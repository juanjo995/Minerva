#ifdef _WIN32
    #include <windows.h>
    #include <shellapi.h>
#endif
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <filesystem>
#include <iostream>
#include <limits>
#include <charconv> // Requerido para std::from_chars

// To lower-case
#include <algorithm> // Requerido para std::transform
#include <cctype>    // Requerido para ::tolower

#include "GUI.h"
#include "secure_memory.h"
#include "assets.h"

// We only need to convert from std::wstring to std::string on Windows
#ifdef _WIN32
std::string WideToNarrow(const std::wstring& wide) {
    if (wide.empty()) return {};
    int size = WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), (int)wide.size(),
                                    nullptr, 0, nullptr, nullptr);
    std::string result(size, 0);
    WideCharToMultiByte(CP_UTF8, 0, wide.c_str(), (int)wide.size(),
                         result.data(), size, nullptr, nullptr);
    return result;
}
#elif defined(__linux__) || defined(__APPLE__)
// Dummy function
std::string WideToNarrow(const std::string& wide) {
    return wide;
}
#endif

enum Mode {
    Help,
    Encrypt,
    Decrypt,
    Password,
    SHA,
    Gui
};

std::string getHelpMessage() {

    std::string helpMessage = "";

#ifdef _WIN32
	helpMessage += "\n";
    helpMessage += "Help mode [ help | h | -help | -h | --help | --h ]\n";
    helpMessage += "Shows help message\n";
    helpMessage += "Example -> .\\Minerva.exe help\n\n";

    helpMessage += "Encrypt mode [ encrypt | e | -encrypt | -e | --encrypt | --e ]\n";
    helpMessage += "Encrypts a file\n";
    helpMessage += "Example -> .\\Minerva.exe encrypt C:\\Path\\to\\input\\file C:\\Path\\to\\output\\file\n\n";

    helpMessage += "Decrypt mode [ decrypt | d | -decrypt | -d | --decrypt | --d ]\n";
    helpMessage += "Decrypts a file\n";
    helpMessage += "Example -> .\\Minerva.exe decrypt C:\\Path\\to\\input\\file C:\\Path\\to\\output\\file\n\n";

    helpMessage += "Password mode [ password | pass | p | -password | -pass | -p | --password | --pass | --p ]\n";
    helpMessage += "Generates a secure password of N characters\n";
    helpMessage += "Example -> .\\Minerva.exe password N\n\n";
    
    helpMessage += "SHA256 mode [ sha256 | sha | -sha256 | -sha | --sha256 | --sha ]\n";
    helpMessage += "Gets the SHA256 of a file\n";
    helpMessage += "Example -> .\\Minerva.exe sha256 C:\\Path\\to\\input\\file\n\n";

    helpMessage += "GUI mode\n";
    helpMessage += "To enter into GUI mode just run it with no parameters at all\n";
    helpMessage += "Example -> .\\Minerva.exe\n\n";
#elif defined(__linux__) || defined(__APPLE__)
	helpMessage += "\n";
    helpMessage += "Help mode [ help | h | -help | -h | --help | --h ]\n";
    helpMessage += "Shows help message\n";
    helpMessage += "Example -> ./Minerva help\n\n";

    helpMessage += "Encrypt mode [ encrypt | e | -encrypt | -e | --encrypt | --e ]\n";
    helpMessage += "Encrypts a file\n";
    helpMessage += "Example -> ./Minerva encrypt /Path/to/input/file /Path/to/output/file\n\n";

    helpMessage += "Decrypt mode [ decrypt | d | -decrypt | -d | --decrypt | --d ]\n";
    helpMessage += "Decrypts a file\n";
    helpMessage += "Example -> ./Minerva decrypt /Path/to/input/file /Path/to/output/file\n\n";

    helpMessage += "Password mode [ password | pass | p | -password | -pass | -p | --password | --pass | --p ]\n";
    helpMessage += "Generates a secure password of N characters\n";
    helpMessage += "Example -> ./Minerva password N\n\n";

	helpMessage += "SHA256 mode [ sha256 | sha | -sha256 | -sha | --sha256 | --sha ]\n";
    helpMessage += "Gets the SHA256 of a file\n";
    helpMessage += "Example -> ./Minerva sha256 /Path/to/input/file\n\n";

    helpMessage += "GUI mode\n";
    helpMessage += "To enter into GUI mode just run it with no parameters at all\n";
    helpMessage += "Example -> ./Minerva\n\n";
#endif

    return helpMessage;
}

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return str;
}

