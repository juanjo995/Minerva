# Minerva

With Minerva you can easily encrypt and decrypt your files.

<img width="512" height="256" alt="NormalMode" src="https://github.com/user-attachments/assets/95686a10-879d-459c-90ac-85f8bd5ce76c" />

Minerva uses the algorithm AES-256 in CTR mode and PBKDF2 to derive keys.

## Plaintext mode

Minerva includes a plaintext mode for files containing plaintext, allowing you to modify your most sensitive information without it ever being stored on your hard drive in an unencrypted state.

<img width="512" height="512" alt="PlainTextMode" src="https://github.com/user-attachments/assets/e94db888-3135-4e09-9168-e3c0c3aa764f" />

## OpenSSL format

On the settings menu you can choose to save your encrypted files as printable characters or in binary format (recommended for large files) compatible with OpenSSL, so files encrypted with OpenSSL can be decrypted with Minerva and vice versa.

OpenSSL commands to encrypt and decrypt:

Encrypt: `openssl enc -e -aes-256-ctr -pbkdf2 -salt -in inputFile -out outputFile`

Decrypt: `openssl enc -d -aes-256-ctr -pbkdf2 -in inputFile -out outputFile`

## Language support

Minerva includes 84 languages. English and Spanish translations were made by me, the rest of translations were made using AI so some translations may be wrong or inaccurate.

<img width="302" height="224" alt="languages" src="https://github.com/user-attachments/assets/490bb24a-c801-42a7-b939-3d4fc95651b0" />

## Run it

Just go to [Releases](https://github.com/juanjo995/Minerva/releases) and download the executable for your OS version, Windows, Linux or macOS.

## How to compile this project

### Windows

This project needs CMake to be compiled, if you don't have CMake you can download it from [here](https://cmake.org/download/).

`mkdir build`

`cd build`

CMake requires the Python's **jinja2** library to configure Glad.

If you don't have Python, you can install it by running the command `python` in a terminal, this will open the Microsoft Store, where you can install the Python install manager. Once it is installed, you must run `python` in a terminal again to complete the installation.

Before running the `cmake` command, you must install **jinja2** in a Python virtual environment.

`python -m venv venv`

`.\venv\Scripts\Activate.ps1`

`pip install jinja2`

Now, if you are using **MinGW** you can just run:

`cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..`

We no longer need the Python virtual environment.

`deactivate`

Now you have to modify the file `build\_deps\tiny_aes-src\aes.h`.

You have to comment the line `#define AES128 1` and uncomment the line `#define AES256 1`.

Finally, to compile it, just run the next command:

`cmake --build .`

If you want to use **MSVC** the steps are very similar, you must open a **Developer Command Prompt for VS**.

`mkdir build`

`cd build`

`python -m venv venv`

`.\venv\Scripts\activate`

`pip install jinja2`

`cmake -G "Visual Studio 17 2022" -A x64 ..`

(If you prefer to use **Ninja** run `cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ..`)

`deactivate`

Modify the file `build\_deps\tiny_aes-src\aes.h` as explained above.

`cmake --build . --config Release`

(If you prefer to use **Ninja** run `cmake --build .`)

### Linux

First, you need to install these dependencies.

`sudo apt update`

`sudo apt install cmake pkg-config build-essential libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgtk-3-dev`

`mkdir build`

`cd build`

`python3 -m venv venv`

`source venv/bin/activate`

`pip install jinja2`

`cmake ..`

`deactivate`

Now you have to modify the file `build\_deps\tiny_aes-src\aes.h`.

You have to comment the line `#define AES128 1` and uncomment the line `#define AES256 1`.

`make`

### macOS

First, ensure that you have the compiler and the development tools.

`xcode-select --install`

If you don't have CMake, you can download it from [here](https://cmake.org/download/).

After installing CMake you have to run the next command to be able to use it from the terminal.

`sudo "/Applications/CMake.app/Contents/bin/cmake-gui" --install`

`mkdir build`

`cd build`

`python3 -m venv venv`

`source venv/bin/activate`

`pip install jinja2`

`cmake ..`

`deactivate`

Now you have to modify the file `build\_deps\tiny_aes-src\aes.h`.

You have to comment the line `#define AES128 1` and uncomment the line `#define AES256 1`.

`make`

## Credits

### Libraries

This project relies on a few libraries to work:

| Library | Author | License |
|---------|--------|---------|
| [stb](https://github.com/nothings/stb) | Sean Barrett | Public Domain / MIT |
| [GLFW](https://github.com/glfw/glfw) | Marcus Geelnard, Camilla Löwy | zlib/libpng |
| [glad](https://github.com/Dav1dde/glad) | David Herberth | Generated code: Public Domain / CC0 (Khronos specs: Apache 2.0) |
| [Dear ImGui](https://github.com/ocornut/imgui) | Omar Cornut | MIT |
| [Native File Dialog Extended](https://github.com/btzy/nativefiledialog-extended) | Bernard Teo (based on Michael Labbe's NFD) | zlib |
| [Tiny AES in C](https://github.com/kokke/tiny-AES-c) | kokke | Unlicense |

### Assets

| Asset | Author | License |
|-------|--------|---------|
| [Flag icons](https://github.com/HatScripts/circle-flags) | HatScripts | MIT |
| [Settings icon](https://www.svgrepo.com/svg/435417/settings) | Nuiverse Design | BSD |
| [Folder icon](https://www.svgrepo.com/svg/365406/folder-notch-open-thin) | Phosphor Icons | MIT |
| [Swap icon](https://www.svgrepo.com/svg/491149/swap-vertical) | Will Kelly | CC0 |
| [Eye icon](https://www.svgrepo.com/svg/390437/eye-key-look-password-security-see) | Gokce Kurt | CC0 |
| [Crossed-out eye icon](https://www.svgrepo.com/svg/390427/eye-password-see-view) | Gokce Kurt | CC0 |
| [Dice icon](https://www.svgrepo.com/svg/435616/dice) | JetBrains | Apache 2.0 |
| [UnifontEX](https://github.com/stgiga/UnifontEX) | stgiga (based on GNU Unifont by Roman Czyborra, Paul Hardy et al.) | GPL 2.0 with font embedding exception / OFL 1.1 |

## License

This project is licensed under the GNU General Public License v3.0 or later.