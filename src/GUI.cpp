#include "GUI.h"

#include "secure_memory.h"
#include "clipboard.h"
#include "assets.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void GUI::centerButton(std::string text) {
	float buttonWidth = ImGui::CalcTextSize(text.c_str()).x + style->FramePadding.x * 2.0f;
	float cursorX = (windowWidth - buttonWidth) * 0.5f;
	if (cursorX > 0.0f)
		ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + cursorX));
}

void GUI::centerButtons(std::string text1, std::string text2) {
	float buttonsWidth = ImGui::CalcTextSize(text1.c_str()).x + ImGui::CalcTextSize(text2.c_str()).x + style->FramePadding.x * 4.0f + style->ItemSpacing.x;
	float cursorX = (windowWidth - buttonsWidth) * 0.5f;
	if (cursorX > 0.0f)
		ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + cursorX));
}

void GUI::centerText(std::string text) {
	float cursorX = (windowWidth - ImGui::CalcTextSize(text.c_str()).x) * 0.5f;
	if (cursorX > 0.0f)
		ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + cursorX));
}

void GUI::centerCombo(std::string text) {
	float comboWidth = ImGui::CalcTextSize(text.c_str()).x + style->FramePadding.x * 1.0f + style->ItemInnerSpacing.x + currentFontSize + 6.0f;
	float cursorX = (windowWidth - comboWidth) * 0.5f;
	if (cursorX > 0.0f)
		ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + cursorX));
}

void GUI::centerComboForSettingsMenu(std::string text) {
	comboWidthForInterfaceSettingsMenu = ImGui::CalcTextSize(text.c_str()).x + style->FramePadding.x * 1.0f + style->ItemInnerSpacing.x + currentFontSizeForSettingsMenu + 6.0f;
	float cursorX = (windowWidth - comboWidthForInterfaceSettingsMenu) * 0.5f;
	if (cursorX > 0.0f)
		ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + cursorX));
}

void GUI::centerCheckboxForSettingsMenu(std::string text) {
	checkboxWidth = ImGui::GetFrameHeight() + ImGui::CalcTextSize(text.c_str()).x + style->ItemInnerSpacing.x;
	float cursorX = (windowWidth - checkboxWidth) * 0.5f;
	if (cursorX > 0.0f)
		ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + cursorX));
}

void GUI::checkFilePath() {
	fileExists = std::filesystem::is_regular_file(path);
	if(!fileExists) {
		showFileSHA = false;
	}
}

void GUI::checkInputFilePath() {
	inputFileExists = std::filesystem::is_regular_file(inputFilePath);
	if(!inputFileExists) {
		showInputFileSHA = false;
	}
}

void GUI::checkOutputFilePath() {
	outputFileExists = std::filesystem::is_regular_file(outputFilePath);
	if(!outputFileExists) {
		showOutputFileSHA = false;
	}
}

std::string toUpper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return str;
}

std::string getSecurePassword(unsigned int n) {
	if (n == 0) return "";

	// Conjunto de caracteres permitidos para la contraseña: ASCII imprimible completo
	// (0x21-0x7E, 94 caracteres), excluyendo 5 caracteres conflictivos en contextos
	// habituales (shell, JSON/YAML, rutas de Windows):
	//   " ' -> delimitadores de cadena en JSON/YAML/CSV y quoting de shell
	//   `   -> command substitution en shell (ejecuta lo que hay entre backticks)
	//   \   -> caracter de escape universal, ademas de separador de rutas en Windows
	//   $   -> expansion de variables en shell/bash
	// Resultado: 89 caracteres.
	const std::string alfabeto =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"0123456789"
		"!#%&()*+,-./:;<=>?@[]^_{|}~";

	const size_t tamanoAlfabeto = alfabeto.size();
	
	// Calculamos el límite máximo uniforme para evitar el sesgo del módulo.
	// IMPORTANTE: usamos 'unsigned int' (no 'uint8_t') porque el resultado puede
	// valer exactamente 256 cuando tamanoAlfabeto divide a 256 de forma exacta
	// (por ejemplo, con un alfabeto de 64, 32, 16... caracteres). Con uint8_t,
	// ese 256 desbordaría a 0, dejando la condición de aceptación siempre falsa
	// y el bucle de generación colgado para siempre.
	const unsigned int limiteUniforme = 256u - (256u % tamanoAlfabeto);

	std::string password;
	password.clear();
	password.reserve(n); // Reservamos memoria para evitar reasignaciones
	
	char nextChar;

	while (password.size() < n) {
		// Pedimos la cantidad de bytes que nos faltan para completar la contraseña
		size_t bytesNecesarios = n - password.size();
		std::vector<uint8_t> randomBytes = SecureRandom::generate(bytesNecesarios);

		for (uint8_t byte : randomBytes) {
			// Descartamos los bytes que están fuera del rango uniforme
			if (static_cast<unsigned int>(byte) < limiteUniforme) {
				
				nextChar = static_cast<char>(alfabeto[byte % tamanoAlfabeto]);
				
				if (alfabeto.find(nextChar) != std::string::npos) {
					password += nextChar;
				}

				// Si ya completamos la longitud deseada, salimos del bucle
				if (password.size() == n) {
					break;
				}
			}
		}
	}
	return password;
}

void GUI::checkSpecialThemeCases() {
	lightAndBlack = darkAndWhite = false;
	if (currentTheme == static_cast<int>(Theme::Light) && currentColor == static_cast<int>(ThemeColor::Black)) {
		lightAndBlack = true;
	}
	if (currentTheme == static_cast<int>(Theme::Dark) && currentColor == static_cast<int>(ThemeColor::White)) {
		darkAndWhite = true;
	}
}

void GUI::applySpecialCaseColorFont() {
	if(lightAndBlack) {
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
	} else if (darkAndWhite) {
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
	} else {
	}
}

void GUI::removeSpecialCaseColorFont() {
	if(lightAndBlack || darkAndWhite) {
		ImGui::PopStyleColor();
	}
}

void GUI::setThemesNames() {
	themes.clear();
	themes.push_back(T(Str::LightThemeName));
	themes.push_back(T(Str::DarkThemeName));
}

void GUI::setColorsNames() {
	colors.clear();
	colors.push_back(T(Str::BlueName));
    colors.push_back(T(Str::CyanName));
    colors.push_back(T(Str::GreenName));
    colors.push_back(T(Str::LimeName));
    colors.push_back(T(Str::YellowName));
    colors.push_back(T(Str::BrownName));
    colors.push_back(T(Str::OrangeName));
    colors.push_back(T(Str::RedName));
    colors.push_back(T(Str::PinkName));
    colors.push_back(T(Str::PurpleName));
    colors.push_back(T(Str::GreyName));
    colors.push_back(T(Str::WhiteName));
    colors.push_back(T(Str::BlackName));
}

void GUI::ApplyTheme() {
	if(currentTheme == static_cast<int>(Theme::Light)) {
		ImGui::StyleColorsLight();
	} else if (currentTheme == static_cast<int>(Theme::Dark)) {
		ImGui::StyleColorsDark();
	} else {
		ImGui::StyleColorsDark();
	}
}