Mode mode = Gui;

GUI gui;

void loadConfig(ImGuiIO& io) {
    if(std::filesystem::is_regular_file("config.txt")) {
        std::ifstream fichero("config.txt");
        if (!fichero.is_open()) {
            std::cerr << "No se pudo abrir el fichero: " << "config.txt" << std::endl;
            return;
        }

        std::string line;
        std::vector<std::string> lines;

        line.clear();
        lines.clear();
        
        for(unsigned int i = 0; i < 12; i++) {
			std::getline(fichero, line);
			lines.push_back(line);
		}
		
        fichero.close();

        for(unsigned int i = 0; i < lines.size(); i++) {
            // Opcional: quitar espacios en blanco al inicio/fin
            // (útil si el fichero tiene indentación o retorno de carro \r en Windows)
            while (!lines[i].empty() && (lines[i].back() == '\r' || lines[i].back() == '\n' || lines[i].back() == ' '))
                lines[i].pop_back();
        }

        std::string prefix;

        prefix = "LANGUAGE=";
        if(lines[0].compare(0, prefix.size(), prefix) == 0)
            lines[0] = lines[0].substr(prefix.size());
        currentLanguage = languages[lines[0]];
        
        gui.updateOptionsOfCombos();

        prefix = "PLAINTEXT_MODE=";
        if(lines[1].compare(0, prefix.size(), prefix) == 0)
            lines[1] = lines[1].substr(prefix.size());
        lines[1] = toLower(lines[1]);
        if(lines[1] == "true") {
            gui.currentMode = 1;
        } else {
            gui.currentMode = 0;
        }

        prefix = "PATH=";
        if(lines[2].compare(0, prefix.size(), prefix) == 0)
            lines[2] = lines[2].substr(prefix.size());
        if(!lines[2].empty()) {
            gui.path = lines[2];
            gui.fileExists = std::filesystem::is_regular_file(gui.path);
		}
        
        prefix = "INPUT_PATH=";
        if(lines[3].compare(0, prefix.size(), prefix) == 0)
            lines[3] = lines[3].substr(prefix.size());
        if(!lines[3].empty()) {
            gui.inputFilePath = lines[3];
            gui.inputFileExists = std::filesystem::is_regular_file(gui.inputFilePath);
		}

        prefix = "OUTPUT_PATH=";
        if(lines[4].compare(0, prefix.size(), prefix) == 0)
            lines[4] = lines[4].substr(prefix.size());
        if(!lines[4].empty()) {
            gui.outputFilePath = lines[4];
            gui.outputFileExists = std::filesystem::is_regular_file(gui.outputFilePath);
		}
		
		prefix = "WINDOW_WIDTH=";
        if(lines[5].compare(0, prefix.size(), prefix) == 0)
            lines[5] = lines[5].substr(prefix.size());
        if(!lines[5].empty()) {
            gui.GLFWWindowWidth = std::stof(lines[5]);
		}
		
		prefix = "WINDOW_HEIGHT=";
        if(lines[6].compare(0, prefix.size(), prefix) == 0)
            lines[6] = lines[6].substr(prefix.size());
        if(!lines[6].empty()) {
            gui.GLFWWindowHeight = std::stof(lines[6]);
		}
			 
        prefix = "FONT_SIZE=";
        if(lines[7].compare(0, prefix.size(), prefix) == 0)
            lines[7] = lines[7].substr(prefix.size());
        if(!lines[7].empty()) {
            gui.currentFontSize = std::stoi(lines[7]);
		} else {
			gui.currentFontSize = 16;
		}
            
        prefix = "THEME=";
        if(lines[8].compare(0, prefix.size(), prefix) == 0)
            lines[8] = lines[8].substr(prefix.size());
        if(!lines[8].empty()) {
            gui.currentTheme = std::stoi(lines[8]);
		}
		
        prefix = "COLOR=";
        if(lines[9].compare(0, prefix.size(), prefix) == 0)
            lines[9] = lines[9].substr(prefix.size());
        if(!lines[9].empty()) {
            gui.currentColor = std::stoi(lines[9]);
		}
            
        prefix = "OUTPUT_FORMAT=";
        if(lines[10].compare(0, prefix.size(), prefix) == 0)
            lines[10] = lines[10].substr(prefix.size());
        if(!lines[10].empty()) {
			lines[10] = toLower(lines[10]);
			if(lines[10] == "default") {
				gui.cipherMode = 0;
			} else {
				gui.cipherMode = 1;
			}
		}
		
		prefix = "PBKDF2_ITERATIONS=";
        if(lines[11].compare(0, prefix.size(), prefix) == 0)
            lines[11] = lines[11].substr(prefix.size());
        if(!lines[11].empty()) {
			PBKDF2_ITERATIONS = static_cast<uint32_t>(std::stoi(lines[11]));
		}
		
    } else {
		currentLanguage = Language::English;
		gui.path = "";
		gui.inputFilePath = "";
		gui.outputFilePath = "";
		gui.GLFWWindowWidth = 512.0f;
		gui.GLFWWindowHeight = 512.0f;
		gui.currentFontSize = 16;
		gui.currentTheme = 1;
		gui.currentColor = 0;
		gui.cipherMode = 0;
		PBKDF2_ITERATIONS = 300000;
	}
	
	// Cargar fuente TTF

    static const ImWchar extra_ranges[] = {
        0x0100, 0x02FF, // Latin Ext-A, Ext-B, IPA, modificadores
        0x0370, 0x03FF, // Griego
        0x0530, 0x058F, // Armenio
        0x10A0, 0x10FF, // Georgiano
        0x1C90, 0x1CBF, // Georgiano Mtavruli
        0x1200, 0x139F, // Etiópico + suplemento
        0x2D80, 0x2DDF, // Etiópico extendido
        0x1E00, 0x1EFF, // Latin Extended Additional
        0x2000, 0x206F, // Puntuación general
        0x20A0, 0x20CF, // Símbolos de moneda
        0,
    };

	// Rangos de glifos: Latin básico + extendido + Cirílico
	gui.builder.AddRanges(io.Fonts->GetGlyphRangesDefault());
    gui.builder.AddRanges(io.Fonts->GetGlyphRangesCyrillic());
    gui.builder.AddRanges(extra_ranges);
    gui.builder.AddRanges(io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
    gui.builder.AddRanges(io.Fonts->GetGlyphRangesJapanese());
    gui.builder.AddRanges(io.Fonts->GetGlyphRangesKorean());
    
    for (size_t l = 0; l < static_cast<size_t>(Language::Count); ++l)
        for (size_t i = 0; i < static_cast<size_t>(Str::Count); ++i)
            gui.builder.AddText(T(static_cast<Str>(i), static_cast<Language>(l)).c_str());

    gui.builder.BuildRanges(&gui.ranges);

	// Esta línea se supone que es para renderizar (rasterizar) el texto sin antialiasing... No es estrictamente imprescindible...
	gui.config.FontLoaderFlags = ImGuiFreeTypeBuilderFlags_Monochrome | ImGuiFreeTypeBuilderFlags_MonoHinting;

	gui.minFontSize = 8;
	gui.maxFontSize = 32;
	gui.computeButtonSize();

    gui.config.FontDataOwnedByAtlas = false; // ¡importante!

	io.Fonts->AddFontFromMemoryTTF((void*)font_unifont, (int)font_unifont_size,
                               (float)gui.currentFontSize, &gui.config, gui.ranges.Data);
    io.Fonts->Build();
	
	gui.ApplyTheme();
	gui.ApplyColor();
}

void saveConfig() {

	// std::ios::trunc borra el contenido existente antes de escribir
	// (es el modo por defecto al abrir con ofstream, pero lo indicamos explícitamente)
	std::ofstream fichero("config.txt", std::ios::out | std::ios::trunc);

	if (!fichero.is_open()) {
		std::cerr << "No se pudo abrir el fichero para escritura: " << "config.txt" << std::endl;
		return;
	}

	fichero << "LANGUAGE=" << getLanguageFromEnum(currentLanguage) << std::endl
			<< "PLAINTEXT_MODE=" << (gui.currentMode == 1 ? "true" : "false") << std::endl
			<< "PATH=" << gui.path << std::endl
			<< "INPUT_PATH=" << gui.inputFilePath << std::endl
			<< "OUTPUT_PATH=" << gui.outputFilePath << std::endl
			<< "WINDOW_WIDTH=" << std::to_string(static_cast<int>(gui.GLFWWindowWidth)) << std::endl
			<< "WINDOW_HEIGHT=" << std::to_string(static_cast<int>(gui.GLFWWindowHeight)) << std::endl
			<< "FONT_SIZE=" << std::to_string(gui.currentFontSize) << std::endl
			<< "THEME=" << std::to_string(gui.currentTheme) << std::endl
			<< "COLOR=" << std::to_string(gui.currentColor) << std::endl
			<< "OUTPUT_FORMAT=" << (gui.cipherMode == 0 ? "default" : "OpenSSL") << std::endl
			<< "PBKDF2_ITERATIONS=" << std::to_string(PBKDF2_ITERATIONS);

	// Comprobamos que la escritura fue correcta
	if (fichero.fail()) {
		std::cerr << "Error al escribir en el fichero: " << "config.txt" << std::endl;
		return;
	}

	fichero.close();

}

std::filesystem::path path;

std::wstring wparam1;
std::wstring wparam2;
std::wstring wparam3;
std::wstring wparam4;

std::string param1;
std::string param2;

std::string password;
unsigned int passwordLength;
std::string inputFilePath;
std::string outputFilePath;

std::string hashString;

// Punteros globales para poder cerrarlos después
FILE* fpOut = nullptr;
FILE* fpIn = nullptr;

bool isConsoleAlreadyOpened = false;

void abrirConsola() {
#ifdef _WIN32
    if(isConsoleAlreadyOpened == false) {
        // 1. Crear la consola
        AllocConsole();

        // 2. Redirigir la SALIDA estándar (std::cout / printf)
        freopen_s(&fpOut, "CONOUT$", "w", stdout);

        // 3. Redirigir la ENTRADA estándar (std::cin / scanf)
        freopen_s(&fpIn, "CONIN$", "r", stdin);

        // 4. Limpiar los estados de los flujos de C++
        std::cin.clear();
        std::cout.clear();
        
        // Opcional: Desactivar la sincronización de C/C++ para evitar inconsistencias...
        std::ios::sync_with_stdio(); // true por defecto
        //std::ios::sync_with_stdio(false);

        isConsoleAlreadyOpened = true;
    }
#endif
}

void cerrarConsola() {
#ifdef _WIN32
    // 1. Cerramos los flujos de archivo abiertos
    if (fpOut) {
        fclose(fpOut);
        fpOut = nullptr;
    }
    if (fpIn) {
        fclose(fpIn);
        fpIn = nullptr;
    }

    // 2. Cerramos explícitamente la ventana de la consola si sigue abierta
    HWND hwndConsole = GetConsoleWindow();
    if (hwndConsole != NULL) {
        PostMessage(hwndConsole, WM_CLOSE, 0, 0);
    }

    // 3. Desvinculamos la consola de nuestra aplicación
    FreeConsole();

    isConsoleAlreadyOpened = false;
#endif
}

bool stringToUnsignedInt(const std::string& str, unsigned int& resultado) {
    if (str.empty()) return false;

    // Ejecutamos la conversión sobre el rango de memoria del string
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), resultado);

    // ec == std::errc{} indica que no hubo errores de conversión
    // ptr == str.data() + str.size() garantiza que se procesó TODO el string (sin letras al final)
    if (ec == std::errc{} && ptr == str.data() + str.size()) {
        return true; // Conversión exitosa
    }

    return false; // Error (texto no numérico, número negativo, desbordamiento o basura al final)
}

