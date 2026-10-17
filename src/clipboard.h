// clipboard.h
// Copia un texto UTF-8 al portapapeles del sistema.
//   - Windows: API Win32 (CF_UNICODETEXT)
//   - macOS:   pbcopy
//   - Linux:   Xlib (X11 / XWayland). Requiere enlazar con libX11.
//
// Uso:
//   #include "clipboard.h"
//   copyToClipboard("Hola, mundo");

#pragma once

#include <string>

#if defined(_WIN32)
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif
    #include <windows.h>
#elif defined(__APPLE__)
    #include <cstdio>
#else
    #include <X11/Xlib.h>
    #include <X11/Xatom.h>
    #include <unistd.h>
    #include <sys/wait.h>
#endif

inline bool copyToClipboard(const std::string& s)
{
#if defined(_WIN32)
    // ------------------------------------------------------------------ Windows
    // Convertir UTF-8 a UTF-16, que es lo que espera CF_UNICODETEXT
    int len = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, nullptr, 0);
    if (len <= 0) return false;

    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, static_cast<SIZE_T>(len) * sizeof(wchar_t));
    if (!hMem) return false;

    wchar_t* dst = static_cast<wchar_t*>(GlobalLock(hMem));
    if (!dst) { GlobalFree(hMem); return false; }
    MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, dst, len);
    GlobalUnlock(hMem);

    if (!OpenClipboard(nullptr)) { GlobalFree(hMem); return false; }
    EmptyClipboard();
    if (!SetClipboardData(CF_UNICODETEXT, hMem)) {
        CloseClipboard();
        GlobalFree(hMem);
        return false;
    }
    CloseClipboard();   // a partir de aquí el sistema es dueño de hMem
    return true;

#elif defined(__APPLE__)
    // -------------------------------------------------------------------- macOS
    // LANG fuerza UTF-8 aunque el programa no se haya lanzado desde un terminal
    FILE* pipe = popen("LANG=en_US.UTF-8 pbcopy", "w");
    if (!pipe) return false;
    fwrite(s.data(), 1, s.size(), pipe);
    return pclose(pipe) == 0;

#else
    // ------------------------------------------------------------ Linux (X11)
    // Un proceso en segundo plano se queda como dueño del portapapeles y
    // atiende las peticiones de pegado hasta que otro programa copie algo.
    int fds[2];
    if (pipe(fds) != 0) return false;

    pid_t pid = fork();
    if (pid < 0) { close(fds[0]); close(fds[1]); return false; }

    if (pid == 0) {
        // Doble fork: el nieto queda huérfano y no deja procesos zombi
        close(fds[0]);
        if (fork() != 0) _exit(0);
        setsid();

        char ok = 0;
        Display* dpy = XOpenDisplay(nullptr);
        if (!dpy) { (void)!write(fds[1], &ok, 1); _exit(1); }

        Window win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 1, 1, 0, 0, 0);
        Atom CLIPBOARD = XInternAtom(dpy, "CLIPBOARD",   False);
        Atom UTF8      = XInternAtom(dpy, "UTF8_STRING", False);
        Atom TARGETS   = XInternAtom(dpy, "TARGETS",     False);
        Atom TEXT      = XInternAtom(dpy, "TEXT",        False);

        XSetSelectionOwner(dpy, CLIPBOARD, win, CurrentTime);
        ok = (XGetSelectionOwner(dpy, CLIPBOARD) == win);
        (void)!write(fds[1], &ok, 1);
        close(fds[1]);
        if (!ok) { XCloseDisplay(dpy); _exit(1); }

        for (;;) {
            XEvent ev;
            XNextEvent(dpy, &ev);

            if (ev.type == SelectionClear) break;   // otro programa ha copiado algo
            if (ev.type != SelectionRequest) continue;

            XSelectionRequestEvent* req = &ev.xselectionrequest;
            Atom prop = (req->property != None) ? req->property : req->target;

            XSelectionEvent reply{};
            reply.type      = SelectionNotify;
            reply.display   = req->display;
            reply.requestor = req->requestor;
            reply.selection = req->selection;
            reply.target    = req->target;
            reply.time      = req->time;
            reply.property  = None;   // None = petición rechazada

            if (req->target == TARGETS) {
                Atom targets[] = { TARGETS, UTF8, XA_STRING, TEXT };
                XChangeProperty(dpy, req->requestor, prop, XA_ATOM, 32, PropModeReplace,
                                reinterpret_cast<unsigned char*>(targets), 4);
                reply.property = prop;
            }
            else if (req->target == UTF8 || req->target == XA_STRING || req->target == TEXT) {
                Atom type = (req->target == XA_STRING) ? XA_STRING : UTF8;
                XChangeProperty(dpy, req->requestor, prop, type, 8, PropModeReplace,
                                reinterpret_cast<const unsigned char*>(s.data()),
                                static_cast<int>(s.size()));
                reply.property = prop;
            }

            XSendEvent(dpy, req->requestor, False, 0, reinterpret_cast<XEvent*>(&reply));
            XFlush(dpy);
        }

        XCloseDisplay(dpy);
        _exit(0);
    }

    // Proceso original: espera al hijo intermedio y lee si el nieto lo consiguió
    close(fds[1]);
    waitpid(pid, nullptr, 0);
    char ok = 0;
    bool success = (read(fds[0], &ok, 1) == 1 && ok);
    close(fds[0]);
    return success;
#endif
}