void GUI::ApplyColor() {
	
	ThemeColor color = static_cast<ThemeColor>(currentColor);

    // Colores de acento por tema (Hue en HSV, saturación y valor fijos)
    ImVec4 accent;

    switch (color)
	{
		case ThemeColor::Blue:   accent = ImVec4(0.26f, 0.59f, 0.98f, 1.0f); break;
		case ThemeColor::Cyan:   accent = ImVec4(0.20f, 0.75f, 0.90f, 1.0f); break;
		case ThemeColor::Red:    accent = ImVec4(0.85f, 0.20f, 0.20f, 1.0f); break;
		case ThemeColor::Yellow: accent = ImVec4(0.90f, 0.80f, 0.15f, 1.0f); break;
		case ThemeColor::Green:  accent = ImVec4(0.15f, 0.60f, 0.35f, 1.0f); break;
		case ThemeColor::Lime:   accent = ImVec4(0.65f, 0.80f, 0.25f, 1.0f); break;
		case ThemeColor::Orange: accent = ImVec4(0.95f, 0.55f, 0.15f, 1.0f); break;
		case ThemeColor::Purple: accent = ImVec4(0.60f, 0.30f, 0.85f, 1.0f); break;
		case ThemeColor::Pink:   accent = ImVec4(0.95f, 0.45f, 0.65f, 1.0f); break;
		case ThemeColor::Brown:  accent = ImVec4(0.55f, 0.35f, 0.20f, 1.0f); break;
		case ThemeColor::White:  accent = ImVec4(0.90f, 0.90f, 0.90f, 1.0f); break;
		case ThemeColor::Black:  accent = ImVec4(0.15f, 0.15f, 0.15f, 1.0f); break;
		case ThemeColor::Grey:   accent = ImVec4(0.50f, 0.50f, 0.50f, 1.0f); break;
	}

    ImVec4* colors = style->Colors;

    // Variantes hover/active a partir del acento (más claro/oscuro)
    ImVec4 accentHover = ImVec4(accent.x + 0.08f, accent.y + 0.08f, accent.z + 0.08f, 1.0f);
    ImVec4 accentActive = ImVec4(accent.x - 0.08f, accent.y - 0.08f, accent.z - 0.08f, 1.0f);

    colors[ImGuiCol_Button]              = ImVec4(accent.x, accent.y, accent.z, 0.60f);
    colors[ImGuiCol_ButtonHovered]       = accentHover;
    colors[ImGuiCol_ButtonActive]        = accentActive;

    colors[ImGuiCol_Header]              = ImVec4(accent.x, accent.y, accent.z, 0.55f);
    colors[ImGuiCol_HeaderHovered]       = accentHover;
    colors[ImGuiCol_HeaderActive]        = accentActive;

    colors[ImGuiCol_FrameBg]             = ImVec4(accent.x, accent.y, accent.z, 0.25f);
    colors[ImGuiCol_FrameBgHovered]      = ImVec4(accent.x, accent.y, accent.z, 0.40f);
    colors[ImGuiCol_FrameBgActive]       = ImVec4(accent.x, accent.y, accent.z, 0.55f);

    colors[ImGuiCol_SliderGrab]          = accent;
    colors[ImGuiCol_SliderGrabActive]    = accentActive;

    colors[ImGuiCol_CheckMark]           = accent;
    colors[ImGuiCol_CheckboxSelectedBg]  = ImVec4(accent.x, accent.y, accent.z, 0.25f);

    colors[ImGuiCol_Tab]                 = ImVec4(accent.x, accent.y, accent.z, 0.45f);
    colors[ImGuiCol_TabHovered]          = accentHover;
    colors[ImGuiCol_TabActive]           = ImVec4(accent.x, accent.y, accent.z, 0.70f);

    colors[ImGuiCol_TitleBgActive]       = ImVec4(accent.x, accent.y, accent.z, 1.0f);

    colors[ImGuiCol_ResizeGrip]          = ImVec4(accent.x, accent.y, accent.z, 0.30f);
    colors[ImGuiCol_ResizeGripHovered]   = accentHover;
    colors[ImGuiCol_ResizeGripActive]    = accentActive;

    colors[ImGuiCol_SeparatorHovered]    = accentHover;
    colors[ImGuiCol_SeparatorActive]     = accentActive;
}

bool GUI::LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height) {
    int width, height, channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 4); // forzamos 4 canales (RGBA)
    if (data == nullptr) {
        return false;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);

    *out_texture = texture;
    *out_width = width;
    *out_height = height;

    return true;
}

bool GUI::LoadTextureFromMemory(const void* data, size_t size,
                           GLuint* out_tex, int* out_w, int* out_h)
{
    int w = 0, h = 0;
    unsigned char* pixels = stbi_load_from_memory(
        (const unsigned char*)data, (int)size, &w, &h, nullptr, 4);
    if (!pixels) return false;

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    stbi_image_free(pixels);

    *out_tex = tex; *out_w = w; *out_h = h;
    return true;
}