void pause() {
    std::cout << T(Str::ExitInfoMessage);
    
    // Limpia cualquier caracter sobrante en el búfer (como un '\n' de un std::cin previo)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Espera a que el usuario presione una tecla (Enter)
    std::cin.get();
}

void exit() {
    if(isConsoleAlreadyOpened) {
        pause();
        // Liberar la consola antes de salir
        cerrarConsola();
    }
}

// Callback function to handle window resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height); // Adjust the viewport to the new window size
	gui.GLFWWindowWidth = width;
	gui.GLFWWindowHeight = height;
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    int argc = 0;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

#elif defined(__linux__) || defined(__APPLE__)
int main(int argc, char* argv[]) {
#endif

    // argv[0] es el nombre del ejecutable, igual que en main()

    if (argv != nullptr) {
        switch(argc) {
            case 1: // Gui
                break;
            case 2: // Help
                param1 = WideToNarrow(argv[1]);
                param1 = toLower(param1);
                if(param1 == "help" || param1 == "h" || param1 == "-help" || param1 == "-h" || param1 == "--help" || param1 == "--h") {
                    mode = Help;
                    abrirConsola();
                    std::cout << getHelpMessage();
                    exit();
                    return 0;
                } else {
                    mode = Help;
                    abrirConsola();
                    std::cout << getHelpMessage();
                    exit();
                    return 0;
                }
                break;
            case 3: // Password | SHA256
                param1 = WideToNarrow(argv[1]);
                param1 = toLower(param1);
                param2 = WideToNarrow(argv[2]);
                if(param1 == "password" || param1 == "pass" || param1 == "p" || param1 == "-password" || param1 == "-pass" || param1 == "-p" || param1 == "--password" || param1 == "--pass" || param1 == "--p") {
                    mode = Password;
                    if (stringToUnsignedInt(param2, passwordLength) == false) {
                        abrirConsola();
                        std::cout << T(Str::WrongParamsText) + "\n" + T(Str::WrongNumberValueMessage) + "\n\n";
                        std::cout << T(Str::InputValueText) << ": " << param2 << "\n\n";
                        exit();
                        return 0;
                    }
                } else if (param1 == "sha256" || param1 == "sha" || param1 == "-sha256" || param1 == "-sha" || param1 == "--sha256" || param1 == "--sha") {
                    mode = SHA;
                    path = WideToNarrow(argv[2]);
                    if (std::filesystem::is_regular_file(path) == false) {
                        abrirConsola();
                        std::cout << T(Str::WrongParamsText) + "\n" + T(Str::WrongPathValueMessage) + "\n\n";
                        std::cout << T(Str::InputPathText) << ": " << param2 << "\n\n";
                        exit();
                        return 0;
                    }
                } else {
                    abrirConsola();
                    std::cout << T(Str::WrongParamsText) + '\n';
                    exit();
                    return 0;
                }
                break;
            case 4: // Encrypt/Decrypt
            case 5: // Encrypt/Decrypt
                param1 = WideToNarrow(argv[1]);
                param1 = toLower(param1);

                if(param1 == "encrypt" || param1 == "e" || param1 == "-encrypt" || param1 == "-e" || param1 == "--encrypt" || param1 == "--e") {
                    mode = Encrypt;
                } else if (param1 == "decrypt" || param1 == "d" || param1 == "-decrypt" || param1 == "-d" || param1 == "--decrypt" || param1 == "--d") {
                    mode = Decrypt;
                } else {
                    abrirConsola();
                    std::cout << T(Str::WrongParamsText) + "\n" + T(Str::InvalidOptionMessage) + "\n";
                    std::cout << T(Str::EnteredOptionText) << ": " << param1 << "\n\n";
                    exit();
                    return 0;
                }

                path = WideToNarrow(argv[2]);

                if (!std::filesystem::is_regular_file(path)) {
                    abrirConsola();
                    std::cout << T(Str::WrongParamsText) << "\n" << T(Str::WrongPathValueMessage) << "\n";
                    std::cout << T(Str::InputPathText) << ": " << argv[2] << "\n\n";
                    exit();
                    return 0;
                } else {
                    inputFilePath = WideToNarrow(argv[2]);
                }

                path = WideToNarrow(argv[3]);
                outputFilePath = WideToNarrow(argv[3]);

                password = "";
                if(argc == 5) {
                    password = WideToNarrow(argv[4]);
                }

                break;
            default:
                mode = Help;
                abrirConsola();
                std::cout << getHelpMessage();
                exit();
                return 0;
                break;
        }
#ifdef _WIN32
        LocalFree(argv);
#endif
    }

    std::vector<uint8_t> in;

    switch(mode) {
        case Encrypt:
            if(password == "") {
                abrirConsola();
                std::cout << "\n\n" + T(Str::PasswordLabel) << ": ";
                std::cin >> password;
            }
            in = cargarFichero(inputFilePath);
            // Cifrar
            std::cout << "\n\n" << T(Str::EncryptingText) << "\n\n";
            encrypt(outputFilePath, in, password);
            std::cout << "\n\n" << T(Str::FileEncryptedMessage) << "\n\n";
            wipe(in);
            exit();
            return 0;
            break;
        case Decrypt:
            if(password == "") {
                abrirConsola();
                std::cout << "\n\n" + T(Str::PasswordLabel) << ": ";
                std::cin >> password;
            }
            // Descifrar
            std::cout << "\n\n" << T(Str::DecryptingText) << "\n\n";
            try {
                decrypt(inputFilePath, outputFilePath, password);
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
                exit();
                return 0;
            } catch ( ... ) {
                std::cout << T(Str::UnknownExceptionText) << std::endl;
                exit();
                return 0;
            }
            std::cout << "\n\n" << T(Str::FileDecryptedMessage) << "\n\n";
            exit();
            return 0;
            break;
        case Password:
            abrirConsola();
            std::cout << "\n\n" << T(Str::PasswordLabel) << ": " << getSecurePassword(passwordLength) << "\n\n";
            exit();
            return 0;
            break;
        case SHA:
            in = cargarFichero(param2);
            hashString = toUpper(toHexString(SHA256::getHash(in)));
            abrirConsola();
            std::cout << "\n\n" << T(Str::FileLabel) << ": " << param2 << "\n\nSHA256: " + hashString << "\n\n";
            exit();
            return 0;
            break;
        case Gui:
            break;
        default:
            break;
    }

    // Initialize GLFW
    if (!glfwInit()) {
        std::cout << T(Str::FileLabel) << std::endl;
        return -1;
    }

    // Aceleración hardware por CPU, OpenGL legacy
    // Fuerza un contexto no acelerado (permite el software renderer de Apple)
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_FALSE);

    // Create a windowed mode window and its OpenGL context
    
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);   // crear la ventana oculta para que no "salte"
    
    GLFWwindow* window = glfwCreateWindow(512, 512, "Minerva", nullptr, nullptr);
    if (!window) {
        std::cout << T(Str::GLFWErrorMessage) << std::endl;
        glfwTerminate();
        return -1;
    }
    
    // Centrar la ventana en la pantalla    
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	int mx, my, mw, mh;
	glfwGetMonitorWorkarea(monitor, &mx, &my, &mw, &mh);  // área útil, sin barra de tareas

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set the framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
        std::cout << T(Str::GLADErrorMessage) << std::endl;
        return -1;
    }

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();// (void)io;
    io.IniFilename = nullptr; // <- desactiva la carga/guardado de imgui.ini
    
    // Descomentar esta línea para la Release
    io.ConfigDebugHighlightIdConflicts = false;

    // Initialize ImGui for GLFW and OpenGL
    ImGui_ImplGlfw_InitForOpenGL(window, true);

    ImGui_ImplOpenGL3_Init("#version 120");

    //Init gui
    gui.init(io);
    loadConfig(io);
    gui.checkSpecialThemeCases();
    
    glfwSetWindowSize(window, gui.GLFWWindowWidth, gui.GLFWWindowHeight);
    glfwSetWindowPos(window,
                 mx + (mw - gui.GLFWWindowWidth) / 2,
                 my + (mh - gui.GLFWWindowHeight) / 2);
    glfwShowWindow(window);

    // Main loop
    while (!glfwWindowShouldClose(window)) {

        // Poll for and process events
        glfwPollEvents();

        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

		ImGui::PushFont(nullptr, (float)gui.currentFontSize);
		gui.draw(io);
		ImGui::PopFont();

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap front and back buffers
        glfwSwapBuffers(window);
    }

    saveConfig();

    // Cleanup
    gui.deleteTextures();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
