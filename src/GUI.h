#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include "imgui.h"
#include "imgui_internal.h"
#include "misc/cpp/imgui_stdlib.h"
#include "misc/freetype/imgui_freetype.h"

#include "FileDialog.h"
#include "AES.h"

inline char getSlash() {
    char c;
#ifdef _WIN32
    c = '\\';
#elif __linux__
    c = '/';
#endif
    return c;
}

std::string toUpper(std::string str);

std::string getSecurePassword(unsigned int n);

enum class Theme
{
    Light,
    Dark
};

static const char* ThemeNames[] = {
    "Light", "Dark"
};

enum class ThemeColor
{
    Blue,
    Cyan,
    Green,
    Lime,
    Yellow,
    Brown,
    Orange,
    Red,
    Pink,
    Purple,
    Grey,
    White,
    Black,
    
    Count
};

enum action {
    encrypting,
    decrypting
};

struct textureParameters {
    GLuint GLID;
    int width;
    int height;
    ImTextureID ImGuiID;
};

struct ComboOption {
    const char* text;
    ImTextureID texture;
};

struct GUI {
	
	ImGuiStyle* style;

    float GLFWWindowWidth; // Necesario para calcular el ancho que deben tener nuestros InputText
    float GLFWWindowHeight;

    // Variables para gestionar la fuente TTF
    unsigned int currentFontSize;
    unsigned int minFontSize;
    unsigned int maxFontSize;
    unsigned int currentFontSizeForSettingsMenu;
    ImFontConfig config;
    ImVector<ImWchar> ranges;
    ImFontGlyphRangesBuilder builder;
    
    // Themes
    void setThemesNames();
    std::vector<std::string> themes;
    std::string maxThemeNameString;
    
    // Colors
    std::map<ThemeColor, ImVec4> colorValues;
    void setColorsNames();
    std::vector<std::string> colors;
    std::string maxColorNameString;
    void ApplyTheme();
    void ApplyColor();
    int currentTheme; // 0 Light, 1 Dark
    int currentColor; // índice en ThemeNames / ThemeColor
    
    void checkSpecialThemeCases();
    bool lightAndBlack;
    bool darkAndWhite;
    void applySpecialCaseColorFont();
    void removeSpecialCaseColorFont();

    ImGuiWindowFlags main_window_flags;
    ImGuiWindowFlags popup_window_flags;

	bool showSettingsMenu;
	
	bool showInterfaceSettings;
	bool showCipherAlgorithmSettings;

    void updateOptionsOfCombos();
    std::vector<std::string> options;
    int currentMode; // 0 Normal mode, 1 Plaintext mode
    std::string maxOptionModeString;

	void checkFilePath();
    std::string path;
    bool showFileSHA;
    std::string fileSHA;
    bool fileExists;
    
    void checkInputFilePath();
    std::string inputFilePath;
    bool showInputFileSHA;
    std::string inputFileSHA;
    bool inputFileExists;
    
    void checkOutputFilePath();
    std::string outputFilePath;
    bool showOutputFileSHA;
    std::string outputFileSHA;
    bool outputFileExists;
    
    std::string password;
    bool showPasswordFlag;
    std::string message;
    std::vector<uint8_t> in;
    
    // Cipher option
    int cipherMode; // 0 Default, 1 OpenSSL
    std::vector<std::string> cipherModes;
    std::string maxCipherModeString;
    unsigned int PBKDF2Iterations;
    unsigned int PBKDF2IterationsStep;
    
    ImVec2 centro;
    bool areYouSure;
    std::string areYouSureTextMessage;
    action currentAction;
    bool warningAlarm;
    std::string warningMessage;

	bool generatePasswordPopUpFlag;
	std::string generatedPassword;
	unsigned int minPasswordLenght;
	unsigned int maxPasswordLenght;
	unsigned int currentPasswordLenght;
	
	bool selectLanguagePopUpFlag;
	ComboOption languageOptions[static_cast<unsigned int>(Language::Count)];

    float buttonSize;
    
    float comboWidthForMode;
    float comboWidthForInterfaceSettingsMenu;
    
    float checkboxWidth;
    
    float windowWidth;

    textureParameters gear;

    textureParameters folder;
    
    textureParameters swap;
    textureParameters eye;
    textureParameters eyeS;
    textureParameters dice;
    textureParameters languageTextures[(unsigned int) Language::Count];

    textureParameters en;
    textureParameters zh_hans;
    textureParameters es;
    textureParameters fr;
    textureParameters pt;
    textureParameters ru;
    textureParameters id;
    textureParameters de;
    textureParameters ja;
    textureParameters tr;
    textureParameters vi;
    textureParameters fil;
    textureParameters sw;
    textureParameters ha;
    textureParameters ko;
    textureParameters jv;
    textureParameters it;
    textureParameters ms;
    textureParameters am;
    textureParameters yo;
    textureParameters om;
    textureParameters su;
    textureParameters pl;
    textureParameters ln;
    textureParameters uk;
    textureParameters ff;
    textureParameters zh_hant;
    textureParameters uz;
    textureParameters ig;
    textureParameters zu;
    textureParameters ceb;
    textureParameters nl;
    textureParameters mg;
    textureParameters ro;
    textureParameters az;
    textureParameters so;
    textureParameters wo;
    textureParameters xh;
    textureParameters af;
    textureParameters kk;
    textureParameters kmr;
    textureParameters rw;
    textureParameters sn;
    textureParameters ny;
    textureParameters el;
    textureParameters hu;
    textureParameters sv;
    textureParameters ht;
    textureParameters cs;
    textureParameters sr;
    textureParameters ca;
    textureParameters ti;
    textureParameters bg;
    textureParameters tg;
    textureParameters qu;
    textureParameters sq;
    textureParameters sk;
    textureParameters tk;
    textureParameters hy;
    textureParameters gn;
    textureParameters hr;
    textureParameters da;
    textureParameters fi;
    textureParameters ky;
    textureParameters nb;
    textureParameters be;
    textureParameters tt;
    textureParameters ka;
    textureParameters mn;
    textureParameters bs;
    textureParameters gl;
    textureParameters lt;
    textureParameters sl;
    textureParameters lv;
    textureParameters mk;
    textureParameters ga;
    textureParameters et;
    textureParameters eo;
    textureParameters eu;
    textureParameters cy;
    textureParameters lb;
    textureParameters mt;
    textureParameters is;
    textureParameters fo;

    void init(ImGuiIO& io);
    void centerButton(std::string text);
    void centerButtons(std::string text1, std::string text2);
    void centerText(std::string text);
    void centerCombo(std::string text);
    void centerComboForSettingsMenu(std::string text);
    void centerCheckboxForSettingsMenu(std::string text);
    bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height);
    bool LoadTextureFromMemory(const void* data, size_t size, GLuint* out_tex, int* out_w, int* out_h);
    void computeButtonSize();
    float getCheckboxWidth(const std::string& label);
    float getInputTextWidth(const std::string& textLabel, float buttonWidth, int buttonsCount);
    void onClickOverEncryptButton();
    void onClickOverDecryptButton();
    void drawPasswordSection();
    void encryptAndDecryptButtons(ImGuiIO& io);
    void draw(ImGuiIO& io);
    void deleteTextures();
};