#define LOAD_ICON(var, asset) \
    LoadTextureFromMemory(asset, asset##_size, &var.GLID, &var.width, &var.height); \
    var.ImGuiID = (ImTextureID)(intptr_t)var.GLID;

void GUI::updateOptionsOfCombos() {

	options.clear();
    options.push_back(T(Str::NormalModeLabel)); // 0
    options.push_back(T(Str::PlaintextModeLabel)); // 1
    maxOptionModeString.clear();
    int auxMax = 0;
    for(unsigned int i = 0; i < options.size(); i++) {
		if(options[i].size() > auxMax) {
			auxMax = options[i].size();
			maxOptionModeString = options[i];
		}
	}

	cipherModes.clear();
	cipherModes.push_back(T(Str::DefaultLabel));
    cipherModes.push_back(T(Str::OpenSSLLabel));
    auxMax = 0;
    for(unsigned int i = 0; i < cipherModes.size(); i++) {
		if(cipherModes[i].size() > auxMax) {
			auxMax = cipherModes[i].size();
			maxCipherModeString = cipherModes[i];
		}
	}
	
	setThemesNames();
	maxThemeNameString.clear();
	auxMax = 0;
	for(unsigned int i = 0; i < themes.size(); i++) {
		if(themes[i].size() > auxMax) {
			auxMax = themes[i].size();
			maxThemeNameString = themes[i];
		}
	}
	
	setColorsNames();
	maxColorNameString.clear();
	auxMax = 0;
	for(unsigned int i = 0; i < colors.size(); i++) {
		if(colors[i].size() > auxMax) {
			auxMax = colors[i].size();
			maxColorNameString = colors[i];
		}
	}
}

void GUI::init(ImGuiIO& io) {
	
	style = &ImGui::GetStyle();
	
    // Inicializar variables
    showSettingsMenu = false;
    showInterfaceSettings = false;
    showCipherAlgorithmSettings = false;
    password.clear();
    
    updateOptionsOfCombos();
    
    showPasswordFlag = false;
    minPasswordLenght = 8;
    maxPasswordLenght = 64;
    currentPasswordLenght = 20;
    
    PBKDF2IterationsStep = 2500;
    
    cipherMode = 0;
    cipherModes.clear();
    cipherModes.push_back(T(Str::DefaultLabel));
    cipherModes.push_back(T(Str::OpenSSLLabel));
	
    areYouSure = false;
    warningAlarm = false;
    warningMessage.clear();
    
    generatePasswordPopUpFlag = false;
	generatedPassword = "";
	
	selectLanguagePopUpFlag = false;
	
	showFileSHA = false;
	showInputFileSHA = false;
	showOutputFileSHA = false;
	
	fileSHA.clear();
	inputFileSHA.clear();
	outputFileSHA.clear();

    // Seleccionamos los flags que necesitemos para nuestras ventanas
    // Pasar flags para desactivar la barra de título, resize, scroll, etc.
    main_window_flags = ImGuiWindowFlags_NoTitleBar
                                | ImGuiWindowFlags_NoResize
                                | ImGuiWindowFlags_NoMove
                                | ImGuiWindowFlags_NoCollapse
                                | ImGuiWindowFlags_NoBringToFrontOnFocus
                                | ImGuiWindowFlags_NoNavFocus;
    
    popup_window_flags = ImGuiWindowFlags_AlwaysAutoResize
                                | ImGuiWindowFlags_NoMove
                                | ImGuiWindowFlags_NoCollapse
                                | ImGuiWindowFlags_NoNavFocus;
    
    // Cargar texturas de iconos
	LOAD_ICON(gear,   img_gear)
	LOAD_ICON(folder, img_folder)
	LOAD_ICON(swap,   img_swap)
	LOAD_ICON(eye,    img_eye)
	LOAD_ICON(eyeS,   img_eyeS)
	LOAD_ICON(dice,   img_dice)

	// Cargar texturas de idiomas
	LOAD_ICON(en,       img_en)
	LOAD_ICON(zh_hans,  img_zh_hans)
	LOAD_ICON(es,       img_es)
	LOAD_ICON(fr,       img_fr)
	LOAD_ICON(pt,       img_pt)
	LOAD_ICON(ru,       img_ru)
	LOAD_ICON(id,       img_id)
	LOAD_ICON(de,       img_de)
	LOAD_ICON(ja,       img_ja)
	LOAD_ICON(tr,       img_tr)
	LOAD_ICON(vi,       img_vi)
	LOAD_ICON(fil,      img_fil)
	LOAD_ICON(sw,       img_sw)
	LOAD_ICON(ha,       img_ha)
	LOAD_ICON(ko,       img_ko)
	LOAD_ICON(jv,       img_jv)
	LOAD_ICON(it,       img_it)
	LOAD_ICON(ms,       img_ms)
	LOAD_ICON(am,       img_am)
	LOAD_ICON(yo,       img_yo)
	LOAD_ICON(om,       img_om)
	LOAD_ICON(su,       img_su)
	LOAD_ICON(pl,       img_pl)
	LOAD_ICON(ln,       img_ln)
	LOAD_ICON(uk,       img_uk)
	LOAD_ICON(ff,       img_ff)
	LOAD_ICON(zh_hant,  img_zh_hant)
	LOAD_ICON(uz,       img_uz)
	LOAD_ICON(ig,       img_ig)
	LOAD_ICON(zu,       img_zu)
	LOAD_ICON(ceb,      img_ceb)
	LOAD_ICON(nl,       img_nl)
	LOAD_ICON(mg,       img_mg)
	LOAD_ICON(ro,       img_ro)
	LOAD_ICON(az,       img_az)
	LOAD_ICON(so,       img_so)
	LOAD_ICON(wo,       img_wo)
	LOAD_ICON(xh,       img_xh)
	LOAD_ICON(af,       img_af)
	LOAD_ICON(kk,       img_kk)
	LOAD_ICON(kmr,      img_kmr)
	LOAD_ICON(rw,       img_rw)
	LOAD_ICON(sn,       img_sn)
	LOAD_ICON(ny,       img_ny)
	LOAD_ICON(el,       img_el)
	LOAD_ICON(hu,       img_hu)
	LOAD_ICON(sv,       img_sv)
	LOAD_ICON(ht,       img_ht)
	LOAD_ICON(cs,       img_cs)
	LOAD_ICON(sr,       img_sr)
	LOAD_ICON(ca,       img_ca)
	LOAD_ICON(ti,       img_ti)
	LOAD_ICON(bg,       img_bg)
	LOAD_ICON(tg,       img_tg)
	LOAD_ICON(qu,       img_qu)
	LOAD_ICON(sq,       img_sq)
	LOAD_ICON(sk,       img_sk)
	LOAD_ICON(tk,       img_tk)
	LOAD_ICON(hy,       img_hy)
	LOAD_ICON(gn,       img_gn)
	LOAD_ICON(hr,       img_hr)
	LOAD_ICON(da,       img_da)
	LOAD_ICON(fi,       img_fi)
	LOAD_ICON(ky,       img_ky)
	LOAD_ICON(nb,       img_nb)
	LOAD_ICON(be,       img_be)
	LOAD_ICON(tt,       img_tt)
	LOAD_ICON(ka,       img_ka)
	LOAD_ICON(mn,       img_mn)
	LOAD_ICON(bs,       img_bs)
	LOAD_ICON(gl,       img_gl)
	LOAD_ICON(lt,       img_lt)
	LOAD_ICON(sl,       img_sl)
	LOAD_ICON(lv,       img_lv)
	LOAD_ICON(mk,       img_mk)
	LOAD_ICON(ga,       img_ga)
	LOAD_ICON(et,       img_et)
	LOAD_ICON(eo,       img_eo)
	LOAD_ICON(eu,       img_eu)
	LOAD_ICON(cy,       img_cy)
	LOAD_ICON(lb,       img_lb)
	LOAD_ICON(mt,       img_mt)
	LOAD_ICON(is,       img_is)
	LOAD_ICON(fo,       img_fo)

	// Inicializar mapa de colores
	colorValues.clear();
	colorValues[ThemeColor::Blue]   = ImVec4(0.26f, 0.59f, 0.98f, 1.0f);
	colorValues[ThemeColor::Cyan]   = ImVec4(0.20f, 0.75f, 0.90f, 1.0f);
	colorValues[ThemeColor::Red]    = ImVec4(0.85f, 0.20f, 0.20f, 1.0f);
	colorValues[ThemeColor::Yellow] = ImVec4(0.90f, 0.80f, 0.15f, 1.0f);
	colorValues[ThemeColor::Green]  = ImVec4(0.15f, 0.60f, 0.35f, 1.0f);
	colorValues[ThemeColor::Lime]   = ImVec4(0.65f, 0.80f, 0.25f, 1.0f);
	colorValues[ThemeColor::Orange] = ImVec4(0.95f, 0.55f, 0.15f, 1.0f);
	colorValues[ThemeColor::Purple] = ImVec4(0.60f, 0.30f, 0.85f, 1.0f);
	colorValues[ThemeColor::Pink]   = ImVec4(0.95f, 0.45f, 0.65f, 1.0f);
	colorValues[ThemeColor::Brown]  = ImVec4(0.55f, 0.35f, 0.20f, 1.0f);
	colorValues[ThemeColor::White]  = ImVec4(0.90f, 0.90f, 0.90f, 1.0f);
	colorValues[ThemeColor::Black]  = ImVec4(0.15f, 0.15f, 0.15f, 1.0f);
	colorValues[ThemeColor::Grey]   = ImVec4(0.50f, 0.50f, 0.50f, 1.0f);

    languageTextures[(unsigned int) Language::English]            = en;
    languageTextures[(unsigned int) Language::Spanish]            = es;
    languageTextures[(unsigned int) Language::ChineseSimplified]  = zh_hans;
    languageTextures[(unsigned int) Language::French]             = fr;
    languageTextures[(unsigned int) Language::Portuguese]         = pt;
    languageTextures[(unsigned int) Language::Russian]            = ru;
    languageTextures[(unsigned int) Language::Indonesian]         = id;
    languageTextures[(unsigned int) Language::German]             = de;
    languageTextures[(unsigned int) Language::Japanese]           = ja;
    languageTextures[(unsigned int) Language::Turkish]            = tr;
    languageTextures[(unsigned int) Language::Vietnamese]         = vi;
    languageTextures[(unsigned int) Language::Filipino]           = fil;
    languageTextures[(unsigned int) Language::Swahili]            = sw;
    languageTextures[(unsigned int) Language::Hausa]              = ha;
    languageTextures[(unsigned int) Language::Korean]             = ko;
    languageTextures[(unsigned int) Language::Javanese]           = jv;
    languageTextures[(unsigned int) Language::Italian]            = it;
    languageTextures[(unsigned int) Language::Malay]              = ms;
    languageTextures[(unsigned int) Language::Amharic]            = am;
    languageTextures[(unsigned int) Language::Yoruba]             = yo;
    languageTextures[(unsigned int) Language::Oromo]              = om;
    languageTextures[(unsigned int) Language::Sundanese]          = su;
    languageTextures[(unsigned int) Language::Polish]             = pl;
    languageTextures[(unsigned int) Language::Lingala]            = ln;
    languageTextures[(unsigned int) Language::Ukrainian]          = uk;
    languageTextures[(unsigned int) Language::Fula]               = ff;
    languageTextures[(unsigned int) Language::ChineseTraditional] = zh_hant;
    languageTextures[(unsigned int) Language::Uzbek]              = uz;
    languageTextures[(unsigned int) Language::Igbo]               = ig;
    languageTextures[(unsigned int) Language::Zulu]               = zu;
    languageTextures[(unsigned int) Language::Cebuano]            = ceb;
    languageTextures[(unsigned int) Language::Dutch]              = nl;
    languageTextures[(unsigned int) Language::Malagasy]           = mg;
    languageTextures[(unsigned int) Language::Romanian]           = ro;
    languageTextures[(unsigned int) Language::Azerbaijani]        = az;
    languageTextures[(unsigned int) Language::Somali]             = so;
    languageTextures[(unsigned int) Language::Wolof]              = wo;
    languageTextures[(unsigned int) Language::Xhosa]              = xh;
    languageTextures[(unsigned int) Language::Afrikaans]          = af;
    languageTextures[(unsigned int) Language::Kazakh]             = kk;
    languageTextures[(unsigned int) Language::Kurdish]            = kmr;
    languageTextures[(unsigned int) Language::Kinyarwanda]        = rw;
    languageTextures[(unsigned int) Language::Shona]              = sn;
    languageTextures[(unsigned int) Language::Chichewa]           = ny;
    languageTextures[(unsigned int) Language::Greek]              = el;
    languageTextures[(unsigned int) Language::Hungarian]          = hu;
    languageTextures[(unsigned int) Language::Swedish]            = sv;
    languageTextures[(unsigned int) Language::HaitianCreole]      = ht;
    languageTextures[(unsigned int) Language::Czech]              = cs;
    languageTextures[(unsigned int) Language::Serbian]            = sr;
    languageTextures[(unsigned int) Language::Catalan]            = ca;
    languageTextures[(unsigned int) Language::Tigrinya]           = ti;
    languageTextures[(unsigned int) Language::Bulgarian]          = bg;
    languageTextures[(unsigned int) Language::Tajik]              = tg;
    languageTextures[(unsigned int) Language::Quechua]            = qu;
    languageTextures[(unsigned int) Language::Albanian]           = sq;
    languageTextures[(unsigned int) Language::Slovak]             = sk;
    languageTextures[(unsigned int) Language::Turkmen]            = tk;
    languageTextures[(unsigned int) Language::Armenian]           = hy;
    languageTextures[(unsigned int) Language::Guarani]            = gn;
    languageTextures[(unsigned int) Language::Croatian]           = hr;
    languageTextures[(unsigned int) Language::Danish]             = da;
    languageTextures[(unsigned int) Language::Finnish]            = fi;
    languageTextures[(unsigned int) Language::Kyrgyz]             = ky;
    languageTextures[(unsigned int) Language::Norwegian]          = nb;
    languageTextures[(unsigned int) Language::Belarusian]         = be;
    languageTextures[(unsigned int) Language::Tatar]              = tt;
    languageTextures[(unsigned int) Language::Georgian]           = ka;
    languageTextures[(unsigned int) Language::Mongolian]          = mn;
    languageTextures[(unsigned int) Language::Bosnian]            = bs;
    languageTextures[(unsigned int) Language::Galician]           = gl;
    languageTextures[(unsigned int) Language::Lithuanian]         = lt;
    languageTextures[(unsigned int) Language::Slovenian]          = sl;
    languageTextures[(unsigned int) Language::Latvian]            = lv;
    languageTextures[(unsigned int) Language::Macedonian]         = mk;
    languageTextures[(unsigned int) Language::Irish]              = ga;
    languageTextures[(unsigned int) Language::Estonian]           = et;
    languageTextures[(unsigned int) Language::Esperanto]          = eo;
    languageTextures[(unsigned int) Language::Basque]             = eu;
    languageTextures[(unsigned int) Language::Welsh]              = cy;
    languageTextures[(unsigned int) Language::Luxembourgish]      = lb;
    languageTextures[(unsigned int) Language::Maltese]            = mt;
    languageTextures[(unsigned int) Language::Icelandic]          = is;
    languageTextures[(unsigned int) Language::Faroese]            = fo;
    
	languageOptions[0] = { "English (English)",               en.ImGuiID };
    languageOptions[1] = { "Español (Spanish)",               es.ImGuiID };
    languageOptions[2] = { "简体中文 (Chinese Simplified)",       zh_hans.ImGuiID };
    languageOptions[3] = { "Français (French)",               fr.ImGuiID };
    languageOptions[4] = { "Português (Portuguese)",          pt.ImGuiID };
    languageOptions[5] = { "Русский (Russian)",               ru.ImGuiID };
    languageOptions[6] = { "Bahasa Indonesia (Indonesian)",   id.ImGuiID };
    languageOptions[7] = { "Deutsch (German)",                de.ImGuiID };
    languageOptions[8] = { "日本語 (Japanese)",                  ja.ImGuiID };
    languageOptions[9] = { "Türkçe (Turkish)",                tr.ImGuiID };
    languageOptions[10] = { "Tiếng Việt (Vietnamese)",         vi.ImGuiID };
    languageOptions[11] = { "Filipino (Filipino)",             fil.ImGuiID };
    languageOptions[12] = { "Kiswahili (Swahili)",             sw.ImGuiID };
    languageOptions[13] = { "Hausa (Hausa)",                   ha.ImGuiID };
    languageOptions[14] = { "한국어 (Korean)",                    ko.ImGuiID };
    languageOptions[15] = { "Basa Jawa (Javanese)",            jv.ImGuiID };
    languageOptions[16] = { "Italiano (Italian)",              it.ImGuiID };
    languageOptions[17] = { "Bahasa Melayu (Malay)",           ms.ImGuiID };
    languageOptions[18] = { "አማርኛ (Amharic)",                  am.ImGuiID };
    languageOptions[19] = { "Yorùbá (Yoruba)",                 yo.ImGuiID };
    languageOptions[20] = { "Afaan Oromoo (Oromo)",            om.ImGuiID };
    languageOptions[21] = { "Basa Sunda (Sundanese)",          su.ImGuiID };
    languageOptions[22] = { "Polski (Polish)",                 pl.ImGuiID };
    languageOptions[23] = { "Lingála (Lingala)",               ln.ImGuiID };
    languageOptions[24] = { "Українська (Ukrainian)",          uk.ImGuiID };
    languageOptions[25] = { "Fulfulde (Fula)",                 ff.ImGuiID };
    languageOptions[26] = { "繁體中文 (Chinese Traditional)",      zh_hant.ImGuiID };
    languageOptions[27] = { "Oʻzbekcha (Uzbek)",               uz.ImGuiID };
    languageOptions[28] = { "Asụsụ Igbo (Igbo)",               ig.ImGuiID };
    languageOptions[29] = { "isiZulu (Zulu)",                  zu.ImGuiID };
    languageOptions[30] = { "Cebuano (Cebuano)",               ceb.ImGuiID };
    languageOptions[31] = { "Nederlands (Dutch)",              nl.ImGuiID };
    languageOptions[32] = { "Malagasy (Malagasy)",             mg.ImGuiID };
    languageOptions[33] = { "Română (Romanian)",               ro.ImGuiID };
    languageOptions[34] = { "Azərbaycanca (Azerbaijani)",      az.ImGuiID };
    languageOptions[35] = { "Soomaali (Somali)",               so.ImGuiID };
    languageOptions[36] = { "Wolof (Wolof)",                   wo.ImGuiID };
    languageOptions[37] = { "isiXhosa (Xhosa)",                xh.ImGuiID };
    languageOptions[38] = { "Afrikaans (Afrikaans)",           af.ImGuiID };
    languageOptions[39] = { "Қазақша (Kazakh)",                kk.ImGuiID };
    languageOptions[40] = { "Kurmancî (Kurdish)",              kmr.ImGuiID };
    languageOptions[41] = { "Ikinyarwanda (Kinyarwanda)",      rw.ImGuiID };
    languageOptions[42] = { "chiShona (Shona)",                sn.ImGuiID };
    languageOptions[43] = { "Chichewa (Chichewa)",             ny.ImGuiID };
    languageOptions[44] = { "Ελληνικά (Greek)",                el.ImGuiID };
    languageOptions[45] = { "Magyar (Hungarian)",              hu.ImGuiID };
    languageOptions[46] = { "Svenska (Swedish)",               sv.ImGuiID };
    languageOptions[47] = { "Kreyòl ayisyen (Haitian Creole)", ht.ImGuiID };
    languageOptions[48] = { "Čeština (Czech)",                 cs.ImGuiID };
    languageOptions[49] = { "Српски (Serbian)",                sr.ImGuiID };
    languageOptions[50] = { "Català (Catalan)",                ca.ImGuiID };
    languageOptions[51] = { "ትግርኛ (Tigrinya)",                 ti.ImGuiID };
    languageOptions[52] = { "Български (Bulgarian)",           bg.ImGuiID };
    languageOptions[53] = { "Тоҷикӣ (Tajik)",                  tg.ImGuiID };
    languageOptions[54] = { "Runa Simi (Quechua)",             qu.ImGuiID };
    languageOptions[55] = { "Shqip (Albanian)",                sq.ImGuiID };
    languageOptions[56] = { "Slovenčina (Slovak)",             sk.ImGuiID };
    languageOptions[57] = { "Türkmençe (Turkmen)",             tk.ImGuiID };
    languageOptions[58] = { "Հայերեն (Armenian)",              hy.ImGuiID };
    languageOptions[59] = { "Avañe'ẽ (Guarani)",               gn.ImGuiID };
    languageOptions[60] = { "Hrvatski (Croatian)",             hr.ImGuiID };
    languageOptions[61] = { "Dansk (Danish)",                  da.ImGuiID };
    languageOptions[62] = { "Suomi (Finnish)",                 fi.ImGuiID };
    languageOptions[63] = { "Кыргызча (Kyrgyz)",               ky.ImGuiID };
    languageOptions[64] = { "Norsk (Norwegian)",               nb.ImGuiID };
    languageOptions[65] = { "Беларуская (Belarusian)",         be.ImGuiID };
    languageOptions[66] = { "Татарча (Tatar)",                 tt.ImGuiID };
    languageOptions[67] = { "ქართული (Georgian)",              ka.ImGuiID };
    languageOptions[68] = { "Монгол (Mongolian)",              mn.ImGuiID };
    languageOptions[69] = { "Bosanski (Bosnian)",              bs.ImGuiID };
    languageOptions[70] = { "Galego (Galician)",               gl.ImGuiID };
    languageOptions[71] = { "Lietuvių (Lithuanian)",           lt.ImGuiID };
    languageOptions[72] = { "Slovenščina (Slovenian)",         sl.ImGuiID };
    languageOptions[73] = { "Latviešu (Latvian)",              lv.ImGuiID };
    languageOptions[74] = { "Македонски (Macedonian)",         mk.ImGuiID };
    languageOptions[75] = { "Gaeilge (Irish)",                 ga.ImGuiID };
    languageOptions[76] = { "Eesti (Estonian)",                et.ImGuiID };
    languageOptions[77] = { "Esperanto (Esperanto)",           eo.ImGuiID };
    languageOptions[78] = { "Euskara (Basque)",                eu.ImGuiID };
    languageOptions[79] = { "Cymraeg (Welsh)",                 cy.ImGuiID };
    languageOptions[80] = { "Lëtzebuergesch (Luxembourgish)",  lb.ImGuiID };
    languageOptions[81] = { "Malti (Maltese)",                 mt.ImGuiID };
    languageOptions[82] = { "Íslenska (Icelandic)",            is.ImGuiID };
    languageOptions[83] = { "Føroyskt (Faroese)",              fo.ImGuiID };
    
}

void GUI::deleteTextures() {
    glDeleteTextures(1, &gear.GLID);
    glDeleteTextures(1, &folder.GLID);
    glDeleteTextures(1, &swap.GLID);
    glDeleteTextures(1, &eye.GLID);
    glDeleteTextures(1, &eyeS.GLID);
    glDeleteTextures(1, &dice.GLID);

    for(unsigned int i = 0; i < (unsigned int) Language::Count; i++) {
        glDeleteTextures(1, &languageTextures[i].GLID);
    }
}

void GUI::computeButtonSize() {
    buttonSize = (float)(currentFontSize + 6);
}

// To compute Buttons width
float GUI::getInputTextWidth(const std::string& textLabel, float buttonWidth, int buttonsCount) { //const std::string& buttonLabel) {
    bool isImage = true;
    
    // Anchos fijos de los elementos que NO quieres que se encojan
    float textWidth   = ImGui::CalcTextSize((textLabel + ':').c_str()).x;

    float finalButtonWidth;
    if(isImage) {
        // Is an image, the received buttonWidth is exactly the size we need
        finalButtonWidth = buttonWidth;
    } else {
        // Is not an image, we must add margin pixels to the received buttonWidth
        finalButtonWidth = buttonWidth + ImGui::GetStyle().FramePadding.x * 2.0f;
    }

    // Espaciado horizontal que ImGui mete automáticamente entre elementos con SameLine()
    float spacing = ImGui::GetStyle().ItemSpacing.x;

    // Ancho total disponible en la ventana/región actual
    float margin = 7.0f;
    // The ImGui available width or height is 2 pixels smaller than the GLFW window size
    float availWidth = GLFWWindowWidth - 2.0f - 2.0f * margin; // Lo hacemos así porque GetContentRegionAvail().x no nos devuelve el valor que necesitamos

    // Ancho que le queda al InputText (con un mínimo para que no desaparezca)
    float inputWidth = availWidth - textWidth - finalButtonWidth * buttonsCount - (spacing * (buttonsCount + 1));
    inputWidth = std::max(inputWidth, 20.0f);

    return inputWidth;
}

void GUI::onClickOverEncryptButton() {
    try {
        if(password == "") {
            throw std::runtime_error(T(Str::EmptyPasswordErrorMessage));
        }
        if(currentMode == 1) { // Plaintext mode
            if(std::filesystem::is_directory(path)) {
                throw std::runtime_error(T(Str::OutputFileIsDirectoryErrorMessage));
            }
            if(!std::filesystem::exists(path) && path == "") {
                throw std::runtime_error(T(Str::EmptyOutputFilePathErrorMessage));
            }
        } else if (currentMode == 0) { // Normal mode
            if(std::filesystem::is_directory(outputFilePath)) {
                throw std::runtime_error(T(Str::OutputFileIsDirectoryErrorMessage));
            }
            if(!std::filesystem::exists(outputFilePath) && outputFilePath == "") {
                throw std::runtime_error(T(Str::EmptyOutputFilePathErrorMessage));
            }
            if(inputFilePath == "") {
                throw std::runtime_error(T(Str::EmptyInputFilePathErrorMessage));
            }
            if(!std::filesystem::exists(inputFilePath)) {
                throw std::runtime_error(T(Str::SourceFileDoesNotExistErrorMessage));
            }
        }
        if(currentMode == 1 && path != "" && password != "") {
			if(cipherMode == 0) {
				encrypt(path, message, password);
			} else if (cipherMode == 1) {
				encryptOpenSSLCompatible(path, message, password);
			}
			checkFilePath();
        } else if(currentMode == 0 && inputFilePath != "" && outputFilePath != "" && password != "") {
            in = cargarFichero(inputFilePath);
            if(cipherMode == 0) {
				encrypt(outputFilePath, in, password);
			} else if (cipherMode == 1) {
				encryptOpenSSLCompatible(outputFilePath, in, password);
			}
			wipe(in);
            in.clear();
			checkOutputFilePath();
        }
    } catch (const std::runtime_error& e) {
        warningMessage = e.what();
        warningAlarm = true;
        ImGui::OpenPopup((T(Str::WarningTitle) + "###WarningTitle").c_str());
    } catch ( ... ) {
        warningMessage = T(Str::UnknownExceptionText);
        warningAlarm = true;
        ImGui::OpenPopup((T(Str::WarningTitle) + "###WarningTitle").c_str());
    }
}

void GUI::onClickOverDecryptButton() {
    try {
        if(password == "") {
            throw std::runtime_error(T(Str::EmptyPasswordErrorMessage));
        }
        if(currentMode == 1) { // Plaintext mode
            if(std::filesystem::is_directory(path)) {
                throw std::runtime_error(T(Str::InputFileIsDirectoryErrorMessage));
            }
            if(!std::filesystem::exists(path) && path == "") {
                throw std::runtime_error(T(Str::EmptyInputFilePathErrorMessage));
            }
        } else if (currentMode == 0) { // Normal mode
            if(std::filesystem::is_directory(outputFilePath)) {
                throw std::runtime_error(T(Str::OutputFileIsDirectoryErrorMessage));
            }
            if(!std::filesystem::exists(outputFilePath) && outputFilePath == "") {
                throw std::runtime_error(T(Str::EmptyOutputFilePathErrorMessage));
            }
            if(inputFilePath == "") {
                throw std::runtime_error(T(Str::EmptyInputFilePathErrorMessage));
            }
            if(!std::filesystem::exists(inputFilePath)) {
                throw std::runtime_error(T(Str::SourceFileDoesNotExistErrorMessage));
            }
        }
        if(currentMode == 1 && path != "" && password != "") {
			if(cipherMode == 0) {
				wipe(message);
				message = decrypt(path, password);
			} else if (cipherMode == 1) {
				wipe(message);
				message = decryptOpenSSLCompatible(path, password);
			}
			checkFilePath();
        } else if(currentMode == 0 && inputFilePath != "" && outputFilePath != "" && password != "") {
			if(cipherMode == 0) {
				decrypt(inputFilePath, outputFilePath, password);
			} else if (cipherMode == 1) {
				decryptOpenSSLCompatible(inputFilePath, outputFilePath, password);
			}
			checkOutputFilePath();
        }
    } catch (const std::runtime_error& e) {
        warningMessage = e.what();
        warningAlarm = true;
        ImGui::OpenPopup((T(Str::WarningTitle) + "###WarningTitle").c_str());
    } catch ( ... ) {
        warningMessage = T(Str::UnknownExceptionText);
        warningAlarm = true;
        ImGui::OpenPopup((T(Str::WarningTitle) + "###WarningTitle").c_str());
    }
}

void GUI::drawPasswordSection() {
    ImGui::Text((T(Str::PasswordLabel) + ':').c_str());
    ImGui::SameLine();
    ImGui::SetNextItemWidth(getInputTextWidth(T(Str::PasswordLabel), buttonSize, 2));
	if(showPasswordFlag) {
		ImGui::InputText("###password", &password);
	} else {
		ImGui::InputText("###password", &password, ImGuiInputTextFlags_Password);
	}
	
    ImGui::SameLine();
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.15f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.25f));
    if(showPasswordFlag) {
		if (ImGui::ImageButton("###showPasswordButton", eye.ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
			showPasswordFlag = false;
		}
	} else {
		if (ImGui::ImageButton("###showPasswordButton", eyeS.ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
			showPasswordFlag = true;
		}
	}
	if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
    }
	ImGui::SameLine();
	if (ImGui::ImageButton("###generatePassword", dice.ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
		generatePasswordPopUpFlag = true;
		generatedPassword = getSecurePassword(currentPasswordLenght);
		ImGui::OpenPopup((T(Str::GeneratePasswordTitle) + "###generatePasswordTitle").c_str());
	}
	if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
    }
    ImGui::PopStyleColor(3);
    ImGui::PopStyleVar();
}

void GUI::encryptAndDecryptButtons(ImGuiIO& io) {
	
	centerButtons(T(Str::EncryptText), T(Str::DecryptText));
	
    if(ImGui::Button((T(Str::EncryptText) + "###EncryptButton").c_str())) {
        std::string currentPath = currentMode == 1 ? path : outputFilePath;
        if (std::filesystem::is_regular_file(currentPath)) {
            areYouSure = true;
            areYouSureTextMessage = T(Str::TheFileLabel) + ' ' + split(currentPath, getSlash()).back() + ' ' + T(Str::WillBeOverwrittenLabel);
            currentAction = encrypting;
            ImGui::OpenPopup((T(Str::AreYouSureTitle) + "###AreYouSureTitle").c_str());
        } else if (!std::filesystem::exists(currentPath)) {
            onClickOverEncryptButton();
        }
    }
    ImGui::SameLine();
    if(ImGui::Button((T(Str::DecryptText) + "###DecryptButton").c_str())) {
        std::string currentPath = currentMode == 1 ? path : outputFilePath;
        if (currentMode == 0 && std::filesystem::is_regular_file(currentPath)) {
            areYouSure = true;
            areYouSureTextMessage = T(Str::TheFileLabel) + ' ' + split(currentPath, getSlash()).back() + ' ' + T(Str::WillBeOverwrittenLabel);
            currentAction = decrypting;
            ImGui::OpenPopup((T(Str::AreYouSureTitle) + "###AreYouSureTitle").c_str());
        } else {
            onClickOverDecryptButton();
        }
    }
}

void GUI::draw(ImGuiIO& io) {
	
	centro = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f); // Compute window center

    // 1. Forzar posición (esquina superior izquierda) y tamaño (toda la pantalla)
    ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
    ImGui::SetNextWindowSize(io.DisplaySize);

    // 2. Iniciar la ventana
    ImGui::Begin("###mainWindow", nullptr, main_window_flags);
    windowWidth = ImGui::GetContentRegionAvail().x;

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    if (ImGui::ImageButton("###languageImageButton", languageTextures[(unsigned int) currentLanguage].ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f))) {
        selectLanguagePopUpFlag = true;
		ImGui::OpenPopup((T(Str::SelectLanguageTitle) + "###selectLanguage").c_str());
    }
    ImGui::PopStyleColor(3);
    ImGui::PopStyleVar();

    // Opcional: Para cambiar el cursor al pasar por encima (efecto 'mano')
    if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
    }
    ImGui::SameLine();

    comboWidthForMode = ImGui::CalcTextSize(maxOptionModeString.c_str()).x + style->FramePadding.x * 1.0f + style->ItemInnerSpacing.x + currentFontSize + 6.0f;
    
    float modeComboTotalLenght = ImGui::CalcTextSize((T(Str::ModeLabel) + ":").c_str()).x + // Label
								 style->ItemSpacing.x + // ImGui::SameLine() introduce este espaciado
								 comboWidthForMode; // Combo
    float cursorX = (windowWidth - modeComboTotalLenght) * 0.5f;
    
	if (cursorX > 0.0f)
		ImGui::SetCursorPosX(std::round(cursorX));
	
	ImGui::Text((T(Str::ModeLabel) + ":").c_str());

	ImGui::SameLine();

	ImGui::SetNextItemWidth(comboWidthForMode);
	if (ImGui::Combo("###modeCombo", &currentMode,
		[](void* data, int idx) -> const char* {
			auto& vec = *static_cast<std::vector<std::string>*>(data);
			return vec[idx].c_str();
		},
		static_cast<void*>(&options), (int)options.size()))
	{
		// cambio de selección
	}

	if (ImGui::IsItemHovered() && currentMode == 1) {
		ImGui::BeginTooltip();
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 5.0f)); // Lo hacemos asi en lugar de usar la funcion SetTooltip() para controlar el espaciado vertical cuando nuestro texto tiene varias lineas
		ImGui::Text(T(Str::PlainTextModeMessage_FirstLine).c_str());
		ImGui::Text(T(Str::PlainTextModeMessage_SecondLine).c_str());
		ImGui::PopStyleVar();
		ImGui::EndTooltip();
	}
    
    ImGui::SameLine();
    
    // Alinear botón a la derecha
    ImGui::SetCursorPosX(windowWidth - buttonSize + style->WindowPadding.x);
    
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    if (ImGui::ImageButton("###gearButton", gear.ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
		showSettingsMenu = true;
		currentFontSizeForSettingsMenu = currentFontSize;
		ImGui::OpenPopup((T(Str::SettingsTitle) + "###settingsMenu").c_str());
    }
    if (ImGui::IsItemHovered()) {
		ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
	}
    ImGui::PopStyleColor(3);
    ImGui::PopStyleVar();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

	switch (currentMode) {
		case 0: // Normal mode
			ImGui::Text((T(Str::InputFilePathLabel) + ':').c_str());
			ImGui::SameLine();
			ImGui::SetNextItemWidth(getInputTextWidth(T(Str::InputFilePathLabel), buttonSize, 1));
			
			if(ImGui::InputText("###inputFilePath", &inputFilePath)) {
				inputFileExists = std::filesystem::is_regular_file(inputFilePath);
				if(!inputFileExists) {
					showInputFileSHA = false;
				}
			}
			
			if (ImGui::IsItemActive() && io.KeyCtrl) {
				if (ImGui::IsKeyPressed(ImGuiKey_V) || ImGui::IsKeyPressed(ImGuiKey_X)) {
					// Ctrl+V o Ctrl+X detectado sobre este InputText
					inputFileExists = std::filesystem::is_regular_file(inputFilePath);
					if(!inputFileExists) {
						showInputFileSHA = false;
					}
				}
			}

			if (ImGui::IsItemClicked() && ImGui::IsKeyDown(ImGuiMod_Ctrl) && inputFileExists) { // SHA256
				std::vector<uint8_t> in = cargarFichero(inputFilePath);
				inputFileSHA = toUpper(toHexString(SHA256::getHash(in)));
				in.clear();
				showInputFileSHA = true;
			}

			if (ImGui::IsItemHovered() && inputFileExists) {
				ImGui::SetTooltip(T(Str::GetSHA256Text).c_str());
			}

			ImGui::SameLine();

			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f)); // margenes a 0.0f
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.15f)); // ligero resalte blanco semitransparente
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.25f));
			if(ImGui::ImageButton("###inputFileDialog", folder.ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
				std::string auxString = openFileDialog();
				if(!auxString.empty()) {
					inputFilePath = auxString;
					inputFileExists = std::filesystem::is_regular_file(inputFilePath);

				}
			}
			if (ImGui::IsItemHovered()) {
				ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
			}
			ImGui::PopStyleColor(3);
			ImGui::PopStyleVar();

			ImGui::Spacing();
			
			if(showInputFileSHA) {
				ImGui::Text(("SHA256: " + inputFileSHA).c_str());
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f)); // margenes a 0.0f
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.15f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.25f));
			ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (ImGui::GetContentRegionAvail().x - buttonSize) * 0.5f);
			if(ImGui::ImageButton("###swapPathsButton", swap.ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
				std::string auxString = inputFilePath;
				inputFilePath = outputFilePath;
				outputFilePath = auxString;
				
				bool auxBool = inputFileExists;
				inputFileExists = outputFileExists;
				outputFileExists = auxBool;
				
				auxBool = showInputFileSHA;
				showInputFileSHA = showOutputFileSHA;
				showOutputFileSHA = auxBool;
				
				auxString = inputFileSHA;
				inputFileSHA = outputFileSHA;
				outputFileSHA = auxString;
			}
			
			if (ImGui::IsItemHovered()) {
				ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
			}
			
			ImGui::PopStyleColor(3);
			ImGui::PopStyleVar();

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::Text((T(Str::OutputFilePathLabel) + ':').c_str());
			ImGui::SameLine();
			ImGui::SetNextItemWidth(getInputTextWidth(T(Str::OutputFilePathLabel), buttonSize, 1));
			
			if(ImGui::InputText("###outputFilePath", &outputFilePath)) {

				outputFileExists = std::filesystem::is_regular_file(outputFilePath);
				if(!outputFileExists) {
					showOutputFileSHA = false;
				}
			}
			
			if (ImGui::IsItemActive() && io.KeyCtrl) {
				if (ImGui::IsKeyPressed(ImGuiKey_V) || ImGui::IsKeyPressed(ImGuiKey_X)) {
					// Ctrl+V o Ctrl+X detectado sobre este InputText
					inputFileExists = std::filesystem::is_regular_file(inputFilePath);
					if(!inputFileExists) {
						showInputFileSHA = false;
					}
				}
			}

			if (ImGui::IsItemClicked() && ImGui::IsKeyDown(ImGuiMod_Ctrl) && outputFileExists) { // SHA256
				std::vector<uint8_t> in = cargarFichero(outputFilePath);
				outputFileSHA = toUpper(toHexString(SHA256::getHash(in)));
				in.clear();
				showOutputFileSHA = true;
			}

			if (ImGui::IsItemHovered() && outputFileExists) {
				ImGui::SetTooltip(T(Str::GetSHA256Text).c_str());
			}

			ImGui::SameLine();

			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.15f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.25f));
			if(ImGui::ImageButton("###outputFileDialog", folder.ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
				std::string auxString = openFileDialog();
				if(!auxString.empty()) {
					outputFilePath = auxString;
					outputFileExists = std::filesystem::is_regular_file(outputFilePath);

				}
			}
			if (ImGui::IsItemHovered()) {
				ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
			}
			ImGui::PopStyleColor(3);
			ImGui::PopStyleVar();

			ImGui::Spacing();

			if(showOutputFileSHA) {
				ImGui::Text(("SHA256: " + outputFileSHA).c_str());
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			drawPasswordSection();
			
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			encryptAndDecryptButtons(io);
			
			break;

		case 1: // Plaintext mode
			ImGui::Text((T(Str::PathLabel) + ':').c_str());
			ImGui::SameLine();
			ImGui::SetNextItemWidth(getInputTextWidth(T(Str::PathLabel), buttonSize, 1));
			
			if(ImGui::InputText("###path", &path)) {

				fileExists = std::filesystem::is_regular_file(path);
				if(!fileExists) {
					showFileSHA = false;
				}
			}
			
			if (ImGui::IsItemActive() && io.KeyCtrl) {
				if (ImGui::IsKeyPressed(ImGuiKey_V) || ImGui::IsKeyPressed(ImGuiKey_X)) {
					// Ctrl+V o Ctrl+X detectado sobre este InputText
					fileExists = std::filesystem::is_regular_file(path);
					if(!fileExists) {
						showFileSHA = false;
					}
				}
			}

			if (ImGui::IsItemClicked() && ImGui::IsKeyDown(ImGuiMod_Ctrl) && fileExists) { // SHA256
				std::vector<uint8_t> in = cargarFichero(path);
				fileSHA = toUpper(toHexString(SHA256::getHash(in)));
				in.clear();
				showFileSHA = true;
			}

			if (ImGui::IsItemHovered() && fileExists) {
				ImGui::SetTooltip(T(Str::GetSHA256Text).c_str());
			}

			ImGui::SameLine();

			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));

			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(1.0f, 1.0f, 1.0f, 0.15f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 1.0f, 1.0f, 0.25f));
			if (ImGui::ImageButton("###folderButton", folder.ImGuiID, ImVec2(buttonSize, buttonSize), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
				path = openFileDialog();

			}
			if (ImGui::IsItemHovered()) {
				ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
			}
			ImGui::PopStyleColor(3);
			ImGui::PopStyleVar();

			ImGui::Spacing();

			if(showFileSHA) {
				ImGui::Text(("SHA256: " + fileSHA).c_str());
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			drawPasswordSection();
			
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();
			
			encryptAndDecryptButtons(io);
			
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			ImGui::InputTextMultiline("###message", &message, ImGui::GetContentRegionAvail());
			
			break;
	}

	bool isPopUpOpen = false;

	// -----------------------------------------------------------------
	// Are you sure? popup
	// -----------------------------------------------------------------

	// 1. Establecer posición y pivote
	// (0.5f, 0.5f) indica que el punto de anclaje de la ventana es su propio CENTRO, no la esquina superior izquierda
	ImGui::SetNextWindowPos(centro, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

	applySpecialCaseColorFont();
	isPopUpOpen = ImGui::BeginPopupModal((T(Str::AreYouSureTitle) + "###AreYouSureTitle").c_str(), &areYouSure, popup_window_flags);
    removeSpecialCaseColorFont();

	if(isPopUpOpen) {
		
		windowWidth = ImGui::GetContentRegionAvail().x;
		
		centerText(areYouSureTextMessage);
		ImGui::TextUnformatted(areYouSureTextMessage.c_str());
		
		ImGui::Spacing();
		
		centerButtons(T(Str::YesLabel), T(Str::NoLabel));
		
		if(ImGui::Button(T(Str::YesLabel).c_str())) {
			areYouSure = false;
			ImGui::CloseCurrentPopup();
			ImGui::EndPopup();
			if(currentAction == encrypting) {
				onClickOverEncryptButton();
			} else if(currentAction == decrypting) {
				onClickOverDecryptButton();
			}
		} else {
			ImGui::SameLine();
			if(ImGui::Button(T(Str::NoLabel).c_str())) {
				areYouSure = false;
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();
		}
	}

	// -----------------------------------------------------------------
	// Warning message popup
	// -----------------------------------------------------------------

	ImGui::SetNextWindowPos(centro, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

	applySpecialCaseColorFont();
	isPopUpOpen = ImGui::BeginPopupModal((T(Str::WarningTitle) + "###WarningTitle").c_str(), &warningAlarm, popup_window_flags);
    removeSpecialCaseColorFont();
    
	if(isPopUpOpen) {
		windowWidth = ImGui::GetContentRegionAvail().x;
		
		centerText(warningMessage);
		ImGui::TextUnformatted(warningMessage.c_str());

		ImGui::Spacing();

		centerButton(T(Str::OkLabel));

		if(ImGui::Button(T(Str::OkLabel).c_str())) {
			warningMessage.clear();
			warningAlarm = false;
			ImGui::CloseCurrentPopup();
		}
		
		ImGui::EndPopup();
	}
	
	// -----------------------------------------------------------------
	// Settings menu popup
	// -----------------------------------------------------------------
	
	ImGui::PushFont(nullptr, (float)currentFontSizeForSettingsMenu); // Push para el tamaño de letra mientras el menú de opciones está abierto

	ImGui::SetNextWindowPos(centro, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

	applySpecialCaseColorFont();
	isPopUpOpen = ImGui::BeginPopupModal((T(Str::SettingsTitle) + "###settingsMenu").c_str(), &showSettingsMenu, popup_window_flags);
    removeSpecialCaseColorFont();
    
	if(isPopUpOpen) { // Modo Normal/Plaintext

		windowWidth = ImGui::GetContentRegionAvail().x;
		
		centerCheckboxForSettingsMenu(T(Str::InterfaceSettingsLabel));
		ImGui::Checkbox(T(Str::InterfaceSettingsLabel).c_str(), &showInterfaceSettings);
		
		if(showInterfaceSettings) {
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			// Tamaño interfaz
			centerText(T(Str::InterfaceSizeLabel));
			ImGui::Text(T(Str::InterfaceSizeLabel).c_str());
			
			ImGui::Spacing();
			
			ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + (windowWidth - 16.0f * currentFontSizeForSettingsMenu) * 0.5f));
			if (ImGui::SliderScalar("###interfaceSize", ImGuiDataType_U32, &currentFontSize, &minFontSize, &maxFontSize)) {
				computeButtonSize();
			}
			
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			// Tema interfaz
			centerText(T(Str::InterfaceThemeLabel));
			ImGui::Text(T(Str::InterfaceThemeLabel).c_str());
			
			ImGui::Spacing();

			centerComboForSettingsMenu(maxThemeNameString);
			ImGui::SetNextItemWidth(comboWidthForInterfaceSettingsMenu);
			if (ImGui::Combo("###themeCombo", &currentTheme,
				[](void* data, int idx) -> const char* {
					auto& vec = *static_cast<std::vector<std::string>*>(data);
					return vec[idx].c_str();
				},
				static_cast<void*>(&themes), (int)themes.size()))
			{
				// cambio de selección
				ApplyTheme();
				ApplyColor();
				checkSpecialThemeCases();
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			// Color interfaz
			centerText(T(Str::InterfaceColorLabel));
			ImGui::Text(T(Str::InterfaceColorLabel).c_str());
			
			ImGui::Spacing();
			
			centerComboForSettingsMenu(maxColorNameString);
			ImGui::SetNextItemWidth(comboWidthForInterfaceSettingsMenu);
			if (ImGui::Combo("###colorsCombo", &currentColor,
				[](void* data, int idx) -> const char* {
					auto& vec = *static_cast<std::vector<std::string>*>(data);
					return vec[idx].c_str();
				},
				static_cast<void*>(&colors), (int)colors.size()))
			{
				// cambio de selección
				ApplyColor();
				checkSpecialThemeCases();
			}
		}
		
		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();
		
		centerCheckboxForSettingsMenu(T(Str::OutFormatLabel));
		ImGui::Checkbox(T(Str::OutFormatLabel).c_str(), &showCipherAlgorithmSettings);
		
		if(showCipherAlgorithmSettings) {
			
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();
			
			centerComboForSettingsMenu(maxCipherModeString);
			ImGui::SetNextItemWidth(comboWidthForInterfaceSettingsMenu);
			if (ImGui::Combo("###cipherModeCombo", &cipherMode,
				[](void* data, int idx) -> const char* {
					auto& vec = *static_cast<std::vector<std::string>*>(data);
					return vec[idx].c_str();
				},
				static_cast<void*>(&cipherModes), (int)cipherModes.size()))
			{
				
			}

			if(cipherMode == 0) { // Default
				ImGui::Spacing();
				if(ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 5.0f)); // Lo hacemos asi en lugar de usar la funcion SetTooltip() para controlar el espaciado vertical cuando nuestro texto tiene varias lineas
					ImGui::Text(T(Str::DefaultCipherModeText_FirstLine).c_str());
					ImGui::Text(T(Str::DefaultCipherModeText_SecondLine).c_str());
					ImGui::PopStyleVar();
					ImGui::EndTooltip();
				}
				centerText(T(Str::PBKDF2IterationsText));
				ImGui::Text(T(Str::PBKDF2IterationsText).c_str());
				ImGui::Spacing();
				if(ImGui::InputScalar("###iterations", ImGuiDataType_U32, &PBKDF2_ITERATIONS, &PBKDF2IterationsStep, nullptr, "%u")) {
					int aux = static_cast<int>(PBKDF2_ITERATIONS);
					aux = std::clamp(aux, 1, 10000000);
					PBKDF2_ITERATIONS = static_cast<uint32_t>(aux);
				}
			}
			
			if(cipherMode == 1) { // OpenSSL
				ImGui::Spacing();
				if(ImGui::IsItemHovered()) {
					ImGui::BeginTooltip();
					ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 5.0f));
					ImGui::Text(T(Str::OpenSSLCipherModeText_FirstLine).c_str());
					ImGui::Text(T(Str::OpenSSLCipherModeText_SecondLine).c_str());
					ImGui::PopStyleVar();
					ImGui::EndTooltip();
				}
				centerText(T(Str::PBKDF2IterationsText) + " 10000");
				ImGui::Text((T(Str::PBKDF2IterationsText) + " 10000").c_str());
				
			}
		}
		ImGui::EndPopup();
	}
	ImGui::PopFont(); // Pop para el tamaño de letra mientras el menú de opciones está abierto
    
	// -----------------------------------------------------------------
    // Generate random password popup
    // -----------------------------------------------------------------

	ImGui::SetNextWindowPos(centro, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

	applySpecialCaseColorFont();
	isPopUpOpen = ImGui::BeginPopupModal((T(Str::GeneratePasswordTitle) + "###generatePasswordTitle").c_str(), &generatePasswordPopUpFlag, popup_window_flags);
    removeSpecialCaseColorFont();

	if(isPopUpOpen) {
		
		windowWidth = ImGui::GetContentRegionAvail().x;
		
		centerText(T(Str::PasswordLabel) + ":");
		ImGui::Text((T(Str::PasswordLabel) + ":").c_str());
		
		ImGui::Spacing();
		
		centerText(generatedPassword);
		ImGui::TextUnformatted(generatedPassword.c_str());
		
		ImGui::Spacing();
		
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
		ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + (windowWidth - buttonSize * 2.0f) * 0.5f));
		if(ImGui::ImageButton("###generatePasswordButton", dice.ImGuiID, ImVec2(buttonSize * 2.0f, buttonSize * 2.0f), ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), ImVec4(0.0f, 0.0f, 0.0f, 0.0f), colorValues[static_cast<ThemeColor>(currentColor)])) {
			generatedPassword = getSecurePassword(currentPasswordLenght);
		}

		if (ImGui::IsItemHovered()) {
			ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
		}
		ImGui::PopStyleColor(3);
		ImGui::PopStyleVar();

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();
		
		centerText(T(Str::PasswordLenghtLabel) + ":");
		ImGui::Text((T(Str::PasswordLenghtLabel) + ":").c_str());
		
		ImGui::Spacing();

		ImGui::SetCursorPosX(std::round(ImGui::GetCursorPosX() + (windowWidth - 16.0f * currentFontSize) * 0.5f));
		if (ImGui::SliderScalar("###passwordLenght", ImGuiDataType_U32, &currentPasswordLenght, &minPasswordLenght, &maxPasswordLenght)) {
			generatedPassword = getSecurePassword(currentPasswordLenght);
		}
		
		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();
		
		centerButtons(T(Str::UsePasswordLabel), T(Str::CopyLabel));
		
		if(ImGui::Button(T(Str::UsePasswordLabel).c_str())) {
			password = generatedPassword;
		}
		
		ImGui::SameLine();
		
		if(ImGui::Button(T(Str::CopyLabel).c_str())) {
			copyToClipboard(generatedPassword);
		}
		ImGui::EndPopup();
	}
	
	// -----------------------------------------------------------------
    // Select language popup
    // -----------------------------------------------------------------

	ImGui::SetNextWindowPos(centro, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

	applySpecialCaseColorFont();
	isPopUpOpen = ImGui::BeginPopupModal((T(Str::SelectLanguageTitle) + "###selectLanguage").c_str(), &selectLanguagePopUpFlag, popup_window_flags);
    removeSpecialCaseColorFont();

	if(isPopUpOpen) {
		
		static ImGuiTextFilter filtro;

		float iconSize = ImGui::GetTextLineHeight();

		if (ImGui::BeginCombo("###ComboWithIcons", nullptr, ImGuiComboFlags_CustomPreview))
		{
			// Al abrir el desplegable: limpia la búsqueda anterior y pon el foco en el campo
			if (ImGui::IsWindowAppearing())
			{
				filtro.Clear();
				ImGui::SetKeyboardFocusHere();
			}

			// Campo de búsqueda ocupando todo el ancho del desplegable
			filtro.Draw("###filtro", -FLT_MIN);
			bool enterPulsado = ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter);

			ImGui::Separator();

			int primeraCoincidencia = -1;

			for (int i = 0; i < IM_ARRAYSIZE(languageOptions); i++)
			{
				if (!filtro.PassFilter(languageOptions[i].text))
					continue; // no coincide con lo tecleado: no se muestra

				if (primeraCoincidencia == -1)
					primeraCoincidencia = i;

				ImGui::PushID(i);
				bool isSelected = (static_cast<int>(currentLanguage) == i);

				ImVec2 posInicial = ImGui::GetCursorPos();
				if (ImGui::Selectable("##opcion", isSelected, 0, ImVec2(0.0f, iconSize))) {
					currentLanguage = static_cast<Language>(i);
					updateOptionsOfCombos();
				}

				ImGui::SetCursorPos(posInicial);
				ImGui::Image(languageOptions[i].texture, ImVec2(iconSize, iconSize));
				ImGui::SameLine();
				ImGui::TextUnformatted(languageOptions[i].text);

				ImGui::PopID();
			}

			// Enter: selecciona la primera opción visible y cierra el combo
			if (enterPulsado && primeraCoincidencia != -1)
			{
				currentLanguage = static_cast<Language>(primeraCoincidencia);
				ImGui::CloseCurrentPopup();
			}

			ImGui::EndCombo();
		}

		if (ImGui::BeginComboPreview())
		{
			ImGui::Image(languageOptions[static_cast<unsigned int>(currentLanguage)].texture, ImVec2(iconSize, iconSize));
			ImGui::SameLine();
			ImGui::TextUnformatted(languageOptions[static_cast<unsigned int>(currentLanguage)].text);
			ImGui::EndComboPreview();
		}

		ImGui::EndPopup();
	}

    ImGui::End();
}
