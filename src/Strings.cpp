#include "Strings.h"

Language currentLanguage = Language::English;

std::map<std::string, Language> languages = {
    {"English", Language::English},
    {"Spanish", Language::Spanish},
    {"ChineseSimplified", Language::ChineseSimplified},
    {"French", Language::French},
    {"Portuguese", Language::Portuguese},
    {"Russian", Language::Russian},
    {"Indonesian", Language::Indonesian},
    {"German", Language::German},
    {"Japanese", Language::Japanese},
    {"Turkish", Language::Turkish},
    {"Vietnamese", Language::Vietnamese},
    {"Filipino", Language::Filipino},
    {"Swahili", Language::Swahili},
    {"Hausa", Language::Hausa},
    {"Korean", Language::Korean},
    {"Javanese", Language::Javanese},
    {"Italian", Language::Italian},
    {"Malay", Language::Malay},
    {"Amharic", Language::Amharic},
    {"Yoruba", Language::Yoruba},
    {"Oromo", Language::Oromo},
    {"Sundanese", Language::Sundanese},
    {"Polish", Language::Polish},
    {"Lingala", Language::Lingala},
    {"Ukrainian", Language::Ukrainian},
    {"Fula", Language::Fula},
    {"ChineseTraditional", Language::ChineseTraditional},
    {"Uzbek", Language::Uzbek},
    {"Igbo", Language::Igbo},
    {"Zulu", Language::Zulu},
    {"Cebuano", Language::Cebuano},
    {"Dutch", Language::Dutch},
    {"Malagasy", Language::Malagasy},
    {"Romanian", Language::Romanian},
    {"Azerbaijani", Language::Azerbaijani},
    {"Somali", Language::Somali},
    {"Wolof", Language::Wolof},
    {"Xhosa", Language::Xhosa},
    {"Afrikaans", Language::Afrikaans},
    {"Kazakh", Language::Kazakh},
    {"Kurdish", Language::Kurdish},
    {"Kinyarwanda", Language::Kinyarwanda},
    {"Shona", Language::Shona},
    {"Chichewa", Language::Chichewa},
    {"Greek", Language::Greek},
    {"Hungarian", Language::Hungarian},
    {"Swedish", Language::Swedish},
    {"HaitianCreole", Language::HaitianCreole},
    {"Czech", Language::Czech},
    {"Serbian", Language::Serbian},
    {"Catalan", Language::Catalan},
    {"Tigrinya", Language::Tigrinya},
    {"Bulgarian", Language::Bulgarian},
    {"Tajik", Language::Tajik},
    {"Quechua", Language::Quechua},
    {"Albanian", Language::Albanian},
    {"Slovak", Language::Slovak},
    {"Turkmen", Language::Turkmen},
    {"Armenian", Language::Armenian},
    {"Guarani", Language::Guarani},
    {"Croatian", Language::Croatian},
    {"Danish", Language::Danish},
    {"Finnish", Language::Finnish},
    {"Kyrgyz", Language::Kyrgyz},
    {"Norwegian", Language::Norwegian},
    {"Belarusian", Language::Belarusian},
    {"Tatar", Language::Tatar},
    {"Georgian", Language::Georgian},
    {"Mongolian", Language::Mongolian},
    {"Bosnian", Language::Bosnian},
    {"Galician", Language::Galician},
    {"Lithuanian", Language::Lithuanian},
    {"Slovenian", Language::Slovenian},
    {"Latvian", Language::Latvian},
    {"Macedonian", Language::Macedonian},
    {"Irish", Language::Irish},
    {"Estonian", Language::Estonian},
    {"Esperanto", Language::Esperanto},
    {"Basque", Language::Basque},
    {"Welsh", Language::Welsh},
    {"Luxembourgish", Language::Luxembourgish},
    {"Maltese", Language::Maltese},
    {"Icelandic", Language::Icelandic},
    {"Faroese", Language::Faroese}
};

const std::string getLanguageFromEnum(Language l) {
    for(auto it = languages.begin(); it != languages.end(); it++) {
        if(it->second == l) {
            return it->first;
        }
    }
    return "English";
}

namespace {

constexpr size_t N = static_cast<size_t>(Str::Count);
constexpr size_t L = static_cast<size_t>(Language::Count);

// Un bloque const char*[] por idioma. Cada uno se valida por
// separado con su propio static_assert, asi un olvido en la
// traduccion de un idioma concreto senala exactamente cual falla.
constexpr const char* textosEN[] = {

    
    
    // Info
    "Press Enter to exit...", // Str::ExitInfoMessage
    "Enable only if the file", // Str::PlainTextModeMessage_FirstLine
    "content is plain text", // Str::PlainTextModeMessage_SecondLine
    "The encrypted file will be", // Str::DefaultCipherModeText_FirstLine
    "saved as printable characters", // Str::DefaultCipherModeText_SecondLine
    "The encrypted file will be saved in", // Str::DefaultCipherModeText_FirstLine
    "binary format, compatible with OpenSSL", // Str::DefaultCipherModeText_SecondLine
    "PBKDF2 Iterations:", // Str::PBKDF2IterationsText
    // Errors
    "Error: incorrect parameters", // Str::WrongParamsText
    "Input value", // Str::InputValueText
    "Input path", // Str::InputPathText
    "The input value could not be converted to a number greater than or equal to 0", // Str::WrongNumberValueMessage
    "The input path does not correspond to any existing file", // Str::WrongPathValueMessage
    "The entered option is not recognized as a valid parameter", // Str::InvalidOptionMessage
    "Entered option", // Str::EnteredOptionText
    "Unknown exception", // Str::UnknownExceptionText
    "Failed to initialize GLFW", // Str::GLFWErrorMessage
    "Failed to initialize GLAD", // Str::GLADErrorMessage
    "Error: Could not open the file for reading", // Str::ReadFileErrorMessage
    "Error reading the file content", // Str::ErrorWhileReadingMessage
    "Error: Could not open the file for writing", // Str::WriteFileErrorMessage
    "Error: Hex string must have an even number of characters", // Str::HexStringErrorMessage
    "Error: Invalid hex character in string", // Str::InvalidHexCharacterErrorMessage
    "Error: Could not save the file", // Str::SaveFileErrorMessage
    "Error: Could not load the file", // Str::LoadFileErrorMessage
    "Error: Invalid file format (expected 5 fields: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Error: Number of iterations exceeds the established maximum (10,000,000)", // Str::MaxIterationsErrorMessage
    "Error: Integrity verification failed, incorrect password or corrupt/tampered file", // Str::IntegrityCheckErrorMessage
    "Error: The password cannot be empty", // Str::EmptyPasswordErrorMessage
    "Error: The destination file path is a directory", // Str::OutputFileIsDirectoryErrorMessage
    "Error: The source file path is a directory", // Str::InputFileIsDirectoryErrorMessage
    "Error: The destination file path cannot be empty", // Str::EmptyOutputFilePathErrorMessage
    "Error: The source file path cannot be empty", // Str::EmptyInputFilePathErrorMessage
    "Error: The source file does not exist", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Language: English", // Str::LanguageLabel
    "Password", // Str::PasswordLabel
    "Password length", // Str::PasswordLenghtLabel
    "File", // Str::FileLabel
    "The file", // Str::TheFileLabel
    "Path", // Str::PathLabel
    "Input file path", // Str::InputFilePathLabel
    "Output file path", // Str::OutputFilePathLabel
    "Swap paths", // Str::SwapPathsLabel
    "will be overwritten", // Str::WillBeOverwrittenLabel
    "Encrypting...", // Str::EncryptingText
    "Decrypting...", // Str::DecryptingText
    "Encrypt", // Str::EncryptText
    "Decrypt", // Str::DecryptText
    "File successfully encrypted", // Str::FileEncryptedMessage
    "File successfully decrypted", // Str::FileDecryptedMessage
    "Warning!", // Str::WarningTitle
    "Are you sure?", // Str::AreYouSureTitle
    "Settings", // Str::SettingsTitle
    "Password generator", // Str::GeneratePasswordTitle
    "Select language", // Str::SelectLanguageTitle
    "Yes", // Str::YesLabel
    "No", // Str::NoLabel
    "Ok", // Str::OkLabel
    "Output format", // Str::OutFormatLabel
    "Interface settings", // Str::InterfaceSettingsLabel
    "Size", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Plaintext", // Str::PlaintextModeLabel
    "Theme", // Str::InterfaceThemeLabel
    "Color", // Str::InterfaceColorLabel
    "Default (plaintext)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Use this password", // Str::UsePasswordLabel,
    "Copy", // Str::CopyLabel,
    "Ctrl + Left click to get SHA256", // Str::GetSHA256Text,
    // Themes
    "Light", // Str::LightThemeName
    "Dark", // Str::DarkThemeName
    // Colors
    "Blue", // Str::BlueName
    "Cyan", // Str::CyanName
    "Green", // Str::GreenName
    "Lime", // Str::LimeName
    "Yellow", // Str::YellowName
    "Brown", // Str::BrownName
    "Orange", // Str::OrangeName
    "Red", // Str::RedName
    "Pink", // Str::PinkName
    "Purple", // Str::PurpleName
    "Grey", // Str::GreyName
    "White", // Str::WhiteName
    "Black", // Str::BlackName

};
static_assert(sizeof(textosEN) / sizeof(textosEN[0]) == N,
    "Faltan o sobran textos en ingles: revisa que coincidan con Str::Count.");

constexpr const char* textosES[] = {

    
    
    // Info
    "Presiona Enter para salir...", // Str::ExitInfoMessage
    "Activar solo si el contenido", // Str::PlainTextModeMessage_FirstLine
    "del archivo es texto claro", // Str::PlainTextModeMessage_SecondLine
    "El archivo cifrado será guardado", // Str::DefaultCipherModeText_FirstLine
    "como caracteres imprimibles", // Str::DefaultCipherModeText_SecondLine
    "El archivo cifrado será guardado en", // Str::DefaultCipherModeText_FirstLine
    "formato binario, compatible con OpenSSL", // Str::DefaultCipherModeText_SecondLine
    "Iteraciones PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Error: parámetros incorrectos", // Str::WrongParamsText
    "Valor recibido", // Str::InputValueText
    "Ruta recibida", // Str::InputPathText
    "No se pudo convertir el valor recibido a un número mayor o igual que 0", // Str::WrongNumberValueMessage
    "La ruta recibida no se corresponde con ningún fichero existente", // Str::WrongPathValueMessage
    "La opción introducida no se reconoce como un parámetro válido", // Str::InvalidOptionMessage
    "Opción introducida", // Str::EnteredOptionText
    "Excepción desconocida", // Str::UnknownExceptionText
    "Error al iniciar GLFW", // Str::GLFWErrorMessage
    "Error al iniciar GLAD", // Str::GLADErrorMessage
    "Error: No se pudo abrir el archivo para lectura", // Str::ReadFileErrorMessage
    "Error al leer el contenido del archivo", // Str::ErrorWhileReadingMessage
    "Error: No se pudo abrir el archivo para escritura", // Str::WriteFileErrorMessage
    "Error: La cadena hexadecimal debe tener un número par de carácteres", // Str::HexStringErrorMessage
    "Error: Carácter hexadecimal no válido en la cadena", // Str::InvalidHexCharacterErrorMessage
    "Error: No se pudo guardar el fichero", // Str::SaveFileErrorMessage
    "Error: No se pudo abrir el fichero", // Str::LoadFileErrorMessage
    "Error: Formato de fichero inválido (se esperaban 5 campos: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Error: Número de iteraciones mayor que el máximo establecido (10.000.000)", // Str::MaxIterationsErrorMessage
    "Error: Verificación de integridad fallida, contraseña incorrecta o fichero corrupto/manipulado", // Str::IntegrityCheckErrorMessage
    "Error: La contraseña no puede estar vacía", // Str::EmptyPasswordErrorMessage
    "Error: La ruta del fichero destino es un directorio", // Str::OutputFileIsDirectoryErrorMessage
    "Error: La ruta del fichero origen es un directorio", // Str::InputFileIsDirectoryErrorMessage
    "Error: La ruta del fichero destino no puede estar vacía", // Str::EmptyOutputFilePathErrorMessage
    "Error: La ruta del fichero origen no puede estar vacía", // Str::EmptyInputFilePathErrorMessage
    "Error: El fichero origen no existe", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Idioma: Español", // Str::LanguageLabel
    "Contraseña", // Str::PasswordLabel
    "Longitud de la contraseña", // Str::PasswordLenghtLabel
    "Archivo", // Str::FileLabel
    "El archivo", // Str::TheFileLabel
    "Ruta", // Str::PathLabel
    "Ruta de entrada", // Str::InputFilePathLabel
    "Ruta de salida", // Str::OutputFilePathLabel
    "Intercambiar rutas", // Str::SwapPathsLabel
    "será sobreescrito", // Str::WillBeOverwrittenLabel
    "Cifrando...", // Str::EncryptingText
    "Descifrando...", // Str::DecryptingText
    "Cifrar", // Str::EncryptText
    "Descifrar", // Str::DecryptText
    "Archivo cifrado con éxito", // Str::FileEncryptedMessage
    "Archivo descifrado con éxito", // Str::FileDecryptedMessage
    "¡Alerta!", // Str::WarningTitle
    "¿Estás seguro?", // Str::AreYouSureTitle
    "Ajustes", // Str::SettingsTitle
    "Generador de contraseñas", // Str::GeneratePasswordTitle
    "Seleccionar idioma", // Str::SelectLanguageTitle
    "Sí", // Str::YesLabel
    "No", // Str::NoLabel
    "Ok", // Str::OkLabel
    "Formato de salida", // Str::OutFormatLabel
    "Ajustes de la interfaz", // Str::InterfaceSettingsLabel
    "Tamaño", // Str::InterfaceSizeLabel
    "Modo", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Texto claro", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Color", // Str::InterfaceColorLabel
    "Por defecto (texto claro)", // Str::DefaultLabel
    "OpenSSL (binario)", // Str::OpenSSLLabel
    "Usar esta contraseña", // Str::UsePasswordLabel,
    "Copiar", // Str::CopyLabel,
    "Ctrl + click izquierdo para obtener el SHA256", // Str::GetSHA256Text,
    // Themes
    "Claro", // Str::LightThemeName
    "Oscuro", // Str::DarkThemeName
    // Colors
    "Azul", // Str::BlueName
    "Celeste", // Str::CyanName
    "Verde", // Str::GreenName
    "Lima", // Str::LimeName
    "Amarillo", // Str::YellowName
    "Marrón", // Str::BrownName
    "Naranja", // Str::OrangeName
    "Rojo", // Str::RedName
    "Rosa", // Str::PinkName
    "Morado", // Str::PurpleName
    "Gris", // Str::GreyName
    "Blanco", // Str::WhiteName
    "Negro", // Str::BlackName

};
static_assert(sizeof(textosES) / sizeof(textosES[0]) == N,
    "Faltan o sobran textos en espanol: revisa que coincidan con Str::Count.");

// 简体中文 (zh-Hans)
constexpr const char* textosZH_HANS[] = {

    
    
    // Info
    "按 Enter 键退出...", // Str::ExitInfoMessage
    "仅当文件内容", // Str::PlainTextModeMessage_FirstLine
    "为纯文本时启用", // Str::PlainTextModeMessage_SecondLine
    "加密后的文件将保存为", // Str::DefaultCipherModeText_FirstLine
    "可打印字符", // Str::DefaultCipherModeText_SecondLine
    "加密后的文件将保存为", // Str::OpenSSLCipherModeText_FirstLine
    "二进制格式，与 OpenSSL 兼容", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 迭代次数：", // Str::PBKDF2IterationsText
    // Errors
    "错误：参数不正确", // Str::WrongParamsText
    "输入值", // Str::InputValueText
    "输入路径", // Str::InputPathText
    "无法将输入值转换为大于或等于 0 的数字", // Str::WrongNumberValueMessage
    "输入路径不对应任何现有文件", // Str::WrongPathValueMessage
    "输入的选项未被识别为有效参数", // Str::InvalidOptionMessage
    "输入的选项", // Str::EnteredOptionText
    "未知异常", // Str::UnknownExceptionText
    "GLFW 初始化失败", // Str::GLFWErrorMessage
    "GLAD 初始化失败", // Str::GLADErrorMessage
    "错误：无法打开文件进行读取", // Str::ReadFileErrorMessage
    "读取文件内容时出错", // Str::ErrorWhileReadingMessage
    "错误：无法打开文件进行写入", // Str::WriteFileErrorMessage
    "错误：十六进制字符串的字符数必须为偶数", // Str::HexStringErrorMessage
    "错误：字符串中包含无效的十六进制字符", // Str::InvalidHexCharacterErrorMessage
    "错误：无法保存文件", // Str::SaveFileErrorMessage
    "错误：无法加载文件", // Str::LoadFileErrorMessage
    "错误：文件格式无效（应有 5 个字段：ciphertext|iv|salt|iterations|mac）", // Str::InvalidFileFormatErrorMessage
    "错误：迭代次数超过设定的最大值（10,000,000）", // Str::MaxIterationsErrorMessage
    "错误：完整性校验失败，密码错误或文件已损坏/被修改", // Str::IntegrityCheckErrorMessage
    "错误：密码不能为空", // Str::EmptyPasswordErrorMessage
    "错误：目标文件路径是一个目录", // Str::OutputFileIsDirectoryErrorMessage
    "错误：源文件路径是一个目录", // Str::InputFileIsDirectoryErrorMessage
    "错误：目标文件路径不能为空", // Str::EmptyOutputFilePathErrorMessage
    "错误：源文件路径不能为空", // Str::EmptyInputFilePathErrorMessage
    "错误：源文件不存在", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "语言：简体中文", // Str::LanguageLabel
    "密码", // Str::PasswordLabel
    "密码长度", // Str::PasswordLenghtLabel
    "文件", // Str::FileLabel
    "文件", // Str::TheFileLabel
    "路径", // Str::PathLabel
    "输入文件路径", // Str::InputFilePathLabel
    "输出文件路径", // Str::OutputFilePathLabel
    "交换路径", // Str::SwapPathsLabel
    "将被覆盖", // Str::WillBeOverwrittenLabel
    "正在加密...", // Str::EncryptingText
    "正在解密...", // Str::DecryptingText
    "加密", // Str::EncryptText
    "解密", // Str::DecryptText
    "文件加密成功", // Str::FileEncryptedMessage
    "文件解密成功", // Str::FileDecryptedMessage
    "警告！", // Str::WarningTitle
    "您确定吗？", // Str::AreYouSureTitle
    "设置", // Str::SettingsTitle
    "密码生成器", // Str::GeneratePasswordTitle
    "选择语言", // Str::SelectLanguageTitle
    "是", // Str::YesLabel
    "否", // Str::NoLabel
    "确定", // Str::OkLabel
    "输出格式", // Str::OutFormatLabel
    "界面设置", // Str::InterfaceSettingsLabel
    "大小", // Str::InterfaceSizeLabel
    "模式", // Str::ModeLabel
    "普通", // Str::NormalModeLabel
    "纯文本", // Str::PlaintextModeLabel
    "主题", // Str::InterfaceThemeLabel
    "颜色", // Str::InterfaceColorLabel
    "默认（纯文本）", // Str::DefaultLabel
    "OpenSSL（二进制）", // Str::OpenSSLLabel
    "使用此密码", // Str::UsePasswordLabel
    "复制", // Str::CopyLabel
    "Ctrl + 左键单击获取 SHA256", // Str::GetSHA256Text
    // Themes
    "浅色", // Str::LightThemeName
    "深色", // Str::DarkThemeName
    // Colors
    "蓝色", // Str::BlueName
    "青色", // Str::CyanName
    "绿色", // Str::GreenName
    "黄绿色", // Str::LimeName
    "黄色", // Str::YellowName
    "棕色", // Str::BrownName
    "橙色", // Str::OrangeName
    "红色", // Str::RedName
    "粉色", // Str::PinkName
    "紫色", // Str::PurpleName
    "灰色", // Str::GreyName
    "白色", // Str::WhiteName
    "黑色", // Str::BlackName

};
static_assert(sizeof(textosZH_HANS) / sizeof(textosZH_HANS[0]) == N,
    "Faltan o sobran textos en chino simplificado: revisa que coincidan con Str::Count.");

// Français (fr)
constexpr const char* textosFR[] = {

    
    
    // Info
    "Appuyez sur Entrée pour quitter...", // Str::ExitInfoMessage
    "À activer uniquement si le contenu", // Str::PlainTextModeMessage_FirstLine
    "du fichier est du texte brut", // Str::PlainTextModeMessage_SecondLine
    "Le fichier chiffré sera enregistré", // Str::DefaultCipherModeText_FirstLine
    "sous forme de caractères imprimables", // Str::DefaultCipherModeText_SecondLine
    "Le fichier chiffré sera enregistré au", // Str::OpenSSLCipherModeText_FirstLine
    "format binaire, compatible avec OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Itérations PBKDF2 :", // Str::PBKDF2IterationsText
    // Errors
    "Erreur : paramètres incorrects", // Str::WrongParamsText
    "Valeur reçue", // Str::InputValueText
    "Chemin reçu", // Str::InputPathText
    "La valeur reçue n'a pas pu être convertie en un nombre supérieur ou égal à 0", // Str::WrongNumberValueMessage
    "Le chemin reçu ne correspond à aucun fichier existant", // Str::WrongPathValueMessage
    "L'option saisie n'est pas reconnue comme un paramètre valide", // Str::InvalidOptionMessage
    "Option saisie", // Str::EnteredOptionText
    "Exception inconnue", // Str::UnknownExceptionText
    "Échec de l'initialisation de GLFW", // Str::GLFWErrorMessage
    "Échec de l'initialisation de GLAD", // Str::GLADErrorMessage
    "Erreur : impossible d'ouvrir le fichier en lecture", // Str::ReadFileErrorMessage
    "Erreur lors de la lecture du contenu du fichier", // Str::ErrorWhileReadingMessage
    "Erreur : impossible d'ouvrir le fichier en écriture", // Str::WriteFileErrorMessage
    "Erreur : la chaîne hexadécimale doit contenir un nombre pair de caractères", // Str::HexStringErrorMessage
    "Erreur : caractère hexadécimal non valide dans la chaîne", // Str::InvalidHexCharacterErrorMessage
    "Erreur : impossible d'enregistrer le fichier", // Str::SaveFileErrorMessage
    "Erreur : impossible de charger le fichier", // Str::LoadFileErrorMessage
    "Erreur : format de fichier non valide (5 champs attendus : ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Erreur : le nombre d'itérations dépasse le maximum fixé (10 000 000)", // Str::MaxIterationsErrorMessage
    "Erreur : échec de la vérification d'intégrité, mot de passe incorrect ou fichier corrompu/altéré", // Str::IntegrityCheckErrorMessage
    "Erreur : le mot de passe ne peut pas être vide", // Str::EmptyPasswordErrorMessage
    "Erreur : le chemin du fichier de destination est un dossier", // Str::OutputFileIsDirectoryErrorMessage
    "Erreur : le chemin du fichier source est un dossier", // Str::InputFileIsDirectoryErrorMessage
    "Erreur : le chemin du fichier de destination ne peut pas être vide", // Str::EmptyOutputFilePathErrorMessage
    "Erreur : le chemin du fichier source ne peut pas être vide", // Str::EmptyInputFilePathErrorMessage
    "Erreur : le fichier source n'existe pas", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Langue : Français", // Str::LanguageLabel
    "Mot de passe", // Str::PasswordLabel
    "Longueur du mot de passe", // Str::PasswordLenghtLabel
    "Fichier", // Str::FileLabel
    "Le fichier", // Str::TheFileLabel
    "Chemin", // Str::PathLabel
    "Chemin d'entrée", // Str::InputFilePathLabel
    "Chemin de sortie", // Str::OutputFilePathLabel
    "Inverser les chemins", // Str::SwapPathsLabel
    "sera écrasé", // Str::WillBeOverwrittenLabel
    "Chiffrement...", // Str::EncryptingText
    "Déchiffrement...", // Str::DecryptingText
    "Chiffrer", // Str::EncryptText
    "Déchiffrer", // Str::DecryptText
    "Fichier chiffré avec succès", // Str::FileEncryptedMessage
    "Fichier déchiffré avec succès", // Str::FileDecryptedMessage
    "Attention !", // Str::WarningTitle
    "Êtes-vous sûr ?", // Str::AreYouSureTitle
    "Paramètres", // Str::SettingsTitle
    "Générateur de mots de passe", // Str::GeneratePasswordTitle
    "Choisir la langue", // Str::SelectLanguageTitle
    "Oui", // Str::YesLabel
    "Non", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format de sortie", // Str::OutFormatLabel
    "Paramètres de l'interface", // Str::InterfaceSettingsLabel
    "Taille", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Texte brut", // Str::PlaintextModeLabel
    "Thème", // Str::InterfaceThemeLabel
    "Couleur", // Str::InterfaceColorLabel
    "Par défaut (texte brut)", // Str::DefaultLabel
    "OpenSSL (binaire)", // Str::OpenSSLLabel
    "Utiliser ce mot de passe", // Str::UsePasswordLabel
    "Copier", // Str::CopyLabel
    "Ctrl + clic gauche pour obtenir le SHA256", // Str::GetSHA256Text
    // Themes
    "Clair", // Str::LightThemeName
    "Sombre", // Str::DarkThemeName
    // Colors
    "Bleu", // Str::BlueName
    "Cyan", // Str::CyanName
    "Vert", // Str::GreenName
    "Vert citron", // Str::LimeName
    "Jaune", // Str::YellowName
    "Marron", // Str::BrownName
    "Orange", // Str::OrangeName
    "Rouge", // Str::RedName
    "Rose", // Str::PinkName
    "Violet", // Str::PurpleName
    "Gris", // Str::GreyName
    "Blanc", // Str::WhiteName
    "Noir", // Str::BlackName

};
static_assert(sizeof(textosFR) / sizeof(textosFR[0]) == N,
    "Faltan o sobran textos en frances: revisa que coincidan con Str::Count.");

// Português (pt)
constexpr const char* textosPT[] = {

    
    
    // Info
    "Pressione Enter para sair...", // Str::ExitInfoMessage
    "Ative somente se o conteúdo", // Str::PlainTextModeMessage_FirstLine
    "do arquivo for texto simples", // Str::PlainTextModeMessage_SecondLine
    "O arquivo criptografado será salvo", // Str::DefaultCipherModeText_FirstLine
    "como caracteres imprimíveis", // Str::DefaultCipherModeText_SecondLine
    "O arquivo criptografado será salvo em", // Str::OpenSSLCipherModeText_FirstLine
    "formato binário, compatível com OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterações PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Erro: parâmetros incorretos", // Str::WrongParamsText
    "Valor recebido", // Str::InputValueText
    "Caminho recebido", // Str::InputPathText
    "Não foi possível converter o valor recebido em um número maior ou igual a 0", // Str::WrongNumberValueMessage
    "O caminho recebido não corresponde a nenhum arquivo existente", // Str::WrongPathValueMessage
    "A opção informada não é reconhecida como um parâmetro válido", // Str::InvalidOptionMessage
    "Opção informada", // Str::EnteredOptionText
    "Exceção desconhecida", // Str::UnknownExceptionText
    "Falha ao inicializar o GLFW", // Str::GLFWErrorMessage
    "Falha ao inicializar o GLAD", // Str::GLADErrorMessage
    "Erro: não foi possível abrir o arquivo para leitura", // Str::ReadFileErrorMessage
    "Erro ao ler o conteúdo do arquivo", // Str::ErrorWhileReadingMessage
    "Erro: não foi possível abrir o arquivo para gravação", // Str::WriteFileErrorMessage
    "Erro: a string hexadecimal deve ter um número par de caracteres", // Str::HexStringErrorMessage
    "Erro: caractere hexadecimal inválido na string", // Str::InvalidHexCharacterErrorMessage
    "Erro: não foi possível salvar o arquivo", // Str::SaveFileErrorMessage
    "Erro: não foi possível carregar o arquivo", // Str::LoadFileErrorMessage
    "Erro: formato de arquivo inválido (esperados 5 campos: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Erro: o número de iterações excede o máximo estabelecido (10.000.000)", // Str::MaxIterationsErrorMessage
    "Erro: falha na verificação de integridade, senha incorreta ou arquivo corrompido/adulterado", // Str::IntegrityCheckErrorMessage
    "Erro: a senha não pode estar vazia", // Str::EmptyPasswordErrorMessage
    "Erro: o caminho do arquivo de destino é um diretório", // Str::OutputFileIsDirectoryErrorMessage
    "Erro: o caminho do arquivo de origem é um diretório", // Str::InputFileIsDirectoryErrorMessage
    "Erro: o caminho do arquivo de destino não pode estar vazio", // Str::EmptyOutputFilePathErrorMessage
    "Erro: o caminho do arquivo de origem não pode estar vazio", // Str::EmptyInputFilePathErrorMessage
    "Erro: o arquivo de origem não existe", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Idioma: Português", // Str::LanguageLabel
    "Senha", // Str::PasswordLabel
    "Tamanho da senha", // Str::PasswordLenghtLabel
    "Arquivo", // Str::FileLabel
    "O arquivo", // Str::TheFileLabel
    "Caminho", // Str::PathLabel
    "Caminho de entrada", // Str::InputFilePathLabel
    "Caminho de saída", // Str::OutputFilePathLabel
    "Trocar caminhos", // Str::SwapPathsLabel
    "será substituído", // Str::WillBeOverwrittenLabel
    "Criptografando...", // Str::EncryptingText
    "Descriptografando...", // Str::DecryptingText
    "Criptografar", // Str::EncryptText
    "Descriptografar", // Str::DecryptText
    "Arquivo criptografado com sucesso", // Str::FileEncryptedMessage
    "Arquivo descriptografado com sucesso", // Str::FileDecryptedMessage
    "Atenção!", // Str::WarningTitle
    "Tem certeza?", // Str::AreYouSureTitle
    "Configurações", // Str::SettingsTitle
    "Gerador de senhas", // Str::GeneratePasswordTitle
    "Selecionar idioma", // Str::SelectLanguageTitle
    "Sim", // Str::YesLabel
    "Não", // Str::NoLabel
    "OK", // Str::OkLabel
    "Formato de saída", // Str::OutFormatLabel
    "Configurações da interface", // Str::InterfaceSettingsLabel
    "Tamanho", // Str::InterfaceSizeLabel
    "Modo", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Texto simples", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Cor", // Str::InterfaceColorLabel
    "Padrão (texto simples)", // Str::DefaultLabel
    "OpenSSL (binário)", // Str::OpenSSLLabel
    "Usar esta senha", // Str::UsePasswordLabel
    "Copiar", // Str::CopyLabel
    "Ctrl + clique esquerdo para obter o SHA256", // Str::GetSHA256Text
    // Themes
    "Claro", // Str::LightThemeName
    "Escuro", // Str::DarkThemeName
    // Colors
    "Azul", // Str::BlueName
    "Ciano", // Str::CyanName
    "Verde", // Str::GreenName
    "Verde-limão", // Str::LimeName
    "Amarelo", // Str::YellowName
    "Marrom", // Str::BrownName
    "Laranja", // Str::OrangeName
    "Vermelho", // Str::RedName
    "Rosa", // Str::PinkName
    "Roxo", // Str::PurpleName
    "Cinza", // Str::GreyName
    "Branco", // Str::WhiteName
    "Preto", // Str::BlackName

};
static_assert(sizeof(textosPT) / sizeof(textosPT[0]) == N,
    "Faltan o sobran textos en portugues: revisa que coincidan con Str::Count.");

// Русский (ru)
constexpr const char* textosRU[] = {

    
    
    // Info
    "Нажмите Enter для выхода...", // Str::ExitInfoMessage
    "Включайте, только если содержимое", // Str::PlainTextModeMessage_FirstLine
    "файла является простым текстом", // Str::PlainTextModeMessage_SecondLine
    "Зашифрованный файл будет сохранён", // Str::DefaultCipherModeText_FirstLine
    "в виде печатаемых символов", // Str::DefaultCipherModeText_SecondLine
    "Зашифрованный файл будет сохранён", // Str::OpenSSLCipherModeText_FirstLine
    "в двоичном формате, совместимом с OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Итерации PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Ошибка: неверные параметры", // Str::WrongParamsText
    "Полученное значение", // Str::InputValueText
    "Полученный путь", // Str::InputPathText
    "Не удалось преобразовать полученное значение в число, большее или равное 0", // Str::WrongNumberValueMessage
    "Полученный путь не соответствует ни одному существующему файлу", // Str::WrongPathValueMessage
    "Введённый параметр не распознан как допустимый", // Str::InvalidOptionMessage
    "Введённый параметр", // Str::EnteredOptionText
    "Неизвестное исключение", // Str::UnknownExceptionText
    "Не удалось инициализировать GLFW", // Str::GLFWErrorMessage
    "Не удалось инициализировать GLAD", // Str::GLADErrorMessage
    "Ошибка: не удалось открыть файл для чтения", // Str::ReadFileErrorMessage
    "Ошибка при чтении содержимого файла", // Str::ErrorWhileReadingMessage
    "Ошибка: не удалось открыть файл для записи", // Str::WriteFileErrorMessage
    "Ошибка: шестнадцатеричная строка должна содержать чётное число символов", // Str::HexStringErrorMessage
    "Ошибка: недопустимый шестнадцатеричный символ в строке", // Str::InvalidHexCharacterErrorMessage
    "Ошибка: не удалось сохранить файл", // Str::SaveFileErrorMessage
    "Ошибка: не удалось загрузить файл", // Str::LoadFileErrorMessage
    "Ошибка: неверный формат файла (ожидается 5 полей: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Ошибка: количество итераций превышает установленный максимум (10 000 000)", // Str::MaxIterationsErrorMessage
    "Ошибка: проверка целостности не пройдена, неверный пароль или файл повреждён/изменён", // Str::IntegrityCheckErrorMessage
    "Ошибка: пароль не может быть пустым", // Str::EmptyPasswordErrorMessage
    "Ошибка: путь к файлу назначения является каталогом", // Str::OutputFileIsDirectoryErrorMessage
    "Ошибка: путь к исходному файлу является каталогом", // Str::InputFileIsDirectoryErrorMessage
    "Ошибка: путь к файлу назначения не может быть пустым", // Str::EmptyOutputFilePathErrorMessage
    "Ошибка: путь к исходному файлу не может быть пустым", // Str::EmptyInputFilePathErrorMessage
    "Ошибка: исходный файл не существует", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Язык: Русский", // Str::LanguageLabel
    "Пароль", // Str::PasswordLabel
    "Длина пароля", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файл", // Str::TheFileLabel
    "Путь", // Str::PathLabel
    "Путь к входному файлу", // Str::InputFilePathLabel
    "Путь к выходному файлу", // Str::OutputFilePathLabel
    "Поменять пути местами", // Str::SwapPathsLabel
    "будет перезаписан", // Str::WillBeOverwrittenLabel
    "Шифрование...", // Str::EncryptingText
    "Расшифровка...", // Str::DecryptingText
    "Зашифровать", // Str::EncryptText
    "Расшифровать", // Str::DecryptText
    "Файл успешно зашифрован", // Str::FileEncryptedMessage
    "Файл успешно расшифрован", // Str::FileDecryptedMessage
    "Внимание!", // Str::WarningTitle
    "Вы уверены?", // Str::AreYouSureTitle
    "Настройки", // Str::SettingsTitle
    "Генератор паролей", // Str::GeneratePasswordTitle
    "Выбор языка", // Str::SelectLanguageTitle
    "Да", // Str::YesLabel
    "Нет", // Str::NoLabel
    "ОК", // Str::OkLabel
    "Формат вывода", // Str::OutFormatLabel
    "Настройки интерфейса", // Str::InterfaceSettingsLabel
    "Размер", // Str::InterfaceSizeLabel
    "Режим", // Str::ModeLabel
    "Обычный", // Str::NormalModeLabel
    "Простой текст", // Str::PlaintextModeLabel
    "Тема", // Str::InterfaceThemeLabel
    "Цвет", // Str::InterfaceColorLabel
    "По умолчанию (простой текст)", // Str::DefaultLabel
    "OpenSSL (двоичный)", // Str::OpenSSLLabel
    "Использовать этот пароль", // Str::UsePasswordLabel
    "Копировать", // Str::CopyLabel
    "Ctrl + левый щелчок, чтобы получить SHA256", // Str::GetSHA256Text
    // Themes
    "Светлая", // Str::LightThemeName
    "Тёмная", // Str::DarkThemeName
    // Colors
    "Синий", // Str::BlueName
    "Голубой", // Str::CyanName
    "Зелёный", // Str::GreenName
    "Лаймовый", // Str::LimeName
    "Жёлтый", // Str::YellowName
    "Коричневый", // Str::BrownName
    "Оранжевый", // Str::OrangeName
    "Красный", // Str::RedName
    "Розовый", // Str::PinkName
    "Фиолетовый", // Str::PurpleName
    "Серый", // Str::GreyName
    "Белый", // Str::WhiteName
    "Чёрный", // Str::BlackName

};
static_assert(sizeof(textosRU) / sizeof(textosRU[0]) == N,
    "Faltan o sobran textos en ruso: revisa que coincidan con Str::Count.");

// Bahasa Indonesia (id)
constexpr const char* textosID[] = {

    
    
    // Info
    "Tekan Enter untuk keluar...", // Str::ExitInfoMessage
    "Aktifkan hanya jika isi", // Str::PlainTextModeMessage_FirstLine
    "berkas berupa teks biasa", // Str::PlainTextModeMessage_SecondLine
    "Berkas terenkripsi akan disimpan", // Str::DefaultCipherModeText_FirstLine
    "sebagai karakter yang dapat dicetak", // Str::DefaultCipherModeText_SecondLine
    "Berkas terenkripsi akan disimpan dalam", // Str::OpenSSLCipherModeText_FirstLine
    "format biner, kompatibel dengan OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterasi PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Kesalahan: parameter salah", // Str::WrongParamsText
    "Nilai masukan", // Str::InputValueText
    "Jalur masukan", // Str::InputPathText
    "Nilai masukan tidak dapat dikonversi menjadi angka yang lebih besar dari atau sama dengan 0", // Str::WrongNumberValueMessage
    "Jalur masukan tidak sesuai dengan berkas mana pun yang ada", // Str::WrongPathValueMessage
    "Opsi yang dimasukkan tidak dikenali sebagai parameter yang valid", // Str::InvalidOptionMessage
    "Opsi yang dimasukkan", // Str::EnteredOptionText
    "Pengecualian tidak dikenal", // Str::UnknownExceptionText
    "Gagal menginisialisasi GLFW", // Str::GLFWErrorMessage
    "Gagal menginisialisasi GLAD", // Str::GLADErrorMessage
    "Kesalahan: Tidak dapat membuka berkas untuk dibaca", // Str::ReadFileErrorMessage
    "Kesalahan saat membaca isi berkas", // Str::ErrorWhileReadingMessage
    "Kesalahan: Tidak dapat membuka berkas untuk ditulis", // Str::WriteFileErrorMessage
    "Kesalahan: String heksadesimal harus memiliki jumlah karakter genap", // Str::HexStringErrorMessage
    "Kesalahan: Karakter heksadesimal tidak valid dalam string", // Str::InvalidHexCharacterErrorMessage
    "Kesalahan: Tidak dapat menyimpan berkas", // Str::SaveFileErrorMessage
    "Kesalahan: Tidak dapat memuat berkas", // Str::LoadFileErrorMessage
    "Kesalahan: Format berkas tidak valid (diharapkan 5 bidang: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Kesalahan: Jumlah iterasi melebihi batas maksimum yang ditetapkan (10.000.000)", // Str::MaxIterationsErrorMessage
    "Kesalahan: Verifikasi integritas gagal, kata sandi salah atau berkas rusak/dimanipulasi", // Str::IntegrityCheckErrorMessage
    "Kesalahan: Kata sandi tidak boleh kosong", // Str::EmptyPasswordErrorMessage
    "Kesalahan: Jalur berkas tujuan adalah direktori", // Str::OutputFileIsDirectoryErrorMessage
    "Kesalahan: Jalur berkas sumber adalah direktori", // Str::InputFileIsDirectoryErrorMessage
    "Kesalahan: Jalur berkas tujuan tidak boleh kosong", // Str::EmptyOutputFilePathErrorMessage
    "Kesalahan: Jalur berkas sumber tidak boleh kosong", // Str::EmptyInputFilePathErrorMessage
    "Kesalahan: Berkas sumber tidak ada", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Bahasa: Bahasa Indonesia", // Str::LanguageLabel
    "Kata sandi", // Str::PasswordLabel
    "Panjang kata sandi", // Str::PasswordLenghtLabel
    "Berkas", // Str::FileLabel
    "Berkas", // Str::TheFileLabel
    "Jalur", // Str::PathLabel
    "Jalur berkas masukan", // Str::InputFilePathLabel
    "Jalur berkas keluaran", // Str::OutputFilePathLabel
    "Tukar jalur", // Str::SwapPathsLabel
    "akan ditimpa", // Str::WillBeOverwrittenLabel
    "Mengenkripsi...", // Str::EncryptingText
    "Mendekripsi...", // Str::DecryptingText
    "Enkripsi", // Str::EncryptText
    "Dekripsi", // Str::DecryptText
    "Berkas berhasil dienkripsi", // Str::FileEncryptedMessage
    "Berkas berhasil didekripsi", // Str::FileDecryptedMessage
    "Peringatan!", // Str::WarningTitle
    "Apakah Anda yakin?", // Str::AreYouSureTitle
    "Pengaturan", // Str::SettingsTitle
    "Pembuat kata sandi", // Str::GeneratePasswordTitle
    "Pilih bahasa", // Str::SelectLanguageTitle
    "Ya", // Str::YesLabel
    "Tidak", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format keluaran", // Str::OutFormatLabel
    "Pengaturan antarmuka", // Str::InterfaceSettingsLabel
    "Ukuran", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Teks biasa", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Warna", // Str::InterfaceColorLabel
    "Bawaan (teks biasa)", // Str::DefaultLabel
    "OpenSSL (biner)", // Str::OpenSSLLabel
    "Gunakan kata sandi ini", // Str::UsePasswordLabel
    "Salin", // Str::CopyLabel
    "Ctrl + klik kiri untuk mendapatkan SHA256", // Str::GetSHA256Text
    // Themes
    "Terang", // Str::LightThemeName
    "Gelap", // Str::DarkThemeName
    // Colors
    "Biru", // Str::BlueName
    "Sian", // Str::CyanName
    "Hijau", // Str::GreenName
    "Hijau limau", // Str::LimeName
    "Kuning", // Str::YellowName
    "Cokelat", // Str::BrownName
    "Oranye", // Str::OrangeName
    "Merah", // Str::RedName
    "Merah muda", // Str::PinkName
    "Ungu", // Str::PurpleName
    "Abu-abu", // Str::GreyName
    "Putih", // Str::WhiteName
    "Hitam", // Str::BlackName

};
static_assert(sizeof(textosID) / sizeof(textosID[0]) == N,
    "Faltan o sobran textos en indonesio: revisa que coincidan con Str::Count.");

// Deutsch (de)
constexpr const char* textosDE[] = {

    
    
    // Info
    "Drücken Sie Enter zum Beenden...", // Str::ExitInfoMessage
    "Nur aktivieren, wenn der Dateiinhalt", // Str::PlainTextModeMessage_FirstLine
    "Klartext ist", // Str::PlainTextModeMessage_SecondLine
    "Die verschlüsselte Datei wird als", // Str::DefaultCipherModeText_FirstLine
    "druckbare Zeichen gespeichert", // Str::DefaultCipherModeText_SecondLine
    "Die verschlüsselte Datei wird im", // Str::OpenSSLCipherModeText_FirstLine
    "Binärformat gespeichert, OpenSSL-kompatibel", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-Iterationen:", // Str::PBKDF2IterationsText
    // Errors
    "Fehler: ungültige Parameter", // Str::WrongParamsText
    "Eingabewert", // Str::InputValueText
    "Eingabepfad", // Str::InputPathText
    "Der Eingabewert konnte nicht in eine Zahl größer oder gleich 0 umgewandelt werden", // Str::WrongNumberValueMessage
    "Der Eingabepfad entspricht keiner vorhandenen Datei", // Str::WrongPathValueMessage
    "Die eingegebene Option wird nicht als gültiger Parameter erkannt", // Str::InvalidOptionMessage
    "Eingegebene Option", // Str::EnteredOptionText
    "Unbekannte Ausnahme", // Str::UnknownExceptionText
    "GLFW konnte nicht initialisiert werden", // Str::GLFWErrorMessage
    "GLAD konnte nicht initialisiert werden", // Str::GLADErrorMessage
    "Fehler: Die Datei konnte nicht zum Lesen geöffnet werden", // Str::ReadFileErrorMessage
    "Fehler beim Lesen des Dateiinhalts", // Str::ErrorWhileReadingMessage
    "Fehler: Die Datei konnte nicht zum Schreiben geöffnet werden", // Str::WriteFileErrorMessage
    "Fehler: Die Hex-Zeichenfolge muss eine gerade Anzahl von Zeichen haben", // Str::HexStringErrorMessage
    "Fehler: Ungültiges Hex-Zeichen in der Zeichenfolge", // Str::InvalidHexCharacterErrorMessage
    "Fehler: Die Datei konnte nicht gespeichert werden", // Str::SaveFileErrorMessage
    "Fehler: Die Datei konnte nicht geladen werden", // Str::LoadFileErrorMessage
    "Fehler: Ungültiges Dateiformat (5 Felder erwartet: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Fehler: Die Anzahl der Iterationen überschreitet das festgelegte Maximum (10.000.000)", // Str::MaxIterationsErrorMessage
    "Fehler: Integritätsprüfung fehlgeschlagen, falsches Passwort oder beschädigte/manipulierte Datei", // Str::IntegrityCheckErrorMessage
    "Fehler: Das Passwort darf nicht leer sein", // Str::EmptyPasswordErrorMessage
    "Fehler: Der Pfad der Zieldatei ist ein Verzeichnis", // Str::OutputFileIsDirectoryErrorMessage
    "Fehler: Der Pfad der Quelldatei ist ein Verzeichnis", // Str::InputFileIsDirectoryErrorMessage
    "Fehler: Der Pfad der Zieldatei darf nicht leer sein", // Str::EmptyOutputFilePathErrorMessage
    "Fehler: Der Pfad der Quelldatei darf nicht leer sein", // Str::EmptyInputFilePathErrorMessage
    "Fehler: Die Quelldatei existiert nicht", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Sprache: Deutsch", // Str::LanguageLabel
    "Passwort", // Str::PasswordLabel
    "Passwortlänge", // Str::PasswordLenghtLabel
    "Datei", // Str::FileLabel
    "Die Datei", // Str::TheFileLabel
    "Pfad", // Str::PathLabel
    "Eingabepfad", // Str::InputFilePathLabel
    "Ausgabepfad", // Str::OutputFilePathLabel
    "Pfade tauschen", // Str::SwapPathsLabel
    "wird überschrieben", // Str::WillBeOverwrittenLabel
    "Wird verschlüsselt...", // Str::EncryptingText
    "Wird entschlüsselt...", // Str::DecryptingText
    "Verschlüsseln", // Str::EncryptText
    "Entschlüsseln", // Str::DecryptText
    "Datei erfolgreich verschlüsselt", // Str::FileEncryptedMessage
    "Datei erfolgreich entschlüsselt", // Str::FileDecryptedMessage
    "Warnung!", // Str::WarningTitle
    "Sind Sie sicher?", // Str::AreYouSureTitle
    "Einstellungen", // Str::SettingsTitle
    "Passwortgenerator", // Str::GeneratePasswordTitle
    "Sprache auswählen", // Str::SelectLanguageTitle
    "Ja", // Str::YesLabel
    "Nein", // Str::NoLabel
    "OK", // Str::OkLabel
    "Ausgabeformat", // Str::OutFormatLabel
    "Oberflächeneinstellungen", // Str::InterfaceSettingsLabel
    "Größe", // Str::InterfaceSizeLabel
    "Modus", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Klartext", // Str::PlaintextModeLabel
    "Design", // Str::InterfaceThemeLabel
    "Farbe", // Str::InterfaceColorLabel
    "Standard (Klartext)", // Str::DefaultLabel
    "OpenSSL (binär)", // Str::OpenSSLLabel
    "Dieses Passwort verwenden", // Str::UsePasswordLabel
    "Kopieren", // Str::CopyLabel
    "Strg + Linksklick, um SHA256 zu erhalten", // Str::GetSHA256Text
    // Themes
    "Hell", // Str::LightThemeName
    "Dunkel", // Str::DarkThemeName
    // Colors
    "Blau", // Str::BlueName
    "Cyan", // Str::CyanName
    "Grün", // Str::GreenName
    "Limettengrün", // Str::LimeName
    "Gelb", // Str::YellowName
    "Braun", // Str::BrownName
    "Orange", // Str::OrangeName
    "Rot", // Str::RedName
    "Rosa", // Str::PinkName
    "Lila", // Str::PurpleName
    "Grau", // Str::GreyName
    "Weiß", // Str::WhiteName
    "Schwarz", // Str::BlackName

};
static_assert(sizeof(textosDE) / sizeof(textosDE[0]) == N,
    "Faltan o sobran textos en aleman: revisa que coincidan con Str::Count.");

// 日本語 (ja)
constexpr const char* textosJA[] = {

    
    
    // Info
    "Enter キーを押すと終了します...", // Str::ExitInfoMessage
    "ファイルの内容がプレーンテキストの", // Str::PlainTextModeMessage_FirstLine
    "場合のみ有効にしてください", // Str::PlainTextModeMessage_SecondLine
    "暗号化されたファイルは", // Str::DefaultCipherModeText_FirstLine
    "印刷可能な文字として保存されます", // Str::DefaultCipherModeText_SecondLine
    "暗号化されたファイルはバイナリ形式で", // Str::OpenSSLCipherModeText_FirstLine
    "保存されます（OpenSSL 互換）", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 反復回数：", // Str::PBKDF2IterationsText
    // Errors
    "エラー：パラメーターが正しくありません", // Str::WrongParamsText
    "入力値", // Str::InputValueText
    "入力パス", // Str::InputPathText
    "入力値を 0 以上の数値に変換できませんでした", // Str::WrongNumberValueMessage
    "入力パスに該当する既存のファイルがありません", // Str::WrongPathValueMessage
    "入力されたオプションは有効なパラメーターとして認識されません", // Str::InvalidOptionMessage
    "入力されたオプション", // Str::EnteredOptionText
    "不明な例外", // Str::UnknownExceptionText
    "GLFW の初期化に失敗しました", // Str::GLFWErrorMessage
    "GLAD の初期化に失敗しました", // Str::GLADErrorMessage
    "エラー：ファイルを読み取り用に開けませんでした", // Str::ReadFileErrorMessage
    "ファイルの内容の読み取り中にエラーが発生しました", // Str::ErrorWhileReadingMessage
    "エラー：ファイルを書き込み用に開けませんでした", // Str::WriteFileErrorMessage
    "エラー：16 進文字列の文字数は偶数である必要があります", // Str::HexStringErrorMessage
    "エラー：文字列に無効な 16 進文字が含まれています", // Str::InvalidHexCharacterErrorMessage
    "エラー：ファイルを保存できませんでした", // Str::SaveFileErrorMessage
    "エラー：ファイルを読み込めませんでした", // Str::LoadFileErrorMessage
    "エラー：無効なファイル形式です（5 つのフィールドが必要：ciphertext|iv|salt|iterations|mac）", // Str::InvalidFileFormatErrorMessage
    "エラー：反復回数が設定された上限（10,000,000）を超えています", // Str::MaxIterationsErrorMessage
    "エラー：整合性の検証に失敗しました（パスワードが正しくないか、ファイルが破損または改ざんされています）", // Str::IntegrityCheckErrorMessage
    "エラー：パスワードを空にすることはできません", // Str::EmptyPasswordErrorMessage
    "エラー：出力先ファイルのパスがディレクトリです", // Str::OutputFileIsDirectoryErrorMessage
    "エラー：元ファイルのパスがディレクトリです", // Str::InputFileIsDirectoryErrorMessage
    "エラー：出力先ファイルのパスを空にすることはできません", // Str::EmptyOutputFilePathErrorMessage
    "エラー：元ファイルのパスを空にすることはできません", // Str::EmptyInputFilePathErrorMessage
    "エラー：元ファイルが存在しません", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "言語：日本語", // Str::LanguageLabel
    "パスワード", // Str::PasswordLabel
    "パスワードの長さ", // Str::PasswordLenghtLabel
    "ファイル", // Str::FileLabel
    "ファイル", // Str::TheFileLabel
    "パス", // Str::PathLabel
    "入力ファイルのパス", // Str::InputFilePathLabel
    "出力ファイルのパス", // Str::OutputFilePathLabel
    "パスを入れ替える", // Str::SwapPathsLabel
    "は上書きされます", // Str::WillBeOverwrittenLabel
    "暗号化しています...", // Str::EncryptingText
    "復号しています...", // Str::DecryptingText
    "暗号化", // Str::EncryptText
    "復号", // Str::DecryptText
    "ファイルの暗号化に成功しました", // Str::FileEncryptedMessage
    "ファイルの復号に成功しました", // Str::FileDecryptedMessage
    "警告！", // Str::WarningTitle
    "よろしいですか？", // Str::AreYouSureTitle
    "設定", // Str::SettingsTitle
    "パスワード生成", // Str::GeneratePasswordTitle
    "言語を選択", // Str::SelectLanguageTitle
    "はい", // Str::YesLabel
    "いいえ", // Str::NoLabel
    "OK", // Str::OkLabel
    "出力形式", // Str::OutFormatLabel
    "インターフェース設定", // Str::InterfaceSettingsLabel
    "サイズ", // Str::InterfaceSizeLabel
    "モード", // Str::ModeLabel
    "通常", // Str::NormalModeLabel
    "プレーンテキスト", // Str::PlaintextModeLabel
    "テーマ", // Str::InterfaceThemeLabel
    "カラー", // Str::InterfaceColorLabel
    "デフォルト（プレーンテキスト）", // Str::DefaultLabel
    "OpenSSL（バイナリ）", // Str::OpenSSLLabel
    "このパスワードを使用", // Str::UsePasswordLabel
    "コピー", // Str::CopyLabel
    "Ctrl + 左クリックで SHA256 を取得", // Str::GetSHA256Text
    // Themes
    "ライト", // Str::LightThemeName
    "ダーク", // Str::DarkThemeName
    // Colors
    "青", // Str::BlueName
    "シアン", // Str::CyanName
    "緑", // Str::GreenName
    "ライム", // Str::LimeName
    "黄色", // Str::YellowName
    "茶色", // Str::BrownName
    "オレンジ", // Str::OrangeName
    "赤", // Str::RedName
    "ピンク", // Str::PinkName
    "紫", // Str::PurpleName
    "グレー", // Str::GreyName
    "白", // Str::WhiteName
    "黒", // Str::BlackName

};
static_assert(sizeof(textosJA) / sizeof(textosJA[0]) == N,
    "Faltan o sobran textos en japones: revisa que coincidan con Str::Count.");

// Türkçe (tr)
constexpr const char* textosTR[] = {

    
    
    // Info
    "Çıkmak için Enter tuşuna basın...", // Str::ExitInfoMessage
    "Yalnızca dosya içeriği", // Str::PlainTextModeMessage_FirstLine
    "düz metinse etkinleştirin", // Str::PlainTextModeMessage_SecondLine
    "Şifrelenmiş dosya yazdırılabilir", // Str::DefaultCipherModeText_FirstLine
    "karakterler olarak kaydedilecek", // Str::DefaultCipherModeText_SecondLine
    "Şifrelenmiş dosya OpenSSL ile uyumlu", // Str::OpenSSLCipherModeText_FirstLine
    "ikili biçimde kaydedilecek", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 yinelemeleri:", // Str::PBKDF2IterationsText
    // Errors
    "Hata: geçersiz parametreler", // Str::WrongParamsText
    "Girilen değer", // Str::InputValueText
    "Girilen yol", // Str::InputPathText
    "Girilen değer 0'a eşit veya 0'dan büyük bir sayıya dönüştürülemedi", // Str::WrongNumberValueMessage
    "Girilen yol mevcut hiçbir dosyaya karşılık gelmiyor", // Str::WrongPathValueMessage
    "Girilen seçenek geçerli bir parametre olarak tanınmıyor", // Str::InvalidOptionMessage
    "Girilen seçenek", // Str::EnteredOptionText
    "Bilinmeyen istisna", // Str::UnknownExceptionText
    "GLFW başlatılamadı", // Str::GLFWErrorMessage
    "GLAD başlatılamadı", // Str::GLADErrorMessage
    "Hata: Dosya okumak için açılamadı", // Str::ReadFileErrorMessage
    "Dosya içeriği okunurken hata oluştu", // Str::ErrorWhileReadingMessage
    "Hata: Dosya yazmak için açılamadı", // Str::WriteFileErrorMessage
    "Hata: Onaltılık dize çift sayıda karakter içermelidir", // Str::HexStringErrorMessage
    "Hata: Dizede geçersiz onaltılık karakter var", // Str::InvalidHexCharacterErrorMessage
    "Hata: Dosya kaydedilemedi", // Str::SaveFileErrorMessage
    "Hata: Dosya yüklenemedi", // Str::LoadFileErrorMessage
    "Hata: Geçersiz dosya biçimi (5 alan bekleniyordu: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Hata: Yineleme sayısı belirlenen üst sınırı aşıyor (10.000.000)", // Str::MaxIterationsErrorMessage
    "Hata: Bütünlük doğrulaması başarısız, yanlış parola veya bozuk/değiştirilmiş dosya", // Str::IntegrityCheckErrorMessage
    "Hata: Parola boş olamaz", // Str::EmptyPasswordErrorMessage
    "Hata: Hedef dosya yolu bir dizindir", // Str::OutputFileIsDirectoryErrorMessage
    "Hata: Kaynak dosya yolu bir dizindir", // Str::InputFileIsDirectoryErrorMessage
    "Hata: Hedef dosya yolu boş olamaz", // Str::EmptyOutputFilePathErrorMessage
    "Hata: Kaynak dosya yolu boş olamaz", // Str::EmptyInputFilePathErrorMessage
    "Hata: Kaynak dosya mevcut değil", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Dil: Türkçe", // Str::LanguageLabel
    "Parola", // Str::PasswordLabel
    "Parola uzunluğu", // Str::PasswordLenghtLabel
    "Dosya", // Str::FileLabel
    "Dosya", // Str::TheFileLabel
    "Yol", // Str::PathLabel
    "Giriş dosyası yolu", // Str::InputFilePathLabel
    "Çıkış dosyası yolu", // Str::OutputFilePathLabel
    "Yolların yerini değiştir", // Str::SwapPathsLabel
    "üzerine yazılacak", // Str::WillBeOverwrittenLabel
    "Şifreleniyor...", // Str::EncryptingText
    "Şifre çözülüyor...", // Str::DecryptingText
    "Şifrele", // Str::EncryptText
    "Şifreyi çöz", // Str::DecryptText
    "Dosya başarıyla şifrelendi", // Str::FileEncryptedMessage
    "Dosyanın şifresi başarıyla çözüldü", // Str::FileDecryptedMessage
    "Uyarı!", // Str::WarningTitle
    "Emin misiniz?", // Str::AreYouSureTitle
    "Ayarlar", // Str::SettingsTitle
    "Parola oluşturucu", // Str::GeneratePasswordTitle
    "Dil seçin", // Str::SelectLanguageTitle
    "Evet", // Str::YesLabel
    "Hayır", // Str::NoLabel
    "Tamam", // Str::OkLabel
    "Çıktı biçimi", // Str::OutFormatLabel
    "Arayüz ayarları", // Str::InterfaceSettingsLabel
    "Boyut", // Str::InterfaceSizeLabel
    "Mod", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Düz metin", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Renk", // Str::InterfaceColorLabel
    "Varsayılan (düz metin)", // Str::DefaultLabel
    "OpenSSL (ikili)", // Str::OpenSSLLabel
    "Bu parolayı kullan", // Str::UsePasswordLabel
    "Kopyala", // Str::CopyLabel
    "SHA256 almak için Ctrl + sol tıklayın", // Str::GetSHA256Text
    // Themes
    "Açık", // Str::LightThemeName
    "Koyu", // Str::DarkThemeName
    // Colors
    "Mavi", // Str::BlueName
    "Camgöbeği", // Str::CyanName
    "Yeşil", // Str::GreenName
    "Limon yeşili", // Str::LimeName
    "Sarı", // Str::YellowName
    "Kahverengi", // Str::BrownName
    "Turuncu", // Str::OrangeName
    "Kırmızı", // Str::RedName
    "Pembe", // Str::PinkName
    "Mor", // Str::PurpleName
    "Gri", // Str::GreyName
    "Beyaz", // Str::WhiteName
    "Siyah", // Str::BlackName

};
static_assert(sizeof(textosTR) / sizeof(textosTR[0]) == N,
    "Faltan o sobran textos en turco: revisa que coincidan con Str::Count.");

// Tiếng Việt (vi)
constexpr const char* textosVI[] = {

    
    
    // Info
    "Nhấn Enter để thoát...", // Str::ExitInfoMessage
    "Chỉ bật nếu nội dung tệp", // Str::PlainTextModeMessage_FirstLine
    "là văn bản thuần", // Str::PlainTextModeMessage_SecondLine
    "Tệp đã mã hóa sẽ được lưu", // Str::DefaultCipherModeText_FirstLine
    "dưới dạng ký tự in được", // Str::DefaultCipherModeText_SecondLine
    "Tệp đã mã hóa sẽ được lưu ở định dạng", // Str::OpenSSLCipherModeText_FirstLine
    "nhị phân, tương thích với OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Số vòng lặp PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Lỗi: tham số không đúng", // Str::WrongParamsText
    "Giá trị đầu vào", // Str::InputValueText
    "Đường dẫn đầu vào", // Str::InputPathText
    "Không thể chuyển giá trị đầu vào thành số lớn hơn hoặc bằng 0", // Str::WrongNumberValueMessage
    "Đường dẫn đầu vào không tương ứng với tệp nào hiện có", // Str::WrongPathValueMessage
    "Tùy chọn đã nhập không được nhận dạng là tham số hợp lệ", // Str::InvalidOptionMessage
    "Tùy chọn đã nhập", // Str::EnteredOptionText
    "Ngoại lệ không xác định", // Str::UnknownExceptionText
    "Không thể khởi tạo GLFW", // Str::GLFWErrorMessage
    "Không thể khởi tạo GLAD", // Str::GLADErrorMessage
    "Lỗi: Không thể mở tệp để đọc", // Str::ReadFileErrorMessage
    "Lỗi khi đọc nội dung tệp", // Str::ErrorWhileReadingMessage
    "Lỗi: Không thể mở tệp để ghi", // Str::WriteFileErrorMessage
    "Lỗi: Chuỗi thập lục phân phải có số ký tự chẵn", // Str::HexStringErrorMessage
    "Lỗi: Ký tự thập lục phân không hợp lệ trong chuỗi", // Str::InvalidHexCharacterErrorMessage
    "Lỗi: Không thể lưu tệp", // Str::SaveFileErrorMessage
    "Lỗi: Không thể tải tệp", // Str::LoadFileErrorMessage
    "Lỗi: Định dạng tệp không hợp lệ (cần 5 trường: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Lỗi: Số vòng lặp vượt quá mức tối đa đã đặt (10.000.000)", // Str::MaxIterationsErrorMessage
    "Lỗi: Kiểm tra tính toàn vẹn thất bại, sai mật khẩu hoặc tệp bị hỏng/bị can thiệp", // Str::IntegrityCheckErrorMessage
    "Lỗi: Mật khẩu không được để trống", // Str::EmptyPasswordErrorMessage
    "Lỗi: Đường dẫn tệp đích là một thư mục", // Str::OutputFileIsDirectoryErrorMessage
    "Lỗi: Đường dẫn tệp nguồn là một thư mục", // Str::InputFileIsDirectoryErrorMessage
    "Lỗi: Đường dẫn tệp đích không được để trống", // Str::EmptyOutputFilePathErrorMessage
    "Lỗi: Đường dẫn tệp nguồn không được để trống", // Str::EmptyInputFilePathErrorMessage
    "Lỗi: Tệp nguồn không tồn tại", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Ngôn ngữ: Tiếng Việt", // Str::LanguageLabel
    "Mật khẩu", // Str::PasswordLabel
    "Độ dài mật khẩu", // Str::PasswordLenghtLabel
    "Tệp", // Str::FileLabel
    "Tệp", // Str::TheFileLabel
    "Đường dẫn", // Str::PathLabel
    "Đường dẫn tệp đầu vào", // Str::InputFilePathLabel
    "Đường dẫn tệp đầu ra", // Str::OutputFilePathLabel
    "Hoán đổi đường dẫn", // Str::SwapPathsLabel
    "sẽ bị ghi đè", // Str::WillBeOverwrittenLabel
    "Đang mã hóa...", // Str::EncryptingText
    "Đang giải mã...", // Str::DecryptingText
    "Mã hóa", // Str::EncryptText
    "Giải mã", // Str::DecryptText
    "Đã mã hóa tệp thành công", // Str::FileEncryptedMessage
    "Đã giải mã tệp thành công", // Str::FileDecryptedMessage
    "Cảnh báo!", // Str::WarningTitle
    "Bạn có chắc không?", // Str::AreYouSureTitle
    "Cài đặt", // Str::SettingsTitle
    "Trình tạo mật khẩu", // Str::GeneratePasswordTitle
    "Chọn ngôn ngữ", // Str::SelectLanguageTitle
    "Có", // Str::YesLabel
    "Không", // Str::NoLabel
    "OK", // Str::OkLabel
    "Định dạng đầu ra", // Str::OutFormatLabel
    "Cài đặt giao diện", // Str::InterfaceSettingsLabel
    "Kích thước", // Str::InterfaceSizeLabel
    "Chế độ", // Str::ModeLabel
    "Bình thường", // Str::NormalModeLabel
    "Văn bản thuần", // Str::PlaintextModeLabel
    "Chủ đề", // Str::InterfaceThemeLabel
    "Màu", // Str::InterfaceColorLabel
    "Mặc định (văn bản thuần)", // Str::DefaultLabel
    "OpenSSL (nhị phân)", // Str::OpenSSLLabel
    "Dùng mật khẩu này", // Str::UsePasswordLabel
    "Sao chép", // Str::CopyLabel
    "Ctrl + nhấp chuột trái để lấy SHA256", // Str::GetSHA256Text
    // Themes
    "Sáng", // Str::LightThemeName
    "Tối", // Str::DarkThemeName
    // Colors
    "Xanh dương", // Str::BlueName
    "Xanh lơ", // Str::CyanName
    "Xanh lá", // Str::GreenName
    "Xanh chanh", // Str::LimeName
    "Vàng", // Str::YellowName
    "Nâu", // Str::BrownName
    "Cam", // Str::OrangeName
    "Đỏ", // Str::RedName
    "Hồng", // Str::PinkName
    "Tím", // Str::PurpleName
    "Xám", // Str::GreyName
    "Trắng", // Str::WhiteName
    "Đen", // Str::BlackName

};
static_assert(sizeof(textosVI) / sizeof(textosVI[0]) == N,
    "Faltan o sobran textos en vietnamita: revisa que coincidan con Str::Count.");

// Filipino (fil)
constexpr const char* textosFIL[] = {

    
    
    // Info
    "Pindutin ang Enter para lumabas...", // Str::ExitInfoMessage
    "I-enable lamang kung ang nilalaman", // Str::PlainTextModeMessage_FirstLine
    "ng file ay plain text", // Str::PlainTextModeMessage_SecondLine
    "Ang naka-encrypt na file ay ise-save", // Str::DefaultCipherModeText_FirstLine
    "bilang mga character na nai-print", // Str::DefaultCipherModeText_SecondLine
    "Ang naka-encrypt na file ay ise-save sa", // Str::OpenSSLCipherModeText_FirstLine
    "binary na format, tugma sa OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Mga iteration ng PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Error: maling mga parameter", // Str::WrongParamsText
    "Inilagay na value", // Str::InputValueText
    "Inilagay na path", // Str::InputPathText
    "Hindi ma-convert ang inilagay na value sa numerong mas malaki o katumbas ng 0", // Str::WrongNumberValueMessage
    "Ang inilagay na path ay hindi tumutugma sa anumang umiiral na file", // Str::WrongPathValueMessage
    "Ang inilagay na opsyon ay hindi kinikilala bilang wastong parameter", // Str::InvalidOptionMessage
    "Inilagay na opsyon", // Str::EnteredOptionText
    "Hindi kilalang exception", // Str::UnknownExceptionText
    "Nabigong i-initialize ang GLFW", // Str::GLFWErrorMessage
    "Nabigong i-initialize ang GLAD", // Str::GLADErrorMessage
    "Error: Hindi mabuksan ang file para basahin", // Str::ReadFileErrorMessage
    "Error sa pagbasa ng nilalaman ng file", // Str::ErrorWhileReadingMessage
    "Error: Hindi mabuksan ang file para sulatan", // Str::WriteFileErrorMessage
    "Error: Dapat may even na bilang ng character ang hex string", // Str::HexStringErrorMessage
    "Error: May hindi wastong hex character sa string", // Str::InvalidHexCharacterErrorMessage
    "Error: Hindi ma-save ang file", // Str::SaveFileErrorMessage
    "Error: Hindi ma-load ang file", // Str::LoadFileErrorMessage
    "Error: Hindi wastong format ng file (inaasahan ang 5 field: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Error: Lumampas ang bilang ng iteration sa itinakdang maximum (10,000,000)", // Str::MaxIterationsErrorMessage
    "Error: Nabigo ang pag-verify ng integridad, maling password o sira/binagong file", // Str::IntegrityCheckErrorMessage
    "Error: Hindi puwedeng walang laman ang password", // Str::EmptyPasswordErrorMessage
    "Error: Ang path ng destination file ay isang directory", // Str::OutputFileIsDirectoryErrorMessage
    "Error: Ang path ng source file ay isang directory", // Str::InputFileIsDirectoryErrorMessage
    "Error: Hindi puwedeng walang laman ang path ng destination file", // Str::EmptyOutputFilePathErrorMessage
    "Error: Hindi puwedeng walang laman ang path ng source file", // Str::EmptyInputFilePathErrorMessage
    "Error: Hindi umiiral ang source file", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Wika: Filipino", // Str::LanguageLabel
    "Password", // Str::PasswordLabel
    "Haba ng password", // Str::PasswordLenghtLabel
    "File", // Str::FileLabel
    "Ang file na", // Str::TheFileLabel
    "Path", // Str::PathLabel
    "Path ng input file", // Str::InputFilePathLabel
    "Path ng output file", // Str::OutputFilePathLabel
    "Pagpalitin ang mga path", // Str::SwapPathsLabel
    "ay mao-overwrite", // Str::WillBeOverwrittenLabel
    "Ine-encrypt...", // Str::EncryptingText
    "Dine-decrypt...", // Str::DecryptingText
    "I-encrypt", // Str::EncryptText
    "I-decrypt", // Str::DecryptText
    "Matagumpay na na-encrypt ang file", // Str::FileEncryptedMessage
    "Matagumpay na na-decrypt ang file", // Str::FileDecryptedMessage
    "Babala!", // Str::WarningTitle
    "Sigurado ka ba?", // Str::AreYouSureTitle
    "Mga Setting", // Str::SettingsTitle
    "Generator ng password", // Str::GeneratePasswordTitle
    "Pumili ng wika", // Str::SelectLanguageTitle
    "Oo", // Str::YesLabel
    "Hindi", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format ng output", // Str::OutFormatLabel
    "Mga setting ng interface", // Str::InterfaceSettingsLabel
    "Laki", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Plain text", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Kulay", // Str::InterfaceColorLabel
    "Default (plain text)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Gamitin ang password na ito", // Str::UsePasswordLabel
    "Kopyahin", // Str::CopyLabel
    "Ctrl + left click para makuha ang SHA256", // Str::GetSHA256Text
    // Themes
    "Maliwanag", // Str::LightThemeName
    "Madilim", // Str::DarkThemeName
    // Colors
    "Asul", // Str::BlueName
    "Cyan", // Str::CyanName
    "Berde", // Str::GreenName
    "Lime", // Str::LimeName
    "Dilaw", // Str::YellowName
    "Kayumanggi", // Str::BrownName
    "Kahel", // Str::OrangeName
    "Pula", // Str::RedName
    "Rosas", // Str::PinkName
    "Lila", // Str::PurpleName
    "Abo", // Str::GreyName
    "Puti", // Str::WhiteName
    "Itim", // Str::BlackName

};
static_assert(sizeof(textosFIL) / sizeof(textosFIL[0]) == N,
    "Faltan o sobran textos en filipino: revisa que coincidan con Str::Count.");

// Kiswahili (sw)
constexpr const char* textosSW[] = {

    
    
    // Info
    "Bonyeza Enter ili kutoka...", // Str::ExitInfoMessage
    "Washa tu ikiwa maudhui", // Str::PlainTextModeMessage_FirstLine
    "ya faili ni maandishi wazi", // Str::PlainTextModeMessage_SecondLine
    "Faili iliyosimbwa itahifadhiwa", // Str::DefaultCipherModeText_FirstLine
    "kama herufi zinazoweza kuchapishwa", // Str::DefaultCipherModeText_SecondLine
    "Faili iliyosimbwa itahifadhiwa katika", // Str::OpenSSLCipherModeText_FirstLine
    "muundo wa binari, unaooana na OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Mizunguko ya PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Hitilafu: vigezo si sahihi", // Str::WrongParamsText
    "Thamani iliyopokelewa", // Str::InputValueText
    "Njia iliyopokelewa", // Str::InputPathText
    "Thamani iliyopokelewa haikuweza kubadilishwa kuwa nambari kubwa kuliko au sawa na 0", // Str::WrongNumberValueMessage
    "Njia iliyopokelewa hailingani na faili yoyote iliyopo", // Str::WrongPathValueMessage
    "Chaguo lililowekwa halitambuliki kama kigezo halali", // Str::InvalidOptionMessage
    "Chaguo lililowekwa", // Str::EnteredOptionText
    "Hitilafu isiyojulikana", // Str::UnknownExceptionText
    "Imeshindwa kuanzisha GLFW", // Str::GLFWErrorMessage
    "Imeshindwa kuanzisha GLAD", // Str::GLADErrorMessage
    "Hitilafu: Imeshindwa kufungua faili ili kusoma", // Str::ReadFileErrorMessage
    "Hitilafu wakati wa kusoma maudhui ya faili", // Str::ErrorWhileReadingMessage
    "Hitilafu: Imeshindwa kufungua faili ili kuandika", // Str::WriteFileErrorMessage
    "Hitilafu: Mfuatano wa heksadesimali lazima uwe na idadi shufwa ya herufi", // Str::HexStringErrorMessage
    "Hitilafu: Herufi ya heksadesimali si sahihi katika mfuatano", // Str::InvalidHexCharacterErrorMessage
    "Hitilafu: Imeshindwa kuhifadhi faili", // Str::SaveFileErrorMessage
    "Hitilafu: Imeshindwa kupakia faili", // Str::LoadFileErrorMessage
    "Hitilafu: Muundo wa faili si sahihi (sehemu 5 zinatarajiwa: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Hitilafu: Idadi ya mizunguko inazidi kiwango cha juu kilichowekwa (10,000,000)", // Str::MaxIterationsErrorMessage
    "Hitilafu: Uthibitishaji wa uadilifu umeshindwa, nenosiri si sahihi au faili imeharibika/imebadilishwa", // Str::IntegrityCheckErrorMessage
    "Hitilafu: Nenosiri haliwezi kuwa tupu", // Str::EmptyPasswordErrorMessage
    "Hitilafu: Njia ya faili lengwa ni folda", // Str::OutputFileIsDirectoryErrorMessage
    "Hitilafu: Njia ya faili chanzo ni folda", // Str::InputFileIsDirectoryErrorMessage
    "Hitilafu: Njia ya faili lengwa haiwezi kuwa tupu", // Str::EmptyOutputFilePathErrorMessage
    "Hitilafu: Njia ya faili chanzo haiwezi kuwa tupu", // Str::EmptyInputFilePathErrorMessage
    "Hitilafu: Faili chanzo haipo", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Lugha: Kiswahili", // Str::LanguageLabel
    "Nenosiri", // Str::PasswordLabel
    "Urefu wa nenosiri", // Str::PasswordLenghtLabel
    "Faili", // Str::FileLabel
    "Faili", // Str::TheFileLabel
    "Njia", // Str::PathLabel
    "Njia ya faili ya kuingiza", // Str::InputFilePathLabel
    "Njia ya faili ya kutoa", // Str::OutputFilePathLabel
    "Badilishana njia", // Str::SwapPathsLabel
    "itaandikwa upya", // Str::WillBeOverwrittenLabel
    "Inasimba...", // Str::EncryptingText
    "Inasimbua...", // Str::DecryptingText
    "Simba", // Str::EncryptText
    "Simbua", // Str::DecryptText
    "Faili imesimbwa kwa mafanikio", // Str::FileEncryptedMessage
    "Faili imesimbuliwa kwa mafanikio", // Str::FileDecryptedMessage
    "Onyo!", // Str::WarningTitle
    "Una uhakika?", // Str::AreYouSureTitle
    "Mipangilio", // Str::SettingsTitle
    "Kizalishaji cha nenosiri", // Str::GeneratePasswordTitle
    "Chagua lugha", // Str::SelectLanguageTitle
    "Ndiyo", // Str::YesLabel
    "Hapana", // Str::NoLabel
    "Sawa", // Str::OkLabel
    "Muundo wa matokeo", // Str::OutFormatLabel
    "Mipangilio ya kiolesura", // Str::InterfaceSettingsLabel
    "Ukubwa", // Str::InterfaceSizeLabel
    "Hali", // Str::ModeLabel
    "Kawaida", // Str::NormalModeLabel
    "Maandishi wazi", // Str::PlaintextModeLabel
    "Mandhari", // Str::InterfaceThemeLabel
    "Rangi", // Str::InterfaceColorLabel
    "Chaguo-msingi (maandishi wazi)", // Str::DefaultLabel
    "OpenSSL (binari)", // Str::OpenSSLLabel
    "Tumia nenosiri hili", // Str::UsePasswordLabel
    "Nakili", // Str::CopyLabel
    "Ctrl + bofya kushoto ili kupata SHA256", // Str::GetSHA256Text
    // Themes
    "Angavu", // Str::LightThemeName
    "Giza", // Str::DarkThemeName
    // Colors
    "Bluu", // Str::BlueName
    "Samawati", // Str::CyanName
    "Kijani", // Str::GreenName
    "Kijani kibichi", // Str::LimeName
    "Manjano", // Str::YellowName
    "Kahawia", // Str::BrownName
    "Rangi ya chungwa", // Str::OrangeName
    "Nyekundu", // Str::RedName
    "Waridi", // Str::PinkName
    "Zambarau", // Str::PurpleName
    "Kijivu", // Str::GreyName
    "Nyeupe", // Str::WhiteName
    "Nyeusi", // Str::BlackName

};
static_assert(sizeof(textosSW) / sizeof(textosSW[0]) == N,
    "Faltan o sobran textos en suajili: revisa que coincidan con Str::Count.");

// Hausa (ha)
constexpr const char* textosHA[] = {

    
    
    // Info
    "Danna Enter don fita...", // Str::ExitInfoMessage
    "Kunna kawai idan abin da ke cikin", // Str::PlainTextModeMessage_FirstLine
    "fayil ɗin rubutu ne kawai", // Str::PlainTextModeMessage_SecondLine
    "Za a adana fayil ɗin da aka ɓoye", // Str::DefaultCipherModeText_FirstLine
    "a matsayin haruffan da ake iya bugawa", // Str::DefaultCipherModeText_SecondLine
    "Za a adana fayil ɗin da aka ɓoye a", // Str::OpenSSLCipherModeText_FirstLine
    "tsarin binary, mai dacewa da OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Maimaitawar PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Kuskure: sigogi ba daidai ba ne", // Str::WrongParamsText
    "Ƙimar da aka shigar", // Str::InputValueText
    "Hanyar da aka shigar", // Str::InputPathText
    "Ba a iya mayar da ƙimar da aka shigar zuwa lamba mafi girma ko daidai da 0 ba", // Str::WrongNumberValueMessage
    "Hanyar da aka shigar ba ta dace da kowane fayil da ke akwai ba", // Str::WrongPathValueMessage
    "Ba a gane zaɓin da aka shigar a matsayin siga mai inganci ba", // Str::InvalidOptionMessage
    "Zaɓin da aka shigar", // Str::EnteredOptionText
    "Kuskuren da ba a sani ba", // Str::UnknownExceptionText
    "An kasa fara GLFW", // Str::GLFWErrorMessage
    "An kasa fara GLAD", // Str::GLADErrorMessage
    "Kuskure: An kasa buɗe fayil ɗin don karantawa", // Str::ReadFileErrorMessage
    "Kuskure yayin karanta abin da ke cikin fayil ɗin", // Str::ErrorWhileReadingMessage
    "Kuskure: An kasa buɗe fayil ɗin don rubutawa", // Str::WriteFileErrorMessage
    "Kuskure: Dole ne jerin hexadecimal ya ƙunshi adadin haruffa mai rabuwa da biyu", // Str::HexStringErrorMessage
    "Kuskure: Akwai harafin hexadecimal mara inganci a cikin jerin", // Str::InvalidHexCharacterErrorMessage
    "Kuskure: An kasa adana fayil ɗin", // Str::SaveFileErrorMessage
    "Kuskure: An kasa loda fayil ɗin", // Str::LoadFileErrorMessage
    "Kuskure: Tsarin fayil mara inganci (ana sa ran filaye 5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Kuskure: Adadin maimaitawa ya wuce iyakar da aka ƙayyade (10,000,000)", // Str::MaxIterationsErrorMessage
    "Kuskure: Tabbatar da ingancin fayil ya gaza, kalmar sirri ba daidai ba ce ko fayil ɗin ya lalace/an canza shi", // Str::IntegrityCheckErrorMessage
    "Kuskure: Kalmar sirri ba za ta iya zama fanko ba", // Str::EmptyPasswordErrorMessage
    "Kuskure: Hanyar fayil ɗin manufa babban fayil ce", // Str::OutputFileIsDirectoryErrorMessage
    "Kuskure: Hanyar fayil ɗin tushe babban fayil ce", // Str::InputFileIsDirectoryErrorMessage
    "Kuskure: Hanyar fayil ɗin manufa ba za ta iya zama fanko ba", // Str::EmptyOutputFilePathErrorMessage
    "Kuskure: Hanyar fayil ɗin tushe ba za ta iya zama fanko ba", // Str::EmptyInputFilePathErrorMessage
    "Kuskure: Fayil ɗin tushe ba ya wanzu", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Harshe: Hausa", // Str::LanguageLabel
    "Kalmar sirri", // Str::PasswordLabel
    "Tsawon kalmar sirri", // Str::PasswordLenghtLabel
    "Fayil", // Str::FileLabel
    "Fayil ɗin", // Str::TheFileLabel
    "Hanya", // Str::PathLabel
    "Hanyar fayil na shigarwa", // Str::InputFilePathLabel
    "Hanyar fayil na fitarwa", // Str::OutputFilePathLabel
    "Musanya hanyoyi", // Str::SwapPathsLabel
    "za a sake rubuta shi", // Str::WillBeOverwrittenLabel
    "Ana ɓoyewa...", // Str::EncryptingText
    "Ana warwarewa...", // Str::DecryptingText
    "Ɓoye", // Str::EncryptText
    "Warware", // Str::DecryptText
    "An ɓoye fayil ɗin cikin nasara", // Str::FileEncryptedMessage
    "An warware fayil ɗin cikin nasara", // Str::FileDecryptedMessage
    "Gargaɗi!", // Str::WarningTitle
    "Ka tabbata?", // Str::AreYouSureTitle
    "Saituna", // Str::SettingsTitle
    "Mai samar da kalmar sirri", // Str::GeneratePasswordTitle
    "Zaɓi harshe", // Str::SelectLanguageTitle
    "Ee", // Str::YesLabel
    "A'a", // Str::NoLabel
    "To", // Str::OkLabel
    "Tsarin fitarwa", // Str::OutFormatLabel
    "Saitunan fuskar mu'amala", // Str::InterfaceSettingsLabel
    "Girma", // Str::InterfaceSizeLabel
    "Yanayi", // Str::ModeLabel
    "Na yau da kullum", // Str::NormalModeLabel
    "Rubutu kawai", // Str::PlaintextModeLabel
    "Jigo", // Str::InterfaceThemeLabel
    "Launi", // Str::InterfaceColorLabel
    "Tsoho (rubutu kawai)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Yi amfani da wannan kalmar sirri", // Str::UsePasswordLabel
    "Kwafa", // Str::CopyLabel
    "Ctrl + danna hagu don samun SHA256", // Str::GetSHA256Text
    // Themes
    "Haske", // Str::LightThemeName
    "Duhu", // Str::DarkThemeName
    // Colors
    "Shuɗi", // Str::BlueName
    "Shuɗi mai haske", // Str::CyanName
    "Kore", // Str::GreenName
    "Koren lemo", // Str::LimeName
    "Rawaya", // Str::YellowName
    "Ruwan ƙasa", // Str::BrownName
    "Lemu", // Str::OrangeName
    "Ja", // Str::RedName
    "Ruwan hoda", // Str::PinkName
    "Shunayya", // Str::PurpleName
    "Toka", // Str::GreyName
    "Fari", // Str::WhiteName
    "Baƙi", // Str::BlackName

};
static_assert(sizeof(textosHA) / sizeof(textosHA[0]) == N,
    "Faltan o sobran textos en hausa: revisa que coincidan con Str::Count.");

// 한국어 (ko)
constexpr const char* textosKO[] = {

    
    
    // Info
    "종료하려면 Enter 키를 누르세요...", // Str::ExitInfoMessage
    "파일 내용이 일반 텍스트인", // Str::PlainTextModeMessage_FirstLine
    "경우에만 활성화하세요", // Str::PlainTextModeMessage_SecondLine
    "암호화된 파일은 인쇄 가능한", // Str::DefaultCipherModeText_FirstLine
    "문자 형식으로 저장됩니다", // Str::DefaultCipherModeText_SecondLine
    "암호화된 파일은 OpenSSL과 호환되는", // Str::OpenSSLCipherModeText_FirstLine
    "바이너리 형식으로 저장됩니다", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 반복 횟수:", // Str::PBKDF2IterationsText
    // Errors
    "오류: 잘못된 매개변수", // Str::WrongParamsText
    "입력 값", // Str::InputValueText
    "입력 경로", // Str::InputPathText
    "입력 값을 0 이상의 숫자로 변환할 수 없습니다", // Str::WrongNumberValueMessage
    "입력 경로에 해당하는 기존 파일이 없습니다", // Str::WrongPathValueMessage
    "입력한 옵션은 유효한 매개변수로 인식되지 않습니다", // Str::InvalidOptionMessage
    "입력한 옵션", // Str::EnteredOptionText
    "알 수 없는 예외", // Str::UnknownExceptionText
    "GLFW를 초기화하지 못했습니다", // Str::GLFWErrorMessage
    "GLAD를 초기화하지 못했습니다", // Str::GLADErrorMessage
    "오류: 파일을 읽기용으로 열 수 없습니다", // Str::ReadFileErrorMessage
    "파일 내용을 읽는 중 오류가 발생했습니다", // Str::ErrorWhileReadingMessage
    "오류: 파일을 쓰기용으로 열 수 없습니다", // Str::WriteFileErrorMessage
    "오류: 16진수 문자열의 문자 수는 짝수여야 합니다", // Str::HexStringErrorMessage
    "오류: 문자열에 잘못된 16진수 문자가 있습니다", // Str::InvalidHexCharacterErrorMessage
    "오류: 파일을 저장할 수 없습니다", // Str::SaveFileErrorMessage
    "오류: 파일을 불러올 수 없습니다", // Str::LoadFileErrorMessage
    "오류: 잘못된 파일 형식 (5개의 필드 필요: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "오류: 반복 횟수가 설정된 최댓값(10,000,000)을 초과합니다", // Str::MaxIterationsErrorMessage
    "오류: 무결성 검증 실패, 비밀번호가 틀렸거나 파일이 손상/변조되었습니다", // Str::IntegrityCheckErrorMessage
    "오류: 비밀번호는 비워 둘 수 없습니다", // Str::EmptyPasswordErrorMessage
    "오류: 대상 파일 경로가 디렉터리입니다", // Str::OutputFileIsDirectoryErrorMessage
    "오류: 원본 파일 경로가 디렉터리입니다", // Str::InputFileIsDirectoryErrorMessage
    "오류: 대상 파일 경로는 비워 둘 수 없습니다", // Str::EmptyOutputFilePathErrorMessage
    "오류: 원본 파일 경로는 비워 둘 수 없습니다", // Str::EmptyInputFilePathErrorMessage
    "오류: 원본 파일이 존재하지 않습니다", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "언어: 한국어", // Str::LanguageLabel
    "비밀번호", // Str::PasswordLabel
    "비밀번호 길이", // Str::PasswordLenghtLabel
    "파일", // Str::FileLabel
    "파일", // Str::TheFileLabel
    "경로", // Str::PathLabel
    "입력 파일 경로", // Str::InputFilePathLabel
    "출력 파일 경로", // Str::OutputFilePathLabel
    "경로 바꾸기", // Str::SwapPathsLabel
    "을(를) 덮어씁니다", // Str::WillBeOverwrittenLabel
    "암호화하는 중...", // Str::EncryptingText
    "복호화하는 중...", // Str::DecryptingText
    "암호화", // Str::EncryptText
    "복호화", // Str::DecryptText
    "파일이 성공적으로 암호화되었습니다", // Str::FileEncryptedMessage
    "파일이 성공적으로 복호화되었습니다", // Str::FileDecryptedMessage
    "경고!", // Str::WarningTitle
    "계속하시겠습니까?", // Str::AreYouSureTitle
    "설정", // Str::SettingsTitle
    "비밀번호 생성기", // Str::GeneratePasswordTitle
    "언어 선택", // Str::SelectLanguageTitle
    "예", // Str::YesLabel
    "아니요", // Str::NoLabel
    "확인", // Str::OkLabel
    "출력 형식", // Str::OutFormatLabel
    "인터페이스 설정", // Str::InterfaceSettingsLabel
    "크기", // Str::InterfaceSizeLabel
    "모드", // Str::ModeLabel
    "일반", // Str::NormalModeLabel
    "일반 텍스트", // Str::PlaintextModeLabel
    "테마", // Str::InterfaceThemeLabel
    "색상", // Str::InterfaceColorLabel
    "기본값 (일반 텍스트)", // Str::DefaultLabel
    "OpenSSL (바이너리)", // Str::OpenSSLLabel
    "이 비밀번호 사용", // Str::UsePasswordLabel
    "복사", // Str::CopyLabel
    "Ctrl + 왼쪽 클릭으로 SHA256 가져오기", // Str::GetSHA256Text
    // Themes
    "라이트", // Str::LightThemeName
    "다크", // Str::DarkThemeName
    // Colors
    "파란색", // Str::BlueName
    "청록색", // Str::CyanName
    "초록색", // Str::GreenName
    "라임색", // Str::LimeName
    "노란색", // Str::YellowName
    "갈색", // Str::BrownName
    "주황색", // Str::OrangeName
    "빨간색", // Str::RedName
    "분홍색", // Str::PinkName
    "보라색", // Str::PurpleName
    "회색", // Str::GreyName
    "흰색", // Str::WhiteName
    "검은색", // Str::BlackName

};
static_assert(sizeof(textosKO) / sizeof(textosKO[0]) == N,
    "Faltan o sobran textos en coreano: revisa que coincidan con Str::Count.");

// Basa Jawa (jv)
constexpr const char* textosJV[] = {

    
    
    // Info
    "Penet Enter kanggo metu...", // Str::ExitInfoMessage
    "Aktifake mung yen isi berkas", // Str::PlainTextModeMessage_FirstLine
    "arupa teks biasa", // Str::PlainTextModeMessage_SecondLine
    "Berkas sing dienkripsi bakal disimpen", // Str::DefaultCipherModeText_FirstLine
    "minangka karakter sing bisa dicithak", // Str::DefaultCipherModeText_SecondLine
    "Berkas sing dienkripsi bakal disimpen", // Str::OpenSSLCipherModeText_FirstLine
    "ing format biner, cocog karo OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterasi PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Kesalahan: parameter ora bener", // Str::WrongParamsText
    "Nilai sing dilebokake", // Str::InputValueText
    "Path sing dilebokake", // Str::InputPathText
    "Nilai sing dilebokake ora bisa diowahi dadi angka sing luwih gedhe utawa padha karo 0", // Str::WrongNumberValueMessage
    "Path sing dilebokake ora cocog karo berkas apa wae sing ana", // Str::WrongPathValueMessage
    "Opsi sing dilebokake ora dikenali minangka parameter sing sah", // Str::InvalidOptionMessage
    "Opsi sing dilebokake", // Str::EnteredOptionText
    "Pengecualian sing ora dikenal", // Str::UnknownExceptionText
    "Gagal miwiti GLFW", // Str::GLFWErrorMessage
    "Gagal miwiti GLAD", // Str::GLADErrorMessage
    "Kesalahan: Ora bisa mbukak berkas kanggo diwaca", // Str::ReadFileErrorMessage
    "Kesalahan nalika maca isi berkas", // Str::ErrorWhileReadingMessage
    "Kesalahan: Ora bisa mbukak berkas kanggo ditulis", // Str::WriteFileErrorMessage
    "Kesalahan: String heksadesimal kudu nduweni cacah karakter genep", // Str::HexStringErrorMessage
    "Kesalahan: Ana karakter heksadesimal sing ora sah ing string", // Str::InvalidHexCharacterErrorMessage
    "Kesalahan: Ora bisa nyimpen berkas", // Str::SaveFileErrorMessage
    "Kesalahan: Ora bisa ngemot berkas", // Str::LoadFileErrorMessage
    "Kesalahan: Format berkas ora sah (dikarepake 5 kolom: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Kesalahan: Cacah iterasi ngluwihi watesan maksimum sing ditemtokake (10.000.000)", // Str::MaxIterationsErrorMessage
    "Kesalahan: Verifikasi integritas gagal, tembung sandhi salah utawa berkas rusak/diowahi", // Str::IntegrityCheckErrorMessage
    "Kesalahan: Tembung sandhi ora kena kosong", // Str::EmptyPasswordErrorMessage
    "Kesalahan: Path berkas tujuan iku direktori", // Str::OutputFileIsDirectoryErrorMessage
    "Kesalahan: Path berkas sumber iku direktori", // Str::InputFileIsDirectoryErrorMessage
    "Kesalahan: Path berkas tujuan ora kena kosong", // Str::EmptyOutputFilePathErrorMessage
    "Kesalahan: Path berkas sumber ora kena kosong", // Str::EmptyInputFilePathErrorMessage
    "Kesalahan: Berkas sumber ora ana", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Basa: Basa Jawa", // Str::LanguageLabel
    "Tembung sandhi", // Str::PasswordLabel
    "Dawane tembung sandhi", // Str::PasswordLenghtLabel
    "Berkas", // Str::FileLabel
    "Berkas", // Str::TheFileLabel
    "Path", // Str::PathLabel
    "Path berkas input", // Str::InputFilePathLabel
    "Path berkas output", // Str::OutputFilePathLabel
    "Ijolake path", // Str::SwapPathsLabel
    "bakal ditimpa", // Str::WillBeOverwrittenLabel
    "Ngenkripsi...", // Str::EncryptingText
    "Ndekripsi...", // Str::DecryptingText
    "Enkripsi", // Str::EncryptText
    "Dekripsi", // Str::DecryptText
    "Berkas kasil dienkripsi", // Str::FileEncryptedMessage
    "Berkas kasil didekripsi", // Str::FileDecryptedMessage
    "Pènget!", // Str::WarningTitle
    "Apa sampeyan yakin?", // Str::AreYouSureTitle
    "Setelan", // Str::SettingsTitle
    "Panggawe tembung sandhi", // Str::GeneratePasswordTitle
    "Pilih basa", // Str::SelectLanguageTitle
    "Ya", // Str::YesLabel
    "Ora", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format output", // Str::OutFormatLabel
    "Setelan antarmuka", // Str::InterfaceSettingsLabel
    "Ukuran", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Teks biasa", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Werna", // Str::InterfaceColorLabel
    "Gawan (teks biasa)", // Str::DefaultLabel
    "OpenSSL (biner)", // Str::OpenSSLLabel
    "Gunakake tembung sandhi iki", // Str::UsePasswordLabel
    "Salin", // Str::CopyLabel
    "Ctrl + klik kiwa kanggo entuk SHA256", // Str::GetSHA256Text
    // Themes
    "Padhang", // Str::LightThemeName
    "Peteng", // Str::DarkThemeName
    // Colors
    "Biru", // Str::BlueName
    "Sian", // Str::CyanName
    "Ijo", // Str::GreenName
    "Ijo jeruk", // Str::LimeName
    "Kuning", // Str::YellowName
    "Coklat", // Str::BrownName
    "Oranye", // Str::OrangeName
    "Abang", // Str::RedName
    "Jambon", // Str::PinkName
    "Wungu", // Str::PurpleName
    "Abu-abu", // Str::GreyName
    "Putih", // Str::WhiteName
    "Ireng", // Str::BlackName

};
static_assert(sizeof(textosJV) / sizeof(textosJV[0]) == N,
    "Faltan o sobran textos en javanes: revisa que coincidan con Str::Count.");

// Italiano (it)
constexpr const char* textosIT[] = {

    
    
    // Info
    "Premi Invio per uscire...", // Str::ExitInfoMessage
    "Attivare solo se il contenuto", // Str::PlainTextModeMessage_FirstLine
    "del file è testo semplice", // Str::PlainTextModeMessage_SecondLine
    "Il file cifrato verrà salvato", // Str::DefaultCipherModeText_FirstLine
    "come caratteri stampabili", // Str::DefaultCipherModeText_SecondLine
    "Il file cifrato verrà salvato in", // Str::OpenSSLCipherModeText_FirstLine
    "formato binario, compatibile con OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterazioni PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Errore: parametri non corretti", // Str::WrongParamsText
    "Valore ricevuto", // Str::InputValueText
    "Percorso ricevuto", // Str::InputPathText
    "Impossibile convertire il valore ricevuto in un numero maggiore o uguale a 0", // Str::WrongNumberValueMessage
    "Il percorso ricevuto non corrisponde a nessun file esistente", // Str::WrongPathValueMessage
    "L'opzione inserita non è riconosciuta come parametro valido", // Str::InvalidOptionMessage
    "Opzione inserita", // Str::EnteredOptionText
    "Eccezione sconosciuta", // Str::UnknownExceptionText
    "Impossibile inizializzare GLFW", // Str::GLFWErrorMessage
    "Impossibile inizializzare GLAD", // Str::GLADErrorMessage
    "Errore: impossibile aprire il file in lettura", // Str::ReadFileErrorMessage
    "Errore durante la lettura del contenuto del file", // Str::ErrorWhileReadingMessage
    "Errore: impossibile aprire il file in scrittura", // Str::WriteFileErrorMessage
    "Errore: la stringa esadecimale deve avere un numero pari di caratteri", // Str::HexStringErrorMessage
    "Errore: carattere esadecimale non valido nella stringa", // Str::InvalidHexCharacterErrorMessage
    "Errore: impossibile salvare il file", // Str::SaveFileErrorMessage
    "Errore: impossibile caricare il file", // Str::LoadFileErrorMessage
    "Errore: formato del file non valido (attesi 5 campi: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Errore: il numero di iterazioni supera il massimo stabilito (10.000.000)", // Str::MaxIterationsErrorMessage
    "Errore: verifica dell'integrità non riuscita, password errata o file danneggiato/manomesso", // Str::IntegrityCheckErrorMessage
    "Errore: la password non può essere vuota", // Str::EmptyPasswordErrorMessage
    "Errore: il percorso del file di destinazione è una cartella", // Str::OutputFileIsDirectoryErrorMessage
    "Errore: il percorso del file di origine è una cartella", // Str::InputFileIsDirectoryErrorMessage
    "Errore: il percorso del file di destinazione non può essere vuoto", // Str::EmptyOutputFilePathErrorMessage
    "Errore: il percorso del file di origine non può essere vuoto", // Str::EmptyInputFilePathErrorMessage
    "Errore: il file di origine non esiste", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Lingua: Italiano", // Str::LanguageLabel
    "Password", // Str::PasswordLabel
    "Lunghezza della password", // Str::PasswordLenghtLabel
    "File", // Str::FileLabel
    "Il file", // Str::TheFileLabel
    "Percorso", // Str::PathLabel
    "Percorso di input", // Str::InputFilePathLabel
    "Percorso di output", // Str::OutputFilePathLabel
    "Scambia percorsi", // Str::SwapPathsLabel
    "verrà sovrascritto", // Str::WillBeOverwrittenLabel
    "Cifratura in corso...", // Str::EncryptingText
    "Decifratura in corso...", // Str::DecryptingText
    "Cifra", // Str::EncryptText
    "Decifra", // Str::DecryptText
    "File cifrato correttamente", // Str::FileEncryptedMessage
    "File decifrato correttamente", // Str::FileDecryptedMessage
    "Attenzione!", // Str::WarningTitle
    "Sei sicuro?", // Str::AreYouSureTitle
    "Impostazioni", // Str::SettingsTitle
    "Generatore di password", // Str::GeneratePasswordTitle
    "Seleziona lingua", // Str::SelectLanguageTitle
    "Sì", // Str::YesLabel
    "No", // Str::NoLabel
    "OK", // Str::OkLabel
    "Formato di output", // Str::OutFormatLabel
    "Impostazioni dell'interfaccia", // Str::InterfaceSettingsLabel
    "Dimensione", // Str::InterfaceSizeLabel
    "Modalità", // Str::ModeLabel
    "Normale", // Str::NormalModeLabel
    "Testo semplice", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Colore", // Str::InterfaceColorLabel
    "Predefinito (testo semplice)", // Str::DefaultLabel
    "OpenSSL (binario)", // Str::OpenSSLLabel
    "Usa questa password", // Str::UsePasswordLabel
    "Copia", // Str::CopyLabel
    "Ctrl + clic sinistro per ottenere lo SHA256", // Str::GetSHA256Text
    // Themes
    "Chiaro", // Str::LightThemeName
    "Scuro", // Str::DarkThemeName
    // Colors
    "Blu", // Str::BlueName
    "Ciano", // Str::CyanName
    "Verde", // Str::GreenName
    "Lime", // Str::LimeName
    "Giallo", // Str::YellowName
    "Marrone", // Str::BrownName
    "Arancione", // Str::OrangeName
    "Rosso", // Str::RedName
    "Rosa", // Str::PinkName
    "Viola", // Str::PurpleName
    "Grigio", // Str::GreyName
    "Bianco", // Str::WhiteName
    "Nero", // Str::BlackName

};
static_assert(sizeof(textosIT) / sizeof(textosIT[0]) == N,
    "Faltan o sobran textos en italiano: revisa que coincidan con Str::Count.");

// Bahasa Melayu (ms)
constexpr const char* textosMS[] = {

    
    
    // Info
    "Tekan Enter untuk keluar...", // Str::ExitInfoMessage
    "Dayakan hanya jika kandungan", // Str::PlainTextModeMessage_FirstLine
    "fail ialah teks biasa", // Str::PlainTextModeMessage_SecondLine
    "Fail yang disulitkan akan disimpan", // Str::DefaultCipherModeText_FirstLine
    "sebagai aksara yang boleh dicetak", // Str::DefaultCipherModeText_SecondLine
    "Fail yang disulitkan akan disimpan dalam", // Str::OpenSSLCipherModeText_FirstLine
    "format binari, serasi dengan OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Lelaran PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Ralat: parameter tidak betul", // Str::WrongParamsText
    "Nilai input", // Str::InputValueText
    "Laluan input", // Str::InputPathText
    "Nilai input tidak dapat ditukar kepada nombor yang lebih besar daripada atau sama dengan 0", // Str::WrongNumberValueMessage
    "Laluan input tidak sepadan dengan mana-mana fail yang wujud", // Str::WrongPathValueMessage
    "Pilihan yang dimasukkan tidak dikenali sebagai parameter yang sah", // Str::InvalidOptionMessage
    "Pilihan yang dimasukkan", // Str::EnteredOptionText
    "Pengecualian tidak diketahui", // Str::UnknownExceptionText
    "Gagal memulakan GLFW", // Str::GLFWErrorMessage
    "Gagal memulakan GLAD", // Str::GLADErrorMessage
    "Ralat: Tidak dapat membuka fail untuk dibaca", // Str::ReadFileErrorMessage
    "Ralat semasa membaca kandungan fail", // Str::ErrorWhileReadingMessage
    "Ralat: Tidak dapat membuka fail untuk ditulis", // Str::WriteFileErrorMessage
    "Ralat: Rentetan heksadesimal mesti mempunyai bilangan aksara genap", // Str::HexStringErrorMessage
    "Ralat: Aksara heksadesimal tidak sah dalam rentetan", // Str::InvalidHexCharacterErrorMessage
    "Ralat: Tidak dapat menyimpan fail", // Str::SaveFileErrorMessage
    "Ralat: Tidak dapat memuatkan fail", // Str::LoadFileErrorMessage
    "Ralat: Format fail tidak sah (dijangka 5 medan: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Ralat: Bilangan lelaran melebihi had maksimum yang ditetapkan (10,000,000)", // Str::MaxIterationsErrorMessage
    "Ralat: Pengesahan integriti gagal, kata laluan salah atau fail rosak/diusik", // Str::IntegrityCheckErrorMessage
    "Ralat: Kata laluan tidak boleh kosong", // Str::EmptyPasswordErrorMessage
    "Ralat: Laluan fail destinasi ialah direktori", // Str::OutputFileIsDirectoryErrorMessage
    "Ralat: Laluan fail sumber ialah direktori", // Str::InputFileIsDirectoryErrorMessage
    "Ralat: Laluan fail destinasi tidak boleh kosong", // Str::EmptyOutputFilePathErrorMessage
    "Ralat: Laluan fail sumber tidak boleh kosong", // Str::EmptyInputFilePathErrorMessage
    "Ralat: Fail sumber tidak wujud", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Bahasa: Bahasa Melayu", // Str::LanguageLabel
    "Kata laluan", // Str::PasswordLabel
    "Panjang kata laluan", // Str::PasswordLenghtLabel
    "Fail", // Str::FileLabel
    "Fail", // Str::TheFileLabel
    "Laluan", // Str::PathLabel
    "Laluan fail input", // Str::InputFilePathLabel
    "Laluan fail output", // Str::OutputFilePathLabel
    "Tukar laluan", // Str::SwapPathsLabel
    "akan ditulis ganti", // Str::WillBeOverwrittenLabel
    "Menyulitkan...", // Str::EncryptingText
    "Menyahsulit...", // Str::DecryptingText
    "Sulitkan", // Str::EncryptText
    "Nyahsulit", // Str::DecryptText
    "Fail berjaya disulitkan", // Str::FileEncryptedMessage
    "Fail berjaya dinyahsulit", // Str::FileDecryptedMessage
    "Amaran!", // Str::WarningTitle
    "Adakah anda pasti?", // Str::AreYouSureTitle
    "Tetapan", // Str::SettingsTitle
    "Penjana kata laluan", // Str::GeneratePasswordTitle
    "Pilih bahasa", // Str::SelectLanguageTitle
    "Ya", // Str::YesLabel
    "Tidak", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format output", // Str::OutFormatLabel
    "Tetapan antara muka", // Str::InterfaceSettingsLabel
    "Saiz", // Str::InterfaceSizeLabel
    "Mod", // Str::ModeLabel
    "Biasa", // Str::NormalModeLabel
    "Teks biasa", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Warna", // Str::InterfaceColorLabel
    "Lalai (teks biasa)", // Str::DefaultLabel
    "OpenSSL (binari)", // Str::OpenSSLLabel
    "Guna kata laluan ini", // Str::UsePasswordLabel
    "Salin", // Str::CopyLabel
    "Ctrl + klik kiri untuk mendapatkan SHA256", // Str::GetSHA256Text
    // Themes
    "Cerah", // Str::LightThemeName
    "Gelap", // Str::DarkThemeName
    // Colors
    "Biru", // Str::BlueName
    "Sian", // Str::CyanName
    "Hijau", // Str::GreenName
    "Hijau limau", // Str::LimeName
    "Kuning", // Str::YellowName
    "Coklat", // Str::BrownName
    "Oren", // Str::OrangeName
    "Merah", // Str::RedName
    "Merah jambu", // Str::PinkName
    "Ungu", // Str::PurpleName
    "Kelabu", // Str::GreyName
    "Putih", // Str::WhiteName
    "Hitam", // Str::BlackName

};
static_assert(sizeof(textosMS) / sizeof(textosMS[0]) == N,
    "Faltan o sobran textos en malayo: revisa que coincidan con Str::Count.");

// አማርኛ (am)
constexpr const char* textosAM[] = {

    
    
    // Info
    "ለመውጣት Enter ይጫኑ...", // Str::ExitInfoMessage
    "የፋይሉ ይዘት ግልጽ ጽሑፍ", // Str::PlainTextModeMessage_FirstLine
    "ከሆነ ብቻ ያንቁት", // Str::PlainTextModeMessage_SecondLine
    "የተመሰጠረው ፋይል", // Str::DefaultCipherModeText_FirstLine
    "ሊታተሙ በሚችሉ ቁምፊዎች ይቀመጣል", // Str::DefaultCipherModeText_SecondLine
    "የተመሰጠረው ፋይል ከOpenSSL ጋር", // Str::OpenSSLCipherModeText_FirstLine
    "በሚጣጣም ባለሁለትዮሽ ቅርጸት ይቀመጣል", // Str::OpenSSLCipherModeText_SecondLine
    "የPBKDF2 ድግግሞሾች:", // Str::PBKDF2IterationsText
    // Errors
    "ስህተት: ትክክል ያልሆኑ መለኪያዎች", // Str::WrongParamsText
    "የገባው እሴት", // Str::InputValueText
    "የገባው ዱካ", // Str::InputPathText
    "የገባውን እሴት ከ0 ወደሚበልጥ ወይም ከ0 ጋር እኩል ወደሆነ ቁጥር መቀየር አልተቻለም", // Str::WrongNumberValueMessage
    "የገባው ዱካ ከማንኛውም ነባር ፋይል ጋር አይዛመድም", // Str::WrongPathValueMessage
    "የገባው አማራጭ እንደ ትክክለኛ መለኪያ አልታወቀም", // Str::InvalidOptionMessage
    "የገባው አማራጭ", // Str::EnteredOptionText
    "ያልታወቀ ልዩ ሁኔታ", // Str::UnknownExceptionText
    "GLFWን ማስጀመር አልተሳካም", // Str::GLFWErrorMessage
    "GLADን ማስጀመር አልተሳካም", // Str::GLADErrorMessage
    "ስህተት: ፋይሉን ለንባብ መክፈት አልተቻለም", // Str::ReadFileErrorMessage
    "የፋይሉን ይዘት በማንበብ ላይ ስህተት ተፈጥሯል", // Str::ErrorWhileReadingMessage
    "ስህተት: ፋይሉን ለመጻፍ መክፈት አልተቻለም", // Str::WriteFileErrorMessage
    "ስህተት: የሄክሳዴሲማል ሕብረቁምፊው የቁምፊዎች ብዛት ጥንድ ቁጥር መሆን አለበት", // Str::HexStringErrorMessage
    "ስህተት: በሕብረቁምፊው ውስጥ ልክ ያልሆነ የሄክሳዴሲማል ቁምፊ አለ", // Str::InvalidHexCharacterErrorMessage
    "ስህተት: ፋይሉን ማስቀመጥ አልተቻለም", // Str::SaveFileErrorMessage
    "ስህተት: ፋይሉን መጫን አልተቻለም", // Str::LoadFileErrorMessage
    "ስህተት: ልክ ያልሆነ የፋይል ቅርጸት (5 መስኮች ይጠበቁ ነበር: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "ስህተት: የድግግሞሾቹ ብዛት ከተወሰነው ከፍተኛ ገደብ (10,000,000) ይበልጣል", // Str::MaxIterationsErrorMessage
    "ስህተት: የትክክለኛነት ማረጋገጫ አልተሳካም፣ የተሳሳተ የይለፍ ቃል ወይም የተበላሸ/የተነካካ ፋይል", // Str::IntegrityCheckErrorMessage
    "ስህተት: የይለፍ ቃሉ ባዶ መሆን አይችልም", // Str::EmptyPasswordErrorMessage
    "ስህተት: የመድረሻ ፋይሉ ዱካ አቃፊ ነው", // Str::OutputFileIsDirectoryErrorMessage
    "ስህተት: የምንጭ ፋይሉ ዱካ አቃፊ ነው", // Str::InputFileIsDirectoryErrorMessage
    "ስህተት: የመድረሻ ፋይሉ ዱካ ባዶ መሆን አይችልም", // Str::EmptyOutputFilePathErrorMessage
    "ስህተት: የምንጭ ፋይሉ ዱካ ባዶ መሆን አይችልም", // Str::EmptyInputFilePathErrorMessage
    "ስህተት: የምንጭ ፋይሉ የለም", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "ቋንቋ: አማርኛ", // Str::LanguageLabel
    "የይለፍ ቃል", // Str::PasswordLabel
    "የይለፍ ቃል ርዝመት", // Str::PasswordLenghtLabel
    "ፋይል", // Str::FileLabel
    "ፋይሉ", // Str::TheFileLabel
    "ዱካ", // Str::PathLabel
    "የግብዓት ፋይል ዱካ", // Str::InputFilePathLabel
    "የውጤት ፋይል ዱካ", // Str::OutputFilePathLabel
    "ዱካዎቹን አቀያይር", // Str::SwapPathsLabel
    "ይተካል", // Str::WillBeOverwrittenLabel
    "በማመስጠር ላይ...", // Str::EncryptingText
    "ምስጠራን በመፍታት ላይ...", // Str::DecryptingText
    "አመስጥር", // Str::EncryptText
    "ምስጠራ ፍታ", // Str::DecryptText
    "ፋይሉ በተሳካ ሁኔታ ተመስጥሯል", // Str::FileEncryptedMessage
    "የፋይሉ ምስጠራ በተሳካ ሁኔታ ተፈትቷል", // Str::FileDecryptedMessage
    "ማስጠንቀቂያ!", // Str::WarningTitle
    "እርግጠኛ ነዎት?", // Str::AreYouSureTitle
    "ቅንብሮች", // Str::SettingsTitle
    "የይለፍ ቃል አመንጪ", // Str::GeneratePasswordTitle
    "ቋንቋ ይምረጡ", // Str::SelectLanguageTitle
    "አዎ", // Str::YesLabel
    "አይ", // Str::NoLabel
    "እሺ", // Str::OkLabel
    "የውጤት ቅርጸት", // Str::OutFormatLabel
    "የበይነገጽ ቅንብሮች", // Str::InterfaceSettingsLabel
    "መጠን", // Str::InterfaceSizeLabel
    "ሁነታ", // Str::ModeLabel
    "መደበኛ", // Str::NormalModeLabel
    "ግልጽ ጽሑፍ", // Str::PlaintextModeLabel
    "ገጽታ", // Str::InterfaceThemeLabel
    "ቀለም", // Str::InterfaceColorLabel
    "ነባሪ (ግልጽ ጽሑፍ)", // Str::DefaultLabel
    "OpenSSL (ባለሁለትዮሽ)", // Str::OpenSSLLabel
    "ይህን የይለፍ ቃል ተጠቀም", // Str::UsePasswordLabel
    "ቅዳ", // Str::CopyLabel
    "SHA256 ለማግኘት Ctrl + የግራ ጠቅታ ያድርጉ", // Str::GetSHA256Text
    // Themes
    "ብርሃን", // Str::LightThemeName
    "ጨለማ", // Str::DarkThemeName
    // Colors
    "ሰማያዊ", // Str::BlueName
    "ውሃ ሰማያዊ", // Str::CyanName
    "አረንጓዴ", // Str::GreenName
    "ሎሚ አረንጓዴ", // Str::LimeName
    "ቢጫ", // Str::YellowName
    "ቡናማ", // Str::BrownName
    "ብርቱካናማ", // Str::OrangeName
    "ቀይ", // Str::RedName
    "ሮዝ", // Str::PinkName
    "ወይን ጠጅ", // Str::PurpleName
    "ግራጫ", // Str::GreyName
    "ነጭ", // Str::WhiteName
    "ጥቁር", // Str::BlackName

};
static_assert(sizeof(textosAM) / sizeof(textosAM[0]) == N,
    "Faltan o sobran textos en amharico: revisa que coincidan con Str::Count.");

// Yorùbá (yo)
constexpr const char* textosYO[] = {

    
    
    // Info
    "Tẹ Enter láti jáde...", // Str::ExitInfoMessage
    "Mú ṣiṣẹ nìkan tí àkóónú fáìlì", // Str::PlainTextModeMessage_FirstLine
    "náà bá jẹ ọrọ lásán", // Str::PlainTextModeMessage_SecondLine
    "A ó fi fáìlì tí a ti pa ní kóòdù", // Str::DefaultCipherModeText_FirstLine
    "pamọ gẹgẹ bí àwọn ohun kikọ tí a lè tẹ jáde", // Str::DefaultCipherModeText_SecondLine
    "A ó fi fáìlì tí a ti pa ní kóòdù pamọ", // Str::OpenSSLCipherModeText_FirstLine
    "ní ìlànà binary, tí ó bá OpenSSL mu", // Str::OpenSSLCipherModeText_SecondLine
    "Ìyípo PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Àṣìṣe: àwọn pàrámítà kò tọ", // Str::WrongParamsText
    "Iye tí a gbà", // Str::InputValueText
    "Ọnà tí a gbà", // Str::InputPathText
    "Kò ṣeé ṣe láti yí iye tí a gbà padà sí nọmbà tí ó tóbi ju 0 lọ tàbí tí ó dọgba pẹlú 0", // Str::WrongNumberValueMessage
    "Ọnà tí a gbà kò bá fáìlì kankan tí ó wà mu", // Str::WrongPathValueMessage
    "A kò dá àṣàyàn tí a tẹ sí mọ gẹgẹ bí pàrámítà tí ó wúlò", // Str::InvalidOptionMessage
    "Àṣàyàn tí a tẹ sí", // Str::EnteredOptionText
    "Àṣìṣe àìmọ", // Str::UnknownExceptionText
    "Kùnà láti bẹrẹ GLFW", // Str::GLFWErrorMessage
    "Kùnà láti bẹrẹ GLAD", // Str::GLADErrorMessage
    "Àṣìṣe: Kò ṣeé ṣe láti ṣí fáìlì náà fún kíkà", // Str::ReadFileErrorMessage
    "Àṣìṣe nígbà tí a ń ka àkóónú fáìlì náà", // Str::ErrorWhileReadingMessage
    "Àṣìṣe: Kò ṣeé ṣe láti ṣí fáìlì náà fún kíkọ", // Str::WriteFileErrorMessage
    "Àṣìṣe: Iye ohun kikọ inú okùn hexadecimal gbọdọ jẹ nọmbà tí a lè pín sí méjì", // Str::HexStringErrorMessage
    "Àṣìṣe: Ohun kikọ hexadecimal tí kò wúlò wà nínú okùn náà", // Str::InvalidHexCharacterErrorMessage
    "Àṣìṣe: Kò ṣeé ṣe láti fi fáìlì náà pamọ", // Str::SaveFileErrorMessage
    "Àṣìṣe: Kò ṣeé ṣe láti gbé fáìlì náà wọlé", // Str::LoadFileErrorMessage
    "Àṣìṣe: Ìlànà fáìlì kò wúlò (a ń retí abala 5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Àṣìṣe: Iye ìyípo ti kọjá òpin tí a ṣètò (10,000,000)", // Str::MaxIterationsErrorMessage
    "Àṣìṣe: Ìjẹrìísí òtítọ fáìlì kùnà, ọrọ aṣínà kò tọ tàbí fáìlì ti bàjẹ/a ti yí i padà", // Str::IntegrityCheckErrorMessage
    "Àṣìṣe: Ọrọ aṣínà kò lè ṣófo", // Str::EmptyPasswordErrorMessage
    "Àṣìṣe: Ọnà fáìlì ìjáde jẹ fódà", // Str::OutputFileIsDirectoryErrorMessage
    "Àṣìṣe: Ọnà fáìlì orísun jẹ fódà", // Str::InputFileIsDirectoryErrorMessage
    "Àṣìṣe: Ọnà fáìlì ìjáde kò lè ṣófo", // Str::EmptyOutputFilePathErrorMessage
    "Àṣìṣe: Ọnà fáìlì orísun kò lè ṣófo", // Str::EmptyInputFilePathErrorMessage
    "Àṣìṣe: Fáìlì orísun kò sí", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Èdè: Yorùbá", // Str::LanguageLabel
    "Ọrọ aṣínà", // Str::PasswordLabel
    "Gígùn ọrọ aṣínà", // Str::PasswordLenghtLabel
    "Fáìlì", // Str::FileLabel
    "Fáìlì náà", // Str::TheFileLabel
    "Ọnà", // Str::PathLabel
    "Ọnà fáìlì ìwọlé", // Str::InputFilePathLabel
    "Ọnà fáìlì ìjáde", // Str::OutputFilePathLabel
    "Pààrọ àwọn ọnà", // Str::SwapPathsLabel
    "yóò di kíkọ lé lórí", // Str::WillBeOverwrittenLabel
    "Ń pa á ní kóòdù...", // Str::EncryptingText
    "Ń ṣí kóòdù...", // Str::DecryptingText
    "Pa ní kóòdù", // Str::EncryptText
    "Ṣí kóòdù", // Str::DecryptText
    "A ti pa fáìlì náà ní kóòdù ní àṣeyọrí", // Str::FileEncryptedMessage
    "A ti ṣí kóòdù fáìlì náà ní àṣeyọrí", // Str::FileDecryptedMessage
    "Ìkìlọ!", // Str::WarningTitle
    "Ṣé ó dá ọ lójú?", // Str::AreYouSureTitle
    "Ètò", // Str::SettingsTitle
    "Olùṣẹdá ọrọ aṣínà", // Str::GeneratePasswordTitle
    "Yan èdè", // Str::SelectLanguageTitle
    "Bẹẹni", // Str::YesLabel
    "Rárá", // Str::NoLabel
    "Ó dáa", // Str::OkLabel
    "Ìlànà ìjáde", // Str::OutFormatLabel
    "Ètò ìṣàfihàn", // Str::InterfaceSettingsLabel
    "Ìwọn", // Str::InterfaceSizeLabel
    "Ipò", // Str::ModeLabel
    "Déédéé", // Str::NormalModeLabel
    "Ọrọ lásán", // Str::PlaintextModeLabel
    "Àkòrí", // Str::InterfaceThemeLabel
    "Àwọ", // Str::InterfaceColorLabel
    "Àìyípadà (ọrọ lásán)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Lo ọrọ aṣínà yìí", // Str::UsePasswordLabel
    "Daakọ", // Str::CopyLabel
    "Ctrl + tẹ apá òsì láti gba SHA256", // Str::GetSHA256Text
    // Themes
    "Ìmọlẹ", // Str::LightThemeName
    "Òkùnkùn", // Str::DarkThemeName
    // Colors
    "Búlúù", // Str::BlueName
    "Búlúù fẹẹrẹ", // Str::CyanName
    "Àwọ ewé", // Str::GreenName
    "Àwọ ewé fẹẹrẹ", // Str::LimeName
    "Ìyeyè", // Str::YellowName
    "Àwọ ilẹ", // Str::BrownName
    "Ọsàn", // Str::OrangeName
    "Pupa", // Str::RedName
    "Pínkì", // Str::PinkName
    "Elése àlùkò", // Str::PurpleName
    "Eérú", // Str::GreyName
    "Funfun", // Str::WhiteName
    "Dúdú", // Str::BlackName

};
static_assert(sizeof(textosYO) / sizeof(textosYO[0]) == N,
    "Faltan o sobran textos en yoruba: revisa que coincidan con Str::Count.");

// Afaan Oromoo (om)
constexpr const char* textosOM[] = {

    
    
    // Info
    "Ba'uuf Enter tuqi...", // Str::ExitInfoMessage
    "Qabiyyeen faayilichaa barreeffama", // Str::PlainTextModeMessage_FirstLine
    "salphaa yoo ta'e qofa dandeessisi", // Str::PlainTextModeMessage_SecondLine
    "Faayilli icciitessame akka", // Str::DefaultCipherModeText_FirstLine
    "qubee maxxansamuu danda'aniitti olkaa'ama", // Str::DefaultCipherModeText_SecondLine
    "Faayilli icciitessame bifa binary,", // Str::OpenSSLCipherModeText_FirstLine
    "OpenSSL waliin walsimuun olkaa'ama", // Str::OpenSSLCipherModeText_SecondLine
    "Irra deddeebii PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Dogoggora: paaraameetiroonni sirrii miti", // Str::WrongParamsText
    "Gatii galfame", // Str::InputValueText
    "Karaa galfame", // Str::InputPathText
    "Gatiin galfame lakkoofsa 0 irra guddaa ykn 0 wajjin walqixa ta'etti jijjiiramuu hin dandeenye", // Str::WrongNumberValueMessage
    "Karaan galfame faayilii jiru kamiinuu wal hin simu", // Str::WrongPathValueMessage
    "Filannoon galfame akka paaraameetira sirriitti hin beekamne", // Str::InvalidOptionMessage
    "Filannoo galfame", // Str::EnteredOptionText
    "Dogoggora hin beekamne", // Str::UnknownExceptionText
    "GLFW jalqabsiisuun hin danda'amne", // Str::GLFWErrorMessage
    "GLAD jalqabsiisuun hin danda'amne", // Str::GLADErrorMessage
    "Dogoggora: Faayilicha dubbisuuf banuun hin danda'amne", // Str::ReadFileErrorMessage
    "Qabiyyee faayilichaa dubbisuu irratti dogoggorri uumame", // Str::ErrorWhileReadingMessage
    "Dogoggora: Faayilicha barreessuuf banuun hin danda'amne", // Str::WriteFileErrorMessage
    "Dogoggora: Tarreen hexadecimal baay'ina qubee dachaa qabaachuu qaba", // Str::HexStringErrorMessage
    "Dogoggora: Tarree keessa qubee hexadecimal sirrii hin taane jira", // Str::InvalidHexCharacterErrorMessage
    "Dogoggora: Faayilicha olkaa'uun hin danda'amne", // Str::SaveFileErrorMessage
    "Dogoggora: Faayilicha fe'uun hin danda'amne", // Str::LoadFileErrorMessage
    "Dogoggora: Bifni faayilii sirrii miti (dirreewwan 5 eegamu: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Dogoggora: Baay'inni irra deddeebii daangaa ol'aanaa murtaa'e (10,000,000) darbeera", // Str::MaxIterationsErrorMessage
    "Dogoggora: Mirkaneessi guutummaa hin milkoofne, jechi icciitii dogoggora ykn faayilli miidhameera/jijjiirameera", // Str::IntegrityCheckErrorMessage
    "Dogoggora: Jechi icciitii duwwaa ta'uu hin danda'u", // Str::EmptyPasswordErrorMessage
    "Dogoggora: Karaan faayilii bakka gahiinsaa kuusaa dha", // Str::OutputFileIsDirectoryErrorMessage
    "Dogoggora: Karaan faayilii madda kuusaa dha", // Str::InputFileIsDirectoryErrorMessage
    "Dogoggora: Karaan faayilii bakka gahiinsaa duwwaa ta'uu hin danda'u", // Str::EmptyOutputFilePathErrorMessage
    "Dogoggora: Karaan faayilii madda duwwaa ta'uu hin danda'u", // Str::EmptyInputFilePathErrorMessage
    "Dogoggora: Faayilli madda hin jiru", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Afaan: Afaan Oromoo", // Str::LanguageLabel
    "Jecha icciitii", // Str::PasswordLabel
    "Dheerina jecha icciitii", // Str::PasswordLenghtLabel
    "Faayilii", // Str::FileLabel
    "Faayilli", // Str::TheFileLabel
    "Karaa", // Str::PathLabel
    "Karaa faayilii galchaa", // Str::InputFilePathLabel
    "Karaa faayilii bahaa", // Str::OutputFilePathLabel
    "Karaawwan wal jijjiiri", // Str::SwapPathsLabel
    "irra deebi'ee ni barreeffama", // Str::WillBeOverwrittenLabel
    "Icciitessaa jira...", // Str::EncryptingText
    "Icciitii baasaa jira...", // Str::DecryptingText
    "Icciitessi", // Str::EncryptText
    "Icciitii baasi", // Str::DecryptText
    "Faayilli milkaa'inaan icciitessameera", // Str::FileEncryptedMessage
    "Icciitiin faayilichaa milkaa'inaan baafameera", // Str::FileDecryptedMessage
    "Akeekkachiisa!", // Str::WarningTitle
    "Ni mirkaneessitaa?", // Str::AreYouSureTitle
    "Qindaa'ina", // Str::SettingsTitle
    "Uumaa jecha icciitii", // Str::GeneratePasswordTitle
    "Afaan filadhu", // Str::SelectLanguageTitle
    "Eeyyee", // Str::YesLabel
    "Lakki", // Str::NoLabel
    "Tole", // Str::OkLabel
    "Bifa bahaa", // Str::OutFormatLabel
    "Qindaa'ina fuula fayyadamaa", // Str::InterfaceSettingsLabel
    "Hamma", // Str::InterfaceSizeLabel
    "Haalata", // Str::ModeLabel
    "Idilee", // Str::NormalModeLabel
    "Barreeffama salphaa", // Str::PlaintextModeLabel
    "Haala mul'ataa", // Str::InterfaceThemeLabel
    "Halluu", // Str::InterfaceColorLabel
    "Durtii (barreeffama salphaa)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Jecha icciitii kana fayyadami", // Str::UsePasswordLabel
    "Garagalchi", // Str::CopyLabel
    "SHA256 argachuuf Ctrl + bitaa cuqaasi", // Str::GetSHA256Text
    // Themes
    "Ifaa", // Str::LightThemeName
    "Dukkana", // Str::DarkThemeName
    // Colors
    "Cuquliisa", // Str::BlueName
    "Cuquliisa ifaa", // Str::CyanName
    "Magariisa", // Str::GreenName
    "Magariisa ifaa", // Str::LimeName
    "Keelloo", // Str::YellowName
    "Magaala", // Str::BrownName
    "Burtukaanii", // Str::OrangeName
    "Diimaa", // Str::RedName
    "Diimaa ifaa", // Str::PinkName
    "Diimaa cuquliisaa", // Str::PurpleName
    "Daalacha", // Str::GreyName
    "Adii", // Str::WhiteName
    "Gurraacha", // Str::BlackName

};
static_assert(sizeof(textosOM) / sizeof(textosOM[0]) == N,
    "Faltan o sobran textos en oromo: revisa que coincidan con Str::Count.");

// Basa Sunda (su)
constexpr const char* textosSU[] = {

    
    
    // Info
    "Pencét Enter pikeun kaluar...", // Str::ExitInfoMessage
    "Aktipkeun ngan lamun eusi berkas", // Str::PlainTextModeMessage_FirstLine
    "mangrupa téks biasa", // Str::PlainTextModeMessage_SecondLine
    "Berkas anu diénkripsi bakal disimpen", // Str::DefaultCipherModeText_FirstLine
    "salaku karakter anu bisa dicitak", // Str::DefaultCipherModeText_SecondLine
    "Berkas anu diénkripsi bakal disimpen", // Str::OpenSSLCipherModeText_FirstLine
    "dina format biner, cocog jeung OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterasi PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Kasalahan: paraméter teu bener", // Str::WrongParamsText
    "Nilai anu diasupkeun", // Str::InputValueText
    "Jalur anu diasupkeun", // Str::InputPathText
    "Nilai anu diasupkeun teu bisa dirobah jadi angka anu leuwih gedé atawa sarua jeung 0", // Str::WrongNumberValueMessage
    "Jalur anu diasupkeun teu cocog jeung berkas mana waé anu aya", // Str::WrongPathValueMessage
    "Pilihan anu diasupkeun teu dipikawanoh salaku paraméter anu sah", // Str::InvalidOptionMessage
    "Pilihan anu diasupkeun", // Str::EnteredOptionText
    "Pengecualian anu teu dipikanyaho", // Str::UnknownExceptionText
    "Gagal ngamimitian GLFW", // Str::GLFWErrorMessage
    "Gagal ngamimitian GLAD", // Str::GLADErrorMessage
    "Kasalahan: Teu bisa muka berkas pikeun dibaca", // Str::ReadFileErrorMessage
    "Kasalahan nalika maca eusi berkas", // Str::ErrorWhileReadingMessage
    "Kasalahan: Teu bisa muka berkas pikeun ditulis", // Str::WriteFileErrorMessage
    "Kasalahan: String héksadésimal kudu ngandung jumlah karakter genep", // Str::HexStringErrorMessage
    "Kasalahan: Aya karakter héksadésimal anu teu sah dina string", // Str::InvalidHexCharacterErrorMessage
    "Kasalahan: Teu bisa nyimpen berkas", // Str::SaveFileErrorMessage
    "Kasalahan: Teu bisa ngamuat berkas", // Str::LoadFileErrorMessage
    "Kasalahan: Format berkas teu sah (diperkirakeun 5 widang: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Kasalahan: Jumlah iterasi ngaleuwihan wates maksimum anu ditetepkeun (10.000.000)", // Str::MaxIterationsErrorMessage
    "Kasalahan: Vérifikasi integritas gagal, kecap akses salah atawa berkas ruksak/dirobah", // Str::IntegrityCheckErrorMessage
    "Kasalahan: Kecap akses teu meunang kosong", // Str::EmptyPasswordErrorMessage
    "Kasalahan: Jalur berkas tujuan mangrupa diréktori", // Str::OutputFileIsDirectoryErrorMessage
    "Kasalahan: Jalur berkas sumber mangrupa diréktori", // Str::InputFileIsDirectoryErrorMessage
    "Kasalahan: Jalur berkas tujuan teu meunang kosong", // Str::EmptyOutputFilePathErrorMessage
    "Kasalahan: Jalur berkas sumber teu meunang kosong", // Str::EmptyInputFilePathErrorMessage
    "Kasalahan: Berkas sumber teu aya", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Basa: Basa Sunda", // Str::LanguageLabel
    "Kecap akses", // Str::PasswordLabel
    "Panjang kecap akses", // Str::PasswordLenghtLabel
    "Berkas", // Str::FileLabel
    "Berkas", // Str::TheFileLabel
    "Jalur", // Str::PathLabel
    "Jalur berkas input", // Str::InputFilePathLabel
    "Jalur berkas output", // Str::OutputFilePathLabel
    "Tukeur jalur", // Str::SwapPathsLabel
    "bakal ditimpa", // Str::WillBeOverwrittenLabel
    "Ngénkripsi...", // Str::EncryptingText
    "Ngadékripsi...", // Str::DecryptingText
    "Énkripsi", // Str::EncryptText
    "Dékripsi", // Str::DecryptText
    "Berkas suksés diénkripsi", // Str::FileEncryptedMessage
    "Berkas suksés didékripsi", // Str::FileDecryptedMessage
    "Perhatosan!", // Str::WarningTitle
    "Anjeun yakin?", // Str::AreYouSureTitle
    "Setélan", // Str::SettingsTitle
    "Pembuat kecap akses", // Str::GeneratePasswordTitle
    "Pilih basa", // Str::SelectLanguageTitle
    "Enya", // Str::YesLabel
    "Henteu", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format output", // Str::OutFormatLabel
    "Setélan antarbeungeut", // Str::InterfaceSettingsLabel
    "Ukuran", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Téks biasa", // Str::PlaintextModeLabel
    "Téma", // Str::InterfaceThemeLabel
    "Warna", // Str::InterfaceColorLabel
    "Baku (téks biasa)", // Str::DefaultLabel
    "OpenSSL (biner)", // Str::OpenSSLLabel
    "Paké kecap akses ieu", // Str::UsePasswordLabel
    "Tiron", // Str::CopyLabel
    "Ctrl + klik kénca pikeun meunangkeun SHA256", // Str::GetSHA256Text
    // Themes
    "Caang", // Str::LightThemeName
    "Poék", // Str::DarkThemeName
    // Colors
    "Bulao", // Str::BlueName
    "Bulao ngora", // Str::CyanName
    "Héjo", // Str::GreenName
    "Héjo ngora", // Str::LimeName
    "Konéng", // Str::YellowName
    "Coklat", // Str::BrownName
    "Oranyeu", // Str::OrangeName
    "Beureum", // Str::RedName
    "Kayas", // Str::PinkName
    "Wungu", // Str::PurpleName
    "Kulawu", // Str::GreyName
    "Bodas", // Str::WhiteName
    "Hideung", // Str::BlackName

};
static_assert(sizeof(textosSU) / sizeof(textosSU[0]) == N,
    "Faltan o sobran textos en sundanes: revisa que coincidan con Str::Count.");

// Polski (pl)
constexpr const char* textosPL[] = {

    
    
    // Info
    "Naciśnij Enter, aby zakończyć...", // Str::ExitInfoMessage
    "Włącz tylko wtedy, gdy zawartość", // Str::PlainTextModeMessage_FirstLine
    "pliku jest zwykłym tekstem", // Str::PlainTextModeMessage_SecondLine
    "Zaszyfrowany plik zostanie zapisany", // Str::DefaultCipherModeText_FirstLine
    "jako znaki drukowalne", // Str::DefaultCipherModeText_SecondLine
    "Zaszyfrowany plik zostanie zapisany", // Str::OpenSSLCipherModeText_FirstLine
    "w formacie binarnym, zgodnym z OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iteracje PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Błąd: nieprawidłowe parametry", // Str::WrongParamsText
    "Otrzymana wartość", // Str::InputValueText
    "Otrzymana ścieżka", // Str::InputPathText
    "Nie udało się przekształcić otrzymanej wartości na liczbę większą lub równą 0", // Str::WrongNumberValueMessage
    "Otrzymana ścieżka nie odpowiada żadnemu istniejącemu plikowi", // Str::WrongPathValueMessage
    "Wprowadzona opcja nie została rozpoznana jako prawidłowy parametr", // Str::InvalidOptionMessage
    "Wprowadzona opcja", // Str::EnteredOptionText
    "Nieznany wyjątek", // Str::UnknownExceptionText
    "Nie udało się zainicjować GLFW", // Str::GLFWErrorMessage
    "Nie udało się zainicjować GLAD", // Str::GLADErrorMessage
    "Błąd: nie można otworzyć pliku do odczytu", // Str::ReadFileErrorMessage
    "Błąd podczas odczytu zawartości pliku", // Str::ErrorWhileReadingMessage
    "Błąd: nie można otworzyć pliku do zapisu", // Str::WriteFileErrorMessage
    "Błąd: ciąg szesnastkowy musi zawierać parzystą liczbę znaków", // Str::HexStringErrorMessage
    "Błąd: nieprawidłowy znak szesnastkowy w ciągu", // Str::InvalidHexCharacterErrorMessage
    "Błąd: nie można zapisać pliku", // Str::SaveFileErrorMessage
    "Błąd: nie można wczytać pliku", // Str::LoadFileErrorMessage
    "Błąd: nieprawidłowy format pliku (oczekiwano 5 pól: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Błąd: liczba iteracji przekracza ustalone maksimum (10 000 000)", // Str::MaxIterationsErrorMessage
    "Błąd: weryfikacja integralności nie powiodła się, nieprawidłowe hasło lub uszkodzony/zmodyfikowany plik", // Str::IntegrityCheckErrorMessage
    "Błąd: hasło nie może być puste", // Str::EmptyPasswordErrorMessage
    "Błąd: ścieżka pliku docelowego jest katalogiem", // Str::OutputFileIsDirectoryErrorMessage
    "Błąd: ścieżka pliku źródłowego jest katalogiem", // Str::InputFileIsDirectoryErrorMessage
    "Błąd: ścieżka pliku docelowego nie może być pusta", // Str::EmptyOutputFilePathErrorMessage
    "Błąd: ścieżka pliku źródłowego nie może być pusta", // Str::EmptyInputFilePathErrorMessage
    "Błąd: plik źródłowy nie istnieje", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Język: Polski", // Str::LanguageLabel
    "Hasło", // Str::PasswordLabel
    "Długość hasła", // Str::PasswordLenghtLabel
    "Plik", // Str::FileLabel
    "Plik", // Str::TheFileLabel
    "Ścieżka", // Str::PathLabel
    "Ścieżka pliku wejściowego", // Str::InputFilePathLabel
    "Ścieżka pliku wyjściowego", // Str::OutputFilePathLabel
    "Zamień ścieżki", // Str::SwapPathsLabel
    "zostanie nadpisany", // Str::WillBeOverwrittenLabel
    "Szyfrowanie...", // Str::EncryptingText
    "Odszyfrowywanie...", // Str::DecryptingText
    "Zaszyfruj", // Str::EncryptText
    "Odszyfruj", // Str::DecryptText
    "Plik został pomyślnie zaszyfrowany", // Str::FileEncryptedMessage
    "Plik został pomyślnie odszyfrowany", // Str::FileDecryptedMessage
    "Uwaga!", // Str::WarningTitle
    "Czy na pewno?", // Str::AreYouSureTitle
    "Ustawienia", // Str::SettingsTitle
    "Generator haseł", // Str::GeneratePasswordTitle
    "Wybierz język", // Str::SelectLanguageTitle
    "Tak", // Str::YesLabel
    "Nie", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format wyjściowy", // Str::OutFormatLabel
    "Ustawienia interfejsu", // Str::InterfaceSettingsLabel
    "Rozmiar", // Str::InterfaceSizeLabel
    "Tryb", // Str::ModeLabel
    "Normalny", // Str::NormalModeLabel
    "Zwykły tekst", // Str::PlaintextModeLabel
    "Motyw", // Str::InterfaceThemeLabel
    "Kolor", // Str::InterfaceColorLabel
    "Domyślny (zwykły tekst)", // Str::DefaultLabel
    "OpenSSL (binarny)", // Str::OpenSSLLabel
    "Użyj tego hasła", // Str::UsePasswordLabel
    "Kopiuj", // Str::CopyLabel
    "Ctrl + lewy klik, aby uzyskać SHA256", // Str::GetSHA256Text
    // Themes
    "Jasny", // Str::LightThemeName
    "Ciemny", // Str::DarkThemeName
    // Colors
    "Niebieski", // Str::BlueName
    "Cyjan", // Str::CyanName
    "Zielony", // Str::GreenName
    "Limonkowy", // Str::LimeName
    "Żółty", // Str::YellowName
    "Brązowy", // Str::BrownName
    "Pomarańczowy", // Str::OrangeName
    "Czerwony", // Str::RedName
    "Różowy", // Str::PinkName
    "Fioletowy", // Str::PurpleName
    "Szary", // Str::GreyName
    "Biały", // Str::WhiteName
    "Czarny", // Str::BlackName

};
static_assert(sizeof(textosPL) / sizeof(textosPL[0]) == N,
    "Faltan o sobran textos en polaco: revisa que coincidan con Str::Count.");

// Lingála (ln)
constexpr const char* textosLN[] = {

    
    
    // Info
    "Fina Enter mpo na kobima...", // Str::ExitInfoMessage
    "Pelisa kaka soki maye ezali na fisyé", // Str::PlainTextModeMessage_FirstLine
    "ezali makomi ya pɛtɛɛ", // Str::PlainTextModeMessage_SecondLine
    "Fisyé oyo ekangami na sekele ekobombama", // Str::DefaultCipherModeText_FirstLine
    "lokola bilembo oyo ekoki kobimisama", // Str::DefaultCipherModeText_SecondLine
    "Fisyé oyo ekangami na sekele ekobombama", // Str::OpenSSLCipherModeText_FirstLine
    "na lolenge binaire, oyo ekokani na OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Mbala ya kozongela PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Libunga: baparamɛtrɛ ezali malamu te", // Str::WrongParamsText
    "Motuya oyo ekɔtisami", // Str::InputValueText
    "Nzela oyo ekɔtisami", // Str::InputPathText
    "Ekokaki te kobongola motuya oyo ekɔtisami na motango oleki 0 to ekokani na 0", // Str::WrongNumberValueMessage
    "Nzela oyo ekɔtisami ekokani na fisyé moko te oyo ezali", // Str::WrongPathValueMessage
    "Bopɔni oyo ekɔtisami eyebani te lokola paramɛtrɛ ya malamu", // Str::InvalidOptionMessage
    "Bopɔni oyo ekɔtisami", // Str::EnteredOptionText
    "Libunga oyo eyebani te", // Str::UnknownExceptionText
    "Ekokaki te kobandisa GLFW", // Str::GLFWErrorMessage
    "Ekokaki te kobandisa GLAD", // Str::GLADErrorMessage
    "Libunga: Ekokaki te kofungola fisyé mpo na kotanga", // Str::ReadFileErrorMessage
    "Libunga ntango ya kotanga maye ezali na fisyé", // Str::ErrorWhileReadingMessage
    "Libunga: Ekokaki te kofungola fisyé mpo na kokoma", // Str::WriteFileErrorMessage
    "Libunga: Molɔngɔ ya hexadécimal esengeli kozala na motango ya bilembo oyo ekabwani na mibale", // Str::HexStringErrorMessage
    "Libunga: Elembo ya hexadécimal oyo ebongi te ezali na molɔngɔ", // Str::InvalidHexCharacterErrorMessage
    "Libunga: Ekokaki te kobomba fisyé", // Str::SaveFileErrorMessage
    "Libunga: Ekokaki te kozwa fisyé", // Str::LoadFileErrorMessage
    "Libunga: Lolenge ya fisyé ebongi te (bisika 5 ezalaki kozelama: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Libunga: Motango ya kozongela eleki ndelo oyo etyamaki (10 000 000)", // Str::MaxIterationsErrorMessage
    "Libunga: Botali ya bosembo ya fisyé elongi te, liloba ya nkuku ezali mabe to fisyé ebebi/ebongolami", // Str::IntegrityCheckErrorMessage
    "Libunga: Liloba ya nkuku ekoki kozala mpamba te", // Str::EmptyPasswordErrorMessage
    "Libunga: Nzela ya fisyé ya kobimisa ezali dosye", // Str::OutputFileIsDirectoryErrorMessage
    "Libunga: Nzela ya fisyé ya ebandeli ezali dosye", // Str::InputFileIsDirectoryErrorMessage
    "Libunga: Nzela ya fisyé ya kobimisa ekoki kozala mpamba te", // Str::EmptyOutputFilePathErrorMessage
    "Libunga: Nzela ya fisyé ya ebandeli ekoki kozala mpamba te", // Str::EmptyInputFilePathErrorMessage
    "Libunga: Fisyé ya ebandeli ezali te", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Lokota: Lingála", // Str::LanguageLabel
    "Liloba ya nkuku", // Str::PasswordLabel
    "Bolai ya liloba ya nkuku", // Str::PasswordLenghtLabel
    "Fisyé", // Str::FileLabel
    "Fisyé", // Str::TheFileLabel
    "Nzela", // Str::PathLabel
    "Nzela ya fisyé ya kokɔtisa", // Str::InputFilePathLabel
    "Nzela ya fisyé ya kobimisa", // Str::OutputFilePathLabel
    "Kobongola esika ya banzela", // Str::SwapPathsLabel
    "ekokomama lisusu", // Str::WillBeOverwrittenLabel
    "Ezali kokanga na sekele...", // Str::EncryptingText
    "Ezali kofungola sekele...", // Str::DecryptingText
    "Kanga na sekele", // Str::EncryptText
    "Fungola sekele", // Str::DecryptText
    "Fisyé ekangami na sekele malamu", // Str::FileEncryptedMessage
    "Sekele ya fisyé efungolami malamu", // Str::FileDecryptedMessage
    "Likébisi!", // Str::WarningTitle
    "Ozali sikisiki?", // Str::AreYouSureTitle
    "Bibongiseli", // Str::SettingsTitle
    "Kosala liloba ya nkuku", // Str::GeneratePasswordTitle
    "Pɔna lokota", // Str::SelectLanguageTitle
    "Ee", // Str::YesLabel
    "Te", // Str::NoLabel
    "Malamu", // Str::OkLabel
    "Lolenge ya kobimisa", // Str::OutFormatLabel
    "Bibongiseli ya etando", // Str::InterfaceSettingsLabel
    "Monene", // Str::InterfaceSizeLabel
    "Lolenge", // Str::ModeLabel
    "Ya momesano", // Str::NormalModeLabel
    "Makomi ya pɛtɛɛ", // Str::PlaintextModeLabel
    "Motindo", // Str::InterfaceThemeLabel
    "Langi", // Str::InterfaceColorLabel
    "Ya ebandeli (makomi ya pɛtɛɛ)", // Str::DefaultLabel
    "OpenSSL (binaire)", // Str::OpenSSLLabel
    "Salela liloba ya nkuku oyo", // Str::UsePasswordLabel
    "Kopia", // Str::CopyLabel
    "Ctrl + kofina na lobɔkɔ ya mwasi mpo na kozwa SHA256", // Str::GetSHA256Text
    // Themes
    "Pole", // Str::LightThemeName
    "Molili", // Str::DarkThemeName
    // Colors
    "Bule", // Str::BlueName
    "Bule ya pole", // Str::CyanName
    "Langi ya matiti", // Str::GreenName
    "Langi ya ndimo", // Str::LimeName
    "Zɔnɛ", // Str::YellowName
    "Langi ya mabele", // Str::BrownName
    "Langi ya lilala", // Str::OrangeName
    "Motane", // Str::RedName
    "Rozɛ", // Str::PinkName
    "Violɛ", // Str::PurpleName
    "Gri", // Str::GreyName
    "Mpɛmbɛ", // Str::WhiteName
    "Moindo", // Str::BlackName

};
static_assert(sizeof(textosLN) / sizeof(textosLN[0]) == N,
    "Faltan o sobran textos en lingala: revisa que coincidan con Str::Count.");

// Українська (uk)
constexpr const char* textosUK[] = {

    
    
    // Info
    "Натисніть Enter, щоб вийти...", // Str::ExitInfoMessage
    "Вмикайте, лише якщо вміст", // Str::PlainTextModeMessage_FirstLine
    "файлу є простим текстом", // Str::PlainTextModeMessage_SecondLine
    "Зашифрований файл буде збережено", // Str::DefaultCipherModeText_FirstLine
    "у вигляді друкованих символів", // Str::DefaultCipherModeText_SecondLine
    "Зашифрований файл буде збережено", // Str::OpenSSLCipherModeText_FirstLine
    "у двійковому форматі, сумісному з OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Ітерації PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Помилка: неправильні параметри", // Str::WrongParamsText
    "Отримане значення", // Str::InputValueText
    "Отриманий шлях", // Str::InputPathText
    "Не вдалося перетворити отримане значення на число, більше або рівне 0", // Str::WrongNumberValueMessage
    "Отриманий шлях не відповідає жодному наявному файлу", // Str::WrongPathValueMessage
    "Введений параметр не розпізнано як допустимий", // Str::InvalidOptionMessage
    "Введений параметр", // Str::EnteredOptionText
    "Невідомий виняток", // Str::UnknownExceptionText
    "Не вдалося ініціалізувати GLFW", // Str::GLFWErrorMessage
    "Не вдалося ініціалізувати GLAD", // Str::GLADErrorMessage
    "Помилка: не вдалося відкрити файл для читання", // Str::ReadFileErrorMessage
    "Помилка під час читання вмісту файлу", // Str::ErrorWhileReadingMessage
    "Помилка: не вдалося відкрити файл для запису", // Str::WriteFileErrorMessage
    "Помилка: шістнадцятковий рядок повинен містити парну кількість символів", // Str::HexStringErrorMessage
    "Помилка: неприпустимий шістнадцятковий символ у рядку", // Str::InvalidHexCharacterErrorMessage
    "Помилка: не вдалося зберегти файл", // Str::SaveFileErrorMessage
    "Помилка: не вдалося завантажити файл", // Str::LoadFileErrorMessage
    "Помилка: неправильний формат файлу (очікується 5 полів: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Помилка: кількість ітерацій перевищує встановлений максимум (10 000 000)", // Str::MaxIterationsErrorMessage
    "Помилка: перевірку цілісності не пройдено, неправильний пароль або файл пошкоджено/змінено", // Str::IntegrityCheckErrorMessage
    "Помилка: пароль не може бути порожнім", // Str::EmptyPasswordErrorMessage
    "Помилка: шлях до цільового файлу є каталогом", // Str::OutputFileIsDirectoryErrorMessage
    "Помилка: шлях до файлу-джерела є каталогом", // Str::InputFileIsDirectoryErrorMessage
    "Помилка: шлях до цільового файлу не може бути порожнім", // Str::EmptyOutputFilePathErrorMessage
    "Помилка: шлях до файлу-джерела не може бути порожнім", // Str::EmptyInputFilePathErrorMessage
    "Помилка: файл-джерело не існує", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Мова: Українська", // Str::LanguageLabel
    "Пароль", // Str::PasswordLabel
    "Довжина пароля", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файл", // Str::TheFileLabel
    "Шлях", // Str::PathLabel
    "Шлях до вхідного файлу", // Str::InputFilePathLabel
    "Шлях до вихідного файлу", // Str::OutputFilePathLabel
    "Поміняти шляхи місцями", // Str::SwapPathsLabel
    "буде перезаписано", // Str::WillBeOverwrittenLabel
    "Шифрування...", // Str::EncryptingText
    "Розшифрування...", // Str::DecryptingText
    "Зашифрувати", // Str::EncryptText
    "Розшифрувати", // Str::DecryptText
    "Файл успішно зашифровано", // Str::FileEncryptedMessage
    "Файл успішно розшифровано", // Str::FileDecryptedMessage
    "Увага!", // Str::WarningTitle
    "Ви впевнені?", // Str::AreYouSureTitle
    "Налаштування", // Str::SettingsTitle
    "Генератор паролів", // Str::GeneratePasswordTitle
    "Вибір мови", // Str::SelectLanguageTitle
    "Так", // Str::YesLabel
    "Ні", // Str::NoLabel
    "OK", // Str::OkLabel
    "Формат виводу", // Str::OutFormatLabel
    "Налаштування інтерфейсу", // Str::InterfaceSettingsLabel
    "Розмір", // Str::InterfaceSizeLabel
    "Режим", // Str::ModeLabel
    "Звичайний", // Str::NormalModeLabel
    "Простий текст", // Str::PlaintextModeLabel
    "Тема", // Str::InterfaceThemeLabel
    "Колір", // Str::InterfaceColorLabel
    "Типово (простий текст)", // Str::DefaultLabel
    "OpenSSL (двійковий)", // Str::OpenSSLLabel
    "Використати цей пароль", // Str::UsePasswordLabel
    "Копіювати", // Str::CopyLabel
    "Ctrl + клік лівою кнопкою, щоб отримати SHA256", // Str::GetSHA256Text
    // Themes
    "Світла", // Str::LightThemeName
    "Темна", // Str::DarkThemeName
    // Colors
    "Синій", // Str::BlueName
    "Блакитний", // Str::CyanName
    "Зелений", // Str::GreenName
    "Лаймовий", // Str::LimeName
    "Жовтий", // Str::YellowName
    "Коричневий", // Str::BrownName
    "Помаранчевий", // Str::OrangeName
    "Червоний", // Str::RedName
    "Рожевий", // Str::PinkName
    "Фіолетовий", // Str::PurpleName
    "Сірий", // Str::GreyName
    "Білий", // Str::WhiteName
    "Чорний", // Str::BlackName

};
static_assert(sizeof(textosUK) / sizeof(textosUK[0]) == N,
    "Faltan o sobran textos en ucraniano: revisa que coincidan con Str::Count.");

// Fulfulde (ff)
constexpr const char* textosFF[] = {

    
    
    // Info
    "Ñoƴƴu Enter ngam yaltude...", // Str::ExitInfoMessage
    "Huutoro tan so ko woni e fiilde ndee", // Str::PlainTextModeMessage_FirstLine
    "ko binndi tan", // Str::PlainTextModeMessage_SecondLine
    "Fiilde sifiraande ndee maa danndee", // Str::DefaultCipherModeText_FirstLine
    "no alkule mbaawɗe muulneede", // Str::DefaultCipherModeText_SecondLine
    "Fiilde sifiraande ndee maa danndee e mbaydi", // Str::OpenSSLCipherModeText_FirstLine
    "binaire, fotondirnde e OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Ruttinanɗe PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Juumre: parameeteruuji ɗii moƴƴaani", // Str::WrongParamsText
    "Limoore naatnaande", // Str::InputValueText
    "Laawol naatnaangol", // Str::InputPathText
    "Waawaa waylude limoore naatnaande ndee e limoore ɓurnde 0 walla fotnde e 0", // Str::WrongNumberValueMessage
    "Laawol naatnaangol ngol fotondiraani e fiilde woodnde", // Str::WrongPathValueMessage
    "Suɓaade naatnaande ndee heɓtinaaka no parameeter moƴƴo", // Str::InvalidOptionMessage
    "Suɓaade naatnaande", // Str::EnteredOptionText
    "Juumre nde anndaaka", // Str::UnknownExceptionText
    "Waawaa fuɗɗinde GLFW", // Str::GLFWErrorMessage
    "Waawaa fuɗɗinde GLAD", // Str::GLADErrorMessage
    "Juumre: Waawaa uddittude fiilde ndee ngam janngude", // Str::ReadFileErrorMessage
    "Juumre e nder janngugol ko woni e fiilde ndee", // Str::ErrorWhileReadingMessage
    "Juumre: Waawaa uddittude fiilde ndee ngam winndude", // Str::WriteFileErrorMessage
    "Juumre: Diidol hexadecimal ngol ina foti jogaade limoore alkule peccotoonde e ɗiɗi", // Str::HexStringErrorMessage
    "Juumre: Alkule hexadecimal moƴƴaani ina e nder diidol ngol", // Str::InvalidHexCharacterErrorMessage
    "Juumre: Waawaa danndude fiilde ndee", // Str::SaveFileErrorMessage
    "Juumre: Waawaa loowde fiilde ndee", // Str::LoadFileErrorMessage
    "Juumre: Mbaydi fiilde moƴƴaani (ina haani wonde geɗe 5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Juumre: Limoore ruttinanɗe ɓurii keerol ɓurngol mawnude (10 000 000)", // Str::MaxIterationsErrorMessage
    "Juumre: Ƴeewndagol timmal fiilde ronkii, finnde nde moƴƴaani walla fiilde ndee bonii/waylaama", // Str::IntegrityCheckErrorMessage
    "Juumre: Finnde ndee waawaa wonde mehre", // Str::EmptyPasswordErrorMessage
    "Juumre: Laawol fiilde njaɓɓitaande ndee ko doosiye", // Str::OutputFileIsDirectoryErrorMessage
    "Juumre: Laawol fiilde iwdi ndee ko doosiye", // Str::InputFileIsDirectoryErrorMessage
    "Juumre: Laawol fiilde njaɓɓitaande ndee waawaa wonde mehol", // Str::EmptyOutputFilePathErrorMessage
    "Juumre: Laawol fiilde iwdi ndee waawaa wonde mehol", // Str::EmptyInputFilePathErrorMessage
    "Juumre: Fiilde iwdi ndee woodaani", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Ɗemngal: Fulfulde", // Str::LanguageLabel
    "Finnde", // Str::PasswordLabel
    "Juutal finnde", // Str::PasswordLenghtLabel
    "Fiilde", // Str::FileLabel
    "Fiilde", // Str::TheFileLabel
    "Laawol", // Str::PathLabel
    "Laawol fiilde naatnaande", // Str::InputFilePathLabel
    "Laawol fiilde yaltinaande", // Str::OutputFilePathLabel
    "Lomtindir laawi", // Str::SwapPathsLabel
    "maa winndee e dow mayre", // Str::WillBeOverwrittenLabel
    "Ina sifira...", // Str::EncryptingText
    "Ina uddita sifir...", // Str::DecryptingText
    "Sifir", // Str::EncryptText
    "Uddit sifir", // Str::DecryptText
    "Fiilde ndee sifiraama no moƴƴiri", // Str::FileEncryptedMessage
    "Sifir fiilde ndee udditaama no moƴƴiri", // Str::FileDecryptedMessage
    "Reentino!", // Str::WarningTitle
    "Aɗa teeŋtini?", // Str::AreYouSureTitle
    "Teelte", // Str::SettingsTitle
    "Sosoowo finnde", // Str::GeneratePasswordTitle
    "Suɓo ɗemngal", // Str::SelectLanguageTitle
    "Eey", // Str::YesLabel
    "Alaa", // Str::NoLabel
    "Ok", // Str::OkLabel
    "Mbaydi yaltinaandi", // Str::OutFormatLabel
    "Teelte interface", // Str::InterfaceSettingsLabel
    "Mawnugol", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Ko woowaa", // Str::NormalModeLabel
    "Binndi tan", // Str::PlaintextModeLabel
    "Jiyol", // Str::InterfaceThemeLabel
    "Noone", // Str::InterfaceColorLabel
    "Ko woowaa (binndi tan)", // Str::DefaultLabel
    "OpenSSL (binaire)", // Str::OpenSSLLabel
    "Huutoro finnde nde", // Str::UsePasswordLabel
    "Natto", // Str::CopyLabel
    "Ctrl + dobo nano ngam heɓde SHA256", // Str::GetSHA256Text
    // Themes
    "Jayngol", // Str::LightThemeName
    "Niɓɓere", // Str::DarkThemeName
    // Colors
    "Bulaa", // Str::BlueName
    "Bulaa jayngol", // Str::CyanName
    "Haakoore", // Str::GreenName
    "Haakoore jayngol", // Str::LimeName
    "Oolo", // Str::YellowName
    "Noone leydi", // Str::BrownName
    "Oraas", // Str::OrangeName
    "Boɗeejo", // Str::RedName
    "Roos", // Str::PinkName
    "Wiyole", // Str::PurpleName
    "Gri", // Str::GreyName
    "Daneejo", // Str::WhiteName
    "Ɓaleejo", // Str::BlackName

};
static_assert(sizeof(textosFF) / sizeof(textosFF[0]) == N,
    "Faltan o sobran textos en fula: revisa que coincidan con Str::Count.");

// 繁體中文 (zh-Hant)
constexpr const char* textosZH_HANT[] = {

    
    
    // Info
    "按 Enter 鍵結束...", // Str::ExitInfoMessage
    "僅在檔案內容", // Str::PlainTextModeMessage_FirstLine
    "為純文字時啟用", // Str::PlainTextModeMessage_SecondLine
    "加密後的檔案將儲存為", // Str::DefaultCipherModeText_FirstLine
    "可列印字元", // Str::DefaultCipherModeText_SecondLine
    "加密後的檔案將儲存為", // Str::OpenSSLCipherModeText_FirstLine
    "二進位格式，與 OpenSSL 相容", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 迭代次數：", // Str::PBKDF2IterationsText
    // Errors
    "錯誤：參數不正確", // Str::WrongParamsText
    "輸入值", // Str::InputValueText
    "輸入路徑", // Str::InputPathText
    "無法將輸入值轉換為大於或等於 0 的數字", // Str::WrongNumberValueMessage
    "輸入路徑不對應任何現有檔案", // Str::WrongPathValueMessage
    "輸入的選項無法識別為有效參數", // Str::InvalidOptionMessage
    "輸入的選項", // Str::EnteredOptionText
    "未知的例外狀況", // Str::UnknownExceptionText
    "GLFW 初始化失敗", // Str::GLFWErrorMessage
    "GLAD 初始化失敗", // Str::GLADErrorMessage
    "錯誤：無法開啟檔案進行讀取", // Str::ReadFileErrorMessage
    "讀取檔案內容時發生錯誤", // Str::ErrorWhileReadingMessage
    "錯誤：無法開啟檔案進行寫入", // Str::WriteFileErrorMessage
    "錯誤：十六進位字串的字元數必須為偶數", // Str::HexStringErrorMessage
    "錯誤：字串中含有無效的十六進位字元", // Str::InvalidHexCharacterErrorMessage
    "錯誤：無法儲存檔案", // Str::SaveFileErrorMessage
    "錯誤：無法載入檔案", // Str::LoadFileErrorMessage
    "錯誤：檔案格式無效（應有 5 個欄位：ciphertext|iv|salt|iterations|mac）", // Str::InvalidFileFormatErrorMessage
    "錯誤：迭代次數超過設定的上限（10,000,000）", // Str::MaxIterationsErrorMessage
    "錯誤：完整性驗證失敗，密碼錯誤或檔案已損毀/遭竄改", // Str::IntegrityCheckErrorMessage
    "錯誤：密碼不得為空", // Str::EmptyPasswordErrorMessage
    "錯誤：目的檔案路徑是一個資料夾", // Str::OutputFileIsDirectoryErrorMessage
    "錯誤：來源檔案路徑是一個資料夾", // Str::InputFileIsDirectoryErrorMessage
    "錯誤：目的檔案路徑不得為空", // Str::EmptyOutputFilePathErrorMessage
    "錯誤：來源檔案路徑不得為空", // Str::EmptyInputFilePathErrorMessage
    "錯誤：來源檔案不存在", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "語言：繁體中文", // Str::LanguageLabel
    "密碼", // Str::PasswordLabel
    "密碼長度", // Str::PasswordLenghtLabel
    "檔案", // Str::FileLabel
    "檔案", // Str::TheFileLabel
    "路徑", // Str::PathLabel
    "輸入檔案路徑", // Str::InputFilePathLabel
    "輸出檔案路徑", // Str::OutputFilePathLabel
    "交換路徑", // Str::SwapPathsLabel
    "將被覆寫", // Str::WillBeOverwrittenLabel
    "正在加密...", // Str::EncryptingText
    "正在解密...", // Str::DecryptingText
    "加密", // Str::EncryptText
    "解密", // Str::DecryptText
    "檔案加密成功", // Str::FileEncryptedMessage
    "檔案解密成功", // Str::FileDecryptedMessage
    "警告！", // Str::WarningTitle
    "您確定嗎？", // Str::AreYouSureTitle
    "設定", // Str::SettingsTitle
    "密碼產生器", // Str::GeneratePasswordTitle
    "選擇語言", // Str::SelectLanguageTitle
    "是", // Str::YesLabel
    "否", // Str::NoLabel
    "確定", // Str::OkLabel
    "輸出格式", // Str::OutFormatLabel
    "介面設定", // Str::InterfaceSettingsLabel
    "大小", // Str::InterfaceSizeLabel
    "模式", // Str::ModeLabel
    "一般", // Str::NormalModeLabel
    "純文字", // Str::PlaintextModeLabel
    "主題", // Str::InterfaceThemeLabel
    "顏色", // Str::InterfaceColorLabel
    "預設（純文字）", // Str::DefaultLabel
    "OpenSSL（二進位）", // Str::OpenSSLLabel
    "使用此密碼", // Str::UsePasswordLabel
    "複製", // Str::CopyLabel
    "Ctrl + 滑鼠左鍵點擊以取得 SHA256", // Str::GetSHA256Text
    // Themes
    "淺色", // Str::LightThemeName
    "深色", // Str::DarkThemeName
    // Colors
    "藍色", // Str::BlueName
    "青色", // Str::CyanName
    "綠色", // Str::GreenName
    "萊姆綠", // Str::LimeName
    "黃色", // Str::YellowName
    "棕色", // Str::BrownName
    "橘色", // Str::OrangeName
    "紅色", // Str::RedName
    "粉紅色", // Str::PinkName
    "紫色", // Str::PurpleName
    "灰色", // Str::GreyName
    "白色", // Str::WhiteName
    "黑色", // Str::BlackName

};
static_assert(sizeof(textosZH_HANT) / sizeof(textosZH_HANT[0]) == N,
    "Faltan o sobran textos en chino tradicional: revisa que coincidan con Str::Count.");

// Oʻzbekcha (uz)
constexpr const char* textosUZ[] = {

    
    
    // Info
    "Chiqish uchun Enter tugmasini bosing...", // Str::ExitInfoMessage
    "Faqat fayl tarkibi oddiy matn", // Str::PlainTextModeMessage_FirstLine
    "boʻlsagina yoqing", // Str::PlainTextModeMessage_SecondLine
    "Shifrlangan fayl chop etiladigan", // Str::DefaultCipherModeText_FirstLine
    "belgilar sifatida saqlanadi", // Str::DefaultCipherModeText_SecondLine
    "Shifrlangan fayl OpenSSL bilan mos", // Str::OpenSSLCipherModeText_FirstLine
    "ikkilik formatda saqlanadi", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 iteratsiyalari:", // Str::PBKDF2IterationsText
    // Errors
    "Xato: notoʻgʻri parametrlar", // Str::WrongParamsText
    "Kiritilgan qiymat", // Str::InputValueText
    "Kiritilgan yoʻl", // Str::InputPathText
    "Kiritilgan qiymatni 0 dan katta yoki unga teng songa aylantirib boʻlmadi", // Str::WrongNumberValueMessage
    "Kiritilgan yoʻl mavjud fayllarning hech biriga mos kelmaydi", // Str::WrongPathValueMessage
    "Kiritilgan opsiya yaroqli parametr sifatida tanilmadi", // Str::InvalidOptionMessage
    "Kiritilgan opsiya", // Str::EnteredOptionText
    "Nomaʼlum istisno", // Str::UnknownExceptionText
    "GLFW ni ishga tushirib boʻlmadi", // Str::GLFWErrorMessage
    "GLAD ni ishga tushirib boʻlmadi", // Str::GLADErrorMessage
    "Xato: Faylni oʻqish uchun ochib boʻlmadi", // Str::ReadFileErrorMessage
    "Fayl tarkibini oʻqishda xato yuz berdi", // Str::ErrorWhileReadingMessage
    "Xato: Faylni yozish uchun ochib boʻlmadi", // Str::WriteFileErrorMessage
    "Xato: Oʻn oltilik satrda belgilar soni juft boʻlishi kerak", // Str::HexStringErrorMessage
    "Xato: Satrda notoʻgʻri oʻn oltilik belgi bor", // Str::InvalidHexCharacterErrorMessage
    "Xato: Faylni saqlab boʻlmadi", // Str::SaveFileErrorMessage
    "Xato: Faylni yuklab boʻlmadi", // Str::LoadFileErrorMessage
    "Xato: Fayl formati notoʻgʻri (5 ta maydon kutilgan: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Xato: Iteratsiyalar soni belgilangan maksimumdan oshib ketdi (10 000 000)", // Str::MaxIterationsErrorMessage
    "Xato: Yaxlitlik tekshiruvi muvaffaqiyatsiz, parol notoʻgʻri yoki fayl buzilgan/oʻzgartirilgan", // Str::IntegrityCheckErrorMessage
    "Xato: Parol boʻsh boʻlishi mumkin emas", // Str::EmptyPasswordErrorMessage
    "Xato: Maqsad fayl yoʻli jild hisoblanadi", // Str::OutputFileIsDirectoryErrorMessage
    "Xato: Manba fayl yoʻli jild hisoblanadi", // Str::InputFileIsDirectoryErrorMessage
    "Xato: Maqsad fayl yoʻli boʻsh boʻlishi mumkin emas", // Str::EmptyOutputFilePathErrorMessage
    "Xato: Manba fayl yoʻli boʻsh boʻlishi mumkin emas", // Str::EmptyInputFilePathErrorMessage
    "Xato: Manba fayl mavjud emas", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Til: Oʻzbekcha", // Str::LanguageLabel
    "Parol", // Str::PasswordLabel
    "Parol uzunligi", // Str::PasswordLenghtLabel
    "Fayl", // Str::FileLabel
    "Fayl", // Str::TheFileLabel
    "Yoʻl", // Str::PathLabel
    "Kirish fayli yoʻli", // Str::InputFilePathLabel
    "Chiqish fayli yoʻli", // Str::OutputFilePathLabel
    "Yoʻllarni almashtirish", // Str::SwapPathsLabel
    "qayta yoziladi", // Str::WillBeOverwrittenLabel
    "Shifrlanmoqda...", // Str::EncryptingText
    "Shifr ochilmoqda...", // Str::DecryptingText
    "Shifrlash", // Str::EncryptText
    "Shifrni ochish", // Str::DecryptText
    "Fayl muvaffaqiyatli shifrlandi", // Str::FileEncryptedMessage
    "Fayl shifri muvaffaqiyatli ochildi", // Str::FileDecryptedMessage
    "Diqqat!", // Str::WarningTitle
    "Ishonchingiz komilmi?", // Str::AreYouSureTitle
    "Sozlamalar", // Str::SettingsTitle
    "Parol generatori", // Str::GeneratePasswordTitle
    "Tilni tanlang", // Str::SelectLanguageTitle
    "Ha", // Str::YesLabel
    "Yoʻq", // Str::NoLabel
    "OK", // Str::OkLabel
    "Chiqish formati", // Str::OutFormatLabel
    "Interfeys sozlamalari", // Str::InterfaceSettingsLabel
    "Oʻlcham", // Str::InterfaceSizeLabel
    "Rejim", // Str::ModeLabel
    "Oddiy", // Str::NormalModeLabel
    "Oddiy matn", // Str::PlaintextModeLabel
    "Mavzu", // Str::InterfaceThemeLabel
    "Rang", // Str::InterfaceColorLabel
    "Standart (oddiy matn)", // Str::DefaultLabel
    "OpenSSL (ikkilik)", // Str::OpenSSLLabel
    "Bu paroldan foydalanish", // Str::UsePasswordLabel
    "Nusxa olish", // Str::CopyLabel
    "SHA256 olish uchun Ctrl + chap tugmani bosing", // Str::GetSHA256Text
    // Themes
    "Yorugʻ", // Str::LightThemeName
    "Qorongʻi", // Str::DarkThemeName
    // Colors
    "Koʻk", // Str::BlueName
    "Zangori", // Str::CyanName
    "Yashil", // Str::GreenName
    "Laym rang", // Str::LimeName
    "Sariq", // Str::YellowName
    "Jigarrang", // Str::BrownName
    "Toʻq sariq", // Str::OrangeName
    "Qizil", // Str::RedName
    "Pushti", // Str::PinkName
    "Binafsha", // Str::PurpleName
    "Kulrang", // Str::GreyName
    "Oq", // Str::WhiteName
    "Qora", // Str::BlackName

};
static_assert(sizeof(textosUZ) / sizeof(textosUZ[0]) == N,
    "Faltan o sobran textos en uzbeko: revisa que coincidan con Str::Count.");

// Asụsụ Igbo (ig)
constexpr const char* textosIG[] = {

    
    
    // Info
    "Pịa Enter ka ị pụọ...", // Str::ExitInfoMessage
    "Gbanye naanị ma ọ bụrụ na ihe dị", // Str::PlainTextModeMessage_FirstLine
    "na faịlụ ahụ bụ ederede nkịtị", // Str::PlainTextModeMessage_SecondLine
    "A ga-echekwa faịlụ ezoro ezo", // Str::DefaultCipherModeText_FirstLine
    "dịka mkpụrụedemede enwere ike ibipụta", // Str::DefaultCipherModeText_SecondLine
    "A ga-echekwa faịlụ ezoro ezo n'ụdị", // Str::OpenSSLCipherModeText_FirstLine
    "binary, nke dabara na OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Ugboro PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Njehie: paramita ezighi ezi", // Str::WrongParamsText
    "Uru e tinyere", // Str::InputValueText
    "Ụzọ e tinyere", // Str::InputPathText
    "Enweghị ike ịgbanwe uru e tinyere ka ọ bụrụ nọmba karịrị 0 ma ọ bụ hà nhata 0", // Str::WrongNumberValueMessage
    "Ụzọ e tinyere adabaghị na faịlụ ọ bụla dị adị", // Str::WrongPathValueMessage
    "Amataghị nhọrọ e tinyere dịka paramita ziri ezi", // Str::InvalidOptionMessage
    "Nhọrọ e tinyere", // Str::EnteredOptionText
    "Njehie a na-amaghị", // Str::UnknownExceptionText
    "Ịmalite GLFW adaghị", // Str::GLFWErrorMessage
    "Ịmalite GLAD adaghị", // Str::GLADErrorMessage
    "Njehie: Enweghị ike imepe faịlụ ahụ maka ịgụ", // Str::ReadFileErrorMessage
    "Njehie mgbe a na-agụ ihe dị na faịlụ ahụ", // Str::ErrorWhileReadingMessage
    "Njehie: Enweghị ike imepe faịlụ ahụ maka ide", // Str::WriteFileErrorMessage
    "Njehie: Ọnụọgụ mkpụrụedemede dị n'usoro hexadecimal ga-abụrịrị ọnụọgụ a pụrụ ikewa abụọ", // Str::HexStringErrorMessage
    "Njehie: Mkpụrụedemede hexadecimal na-ezighi ezi dị n'usoro ahụ", // Str::InvalidHexCharacterErrorMessage
    "Njehie: Enweghị ike ichekwa faịlụ ahụ", // Str::SaveFileErrorMessage
    "Njehie: Enweghị ike ibugo faịlụ ahụ", // Str::LoadFileErrorMessage
    "Njehie: Ụdị faịlụ ezighi ezi (a tụrụ anya mpaghara 5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Njehie: Ọnụọgụ ugboro karịrị oke kachasị elu e debere (10,000,000)", // Str::MaxIterationsErrorMessage
    "Njehie: Nlele izu oke adaghị, okwuntughe ezighi ezi ma ọ bụ faịlụ mebiri emebi/a gbanwere ya", // Str::IntegrityCheckErrorMessage
    "Njehie: Okwuntughe enweghị ike ịbụ ihe efu", // Str::EmptyPasswordErrorMessage
    "Njehie: Ụzọ faịlụ ebe a na-aga bụ folda", // Str::OutputFileIsDirectoryErrorMessage
    "Njehie: Ụzọ faịlụ isi mmalite bụ folda", // Str::InputFileIsDirectoryErrorMessage
    "Njehie: Ụzọ faịlụ ebe a na-aga enweghị ike ịbụ ihe efu", // Str::EmptyOutputFilePathErrorMessage
    "Njehie: Ụzọ faịlụ isi mmalite enweghị ike ịbụ ihe efu", // Str::EmptyInputFilePathErrorMessage
    "Njehie: Faịlụ isi mmalite adịghị", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Asụsụ: Asụsụ Igbo", // Str::LanguageLabel
    "Okwuntughe", // Str::PasswordLabel
    "Ogologo okwuntughe", // Str::PasswordLenghtLabel
    "Faịlụ", // Str::FileLabel
    "Faịlụ", // Str::TheFileLabel
    "Ụzọ", // Str::PathLabel
    "Ụzọ faịlụ ntinye", // Str::InputFilePathLabel
    "Ụzọ faịlụ mwepụta", // Str::OutputFilePathLabel
    "Gbanwee ụzọ abụọ ahụ", // Str::SwapPathsLabel
    "a ga-ede ihe ọhụrụ n'elu ya", // Str::WillBeOverwrittenLabel
    "Na-ezo...", // Str::EncryptingText
    "Na-emepe nzuzo...", // Str::DecryptingText
    "Zochie", // Str::EncryptText
    "Mepee nzuzo", // Str::DecryptText
    "E zochiri faịlụ ahụ nke ọma", // Str::FileEncryptedMessage
    "E mepere nzuzo faịlụ ahụ nke ọma", // Str::FileDecryptedMessage
    "Ịdọ aka na ntị!", // Str::WarningTitle
    "Ị ji n'aka?", // Str::AreYouSureTitle
    "Ntọala", // Str::SettingsTitle
    "Ihe na-emepụta okwuntughe", // Str::GeneratePasswordTitle
    "Họrọ asụsụ", // Str::SelectLanguageTitle
    "Ee", // Str::YesLabel
    "Mba", // Str::NoLabel
    "Ọ dị mma", // Str::OkLabel
    "Ụdị mwepụta", // Str::OutFormatLabel
    "Ntọala ihu ngosi", // Str::InterfaceSettingsLabel
    "Nha", // Str::InterfaceSizeLabel
    "Ọnọdụ", // Str::ModeLabel
    "Nkịtị", // Str::NormalModeLabel
    "Ederede nkịtị", // Str::PlaintextModeLabel
    "Isiokwu", // Str::InterfaceThemeLabel
    "Agba", // Str::InterfaceColorLabel
    "Ndabara (ederede nkịtị)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Jiri okwuntughe a", // Str::UsePasswordLabel
    "Detuo", // Str::CopyLabel
    "Ctrl + pịa aka ekpe iji nweta SHA256", // Str::GetSHA256Text
    // Themes
    "Ìhè", // Str::LightThemeName
    "Ọchịchịrị", // Str::DarkThemeName
    // Colors
    "Acha anụnụ anụnụ", // Str::BlueName
    "Acha mmiri", // Str::CyanName
    "Akwụkwọ ndụ", // Str::GreenName
    "Akwụkwọ ndụ na-egbuke egbuke", // Str::LimeName
    "Odo", // Str::YellowName
    "Aja aja", // Str::BrownName
    "Oroma", // Str::OrangeName
    "Uhie", // Str::RedName
    "Pinki", // Str::PinkName
    "Pọpụl", // Str::PurpleName
    "Ntụ ntụ", // Str::GreyName
    "Ọcha", // Str::WhiteName
    "Oji", // Str::BlackName

};
static_assert(sizeof(textosIG) / sizeof(textosIG[0]) == N,
    "Faltan o sobran textos en igbo: revisa que coincidan con Str::Count.");

// isiZulu (zu)
constexpr const char* textosZU[] = {

    
    
    // Info
    "Cindezela u-Enter ukuze uphume...", // Str::ExitInfoMessage
    "Vula kuphela uma okuqukethwe yifayela", // Str::PlainTextModeMessage_FirstLine
    "kungumbhalo osobala", // Str::PlainTextModeMessage_SecondLine
    "Ifayela elibethelwe lizogcinwa", // Str::DefaultCipherModeText_FirstLine
    "njengezinhlamvu eziphrintekayo", // Str::DefaultCipherModeText_SecondLine
    "Ifayela elibethelwe lizogcinwa ngefomethi", // Str::OpenSSLCipherModeText_FirstLine
    "kanambambili, ehambisana ne-OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Ukuphindaphinda kwe-PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Iphutha: amapharamitha angalungile", // Str::WrongParamsText
    "Inani elitholiwe", // Str::InputValueText
    "Indlela etholiwe", // Str::InputPathText
    "Inani elitholiwe alikwazanga ukuguqulelwa enombolweni enkulu kuno-0 noma elingana no-0", // Str::WrongNumberValueMessage
    "Indlela etholiwe ayihambisani nanoma yiliphi ifayela elikhona", // Str::WrongPathValueMessage
    "Inketho efakiwe ayaziwa njengepharamitha evumelekile", // Str::InvalidOptionMessage
    "Inketho efakiwe", // Str::EnteredOptionText
    "Okuhlukile okungaziwa", // Str::UnknownExceptionText
    "Yehlulekile ukuqalisa i-GLFW", // Str::GLFWErrorMessage
    "Yehlulekile ukuqalisa i-GLAD", // Str::GLADErrorMessage
    "Iphutha: Ayikwazanga ukuvula ifayela ukuze lifundwe", // Str::ReadFileErrorMessage
    "Iphutha ngesikhathi kufundwa okuqukethwe yifayela", // Str::ErrorWhileReadingMessage
    "Iphutha: Ayikwazanga ukuvula ifayela ukuze kubhalwe kulo", // Str::WriteFileErrorMessage
    "Iphutha: Uchungechunge lwe-hexadecimal kumele lube nenani lezinhlamvu elihlukaniseka ngo-2", // Str::HexStringErrorMessage
    "Iphutha: Uhlamvu lwe-hexadecimal olungavumelekile kuchungechunge", // Str::InvalidHexCharacterErrorMessage
    "Iphutha: Ayikwazanga ukugcina ifayela", // Str::SaveFileErrorMessage
    "Iphutha: Ayikwazanga ukulayisha ifayela", // Str::LoadFileErrorMessage
    "Iphutha: Ifomethi yefayela engavumelekile (kulindeleke izinkambu ezi-5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Iphutha: Inani lokuphindaphinda lidlula umkhawulo omkhulu obekiwe (10 000 000)", // Str::MaxIterationsErrorMessage
    "Iphutha: Ukuqinisekiswa kobuqotho kwehlulekile, iphasiwedi engalungile noma ifayela elonakele/eliguquliwe", // Str::IntegrityCheckErrorMessage
    "Iphutha: Iphasiwedi ayikwazi ukungabi nalutho", // Str::EmptyPasswordErrorMessage
    "Iphutha: Indlela yefayela okuyiwa kulo iyifolda", // Str::OutputFileIsDirectoryErrorMessage
    "Iphutha: Indlela yefayela lomthombo iyifolda", // Str::InputFileIsDirectoryErrorMessage
    "Iphutha: Indlela yefayela okuyiwa kulo ayikwazi ukungabi nalutho", // Str::EmptyOutputFilePathErrorMessage
    "Iphutha: Indlela yefayela lomthombo ayikwazi ukungabi nalutho", // Str::EmptyInputFilePathErrorMessage
    "Iphutha: Ifayela lomthombo alikho", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Ulimi: isiZulu", // Str::LanguageLabel
    "Iphasiwedi", // Str::PasswordLabel
    "Ubude bephasiwedi", // Str::PasswordLenghtLabel
    "Ifayela", // Str::FileLabel
    "Ifayela", // Str::TheFileLabel
    "Indlela", // Str::PathLabel
    "Indlela yefayela lokufaka", // Str::InputFilePathLabel
    "Indlela yefayela lokukhipha", // Str::OutputFilePathLabel
    "Shintshanisa izindlela", // Str::SwapPathsLabel
    "lizobhalwa phezu kwalo", // Str::WillBeOverwrittenLabel
    "Iyabethela...", // Str::EncryptingText
    "Isusa ukubethela...", // Str::DecryptingText
    "Bethela", // Str::EncryptText
    "Susa ukubethela", // Str::DecryptText
    "Ifayela libethelwe ngempumelelo", // Str::FileEncryptedMessage
    "Ukubethela kwefayela kususwe ngempumelelo", // Str::FileDecryptedMessage
    "Isexwayiso!", // Str::WarningTitle
    "Uqinisekile?", // Str::AreYouSureTitle
    "Izilungiselelo", // Str::SettingsTitle
    "Ijeneretha yephasiwedi", // Str::GeneratePasswordTitle
    "Khetha ulimi", // Str::SelectLanguageTitle
    "Yebo", // Str::YesLabel
    "Cha", // Str::NoLabel
    "Kulungile", // Str::OkLabel
    "Ifomethi yokukhipha", // Str::OutFormatLabel
    "Izilungiselelo zesixhumi esibonakalayo", // Str::InterfaceSettingsLabel
    "Usayizi", // Str::InterfaceSizeLabel
    "Imodi", // Str::ModeLabel
    "Okujwayelekile", // Str::NormalModeLabel
    "Umbhalo osobala", // Str::PlaintextModeLabel
    "Itimu", // Str::InterfaceThemeLabel
    "Umbala", // Str::InterfaceColorLabel
    "Okuzenzakalelayo (umbhalo osobala)", // Str::DefaultLabel
    "OpenSSL (kanambambili)", // Str::OpenSSLLabel
    "Sebenzisa le phasiwedi", // Str::UsePasswordLabel
    "Kopisha", // Str::CopyLabel
    "Ctrl + chofoza kwesobunxele ukuze uthole i-SHA256", // Str::GetSHA256Text
    // Themes
    "Ekhanyayo", // Str::LightThemeName
    "Emnyama", // Str::DarkThemeName
    // Colors
    "Okwesibhakabhaka", // Str::BlueName
    "Siyani", // Str::CyanName
    "Okotshani", // Str::GreenName
    "Okwelamula", // Str::LimeName
    "Phuzi", // Str::YellowName
    "Nsundu", // Str::BrownName
    "Olintshi", // Str::OrangeName
    "Bomvu", // Str::RedName
    "Phinki", // Str::PinkName
    "Nsomi", // Str::PurpleName
    "Mpunga", // Str::GreyName
    "Mhlophe", // Str::WhiteName
    "Mnyama", // Str::BlackName

};
static_assert(sizeof(textosZU) / sizeof(textosZU[0]) == N,
    "Faltan o sobran textos en zulu: revisa que coincidan con Str::Count.");

// Cebuano (ceb)
constexpr const char* textosCEB[] = {

    
    
    // Info
    "Pindota ang Enter aron mogawas...", // Str::ExitInfoMessage
    "I-enable lang kung ang sulod", // Str::PlainTextModeMessage_FirstLine
    "sa file kay plain text", // Str::PlainTextModeMessage_SecondLine
    "Ang na-encrypt nga file i-save", // Str::DefaultCipherModeText_FirstLine
    "isip mga karakter nga ma-print", // Str::DefaultCipherModeText_SecondLine
    "Ang na-encrypt nga file i-save sa", // Str::OpenSSLCipherModeText_FirstLine
    "binary nga format, compatible sa OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Mga iteration sa PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Sayop: dili husto nga mga parameter", // Str::WrongParamsText
    "Gibutang nga bili", // Str::InputValueText
    "Gibutang nga path", // Str::InputPathText
    "Dili ma-convert ang gibutang nga bili ngadto sa numero nga labaw o parehas sa 0", // Str::WrongNumberValueMessage
    "Ang gibutang nga path dili katugbang sa bisan unsang naglungtad nga file", // Str::WrongPathValueMessage
    "Ang gibutang nga opsyon wala mailhi isip balido nga parameter", // Str::InvalidOptionMessage
    "Gibutang nga opsyon", // Str::EnteredOptionText
    "Wala mailhi nga exception", // Str::UnknownExceptionText
    "Napakyas sa pag-initialize sa GLFW", // Str::GLFWErrorMessage
    "Napakyas sa pag-initialize sa GLAD", // Str::GLADErrorMessage
    "Sayop: Dili maablihan ang file aron basahon", // Str::ReadFileErrorMessage
    "Sayop samtang gibasa ang sulod sa file", // Str::ErrorWhileReadingMessage
    "Sayop: Dili maablihan ang file aron sulatan", // Str::WriteFileErrorMessage
    "Sayop: Ang hex string kinahanglan adunay pares nga gidaghanon sa karakter", // Str::HexStringErrorMessage
    "Sayop: Dili balido nga hex nga karakter sa string", // Str::InvalidHexCharacterErrorMessage
    "Sayop: Dili ma-save ang file", // Str::SaveFileErrorMessage
    "Sayop: Dili ma-load ang file", // Str::LoadFileErrorMessage
    "Sayop: Dili balido nga format sa file (gipaabot ang 5 ka field: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Sayop: Ang gidaghanon sa iteration milapas sa gitakdang maximum (10,000,000)", // Str::MaxIterationsErrorMessage
    "Sayop: Napakyas ang pag-verify sa integridad, sayop nga password o guba/giusab nga file", // Str::IntegrityCheckErrorMessage
    "Sayop: Ang password dili mahimong walay sulod", // Str::EmptyPasswordErrorMessage
    "Sayop: Ang path sa destinasyon nga file usa ka direktoryo", // Str::OutputFileIsDirectoryErrorMessage
    "Sayop: Ang path sa tinubdan nga file usa ka direktoryo", // Str::InputFileIsDirectoryErrorMessage
    "Sayop: Ang path sa destinasyon nga file dili mahimong walay sulod", // Str::EmptyOutputFilePathErrorMessage
    "Sayop: Ang path sa tinubdan nga file dili mahimong walay sulod", // Str::EmptyInputFilePathErrorMessage
    "Sayop: Ang tinubdan nga file wala maglungtad", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Pinulongan: Cebuano", // Str::LanguageLabel
    "Password", // Str::PasswordLabel
    "Gitas-on sa password", // Str::PasswordLenghtLabel
    "File", // Str::FileLabel
    "Ang file nga", // Str::TheFileLabel
    "Path", // Str::PathLabel
    "Path sa input nga file", // Str::InputFilePathLabel
    "Path sa output nga file", // Str::OutputFilePathLabel
    "Ilisan ang mga path", // Str::SwapPathsLabel
    "ma-overwrite", // Str::WillBeOverwrittenLabel
    "Nag-encrypt...", // Str::EncryptingText
    "Nag-decrypt...", // Str::DecryptingText
    "I-encrypt", // Str::EncryptText
    "I-decrypt", // Str::DecryptText
    "Malampusong na-encrypt ang file", // Str::FileEncryptedMessage
    "Malampusong na-decrypt ang file", // Str::FileDecryptedMessage
    "Pasidaan!", // Str::WarningTitle
    "Sigurado ka ba?", // Str::AreYouSureTitle
    "Mga Setting", // Str::SettingsTitle
    "Tighimo og password", // Str::GeneratePasswordTitle
    "Pilia ang pinulongan", // Str::SelectLanguageTitle
    "Oo", // Str::YesLabel
    "Dili", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format sa output", // Str::OutFormatLabel
    "Mga setting sa interface", // Str::InterfaceSettingsLabel
    "Gidak-on", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Plain text", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Kolor", // Str::InterfaceColorLabel
    "Default (plain text)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Gamita kini nga password", // Str::UsePasswordLabel
    "Kopyaha", // Str::CopyLabel
    "Ctrl + wala nga klik aron makuha ang SHA256", // Str::GetSHA256Text
    // Themes
    "Hayag", // Str::LightThemeName
    "Ngitngit", // Str::DarkThemeName
    // Colors
    "Asul", // Str::BlueName
    "Cyan", // Str::CyanName
    "Berde", // Str::GreenName
    "Lime", // Str::LimeName
    "Dalag", // Str::YellowName
    "Kape", // Str::BrownName
    "Kahel", // Str::OrangeName
    "Pula", // Str::RedName
    "Rosas", // Str::PinkName
    "Lila", // Str::PurpleName
    "Abuhon", // Str::GreyName
    "Puti", // Str::WhiteName
    "Itom", // Str::BlackName

};
static_assert(sizeof(textosCEB) / sizeof(textosCEB[0]) == N,
    "Faltan o sobran textos en cebuano: revisa que coincidan con Str::Count.");

// Nederlands (nl)
constexpr const char* textosNL[] = {

    
    
    // Info
    "Druk op Enter om af te sluiten...", // Str::ExitInfoMessage
    "Alleen inschakelen als de inhoud", // Str::PlainTextModeMessage_FirstLine
    "van het bestand platte tekst is", // Str::PlainTextModeMessage_SecondLine
    "Het versleutelde bestand wordt", // Str::DefaultCipherModeText_FirstLine
    "opgeslagen als afdrukbare tekens", // Str::DefaultCipherModeText_SecondLine
    "Het versleutelde bestand wordt opgeslagen", // Str::OpenSSLCipherModeText_FirstLine
    "in binair formaat, compatibel met OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-iteraties:", // Str::PBKDF2IterationsText
    // Errors
    "Fout: onjuiste parameters", // Str::WrongParamsText
    "Ontvangen waarde", // Str::InputValueText
    "Ontvangen pad", // Str::InputPathText
    "De ontvangen waarde kon niet worden omgezet in een getal groter dan of gelijk aan 0", // Str::WrongNumberValueMessage
    "Het ontvangen pad komt niet overeen met een bestaand bestand", // Str::WrongPathValueMessage
    "De ingevoerde optie wordt niet herkend als een geldige parameter", // Str::InvalidOptionMessage
    "Ingevoerde optie", // Str::EnteredOptionText
    "Onbekende uitzondering", // Str::UnknownExceptionText
    "Kan GLFW niet initialiseren", // Str::GLFWErrorMessage
    "Kan GLAD niet initialiseren", // Str::GLADErrorMessage
    "Fout: kan het bestand niet openen om te lezen", // Str::ReadFileErrorMessage
    "Fout bij het lezen van de bestandsinhoud", // Str::ErrorWhileReadingMessage
    "Fout: kan het bestand niet openen om te schrijven", // Str::WriteFileErrorMessage
    "Fout: de hexadecimale tekenreeks moet een even aantal tekens bevatten", // Str::HexStringErrorMessage
    "Fout: ongeldig hexadecimaal teken in de tekenreeks", // Str::InvalidHexCharacterErrorMessage
    "Fout: kan het bestand niet opslaan", // Str::SaveFileErrorMessage
    "Fout: kan het bestand niet laden", // Str::LoadFileErrorMessage
    "Fout: ongeldig bestandsformaat (5 velden verwacht: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Fout: het aantal iteraties overschrijdt het vastgestelde maximum (10.000.000)", // Str::MaxIterationsErrorMessage
    "Fout: integriteitscontrole mislukt, onjuist wachtwoord of beschadigd/gemanipuleerd bestand", // Str::IntegrityCheckErrorMessage
    "Fout: het wachtwoord mag niet leeg zijn", // Str::EmptyPasswordErrorMessage
    "Fout: het pad van het doelbestand is een map", // Str::OutputFileIsDirectoryErrorMessage
    "Fout: het pad van het bronbestand is een map", // Str::InputFileIsDirectoryErrorMessage
    "Fout: het pad van het doelbestand mag niet leeg zijn", // Str::EmptyOutputFilePathErrorMessage
    "Fout: het pad van het bronbestand mag niet leeg zijn", // Str::EmptyInputFilePathErrorMessage
    "Fout: het bronbestand bestaat niet", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Taal: Nederlands", // Str::LanguageLabel
    "Wachtwoord", // Str::PasswordLabel
    "Wachtwoordlengte", // Str::PasswordLenghtLabel
    "Bestand", // Str::FileLabel
    "Het bestand", // Str::TheFileLabel
    "Pad", // Str::PathLabel
    "Invoerpad", // Str::InputFilePathLabel
    "Uitvoerpad", // Str::OutputFilePathLabel
    "Paden omwisselen", // Str::SwapPathsLabel
    "wordt overschreven", // Str::WillBeOverwrittenLabel
    "Bezig met versleutelen...", // Str::EncryptingText
    "Bezig met ontsleutelen...", // Str::DecryptingText
    "Versleutelen", // Str::EncryptText
    "Ontsleutelen", // Str::DecryptText
    "Bestand succesvol versleuteld", // Str::FileEncryptedMessage
    "Bestand succesvol ontsleuteld", // Str::FileDecryptedMessage
    "Waarschuwing!", // Str::WarningTitle
    "Weet je het zeker?", // Str::AreYouSureTitle
    "Instellingen", // Str::SettingsTitle
    "Wachtwoordgenerator", // Str::GeneratePasswordTitle
    "Taal selecteren", // Str::SelectLanguageTitle
    "Ja", // Str::YesLabel
    "Nee", // Str::NoLabel
    "OK", // Str::OkLabel
    "Uitvoerformaat", // Str::OutFormatLabel
    "Interface-instellingen", // Str::InterfaceSettingsLabel
    "Grootte", // Str::InterfaceSizeLabel
    "Modus", // Str::ModeLabel
    "Normaal", // Str::NormalModeLabel
    "Platte tekst", // Str::PlaintextModeLabel
    "Thema", // Str::InterfaceThemeLabel
    "Kleur", // Str::InterfaceColorLabel
    "Standaard (platte tekst)", // Str::DefaultLabel
    "OpenSSL (binair)", // Str::OpenSSLLabel
    "Dit wachtwoord gebruiken", // Str::UsePasswordLabel
    "Kopiëren", // Str::CopyLabel
    "Ctrl + linkermuisklik om SHA256 te krijgen", // Str::GetSHA256Text
    // Themes
    "Licht", // Str::LightThemeName
    "Donker", // Str::DarkThemeName
    // Colors
    "Blauw", // Str::BlueName
    "Cyaan", // Str::CyanName
    "Groen", // Str::GreenName
    "Limoengroen", // Str::LimeName
    "Geel", // Str::YellowName
    "Bruin", // Str::BrownName
    "Oranje", // Str::OrangeName
    "Rood", // Str::RedName
    "Roze", // Str::PinkName
    "Paars", // Str::PurpleName
    "Grijs", // Str::GreyName
    "Wit", // Str::WhiteName
    "Zwart", // Str::BlackName

};
static_assert(sizeof(textosNL) / sizeof(textosNL[0]) == N,
    "Faltan o sobran textos en neerlandes: revisa que coincidan con Str::Count.");

// Malagasy (mg)
constexpr const char* textosMG[] = {

    
    
    // Info
    "Tsindrio Enter raha hivoaka...", // Str::ExitInfoMessage
    "Alefaso raha soratra tsotra ihany", // Str::PlainTextModeMessage_FirstLine
    "no ao anatin'ny rakitra", // Str::PlainTextModeMessage_SecondLine
    "Ny rakitra voaafina dia hotehirizina", // Str::DefaultCipherModeText_FirstLine
    "ho litera azo atonta", // Str::DefaultCipherModeText_SecondLine
    "Ny rakitra voaafina dia hotehirizina", // Str::OpenSSLCipherModeText_FirstLine
    "ho binary, mifanaraka amin'ny OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Famerimberenana PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Hadisoana: masontsivana tsy marina", // Str::WrongParamsText
    "Sanda nampidirina", // Str::InputValueText
    "Lalana nampidirina", // Str::InputPathText
    "Tsy azo navadika ho isa lehibe noho na mitovy amin'ny 0 ilay sanda nampidirina", // Str::WrongNumberValueMessage
    "Tsy mifanaraka amin'ny rakitra misy ilay lalana nampidirina", // Str::WrongPathValueMessage
    "Tsy fantatra ho masontsivana manan-kery ilay safidy nampidirina", // Str::InvalidOptionMessage
    "Safidy nampidirina", // Str::EnteredOptionText
    "Hadisoana tsy fantatra", // Str::UnknownExceptionText
    "Tsy nahomby ny fanombohana ny GLFW", // Str::GLFWErrorMessage
    "Tsy nahomby ny fanombohana ny GLAD", // Str::GLADErrorMessage
    "Hadisoana: Tsy afaka nanokatra ilay rakitra hovakiana", // Str::ReadFileErrorMessage
    "Nisy hadisoana teo am-pamakiana ny votoatin'ny rakitra", // Str::ErrorWhileReadingMessage
    "Hadisoana: Tsy afaka nanokatra ilay rakitra hanoratana", // Str::WriteFileErrorMessage
    "Hadisoana: Tsy maintsy ho isa tsiroaroa ny isan'ny litera ao amin'ny tady hexadecimal", // Str::HexStringErrorMessage
    "Hadisoana: Misy litera hexadecimal tsy mety ao amin'ny tady", // Str::InvalidHexCharacterErrorMessage
    "Hadisoana: Tsy afaka nitahiry ilay rakitra", // Str::SaveFileErrorMessage
    "Hadisoana: Tsy afaka nampiditra ilay rakitra", // Str::LoadFileErrorMessage
    "Hadisoana: Endrika rakitra tsy mety (saha 5 no andrasana: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Hadisoana: Mihoatra ny fetra ambony voafaritra ny isan'ny famerimberenana (10 000 000)", // Str::MaxIterationsErrorMessage
    "Hadisoana: Tsy nahomby ny fanamarinana ny fahatanterahana, diso ny teny miafina na simba/novaina ny rakitra", // Str::IntegrityCheckErrorMessage
    "Hadisoana: Tsy azo atao foana ny teny miafina", // Str::EmptyPasswordErrorMessage
    "Hadisoana: Lahatahiry ny lalan'ny rakitra tanjona", // Str::OutputFileIsDirectoryErrorMessage
    "Hadisoana: Lahatahiry ny lalan'ny rakitra loharano", // Str::InputFileIsDirectoryErrorMessage
    "Hadisoana: Tsy azo atao foana ny lalan'ny rakitra tanjona", // Str::EmptyOutputFilePathErrorMessage
    "Hadisoana: Tsy azo atao foana ny lalan'ny rakitra loharano", // Str::EmptyInputFilePathErrorMessage
    "Hadisoana: Tsy misy ilay rakitra loharano", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Fiteny: Malagasy", // Str::LanguageLabel
    "Teny miafina", // Str::PasswordLabel
    "Halavan'ny teny miafina", // Str::PasswordLenghtLabel
    "Rakitra", // Str::FileLabel
    "Ilay rakitra", // Str::TheFileLabel
    "Lalana", // Str::PathLabel
    "Lalan'ny rakitra fidirana", // Str::InputFilePathLabel
    "Lalan'ny rakitra fivoahana", // Str::OutputFilePathLabel
    "Afamadiho ny lalana", // Str::SwapPathsLabel
    "dia hosoloina", // Str::WillBeOverwrittenLabel
    "Manafina...", // Str::EncryptingText
    "Manaisotra ny fanafenana...", // Str::DecryptingText
    "Afeno", // Str::EncryptText
    "Esory ny fanafenana", // Str::DecryptText
    "Voaafina soa aman-tsara ny rakitra", // Str::FileEncryptedMessage
    "Voaesotra soa aman-tsara ny fanafenana ny rakitra", // Str::FileDecryptedMessage
    "Fampitandremana!", // Str::WarningTitle
    "Azonao antoka ve?", // Str::AreYouSureTitle
    "Fikirana", // Str::SettingsTitle
    "Mpamorona teny miafina", // Str::GeneratePasswordTitle
    "Safidio ny fiteny", // Str::SelectLanguageTitle
    "Eny", // Str::YesLabel
    "Tsia", // Str::NoLabel
    "OK", // Str::OkLabel
    "Endrika fivoahana", // Str::OutFormatLabel
    "Fikirana ny endrika", // Str::InterfaceSettingsLabel
    "Habe", // Str::InterfaceSizeLabel
    "Fomba", // Str::ModeLabel
    "Mahazatra", // Str::NormalModeLabel
    "Soratra tsotra", // Str::PlaintextModeLabel
    "Lohahevitra", // Str::InterfaceThemeLabel
    "Loko", // Str::InterfaceColorLabel
    "Fototra (soratra tsotra)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Ampiasao ity teny miafina ity", // Str::UsePasswordLabel
    "Adikao", // Str::CopyLabel
    "Ctrl + tsindry havia mba hahazoana ny SHA256", // Str::GetSHA256Text
    // Themes
    "Mazava", // Str::LightThemeName
    "Maizina", // Str::DarkThemeName
    // Colors
    "Manga", // Str::BlueName
    "Manga mazava", // Str::CyanName
    "Maitso", // Str::GreenName
    "Maitso mazava", // Str::LimeName
    "Mavo", // Str::YellowName
    "Volontany", // Str::BrownName
    "Volom-boasary", // Str::OrangeName
    "Mena", // Str::RedName
    "Mavokely", // Str::PinkName
    "Volomparasy", // Str::PurpleName
    "Volondavenona", // Str::GreyName
    "Fotsy", // Str::WhiteName
    "Mainty", // Str::BlackName

};
static_assert(sizeof(textosMG) / sizeof(textosMG[0]) == N,
    "Faltan o sobran textos en malgache: revisa que coincidan con Str::Count.");

// Română (ro)
constexpr const char* textosRO[] = {

    
    
    // Info
    "Apăsați Enter pentru a ieși...", // Str::ExitInfoMessage
    "Activați doar dacă fișierul", // Str::PlainTextModeMessage_FirstLine
    "conține text simplu", // Str::PlainTextModeMessage_SecondLine
    "Fișierul criptat va fi salvat", // Str::DefaultCipherModeText_FirstLine
    "sub formă de caractere imprimabile", // Str::DefaultCipherModeText_SecondLine
    "Fișierul criptat va fi salvat în", // Str::OpenSSLCipherModeText_FirstLine
    "format binar, compatibil cu OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterații PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Eroare: parametri incorecți", // Str::WrongParamsText
    "Valoare primită", // Str::InputValueText
    "Cale primită", // Str::InputPathText
    "Valoarea primită nu a putut fi convertită într-un număr mai mare sau egal cu 0", // Str::WrongNumberValueMessage
    "Calea primită nu corespunde niciunui fișier existent", // Str::WrongPathValueMessage
    "Opțiunea introdusă nu este recunoscută ca parametru valid", // Str::InvalidOptionMessage
    "Opțiune introdusă", // Str::EnteredOptionText
    "Excepție necunoscută", // Str::UnknownExceptionText
    "Inițializarea GLFW a eșuat", // Str::GLFWErrorMessage
    "Inițializarea GLAD a eșuat", // Str::GLADErrorMessage
    "Eroare: fișierul nu a putut fi deschis pentru citire", // Str::ReadFileErrorMessage
    "Eroare la citirea conținutului fișierului", // Str::ErrorWhileReadingMessage
    "Eroare: fișierul nu a putut fi deschis pentru scriere", // Str::WriteFileErrorMessage
    "Eroare: șirul hexazecimal trebuie să aibă un număr par de caractere", // Str::HexStringErrorMessage
    "Eroare: caracter hexazecimal nevalid în șir", // Str::InvalidHexCharacterErrorMessage
    "Eroare: fișierul nu a putut fi salvat", // Str::SaveFileErrorMessage
    "Eroare: fișierul nu a putut fi încărcat", // Str::LoadFileErrorMessage
    "Eroare: format de fișier nevalid (se așteptau 5 câmpuri: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Eroare: numărul de iterații depășește maximul stabilit (10.000.000)", // Str::MaxIterationsErrorMessage
    "Eroare: verificarea integrității a eșuat, parolă incorectă sau fișier corupt/modificat", // Str::IntegrityCheckErrorMessage
    "Eroare: parola nu poate fi goală", // Str::EmptyPasswordErrorMessage
    "Eroare: calea fișierului de destinație este un director", // Str::OutputFileIsDirectoryErrorMessage
    "Eroare: calea fișierului sursă este un director", // Str::InputFileIsDirectoryErrorMessage
    "Eroare: calea fișierului de destinație nu poate fi goală", // Str::EmptyOutputFilePathErrorMessage
    "Eroare: calea fișierului sursă nu poate fi goală", // Str::EmptyInputFilePathErrorMessage
    "Eroare: fișierul sursă nu există", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Limbă: Română", // Str::LanguageLabel
    "Parolă", // Str::PasswordLabel
    "Lungimea parolei", // Str::PasswordLenghtLabel
    "Fișier", // Str::FileLabel
    "Fișierul", // Str::TheFileLabel
    "Cale", // Str::PathLabel
    "Cale de intrare", // Str::InputFilePathLabel
    "Cale de ieșire", // Str::OutputFilePathLabel
    "Inversează căile", // Str::SwapPathsLabel
    "va fi suprascris", // Str::WillBeOverwrittenLabel
    "Se criptează...", // Str::EncryptingText
    "Se decriptează...", // Str::DecryptingText
    "Criptează", // Str::EncryptText
    "Decriptează", // Str::DecryptText
    "Fișier criptat cu succes", // Str::FileEncryptedMessage
    "Fișier decriptat cu succes", // Str::FileDecryptedMessage
    "Atenție!", // Str::WarningTitle
    "Sunteți sigur?", // Str::AreYouSureTitle
    "Setări", // Str::SettingsTitle
    "Generator de parole", // Str::GeneratePasswordTitle
    "Selectați limba", // Str::SelectLanguageTitle
    "Da", // Str::YesLabel
    "Nu", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format de ieșire", // Str::OutFormatLabel
    "Setări interfață", // Str::InterfaceSettingsLabel
    "Dimensiune", // Str::InterfaceSizeLabel
    "Mod", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Text simplu", // Str::PlaintextModeLabel
    "Temă", // Str::InterfaceThemeLabel
    "Culoare", // Str::InterfaceColorLabel
    "Implicit (text simplu)", // Str::DefaultLabel
    "OpenSSL (binar)", // Str::OpenSSLLabel
    "Folosește această parolă", // Str::UsePasswordLabel
    "Copiază", // Str::CopyLabel
    "Ctrl + clic stânga pentru a obține SHA256", // Str::GetSHA256Text
    // Themes
    "Luminoasă", // Str::LightThemeName
    "Întunecată", // Str::DarkThemeName
    // Colors
    "Albastru", // Str::BlueName
    "Cyan", // Str::CyanName
    "Verde", // Str::GreenName
    "Verde lime", // Str::LimeName
    "Galben", // Str::YellowName
    "Maro", // Str::BrownName
    "Portocaliu", // Str::OrangeName
    "Roșu", // Str::RedName
    "Roz", // Str::PinkName
    "Mov", // Str::PurpleName
    "Gri", // Str::GreyName
    "Alb", // Str::WhiteName
    "Negru", // Str::BlackName

};
static_assert(sizeof(textosRO) / sizeof(textosRO[0]) == N,
    "Faltan o sobran textos en rumano: revisa que coincidan con Str::Count.");

// Azərbaycanca (az)
constexpr const char* textosAZ[] = {

    
    
    // Info
    "Çıxmaq üçün Enter düyməsini basın...", // Str::ExitInfoMessage
    "Yalnız faylın məzmunu sadə mətn", // Str::PlainTextModeMessage_FirstLine
    "olduqda aktivləşdirin", // Str::PlainTextModeMessage_SecondLine
    "Şifrələnmiş fayl çap edilə bilən", // Str::DefaultCipherModeText_FirstLine
    "simvollar kimi saxlanılacaq", // Str::DefaultCipherModeText_SecondLine
    "Şifrələnmiş fayl OpenSSL ilə uyğun", // Str::OpenSSLCipherModeText_FirstLine
    "ikili formatda saxlanılacaq", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 iterasiyaları:", // Str::PBKDF2IterationsText
    // Errors
    "Xəta: yanlış parametrlər", // Str::WrongParamsText
    "Daxil edilən dəyər", // Str::InputValueText
    "Daxil edilən yol", // Str::InputPathText
    "Daxil edilən dəyəri 0-dan böyük və ya 0-a bərabər ədədə çevirmək mümkün olmadı", // Str::WrongNumberValueMessage
    "Daxil edilən yol mövcud heç bir fayla uyğun gəlmir", // Str::WrongPathValueMessage
    "Daxil edilən seçim etibarlı parametr kimi tanınmadı", // Str::InvalidOptionMessage
    "Daxil edilən seçim", // Str::EnteredOptionText
    "Naməlum istisna", // Str::UnknownExceptionText
    "GLFW işə salına bilmədi", // Str::GLFWErrorMessage
    "GLAD işə salına bilmədi", // Str::GLADErrorMessage
    "Xəta: Faylı oxumaq üçün açmaq mümkün olmadı", // Str::ReadFileErrorMessage
    "Faylın məzmunu oxunarkən xəta baş verdi", // Str::ErrorWhileReadingMessage
    "Xəta: Faylı yazmaq üçün açmaq mümkün olmadı", // Str::WriteFileErrorMessage
    "Xəta: Onaltılıq sətirdə simvolların sayı cüt olmalıdır", // Str::HexStringErrorMessage
    "Xəta: Sətirdə yanlış onaltılıq simvol var", // Str::InvalidHexCharacterErrorMessage
    "Xəta: Faylı saxlamaq mümkün olmadı", // Str::SaveFileErrorMessage
    "Xəta: Faylı yükləmək mümkün olmadı", // Str::LoadFileErrorMessage
    "Xəta: Yanlış fayl formatı (5 sahə gözlənilirdi: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Xəta: İterasiyaların sayı müəyyən edilmiş maksimumu keçir (10.000.000)", // Str::MaxIterationsErrorMessage
    "Xəta: Bütövlük yoxlaması uğursuz oldu, yanlış parol və ya zədələnmiş/dəyişdirilmiş fayl", // Str::IntegrityCheckErrorMessage
    "Xəta: Parol boş ola bilməz", // Str::EmptyPasswordErrorMessage
    "Xəta: Təyinat faylının yolu qovluqdur", // Str::OutputFileIsDirectoryErrorMessage
    "Xəta: Mənbə faylının yolu qovluqdur", // Str::InputFileIsDirectoryErrorMessage
    "Xəta: Təyinat faylının yolu boş ola bilməz", // Str::EmptyOutputFilePathErrorMessage
    "Xəta: Mənbə faylının yolu boş ola bilməz", // Str::EmptyInputFilePathErrorMessage
    "Xəta: Mənbə faylı mövcud deyil", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Dil: Azərbaycanca", // Str::LanguageLabel
    "Parol", // Str::PasswordLabel
    "Parolun uzunluğu", // Str::PasswordLenghtLabel
    "Fayl", // Str::FileLabel
    "Fayl", // Str::TheFileLabel
    "Yol", // Str::PathLabel
    "Giriş faylının yolu", // Str::InputFilePathLabel
    "Çıxış faylının yolu", // Str::OutputFilePathLabel
    "Yolların yerini dəyiş", // Str::SwapPathsLabel
    "üzərinə yazılacaq", // Str::WillBeOverwrittenLabel
    "Şifrələnir...", // Str::EncryptingText
    "Şifrə açılır...", // Str::DecryptingText
    "Şifrələ", // Str::EncryptText
    "Şifrəni aç", // Str::DecryptText
    "Fayl uğurla şifrələndi", // Str::FileEncryptedMessage
    "Faylın şifrəsi uğurla açıldı", // Str::FileDecryptedMessage
    "Xəbərdarlıq!", // Str::WarningTitle
    "Əminsiniz?", // Str::AreYouSureTitle
    "Parametrlər", // Str::SettingsTitle
    "Parol generatoru", // Str::GeneratePasswordTitle
    "Dil seçin", // Str::SelectLanguageTitle
    "Bəli", // Str::YesLabel
    "Xeyr", // Str::NoLabel
    "OK", // Str::OkLabel
    "Çıxış formatı", // Str::OutFormatLabel
    "İnterfeys parametrləri", // Str::InterfaceSettingsLabel
    "Ölçü", // Str::InterfaceSizeLabel
    "Rejim", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Sadə mətn", // Str::PlaintextModeLabel
    "Mövzu", // Str::InterfaceThemeLabel
    "Rəng", // Str::InterfaceColorLabel
    "Defolt (sadə mətn)", // Str::DefaultLabel
    "OpenSSL (ikili)", // Str::OpenSSLLabel
    "Bu paroldan istifadə et", // Str::UsePasswordLabel
    "Kopyala", // Str::CopyLabel
    "SHA256 almaq üçün Ctrl + sol klik edin", // Str::GetSHA256Text
    // Themes
    "Açıq", // Str::LightThemeName
    "Tünd", // Str::DarkThemeName
    // Colors
    "Mavi", // Str::BlueName
    "Firuzəyi", // Str::CyanName
    "Yaşıl", // Str::GreenName
    "Laym yaşılı", // Str::LimeName
    "Sarı", // Str::YellowName
    "Qəhvəyi", // Str::BrownName
    "Narıncı", // Str::OrangeName
    "Qırmızı", // Str::RedName
    "Çəhrayı", // Str::PinkName
    "Bənövşəyi", // Str::PurpleName
    "Boz", // Str::GreyName
    "Ağ", // Str::WhiteName
    "Qara", // Str::BlackName

};
static_assert(sizeof(textosAZ) / sizeof(textosAZ[0]) == N,
    "Faltan o sobran textos en azeri: revisa que coincidan con Str::Count.");

// Soomaali (so)
constexpr const char* textosSO[] = {

    
    
    // Info
    "Riix Enter si aad uga baxdo...", // Str::ExitInfoMessage
    "Daar keliya haddii waxa ku jira", // Str::PlainTextModeMessage_FirstLine
    "faylku yahay qoraal caadi ah", // Str::PlainTextModeMessage_SecondLine
    "Faylka la qariyay waxaa loo kaydin doonaa", // Str::DefaultCipherModeText_FirstLine
    "sidii xarfo la daabici karo", // Str::DefaultCipherModeText_SecondLine
    "Faylka la qariyay waxaa loo kaydin doonaa", // Str::OpenSSLCipherModeText_FirstLine
    "qaab binary ah oo la jaanqaada OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Ku celcelinta PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Khalad: halbeegyo khaldan", // Str::WrongParamsText
    "Qiimaha la galiyay", // Str::InputValueText
    "Dariiqa la galiyay", // Str::InputPathText
    "Qiimaha la galiyay looma beddeli karin tiro ka weyn ama la mid ah 0", // Str::WrongNumberValueMessage
    "Dariiqa la galiyay kuma aaddana fayl jira", // Str::WrongPathValueMessage
    "Doorashada la galiyay looma aqoonsan halbeeg sax ah", // Str::InvalidOptionMessage
    "Doorashada la galiyay", // Str::EnteredOptionText
    "Khalad aan la aqoon", // Str::UnknownExceptionText
    "Bilaabidda GLFW way fashilantay", // Str::GLFWErrorMessage
    "Bilaabidda GLAD way fashilantay", // Str::GLADErrorMessage
    "Khalad: Faylka lama furi karo si loo akhriyo", // Str::ReadFileErrorMessage
    "Khalad ayaa dhacay markii la akhrinayay waxa faylka ku jira", // Str::ErrorWhileReadingMessage
    "Khalad: Faylka lama furi karo si wax loogu qoro", // Str::WriteFileErrorMessage
    "Khalad: Xariga hexadecimal waa inuu lahaadaa tiro dhaban ah oo xarfo ah", // Str::HexStringErrorMessage
    "Khalad: Xaraf hexadecimal ah oo aan sax ahayn ayaa ku jira xariga", // Str::InvalidHexCharacterErrorMessage
    "Khalad: Faylka lama kaydin karo", // Str::SaveFileErrorMessage
    "Khalad: Faylka lama soo rari karo", // Str::LoadFileErrorMessage
    "Khalad: Qaabka faylka ma saxna (waxaa la filayay 5 goobood: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Khalad: Tirada ku celcelinta waxay dhaaftay xadka ugu badan ee la dejiyay (10,000,000)", // Str::MaxIterationsErrorMessage
    "Khalad: Hubinta dhammaystirnaanta way fashilantay, erayga sirta ah waa khalad ama faylka waa xumaaday/waa la beddelay", // Str::IntegrityCheckErrorMessage
    "Khalad: Erayga sirta ah ma noqon karo mid madhan", // Str::EmptyPasswordErrorMessage
    "Khalad: Dariiqa faylka loo socdo waa gal", // Str::OutputFileIsDirectoryErrorMessage
    "Khalad: Dariiqa faylka isha waa gal", // Str::InputFileIsDirectoryErrorMessage
    "Khalad: Dariiqa faylka loo socdo ma noqon karo mid madhan", // Str::EmptyOutputFilePathErrorMessage
    "Khalad: Dariiqa faylka isha ma noqon karo mid madhan", // Str::EmptyInputFilePathErrorMessage
    "Khalad: Faylka isha ma jiro", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Luqadda: Soomaali", // Str::LanguageLabel
    "Erayga sirta ah", // Str::PasswordLabel
    "Dhererka erayga sirta ah", // Str::PasswordLenghtLabel
    "Fayl", // Str::FileLabel
    "Faylka", // Str::TheFileLabel
    "Dariiq", // Str::PathLabel
    "Dariiqa faylka gelinta", // Str::InputFilePathLabel
    "Dariiqa faylka bixinta", // Str::OutputFilePathLabel
    "Isweydaarsii dariiqyada", // Str::SwapPathsLabel
    "dib ayaa loo qori doonaa", // Str::WillBeOverwrittenLabel
    "Waa la qarinayaa...", // Str::EncryptingText
    "Sirta waa la furayaa...", // Str::DecryptingText
    "Qari", // Str::EncryptText
    "Fur sirta", // Str::DecryptText
    "Faylka si guul leh ayaa loo qariyay", // Str::FileEncryptedMessage
    "Sirta faylka si guul leh ayaa loo furay", // Str::FileDecryptedMessage
    "Digniin!", // Str::WarningTitle
    "Ma hubtaa?", // Str::AreYouSureTitle
    "Dejinta", // Str::SettingsTitle
    "Abuuraha erayga sirta ah", // Str::GeneratePasswordTitle
    "Dooro luqadda", // Str::SelectLanguageTitle
    "Haa", // Str::YesLabel
    "Maya", // Str::NoLabel
    "Hagaag", // Str::OkLabel
    "Qaabka bixinta", // Str::OutFormatLabel
    "Dejinta muuqaalka", // Str::InterfaceSettingsLabel
    "Cabbirka", // Str::InterfaceSizeLabel
    "Hab", // Str::ModeLabel
    "Caadi", // Str::NormalModeLabel
    "Qoraal caadi ah", // Str::PlaintextModeLabel
    "Mawduuca", // Str::InterfaceThemeLabel
    "Midabka", // Str::InterfaceColorLabel
    "Asalka (qoraal caadi ah)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Isticmaal eraygan sirta ah", // Str::UsePasswordLabel
    "Koobi", // Str::CopyLabel
    "Ctrl + guji bidix si aad u hesho SHA256", // Str::GetSHA256Text
    // Themes
    "Iftiin", // Str::LightThemeName
    "Mugdi", // Str::DarkThemeName
    // Colors
    "Buluug", // Str::BlueName
    "Buluug khafiif ah", // Str::CyanName
    "Cagaar", // Str::GreenName
    "Cagaar khafiif ah", // Str::LimeName
    "Jaalle", // Str::YellowName
    "Bunni", // Str::BrownName
    "Oranji", // Str::OrangeName
    "Casaan", // Str::RedName
    "Casaan khafiif ah", // Str::PinkName
    "Buluug-casaan", // Str::PurpleName
    "Cawl", // Str::GreyName
    "Caddaan", // Str::WhiteName
    "Madow", // Str::BlackName

};
static_assert(sizeof(textosSO) / sizeof(textosSO[0]) == N,
    "Faltan o sobran textos en somali: revisa que coincidan con Str::Count.");

// Wolof (wo)
constexpr const char* textosWO[] = {

    
    
    // Info
    "Bësal Enter ngir génn...", // Str::ExitInfoMessage
    "Doxal ko rekk bu li nekk ci fisye bi", // Str::PlainTextModeMessage_FirstLine
    "di mbind mu yomb", // Str::PlainTextModeMessage_SecondLine
    "Fisye bi ñu kumpa dees na ko denc", // Str::DefaultCipherModeText_FirstLine
    "niki araf yu ñu mën a móol", // Str::DefaultCipherModeText_SecondLine
    "Fisye bi ñu kumpa dees na ko denc", // Str::OpenSSLCipherModeText_FirstLine
    "ci melokaan binaire, bu dëppoo ak OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterasioŋ yu PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Njuumte: paramet yi baaxul", // Str::WrongParamsText
    "Njëg li ñu dugal", // Str::InputValueText
    "Yoon wi ñu dugal", // Str::InputPathText
    "Mënuñu soppi njëg li ñu dugal mu nekk lim bu ëpp 0 walla bu tollo ak 0", // Str::WrongNumberValueMessage
    "Yoon wi ñu dugal dëppoowul ak benn fisye bu am", // Str::WrongPathValueMessage
    "Tànn bi ñu dugal xamuñu ko niki paramet bu baax", // Str::InvalidOptionMessage
    "Tànn bi ñu dugal", // Str::EnteredOptionText
    "Njuumte ju ñu xamul", // Str::UnknownExceptionText
    "Mënuñu tàmbali GLFW", // Str::GLFWErrorMessage
    "Mënuñu tàmbali GLAD", // Str::GLADErrorMessage
    "Njuumte: Mënuñu ubbi fisye bi ngir jàng ko", // Str::ReadFileErrorMessage
    "Njuumte am na bi ñuy jàng li nekk ci fisye bi", // Str::ErrorWhileReadingMessage
    "Njuumte: Mënuñu ubbi fisye bi ngir bind ci", // Str::WriteFileErrorMessage
    "Njuumte: Limu araf yi ci hexadecimal bi war na nekk lim bu ñu mën a xaajale ñaar", // Str::HexStringErrorMessage
    "Njuumte: Am na araf hexadecimal bu baaxul ci biir", // Str::InvalidHexCharacterErrorMessage
    "Njuumte: Mënuñu denc fisye bi", // Str::SaveFileErrorMessage
    "Njuumte: Mënuñu yeb fisye bi", // Str::LoadFileErrorMessage
    "Njuumte: Melokaanu fisye bi baaxul (5 wàll lañu doon xaar: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Njuumte: Limu iterasioŋ yi ëpp na kem bi ñu tëral (10 000 000)", // Str::MaxIterationsErrorMessage
    "Njuumte: Saytu bi ci mat-matu fisye bi antuwul, baatu jàll bi baaxul walla fisye bi yàqu na/soppiku na", // Str::IntegrityCheckErrorMessage
    "Njuumte: Baatu jàll bi mënul nekk neen", // Str::EmptyPasswordErrorMessage
    "Njuumte: Yoonu fisye bi ñuy jëmale ab dosye la", // Str::OutputFileIsDirectoryErrorMessage
    "Njuumte: Yoonu fisye cosaan bi ab dosye la", // Str::InputFileIsDirectoryErrorMessage
    "Njuumte: Yoonu fisye bi ñuy jëmale mënul nekk neen", // Str::EmptyOutputFilePathErrorMessage
    "Njuumte: Yoonu fisye cosaan bi mënul nekk neen", // Str::EmptyInputFilePathErrorMessage
    "Njuumte: Fisye cosaan bi amul", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Làkk: Wolof", // Str::LanguageLabel
    "Baatu jàll", // Str::PasswordLabel
    "Guddaayu baatu jàll", // Str::PasswordLenghtLabel
    "Fisye", // Str::FileLabel
    "Fisye bi", // Str::TheFileLabel
    "Yoon", // Str::PathLabel
    "Yoonu fisye bi ñuy dugal", // Str::InputFilePathLabel
    "Yoonu fisye bi ñuy génne", // Str::OutputFilePathLabel
    "Weccee yoon yi", // Str::SwapPathsLabel
    "dees na ko bindaat", // Str::WillBeOverwrittenLabel
    "Mi ngi koy kumpa...", // Str::EncryptingText
    "Mi ngi koy ubbi...", // Str::DecryptingText
    "Kumpa", // Str::EncryptText
    "Ubbi kumpa", // Str::DecryptText
    "Fisye bi kumpa nañu ko bu baax", // Str::FileEncryptedMessage
    "Fisye bi ubbi nañu kumpaam bu baax", // Str::FileDecryptedMessage
    "Moytul!", // Str::WarningTitle
    "Ndax wóor na la?", // Str::AreYouSureTitle
    "Tànneef yi", // Str::SettingsTitle
    "Defarukaayu baatu jàll", // Str::GeneratePasswordTitle
    "Tànnal làkk", // Str::SelectLanguageTitle
    "Waaw", // Str::YesLabel
    "Déedéet", // Str::NoLabel
    "Baax na", // Str::OkLabel
    "Melokaanu génne", // Str::OutFormatLabel
    "Tànneefu interface", // Str::InterfaceSettingsLabel
    "Dayo", // Str::InterfaceSizeLabel
    "Anam", // Str::ModeLabel
    "Bu ñu miin", // Str::NormalModeLabel
    "Mbind mu yomb", // Str::PlaintextModeLabel
    "Melo", // Str::InterfaceThemeLabel
    "Kulóor", // Str::InterfaceColorLabel
    "Bu ñu miin (mbind mu yomb)", // Str::DefaultLabel
    "OpenSSL (binaire)", // Str::OpenSSLLabel
    "Jëfandikool baatu jàll bii", // Str::UsePasswordLabel
    "Duppi", // Str::CopyLabel
    "Ctrl + bës ci càmmooñ ngir am SHA256", // Str::GetSHA256Text
    // Themes
    "Leer", // Str::LightThemeName
    "Lëndëm", // Str::DarkThemeName
    // Colors
    "Bulo", // Str::BlueName
    "Bulo bu leer", // Str::CyanName
    "Wert", // Str::GreenName
    "Wert bu leer", // Str::LimeName
    "Mboq", // Str::YellowName
    "Melo suuf", // Str::BrownName
    "Oraas", // Str::OrangeName
    "Xonq", // Str::RedName
    "Roos", // Str::PinkName
    "Wiyole", // Str::PurpleName
    "Gri", // Str::GreyName
    "Weex", // Str::WhiteName
    "Ñuul", // Str::BlackName

};
static_assert(sizeof(textosWO) / sizeof(textosWO[0]) == N,
    "Faltan o sobran textos en wolof: revisa que coincidan con Str::Count.");

// isiXhosa (xh)
constexpr const char* textosXH[] = {

    
    
    // Info
    "Cofa u-Enter ukuze uphume...", // Str::ExitInfoMessage
    "Vula kuphela ukuba okuqulethwe yifayile", // Str::PlainTextModeMessage_FirstLine
    "kungumbhalo ocacileyo", // Str::PlainTextModeMessage_SecondLine
    "Ifayile efihliweyo iya kugcinwa", // Str::DefaultCipherModeText_FirstLine
    "njengoonobumba abanokushicilelwa", // Str::DefaultCipherModeText_SecondLine
    "Ifayile efihliweyo iya kugcinwa ngefomathi", // Str::OpenSSLCipherModeText_FirstLine
    "yokubini, ehambelana ne-OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Uphindaphindo lwe-PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Impazamo: iiparamitha ezingachanekanga", // Str::WrongParamsText
    "Ixabiso elifunyenweyo", // Str::InputValueText
    "Indlela efunyenweyo", // Str::InputPathText
    "Ixabiso elifunyenweyo alikwazanga ukuguqulelwa kwinani elikhulu okanye elilingana no-0", // Str::WrongNumberValueMessage
    "Indlela efunyenweyo ayihambelani nayo nayiphi na ifayile ekhoyo", // Str::WrongPathValueMessage
    "Ukhetho olufakiweyo aluqondwa njengeparamitha esebenzayo", // Str::InvalidOptionMessage
    "Ukhetho olufakiweyo", // Str::EnteredOptionText
    "Impazamo engaziwayo", // Str::UnknownExceptionText
    "Ayiphumelelanga ukuqalisa i-GLFW", // Str::GLFWErrorMessage
    "Ayiphumelelanga ukuqalisa i-GLAD", // Str::GLADErrorMessage
    "Impazamo: Ayikwazanga ukuvula ifayile ukuze ifundwe", // Str::ReadFileErrorMessage
    "Impazamo ngexesha lokufunda okuqulethwe yifayile", // Str::ErrorWhileReadingMessage
    "Impazamo: Ayikwazanga ukuvula ifayile ukuze kubhalwe kuyo", // Str::WriteFileErrorMessage
    "Impazamo: Umtya we-hexadecimal kufuneka ube nenani loonobumba elahlulekayo ngo-2", // Str::HexStringErrorMessage
    "Impazamo: Unobumba we-hexadecimal ongasebenziyo emtyeni", // Str::InvalidHexCharacterErrorMessage
    "Impazamo: Ayikwazanga ukugcina ifayile", // Str::SaveFileErrorMessage
    "Impazamo: Ayikwazanga ukulayisha ifayile", // Str::LoadFileErrorMessage
    "Impazamo: Ifomathi yefayile engasebenziyo (kulindeleke amacandelo ama-5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Impazamo: Inani lophindaphindo ligqitha umda ophezulu omiselweyo (10 000 000)", // Str::MaxIterationsErrorMessage
    "Impazamo: Ukuqinisekiswa kokuphelela akuphumelelanga, iphasiwedi engachanekanga okanye ifayile eyonakeleyo/eguqulweyo", // Str::IntegrityCheckErrorMessage
    "Impazamo: Iphasiwedi ayinakuba ingenanto", // Str::EmptyPasswordErrorMessage
    "Impazamo: Indlela yefayile ekuyiwa kuyo yifolda", // Str::OutputFileIsDirectoryErrorMessage
    "Impazamo: Indlela yefayile yemvelaphi yifolda", // Str::InputFileIsDirectoryErrorMessage
    "Impazamo: Indlela yefayile ekuyiwa kuyo ayinakuba ingenanto", // Str::EmptyOutputFilePathErrorMessage
    "Impazamo: Indlela yefayile yemvelaphi ayinakuba ingenanto", // Str::EmptyInputFilePathErrorMessage
    "Impazamo: Ifayile yemvelaphi ayikho", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Ulwimi: isiXhosa", // Str::LanguageLabel
    "Iphasiwedi", // Str::PasswordLabel
    "Ubude bephasiwedi", // Str::PasswordLenghtLabel
    "Ifayile", // Str::FileLabel
    "Ifayile", // Str::TheFileLabel
    "Indlela", // Str::PathLabel
    "Indlela yefayile yegalelo", // Str::InputFilePathLabel
    "Indlela yefayile yemveliso", // Str::OutputFilePathLabel
    "Tshintshanisa iindlela", // Str::SwapPathsLabel
    "iya kubhalwa ngaphezulu", // Str::WillBeOverwrittenLabel
    "Iyafihla...", // Str::EncryptingText
    "Iyaveza...", // Str::DecryptingText
    "Fihla", // Str::EncryptText
    "Veza", // Str::DecryptText
    "Ifayile ifihlwe ngempumelelo", // Str::FileEncryptedMessage
    "Ifayile ivezwe ngempumelelo", // Str::FileDecryptedMessage
    "Isilumkiso!", // Str::WarningTitle
    "Uqinisekile?", // Str::AreYouSureTitle
    "Iisetingi", // Str::SettingsTitle
    "Umvelisi wephasiwedi", // Str::GeneratePasswordTitle
    "Khetha ulwimi", // Str::SelectLanguageTitle
    "Ewe", // Str::YesLabel
    "Hayi", // Str::NoLabel
    "Kulungile", // Str::OkLabel
    "Ifomathi yemveliso", // Str::OutFormatLabel
    "Iisetingi zojongano", // Str::InterfaceSettingsLabel
    "Ubungakanani", // Str::InterfaceSizeLabel
    "Imowudi", // Str::ModeLabel
    "Eqhelekileyo", // Str::NormalModeLabel
    "Umbhalo ocacileyo", // Str::PlaintextModeLabel
    "Umxholo", // Str::InterfaceThemeLabel
    "Umbala", // Str::InterfaceColorLabel
    "Okumiselweyo (umbhalo ocacileyo)", // Str::DefaultLabel
    "OpenSSL (yokubini)", // Str::OpenSSLLabel
    "Sebenzisa le phasiwedi", // Str::UsePasswordLabel
    "Kopa", // Str::CopyLabel
    "Ctrl + cofa ngasekhohlo ukuze ufumane i-SHA256", // Str::GetSHA256Text
    // Themes
    "Ekhanyayo", // Str::LightThemeName
    "Emnyama", // Str::DarkThemeName
    // Colors
    "Bhlowu", // Str::BlueName
    "Siyani", // Str::CyanName
    "Luhlaza", // Str::GreenName
    "Luhlaza okukhanyayo", // Str::LimeName
    "Mthubi", // Str::YellowName
    "Mdaka", // Str::BrownName
    "Orenji", // Str::OrangeName
    "Bomvu", // Str::RedName
    "Pinki", // Str::PinkName
    "Mfusa", // Str::PurpleName
    "Ngwevu", // Str::GreyName
    "Mhlophe", // Str::WhiteName
    "Mnyama", // Str::BlackName

};
static_assert(sizeof(textosXH) / sizeof(textosXH[0]) == N,
    "Faltan o sobran textos en xhosa: revisa que coincidan con Str::Count.");

// Afrikaans (af)
constexpr const char* textosAF[] = {

    
    
    // Info
    "Druk Enter om uit te gaan...", // Str::ExitInfoMessage
    "Aktiveer slegs as die lêer se inhoud", // Str::PlainTextModeMessage_FirstLine
    "gewone teks is", // Str::PlainTextModeMessage_SecondLine
    "Die geënkripteerde lêer sal as", // Str::DefaultCipherModeText_FirstLine
    "drukbare karakters gestoor word", // Str::DefaultCipherModeText_SecondLine
    "Die geënkripteerde lêer word in binêre", // Str::OpenSSLCipherModeText_FirstLine
    "formaat gestoor, versoenbaar met OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-iterasies:", // Str::PBKDF2IterationsText
    // Errors
    "Fout: verkeerde parameters", // Str::WrongParamsText
    "Ontvangde waarde", // Str::InputValueText
    "Ontvangde pad", // Str::InputPathText
    "Die ontvangde waarde kon nie na 'n getal groter as of gelyk aan 0 omgeskakel word nie", // Str::WrongNumberValueMessage
    "Die ontvangde pad stem nie ooreen met enige bestaande lêer nie", // Str::WrongPathValueMessage
    "Die ingevoerde opsie word nie as 'n geldige parameter herken nie", // Str::InvalidOptionMessage
    "Ingevoerde opsie", // Str::EnteredOptionText
    "Onbekende uitsondering", // Str::UnknownExceptionText
    "Kon nie GLFW inisialiseer nie", // Str::GLFWErrorMessage
    "Kon nie GLAD inisialiseer nie", // Str::GLADErrorMessage
    "Fout: Kon nie die lêer oopmaak om te lees nie", // Str::ReadFileErrorMessage
    "Fout met die lees van die lêer se inhoud", // Str::ErrorWhileReadingMessage
    "Fout: Kon nie die lêer oopmaak om te skryf nie", // Str::WriteFileErrorMessage
    "Fout: Die heksadesimale string moet 'n ewe aantal karakters hê", // Str::HexStringErrorMessage
    "Fout: Ongeldige heksadesimale karakter in die string", // Str::InvalidHexCharacterErrorMessage
    "Fout: Kon nie die lêer stoor nie", // Str::SaveFileErrorMessage
    "Fout: Kon nie die lêer laai nie", // Str::LoadFileErrorMessage
    "Fout: Ongeldige lêerformaat (5 velde verwag: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Fout: Die aantal iterasies oorskry die vasgestelde maksimum (10 000 000)", // Str::MaxIterationsErrorMessage
    "Fout: Integriteitsverifikasie het misluk, verkeerde wagwoord of beskadigde/gemanipuleerde lêer", // Str::IntegrityCheckErrorMessage
    "Fout: Die wagwoord mag nie leeg wees nie", // Str::EmptyPasswordErrorMessage
    "Fout: Die pad van die bestemmingslêer is 'n gids", // Str::OutputFileIsDirectoryErrorMessage
    "Fout: Die pad van die bronlêer is 'n gids", // Str::InputFileIsDirectoryErrorMessage
    "Fout: Die pad van die bestemmingslêer mag nie leeg wees nie", // Str::EmptyOutputFilePathErrorMessage
    "Fout: Die pad van die bronlêer mag nie leeg wees nie", // Str::EmptyInputFilePathErrorMessage
    "Fout: Die bronlêer bestaan nie", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Taal: Afrikaans", // Str::LanguageLabel
    "Wagwoord", // Str::PasswordLabel
    "Wagwoordlengte", // Str::PasswordLenghtLabel
    "Lêer", // Str::FileLabel
    "Die lêer", // Str::TheFileLabel
    "Pad", // Str::PathLabel
    "Invoerpad", // Str::InputFilePathLabel
    "Uitvoerpad", // Str::OutputFilePathLabel
    "Ruil paaie om", // Str::SwapPathsLabel
    "sal oorskryf word", // Str::WillBeOverwrittenLabel
    "Enkripteer tans...", // Str::EncryptingText
    "Dekripteer tans...", // Str::DecryptingText
    "Enkripteer", // Str::EncryptText
    "Dekripteer", // Str::DecryptText
    "Lêer suksesvol geënkripteer", // Str::FileEncryptedMessage
    "Lêer suksesvol gedekripteer", // Str::FileDecryptedMessage
    "Waarskuwing!", // Str::WarningTitle
    "Is jy seker?", // Str::AreYouSureTitle
    "Instellings", // Str::SettingsTitle
    "Wagwoordgenerator", // Str::GeneratePasswordTitle
    "Kies taal", // Str::SelectLanguageTitle
    "Ja", // Str::YesLabel
    "Nee", // Str::NoLabel
    "OK", // Str::OkLabel
    "Uitvoerformaat", // Str::OutFormatLabel
    "Koppelvlakinstellings", // Str::InterfaceSettingsLabel
    "Grootte", // Str::InterfaceSizeLabel
    "Modus", // Str::ModeLabel
    "Normaal", // Str::NormalModeLabel
    "Gewone teks", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Kleur", // Str::InterfaceColorLabel
    "Verstek (gewone teks)", // Str::DefaultLabel
    "OpenSSL (binêr)", // Str::OpenSSLLabel
    "Gebruik hierdie wagwoord", // Str::UsePasswordLabel
    "Kopieer", // Str::CopyLabel
    "Ctrl + linkerklik om SHA256 te kry", // Str::GetSHA256Text
    // Themes
    "Lig", // Str::LightThemeName
    "Donker", // Str::DarkThemeName
    // Colors
    "Blou", // Str::BlueName
    "Siaan", // Str::CyanName
    "Groen", // Str::GreenName
    "Lemmetjiegroen", // Str::LimeName
    "Geel", // Str::YellowName
    "Bruin", // Str::BrownName
    "Oranje", // Str::OrangeName
    "Rooi", // Str::RedName
    "Pienk", // Str::PinkName
    "Pers", // Str::PurpleName
    "Grys", // Str::GreyName
    "Wit", // Str::WhiteName
    "Swart", // Str::BlackName

};
static_assert(sizeof(textosAF) / sizeof(textosAF[0]) == N,
    "Faltan o sobran textos en afrikaans: revisa que coincidan con Str::Count.");

// Қазақша (kk)
constexpr const char* textosKK[] = {

    
    
    // Info
    "Шығу үшін Enter пернесін басыңыз...", // Str::ExitInfoMessage
    "Файл мазмұны қарапайым мәтін", // Str::PlainTextModeMessage_FirstLine
    "болған жағдайда ғана қосыңыз", // Str::PlainTextModeMessage_SecondLine
    "Шифрланған файл басып шығаруға", // Str::DefaultCipherModeText_FirstLine
    "болатын таңбалар ретінде сақталады", // Str::DefaultCipherModeText_SecondLine
    "Шифрланған файл OpenSSL-мен үйлесімді", // Str::OpenSSLCipherModeText_FirstLine
    "екілік форматта сақталады", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 итерациялары:", // Str::PBKDF2IterationsText
    // Errors
    "Қате: параметрлер дұрыс емес", // Str::WrongParamsText
    "Алынған мән", // Str::InputValueText
    "Алынған жол", // Str::InputPathText
    "Алынған мәнді 0-ден үлкен немесе оған тең санға түрлендіру мүмкін болмады", // Str::WrongNumberValueMessage
    "Алынған жол бар файлдардың ешқайсысына сәйкес келмейді", // Str::WrongPathValueMessage
    "Енгізілген опция жарамды параметр ретінде танылмады", // Str::InvalidOptionMessage
    "Енгізілген опция", // Str::EnteredOptionText
    "Белгісіз ерекшелік", // Str::UnknownExceptionText
    "GLFW инициализациясы сәтсіз аяқталды", // Str::GLFWErrorMessage
    "GLAD инициализациясы сәтсіз аяқталды", // Str::GLADErrorMessage
    "Қате: Файлды оқу үшін ашу мүмкін болмады", // Str::ReadFileErrorMessage
    "Файл мазмұнын оқу кезінде қате орын алды", // Str::ErrorWhileReadingMessage
    "Қате: Файлды жазу үшін ашу мүмкін болмады", // Str::WriteFileErrorMessage
    "Қате: Он алтылық жолдағы таңбалар саны жұп болуы керек", // Str::HexStringErrorMessage
    "Қате: Жолда жарамсыз он алтылық таңба бар", // Str::InvalidHexCharacterErrorMessage
    "Қате: Файлды сақтау мүмкін болмады", // Str::SaveFileErrorMessage
    "Қате: Файлды жүктеу мүмкін болмады", // Str::LoadFileErrorMessage
    "Қате: Файл пішімі жарамсыз (5 өріс күтілген: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Қате: Итерациялар саны белгіленген ең жоғары мәннен асып кетті (10 000 000)", // Str::MaxIterationsErrorMessage
    "Қате: Тұтастықты тексеру сәтсіз аяқталды, құпиясөз қате немесе файл бүлінген/өзгертілген", // Str::IntegrityCheckErrorMessage
    "Қате: Құпиясөз бос болмауы керек", // Str::EmptyPasswordErrorMessage
    "Қате: Мақсатты файл жолы қалта болып табылады", // Str::OutputFileIsDirectoryErrorMessage
    "Қате: Бастапқы файл жолы қалта болып табылады", // Str::InputFileIsDirectoryErrorMessage
    "Қате: Мақсатты файл жолы бос болмауы керек", // Str::EmptyOutputFilePathErrorMessage
    "Қате: Бастапқы файл жолы бос болмауы керек", // Str::EmptyInputFilePathErrorMessage
    "Қате: Бастапқы файл жоқ", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Тіл: Қазақша", // Str::LanguageLabel
    "Құпиясөз", // Str::PasswordLabel
    "Құпиясөз ұзындығы", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файл", // Str::TheFileLabel
    "Жол", // Str::PathLabel
    "Кіріс файлының жолы", // Str::InputFilePathLabel
    "Шығыс файлының жолы", // Str::OutputFilePathLabel
    "Жолдардың орнын ауыстыру", // Str::SwapPathsLabel
    "қайта жазылады", // Str::WillBeOverwrittenLabel
    "Шифрлануда...", // Str::EncryptingText
    "Шифр ашылуда...", // Str::DecryptingText
    "Шифрлау", // Str::EncryptText
    "Шифрды ашу", // Str::DecryptText
    "Файл сәтті шифрланды", // Str::FileEncryptedMessage
    "Файлдың шифры сәтті ашылды", // Str::FileDecryptedMessage
    "Назар аударыңыз!", // Str::WarningTitle
    "Сенімдісіз бе?", // Str::AreYouSureTitle
    "Баптаулар", // Str::SettingsTitle
    "Құпиясөз генераторы", // Str::GeneratePasswordTitle
    "Тілді таңдау", // Str::SelectLanguageTitle
    "Иә", // Str::YesLabel
    "Жоқ", // Str::NoLabel
    "OK", // Str::OkLabel
    "Шығыс пішімі", // Str::OutFormatLabel
    "Интерфейс баптаулары", // Str::InterfaceSettingsLabel
    "Өлшем", // Str::InterfaceSizeLabel
    "Режим", // Str::ModeLabel
    "Қалыпты", // Str::NormalModeLabel
    "Қарапайым мәтін", // Str::PlaintextModeLabel
    "Тақырып", // Str::InterfaceThemeLabel
    "Түс", // Str::InterfaceColorLabel
    "Әдепкі (қарапайым мәтін)", // Str::DefaultLabel
    "OpenSSL (екілік)", // Str::OpenSSLLabel
    "Осы құпиясөзді пайдалану", // Str::UsePasswordLabel
    "Көшіру", // Str::CopyLabel
    "SHA256 алу үшін Ctrl + сол жақ шерту", // Str::GetSHA256Text
    // Themes
    "Ашық", // Str::LightThemeName
    "Қараңғы", // Str::DarkThemeName
    // Colors
    "Көк", // Str::BlueName
    "Көгілдір", // Str::CyanName
    "Жасыл", // Str::GreenName
    "Лайм", // Str::LimeName
    "Сары", // Str::YellowName
    "Қоңыр", // Str::BrownName
    "Қызғылт сары", // Str::OrangeName
    "Қызыл", // Str::RedName
    "Қызғылт", // Str::PinkName
    "Күлгін", // Str::PurpleName
    "Сұр", // Str::GreyName
    "Ақ", // Str::WhiteName
    "Қара", // Str::BlackName

};
static_assert(sizeof(textosKK) / sizeof(textosKK[0]) == N,
    "Faltan o sobran textos en kazajo: revisa que coincidan con Str::Count.");

// Kurmancî (kmr)
constexpr const char* textosKMR[] = {

    
    
    // Info
    "Ji bo derketinê Enter bikirtîne...", // Str::ExitInfoMessage
    "Tenê heke naveroka pelê nivîsa", // Str::PlainTextModeMessage_FirstLine
    "sade be çalak bike", // Str::PlainTextModeMessage_SecondLine
    "Pelê şîfrekirî wê wekî tîpên", // Str::DefaultCipherModeText_FirstLine
    "çapbar were tomarkirin", // Str::DefaultCipherModeText_SecondLine
    "Pelê şîfrekirî wê di formata dualî de,", // Str::OpenSSLCipherModeText_FirstLine
    "bi OpenSSL re lihevhatî, were tomarkirin", // Str::OpenSSLCipherModeText_SecondLine
    "Dubarekirinên PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Çewtî: parametreyên nerast", // Str::WrongParamsText
    "Nirxa wergirtî", // Str::InputValueText
    "Rêça wergirtî", // Str::InputPathText
    "Nirxa wergirtî nehat veguhertin bo hejmareke ji 0 mezintir an wekhevî 0", // Str::WrongNumberValueMessage
    "Rêça wergirtî bi tu pelê heyî re li hev nayê", // Str::WrongPathValueMessage
    "Vebijarka têketî wekî parametreyeke derbasdar nayê naskirin", // Str::InvalidOptionMessage
    "Vebijarka têketî", // Str::EnteredOptionText
    "Îstîsnaya nenas", // Str::UnknownExceptionText
    "Destpêkirina GLFW bi ser neket", // Str::GLFWErrorMessage
    "Destpêkirina GLAD bi ser neket", // Str::GLADErrorMessage
    "Çewtî: Pel ji bo xwendinê nehat vekirin", // Str::ReadFileErrorMessage
    "Di xwendina naveroka pelê de çewtî çêbû", // Str::ErrorWhileReadingMessage
    "Çewtî: Pel ji bo nivîsandinê nehat vekirin", // Str::WriteFileErrorMessage
    "Çewtî: Divê hejmara tîpên rêzika heksadesîmal cot be", // Str::HexStringErrorMessage
    "Çewtî: Di rêzikê de tîpeke heksadesîmal a nederbasdar heye", // Str::InvalidHexCharacterErrorMessage
    "Çewtî: Pel nehat tomarkirin", // Str::SaveFileErrorMessage
    "Çewtî: Pel nehat barkirin", // Str::LoadFileErrorMessage
    "Çewtî: Formata pelê nederbasdar e (5 qad dihatin hêvîkirin: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Çewtî: Hejmara dubarekirinan ji herî zêdeya diyarkirî derbas dibe (10.000.000)", // Str::MaxIterationsErrorMessage
    "Çewtî: Piştrastkirina yekparebûnê bi ser neket, şîfreya çewt an pelê xerabûyî/guhertî", // Str::IntegrityCheckErrorMessage
    "Çewtî: Şîfre nikare vala be", // Str::EmptyPasswordErrorMessage
    "Çewtî: Rêça pelê armanc peldank e", // Str::OutputFileIsDirectoryErrorMessage
    "Çewtî: Rêça pelê çavkanî peldank e", // Str::InputFileIsDirectoryErrorMessage
    "Çewtî: Rêça pelê armanc nikare vala be", // Str::EmptyOutputFilePathErrorMessage
    "Çewtî: Rêça pelê çavkanî nikare vala be", // Str::EmptyInputFilePathErrorMessage
    "Çewtî: Pelê çavkanî tune ye", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Ziman: Kurmancî", // Str::LanguageLabel
    "Şîfre", // Str::PasswordLabel
    "Dirêjahiya şîfreyê", // Str::PasswordLenghtLabel
    "Pel", // Str::FileLabel
    "Pelê", // Str::TheFileLabel
    "Rêç", // Str::PathLabel
    "Rêça pelê têketinê", // Str::InputFilePathLabel
    "Rêça pelê derketinê", // Str::OutputFilePathLabel
    "Rêçan biguherîne", // Str::SwapPathsLabel
    "wê li ser were nivîsandin", // Str::WillBeOverwrittenLabel
    "Tê şîfrekirin...", // Str::EncryptingText
    "Şîfre tê vekirin...", // Str::DecryptingText
    "Şîfre bike", // Str::EncryptText
    "Şîfreyê veke", // Str::DecryptText
    "Pel bi serkeftî hat şîfrekirin", // Str::FileEncryptedMessage
    "Şîfreya pelê bi serkeftî hat vekirin", // Str::FileDecryptedMessage
    "Hişyarî!", // Str::WarningTitle
    "Tu piştrast î?", // Str::AreYouSureTitle
    "Mîheng", // Str::SettingsTitle
    "Afirînerê şîfreyan", // Str::GeneratePasswordTitle
    "Ziman hilbijêre", // Str::SelectLanguageTitle
    "Erê", // Str::YesLabel
    "Na", // Str::NoLabel
    "Baş e", // Str::OkLabel
    "Formata derketinê", // Str::OutFormatLabel
    "Mîhengên navrûyê", // Str::InterfaceSettingsLabel
    "Mezinahî", // Str::InterfaceSizeLabel
    "Mod", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Nivîsa sade", // Str::PlaintextModeLabel
    "Rûkar", // Str::InterfaceThemeLabel
    "Reng", // Str::InterfaceColorLabel
    "Pêşdanasîn (nivîsa sade)", // Str::DefaultLabel
    "OpenSSL (dualî)", // Str::OpenSSLLabel
    "Vê şîfreyê bi kar bîne", // Str::UsePasswordLabel
    "Kopî bike", // Str::CopyLabel
    "Ji bo SHA256 Ctrl + klîka çepê bike", // Str::GetSHA256Text
    // Themes
    "Ronî", // Str::LightThemeName
    "Tarî", // Str::DarkThemeName
    // Colors
    "Şîn", // Str::BlueName
    "Şîna vekirî", // Str::CyanName
    "Kesk", // Str::GreenName
    "Keska vekirî", // Str::LimeName
    "Zer", // Str::YellowName
    "Qehweyî", // Str::BrownName
    "Porteqalî", // Str::OrangeName
    "Sor", // Str::RedName
    "Pembe", // Str::PinkName
    "Mor", // Str::PurpleName
    "Gewr", // Str::GreyName
    "Spî", // Str::WhiteName
    "Reş", // Str::BlackName

};
static_assert(sizeof(textosKMR) / sizeof(textosKMR[0]) == N,
    "Faltan o sobran textos en kurdo: revisa que coincidan con Str::Count.");

// Ikinyarwanda (rw)
constexpr const char* textosRW[] = {

    
    
    // Info
    "Kanda Enter kugira ngo usohoke...", // Str::ExitInfoMessage
    "Fungura gusa niba ibiri muri dosiye", // Str::PlainTextModeMessage_FirstLine
    "ari inyandiko isanzwe", // Str::PlainTextModeMessage_SecondLine
    "Dosiye yashyizwe mu ibanga izabikwa", // Str::DefaultCipherModeText_FirstLine
    "nk'inyuguti zishobora gucapwa", // Str::DefaultCipherModeText_SecondLine
    "Dosiye yashyizwe mu ibanga izabikwa", // Str::OpenSSLCipherModeText_FirstLine
    "mu buryo bwa binary, buhuye na OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Isubiramo rya PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Ikosa: ibipimo bitari byo", // Str::WrongParamsText
    "Agaciro kakiriwe", // Str::InputValueText
    "Inzira yakiriwe", // Str::InputPathText
    "Agaciro kakiriwe ntikashoboye guhindurwa umubare uruta 0 cyangwa ungana na 0", // Str::WrongNumberValueMessage
    "Inzira yakiriwe ntihuye na dosiye n'imwe iriho", // Str::WrongPathValueMessage
    "Ihitamo ryinjijwe ntirimenyekana nk'ipimo ryemewe", // Str::InvalidOptionMessage
    "Ihitamo ryinjijwe", // Str::EnteredOptionText
    "Ikosa ritazwi", // Str::UnknownExceptionText
    "Gutangiza GLFW byanze", // Str::GLFWErrorMessage
    "Gutangiza GLAD byanze", // Str::GLADErrorMessage
    "Ikosa: Ntibyashobotse gufungura dosiye ngo isomwe", // Str::ReadFileErrorMessage
    "Ikosa ryabaye mu gusoma ibiri muri dosiye", // Str::ErrorWhileReadingMessage
    "Ikosa: Ntibyashobotse gufungura dosiye ngo yandikwemo", // Str::WriteFileErrorMessage
    "Ikosa: Umurongo wa hexadecimal ugomba kugira umubare w'inyuguti ugabanyika na 2", // Str::HexStringErrorMessage
    "Ikosa: Hari inyuguti ya hexadecimal itemewe mu murongo", // Str::InvalidHexCharacterErrorMessage
    "Ikosa: Ntibyashobotse kubika dosiye", // Str::SaveFileErrorMessage
    "Ikosa: Ntibyashobotse kuzana dosiye", // Str::LoadFileErrorMessage
    "Ikosa: Imiterere ya dosiye itemewe (hari hategerejwe ibice 5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Ikosa: Umubare w'isubiramo urenze ntarengwa yashyizweho (10.000.000)", // Str::MaxIterationsErrorMessage
    "Ikosa: Igenzura ry'ubuziranenge ryanze, ijambo ry'ibanga si ryo cyangwa dosiye yangiritse/yahinduwe", // Str::IntegrityCheckErrorMessage
    "Ikosa: Ijambo ry'ibanga ntirishobora kuba ubusa", // Str::EmptyPasswordErrorMessage
    "Ikosa: Inzira ya dosiye igenewe ni ububiko", // Str::OutputFileIsDirectoryErrorMessage
    "Ikosa: Inzira ya dosiye y'inkomoko ni ububiko", // Str::InputFileIsDirectoryErrorMessage
    "Ikosa: Inzira ya dosiye igenewe ntishobora kuba ubusa", // Str::EmptyOutputFilePathErrorMessage
    "Ikosa: Inzira ya dosiye y'inkomoko ntishobora kuba ubusa", // Str::EmptyInputFilePathErrorMessage
    "Ikosa: Dosiye y'inkomoko ntibaho", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Ururimi: Ikinyarwanda", // Str::LanguageLabel
    "Ijambo ry'ibanga", // Str::PasswordLabel
    "Uburebure bw'ijambo ry'ibanga", // Str::PasswordLenghtLabel
    "Dosiye", // Str::FileLabel
    "Dosiye", // Str::TheFileLabel
    "Inzira", // Str::PathLabel
    "Inzira ya dosiye yinjira", // Str::InputFilePathLabel
    "Inzira ya dosiye isohoka", // Str::OutputFilePathLabel
    "Guhinduranya inzira", // Str::SwapPathsLabel
    "izandikwaho bundi bushya", // Str::WillBeOverwrittenLabel
    "Birimo gushyirwa mu ibanga...", // Str::EncryptingText
    "Birimo gukurwa mu ibanga...", // Str::DecryptingText
    "Shyira mu ibanga", // Str::EncryptText
    "Kura mu ibanga", // Str::DecryptText
    "Dosiye yashyizwe mu ibanga neza", // Str::FileEncryptedMessage
    "Dosiye yakuwe mu ibanga neza", // Str::FileDecryptedMessage
    "Iburira!", // Str::WarningTitle
    "Urabyizeye?", // Str::AreYouSureTitle
    "Igenamiterere", // Str::SettingsTitle
    "Gukora ijambo ry'ibanga", // Str::GeneratePasswordTitle
    "Hitamo ururimi", // Str::SelectLanguageTitle
    "Yego", // Str::YesLabel
    "Oya", // Str::NoLabel
    "Sawa", // Str::OkLabel
    "Imiterere y'ibisohoka", // Str::OutFormatLabel
    "Igenamiterere ry'imigaragarire", // Str::InterfaceSettingsLabel
    "Ingano", // Str::InterfaceSizeLabel
    "Uburyo", // Str::ModeLabel
    "Bisanzwe", // Str::NormalModeLabel
    "Inyandiko isanzwe", // Str::PlaintextModeLabel
    "Insanganyamatsiko", // Str::InterfaceThemeLabel
    "Ibara", // Str::InterfaceColorLabel
    "Mburabuzi (inyandiko isanzwe)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Koresha iri jambo ry'ibanga", // Str::UsePasswordLabel
    "Koporora", // Str::CopyLabel
    "Ctrl + kanda ibumoso kugira ngo ubone SHA256", // Str::GetSHA256Text
    // Themes
    "Urumuri", // Str::LightThemeName
    "Umwijima", // Str::DarkThemeName
    // Colors
    "Ubururu", // Str::BlueName
    "Ubururu bwerurutse", // Str::CyanName
    "Icyatsi", // Str::GreenName
    "Icyatsi cyerurutse", // Str::LimeName
    "Umuhondo", // Str::YellowName
    "Ikigina", // Str::BrownName
    "Icunga", // Str::OrangeName
    "Umutuku", // Str::RedName
    "Iroza", // Str::PinkName
    "Move", // Str::PurpleName
    "Ikijuju", // Str::GreyName
    "Umweru", // Str::WhiteName
    "Umukara", // Str::BlackName

};
static_assert(sizeof(textosRW) / sizeof(textosRW[0]) == N,
    "Faltan o sobran textos en kinyarwanda: revisa que coincidan con Str::Count.");

// chiShona (sn)
constexpr const char* textosSN[] = {

    
    
    // Info
    "Dzvanya Enter kuti ubude...", // Str::ExitInfoMessage
    "Batidza chete kana zviri mufaira", // Str::PlainTextModeMessage_FirstLine
    "zviri zvinyorwa zvakajairika", // Str::PlainTextModeMessage_SecondLine
    "Faira rakavanzidzwa richachengetwa", // Str::DefaultCipherModeText_FirstLine
    "semavara anogona kudhindwa", // Str::DefaultCipherModeText_SecondLine
    "Faira rakavanzidzwa richachengetwa", // Str::OpenSSLCipherModeText_FirstLine
    "muchimiro che binary, chinoenderana neOpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Kudzokororwa kwePBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Chikanganiso: maparamita asina kururama", // Str::WrongParamsText
    "Kukosha kwakagamuchirwa", // Str::InputValueText
    "Nzira yakagamuchirwa", // Str::InputPathText
    "Kukosha kwakagamuchirwa hakuna kugona kushandurwa kuva nhamba huru kupfuura 0 kana yakaenzana ne0", // Str::WrongNumberValueMessage
    "Nzira yakagamuchirwa haienderani nefaira ripi neripi riripo", // Str::WrongPathValueMessage
    "Sarudzo yakaiswa haizivikanwi separamita inoshanda", // Str::InvalidOptionMessage
    "Sarudzo yakaiswa", // Str::EnteredOptionText
    "Chikanganiso chisingazivikanwi", // Str::UnknownExceptionText
    "Zvakundikana kutanga GLFW", // Str::GLFWErrorMessage
    "Zvakundikana kutanga GLAD", // Str::GLADErrorMessage
    "Chikanganiso: Hazvina kugoneka kuvhura faira kuti riverengwe", // Str::ReadFileErrorMessage
    "Chikanganiso pakuverenga zviri mufaira", // Str::ErrorWhileReadingMessage
    "Chikanganiso: Hazvina kugoneka kuvhura faira kuti rinyorwe", // Str::WriteFileErrorMessage
    "Chikanganiso: Tambo ye hexadecimal inofanira kuva nehuwandu hwemavara hunogoneka kupatsanurwa ne2", // Str::HexStringErrorMessage
    "Chikanganiso: Pane vara re hexadecimal risina kukodzera mutambo", // Str::InvalidHexCharacterErrorMessage
    "Chikanganiso: Hazvina kugoneka kuchengeta faira", // Str::SaveFileErrorMessage
    "Chikanganiso: Hazvina kugoneka kurodha faira", // Str::LoadFileErrorMessage
    "Chikanganiso: Chimiro chefaira hachina kukodzera (paitarisirwa minda 5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Chikanganiso: Huwandu hwekudzokorora hwapfuura muganho mukuru wakatarwa (10 000 000)", // Str::MaxIterationsErrorMessage
    "Chikanganiso: Kusimbiswa kwekukwana kwakundikana, pasiwedhi isiriyo kana faira rakakuvadzwa/rakashandurwa", // Str::IntegrityCheckErrorMessage
    "Chikanganiso: Pasiwedhi haigoni kuva isina chinhu", // Str::EmptyPasswordErrorMessage
    "Chikanganiso: Nzira yefaira rekwainoenda ifoda", // Str::OutputFileIsDirectoryErrorMessage
    "Chikanganiso: Nzira yefaira rekwakabva ifoda", // Str::InputFileIsDirectoryErrorMessage
    "Chikanganiso: Nzira yefaira rekwainoenda haigoni kuva isina chinhu", // Str::EmptyOutputFilePathErrorMessage
    "Chikanganiso: Nzira yefaira rekwakabva haigoni kuva isina chinhu", // Str::EmptyInputFilePathErrorMessage
    "Chikanganiso: Faira rekwakabva harisipo", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Mutauro: chiShona", // Str::LanguageLabel
    "Pasiwedhi", // Str::PasswordLabel
    "Kureba kwepasiwedhi", // Str::PasswordLenghtLabel
    "Faira", // Str::FileLabel
    "Faira", // Str::TheFileLabel
    "Nzira", // Str::PathLabel
    "Nzira yefaira rinopinda", // Str::InputFilePathLabel
    "Nzira yefaira rinobuda", // Str::OutputFilePathLabel
    "Chinjanisa nzira", // Str::SwapPathsLabel
    "richanyorwa pamusoro", // Str::WillBeOverwrittenLabel
    "Kuvanzidza...", // Str::EncryptingText
    "Kubvisa kuvanzidza...", // Str::DecryptingText
    "Vanzidza", // Str::EncryptText
    "Bvisa kuvanzidza", // Str::DecryptText
    "Faira ravanzidzwa zvakabudirira", // Str::FileEncryptedMessage
    "Kuvanzidza kwefaira kwabviswa zvakabudirira", // Str::FileDecryptedMessage
    "Yambiro!", // Str::WarningTitle
    "Une chokwadi here?", // Str::AreYouSureTitle
    "Marongedzero", // Str::SettingsTitle
    "Mugadziri wepasiwedhi", // Str::GeneratePasswordTitle
    "Sarudza mutauro", // Str::SelectLanguageTitle
    "Hongu", // Str::YesLabel
    "Kwete", // Str::NoLabel
    "Zvakanaka", // Str::OkLabel
    "Chimiro chekubuda", // Str::OutFormatLabel
    "Marongedzero ekuratidzira", // Str::InterfaceSettingsLabel
    "Saizi", // Str::InterfaceSizeLabel
    "Modhi", // Str::ModeLabel
    "Zvakajairika", // Str::NormalModeLabel
    "Zvinyorwa zvakajairika", // Str::PlaintextModeLabel
    "Dingindira", // Str::InterfaceThemeLabel
    "Ruvara", // Str::InterfaceColorLabel
    "Chakatarwa (zvinyorwa zvakajairika)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Shandisa pasiwedhi iyi", // Str::UsePasswordLabel
    "Kopa", // Str::CopyLabel
    "Ctrl + dzvanya kuruboshwe kuti uwane SHA256", // Str::GetSHA256Text
    // Themes
    "Chiedza", // Str::LightThemeName
    "Rima", // Str::DarkThemeName
    // Colors
    "Bhuruu", // Str::BlueName
    "Bhuruu yakajeka", // Str::CyanName
    "Girinhi", // Str::GreenName
    "Girinhi yakajeka", // Str::LimeName
    "Yero", // Str::YellowName
    "Bhurauni", // Str::BrownName
    "Orenji", // Str::OrangeName
    "Tsvuku", // Str::RedName
    "Pinki", // Str::PinkName
    "Pepuru", // Str::PurpleName
    "Gireyi", // Str::GreyName
    "Chena", // Str::WhiteName
    "Nhema", // Str::BlackName

};
static_assert(sizeof(textosSN) / sizeof(textosSN[0]) == N,
    "Faltan o sobran textos en shona: revisa que coincidan con Str::Count.");

// Chichewa (ny)
constexpr const char* textosNY[] = {

    
    
    // Info
    "Dinani Enter kuti mutuluke...", // Str::ExitInfoMessage
    "Yatsani pokhapokha ngati zomwe zili", // Str::PlainTextModeMessage_FirstLine
    "mufayilo ndi mawu wamba", // Str::PlainTextModeMessage_SecondLine
    "Fayilo yobisidwa idzasungidwa", // Str::DefaultCipherModeText_FirstLine
    "ngati zilembo zomwe zingasindikizidwe", // Str::DefaultCipherModeText_SecondLine
    "Fayilo yobisidwa idzasungidwa", // Str::OpenSSLCipherModeText_FirstLine
    "mu mtundu wa binary, wogwirizana ndi OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Kubwerezabwereza kwa PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Cholakwika: magawo olakwika", // Str::WrongParamsText
    "Mtengo womwe walandiridwa", // Str::InputValueText
    "Njira yomwe yalandiridwa", // Str::InputPathText
    "Mtengo womwe walandiridwa sunasinthidwe kukhala nambala yoposa kapena yofanana ndi 0", // Str::WrongNumberValueMessage
    "Njira yomwe yalandiridwa sikugwirizana ndi fayilo iliyonse yomwe ilipo", // Str::WrongPathValueMessage
    "Chosankha chomwe chalowetsedwa sichidziwika ngati gawo lovomerezeka", // Str::InvalidOptionMessage
    "Chosankha chomwe chalowetsedwa", // Str::EnteredOptionText
    "Cholakwika chosadziwika", // Str::UnknownExceptionText
    "Zalephera kuyambitsa GLFW", // Str::GLFWErrorMessage
    "Zalephera kuyambitsa GLAD", // Str::GLADErrorMessage
    "Cholakwika: Sizinatheke kutsegula fayilo kuti iwerengedwe", // Str::ReadFileErrorMessage
    "Cholakwika powerenga zomwe zili mufayilo", // Str::ErrorWhileReadingMessage
    "Cholakwika: Sizinatheke kutsegula fayilo kuti ilembedwe", // Str::WriteFileErrorMessage
    "Cholakwika: Chingwe cha hexadecimal chiyenera kukhala ndi chiwerengero cha zilembo chogawika ndi 2", // Str::HexStringErrorMessage
    "Cholakwika: Pali chilembo cha hexadecimal cholakwika mu chingwe", // Str::InvalidHexCharacterErrorMessage
    "Cholakwika: Sizinatheke kusunga fayilo", // Str::SaveFileErrorMessage
    "Cholakwika: Sizinatheke kutenga fayilo", // Str::LoadFileErrorMessage
    "Cholakwika: Mtundu wa fayilo ndi wolakwika (panali kuyembekezera magawo 5: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Cholakwika: Chiwerengero cha kubwereza chaposa malire apamwamba omwe adakhazikitsidwa (10,000,000)", // Str::MaxIterationsErrorMessage
    "Cholakwika: Kutsimikizira kukwanira kwalephera, mawu achinsinsi olakwika kapena fayilo yowonongeka/yosinthidwa", // Str::IntegrityCheckErrorMessage
    "Cholakwika: Mawu achinsinsi sangakhale opanda kanthu", // Str::EmptyPasswordErrorMessage
    "Cholakwika: Njira ya fayilo yopitako ndi foda", // Str::OutputFileIsDirectoryErrorMessage
    "Cholakwika: Njira ya fayilo yochokera ndi foda", // Str::InputFileIsDirectoryErrorMessage
    "Cholakwika: Njira ya fayilo yopitako singakhale yopanda kanthu", // Str::EmptyOutputFilePathErrorMessage
    "Cholakwika: Njira ya fayilo yochokera singakhale yopanda kanthu", // Str::EmptyInputFilePathErrorMessage
    "Cholakwika: Fayilo yochokera kulibe", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Chilankhulo: Chichewa", // Str::LanguageLabel
    "Mawu achinsinsi", // Str::PasswordLabel
    "Kutalika kwa mawu achinsinsi", // Str::PasswordLenghtLabel
    "Fayilo", // Str::FileLabel
    "Fayilo", // Str::TheFileLabel
    "Njira", // Str::PathLabel
    "Njira ya fayilo yolowetsa", // Str::InputFilePathLabel
    "Njira ya fayilo yotulutsa", // Str::OutputFilePathLabel
    "Sinthanitsani njira", // Str::SwapPathsLabel
    "idzalembedwa pamwamba", // Str::WillBeOverwrittenLabel
    "Ikubisa...", // Str::EncryptingText
    "Ikuchotsa kubisa...", // Str::DecryptingText
    "Bisa", // Str::EncryptText
    "Chotsa kubisa", // Str::DecryptText
    "Fayilo yabisidwa bwino", // Str::FileEncryptedMessage
    "Kubisa kwa fayilo kwachotsedwa bwino", // Str::FileDecryptedMessage
    "Chenjezo!", // Str::WarningTitle
    "Mukutsimikiza?", // Str::AreYouSureTitle
    "Zokonda", // Str::SettingsTitle
    "Chopangira mawu achinsinsi", // Str::GeneratePasswordTitle
    "Sankhani chilankhulo", // Str::SelectLanguageTitle
    "Inde", // Str::YesLabel
    "Ayi", // Str::NoLabel
    "Chabwino", // Str::OkLabel
    "Mtundu wotulutsa", // Str::OutFormatLabel
    "Zokonda za mawonekedwe", // Str::InterfaceSettingsLabel
    "Kukula", // Str::InterfaceSizeLabel
    "Mkhalidwe", // Str::ModeLabel
    "Wamba", // Str::NormalModeLabel
    "Mawu wamba", // Str::PlaintextModeLabel
    "Kawonekedwe", // Str::InterfaceThemeLabel
    "Mtundu", // Str::InterfaceColorLabel
    "Zokhazikika (mawu wamba)", // Str::DefaultLabel
    "OpenSSL (binary)", // Str::OpenSSLLabel
    "Gwiritsani ntchito mawu achinsinsi awa", // Str::UsePasswordLabel
    "Koperani", // Str::CopyLabel
    "Ctrl + dinani kumanzere kuti mupeze SHA256", // Str::GetSHA256Text
    // Themes
    "Kowala", // Str::LightThemeName
    "Kwamdima", // Str::DarkThemeName
    // Colors
    "Buluu", // Str::BlueName
    "Buluu wowala", // Str::CyanName
    "Wobiriwira", // Str::GreenName
    "Wobiriwira wowala", // Str::LimeName
    "Wachikasu", // Str::YellowName
    "Bulawuni", // Str::BrownName
    "Lalanje", // Str::OrangeName
    "Wofiira", // Str::RedName
    "Pinki", // Str::PinkName
    "Pepo", // Str::PurpleName
    "Imvi", // Str::GreyName
    "Woyera", // Str::WhiteName
    "Wakuda", // Str::BlackName

};
static_assert(sizeof(textosNY) / sizeof(textosNY[0]) == N,
    "Faltan o sobran textos en chichewa: revisa que coincidan con Str::Count.");

// Ελληνικά (el)
constexpr const char* textosEL[] = {

    
    
    // Info
    "Πατήστε Enter για έξοδο...", // Str::ExitInfoMessage
    "Ενεργοποιήστε μόνο αν το περιεχόμενο", // Str::PlainTextModeMessage_FirstLine
    "του αρχείου είναι απλό κείμενο", // Str::PlainTextModeMessage_SecondLine
    "Το κρυπτογραφημένο αρχείο θα αποθηκευτεί", // Str::DefaultCipherModeText_FirstLine
    "ως εκτυπώσιμοι χαρακτήρες", // Str::DefaultCipherModeText_SecondLine
    "Το κρυπτογραφημένο αρχείο θα αποθηκευτεί", // Str::OpenSSLCipherModeText_FirstLine
    "σε δυαδική μορφή, συμβατή με το OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Επαναλήψεις PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Σφάλμα: λανθασμένες παράμετροι", // Str::WrongParamsText
    "Ληφθείσα τιμή", // Str::InputValueText
    "Ληφθείσα διαδρομή", // Str::InputPathText
    "Η ληφθείσα τιμή δεν ήταν δυνατό να μετατραπεί σε αριθμό μεγαλύτερο ή ίσο του 0", // Str::WrongNumberValueMessage
    "Η ληφθείσα διαδρομή δεν αντιστοιχεί σε κανένα υπάρχον αρχείο", // Str::WrongPathValueMessage
    "Η επιλογή που εισαγάγατε δεν αναγνωρίζεται ως έγκυρη παράμετρος", // Str::InvalidOptionMessage
    "Επιλογή που εισαγάγατε", // Str::EnteredOptionText
    "Άγνωστη εξαίρεση", // Str::UnknownExceptionText
    "Αποτυχία αρχικοποίησης του GLFW", // Str::GLFWErrorMessage
    "Αποτυχία αρχικοποίησης του GLAD", // Str::GLADErrorMessage
    "Σφάλμα: Δεν ήταν δυνατό το άνοιγμα του αρχείου για ανάγνωση", // Str::ReadFileErrorMessage
    "Σφάλμα κατά την ανάγνωση του περιεχομένου του αρχείου", // Str::ErrorWhileReadingMessage
    "Σφάλμα: Δεν ήταν δυνατό το άνοιγμα του αρχείου για εγγραφή", // Str::WriteFileErrorMessage
    "Σφάλμα: Η δεκαεξαδική συμβολοσειρά πρέπει να έχει άρτιο αριθμό χαρακτήρων", // Str::HexStringErrorMessage
    "Σφάλμα: Μη έγκυρος δεκαεξαδικός χαρακτήρας στη συμβολοσειρά", // Str::InvalidHexCharacterErrorMessage
    "Σφάλμα: Δεν ήταν δυνατή η αποθήκευση του αρχείου", // Str::SaveFileErrorMessage
    "Σφάλμα: Δεν ήταν δυνατή η φόρτωση του αρχείου", // Str::LoadFileErrorMessage
    "Σφάλμα: Μη έγκυρη μορφή αρχείου (αναμένονταν 5 πεδία: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Σφάλμα: Ο αριθμός των επαναλήψεων υπερβαίνει το καθορισμένο μέγιστο (10.000.000)", // Str::MaxIterationsErrorMessage
    "Σφάλμα: Ο έλεγχος ακεραιότητας απέτυχε, λανθασμένος κωδικός πρόσβασης ή κατεστραμμένο/αλλοιωμένο αρχείο", // Str::IntegrityCheckErrorMessage
    "Σφάλμα: Ο κωδικός πρόσβασης δεν μπορεί να είναι κενός", // Str::EmptyPasswordErrorMessage
    "Σφάλμα: Η διαδρομή του αρχείου προορισμού είναι φάκελος", // Str::OutputFileIsDirectoryErrorMessage
    "Σφάλμα: Η διαδρομή του αρχείου προέλευσης είναι φάκελος", // Str::InputFileIsDirectoryErrorMessage
    "Σφάλμα: Η διαδρομή του αρχείου προορισμού δεν μπορεί να είναι κενή", // Str::EmptyOutputFilePathErrorMessage
    "Σφάλμα: Η διαδρομή του αρχείου προέλευσης δεν μπορεί να είναι κενή", // Str::EmptyInputFilePathErrorMessage
    "Σφάλμα: Το αρχείο προέλευσης δεν υπάρχει", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Γλώσσα: Ελληνικά", // Str::LanguageLabel
    "Κωδικός πρόσβασης", // Str::PasswordLabel
    "Μήκος κωδικού πρόσβασης", // Str::PasswordLenghtLabel
    "Αρχείο", // Str::FileLabel
    "Το αρχείο", // Str::TheFileLabel
    "Διαδρομή", // Str::PathLabel
    "Διαδρομή εισόδου", // Str::InputFilePathLabel
    "Διαδρομή εξόδου", // Str::OutputFilePathLabel
    "Εναλλαγή διαδρομών", // Str::SwapPathsLabel
    "θα αντικατασταθεί", // Str::WillBeOverwrittenLabel
    "Κρυπτογράφηση...", // Str::EncryptingText
    "Αποκρυπτογράφηση...", // Str::DecryptingText
    "Κρυπτογράφηση", // Str::EncryptText
    "Αποκρυπτογράφηση", // Str::DecryptText
    "Το αρχείο κρυπτογραφήθηκε με επιτυχία", // Str::FileEncryptedMessage
    "Το αρχείο αποκρυπτογραφήθηκε με επιτυχία", // Str::FileDecryptedMessage
    "Προειδοποίηση!", // Str::WarningTitle
    "Είστε σίγουροι;", // Str::AreYouSureTitle
    "Ρυθμίσεις", // Str::SettingsTitle
    "Γεννήτρια κωδικών πρόσβασης", // Str::GeneratePasswordTitle
    "Επιλογή γλώσσας", // Str::SelectLanguageTitle
    "Ναι", // Str::YesLabel
    "Όχι", // Str::NoLabel
    "OK", // Str::OkLabel
    "Μορφή εξόδου", // Str::OutFormatLabel
    "Ρυθμίσεις διεπαφής", // Str::InterfaceSettingsLabel
    "Μέγεθος", // Str::InterfaceSizeLabel
    "Λειτουργία", // Str::ModeLabel
    "Κανονική", // Str::NormalModeLabel
    "Απλό κείμενο", // Str::PlaintextModeLabel
    "Θέμα", // Str::InterfaceThemeLabel
    "Χρώμα", // Str::InterfaceColorLabel
    "Προεπιλογή (απλό κείμενο)", // Str::DefaultLabel
    "OpenSSL (δυαδικό)", // Str::OpenSSLLabel
    "Χρήση αυτού του κωδικού", // Str::UsePasswordLabel
    "Αντιγραφή", // Str::CopyLabel
    "Ctrl + αριστερό κλικ για λήψη του SHA256", // Str::GetSHA256Text
    // Themes
    "Φωτεινό", // Str::LightThemeName
    "Σκούρο", // Str::DarkThemeName
    // Colors
    "Μπλε", // Str::BlueName
    "Κυανό", // Str::CyanName
    "Πράσινο", // Str::GreenName
    "Λαχανί", // Str::LimeName
    "Κίτρινο", // Str::YellowName
    "Καφέ", // Str::BrownName
    "Πορτοκαλί", // Str::OrangeName
    "Κόκκινο", // Str::RedName
    "Ροζ", // Str::PinkName
    "Μωβ", // Str::PurpleName
    "Γκρι", // Str::GreyName
    "Λευκό", // Str::WhiteName
    "Μαύρο", // Str::BlackName

};
static_assert(sizeof(textosEL) / sizeof(textosEL[0]) == N,
    "Faltan o sobran textos en griego: revisa que coincidan con Str::Count.");

// Magyar (hu)
constexpr const char* textosHU[] = {

    
    
    // Info
    "Nyomja meg az Entert a kilépéshez...", // Str::ExitInfoMessage
    "Csak akkor engedélyezze, ha a fájl", // Str::PlainTextModeMessage_FirstLine
    "tartalma egyszerű szöveg", // Str::PlainTextModeMessage_SecondLine
    "A titkosított fájl nyomtatható", // Str::DefaultCipherModeText_FirstLine
    "karakterekként lesz mentve", // Str::DefaultCipherModeText_SecondLine
    "A titkosított fájl OpenSSL-kompatibilis", // Str::OpenSSLCipherModeText_FirstLine
    "bináris formátumban lesz mentve", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-iterációk:", // Str::PBKDF2IterationsText
    // Errors
    "Hiba: hibás paraméterek", // Str::WrongParamsText
    "Kapott érték", // Str::InputValueText
    "Kapott elérési út", // Str::InputPathText
    "A kapott érték nem alakítható át 0-nál nagyobb vagy azzal egyenlő számmá", // Str::WrongNumberValueMessage
    "A kapott elérési út egyetlen létező fájlnak sem felel meg", // Str::WrongPathValueMessage
    "A megadott opció nem ismerhető fel érvényes paraméterként", // Str::InvalidOptionMessage
    "Megadott opció", // Str::EnteredOptionText
    "Ismeretlen kivétel", // Str::UnknownExceptionText
    "A GLFW inicializálása sikertelen", // Str::GLFWErrorMessage
    "A GLAD inicializálása sikertelen", // Str::GLADErrorMessage
    "Hiba: A fájl nem nyitható meg olvasásra", // Str::ReadFileErrorMessage
    "Hiba a fájl tartalmának olvasása közben", // Str::ErrorWhileReadingMessage
    "Hiba: A fájl nem nyitható meg írásra", // Str::WriteFileErrorMessage
    "Hiba: A hexadecimális karakterláncnak páros számú karaktert kell tartalmaznia", // Str::HexStringErrorMessage
    "Hiba: Érvénytelen hexadecimális karakter a karakterláncban", // Str::InvalidHexCharacterErrorMessage
    "Hiba: A fájl nem menthető", // Str::SaveFileErrorMessage
    "Hiba: A fájl nem tölthető be", // Str::LoadFileErrorMessage
    "Hiba: Érvénytelen fájlformátum (5 mező várható: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Hiba: Az iterációk száma meghaladja a megadott maximumot (10 000 000)", // Str::MaxIterationsErrorMessage
    "Hiba: Az integritás-ellenőrzés sikertelen, hibás jelszó vagy sérült/manipulált fájl", // Str::IntegrityCheckErrorMessage
    "Hiba: A jelszó nem lehet üres", // Str::EmptyPasswordErrorMessage
    "Hiba: A célfájl elérési útja egy mappa", // Str::OutputFileIsDirectoryErrorMessage
    "Hiba: A forrásfájl elérési útja egy mappa", // Str::InputFileIsDirectoryErrorMessage
    "Hiba: A célfájl elérési útja nem lehet üres", // Str::EmptyOutputFilePathErrorMessage
    "Hiba: A forrásfájl elérési útja nem lehet üres", // Str::EmptyInputFilePathErrorMessage
    "Hiba: A forrásfájl nem létezik", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Nyelv: Magyar", // Str::LanguageLabel
    "Jelszó", // Str::PasswordLabel
    "Jelszó hossza", // Str::PasswordLenghtLabel
    "Fájl", // Str::FileLabel
    "A fájl", // Str::TheFileLabel
    "Elérési út", // Str::PathLabel
    "Bemeneti fájl elérési útja", // Str::InputFilePathLabel
    "Kimeneti fájl elérési útja", // Str::OutputFilePathLabel
    "Elérési utak felcserélése", // Str::SwapPathsLabel
    "felül lesz írva", // Str::WillBeOverwrittenLabel
    "Titkosítás...", // Str::EncryptingText
    "Visszafejtés...", // Str::DecryptingText
    "Titkosítás", // Str::EncryptText
    "Visszafejtés", // Str::DecryptText
    "A fájl titkosítása sikeres", // Str::FileEncryptedMessage
    "A fájl visszafejtése sikeres", // Str::FileDecryptedMessage
    "Figyelem!", // Str::WarningTitle
    "Biztos benne?", // Str::AreYouSureTitle
    "Beállítások", // Str::SettingsTitle
    "Jelszógenerátor", // Str::GeneratePasswordTitle
    "Nyelv kiválasztása", // Str::SelectLanguageTitle
    "Igen", // Str::YesLabel
    "Nem", // Str::NoLabel
    "OK", // Str::OkLabel
    "Kimeneti formátum", // Str::OutFormatLabel
    "Felület beállításai", // Str::InterfaceSettingsLabel
    "Méret", // Str::InterfaceSizeLabel
    "Mód", // Str::ModeLabel
    "Normál", // Str::NormalModeLabel
    "Egyszerű szöveg", // Str::PlaintextModeLabel
    "Téma", // Str::InterfaceThemeLabel
    "Szín", // Str::InterfaceColorLabel
    "Alapértelmezett (egyszerű szöveg)", // Str::DefaultLabel
    "OpenSSL (bináris)", // Str::OpenSSLLabel
    "Jelszó használata", // Str::UsePasswordLabel
    "Másolás", // Str::CopyLabel
    "Ctrl + bal kattintás az SHA256 lekéréséhez", // Str::GetSHA256Text
    // Themes
    "Világos", // Str::LightThemeName
    "Sötét", // Str::DarkThemeName
    // Colors
    "Kék", // Str::BlueName
    "Ciánkék", // Str::CyanName
    "Zöld", // Str::GreenName
    "Limezöld", // Str::LimeName
    "Sárga", // Str::YellowName
    "Barna", // Str::BrownName
    "Narancs", // Str::OrangeName
    "Piros", // Str::RedName
    "Rózsaszín", // Str::PinkName
    "Lila", // Str::PurpleName
    "Szürke", // Str::GreyName
    "Fehér", // Str::WhiteName
    "Fekete", // Str::BlackName

};
static_assert(sizeof(textosHU) / sizeof(textosHU[0]) == N,
    "Faltan o sobran textos en hungaro: revisa que coincidan con Str::Count.");

// Svenska (sv)
constexpr const char* textosSV[] = {

    
    
    // Info
    "Tryck på Enter för att avsluta...", // Str::ExitInfoMessage
    "Aktivera endast om filens innehåll", // Str::PlainTextModeMessage_FirstLine
    "är oformaterad text", // Str::PlainTextModeMessage_SecondLine
    "Den krypterade filen sparas", // Str::DefaultCipherModeText_FirstLine
    "som utskrivbara tecken", // Str::DefaultCipherModeText_SecondLine
    "Den krypterade filen sparas i", // Str::OpenSSLCipherModeText_FirstLine
    "binärt format, kompatibelt med OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-iterationer:", // Str::PBKDF2IterationsText
    // Errors
    "Fel: felaktiga parametrar", // Str::WrongParamsText
    "Mottaget värde", // Str::InputValueText
    "Mottagen sökväg", // Str::InputPathText
    "Det mottagna värdet kunde inte konverteras till ett tal större än eller lika med 0", // Str::WrongNumberValueMessage
    "Den mottagna sökvägen motsvarar ingen befintlig fil", // Str::WrongPathValueMessage
    "Det angivna alternativet känns inte igen som en giltig parameter", // Str::InvalidOptionMessage
    "Angivet alternativ", // Str::EnteredOptionText
    "Okänt undantag", // Str::UnknownExceptionText
    "Det gick inte att initiera GLFW", // Str::GLFWErrorMessage
    "Det gick inte att initiera GLAD", // Str::GLADErrorMessage
    "Fel: Det gick inte att öppna filen för läsning", // Str::ReadFileErrorMessage
    "Fel vid läsning av filens innehåll", // Str::ErrorWhileReadingMessage
    "Fel: Det gick inte att öppna filen för skrivning", // Str::WriteFileErrorMessage
    "Fel: Den hexadecimala strängen måste ha ett jämnt antal tecken", // Str::HexStringErrorMessage
    "Fel: Ogiltigt hexadecimalt tecken i strängen", // Str::InvalidHexCharacterErrorMessage
    "Fel: Det gick inte att spara filen", // Str::SaveFileErrorMessage
    "Fel: Det gick inte att läsa in filen", // Str::LoadFileErrorMessage
    "Fel: Ogiltigt filformat (5 fält förväntades: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Fel: Antalet iterationer överskrider det fastställda maxvärdet (10 000 000)", // Str::MaxIterationsErrorMessage
    "Fel: Integritetskontrollen misslyckades, felaktigt lösenord eller skadad/manipulerad fil", // Str::IntegrityCheckErrorMessage
    "Fel: Lösenordet får inte vara tomt", // Str::EmptyPasswordErrorMessage
    "Fel: Sökvägen till målfilen är en mapp", // Str::OutputFileIsDirectoryErrorMessage
    "Fel: Sökvägen till källfilen är en mapp", // Str::InputFileIsDirectoryErrorMessage
    "Fel: Sökvägen till målfilen får inte vara tom", // Str::EmptyOutputFilePathErrorMessage
    "Fel: Sökvägen till källfilen får inte vara tom", // Str::EmptyInputFilePathErrorMessage
    "Fel: Källfilen finns inte", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Språk: Svenska", // Str::LanguageLabel
    "Lösenord", // Str::PasswordLabel
    "Lösenordslängd", // Str::PasswordLenghtLabel
    "Fil", // Str::FileLabel
    "Filen", // Str::TheFileLabel
    "Sökväg", // Str::PathLabel
    "Indatasökväg", // Str::InputFilePathLabel
    "Utdatasökväg", // Str::OutputFilePathLabel
    "Byt plats på sökvägar", // Str::SwapPathsLabel
    "kommer att skrivas över", // Str::WillBeOverwrittenLabel
    "Krypterar...", // Str::EncryptingText
    "Dekrypterar...", // Str::DecryptingText
    "Kryptera", // Str::EncryptText
    "Dekryptera", // Str::DecryptText
    "Filen har krypterats", // Str::FileEncryptedMessage
    "Filen har dekrypterats", // Str::FileDecryptedMessage
    "Varning!", // Str::WarningTitle
    "Är du säker?", // Str::AreYouSureTitle
    "Inställningar", // Str::SettingsTitle
    "Lösenordsgenerator", // Str::GeneratePasswordTitle
    "Välj språk", // Str::SelectLanguageTitle
    "Ja", // Str::YesLabel
    "Nej", // Str::NoLabel
    "OK", // Str::OkLabel
    "Utdataformat", // Str::OutFormatLabel
    "Gränssnittsinställningar", // Str::InterfaceSettingsLabel
    "Storlek", // Str::InterfaceSizeLabel
    "Läge", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Oformaterad text", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Färg", // Str::InterfaceColorLabel
    "Standard (oformaterad text)", // Str::DefaultLabel
    "OpenSSL (binär)", // Str::OpenSSLLabel
    "Använd detta lösenord", // Str::UsePasswordLabel
    "Kopiera", // Str::CopyLabel
    "Ctrl + vänsterklick för att få SHA256", // Str::GetSHA256Text
    // Themes
    "Ljust", // Str::LightThemeName
    "Mörkt", // Str::DarkThemeName
    // Colors
    "Blå", // Str::BlueName
    "Cyan", // Str::CyanName
    "Grön", // Str::GreenName
    "Limegrön", // Str::LimeName
    "Gul", // Str::YellowName
    "Brun", // Str::BrownName
    "Orange", // Str::OrangeName
    "Röd", // Str::RedName
    "Rosa", // Str::PinkName
    "Lila", // Str::PurpleName
    "Grå", // Str::GreyName
    "Vit", // Str::WhiteName
    "Svart", // Str::BlackName

};
static_assert(sizeof(textosSV) / sizeof(textosSV[0]) == N,
    "Faltan o sobran textos en sueco: revisa que coincidan con Str::Count.");

// Kreyòl ayisyen (ht)
constexpr const char* textosHT[] = {

    
    
    // Info
    "Peze Enter pou w soti...", // Str::ExitInfoMessage
    "Aktive sèlman si sa ki nan fichye a", // Str::PlainTextModeMessage_FirstLine
    "se tèks senp", // Str::PlainTextModeMessage_SecondLine
    "Fichye chifre a ap anrejistre", // Str::DefaultCipherModeText_FirstLine
    "kòm karaktè ki ka enprime", // Str::DefaultCipherModeText_SecondLine
    "Fichye chifre a ap anrejistre an fòma", // Str::OpenSSLCipherModeText_FirstLine
    "binè, ki konpatib ak OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterasyon PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Erè: paramèt yo pa kòrèk", // Str::WrongParamsText
    "Valè yo resevwa", // Str::InputValueText
    "Chemen yo resevwa", // Str::InputPathText
    "Nou pa t ka konvèti valè yo resevwa a an yon nonb ki pi gran oswa egal a 0", // Str::WrongNumberValueMessage
    "Chemen yo resevwa a pa koresponn ak okenn fichye ki egziste", // Str::WrongPathValueMessage
    "Opsyon yo antre a pa rekonèt kòm yon paramèt ki valab", // Str::InvalidOptionMessage
    "Opsyon yo antre", // Str::EnteredOptionText
    "Eksepsyon enkoni", // Str::UnknownExceptionText
    "Echèk inisyalizasyon GLFW", // Str::GLFWErrorMessage
    "Echèk inisyalizasyon GLAD", // Str::GLADErrorMessage
    "Erè: Nou pa t ka louvri fichye a pou li", // Str::ReadFileErrorMessage
    "Erè pandan lekti sa ki nan fichye a", // Str::ErrorWhileReadingMessage
    "Erè: Nou pa t ka louvri fichye a pou ekri", // Str::WriteFileErrorMessage
    "Erè: Chèn egzadesimal la dwe gen yon kantite karaktè ki pè", // Str::HexStringErrorMessage
    "Erè: Gen yon karaktè egzadesimal ki pa valab nan chèn nan", // Str::InvalidHexCharacterErrorMessage
    "Erè: Nou pa t ka anrejistre fichye a", // Str::SaveFileErrorMessage
    "Erè: Nou pa t ka chaje fichye a", // Str::LoadFileErrorMessage
    "Erè: Fòma fichye a pa valab (nou te tann 5 chan: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Erè: Kantite iterasyon yo depase maksimòm ki fikse a (10 000 000)", // Str::MaxIterationsErrorMessage
    "Erè: Verifikasyon entegrite a echwe, modpas la pa kòrèk oswa fichye a domaje/modifye", // Str::IntegrityCheckErrorMessage
    "Erè: Modpas la pa ka vid", // Str::EmptyPasswordErrorMessage
    "Erè: Chemen fichye destinasyon an se yon dosye", // Str::OutputFileIsDirectoryErrorMessage
    "Erè: Chemen fichye sous la se yon dosye", // Str::InputFileIsDirectoryErrorMessage
    "Erè: Chemen fichye destinasyon an pa ka vid", // Str::EmptyOutputFilePathErrorMessage
    "Erè: Chemen fichye sous la pa ka vid", // Str::EmptyInputFilePathErrorMessage
    "Erè: Fichye sous la pa egziste", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Lang: Kreyòl ayisyen", // Str::LanguageLabel
    "Modpas", // Str::PasswordLabel
    "Longè modpas la", // Str::PasswordLenghtLabel
    "Fichye", // Str::FileLabel
    "Fichye", // Str::TheFileLabel
    "Chemen", // Str::PathLabel
    "Chemen fichye antre", // Str::InputFilePathLabel
    "Chemen fichye sòti", // Str::OutputFilePathLabel
    "Chanje plas chemen yo", // Str::SwapPathsLabel
    "pral ranplase", // Str::WillBeOverwrittenLabel
    "Ap chifre...", // Str::EncryptingText
    "Ap dechifre...", // Str::DecryptingText
    "Chifre", // Str::EncryptText
    "Dechifre", // Str::DecryptText
    "Fichye a chifre avèk siksè", // Str::FileEncryptedMessage
    "Fichye a dechifre avèk siksè", // Str::FileDecryptedMessage
    "Atansyon!", // Str::WarningTitle
    "Èske ou si?", // Str::AreYouSureTitle
    "Paramèt", // Str::SettingsTitle
    "Jeneratè modpas", // Str::GeneratePasswordTitle
    "Chwazi lang", // Str::SelectLanguageTitle
    "Wi", // Str::YesLabel
    "Non", // Str::NoLabel
    "OK", // Str::OkLabel
    "Fòma sòti", // Str::OutFormatLabel
    "Paramèt koòdone", // Str::InterfaceSettingsLabel
    "Gwosè", // Str::InterfaceSizeLabel
    "Mòd", // Str::ModeLabel
    "Nòmal", // Str::NormalModeLabel
    "Tèks senp", // Str::PlaintextModeLabel
    "Tèm", // Str::InterfaceThemeLabel
    "Koulè", // Str::InterfaceColorLabel
    "Pa defo (tèks senp)", // Str::DefaultLabel
    "OpenSSL (binè)", // Str::OpenSSLLabel
    "Itilize modpas sa a", // Str::UsePasswordLabel
    "Kopye", // Str::CopyLabel
    "Ctrl + klike agoch pou jwenn SHA256", // Str::GetSHA256Text
    // Themes
    "Klè", // Str::LightThemeName
    "Fonse", // Str::DarkThemeName
    // Colors
    "Ble", // Str::BlueName
    "Siyan", // Str::CyanName
    "Vèt", // Str::GreenName
    "Vèt sitwon", // Str::LimeName
    "Jòn", // Str::YellowName
    "Mawon", // Str::BrownName
    "Zoranj", // Str::OrangeName
    "Wouj", // Str::RedName
    "Woz", // Str::PinkName
    "Mov", // Str::PurpleName
    "Gri", // Str::GreyName
    "Blan", // Str::WhiteName
    "Nwa", // Str::BlackName

};
static_assert(sizeof(textosHT) / sizeof(textosHT[0]) == N,
    "Faltan o sobran textos en criollo haitiano: revisa que coincidan con Str::Count.");

// Čeština (cs)
constexpr const char* textosCS[] = {

    
    
    // Info
    "Stiskněte Enter pro ukončení...", // Str::ExitInfoMessage
    "Povolte pouze v případě, že obsah", // Str::PlainTextModeMessage_FirstLine
    "souboru je prostý text", // Str::PlainTextModeMessage_SecondLine
    "Zašifrovaný soubor bude uložen", // Str::DefaultCipherModeText_FirstLine
    "jako tisknutelné znaky", // Str::DefaultCipherModeText_SecondLine
    "Zašifrovaný soubor bude uložen", // Str::OpenSSLCipherModeText_FirstLine
    "v binárním formátu kompatibilním s OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterace PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Chyba: nesprávné parametry", // Str::WrongParamsText
    "Přijatá hodnota", // Str::InputValueText
    "Přijatá cesta", // Str::InputPathText
    "Přijatou hodnotu nebylo možné převést na číslo větší nebo rovné 0", // Str::WrongNumberValueMessage
    "Přijatá cesta neodpovídá žádnému existujícímu souboru", // Str::WrongPathValueMessage
    "Zadaná volba není rozpoznána jako platný parametr", // Str::InvalidOptionMessage
    "Zadaná volba", // Str::EnteredOptionText
    "Neznámá výjimka", // Str::UnknownExceptionText
    "Nepodařilo se inicializovat GLFW", // Str::GLFWErrorMessage
    "Nepodařilo se inicializovat GLAD", // Str::GLADErrorMessage
    "Chyba: Soubor nelze otevřít pro čtení", // Str::ReadFileErrorMessage
    "Chyba při čtení obsahu souboru", // Str::ErrorWhileReadingMessage
    "Chyba: Soubor nelze otevřít pro zápis", // Str::WriteFileErrorMessage
    "Chyba: Šestnáctkový řetězec musí mít sudý počet znaků", // Str::HexStringErrorMessage
    "Chyba: Neplatný šestnáctkový znak v řetězci", // Str::InvalidHexCharacterErrorMessage
    "Chyba: Soubor nelze uložit", // Str::SaveFileErrorMessage
    "Chyba: Soubor nelze načíst", // Str::LoadFileErrorMessage
    "Chyba: Neplatný formát souboru (očekáváno 5 polí: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Chyba: Počet iterací překračuje stanovené maximum (10 000 000)", // Str::MaxIterationsErrorMessage
    "Chyba: Ověření integrity selhalo, nesprávné heslo nebo poškozený/upravený soubor", // Str::IntegrityCheckErrorMessage
    "Chyba: Heslo nemůže být prázdné", // Str::EmptyPasswordErrorMessage
    "Chyba: Cesta k cílovému souboru je složka", // Str::OutputFileIsDirectoryErrorMessage
    "Chyba: Cesta ke zdrojovému souboru je složka", // Str::InputFileIsDirectoryErrorMessage
    "Chyba: Cesta k cílovému souboru nemůže být prázdná", // Str::EmptyOutputFilePathErrorMessage
    "Chyba: Cesta ke zdrojovému souboru nemůže být prázdná", // Str::EmptyInputFilePathErrorMessage
    "Chyba: Zdrojový soubor neexistuje", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Jazyk: Čeština", // Str::LanguageLabel
    "Heslo", // Str::PasswordLabel
    "Délka hesla", // Str::PasswordLenghtLabel
    "Soubor", // Str::FileLabel
    "Soubor", // Str::TheFileLabel
    "Cesta", // Str::PathLabel
    "Cesta ke vstupnímu souboru", // Str::InputFilePathLabel
    "Cesta k výstupnímu souboru", // Str::OutputFilePathLabel
    "Prohodit cesty", // Str::SwapPathsLabel
    "bude přepsán", // Str::WillBeOverwrittenLabel
    "Šifrování...", // Str::EncryptingText
    "Dešifrování...", // Str::DecryptingText
    "Zašifrovat", // Str::EncryptText
    "Dešifrovat", // Str::DecryptText
    "Soubor byl úspěšně zašifrován", // Str::FileEncryptedMessage
    "Soubor byl úspěšně dešifrován", // Str::FileDecryptedMessage
    "Upozornění!", // Str::WarningTitle
    "Jste si jisti?", // Str::AreYouSureTitle
    "Nastavení", // Str::SettingsTitle
    "Generátor hesel", // Str::GeneratePasswordTitle
    "Vyberte jazyk", // Str::SelectLanguageTitle
    "Ano", // Str::YesLabel
    "Ne", // Str::NoLabel
    "OK", // Str::OkLabel
    "Výstupní formát", // Str::OutFormatLabel
    "Nastavení rozhraní", // Str::InterfaceSettingsLabel
    "Velikost", // Str::InterfaceSizeLabel
    "Režim", // Str::ModeLabel
    "Normální", // Str::NormalModeLabel
    "Prostý text", // Str::PlaintextModeLabel
    "Motiv", // Str::InterfaceThemeLabel
    "Barva", // Str::InterfaceColorLabel
    "Výchozí (prostý text)", // Str::DefaultLabel
    "OpenSSL (binární)", // Str::OpenSSLLabel
    "Použít toto heslo", // Str::UsePasswordLabel
    "Kopírovat", // Str::CopyLabel
    "Ctrl + levé kliknutí pro získání SHA256", // Str::GetSHA256Text
    // Themes
    "Světlý", // Str::LightThemeName
    "Tmavý", // Str::DarkThemeName
    // Colors
    "Modrá", // Str::BlueName
    "Azurová", // Str::CyanName
    "Zelená", // Str::GreenName
    "Limetková", // Str::LimeName
    "Žlutá", // Str::YellowName
    "Hnědá", // Str::BrownName
    "Oranžová", // Str::OrangeName
    "Červená", // Str::RedName
    "Růžová", // Str::PinkName
    "Fialová", // Str::PurpleName
    "Šedá", // Str::GreyName
    "Bílá", // Str::WhiteName
    "Černá", // Str::BlackName

};
static_assert(sizeof(textosCS) / sizeof(textosCS[0]) == N,
    "Faltan o sobran textos en checo: revisa que coincidan con Str::Count.");

// Српски (sr)
constexpr const char* textosSR[] = {

    
    
    // Info
    "Притисните Enter за излаз...", // Str::ExitInfoMessage
    "Омогућите само ако је садржај", // Str::PlainTextModeMessage_FirstLine
    "датотеке обичан текст", // Str::PlainTextModeMessage_SecondLine
    "Шифрована датотека биће сачувана", // Str::DefaultCipherModeText_FirstLine
    "као знакови који се могу штампати", // Str::DefaultCipherModeText_SecondLine
    "Шифрована датотека биће сачувана у бинарном", // Str::OpenSSLCipherModeText_FirstLine
    "формату, компатибилном са OpenSSL-ом", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 итерације:", // Str::PBKDF2IterationsText
    // Errors
    "Грешка: нетачни параметри", // Str::WrongParamsText
    "Примљена вредност", // Str::InputValueText
    "Примљена путања", // Str::InputPathText
    "Примљену вредност није било могуће претворити у број већи од 0 или једнак 0", // Str::WrongNumberValueMessage
    "Примљена путања не одговара ниједној постојећој датотеци", // Str::WrongPathValueMessage
    "Унета опција није препозната као важећи параметар", // Str::InvalidOptionMessage
    "Унета опција", // Str::EnteredOptionText
    "Непознат изузетак", // Str::UnknownExceptionText
    "Покретање GLFW-а није успело", // Str::GLFWErrorMessage
    "Покретање GLAD-а није успело", // Str::GLADErrorMessage
    "Грешка: Није могуће отворити датотеку за читање", // Str::ReadFileErrorMessage
    "Грешка при читању садржаја датотеке", // Str::ErrorWhileReadingMessage
    "Грешка: Није могуће отворити датотеку за писање", // Str::WriteFileErrorMessage
    "Грешка: Хексадецимални низ мора имати паран број знакова", // Str::HexStringErrorMessage
    "Грешка: Неважећи хексадецимални знак у низу", // Str::InvalidHexCharacterErrorMessage
    "Грешка: Није могуће сачувати датотеку", // Str::SaveFileErrorMessage
    "Грешка: Није могуће учитати датотеку", // Str::LoadFileErrorMessage
    "Грешка: Неважећи формат датотеке (очекивано 5 поља: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Грешка: Број итерација премашује утврђени максимум (10.000.000)", // Str::MaxIterationsErrorMessage
    "Грешка: Провера интегритета није успела, нетачна лозинка или оштећена/измењена датотека", // Str::IntegrityCheckErrorMessage
    "Грешка: Лозинка не може бити празна", // Str::EmptyPasswordErrorMessage
    "Грешка: Путања одредишне датотеке је фасцикла", // Str::OutputFileIsDirectoryErrorMessage
    "Грешка: Путања изворне датотеке је фасцикла", // Str::InputFileIsDirectoryErrorMessage
    "Грешка: Путања одредишне датотеке не може бити празна", // Str::EmptyOutputFilePathErrorMessage
    "Грешка: Путања изворне датотеке не може бити празна", // Str::EmptyInputFilePathErrorMessage
    "Грешка: Изворна датотека не постоји", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Језик: Српски", // Str::LanguageLabel
    "Лозинка", // Str::PasswordLabel
    "Дужина лозинке", // Str::PasswordLenghtLabel
    "Датотека", // Str::FileLabel
    "Датотека", // Str::TheFileLabel
    "Путања", // Str::PathLabel
    "Путања улазне датотеке", // Str::InputFilePathLabel
    "Путања излазне датотеке", // Str::OutputFilePathLabel
    "Замени путање", // Str::SwapPathsLabel
    "биће замењена", // Str::WillBeOverwrittenLabel
    "Шифровање...", // Str::EncryptingText
    "Дешифровање...", // Str::DecryptingText
    "Шифруј", // Str::EncryptText
    "Дешифруј", // Str::DecryptText
    "Датотека је успешно шифрована", // Str::FileEncryptedMessage
    "Датотека је успешно дешифрована", // Str::FileDecryptedMessage
    "Упозорење!", // Str::WarningTitle
    "Да ли сте сигурни?", // Str::AreYouSureTitle
    "Подешавања", // Str::SettingsTitle
    "Генератор лозинки", // Str::GeneratePasswordTitle
    "Изаберите језик", // Str::SelectLanguageTitle
    "Да", // Str::YesLabel
    "Не", // Str::NoLabel
    "У реду", // Str::OkLabel
    "Излазни формат", // Str::OutFormatLabel
    "Подешавања интерфејса", // Str::InterfaceSettingsLabel
    "Величина", // Str::InterfaceSizeLabel
    "Режим", // Str::ModeLabel
    "Нормалан", // Str::NormalModeLabel
    "Обичан текст", // Str::PlaintextModeLabel
    "Тема", // Str::InterfaceThemeLabel
    "Боја", // Str::InterfaceColorLabel
    "Подразумевано (обичан текст)", // Str::DefaultLabel
    "OpenSSL (бинарни)", // Str::OpenSSLLabel
    "Користи ову лозинку", // Str::UsePasswordLabel
    "Копирај", // Str::CopyLabel
    "Ctrl + леви клик за добијање SHA256", // Str::GetSHA256Text
    // Themes
    "Светла", // Str::LightThemeName
    "Тамна", // Str::DarkThemeName
    // Colors
    "Плава", // Str::BlueName
    "Цијан", // Str::CyanName
    "Зелена", // Str::GreenName
    "Лимета", // Str::LimeName
    "Жута", // Str::YellowName
    "Браон", // Str::BrownName
    "Наранџаста", // Str::OrangeName
    "Црвена", // Str::RedName
    "Розе", // Str::PinkName
    "Љубичаста", // Str::PurpleName
    "Сива", // Str::GreyName
    "Бела", // Str::WhiteName
    "Црна", // Str::BlackName

};
static_assert(sizeof(textosSR) / sizeof(textosSR[0]) == N,
    "Faltan o sobran textos en serbio: revisa que coincidan con Str::Count.");

// Català (ca)
constexpr const char* textosCA[] = {

    
    
    // Info
    "Premeu Enter per sortir...", // Str::ExitInfoMessage
    "Activeu-ho només si el contingut", // Str::PlainTextModeMessage_FirstLine
    "del fitxer és text pla", // Str::PlainTextModeMessage_SecondLine
    "El fitxer xifrat es desarà", // Str::DefaultCipherModeText_FirstLine
    "com a caràcters imprimibles", // Str::DefaultCipherModeText_SecondLine
    "El fitxer xifrat es desarà en", // Str::OpenSSLCipherModeText_FirstLine
    "format binari, compatible amb OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iteracions PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Error: paràmetres incorrectes", // Str::WrongParamsText
    "Valor rebut", // Str::InputValueText
    "Camí rebut", // Str::InputPathText
    "No s'ha pogut convertir el valor rebut en un nombre més gran o igual que 0", // Str::WrongNumberValueMessage
    "El camí rebut no correspon a cap fitxer existent", // Str::WrongPathValueMessage
    "L'opció introduïda no es reconeix com a paràmetre vàlid", // Str::InvalidOptionMessage
    "Opció introduïda", // Str::EnteredOptionText
    "Excepció desconeguda", // Str::UnknownExceptionText
    "No s'ha pogut inicialitzar GLFW", // Str::GLFWErrorMessage
    "No s'ha pogut inicialitzar GLAD", // Str::GLADErrorMessage
    "Error: No s'ha pogut obrir el fitxer per a la lectura", // Str::ReadFileErrorMessage
    "Error en llegir el contingut del fitxer", // Str::ErrorWhileReadingMessage
    "Error: No s'ha pogut obrir el fitxer per a l'escriptura", // Str::WriteFileErrorMessage
    "Error: La cadena hexadecimal ha de tenir un nombre parell de caràcters", // Str::HexStringErrorMessage
    "Error: Caràcter hexadecimal no vàlid a la cadena", // Str::InvalidHexCharacterErrorMessage
    "Error: No s'ha pogut desar el fitxer", // Str::SaveFileErrorMessage
    "Error: No s'ha pogut carregar el fitxer", // Str::LoadFileErrorMessage
    "Error: Format de fitxer no vàlid (s'esperaven 5 camps: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Error: El nombre d'iteracions supera el màxim establert (10.000.000)", // Str::MaxIterationsErrorMessage
    "Error: La verificació d'integritat ha fallat, contrasenya incorrecta o fitxer malmès/manipulat", // Str::IntegrityCheckErrorMessage
    "Error: La contrasenya no pot estar buida", // Str::EmptyPasswordErrorMessage
    "Error: El camí del fitxer de destinació és un directori", // Str::OutputFileIsDirectoryErrorMessage
    "Error: El camí del fitxer d'origen és un directori", // Str::InputFileIsDirectoryErrorMessage
    "Error: El camí del fitxer de destinació no pot estar buit", // Str::EmptyOutputFilePathErrorMessage
    "Error: El camí del fitxer d'origen no pot estar buit", // Str::EmptyInputFilePathErrorMessage
    "Error: El fitxer d'origen no existeix", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Idioma: Català", // Str::LanguageLabel
    "Contrasenya", // Str::PasswordLabel
    "Longitud de la contrasenya", // Str::PasswordLenghtLabel
    "Fitxer", // Str::FileLabel
    "El fitxer", // Str::TheFileLabel
    "Camí", // Str::PathLabel
    "Camí d'entrada", // Str::InputFilePathLabel
    "Camí de sortida", // Str::OutputFilePathLabel
    "Intercanvia els camins", // Str::SwapPathsLabel
    "se sobreescriurà", // Str::WillBeOverwrittenLabel
    "S'està xifrant...", // Str::EncryptingText
    "S'està desxifrant...", // Str::DecryptingText
    "Xifra", // Str::EncryptText
    "Desxifra", // Str::DecryptText
    "Fitxer xifrat correctament", // Str::FileEncryptedMessage
    "Fitxer desxifrat correctament", // Str::FileDecryptedMessage
    "Atenció!", // Str::WarningTitle
    "N'esteu segur?", // Str::AreYouSureTitle
    "Configuració", // Str::SettingsTitle
    "Generador de contrasenyes", // Str::GeneratePasswordTitle
    "Selecciona l'idioma", // Str::SelectLanguageTitle
    "Sí", // Str::YesLabel
    "No", // Str::NoLabel
    "D'acord", // Str::OkLabel
    "Format de sortida", // Str::OutFormatLabel
    "Configuració de la interfície", // Str::InterfaceSettingsLabel
    "Mida", // Str::InterfaceSizeLabel
    "Mode", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Text pla", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Color", // Str::InterfaceColorLabel
    "Per defecte (text pla)", // Str::DefaultLabel
    "OpenSSL (binari)", // Str::OpenSSLLabel
    "Utilitza aquesta contrasenya", // Str::UsePasswordLabel
    "Copia", // Str::CopyLabel
    "Ctrl + clic esquerre per obtenir l'SHA256", // Str::GetSHA256Text
    // Themes
    "Clar", // Str::LightThemeName
    "Fosc", // Str::DarkThemeName
    // Colors
    "Blau", // Str::BlueName
    "Cian", // Str::CyanName
    "Verd", // Str::GreenName
    "Verd llima", // Str::LimeName
    "Groc", // Str::YellowName
    "Marró", // Str::BrownName
    "Taronja", // Str::OrangeName
    "Vermell", // Str::RedName
    "Rosa", // Str::PinkName
    "Lila", // Str::PurpleName
    "Gris", // Str::GreyName
    "Blanc", // Str::WhiteName
    "Negre", // Str::BlackName

};
static_assert(sizeof(textosCA) / sizeof(textosCA[0]) == N,
    "Faltan o sobran textos en catalan: revisa que coincidan con Str::Count.");

// ትግርኛ (ti)
constexpr const char* textosTI[] = {

    
    
    // Info
    "ንምውጻእ Enter ጠውቑ...", // Str::ExitInfoMessage
    "ትሕዝቶ ፋይል ቀሊል ጽሑፍ", // Str::PlainTextModeMessage_FirstLine
    "እንተኾይኑ ጥራይ ኣንቅሑ", // Str::PlainTextModeMessage_SecondLine
    "እቲ ምስጢራዊ ዝተገብረ ፋይል", // Str::DefaultCipherModeText_FirstLine
    "ከም ዝሕተሙ ፊደላት ክዕቀብ እዩ", // Str::DefaultCipherModeText_SecondLine
    "እቲ ምስጢራዊ ዝተገብረ ፋይል ምስ OpenSSL", // Str::OpenSSLCipherModeText_FirstLine
    "ብዝሰማማዕ ክልተኣዊ ቅርጺ ክዕቀብ እዩ", // Str::OpenSSLCipherModeText_SecondLine
    "ድግግማት PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "ጌጋ: ዘይቅኑዕ መለክዒታት", // Str::WrongParamsText
    "ዝተቐበልናዮ ዋጋ", // Str::InputValueText
    "ዝተቐበልናዮ መንገዲ", // Str::InputPathText
    "ዝተቐበልናዮ ዋጋ ናብ ካብ 0 ዝዓቢ ወይ ምስ 0 ማዕረ ዝኾነ ቁጽሪ ክቕየር ኣይከኣለን", // Str::WrongNumberValueMessage
    "ዝተቐበልናዮ መንገዲ ምስ ዝኾነ ዘሎ ፋይል ኣይሰማማዕን", // Str::WrongPathValueMessage
    "ዝኣተወ ምርጫ ከም ቅኑዕ መለክዒ ኣይተፈልጠን", // Str::InvalidOptionMessage
    "ዝኣተወ ምርጫ", // Str::EnteredOptionText
    "ዘይፍለጥ ፍሉይ ኩነታት", // Str::UnknownExceptionText
    "GLFW ምጅማር ኣይተኻእለን", // Str::GLFWErrorMessage
    "GLAD ምጅማር ኣይተኻእለን", // Str::GLADErrorMessage
    "ጌጋ: ፋይል ንምንባብ ክኽፈት ኣይከኣለን", // Str::ReadFileErrorMessage
    "ትሕዝቶ ፋይል ኣብ ምንባብ ጌጋ ተፈጢሩ", // Str::ErrorWhileReadingMessage
    "ጌጋ: ፋይል ንምጽሓፍ ክኽፈት ኣይከኣለን", // Str::WriteFileErrorMessage
    "ጌጋ: ብዝሒ ፊደላት ናይ ሄክሳዴሲማል ሕብረ-ፊደል ጽምዲ ቁጽሪ ክኸውን ኣለዎ", // Str::HexStringErrorMessage
    "ጌጋ: ኣብቲ ሕብረ-ፊደል ዘይቅኑዕ ናይ ሄክሳዴሲማል ፊደል ኣሎ", // Str::InvalidHexCharacterErrorMessage
    "ጌጋ: ፋይል ክዕቀብ ኣይከኣለን", // Str::SaveFileErrorMessage
    "ጌጋ: ፋይል ክጽዓን ኣይከኣለን", // Str::LoadFileErrorMessage
    "ጌጋ: ዘይቅኑዕ ቅርጺ ፋይል (5 መዳያት ይጽበ ነይሩ: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "ጌጋ: ብዝሒ ድግግማት ካብቲ ዝተወሰነ ዝለዓለ ደረት (10,000,000) ይበዝሕ", // Str::MaxIterationsErrorMessage
    "ጌጋ: ምርግጋጽ ምሉእነት ፈሺሉ፣ ጌጋ ናይ ምሕላፍ ቃል ወይ ዝተበላሸወ/ዝተቐየረ ፋይል", // Str::IntegrityCheckErrorMessage
    "ጌጋ: ናይ ምሕላፍ ቃል ባዶ ክኸውን ኣይክእልን", // Str::EmptyPasswordErrorMessage
    "ጌጋ: መንገዲ ናይቲ መዕለቢ ፋይል ማህደር እዩ", // Str::OutputFileIsDirectoryErrorMessage
    "ጌጋ: መንገዲ ናይቲ ምንጪ ፋይል ማህደር እዩ", // Str::InputFileIsDirectoryErrorMessage
    "ጌጋ: መንገዲ ናይቲ መዕለቢ ፋይል ባዶ ክኸውን ኣይክእልን", // Str::EmptyOutputFilePathErrorMessage
    "ጌጋ: መንገዲ ናይቲ ምንጪ ፋይል ባዶ ክኸውን ኣይክእልን", // Str::EmptyInputFilePathErrorMessage
    "ጌጋ: እቲ ምንጪ ፋይል የለን", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "ቋንቋ: ትግርኛ", // Str::LanguageLabel
    "ናይ ምሕላፍ ቃል", // Str::PasswordLabel
    "ንውሓት ናይ ምሕላፍ ቃል", // Str::PasswordLenghtLabel
    "ፋይል", // Str::FileLabel
    "እቲ ፋይል", // Str::TheFileLabel
    "መንገዲ", // Str::PathLabel
    "መንገዲ ናይ እታዊ ፋይል", // Str::InputFilePathLabel
    "መንገዲ ናይ ውጽኢት ፋይል", // Str::OutputFilePathLabel
    "መንገድታት ቀያይር", // Str::SwapPathsLabel
    "ክትካእ እዩ", // Str::WillBeOverwrittenLabel
    "ምስጢራዊ ይግበር ኣሎ...", // Str::EncryptingText
    "ምስጢር ይፍታሕ ኣሎ...", // Str::DecryptingText
    "ምስጢራዊ ግበር", // Str::EncryptText
    "ምስጢር ፍታሕ", // Str::DecryptText
    "ፋይል ብዓወት ምስጢራዊ ተገይሩ", // Str::FileEncryptedMessage
    "ምስጢር ፋይል ብዓወት ተፈቲሑ", // Str::FileDecryptedMessage
    "መጠንቀቕታ!", // Str::WarningTitle
    "ርግጸኛ ዲኹም?", // Str::AreYouSureTitle
    "ቅጥዕታት", // Str::SettingsTitle
    "መፍጠሪ ናይ ምሕላፍ ቃል", // Str::GeneratePasswordTitle
    "ቋንቋ ምረጹ", // Str::SelectLanguageTitle
    "እወ", // Str::YesLabel
    "ኣይፋል", // Str::NoLabel
    "ሕራይ", // Str::OkLabel
    "ቅርጺ ውጽኢት", // Str::OutFormatLabel
    "ቅጥዕታት መገናኛ", // Str::InterfaceSettingsLabel
    "ዓቐን", // Str::InterfaceSizeLabel
    "ኣገባብ", // Str::ModeLabel
    "ልሙድ", // Str::NormalModeLabel
    "ቀሊል ጽሑፍ", // Str::PlaintextModeLabel
    "ቴማ", // Str::InterfaceThemeLabel
    "ሕብሪ", // Str::InterfaceColorLabel
    "ንቡር (ቀሊል ጽሑፍ)", // Str::DefaultLabel
    "OpenSSL (ክልተኣዊ)", // Str::OpenSSLLabel
    "ነዚ ናይ ምሕላፍ ቃል ተጠቐም", // Str::UsePasswordLabel
    "ቅዳሕ", // Str::CopyLabel
    "SHA256 ንምርካብ Ctrl + ጸጋማይ ጠውቕ", // Str::GetSHA256Text
    // Themes
    "ብሩህ", // Str::LightThemeName
    "ጸልማት", // Str::DarkThemeName
    // Colors
    "ሰማያዊ", // Str::BlueName
    "ሰማያዊ ብሩህ", // Str::CyanName
    "ቀጠልያ", // Str::GreenName
    "ብሩህ ቀጠልያ", // Str::LimeName
    "ብጫ", // Str::YellowName
    "ቡናዊ", // Str::BrownName
    "ኣራንሺ", // Str::OrangeName
    "ቀይሕ", // Str::RedName
    "ሮዛ", // Str::PinkName
    "ሊላ", // Str::PurpleName
    "ሓሙኽሽቲ", // Str::GreyName
    "ጻዕዳ", // Str::WhiteName
    "ጸሊም", // Str::BlackName

};
static_assert(sizeof(textosTI) / sizeof(textosTI[0]) == N,
    "Faltan o sobran textos en tigrina: revisa que coincidan con Str::Count.");

// Български (bg)
constexpr const char* textosBG[] = {

    
    
    // Info
    "Натиснете Enter за изход...", // Str::ExitInfoMessage
    "Активирайте само ако съдържанието", // Str::PlainTextModeMessage_FirstLine
    "на файла е обикновен текст", // Str::PlainTextModeMessage_SecondLine
    "Шифрованият файл ще бъде запазен", // Str::DefaultCipherModeText_FirstLine
    "като символи за печат", // Str::DefaultCipherModeText_SecondLine
    "Шифрованият файл ще бъде запазен", // Str::OpenSSLCipherModeText_FirstLine
    "в двоичен формат, съвместим с OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Итерации на PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Грешка: неправилни параметри", // Str::WrongParamsText
    "Получена стойност", // Str::InputValueText
    "Получен път", // Str::InputPathText
    "Получената стойност не може да бъде преобразувана в число, по-голямо или равно на 0", // Str::WrongNumberValueMessage
    "Полученият път не съответства на нито един съществуващ файл", // Str::WrongPathValueMessage
    "Въведената опция не е разпозната като валиден параметър", // Str::InvalidOptionMessage
    "Въведена опция", // Str::EnteredOptionText
    "Неизвестно изключение", // Str::UnknownExceptionText
    "Неуспешно инициализиране на GLFW", // Str::GLFWErrorMessage
    "Неуспешно инициализиране на GLAD", // Str::GLADErrorMessage
    "Грешка: Файлът не може да бъде отворен за четене", // Str::ReadFileErrorMessage
    "Грешка при четене на съдържанието на файла", // Str::ErrorWhileReadingMessage
    "Грешка: Файлът не може да бъде отворен за запис", // Str::WriteFileErrorMessage
    "Грешка: Шестнадесетичният низ трябва да има четен брой символи", // Str::HexStringErrorMessage
    "Грешка: Невалиден шестнадесетичен символ в низа", // Str::InvalidHexCharacterErrorMessage
    "Грешка: Файлът не може да бъде запазен", // Str::SaveFileErrorMessage
    "Грешка: Файлът не може да бъде зареден", // Str::LoadFileErrorMessage
    "Грешка: Невалиден формат на файла (очакват се 5 полета: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Грешка: Броят итерации надвишава установения максимум (10 000 000)", // Str::MaxIterationsErrorMessage
    "Грешка: Проверката за цялост е неуспешна, грешна парола или повреден/подправен файл", // Str::IntegrityCheckErrorMessage
    "Грешка: Паролата не може да бъде празна", // Str::EmptyPasswordErrorMessage
    "Грешка: Пътят на целевия файл е папка", // Str::OutputFileIsDirectoryErrorMessage
    "Грешка: Пътят на изходния файл е папка", // Str::InputFileIsDirectoryErrorMessage
    "Грешка: Пътят на целевия файл не може да бъде празен", // Str::EmptyOutputFilePathErrorMessage
    "Грешка: Пътят на изходния файл не може да бъде празен", // Str::EmptyInputFilePathErrorMessage
    "Грешка: Изходният файл не съществува", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Език: Български", // Str::LanguageLabel
    "Парола", // Str::PasswordLabel
    "Дължина на паролата", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файлът", // Str::TheFileLabel
    "Път", // Str::PathLabel
    "Път до входния файл", // Str::InputFilePathLabel
    "Път до изходящия файл", // Str::OutputFilePathLabel
    "Размяна на пътищата", // Str::SwapPathsLabel
    "ще бъде презаписан", // Str::WillBeOverwrittenLabel
    "Шифроване...", // Str::EncryptingText
    "Дешифроване...", // Str::DecryptingText
    "Шифроване", // Str::EncryptText
    "Дешифроване", // Str::DecryptText
    "Файлът е шифрован успешно", // Str::FileEncryptedMessage
    "Файлът е дешифрован успешно", // Str::FileDecryptedMessage
    "Внимание!", // Str::WarningTitle
    "Сигурни ли сте?", // Str::AreYouSureTitle
    "Настройки", // Str::SettingsTitle
    "Генератор на пароли", // Str::GeneratePasswordTitle
    "Изберете език", // Str::SelectLanguageTitle
    "Да", // Str::YesLabel
    "Не", // Str::NoLabel
    "OK", // Str::OkLabel
    "Изходящ формат", // Str::OutFormatLabel
    "Настройки на интерфейса", // Str::InterfaceSettingsLabel
    "Размер", // Str::InterfaceSizeLabel
    "Режим", // Str::ModeLabel
    "Нормален", // Str::NormalModeLabel
    "Обикновен текст", // Str::PlaintextModeLabel
    "Тема", // Str::InterfaceThemeLabel
    "Цвят", // Str::InterfaceColorLabel
    "По подразбиране (обикновен текст)", // Str::DefaultLabel
    "OpenSSL (двоичен)", // Str::OpenSSLLabel
    "Използвай тази парола", // Str::UsePasswordLabel
    "Копирай", // Str::CopyLabel
    "Ctrl + ляв бутон за получаване на SHA256", // Str::GetSHA256Text
    // Themes
    "Светла", // Str::LightThemeName
    "Тъмна", // Str::DarkThemeName
    // Colors
    "Син", // Str::BlueName
    "Синьозелен", // Str::CyanName
    "Зелен", // Str::GreenName
    "Лайм", // Str::LimeName
    "Жълт", // Str::YellowName
    "Кафяв", // Str::BrownName
    "Оранжев", // Str::OrangeName
    "Червен", // Str::RedName
    "Розов", // Str::PinkName
    "Лилав", // Str::PurpleName
    "Сив", // Str::GreyName
    "Бял", // Str::WhiteName
    "Черен", // Str::BlackName

};
static_assert(sizeof(textosBG) / sizeof(textosBG[0]) == N,
    "Faltan o sobran textos en bulgaro: revisa que coincidan con Str::Count.");

// Тоҷикӣ (tg)
constexpr const char* textosTG[] = {

    
    
    // Info
    "Барои баромадан Enter-ро пахш кунед...", // Str::ExitInfoMessage
    "Танҳо дар сурате фаъол кунед, ки", // Str::PlainTextModeMessage_FirstLine
    "мундариҷаи файл матни оддӣ бошад", // Str::PlainTextModeMessage_SecondLine
    "Файли рамзгузоришуда ҳамчун", // Str::DefaultCipherModeText_FirstLine
    "аломатҳои чопшаванда нигоҳ дошта мешавад", // Str::DefaultCipherModeText_SecondLine
    "Файли рамзгузоришуда дар формати дуӣ,", // Str::OpenSSLCipherModeText_FirstLine
    "мувофиқ бо OpenSSL, нигоҳ дошта мешавад", // Str::OpenSSLCipherModeText_SecondLine
    "Такрорҳои PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Хато: параметрҳои нодуруст", // Str::WrongParamsText
    "Қимати гирифташуда", // Str::InputValueText
    "Роҳи гирифташуда", // Str::InputPathText
    "Қимати гирифташударо ба адади аз 0 калон ё ба 0 баробар табдил додан ғайриимкон буд", // Str::WrongNumberValueMessage
    "Роҳи гирифташуда ба ягон файли мавҷуда мувофиқат намекунад", // Str::WrongPathValueMessage
    "Интихоби воридшуда ҳамчун параметри дуруст шинохта нашуд", // Str::InvalidOptionMessage
    "Интихоби воридшуда", // Str::EnteredOptionText
    "Истиснои номаълум", // Str::UnknownExceptionText
    "Оғоз кардани GLFW муяссар нашуд", // Str::GLFWErrorMessage
    "Оғоз кардани GLAD муяссар нашуд", // Str::GLADErrorMessage
    "Хато: Файлро барои хондан кушодан ғайриимкон аст", // Str::ReadFileErrorMessage
    "Ҳангоми хондани мундариҷаи файл хато рух дод", // Str::ErrorWhileReadingMessage
    "Хато: Файлро барои навиштан кушодан ғайриимкон аст", // Str::WriteFileErrorMessage
    "Хато: Шумораи аломатҳои сатри шонздаҳӣ бояд ҷуфт бошад", // Str::HexStringErrorMessage
    "Хато: Дар сатр аломати шонздаҳии нодуруст ҳаст", // Str::InvalidHexCharacterErrorMessage
    "Хато: Файлро нигоҳ доштан ғайриимкон аст", // Str::SaveFileErrorMessage
    "Хато: Файлро бор кардан ғайриимкон аст", // Str::LoadFileErrorMessage
    "Хато: Формати файл нодуруст аст (5 майдон интизор буд: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Хато: Шумораи такрорҳо аз ҳадди аксари муқарраршуда зиёд аст (10 000 000)", // Str::MaxIterationsErrorMessage
    "Хато: Санҷиши яклухтӣ ноком шуд, ниҳонвожа нодуруст аст ё файл вайрон/тағйир дода шудааст", // Str::IntegrityCheckErrorMessage
    "Хато: Ниҳонвожа наметавонад холӣ бошад", // Str::EmptyPasswordErrorMessage
    "Хато: Роҳи файли таъинотӣ ҷузвдон аст", // Str::OutputFileIsDirectoryErrorMessage
    "Хато: Роҳи файли манбаъ ҷузвдон аст", // Str::InputFileIsDirectoryErrorMessage
    "Хато: Роҳи файли таъинотӣ наметавонад холӣ бошад", // Str::EmptyOutputFilePathErrorMessage
    "Хато: Роҳи файли манбаъ наметавонад холӣ бошад", // Str::EmptyInputFilePathErrorMessage
    "Хато: Файли манбаъ вуҷуд надорад", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Забон: Тоҷикӣ", // Str::LanguageLabel
    "Ниҳонвожа", // Str::PasswordLabel
    "Дарозии ниҳонвожа", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файл", // Str::TheFileLabel
    "Роҳ", // Str::PathLabel
    "Роҳи файли воридотӣ", // Str::InputFilePathLabel
    "Роҳи файли содиротӣ", // Str::OutputFilePathLabel
    "Ҷойи роҳҳоро иваз кардан", // Str::SwapPathsLabel
    "аз нав навишта мешавад", // Str::WillBeOverwrittenLabel
    "Рамзгузорӣ...", // Str::EncryptingText
    "Рамзкушоӣ...", // Str::DecryptingText
    "Рамзгузорӣ", // Str::EncryptText
    "Рамзкушоӣ", // Str::DecryptText
    "Файл бомуваффақият рамзгузорӣ шуд", // Str::FileEncryptedMessage
    "Файл бомуваффақият рамзкушоӣ шуд", // Str::FileDecryptedMessage
    "Огоҳӣ!", // Str::WarningTitle
    "Шумо боварӣ доред?", // Str::AreYouSureTitle
    "Танзимот", // Str::SettingsTitle
    "Генератори ниҳонвожа", // Str::GeneratePasswordTitle
    "Забонро интихоб кунед", // Str::SelectLanguageTitle
    "Ҳа", // Str::YesLabel
    "Не", // Str::NoLabel
    "Хуб", // Str::OkLabel
    "Формати содирот", // Str::OutFormatLabel
    "Танзимоти интерфейс", // Str::InterfaceSettingsLabel
    "Андоза", // Str::InterfaceSizeLabel
    "Реҷа", // Str::ModeLabel
    "Муқаррарӣ", // Str::NormalModeLabel
    "Матни оддӣ", // Str::PlaintextModeLabel
    "Мавзӯъ", // Str::InterfaceThemeLabel
    "Ранг", // Str::InterfaceColorLabel
    "Пешфарз (матни оддӣ)", // Str::DefaultLabel
    "OpenSSL (дуӣ)", // Str::OpenSSLLabel
    "Ин ниҳонвожаро истифода баред", // Str::UsePasswordLabel
    "Нусха бардоштан", // Str::CopyLabel
    "Барои гирифтани SHA256 Ctrl + тугмаи чапро зер кунед", // Str::GetSHA256Text
    // Themes
    "Равшан", // Str::LightThemeName
    "Торик", // Str::DarkThemeName
    // Colors
    "Кабуд", // Str::BlueName
    "Осмонӣ", // Str::CyanName
    "Сабз", // Str::GreenName
    "Сабзи равшан", // Str::LimeName
    "Зард", // Str::YellowName
    "Қаҳваранг", // Str::BrownName
    "Норанҷӣ", // Str::OrangeName
    "Сурх", // Str::RedName
    "Гулобӣ", // Str::PinkName
    "Бунафш", // Str::PurpleName
    "Хокистарӣ", // Str::GreyName
    "Сафед", // Str::WhiteName
    "Сиёҳ", // Str::BlackName

};
static_assert(sizeof(textosTG) / sizeof(textosTG[0]) == N,
    "Faltan o sobran textos en tayiko: revisa que coincidan con Str::Count.");

// Runa Simi (qu)
constexpr const char* textosQU[] = {

    
    
    // Info
    "Enter ñit'iy lluqsinapaq...", // Str::ExitInfoMessage
    "Willañiqip ukhun ch'uya qillqa", // Str::PlainTextModeMessage_FirstLine
    "kaptinlla llamk'achiy", // Str::PlainTextModeMessage_SecondLine
    "Pakasqa willañiqiqa waqaychasqa kanqa", // Str::DefaultCipherModeText_FirstLine
    "imprimiy atikuq sananchakuna hina", // Str::DefaultCipherModeText_SecondLine
    "Pakasqa willañiqiqa binario rikch'aypi", // Str::OpenSSLCipherModeText_FirstLine
    "waqaychasqa kanqa, OpenSSL-wan tupaq", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 kutipaykuna:", // Str::PBKDF2IterationsText
    // Errors
    "Pantay: mana allin parámetrokuna", // Str::WrongParamsText
    "Chaskisqa chani", // Str::InputValueText
    "Chaskisqa ñan", // Str::InputPathText
    "Chaskisqa chaniqa mana tikrayta atikurqanchu 0-manta aswan hatun utaq 0-wan kaqlla yupaman", // Str::WrongNumberValueMessage
    "Chaskisqa ñanqa mana ima kaq willañiqiwanpas tupanchu", // Str::WrongPathValueMessage
    "Churasqa akllanaqa mana allin parámetro hina riqsisqachu", // Str::InvalidOptionMessage
    "Churasqa akllana", // Str::EnteredOptionText
    "Mana riqsisqa pantay", // Str::UnknownExceptionText
    "Mana GLFW qallarichiyta atikurqanchu", // Str::GLFWErrorMessage
    "Mana GLAD qallarichiyta atikurqanchu", // Str::GLADErrorMessage
    "Pantay: Mana willañiqita kichayta atikurqanchu ñawinchanapaq", // Str::ReadFileErrorMessage
    "Pantay willañiqip ukhunta ñawinchachkaspa", // Str::ErrorWhileReadingMessage
    "Pantay: Mana willañiqita kichayta atikurqanchu qillqanapaq", // Str::WriteFileErrorMessage
    "Pantay: Hexadecimal sinripi sananchakunap yupayninqa iskayman rakikuq kanan tiyan", // Str::HexStringErrorMessage
    "Pantay: Sinripi mana allin hexadecimal sananchakuna kan", // Str::InvalidHexCharacterErrorMessage
    "Pantay: Mana willañiqita waqaychayta atikurqanchu", // Str::SaveFileErrorMessage
    "Pantay: Mana willañiqita apamuyta atikurqanchu", // Str::LoadFileErrorMessage
    "Pantay: Willañiqip rikch'aynin mana allinchu (5 k'itikuna suyakurqan: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Pantay: Kutipaykunap yupayninqa churasqa aswan hatun saywata llallin (10.000.000)", // Str::MaxIterationsErrorMessage
    "Pantay: Hunt'asqa kayninta qhawaypi pantay, pakasqa simi mana allinchu utaq willañiqi waqllisqa/tikrasqa", // Str::IntegrityCheckErrorMessage
    "Pantay: Pakasqa simiqa mana ch'usaq kanmanchu", // Str::EmptyPasswordErrorMessage
    "Pantay: Chayana willañiqip ñanninqa q'ipi", // Str::OutputFileIsDirectoryErrorMessage
    "Pantay: Paqarina willañiqip ñanninqa q'ipi", // Str::InputFileIsDirectoryErrorMessage
    "Pantay: Chayana willañiqip ñanninqa mana ch'usaq kanmanchu", // Str::EmptyOutputFilePathErrorMessage
    "Pantay: Paqarina willañiqip ñanninqa mana ch'usaq kanmanchu", // Str::EmptyInputFilePathErrorMessage
    "Pantay: Paqarina willañiqiqa mana kanchu", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Simi: Runa Simi", // Str::LanguageLabel
    "Pakasqa simi", // Str::PasswordLabel
    "Pakasqa simip sunin", // Str::PasswordLenghtLabel
    "Willañiqi", // Str::FileLabel
    "Willañiqi", // Str::TheFileLabel
    "Ñan", // Str::PathLabel
    "Yaykuq willañiqip ñannin", // Str::InputFilePathLabel
    "Lluqsiq willañiqip ñannin", // Str::OutputFilePathLabel
    "Ñankunata rantinakuy", // Str::SwapPathsLabel
    "huk kutitawan qillqasqa kanqa", // Str::WillBeOverwrittenLabel
    "Pakachkan...", // Str::EncryptingText
    "Kichachkan...", // Str::DecryptingText
    "Pakay", // Str::EncryptText
    "Kichay", // Str::DecryptText
    "Willañiqiqa allinta pakasqa", // Str::FileEncryptedMessage
    "Willañiqiqa allinta kichasqa", // Str::FileDecryptedMessage
    "Yuyaykuy!", // Str::WarningTitle
    "Chiqaqchu?", // Str::AreYouSureTitle
    "Allichaykuna", // Str::SettingsTitle
    "Pakasqa simi ruraq", // Str::GeneratePasswordTitle
    "Simita akllay", // Str::SelectLanguageTitle
    "Arí", // Str::YesLabel
    "Manam", // Str::NoLabel
    "Allinmi", // Str::OkLabel
    "Lluqsiq rikch'ay", // Str::OutFormatLabel
    "Rikuchiypa allichaykunan", // Str::InterfaceSettingsLabel
    "Tupu", // Str::InterfaceSizeLabel
    "Imayna", // Str::ModeLabel
    "Riqsisqa", // Str::NormalModeLabel
    "Ch'uya qillqa", // Str::PlaintextModeLabel
    "Rikch'ay", // Str::InterfaceThemeLabel
    "Llimp'i", // Str::InterfaceColorLabel
    "Ñawpaqmanta (ch'uya qillqa)", // Str::DefaultLabel
    "OpenSSL (binario)", // Str::OpenSSLLabel
    "Kay pakasqa simita llamk'achiy", // Str::UsePasswordLabel
    "Kikinchay", // Str::CopyLabel
    "Ctrl + lluq'i ñit'iy SHA256 hap'inapaq", // Str::GetSHA256Text
    // Themes
    "K'anchay", // Str::LightThemeName
    "Tutayaq", // Str::DarkThemeName
    // Colors
    "Anqas", // Str::BlueName
    "Ch'uya anqas", // Str::CyanName
    "Q'umir", // Str::GreenName
    "Ch'uya q'umir", // Str::LimeName
    "Q'illu", // Str::YellowName
    "Ch'umpi", // Str::BrownName
    "Q'illu puka", // Str::OrangeName
    "Puka", // Str::RedName
    "Panti", // Str::PinkName
    "Kulli", // Str::PurpleName
    "Uqi", // Str::GreyName
    "Yuraq", // Str::WhiteName
    "Yana", // Str::BlackName

};
static_assert(sizeof(textosQU) / sizeof(textosQU[0]) == N,
    "Faltan o sobran textos en quechua: revisa que coincidan con Str::Count.");

// Shqip (sq)
constexpr const char* textosSQ[] = {

    
    
    // Info
    "Shtypni Enter për të dalë...", // Str::ExitInfoMessage
    "Aktivizojeni vetëm nëse përmbajtja", // Str::PlainTextModeMessage_FirstLine
    "e skedarit është tekst i thjeshtë", // Str::PlainTextModeMessage_SecondLine
    "Skedari i enkriptuar do të ruhet", // Str::DefaultCipherModeText_FirstLine
    "si karaktere të printueshme", // Str::DefaultCipherModeText_SecondLine
    "Skedari i enkriptuar do të ruhet në", // Str::OpenSSLCipherModeText_FirstLine
    "format binar, i përputhshëm me OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Përsëritjet PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Gabim: parametra të pasaktë", // Str::WrongParamsText
    "Vlera e marrë", // Str::InputValueText
    "Shtegu i marrë", // Str::InputPathText
    "Vlera e marrë nuk mund të shndërrohej në një numër më të madh ose të barabartë me 0", // Str::WrongNumberValueMessage
    "Shtegu i marrë nuk përputhet me asnjë skedar ekzistues", // Str::WrongPathValueMessage
    "Opsioni i futur nuk njihet si parametër i vlefshëm", // Str::InvalidOptionMessage
    "Opsioni i futur", // Str::EnteredOptionText
    "Përjashtim i panjohur", // Str::UnknownExceptionText
    "Inicializimi i GLFW dështoi", // Str::GLFWErrorMessage
    "Inicializimi i GLAD dështoi", // Str::GLADErrorMessage
    "Gabim: Skedari nuk mund të hapej për lexim", // Str::ReadFileErrorMessage
    "Gabim gjatë leximit të përmbajtjes së skedarit", // Str::ErrorWhileReadingMessage
    "Gabim: Skedari nuk mund të hapej për shkrim", // Str::WriteFileErrorMessage
    "Gabim: Vargu heksadecimal duhet të ketë numër çift karakteresh", // Str::HexStringErrorMessage
    "Gabim: Karakter heksadecimal i pavlefshëm në varg", // Str::InvalidHexCharacterErrorMessage
    "Gabim: Skedari nuk mund të ruhej", // Str::SaveFileErrorMessage
    "Gabim: Skedari nuk mund të ngarkohej", // Str::LoadFileErrorMessage
    "Gabim: Format skedari i pavlefshëm (priteshin 5 fusha: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Gabim: Numri i përsëritjeve tejkalon maksimumin e caktuar (10.000.000)", // Str::MaxIterationsErrorMessage
    "Gabim: Verifikimi i integritetit dështoi, fjalëkalim i pasaktë ose skedar i dëmtuar/i manipuluar", // Str::IntegrityCheckErrorMessage
    "Gabim: Fjalëkalimi nuk mund të jetë bosh", // Str::EmptyPasswordErrorMessage
    "Gabim: Shtegu i skedarit të destinacionit është dosje", // Str::OutputFileIsDirectoryErrorMessage
    "Gabim: Shtegu i skedarit burimor është dosje", // Str::InputFileIsDirectoryErrorMessage
    "Gabim: Shtegu i skedarit të destinacionit nuk mund të jetë bosh", // Str::EmptyOutputFilePathErrorMessage
    "Gabim: Shtegu i skedarit burimor nuk mund të jetë bosh", // Str::EmptyInputFilePathErrorMessage
    "Gabim: Skedari burimor nuk ekziston", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Gjuha: Shqip", // Str::LanguageLabel
    "Fjalëkalimi", // Str::PasswordLabel
    "Gjatësia e fjalëkalimit", // Str::PasswordLenghtLabel
    "Skedari", // Str::FileLabel
    "Skedari", // Str::TheFileLabel
    "Shtegu", // Str::PathLabel
    "Shtegu i hyrjes", // Str::InputFilePathLabel
    "Shtegu i daljes", // Str::OutputFilePathLabel
    "Ndërro shtigjet", // Str::SwapPathsLabel
    "do të mbishkruhet", // Str::WillBeOverwrittenLabel
    "Duke enkriptuar...", // Str::EncryptingText
    "Duke dekriptuar...", // Str::DecryptingText
    "Enkripto", // Str::EncryptText
    "Dekripto", // Str::DecryptText
    "Skedari u enkriptua me sukses", // Str::FileEncryptedMessage
    "Skedari u dekriptua me sukses", // Str::FileDecryptedMessage
    "Kujdes!", // Str::WarningTitle
    "Jeni të sigurt?", // Str::AreYouSureTitle
    "Cilësimet", // Str::SettingsTitle
    "Gjenerues fjalëkalimesh", // Str::GeneratePasswordTitle
    "Zgjidhni gjuhën", // Str::SelectLanguageTitle
    "Po", // Str::YesLabel
    "Jo", // Str::NoLabel
    "OK", // Str::OkLabel
    "Formati i daljes", // Str::OutFormatLabel
    "Cilësimet e ndërfaqes", // Str::InterfaceSettingsLabel
    "Madhësia", // Str::InterfaceSizeLabel
    "Modaliteti", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Tekst i thjeshtë", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Ngjyra", // Str::InterfaceColorLabel
    "Parazgjedhje (tekst i thjeshtë)", // Str::DefaultLabel
    "OpenSSL (binar)", // Str::OpenSSLLabel
    "Përdor këtë fjalëkalim", // Str::UsePasswordLabel
    "Kopjo", // Str::CopyLabel
    "Ctrl + klikim majtas për të marrë SHA256", // Str::GetSHA256Text
    // Themes
    "E çelët", // Str::LightThemeName
    "E errët", // Str::DarkThemeName
    // Colors
    "Blu", // Str::BlueName
    "Cian", // Str::CyanName
    "E gjelbër", // Str::GreenName
    "Gjelbër limoni", // Str::LimeName
    "E verdhë", // Str::YellowName
    "Kafe", // Str::BrownName
    "Portokalli", // Str::OrangeName
    "E kuqe", // Str::RedName
    "Rozë", // Str::PinkName
    "Vjollcë", // Str::PurpleName
    "Gri", // Str::GreyName
    "E bardhë", // Str::WhiteName
    "E zezë", // Str::BlackName

};
static_assert(sizeof(textosSQ) / sizeof(textosSQ[0]) == N,
    "Faltan o sobran textos en albanes: revisa que coincidan con Str::Count.");

// Slovenčina (sk)
constexpr const char* textosSK[] = {

    
    
    // Info
    "Stlačte Enter na ukončenie...", // Str::ExitInfoMessage
    "Povoľte iba vtedy, ak je obsah", // Str::PlainTextModeMessage_FirstLine
    "súboru obyčajný text", // Str::PlainTextModeMessage_SecondLine
    "Zašifrovaný súbor sa uloží", // Str::DefaultCipherModeText_FirstLine
    "ako tlačiteľné znaky", // Str::DefaultCipherModeText_SecondLine
    "Zašifrovaný súbor sa uloží", // Str::OpenSSLCipherModeText_FirstLine
    "v binárnom formáte kompatibilnom s OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterácie PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Chyba: nesprávne parametre", // Str::WrongParamsText
    "Prijatá hodnota", // Str::InputValueText
    "Prijatá cesta", // Str::InputPathText
    "Prijatú hodnotu nebolo možné previesť na číslo väčšie alebo rovné 0", // Str::WrongNumberValueMessage
    "Prijatá cesta nezodpovedá žiadnemu existujúcemu súboru", // Str::WrongPathValueMessage
    "Zadaná možnosť nie je rozpoznaná ako platný parameter", // Str::InvalidOptionMessage
    "Zadaná možnosť", // Str::EnteredOptionText
    "Neznáma výnimka", // Str::UnknownExceptionText
    "Nepodarilo sa inicializovať GLFW", // Str::GLFWErrorMessage
    "Nepodarilo sa inicializovať GLAD", // Str::GLADErrorMessage
    "Chyba: Súbor sa nepodarilo otvoriť na čítanie", // Str::ReadFileErrorMessage
    "Chyba pri čítaní obsahu súboru", // Str::ErrorWhileReadingMessage
    "Chyba: Súbor sa nepodarilo otvoriť na zápis", // Str::WriteFileErrorMessage
    "Chyba: Hexadecimálny reťazec musí mať párny počet znakov", // Str::HexStringErrorMessage
    "Chyba: Neplatný hexadecimálny znak v reťazci", // Str::InvalidHexCharacterErrorMessage
    "Chyba: Súbor sa nepodarilo uložiť", // Str::SaveFileErrorMessage
    "Chyba: Súbor sa nepodarilo načítať", // Str::LoadFileErrorMessage
    "Chyba: Neplatný formát súboru (očakáva sa 5 polí: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Chyba: Počet iterácií prekračuje stanovené maximum (10 000 000)", // Str::MaxIterationsErrorMessage
    "Chyba: Overenie integrity zlyhalo, nesprávne heslo alebo poškodený/zmenený súbor", // Str::IntegrityCheckErrorMessage
    "Chyba: Heslo nemôže byť prázdne", // Str::EmptyPasswordErrorMessage
    "Chyba: Cesta k cieľovému súboru je priečinok", // Str::OutputFileIsDirectoryErrorMessage
    "Chyba: Cesta k zdrojovému súboru je priečinok", // Str::InputFileIsDirectoryErrorMessage
    "Chyba: Cesta k cieľovému súboru nemôže byť prázdna", // Str::EmptyOutputFilePathErrorMessage
    "Chyba: Cesta k zdrojovému súboru nemôže byť prázdna", // Str::EmptyInputFilePathErrorMessage
    "Chyba: Zdrojový súbor neexistuje", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Jazyk: Slovenčina", // Str::LanguageLabel
    "Heslo", // Str::PasswordLabel
    "Dĺžka hesla", // Str::PasswordLenghtLabel
    "Súbor", // Str::FileLabel
    "Súbor", // Str::TheFileLabel
    "Cesta", // Str::PathLabel
    "Cesta k vstupnému súboru", // Str::InputFilePathLabel
    "Cesta k výstupnému súboru", // Str::OutputFilePathLabel
    "Vymeniť cesty", // Str::SwapPathsLabel
    "bude prepísaný", // Str::WillBeOverwrittenLabel
    "Šifrovanie...", // Str::EncryptingText
    "Dešifrovanie...", // Str::DecryptingText
    "Zašifrovať", // Str::EncryptText
    "Dešifrovať", // Str::DecryptText
    "Súbor bol úspešne zašifrovaný", // Str::FileEncryptedMessage
    "Súbor bol úspešne dešifrovaný", // Str::FileDecryptedMessage
    "Upozornenie!", // Str::WarningTitle
    "Ste si istí?", // Str::AreYouSureTitle
    "Nastavenia", // Str::SettingsTitle
    "Generátor hesiel", // Str::GeneratePasswordTitle
    "Vyberte jazyk", // Str::SelectLanguageTitle
    "Áno", // Str::YesLabel
    "Nie", // Str::NoLabel
    "OK", // Str::OkLabel
    "Výstupný formát", // Str::OutFormatLabel
    "Nastavenia rozhrania", // Str::InterfaceSettingsLabel
    "Veľkosť", // Str::InterfaceSizeLabel
    "Režim", // Str::ModeLabel
    "Normálny", // Str::NormalModeLabel
    "Obyčajný text", // Str::PlaintextModeLabel
    "Motív", // Str::InterfaceThemeLabel
    "Farba", // Str::InterfaceColorLabel
    "Predvolené (obyčajný text)", // Str::DefaultLabel
    "OpenSSL (binárny)", // Str::OpenSSLLabel
    "Použiť toto heslo", // Str::UsePasswordLabel
    "Kopírovať", // Str::CopyLabel
    "Ctrl + kliknutie ľavým tlačidlom na získanie SHA256", // Str::GetSHA256Text
    // Themes
    "Svetlý", // Str::LightThemeName
    "Tmavý", // Str::DarkThemeName
    // Colors
    "Modrá", // Str::BlueName
    "Azúrová", // Str::CyanName
    "Zelená", // Str::GreenName
    "Limetková", // Str::LimeName
    "Žltá", // Str::YellowName
    "Hnedá", // Str::BrownName
    "Oranžová", // Str::OrangeName
    "Červená", // Str::RedName
    "Ružová", // Str::PinkName
    "Fialová", // Str::PurpleName
    "Sivá", // Str::GreyName
    "Biela", // Str::WhiteName
    "Čierna", // Str::BlackName

};
static_assert(sizeof(textosSK) / sizeof(textosSK[0]) == N,
    "Faltan o sobran textos en eslovaco: revisa que coincidan con Str::Count.");

// Türkmençe (tk)
constexpr const char* textosTK[] = {

    
    
    // Info
    "Çykmak üçin Enter düwmesine basyň...", // Str::ExitInfoMessage
    "Diňe faýlyň mazmuny ýönekeý tekst", // Str::PlainTextModeMessage_FirstLine
    "bolan ýagdaýynda işjeňleşdiriň", // Str::PlainTextModeMessage_SecondLine
    "Şifrlenen faýl çap edip bolýan", // Str::DefaultCipherModeText_FirstLine
    "nyşanlar görnüşinde saklanar", // Str::DefaultCipherModeText_SecondLine
    "Şifrlenen faýl OpenSSL bilen gabat gelýän", // Str::OpenSSLCipherModeText_FirstLine
    "ikilik formatda saklanar", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 gaýtalamalary:", // Str::PBKDF2IterationsText
    // Errors
    "Ýalňyşlyk: nädogry parametrler", // Str::WrongParamsText
    "Alnan baha", // Str::InputValueText
    "Alnan ýol", // Str::InputPathText
    "Alnan bahany 0-dan uly ýa-da 0-a deň bolan sana öwrüp bolmady", // Str::WrongNumberValueMessage
    "Alnan ýol bar bolan faýllaryň hiç birine gabat gelmeýär", // Str::WrongPathValueMessage
    "Girizilen opsiýa dogry parametr hökmünde tanalmady", // Str::InvalidOptionMessage
    "Girizilen opsiýa", // Str::EnteredOptionText
    "Näbelli kadadan çykma", // Str::UnknownExceptionText
    "GLFW-ni başlatmak başartmady", // Str::GLFWErrorMessage
    "GLAD-y başlatmak başartmady", // Str::GLADErrorMessage
    "Ýalňyşlyk: Faýly okamak üçin açyp bolmady", // Str::ReadFileErrorMessage
    "Faýlyň mazmunyny okamakda ýalňyşlyk ýüze çykdy", // Str::ErrorWhileReadingMessage
    "Ýalňyşlyk: Faýly ýazmak üçin açyp bolmady", // Str::WriteFileErrorMessage
    "Ýalňyşlyk: On altylyk setirdäki nyşanlaryň sany jübüt bolmaly", // Str::HexStringErrorMessage
    "Ýalňyşlyk: Setirde nädogry on altylyk nyşan bar", // Str::InvalidHexCharacterErrorMessage
    "Ýalňyşlyk: Faýly ýatda saklap bolmady", // Str::SaveFileErrorMessage
    "Ýalňyşlyk: Faýly ýükläp bolmady", // Str::LoadFileErrorMessage
    "Ýalňyşlyk: Faýlyň formaty nädogry (5 meýdan garaşylýardy: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Ýalňyşlyk: Gaýtalamalaryň sany bellenen iň ýokary çäkden geçýär (10 000 000)", // Str::MaxIterationsErrorMessage
    "Ýalňyşlyk: Bitewilik barlagy şowsuz boldy, açar sözi nädogry ýa-da faýl zaýalanan/üýtgedilen", // Str::IntegrityCheckErrorMessage
    "Ýalňyşlyk: Açar sözi boş bolup bilmez", // Str::EmptyPasswordErrorMessage
    "Ýalňyşlyk: Maksat faýlyň ýoly bukjadyr", // Str::OutputFileIsDirectoryErrorMessage
    "Ýalňyşlyk: Çeşme faýlyň ýoly bukjadyr", // Str::InputFileIsDirectoryErrorMessage
    "Ýalňyşlyk: Maksat faýlyň ýoly boş bolup bilmez", // Str::EmptyOutputFilePathErrorMessage
    "Ýalňyşlyk: Çeşme faýlyň ýoly boş bolup bilmez", // Str::EmptyInputFilePathErrorMessage
    "Ýalňyşlyk: Çeşme faýl ýok", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Dil: Türkmençe", // Str::LanguageLabel
    "Açar sözi", // Str::PasswordLabel
    "Açar sözüniň uzynlygy", // Str::PasswordLenghtLabel
    "Faýl", // Str::FileLabel
    "Faýl", // Str::TheFileLabel
    "Ýol", // Str::PathLabel
    "Giriş faýlynyň ýoly", // Str::InputFilePathLabel
    "Çykyş faýlynyň ýoly", // Str::OutputFilePathLabel
    "Ýollaryň ornuny çalyş", // Str::SwapPathsLabel
    "täzeden ýazylar", // Str::WillBeOverwrittenLabel
    "Şifrlenýär...", // Str::EncryptingText
    "Şifr açylýar...", // Str::DecryptingText
    "Şifrle", // Str::EncryptText
    "Şifri aç", // Str::DecryptText
    "Faýl üstünlikli şifrlendi", // Str::FileEncryptedMessage
    "Faýlyň şifri üstünlikli açyldy", // Str::FileDecryptedMessage
    "Duýduryş!", // Str::WarningTitle
    "Ynanýaňyzmy?", // Str::AreYouSureTitle
    "Sazlamalar", // Str::SettingsTitle
    "Açar sözi generatory", // Str::GeneratePasswordTitle
    "Dili saýlaň", // Str::SelectLanguageTitle
    "Hawa", // Str::YesLabel
    "Ýok", // Str::NoLabel
    "Bolýar", // Str::OkLabel
    "Çykyş formaty", // Str::OutFormatLabel
    "Interfeýs sazlamalary", // Str::InterfaceSettingsLabel
    "Ölçeg", // Str::InterfaceSizeLabel
    "Tertip", // Str::ModeLabel
    "Adaty", // Str::NormalModeLabel
    "Ýönekeý tekst", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Reňk", // Str::InterfaceColorLabel
    "Deslapky (ýönekeý tekst)", // Str::DefaultLabel
    "OpenSSL (ikilik)", // Str::OpenSSLLabel
    "Bu açar sözüni ulan", // Str::UsePasswordLabel
    "Göçür", // Str::CopyLabel
    "SHA256 almak üçin Ctrl + çep düwme", // Str::GetSHA256Text
    // Themes
    "Ýagty", // Str::LightThemeName
    "Garaňky", // Str::DarkThemeName
    // Colors
    "Gök", // Str::BlueName
    "Mawy", // Str::CyanName
    "Ýaşyl", // Str::GreenName
    "Açyk ýaşyl", // Str::LimeName
    "Sary", // Str::YellowName
    "Goňur", // Str::BrownName
    "Mämişi", // Str::OrangeName
    "Gyzyl", // Str::RedName
    "Gülgüne", // Str::PinkName
    "Benewşe", // Str::PurpleName
    "Çal", // Str::GreyName
    "Ak", // Str::WhiteName
    "Gara", // Str::BlackName

};
static_assert(sizeof(textosTK) / sizeof(textosTK[0]) == N,
    "Faltan o sobran textos en turcomano: revisa que coincidan con Str::Count.");

// Հայերեն (hy)
constexpr const char* textosHY[] = {

    
    
    // Info
    "Սեղմեք Enter՝ դուրս գալու համար...", // Str::ExitInfoMessage
    "Միացրեք միայն այն դեպքում, եթե", // Str::PlainTextModeMessage_FirstLine
    "ֆայլի պարունակությունը պարզ տեքստ է", // Str::PlainTextModeMessage_SecondLine
    "Գաղտնագրված ֆայլը կպահվի", // Str::DefaultCipherModeText_FirstLine
    "տպելի նիշերի տեսքով", // Str::DefaultCipherModeText_SecondLine
    "Գաղտնագրված ֆայլը կպահվի երկուական", // Str::OpenSSLCipherModeText_FirstLine
    "ձևաչափով, որը համատեղելի է OpenSSL-ի հետ", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 իտերացիաներ:", // Str::PBKDF2IterationsText
    // Errors
    "Սխալ: անվավեր պարամետրեր", // Str::WrongParamsText
    "Ստացված արժեք", // Str::InputValueText
    "Ստացված ուղի", // Str::InputPathText
    "Ստացված արժեքը չհաջողվեց փոխարկել 0-ից մեծ կամ 0-ին հավասար թվի", // Str::WrongNumberValueMessage
    "Ստացված ուղին չի համապատասխանում որևէ գոյություն ունեցող ֆայլի", // Str::WrongPathValueMessage
    "Մուտքագրված ընտրանքը չի ճանաչվում որպես վավեր պարամետր", // Str::InvalidOptionMessage
    "Մուտքագրված ընտրանք", // Str::EnteredOptionText
    "Անհայտ բացառություն", // Str::UnknownExceptionText
    "Չհաջողվեց նախաձեռնել GLFW-ն", // Str::GLFWErrorMessage
    "Չհաջողվեց նախաձեռնել GLAD-ը", // Str::GLADErrorMessage
    "Սխալ: Չհաջողվեց բացել ֆայլը կարդալու համար", // Str::ReadFileErrorMessage
    "Սխալ ֆայլի պարունակությունը կարդալիս", // Str::ErrorWhileReadingMessage
    "Սխալ: Չհաջողվեց բացել ֆայլը գրելու համար", // Str::WriteFileErrorMessage
    "Սխալ: Տասնվեցական տողը պետք է ունենա զույգ թվով նիշեր", // Str::HexStringErrorMessage
    "Սխալ: Տողում կա անվավեր տասնվեցական նիշ", // Str::InvalidHexCharacterErrorMessage
    "Սխալ: Չհաջողվեց պահել ֆայլը", // Str::SaveFileErrorMessage
    "Սխալ: Չհաջողվեց բեռնել ֆայլը", // Str::LoadFileErrorMessage
    "Սխալ: Ֆայլի անվավեր ձևաչափ (սպասվում էր 5 դաշտ: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Սխալ: Իտերացիաների քանակը գերազանցում է սահմանված առավելագույնը (10 000 000)", // Str::MaxIterationsErrorMessage
    "Սխալ: Ամբողջականության ստուգումը ձախողվեց, սխալ գաղտնաբառ կամ վնասված/փոփոխված ֆայլ", // Str::IntegrityCheckErrorMessage
    "Սխալ: Գաղտնաբառը չի կարող դատարկ լինել", // Str::EmptyPasswordErrorMessage
    "Սխալ: Նպատակային ֆայլի ուղին թղթապանակ է", // Str::OutputFileIsDirectoryErrorMessage
    "Սխալ: Աղբյուր ֆայլի ուղին թղթապանակ է", // Str::InputFileIsDirectoryErrorMessage
    "Սխալ: Նպատակային ֆայլի ուղին չի կարող դատարկ լինել", // Str::EmptyOutputFilePathErrorMessage
    "Սխալ: Աղբյուր ֆայլի ուղին չի կարող դատարկ լինել", // Str::EmptyInputFilePathErrorMessage
    "Սխալ: Աղբյուր ֆայլը գոյություն չունի", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Լեզու: Հայերեն", // Str::LanguageLabel
    "Գաղտնաբառ", // Str::PasswordLabel
    "Գաղտնաբառի երկարություն", // Str::PasswordLenghtLabel
    "Ֆայլ", // Str::FileLabel
    "Ֆայլը", // Str::TheFileLabel
    "Ուղի", // Str::PathLabel
    "Մուտքային ֆայլի ուղի", // Str::InputFilePathLabel
    "Ելքային ֆայլի ուղի", // Str::OutputFilePathLabel
    "Փոխանակել ուղիները", // Str::SwapPathsLabel
    "կվերագրանցվի", // Str::WillBeOverwrittenLabel
    "Գաղտնագրում...", // Str::EncryptingText
    "Վերծանում...", // Str::DecryptingText
    "Գաղտնագրել", // Str::EncryptText
    "Վերծանել", // Str::DecryptText
    "Ֆայլը հաջողությամբ գաղտնագրվեց", // Str::FileEncryptedMessage
    "Ֆայլը հաջողությամբ վերծանվեց", // Str::FileDecryptedMessage
    "Ուշադրություն!", // Str::WarningTitle
    "Համոզվա՞ծ եք", // Str::AreYouSureTitle
    "Կարգավորումներ", // Str::SettingsTitle
    "Գաղտնաբառի գեներատոր", // Str::GeneratePasswordTitle
    "Ընտրեք լեզուն", // Str::SelectLanguageTitle
    "Այո", // Str::YesLabel
    "Ոչ", // Str::NoLabel
    "Լավ", // Str::OkLabel
    "Ելքային ձևաչափ", // Str::OutFormatLabel
    "Ինտերֆեյսի կարգավորումներ", // Str::InterfaceSettingsLabel
    "Չափ", // Str::InterfaceSizeLabel
    "Ռեժիմ", // Str::ModeLabel
    "Սովորական", // Str::NormalModeLabel
    "Պարզ տեքստ", // Str::PlaintextModeLabel
    "Թեմա", // Str::InterfaceThemeLabel
    "Գույն", // Str::InterfaceColorLabel
    "Լռելյայն (պարզ տեքստ)", // Str::DefaultLabel
    "OpenSSL (երկուական)", // Str::OpenSSLLabel
    "Օգտագործել այս գաղտնաբառը", // Str::UsePasswordLabel
    "Պատճենել", // Str::CopyLabel
    "Ctrl + ձախ սեղմում՝ SHA256 ստանալու համար", // Str::GetSHA256Text
    // Themes
    "Բաց", // Str::LightThemeName
    "Մուգ", // Str::DarkThemeName
    // Colors
    "Կապույտ", // Str::BlueName
    "Երկնագույն", // Str::CyanName
    "Կանաչ", // Str::GreenName
    "Լայմի կանաչ", // Str::LimeName
    "Դեղին", // Str::YellowName
    "Շագանակագույն", // Str::BrownName
    "Նարնջագույն", // Str::OrangeName
    "Կարմիր", // Str::RedName
    "Վարդագույն", // Str::PinkName
    "Մանուշակագույն", // Str::PurpleName
    "Մոխրագույն", // Str::GreyName
    "Սպիտակ", // Str::WhiteName
    "Սև", // Str::BlackName

};
static_assert(sizeof(textosHY) / sizeof(textosHY[0]) == N,
    "Faltan o sobran textos en armenio: revisa que coincidan con Str::Count.");

// Avañe'ẽ (gn)
constexpr const char* textosGN[] = {

    
    
    // Info
    "Ejopy Enter ha resẽta...", // Str::ExitInfoMessage
    "Emyandy añoite marandurenda", // Str::PlainTextModeMessage_FirstLine
    "oguerekóramo jehai potĩ", // Str::PlainTextModeMessage_SecondLine
    "Marandurenda moñemipyre oñeñongatúta", // Str::DefaultCipherModeText_FirstLine
    "tai ikatúva oñeimprimíicha", // Str::DefaultCipherModeText_SecondLine
    "Marandurenda moñemipyre oñeñongatúta", // Str::OpenSSLCipherModeText_FirstLine
    "binario ramo, ojoajúva OpenSSL ndive", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 jejapojey:", // Str::PBKDF2IterationsText
    // Errors
    "Jejavy: parámetro oĩ vai", // Str::WrongParamsText
    "Tepykue oñemoingéva", // Str::InputValueText
    "Tape oñemoingéva", // Str::InputPathText
    "Ndaikatúi oñembohasa tepykue oñemoingéva papapýpe tuichavéva 0-gui térã ojojáva 0 ndive", // Str::WrongNumberValueMessage
    "Tape oñemoingéva ndojoajúi marandurenda oĩvape", // Str::WrongPathValueMessage
    "Poravopyre oñemoingéva ndojekuaái parámetro oiko porãháicha", // Str::InvalidOptionMessage
    "Poravopyre oñemoingéva", // Str::EnteredOptionText
    "Jejavy ojekuaa'ỹva", // Str::UnknownExceptionText
    "Ndaikatúi oñepyrũ GLFW", // Str::GLFWErrorMessage
    "Ndaikatúi oñepyrũ GLAD", // Str::GLADErrorMessage
    "Jejavy: Ndaikatúi ojepe'a marandurenda ojelee", // Str::ReadFileErrorMessage
    "Jejavy ojelee aja marandurenda retepy", // Str::ErrorWhileReadingMessage
    "Jejavy: Ndaikatúi ojepe'a marandurenda ojehai", // Str::WriteFileErrorMessage
    "Jejavy: Hexadecimal jehaipyre oguerekova'erã tai papapy ikatúva oñemboja'o mokõime", // Str::HexStringErrorMessage
    "Jejavy: Oĩ tai hexadecimal ndoikóiva jehaipyrépe", // Str::InvalidHexCharacterErrorMessage
    "Jejavy: Ndaikatúi oñeñongatu marandurenda", // Str::SaveFileErrorMessage
    "Jejavy: Ndaikatúi ojehupi marandurenda", // Str::LoadFileErrorMessage
    "Jejavy: Marandurenda ysaja ndoikói (oñeha'arõ 5 kora: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Jejavy: Jejapojey papapy ohasa tuichavéva oñemboheko va'ekue (10.000.000)", // Str::MaxIterationsErrorMessage
    "Jejavy: Jehechajey ndoikoporãi, ñe'ẽñemi oĩ vai térã marandurenda ivaipáma/oñemoambue", // Str::IntegrityCheckErrorMessage
    "Jejavy: Ñe'ẽñemi ndaikatúi oime nandi", // Str::EmptyPasswordErrorMessage
    "Jejavy: Marandurenda jehupytyrã tape ha'e ñongatuha", // Str::OutputFileIsDirectoryErrorMessage
    "Jejavy: Marandurenda ypykue tape ha'e ñongatuha", // Str::InputFileIsDirectoryErrorMessage
    "Jejavy: Marandurenda jehupytyrã tape ndaikatúi oime nandi", // Str::EmptyOutputFilePathErrorMessage
    "Jejavy: Marandurenda ypykue tape ndaikatúi oime nandi", // Str::EmptyInputFilePathErrorMessage
    "Jejavy: Marandurenda ypykue ndaipóri", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Ñe'ẽ: Avañe'ẽ", // Str::LanguageLabel
    "Ñe'ẽñemi", // Str::PasswordLabel
    "Ñe'ẽñemi pukukue", // Str::PasswordLenghtLabel
    "Marandurenda", // Str::FileLabel
    "Marandurenda", // Str::TheFileLabel
    "Tape", // Str::PathLabel
    "Marandurenda jeike tape", // Str::InputFilePathLabel
    "Marandurenda jeguenohẽ tape", // Str::OutputFilePathLabel
    "Emoambue tapekuéra", // Str::SwapPathsLabel
    "ojehaijeýta", // Str::WillBeOverwrittenLabel
    "Oñemoñemi...", // Str::EncryptingText
    "Ojepe'a ñemi...", // Str::DecryptingText
    "Moñemi", // Str::EncryptText
    "Pe'a ñemi", // Str::DecryptText
    "Marandurenda oñemoñemi porã", // Str::FileEncryptedMessage
    "Marandurenda ñemi ojepe'a porã", // Str::FileDecryptedMessage
    "Ñatende!", // Str::WarningTitle
    "Añetehápepa?", // Str::AreYouSureTitle
    "Ñemboheko", // Str::SettingsTitle
    "Ñe'ẽñemi apoha", // Str::GeneratePasswordTitle
    "Eiporavo ñe'ẽ", // Str::SelectLanguageTitle
    "Héẽ", // Str::YesLabel
    "Nahániri", // Str::NoLabel
    "Oĩma", // Str::OkLabel
    "Jeguenohẽ ysaja", // Str::OutFormatLabel
    "Interfaz ñemboheko", // Str::InterfaceSettingsLabel
    "Tuichakue", // Str::InterfaceSizeLabel
    "Reko", // Str::ModeLabel
    "Jepiguáva", // Str::NormalModeLabel
    "Jehai potĩ", // Str::PlaintextModeLabel
    "Téma", // Str::InterfaceThemeLabel
    "Sa'y", // Str::InterfaceColorLabel
    "Ypyguáva (jehai potĩ)", // Str::DefaultLabel
    "OpenSSL (binario)", // Str::OpenSSLLabel
    "Eipuru ko ñe'ẽñemi", // Str::UsePasswordLabel
    "Kopia", // Str::CopyLabel
    "Ctrl + ejopy asu gotyo ha ehupyty SHA256", // Str::GetSHA256Text
    // Themes
    "Tesakã", // Str::LightThemeName
    "Pytũ", // Str::DarkThemeName
    // Colors
    "Hovy", // Str::BlueName
    "Hovy tesakã", // Str::CyanName
    "Hovyũ", // Str::GreenName
    "Hovyũ tesakã", // Str::LimeName
    "Sa'yju", // Str::YellowName
    "Marrõ", // Str::BrownName
    "Narã", // Str::OrangeName
    "Pytã", // Str::RedName
    "Pytãngy", // Str::PinkName
    "Lila", // Str::PurpleName
    "Hũndy", // Str::GreyName
    "Morotĩ", // Str::WhiteName
    "Hũ", // Str::BlackName

};
static_assert(sizeof(textosGN) / sizeof(textosGN[0]) == N,
    "Faltan o sobran textos en guarani: revisa que coincidan con Str::Count.");

// Hrvatski (hr)
constexpr const char* textosHR[] = {

    
    
    // Info
    "Pritisnite Enter za izlaz...", // Str::ExitInfoMessage
    "Omogućite samo ako je sadržaj", // Str::PlainTextModeMessage_FirstLine
    "datoteke običan tekst", // Str::PlainTextModeMessage_SecondLine
    "Šifrirana datoteka bit će spremljena", // Str::DefaultCipherModeText_FirstLine
    "kao znakovi koji se mogu ispisati", // Str::DefaultCipherModeText_SecondLine
    "Šifrirana datoteka bit će spremljena u", // Str::OpenSSLCipherModeText_FirstLine
    "binarnom formatu, kompatibilnom s OpenSSL-om", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 iteracije:", // Str::PBKDF2IterationsText
    // Errors
    "Pogreška: neispravni parametri", // Str::WrongParamsText
    "Primljena vrijednost", // Str::InputValueText
    "Primljena putanja", // Str::InputPathText
    "Primljenu vrijednost nije bilo moguće pretvoriti u broj veći od 0 ili jednak 0", // Str::WrongNumberValueMessage
    "Primljena putanja ne odgovara nijednoj postojećoj datoteci", // Str::WrongPathValueMessage
    "Unesena opcija nije prepoznata kao valjani parametar", // Str::InvalidOptionMessage
    "Unesena opcija", // Str::EnteredOptionText
    "Nepoznata iznimka", // Str::UnknownExceptionText
    "Inicijalizacija GLFW-a nije uspjela", // Str::GLFWErrorMessage
    "Inicijalizacija GLAD-a nije uspjela", // Str::GLADErrorMessage
    "Pogreška: Datoteku nije moguće otvoriti za čitanje", // Str::ReadFileErrorMessage
    "Pogreška pri čitanju sadržaja datoteke", // Str::ErrorWhileReadingMessage
    "Pogreška: Datoteku nije moguće otvoriti za pisanje", // Str::WriteFileErrorMessage
    "Pogreška: Heksadecimalni niz mora imati paran broj znakova", // Str::HexStringErrorMessage
    "Pogreška: Nevaljan heksadecimalni znak u nizu", // Str::InvalidHexCharacterErrorMessage
    "Pogreška: Datoteku nije moguće spremiti", // Str::SaveFileErrorMessage
    "Pogreška: Datoteku nije moguće učitati", // Str::LoadFileErrorMessage
    "Pogreška: Nevaljan format datoteke (očekivano 5 polja: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Pogreška: Broj iteracija premašuje utvrđeni maksimum (10.000.000)", // Str::MaxIterationsErrorMessage
    "Pogreška: Provjera cjelovitosti nije uspjela, netočna lozinka ili oštećena/izmijenjena datoteka", // Str::IntegrityCheckErrorMessage
    "Pogreška: Lozinka ne smije biti prazna", // Str::EmptyPasswordErrorMessage
    "Pogreška: Putanja odredišne datoteke je mapa", // Str::OutputFileIsDirectoryErrorMessage
    "Pogreška: Putanja izvorne datoteke je mapa", // Str::InputFileIsDirectoryErrorMessage
    "Pogreška: Putanja odredišne datoteke ne smije biti prazna", // Str::EmptyOutputFilePathErrorMessage
    "Pogreška: Putanja izvorne datoteke ne smije biti prazna", // Str::EmptyInputFilePathErrorMessage
    "Pogreška: Izvorna datoteka ne postoji", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Jezik: Hrvatski", // Str::LanguageLabel
    "Lozinka", // Str::PasswordLabel
    "Duljina lozinke", // Str::PasswordLenghtLabel
    "Datoteka", // Str::FileLabel
    "Datoteka", // Str::TheFileLabel
    "Putanja", // Str::PathLabel
    "Putanja ulazne datoteke", // Str::InputFilePathLabel
    "Putanja izlazne datoteke", // Str::OutputFilePathLabel
    "Zamijeni putanje", // Str::SwapPathsLabel
    "bit će prebrisana", // Str::WillBeOverwrittenLabel
    "Šifriranje...", // Str::EncryptingText
    "Dešifriranje...", // Str::DecryptingText
    "Šifriraj", // Str::EncryptText
    "Dešifriraj", // Str::DecryptText
    "Datoteka je uspješno šifrirana", // Str::FileEncryptedMessage
    "Datoteka je uspješno dešifrirana", // Str::FileDecryptedMessage
    "Upozorenje!", // Str::WarningTitle
    "Jeste li sigurni?", // Str::AreYouSureTitle
    "Postavke", // Str::SettingsTitle
    "Generator lozinki", // Str::GeneratePasswordTitle
    "Odaberite jezik", // Str::SelectLanguageTitle
    "Da", // Str::YesLabel
    "Ne", // Str::NoLabel
    "U redu", // Str::OkLabel
    "Izlazni format", // Str::OutFormatLabel
    "Postavke sučelja", // Str::InterfaceSettingsLabel
    "Veličina", // Str::InterfaceSizeLabel
    "Način rada", // Str::ModeLabel
    "Normalan", // Str::NormalModeLabel
    "Običan tekst", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Boja", // Str::InterfaceColorLabel
    "Zadano (običan tekst)", // Str::DefaultLabel
    "OpenSSL (binarni)", // Str::OpenSSLLabel
    "Koristi ovu lozinku", // Str::UsePasswordLabel
    "Kopiraj", // Str::CopyLabel
    "Ctrl + lijevi klik za dobivanje SHA256", // Str::GetSHA256Text
    // Themes
    "Svijetla", // Str::LightThemeName
    "Tamna", // Str::DarkThemeName
    // Colors
    "Plava", // Str::BlueName
    "Cijan", // Str::CyanName
    "Zelena", // Str::GreenName
    "Limeta", // Str::LimeName
    "Žuta", // Str::YellowName
    "Smeđa", // Str::BrownName
    "Narančasta", // Str::OrangeName
    "Crvena", // Str::RedName
    "Ružičasta", // Str::PinkName
    "Ljubičasta", // Str::PurpleName
    "Siva", // Str::GreyName
    "Bijela", // Str::WhiteName
    "Crna", // Str::BlackName

};
static_assert(sizeof(textosHR) / sizeof(textosHR[0]) == N,
    "Faltan o sobran textos en croata: revisa que coincidan con Str::Count.");

// Dansk (da)
constexpr const char* textosDA[] = {

    
    
    // Info
    "Tryk på Enter for at afslutte...", // Str::ExitInfoMessage
    "Aktivér kun, hvis filens indhold", // Str::PlainTextModeMessage_FirstLine
    "er almindelig tekst", // Str::PlainTextModeMessage_SecondLine
    "Den krypterede fil gemmes", // Str::DefaultCipherModeText_FirstLine
    "som udskrivbare tegn", // Str::DefaultCipherModeText_SecondLine
    "Den krypterede fil gemmes i", // Str::OpenSSLCipherModeText_FirstLine
    "binært format, kompatibelt med OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-iterationer:", // Str::PBKDF2IterationsText
    // Errors
    "Fejl: forkerte parametre", // Str::WrongParamsText
    "Modtaget værdi", // Str::InputValueText
    "Modtaget sti", // Str::InputPathText
    "Den modtagne værdi kunne ikke konverteres til et tal større end eller lig med 0", // Str::WrongNumberValueMessage
    "Den modtagne sti svarer ikke til nogen eksisterende fil", // Str::WrongPathValueMessage
    "Den angivne valgmulighed genkendes ikke som en gyldig parameter", // Str::InvalidOptionMessage
    "Angivet valgmulighed", // Str::EnteredOptionText
    "Ukendt undtagelse", // Str::UnknownExceptionText
    "GLFW kunne ikke initialiseres", // Str::GLFWErrorMessage
    "GLAD kunne ikke initialiseres", // Str::GLADErrorMessage
    "Fejl: Filen kunne ikke åbnes til læsning", // Str::ReadFileErrorMessage
    "Fejl ved læsning af filens indhold", // Str::ErrorWhileReadingMessage
    "Fejl: Filen kunne ikke åbnes til skrivning", // Str::WriteFileErrorMessage
    "Fejl: Den hexadecimale streng skal have et lige antal tegn", // Str::HexStringErrorMessage
    "Fejl: Ugyldigt hexadecimalt tegn i strengen", // Str::InvalidHexCharacterErrorMessage
    "Fejl: Filen kunne ikke gemmes", // Str::SaveFileErrorMessage
    "Fejl: Filen kunne ikke indlæses", // Str::LoadFileErrorMessage
    "Fejl: Ugyldigt filformat (5 felter forventet: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Fejl: Antallet af iterationer overstiger det fastsatte maksimum (10.000.000)", // Str::MaxIterationsErrorMessage
    "Fejl: Integritetskontrollen mislykkedes, forkert adgangskode eller beskadiget/manipuleret fil", // Str::IntegrityCheckErrorMessage
    "Fejl: Adgangskoden må ikke være tom", // Str::EmptyPasswordErrorMessage
    "Fejl: Stien til destinationsfilen er en mappe", // Str::OutputFileIsDirectoryErrorMessage
    "Fejl: Stien til kildefilen er en mappe", // Str::InputFileIsDirectoryErrorMessage
    "Fejl: Stien til destinationsfilen må ikke være tom", // Str::EmptyOutputFilePathErrorMessage
    "Fejl: Stien til kildefilen må ikke være tom", // Str::EmptyInputFilePathErrorMessage
    "Fejl: Kildefilen findes ikke", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Sprog: Dansk", // Str::LanguageLabel
    "Adgangskode", // Str::PasswordLabel
    "Adgangskodens længde", // Str::PasswordLenghtLabel
    "Fil", // Str::FileLabel
    "Filen", // Str::TheFileLabel
    "Sti", // Str::PathLabel
    "Inputsti", // Str::InputFilePathLabel
    "Outputsti", // Str::OutputFilePathLabel
    "Byt om på stier", // Str::SwapPathsLabel
    "vil blive overskrevet", // Str::WillBeOverwrittenLabel
    "Krypterer...", // Str::EncryptingText
    "Dekrypterer...", // Str::DecryptingText
    "Kryptér", // Str::EncryptText
    "Dekryptér", // Str::DecryptText
    "Filen blev krypteret", // Str::FileEncryptedMessage
    "Filen blev dekrypteret", // Str::FileDecryptedMessage
    "Advarsel!", // Str::WarningTitle
    "Er du sikker?", // Str::AreYouSureTitle
    "Indstillinger", // Str::SettingsTitle
    "Adgangskodegenerator", // Str::GeneratePasswordTitle
    "Vælg sprog", // Str::SelectLanguageTitle
    "Ja", // Str::YesLabel
    "Nej", // Str::NoLabel
    "OK", // Str::OkLabel
    "Outputformat", // Str::OutFormatLabel
    "Indstillinger for brugerflade", // Str::InterfaceSettingsLabel
    "Størrelse", // Str::InterfaceSizeLabel
    "Tilstand", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Almindelig tekst", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Farve", // Str::InterfaceColorLabel
    "Standard (almindelig tekst)", // Str::DefaultLabel
    "OpenSSL (binær)", // Str::OpenSSLLabel
    "Brug denne adgangskode", // Str::UsePasswordLabel
    "Kopiér", // Str::CopyLabel
    "Ctrl + venstreklik for at få SHA256", // Str::GetSHA256Text
    // Themes
    "Lyst", // Str::LightThemeName
    "Mørkt", // Str::DarkThemeName
    // Colors
    "Blå", // Str::BlueName
    "Cyan", // Str::CyanName
    "Grøn", // Str::GreenName
    "Limegrøn", // Str::LimeName
    "Gul", // Str::YellowName
    "Brun", // Str::BrownName
    "Orange", // Str::OrangeName
    "Rød", // Str::RedName
    "Lyserød", // Str::PinkName
    "Lilla", // Str::PurpleName
    "Grå", // Str::GreyName
    "Hvid", // Str::WhiteName
    "Sort", // Str::BlackName

};
static_assert(sizeof(textosDA) / sizeof(textosDA[0]) == N,
    "Faltan o sobran textos en danes: revisa que coincidan con Str::Count.");

// Suomi (fi)
constexpr const char* textosFI[] = {

    
    
    // Info
    "Poistu painamalla Enter...", // Str::ExitInfoMessage
    "Ota käyttöön vain, jos tiedoston", // Str::PlainTextModeMessage_FirstLine
    "sisältö on pelkkää tekstiä", // Str::PlainTextModeMessage_SecondLine
    "Salattu tiedosto tallennetaan", // Str::DefaultCipherModeText_FirstLine
    "tulostettavina merkkeinä", // Str::DefaultCipherModeText_SecondLine
    "Salattu tiedosto tallennetaan", // Str::OpenSSLCipherModeText_FirstLine
    "OpenSSL-yhteensopivassa binäärimuodossa", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-iteraatiot:", // Str::PBKDF2IterationsText
    // Errors
    "Virhe: virheelliset parametrit", // Str::WrongParamsText
    "Vastaanotettu arvo", // Str::InputValueText
    "Vastaanotettu polku", // Str::InputPathText
    "Vastaanotettua arvoa ei voitu muuntaa luvuksi, joka on suurempi tai yhtä suuri kuin 0", // Str::WrongNumberValueMessage
    "Vastaanotettu polku ei vastaa mitään olemassa olevaa tiedostoa", // Str::WrongPathValueMessage
    "Annettua valintaa ei tunnisteta kelvolliseksi parametriksi", // Str::InvalidOptionMessage
    "Annettu valinta", // Str::EnteredOptionText
    "Tuntematon poikkeus", // Str::UnknownExceptionText
    "GLFW:n alustus epäonnistui", // Str::GLFWErrorMessage
    "GLAD:n alustus epäonnistui", // Str::GLADErrorMessage
    "Virhe: Tiedostoa ei voitu avata lukemista varten", // Str::ReadFileErrorMessage
    "Virhe tiedoston sisältöä luettaessa", // Str::ErrorWhileReadingMessage
    "Virhe: Tiedostoa ei voitu avata kirjoittamista varten", // Str::WriteFileErrorMessage
    "Virhe: Heksadesimaalimerkkijonossa on oltava parillinen määrä merkkejä", // Str::HexStringErrorMessage
    "Virhe: Merkkijonossa on virheellinen heksadesimaalimerkki", // Str::InvalidHexCharacterErrorMessage
    "Virhe: Tiedostoa ei voitu tallentaa", // Str::SaveFileErrorMessage
    "Virhe: Tiedostoa ei voitu ladata", // Str::LoadFileErrorMessage
    "Virhe: Virheellinen tiedostomuoto (odotettiin 5 kenttää: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Virhe: Iteraatioiden määrä ylittää asetetun enimmäismäärän (10 000 000)", // Str::MaxIterationsErrorMessage
    "Virhe: Eheyden tarkistus epäonnistui, väärä salasana tai vioittunut/peukaloitu tiedosto", // Str::IntegrityCheckErrorMessage
    "Virhe: Salasana ei voi olla tyhjä", // Str::EmptyPasswordErrorMessage
    "Virhe: Kohdetiedoston polku on kansio", // Str::OutputFileIsDirectoryErrorMessage
    "Virhe: Lähdetiedoston polku on kansio", // Str::InputFileIsDirectoryErrorMessage
    "Virhe: Kohdetiedoston polku ei voi olla tyhjä", // Str::EmptyOutputFilePathErrorMessage
    "Virhe: Lähdetiedoston polku ei voi olla tyhjä", // Str::EmptyInputFilePathErrorMessage
    "Virhe: Lähdetiedostoa ei ole olemassa", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Kieli: Suomi", // Str::LanguageLabel
    "Salasana", // Str::PasswordLabel
    "Salasanan pituus", // Str::PasswordLenghtLabel
    "Tiedosto", // Str::FileLabel
    "Tiedosto", // Str::TheFileLabel
    "Polku", // Str::PathLabel
    "Syötetiedoston polku", // Str::InputFilePathLabel
    "Tulostiedoston polku", // Str::OutputFilePathLabel
    "Vaihda polut keskenään", // Str::SwapPathsLabel
    "korvataan", // Str::WillBeOverwrittenLabel
    "Salataan...", // Str::EncryptingText
    "Puretaan salausta...", // Str::DecryptingText
    "Salaa", // Str::EncryptText
    "Pura salaus", // Str::DecryptText
    "Tiedosto salattiin onnistuneesti", // Str::FileEncryptedMessage
    "Tiedoston salaus purettiin onnistuneesti", // Str::FileDecryptedMessage
    "Varoitus!", // Str::WarningTitle
    "Oletko varma?", // Str::AreYouSureTitle
    "Asetukset", // Str::SettingsTitle
    "Salasanageneraattori", // Str::GeneratePasswordTitle
    "Valitse kieli", // Str::SelectLanguageTitle
    "Kyllä", // Str::YesLabel
    "Ei", // Str::NoLabel
    "OK", // Str::OkLabel
    "Tulostusmuoto", // Str::OutFormatLabel
    "Käyttöliittymän asetukset", // Str::InterfaceSettingsLabel
    "Koko", // Str::InterfaceSizeLabel
    "Tila", // Str::ModeLabel
    "Normaali", // Str::NormalModeLabel
    "Pelkkä teksti", // Str::PlaintextModeLabel
    "Teema", // Str::InterfaceThemeLabel
    "Väri", // Str::InterfaceColorLabel
    "Oletus (pelkkä teksti)", // Str::DefaultLabel
    "OpenSSL (binääri)", // Str::OpenSSLLabel
    "Käytä tätä salasanaa", // Str::UsePasswordLabel
    "Kopioi", // Str::CopyLabel
    "Ctrl + vasen napsautus hakee SHA256:n", // Str::GetSHA256Text
    // Themes
    "Vaalea", // Str::LightThemeName
    "Tumma", // Str::DarkThemeName
    // Colors
    "Sininen", // Str::BlueName
    "Syaani", // Str::CyanName
    "Vihreä", // Str::GreenName
    "Limetinvihreä", // Str::LimeName
    "Keltainen", // Str::YellowName
    "Ruskea", // Str::BrownName
    "Oranssi", // Str::OrangeName
    "Punainen", // Str::RedName
    "Vaaleanpunainen", // Str::PinkName
    "Violetti", // Str::PurpleName
    "Harmaa", // Str::GreyName
    "Valkoinen", // Str::WhiteName
    "Musta", // Str::BlackName

};
static_assert(sizeof(textosFI) / sizeof(textosFI[0]) == N,
    "Faltan o sobran textos en fines: revisa que coincidan con Str::Count.");

// Кыргызча (ky)
constexpr const char* textosKY[] = {

    
    
    // Info
    "Чыгуу үчүн Enter баскычын басыңыз...", // Str::ExitInfoMessage
    "Файлдын мазмуну жөнөкөй текст", // Str::PlainTextModeMessage_FirstLine
    "болгондо гана күйгүзүңүз", // Str::PlainTextModeMessage_SecondLine
    "Шифрленген файл басып чыгарууга", // Str::DefaultCipherModeText_FirstLine
    "боло турган белгилер катары сакталат", // Str::DefaultCipherModeText_SecondLine
    "Шифрленген файл OpenSSL менен шайкеш", // Str::OpenSSLCipherModeText_FirstLine
    "экилик форматта сакталат", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 итерациялары:", // Str::PBKDF2IterationsText
    // Errors
    "Ката: туура эмес параметрлер", // Str::WrongParamsText
    "Алынган маани", // Str::InputValueText
    "Алынган жол", // Str::InputPathText
    "Алынган маанини 0дөн чоң же 0гө барабар санга айландыруу мүмкүн болгон жок", // Str::WrongNumberValueMessage
    "Алынган жол бар файлдардын бирине да дал келбейт", // Str::WrongPathValueMessage
    "Киргизилген опция жарактуу параметр катары таанылган жок", // Str::InvalidOptionMessage
    "Киргизилген опция", // Str::EnteredOptionText
    "Белгисиз өзгөчө кырдаал", // Str::UnknownExceptionText
    "GLFW ишке киргизилген жок", // Str::GLFWErrorMessage
    "GLAD ишке киргизилген жок", // Str::GLADErrorMessage
    "Ката: Файлды окуу үчүн ачуу мүмкүн болгон жок", // Str::ReadFileErrorMessage
    "Файлдын мазмунун окууда ката кетти", // Str::ErrorWhileReadingMessage
    "Ката: Файлды жазуу үчүн ачуу мүмкүн болгон жок", // Str::WriteFileErrorMessage
    "Ката: Он алтылык саптагы белгилердин саны жуп болушу керек", // Str::HexStringErrorMessage
    "Ката: Сапта жараксыз он алтылык белги бар", // Str::InvalidHexCharacterErrorMessage
    "Ката: Файлды сактоо мүмкүн болгон жок", // Str::SaveFileErrorMessage
    "Ката: Файлды жүктөө мүмкүн болгон жок", // Str::LoadFileErrorMessage
    "Ката: Файлдын форматы жараксыз (5 талаа күтүлгөн: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Ката: Итерациялардын саны белгиленген максимумдан ашып кетти (10 000 000)", // Str::MaxIterationsErrorMessage
    "Ката: Бүтүндүктү текшерүү ийгиликсиз болду, сырсөз туура эмес же файл бузулган/өзгөртүлгөн", // Str::IntegrityCheckErrorMessage
    "Ката: Сырсөз бош болбошу керек", // Str::EmptyPasswordErrorMessage
    "Ката: Максаттуу файлдын жолу папка болуп саналат", // Str::OutputFileIsDirectoryErrorMessage
    "Ката: Баштапкы файлдын жолу папка болуп саналат", // Str::InputFileIsDirectoryErrorMessage
    "Ката: Максаттуу файлдын жолу бош болбошу керек", // Str::EmptyOutputFilePathErrorMessage
    "Ката: Баштапкы файлдын жолу бош болбошу керек", // Str::EmptyInputFilePathErrorMessage
    "Ката: Баштапкы файл жок", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Тил: Кыргызча", // Str::LanguageLabel
    "Сырсөз", // Str::PasswordLabel
    "Сырсөздүн узундугу", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файл", // Str::TheFileLabel
    "Жол", // Str::PathLabel
    "Кирүүчү файлдын жолу", // Str::InputFilePathLabel
    "Чыгуучу файлдын жолу", // Str::OutputFilePathLabel
    "Жолдордун ордун алмаштыруу", // Str::SwapPathsLabel
    "кайра жазылат", // Str::WillBeOverwrittenLabel
    "Шифрленүүдө...", // Str::EncryptingText
    "Шифри ачылууда...", // Str::DecryptingText
    "Шифрлөө", // Str::EncryptText
    "Шифрди ачуу", // Str::DecryptText
    "Файл ийгиликтүү шифрленди", // Str::FileEncryptedMessage
    "Файлдын шифри ийгиликтүү ачылды", // Str::FileDecryptedMessage
    "Эскертүү!", // Str::WarningTitle
    "Ишенесизби?", // Str::AreYouSureTitle
    "Жөндөөлөр", // Str::SettingsTitle
    "Сырсөз генератору", // Str::GeneratePasswordTitle
    "Тилди тандаңыз", // Str::SelectLanguageTitle
    "Ооба", // Str::YesLabel
    "Жок", // Str::NoLabel
    "OK", // Str::OkLabel
    "Чыгуу форматы", // Str::OutFormatLabel
    "Интерфейс жөндөөлөрү", // Str::InterfaceSettingsLabel
    "Өлчөм", // Str::InterfaceSizeLabel
    "Режим", // Str::ModeLabel
    "Кадимки", // Str::NormalModeLabel
    "Жөнөкөй текст", // Str::PlaintextModeLabel
    "Тема", // Str::InterfaceThemeLabel
    "Түс", // Str::InterfaceColorLabel
    "Демейки (жөнөкөй текст)", // Str::DefaultLabel
    "OpenSSL (экилик)", // Str::OpenSSLLabel
    "Бул сырсөздү колдонуу", // Str::UsePasswordLabel
    "Көчүрүү", // Str::CopyLabel
    "SHA256 алуу үчүн Ctrl + сол баскыч", // Str::GetSHA256Text
    // Themes
    "Жарык", // Str::LightThemeName
    "Караңгы", // Str::DarkThemeName
    // Colors
    "Көк", // Str::BlueName
    "Көгүлтүр", // Str::CyanName
    "Жашыл", // Str::GreenName
    "Ачык жашыл", // Str::LimeName
    "Сары", // Str::YellowName
    "Күрөң", // Str::BrownName
    "Кызгылт сары", // Str::OrangeName
    "Кызыл", // Str::RedName
    "Кызгылт", // Str::PinkName
    "Кызгылт көк", // Str::PurpleName
    "Боз", // Str::GreyName
    "Ак", // Str::WhiteName
    "Кара", // Str::BlackName

};
static_assert(sizeof(textosKY) / sizeof(textosKY[0]) == N,
    "Faltan o sobran textos en kirguis: revisa que coincidan con Str::Count.");

// Norsk (nb)
constexpr const char* textosNB[] = {

    
    
    // Info
    "Trykk Enter for å avslutte...", // Str::ExitInfoMessage
    "Aktiver bare hvis filens innhold", // Str::PlainTextModeMessage_FirstLine
    "er ren tekst", // Str::PlainTextModeMessage_SecondLine
    "Den krypterte filen lagres", // Str::DefaultCipherModeText_FirstLine
    "som utskrivbare tegn", // Str::DefaultCipherModeText_SecondLine
    "Den krypterte filen lagres i", // Str::OpenSSLCipherModeText_FirstLine
    "binært format, kompatibelt med OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-iterasjoner:", // Str::PBKDF2IterationsText
    // Errors
    "Feil: ugyldige parametere", // Str::WrongParamsText
    "Mottatt verdi", // Str::InputValueText
    "Mottatt bane", // Str::InputPathText
    "Den mottatte verdien kunne ikke konverteres til et tall større enn eller lik 0", // Str::WrongNumberValueMessage
    "Den mottatte banen samsvarer ikke med noen eksisterende fil", // Str::WrongPathValueMessage
    "Det angitte alternativet gjenkjennes ikke som en gyldig parameter", // Str::InvalidOptionMessage
    "Angitt alternativ", // Str::EnteredOptionText
    "Ukjent unntak", // Str::UnknownExceptionText
    "Kunne ikke initialisere GLFW", // Str::GLFWErrorMessage
    "Kunne ikke initialisere GLAD", // Str::GLADErrorMessage
    "Feil: Kunne ikke åpne filen for lesing", // Str::ReadFileErrorMessage
    "Feil ved lesing av filens innhold", // Str::ErrorWhileReadingMessage
    "Feil: Kunne ikke åpne filen for skriving", // Str::WriteFileErrorMessage
    "Feil: Den heksadesimale strengen må inneholde et partall tegn", // Str::HexStringErrorMessage
    "Feil: Ugyldig heksadesimalt tegn i strengen", // Str::InvalidHexCharacterErrorMessage
    "Feil: Kunne ikke lagre filen", // Str::SaveFileErrorMessage
    "Feil: Kunne ikke laste inn filen", // Str::LoadFileErrorMessage
    "Feil: Ugyldig filformat (forventet 5 felt: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Feil: Antall iterasjoner overskrider fastsatt maksimum (10 000 000)", // Str::MaxIterationsErrorMessage
    "Feil: Integritetskontrollen mislyktes, feil passord eller skadet/manipulert fil", // Str::IntegrityCheckErrorMessage
    "Feil: Passordet kan ikke være tomt", // Str::EmptyPasswordErrorMessage
    "Feil: Banen til målfilen er en mappe", // Str::OutputFileIsDirectoryErrorMessage
    "Feil: Banen til kildefilen er en mappe", // Str::InputFileIsDirectoryErrorMessage
    "Feil: Banen til målfilen kan ikke være tom", // Str::EmptyOutputFilePathErrorMessage
    "Feil: Banen til kildefilen kan ikke være tom", // Str::EmptyInputFilePathErrorMessage
    "Feil: Kildefilen finnes ikke", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Språk: Norsk", // Str::LanguageLabel
    "Passord", // Str::PasswordLabel
    "Passordlengde", // Str::PasswordLenghtLabel
    "Fil", // Str::FileLabel
    "Filen", // Str::TheFileLabel
    "Bane", // Str::PathLabel
    "Inndatabane", // Str::InputFilePathLabel
    "Utdatabane", // Str::OutputFilePathLabel
    "Bytt om baner", // Str::SwapPathsLabel
    "vil bli overskrevet", // Str::WillBeOverwrittenLabel
    "Krypterer...", // Str::EncryptingText
    "Dekrypterer...", // Str::DecryptingText
    "Krypter", // Str::EncryptText
    "Dekrypter", // Str::DecryptText
    "Filen ble kryptert", // Str::FileEncryptedMessage
    "Filen ble dekryptert", // Str::FileDecryptedMessage
    "Advarsel!", // Str::WarningTitle
    "Er du sikker?", // Str::AreYouSureTitle
    "Innstillinger", // Str::SettingsTitle
    "Passordgenerator", // Str::GeneratePasswordTitle
    "Velg språk", // Str::SelectLanguageTitle
    "Ja", // Str::YesLabel
    "Nei", // Str::NoLabel
    "OK", // Str::OkLabel
    "Utdataformat", // Str::OutFormatLabel
    "Grensesnittinnstillinger", // Str::InterfaceSettingsLabel
    "Størrelse", // Str::InterfaceSizeLabel
    "Modus", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Ren tekst", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Farge", // Str::InterfaceColorLabel
    "Standard (ren tekst)", // Str::DefaultLabel
    "OpenSSL (binær)", // Str::OpenSSLLabel
    "Bruk dette passordet", // Str::UsePasswordLabel
    "Kopier", // Str::CopyLabel
    "Ctrl + venstreklikk for å hente SHA256", // Str::GetSHA256Text
    // Themes
    "Lyst", // Str::LightThemeName
    "Mørkt", // Str::DarkThemeName
    // Colors
    "Blå", // Str::BlueName
    "Cyan", // Str::CyanName
    "Grønn", // Str::GreenName
    "Limegrønn", // Str::LimeName
    "Gul", // Str::YellowName
    "Brun", // Str::BrownName
    "Oransje", // Str::OrangeName
    "Rød", // Str::RedName
    "Rosa", // Str::PinkName
    "Lilla", // Str::PurpleName
    "Grå", // Str::GreyName
    "Hvit", // Str::WhiteName
    "Svart", // Str::BlackName

};
static_assert(sizeof(textosNB) / sizeof(textosNB[0]) == N,
    "Faltan o sobran textos en noruego: revisa que coincidan con Str::Count.");

// Беларуская (be)
constexpr const char* textosBE[] = {

    
    
    // Info
    "Націсніце Enter, каб выйсці...", // Str::ExitInfoMessage
    "Уключайце, толькі калі змесціва", // Str::PlainTextModeMessage_FirstLine
    "файла з'яўляецца простым тэкстам", // Str::PlainTextModeMessage_SecondLine
    "Зашыфраваны файл будзе захаваны", // Str::DefaultCipherModeText_FirstLine
    "у выглядзе друкаваных сімвалаў", // Str::DefaultCipherModeText_SecondLine
    "Зашыфраваны файл будзе захаваны", // Str::OpenSSLCipherModeText_FirstLine
    "у двайковым фармаце, сумяшчальным з OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Ітэрацыі PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Памылка: няправільныя параметры", // Str::WrongParamsText
    "Атрыманае значэнне", // Str::InputValueText
    "Атрыманы шлях", // Str::InputPathText
    "Не ўдалося пераўтварыць атрыманае значэнне ў лік, большы або роўны 0", // Str::WrongNumberValueMessage
    "Атрыманы шлях не адпавядае ніводнаму існуючаму файлу", // Str::WrongPathValueMessage
    "Уведзены параметр не распазнаны як дапушчальны", // Str::InvalidOptionMessage
    "Уведзены параметр", // Str::EnteredOptionText
    "Невядомае выключэнне", // Str::UnknownExceptionText
    "Не ўдалося ініцыялізаваць GLFW", // Str::GLFWErrorMessage
    "Не ўдалося ініцыялізаваць GLAD", // Str::GLADErrorMessage
    "Памылка: Не ўдалося адкрыць файл для чытання", // Str::ReadFileErrorMessage
    "Памылка пры чытанні змесціва файла", // Str::ErrorWhileReadingMessage
    "Памылка: Не ўдалося адкрыць файл для запісу", // Str::WriteFileErrorMessage
    "Памылка: Шаснаццатковы радок павінен мець цотную колькасць сімвалаў", // Str::HexStringErrorMessage
    "Памылка: Недапушчальны шаснаццатковы сімвал у радку", // Str::InvalidHexCharacterErrorMessage
    "Памылка: Не ўдалося захаваць файл", // Str::SaveFileErrorMessage
    "Памылка: Не ўдалося загрузіць файл", // Str::LoadFileErrorMessage
    "Памылка: Няправільны фармат файла (чакаецца 5 палёў: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Памылка: Колькасць ітэрацый перавышае ўстаноўлены максімум (10 000 000)", // Str::MaxIterationsErrorMessage
    "Памылка: Праверка цэласнасці не пройдзена, няправільны пароль або файл пашкоджаны/зменены", // Str::IntegrityCheckErrorMessage
    "Памылка: Пароль не можа быць пустым", // Str::EmptyPasswordErrorMessage
    "Памылка: Шлях да мэтавага файла з'яўляецца каталогам", // Str::OutputFileIsDirectoryErrorMessage
    "Памылка: Шлях да зыходнага файла з'яўляецца каталогам", // Str::InputFileIsDirectoryErrorMessage
    "Памылка: Шлях да мэтавага файла не можа быць пустым", // Str::EmptyOutputFilePathErrorMessage
    "Памылка: Шлях да зыходнага файла не можа быць пустым", // Str::EmptyInputFilePathErrorMessage
    "Памылка: Зыходны файл не існуе", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Мова: Беларуская", // Str::LanguageLabel
    "Пароль", // Str::PasswordLabel
    "Даўжыня пароля", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файл", // Str::TheFileLabel
    "Шлях", // Str::PathLabel
    "Шлях да ўваходнага файла", // Str::InputFilePathLabel
    "Шлях да выхаднога файла", // Str::OutputFilePathLabel
    "Памяняць шляхі месцамі", // Str::SwapPathsLabel
    "будзе перазапісаны", // Str::WillBeOverwrittenLabel
    "Шыфраванне...", // Str::EncryptingText
    "Расшыфроўка...", // Str::DecryptingText
    "Зашыфраваць", // Str::EncryptText
    "Расшыфраваць", // Str::DecryptText
    "Файл паспяхова зашыфраваны", // Str::FileEncryptedMessage
    "Файл паспяхова расшыфраваны", // Str::FileDecryptedMessage
    "Увага!", // Str::WarningTitle
    "Вы ўпэўнены?", // Str::AreYouSureTitle
    "Налады", // Str::SettingsTitle
    "Генератар пароляў", // Str::GeneratePasswordTitle
    "Выбар мовы", // Str::SelectLanguageTitle
    "Так", // Str::YesLabel
    "Не", // Str::NoLabel
    "OK", // Str::OkLabel
    "Фармат вываду", // Str::OutFormatLabel
    "Налады інтэрфейсу", // Str::InterfaceSettingsLabel
    "Памер", // Str::InterfaceSizeLabel
    "Рэжым", // Str::ModeLabel
    "Звычайны", // Str::NormalModeLabel
    "Просты тэкст", // Str::PlaintextModeLabel
    "Тэма", // Str::InterfaceThemeLabel
    "Колер", // Str::InterfaceColorLabel
    "Па змаўчанні (просты тэкст)", // Str::DefaultLabel
    "OpenSSL (двайковы)", // Str::OpenSSLLabel
    "Выкарыстаць гэты пароль", // Str::UsePasswordLabel
    "Капіраваць", // Str::CopyLabel
    "Ctrl + левы клік, каб атрымаць SHA256", // Str::GetSHA256Text
    // Themes
    "Светлая", // Str::LightThemeName
    "Цёмная", // Str::DarkThemeName
    // Colors
    "Сіні", // Str::BlueName
    "Блакітны", // Str::CyanName
    "Зялёны", // Str::GreenName
    "Лаймавы", // Str::LimeName
    "Жоўты", // Str::YellowName
    "Карычневы", // Str::BrownName
    "Аранжавы", // Str::OrangeName
    "Чырвоны", // Str::RedName
    "Ружовы", // Str::PinkName
    "Фіялетавы", // Str::PurpleName
    "Шэры", // Str::GreyName
    "Белы", // Str::WhiteName
    "Чорны", // Str::BlackName

};
static_assert(sizeof(textosBE) / sizeof(textosBE[0]) == N,
    "Faltan o sobran textos en bielorruso: revisa que coincidan con Str::Count.");

// Татарча (tt)
constexpr const char* textosTT[] = {

    
    
    // Info
    "Чыгу өчен Enter басыгыз...", // Str::ExitInfoMessage
    "Файлның эчтәлеге гади текст", // Str::PlainTextModeMessage_FirstLine
    "булганда гына кабызыгыз", // Str::PlainTextModeMessage_SecondLine
    "Шифрланган файл басып чыгарырлык", // Str::DefaultCipherModeText_FirstLine
    "символлар рәвешендә сакланачак", // Str::DefaultCipherModeText_SecondLine
    "Шифрланган файл икеле форматта", // Str::OpenSSLCipherModeText_FirstLine
    "сакланачак (OpenSSL белән туры килә)", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 итерацияләре:", // Str::PBKDF2IterationsText
    // Errors
    "Хата: дөрес булмаган параметрлар", // Str::WrongParamsText
    "Алынган кыйммәт", // Str::InputValueText
    "Алынган юл", // Str::InputPathText
    "Алынган кыйммәтне 0дән зуррак яки 0гә тигез санга әйләндереп булмады", // Str::WrongNumberValueMessage
    "Алынган юл булган файлларның берсенә дә туры килми", // Str::WrongPathValueMessage
    "Кертелгән опция дөрес параметр буларак танылмады", // Str::InvalidOptionMessage
    "Кертелгән опция", // Str::EnteredOptionText
    "Билгесез искәрмә", // Str::UnknownExceptionText
    "GLFW инициализацияләү уңышсыз булды", // Str::GLFWErrorMessage
    "GLAD инициализацияләү уңышсыз булды", // Str::GLADErrorMessage
    "Хата: Файлны уку өчен ачып булмады", // Str::ReadFileErrorMessage
    "Файл эчтәлеген укыганда хата килеп чыкты", // Str::ErrorWhileReadingMessage
    "Хата: Файлны язу өчен ачып булмады", // Str::WriteFileErrorMessage
    "Хата: Уналтылы юлдагы символлар саны җөп булырга тиеш", // Str::HexStringErrorMessage
    "Хата: Юлда дөрес булмаган уналтылы символ бар", // Str::InvalidHexCharacterErrorMessage
    "Хата: Файлны саклап булмады", // Str::SaveFileErrorMessage
    "Хата: Файлны йөкләп булмады", // Str::LoadFileErrorMessage
    "Хата: Файл форматы дөрес түгел (5 кыр көтелгән: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Хата: Итерацияләр саны билгеләнгән максимумнан артып китә (10 000 000)", // Str::MaxIterationsErrorMessage
    "Хата: Бөтенлекне тикшерү уңышсыз булды, серсүз дөрес түгел яки файл бозылган/үзгәртелгән", // Str::IntegrityCheckErrorMessage
    "Хата: Серсүз буш була алмый", // Str::EmptyPasswordErrorMessage
    "Хата: Максат файлының юлы папка булып тора", // Str::OutputFileIsDirectoryErrorMessage
    "Хата: Чыганак файлның юлы папка булып тора", // Str::InputFileIsDirectoryErrorMessage
    "Хата: Максат файлының юлы буш була алмый", // Str::EmptyOutputFilePathErrorMessage
    "Хата: Чыганак файлның юлы буш була алмый", // Str::EmptyInputFilePathErrorMessage
    "Хата: Чыганак файл юк", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Тел: Татарча", // Str::LanguageLabel
    "Серсүз", // Str::PasswordLabel
    "Серсүз озынлыгы", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файл", // Str::TheFileLabel
    "Юл", // Str::PathLabel
    "Керү файлының юлы", // Str::InputFilePathLabel
    "Чыгу файлының юлы", // Str::OutputFilePathLabel
    "Юлларны алмаштыру", // Str::SwapPathsLabel
    "яңадан языла", // Str::WillBeOverwrittenLabel
    "Шифрлана...", // Str::EncryptingText
    "Шифр ачыла...", // Str::DecryptingText
    "Шифрлау", // Str::EncryptText
    "Шифрны ачу", // Str::DecryptText
    "Файл уңышлы шифрланды", // Str::FileEncryptedMessage
    "Файлның шифры уңышлы ачылды", // Str::FileDecryptedMessage
    "Игътибар!", // Str::WarningTitle
    "Сез ышанасызмы?", // Str::AreYouSureTitle
    "Көйләүләр", // Str::SettingsTitle
    "Серсүз генераторы", // Str::GeneratePasswordTitle
    "Телне сайлагыз", // Str::SelectLanguageTitle
    "Әйе", // Str::YesLabel
    "Юк", // Str::NoLabel
    "OK", // Str::OkLabel
    "Чыгу форматы", // Str::OutFormatLabel
    "Интерфейс көйләүләре", // Str::InterfaceSettingsLabel
    "Зурлык", // Str::InterfaceSizeLabel
    "Режим", // Str::ModeLabel
    "Гадәти", // Str::NormalModeLabel
    "Гади текст", // Str::PlaintextModeLabel
    "Тема", // Str::InterfaceThemeLabel
    "Төс", // Str::InterfaceColorLabel
    "Килешү буенча (гади текст)", // Str::DefaultLabel
    "OpenSSL (икеле)", // Str::OpenSSLLabel
    "Бу серсүзне куллану", // Str::UsePasswordLabel
    "Күчереп алу", // Str::CopyLabel
    "SHA256 алу өчен Ctrl + сул төймә", // Str::GetSHA256Text
    // Themes
    "Якты", // Str::LightThemeName
    "Караңгы", // Str::DarkThemeName
    // Colors
    "Зәңгәр", // Str::BlueName
    "Ачык зәңгәр", // Str::CyanName
    "Яшел", // Str::GreenName
    "Ачык яшел", // Str::LimeName
    "Сары", // Str::YellowName
    "Көрән", // Str::BrownName
    "Кызгылт сары", // Str::OrangeName
    "Кызыл", // Str::RedName
    "Алсу", // Str::PinkName
    "Шәмәхә", // Str::PurpleName
    "Соры", // Str::GreyName
    "Ак", // Str::WhiteName
    "Кара", // Str::BlackName

};
static_assert(sizeof(textosTT) / sizeof(textosTT[0]) == N,
    "Faltan o sobran textos en tartaro: revisa que coincidan con Str::Count.");

// ქართული (ka)
constexpr const char* textosKA[] = {

    
    
    // Info
    "გასასვლელად დააჭირეთ Enter-ს...", // Str::ExitInfoMessage
    "ჩართეთ მხოლოდ იმ შემთხვევაში, თუ", // Str::PlainTextModeMessage_FirstLine
    "ფაილის შიგთავსი უბრალო ტექსტია", // Str::PlainTextModeMessage_SecondLine
    "დაშიფრული ფაილი შეინახება", // Str::DefaultCipherModeText_FirstLine
    "დასაბეჭდი სიმბოლოების სახით", // Str::DefaultCipherModeText_SecondLine
    "დაშიფრული ფაილი შეინახება ორობით", // Str::OpenSSLCipherModeText_FirstLine
    "ფორმატში, OpenSSL-თან თავსებადი", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 იტერაციები:", // Str::PBKDF2IterationsText
    // Errors
    "შეცდომა: არასწორი პარამეტრები", // Str::WrongParamsText
    "მიღებული მნიშვნელობა", // Str::InputValueText
    "მიღებული გზა", // Str::InputPathText
    "მიღებული მნიშვნელობის 0-ზე მეტ ან 0-ის ტოლ რიცხვად გარდაქმნა ვერ მოხერხდა", // Str::WrongNumberValueMessage
    "მიღებული გზა არცერთ არსებულ ფაილს არ შეესაბამება", // Str::WrongPathValueMessage
    "შეყვანილი ოფცია არ არის აღიარებული სწორ პარამეტრად", // Str::InvalidOptionMessage
    "შეყვანილი ოფცია", // Str::EnteredOptionText
    "უცნობი გამონაკლისი", // Str::UnknownExceptionText
    "GLFW-ის ინიციალიზაცია ვერ მოხერხდა", // Str::GLFWErrorMessage
    "GLAD-ის ინიციალიზაცია ვერ მოხერხდა", // Str::GLADErrorMessage
    "შეცდომა: ფაილის წასაკითხად გახსნა ვერ მოხერხდა", // Str::ReadFileErrorMessage
    "შეცდომა ფაილის შიგთავსის წაკითხვისას", // Str::ErrorWhileReadingMessage
    "შეცდომა: ფაილის ჩასაწერად გახსნა ვერ მოხერხდა", // Str::WriteFileErrorMessage
    "შეცდომა: თექვსმეტობით სტრიქონში სიმბოლოების რაოდენობა ლუწი უნდა იყოს", // Str::HexStringErrorMessage
    "შეცდომა: სტრიქონში არასწორი თექვსმეტობითი სიმბოლოა", // Str::InvalidHexCharacterErrorMessage
    "შეცდომა: ფაილის შენახვა ვერ მოხერხდა", // Str::SaveFileErrorMessage
    "შეცდომა: ფაილის ჩატვირთვა ვერ მოხერხდა", // Str::LoadFileErrorMessage
    "შეცდომა: ფაილის არასწორი ფორმატი (მოსალოდნელი იყო 5 ველი: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "შეცდომა: იტერაციების რაოდენობა აღემატება დადგენილ მაქსიმუმს (10 000 000)", // Str::MaxIterationsErrorMessage
    "შეცდომა: მთლიანობის შემოწმება ვერ მოხერხდა, არასწორი პაროლი ან დაზიანებული/შეცვლილი ფაილი", // Str::IntegrityCheckErrorMessage
    "შეცდომა: პაროლი არ შეიძლება იყოს ცარიელი", // Str::EmptyPasswordErrorMessage
    "შეცდომა: დანიშნულების ფაილის გზა საქაღალდეა", // Str::OutputFileIsDirectoryErrorMessage
    "შეცდომა: წყარო ფაილის გზა საქაღალდეა", // Str::InputFileIsDirectoryErrorMessage
    "შეცდომა: დანიშნულების ფაილის გზა არ შეიძლება იყოს ცარიელი", // Str::EmptyOutputFilePathErrorMessage
    "შეცდომა: წყარო ფაილის გზა არ შეიძლება იყოს ცარიელი", // Str::EmptyInputFilePathErrorMessage
    "შეცდომა: წყარო ფაილი არ არსებობს", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "ენა: ქართული", // Str::LanguageLabel
    "პაროლი", // Str::PasswordLabel
    "პაროლის სიგრძე", // Str::PasswordLenghtLabel
    "ფაილი", // Str::FileLabel
    "ფაილი", // Str::TheFileLabel
    "გზა", // Str::PathLabel
    "შემავალი ფაილის გზა", // Str::InputFilePathLabel
    "გამავალი ფაილის გზა", // Str::OutputFilePathLabel
    "გზების შენაცვლება", // Str::SwapPathsLabel
    "გადაიწერება", // Str::WillBeOverwrittenLabel
    "დაშიფვრა...", // Str::EncryptingText
    "გაშიფვრა...", // Str::DecryptingText
    "დაშიფვრა", // Str::EncryptText
    "გაშიფვრა", // Str::DecryptText
    "ფაილი წარმატებით დაიშიფრა", // Str::FileEncryptedMessage
    "ფაილი წარმატებით გაიშიფრა", // Str::FileDecryptedMessage
    "გაფრთხილება!", // Str::WarningTitle
    "დარწმუნებული ხართ?", // Str::AreYouSureTitle
    "პარამეტრები", // Str::SettingsTitle
    "პაროლის გენერატორი", // Str::GeneratePasswordTitle
    "აირჩიეთ ენა", // Str::SelectLanguageTitle
    "დიახ", // Str::YesLabel
    "არა", // Str::NoLabel
    "კარგი", // Str::OkLabel
    "გამოტანის ფორმატი", // Str::OutFormatLabel
    "ინტერფეისის პარამეტრები", // Str::InterfaceSettingsLabel
    "ზომა", // Str::InterfaceSizeLabel
    "რეჟიმი", // Str::ModeLabel
    "ჩვეულებრივი", // Str::NormalModeLabel
    "უბრალო ტექსტი", // Str::PlaintextModeLabel
    "თემა", // Str::InterfaceThemeLabel
    "ფერი", // Str::InterfaceColorLabel
    "ნაგულისხმევი (უბრალო ტექსტი)", // Str::DefaultLabel
    "OpenSSL (ორობითი)", // Str::OpenSSLLabel
    "ამ პაროლის გამოყენება", // Str::UsePasswordLabel
    "კოპირება", // Str::CopyLabel
    "Ctrl + მარცხენა დაწკაპუნება SHA256-ის მისაღებად", // Str::GetSHA256Text
    // Themes
    "ღია", // Str::LightThemeName
    "მუქი", // Str::DarkThemeName
    // Colors
    "ლურჯი", // Str::BlueName
    "ცისფერი", // Str::CyanName
    "მწვანე", // Str::GreenName
    "ლაიმისფერი", // Str::LimeName
    "ყვითელი", // Str::YellowName
    "ყავისფერი", // Str::BrownName
    "ნარინჯისფერი", // Str::OrangeName
    "წითელი", // Str::RedName
    "ვარდისფერი", // Str::PinkName
    "იისფერი", // Str::PurpleName
    "ნაცრისფერი", // Str::GreyName
    "თეთრი", // Str::WhiteName
    "შავი", // Str::BlackName

};
static_assert(sizeof(textosKA) / sizeof(textosKA[0]) == N,
    "Faltan o sobran textos en georgiano: revisa que coincidan con Str::Count.");

// Монгол (mn)
constexpr const char* textosMN[] = {

    
    
    // Info
    "Гарахын тулд Enter товчийг дарна уу...", // Str::ExitInfoMessage
    "Зөвхөн файлын агуулга энгийн текст", // Str::PlainTextModeMessage_FirstLine
    "байгаа үед идэвхжүүлнэ үү", // Str::PlainTextModeMessage_SecondLine
    "Шифрлэгдсэн файлыг хэвлэх боломжтой", // Str::DefaultCipherModeText_FirstLine
    "тэмдэгтүүд хэлбэрээр хадгална", // Str::DefaultCipherModeText_SecondLine
    "Шифрлэгдсэн файлыг OpenSSL-тэй нийцтэй", // Str::OpenSSLCipherModeText_FirstLine
    "хоёртын форматаар хадгална", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 давталт:", // Str::PBKDF2IterationsText
    // Errors
    "Алдаа: буруу параметрүүд", // Str::WrongParamsText
    "Хүлээн авсан утга", // Str::InputValueText
    "Хүлээн авсан зам", // Str::InputPathText
    "Хүлээн авсан утгыг 0-ээс их буюу 0-тэй тэнцүү тоо руу хөрвүүлж чадсангүй", // Str::WrongNumberValueMessage
    "Хүлээн авсан зам нь одоо байгаа ямар ч файлтай тохирохгүй байна", // Str::WrongPathValueMessage
    "Оруулсан сонголтыг хүчинтэй параметр гэж танисангүй", // Str::InvalidOptionMessage
    "Оруулсан сонголт", // Str::EnteredOptionText
    "Үл мэдэгдэх онцгой тохиолдол", // Str::UnknownExceptionText
    "GLFW-г эхлүүлж чадсангүй", // Str::GLFWErrorMessage
    "GLAD-г эхлүүлж чадсангүй", // Str::GLADErrorMessage
    "Алдаа: Файлыг унших зорилгоор нээж чадсангүй", // Str::ReadFileErrorMessage
    "Файлын агуулгыг уншихад алдаа гарлаа", // Str::ErrorWhileReadingMessage
    "Алдаа: Файлыг бичих зорилгоор нээж чадсангүй", // Str::WriteFileErrorMessage
    "Алдаа: Арван зургаатын мөрийн тэмдэгтийн тоо тэгш байх ёстой", // Str::HexStringErrorMessage
    "Алдаа: Мөрөнд буруу арван зургаатын тэмдэгт байна", // Str::InvalidHexCharacterErrorMessage
    "Алдаа: Файлыг хадгалж чадсангүй", // Str::SaveFileErrorMessage
    "Алдаа: Файлыг ачаалж чадсангүй", // Str::LoadFileErrorMessage
    "Алдаа: Файлын формат буруу (5 талбар хүлээгдэж байсан: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Алдаа: Давталтын тоо тогтоосон дээд хэмжээнээс хэтэрсэн (10 000 000)", // Str::MaxIterationsErrorMessage
    "Алдаа: Бүрэн бүтэн байдлын шалгалт амжилтгүй, нууц үг буруу эсвэл файл гэмтсэн/өөрчлөгдсөн", // Str::IntegrityCheckErrorMessage
    "Алдаа: Нууц үг хоосон байж болохгүй", // Str::EmptyPasswordErrorMessage
    "Алдаа: Хүлээн авах файлын зам нь хавтас байна", // Str::OutputFileIsDirectoryErrorMessage
    "Алдаа: Эх файлын зам нь хавтас байна", // Str::InputFileIsDirectoryErrorMessage
    "Алдаа: Хүлээн авах файлын зам хоосон байж болохгүй", // Str::EmptyOutputFilePathErrorMessage
    "Алдаа: Эх файлын зам хоосон байж болохгүй", // Str::EmptyInputFilePathErrorMessage
    "Алдаа: Эх файл байхгүй байна", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Хэл: Монгол", // Str::LanguageLabel
    "Нууц үг", // Str::PasswordLabel
    "Нууц үгийн урт", // Str::PasswordLenghtLabel
    "Файл", // Str::FileLabel
    "Файл", // Str::TheFileLabel
    "Зам", // Str::PathLabel
    "Оролтын файлын зам", // Str::InputFilePathLabel
    "Гаралтын файлын зам", // Str::OutputFilePathLabel
    "Замуудыг солих", // Str::SwapPathsLabel
    "дарж бичигдэнэ", // Str::WillBeOverwrittenLabel
    "Шифрлэж байна...", // Str::EncryptingText
    "Тайлж байна...", // Str::DecryptingText
    "Шифрлэх", // Str::EncryptText
    "Тайлах", // Str::DecryptText
    "Файлыг амжилттай шифрлэлээ", // Str::FileEncryptedMessage
    "Файлыг амжилттай тайллаа", // Str::FileDecryptedMessage
    "Анхааруулга!", // Str::WarningTitle
    "Та итгэлтэй байна уу?", // Str::AreYouSureTitle
    "Тохиргоо", // Str::SettingsTitle
    "Нууц үг үүсгэгч", // Str::GeneratePasswordTitle
    "Хэл сонгох", // Str::SelectLanguageTitle
    "Тийм", // Str::YesLabel
    "Үгүй", // Str::NoLabel
    "OK", // Str::OkLabel
    "Гаралтын формат", // Str::OutFormatLabel
    "Интерфейсийн тохиргоо", // Str::InterfaceSettingsLabel
    "Хэмжээ", // Str::InterfaceSizeLabel
    "Горим", // Str::ModeLabel
    "Энгийн", // Str::NormalModeLabel
    "Энгийн текст", // Str::PlaintextModeLabel
    "Загвар", // Str::InterfaceThemeLabel
    "Өнгө", // Str::InterfaceColorLabel
    "Үндсэн (энгийн текст)", // Str::DefaultLabel
    "OpenSSL (хоёртын)", // Str::OpenSSLLabel
    "Энэ нууц үгийг ашиглах", // Str::UsePasswordLabel
    "Хуулах", // Str::CopyLabel
    "SHA256 авахын тулд Ctrl + зүүн товш", // Str::GetSHA256Text
    // Themes
    "Цайвар", // Str::LightThemeName
    "Бараан", // Str::DarkThemeName
    // Colors
    "Цэнхэр", // Str::BlueName
    "Цайвар цэнхэр", // Str::CyanName
    "Ногоон", // Str::GreenName
    "Цайвар ногоон", // Str::LimeName
    "Шар", // Str::YellowName
    "Хүрэн", // Str::BrownName
    "Улбар шар", // Str::OrangeName
    "Улаан", // Str::RedName
    "Ягаан", // Str::PinkName
    "Нил ягаан", // Str::PurpleName
    "Саарал", // Str::GreyName
    "Цагаан", // Str::WhiteName
    "Хар", // Str::BlackName

};
static_assert(sizeof(textosMN) / sizeof(textosMN[0]) == N,
    "Faltan o sobran textos en mongol: revisa que coincidan con Str::Count.");

// Bosanski (bs)
constexpr const char* textosBS[] = {

    
    
    // Info
    "Pritisnite Enter za izlaz...", // Str::ExitInfoMessage
    "Omogućite samo ako je sadržaj", // Str::PlainTextModeMessage_FirstLine
    "datoteke običan tekst", // Str::PlainTextModeMessage_SecondLine
    "Šifrirana datoteka bit će sačuvana", // Str::DefaultCipherModeText_FirstLine
    "kao znakovi koji se mogu štampati", // Str::DefaultCipherModeText_SecondLine
    "Šifrirana datoteka bit će sačuvana u", // Str::OpenSSLCipherModeText_FirstLine
    "binarnom formatu, kompatibilnom s OpenSSL-om", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 iteracije:", // Str::PBKDF2IterationsText
    // Errors
    "Greška: neispravni parametri", // Str::WrongParamsText
    "Primljena vrijednost", // Str::InputValueText
    "Primljena putanja", // Str::InputPathText
    "Primljenu vrijednost nije bilo moguće pretvoriti u broj veći od 0 ili jednak 0", // Str::WrongNumberValueMessage
    "Primljena putanja ne odgovara nijednoj postojećoj datoteci", // Str::WrongPathValueMessage
    "Unesena opcija nije prepoznata kao važeći parametar", // Str::InvalidOptionMessage
    "Unesena opcija", // Str::EnteredOptionText
    "Nepoznat izuzetak", // Str::UnknownExceptionText
    "Pokretanje GLFW-a nije uspjelo", // Str::GLFWErrorMessage
    "Pokretanje GLAD-a nije uspjelo", // Str::GLADErrorMessage
    "Greška: Datoteku nije moguće otvoriti za čitanje", // Str::ReadFileErrorMessage
    "Greška pri čitanju sadržaja datoteke", // Str::ErrorWhileReadingMessage
    "Greška: Datoteku nije moguće otvoriti za pisanje", // Str::WriteFileErrorMessage
    "Greška: Heksadecimalni niz mora imati paran broj znakova", // Str::HexStringErrorMessage
    "Greška: Nevažeći heksadecimalni znak u nizu", // Str::InvalidHexCharacterErrorMessage
    "Greška: Datoteku nije moguće sačuvati", // Str::SaveFileErrorMessage
    "Greška: Datoteku nije moguće učitati", // Str::LoadFileErrorMessage
    "Greška: Nevažeći format datoteke (očekivano 5 polja: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Greška: Broj iteracija premašuje utvrđeni maksimum (10.000.000)", // Str::MaxIterationsErrorMessage
    "Greška: Provjera integriteta nije uspjela, netačna lozinka ili oštećena/izmijenjena datoteka", // Str::IntegrityCheckErrorMessage
    "Greška: Lozinka ne može biti prazna", // Str::EmptyPasswordErrorMessage
    "Greška: Putanja odredišne datoteke je folder", // Str::OutputFileIsDirectoryErrorMessage
    "Greška: Putanja izvorne datoteke je folder", // Str::InputFileIsDirectoryErrorMessage
    "Greška: Putanja odredišne datoteke ne može biti prazna", // Str::EmptyOutputFilePathErrorMessage
    "Greška: Putanja izvorne datoteke ne može biti prazna", // Str::EmptyInputFilePathErrorMessage
    "Greška: Izvorna datoteka ne postoji", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Jezik: Bosanski", // Str::LanguageLabel
    "Lozinka", // Str::PasswordLabel
    "Dužina lozinke", // Str::PasswordLenghtLabel
    "Datoteka", // Str::FileLabel
    "Datoteka", // Str::TheFileLabel
    "Putanja", // Str::PathLabel
    "Putanja ulazne datoteke", // Str::InputFilePathLabel
    "Putanja izlazne datoteke", // Str::OutputFilePathLabel
    "Zamijeni putanje", // Str::SwapPathsLabel
    "bit će zamijenjena", // Str::WillBeOverwrittenLabel
    "Šifriranje...", // Str::EncryptingText
    "Dešifriranje...", // Str::DecryptingText
    "Šifriraj", // Str::EncryptText
    "Dešifriraj", // Str::DecryptText
    "Datoteka je uspješno šifrirana", // Str::FileEncryptedMessage
    "Datoteka je uspješno dešifrirana", // Str::FileDecryptedMessage
    "Upozorenje!", // Str::WarningTitle
    "Jeste li sigurni?", // Str::AreYouSureTitle
    "Postavke", // Str::SettingsTitle
    "Generator lozinki", // Str::GeneratePasswordTitle
    "Odaberite jezik", // Str::SelectLanguageTitle
    "Da", // Str::YesLabel
    "Ne", // Str::NoLabel
    "U redu", // Str::OkLabel
    "Izlazni format", // Str::OutFormatLabel
    "Postavke interfejsa", // Str::InterfaceSettingsLabel
    "Veličina", // Str::InterfaceSizeLabel
    "Način rada", // Str::ModeLabel
    "Normalan", // Str::NormalModeLabel
    "Običan tekst", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Boja", // Str::InterfaceColorLabel
    "Zadano (običan tekst)", // Str::DefaultLabel
    "OpenSSL (binarni)", // Str::OpenSSLLabel
    "Koristi ovu lozinku", // Str::UsePasswordLabel
    "Kopiraj", // Str::CopyLabel
    "Ctrl + lijevi klik za dobijanje SHA256", // Str::GetSHA256Text
    // Themes
    "Svijetla", // Str::LightThemeName
    "Tamna", // Str::DarkThemeName
    // Colors
    "Plava", // Str::BlueName
    "Cijan", // Str::CyanName
    "Zelena", // Str::GreenName
    "Limeta", // Str::LimeName
    "Žuta", // Str::YellowName
    "Smeđa", // Str::BrownName
    "Narandžasta", // Str::OrangeName
    "Crvena", // Str::RedName
    "Roza", // Str::PinkName
    "Ljubičasta", // Str::PurpleName
    "Siva", // Str::GreyName
    "Bijela", // Str::WhiteName
    "Crna", // Str::BlackName

};
static_assert(sizeof(textosBS) / sizeof(textosBS[0]) == N,
    "Faltan o sobran textos en bosnio: revisa que coincidan con Str::Count.");

// Galego (gl)
constexpr const char* textosGL[] = {

    
    
    // Info
    "Preme Enter para saír...", // Str::ExitInfoMessage
    "Activar só se o contido", // Str::PlainTextModeMessage_FirstLine
    "do ficheiro é texto simple", // Str::PlainTextModeMessage_SecondLine
    "O ficheiro cifrado gardarase", // Str::DefaultCipherModeText_FirstLine
    "como caracteres imprimibles", // Str::DefaultCipherModeText_SecondLine
    "O ficheiro cifrado gardarase en", // Str::OpenSSLCipherModeText_FirstLine
    "formato binario, compatible con OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iteracións PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Erro: parámetros incorrectos", // Str::WrongParamsText
    "Valor recibido", // Str::InputValueText
    "Ruta recibida", // Str::InputPathText
    "Non se puido converter o valor recibido nun número maior ou igual a 0", // Str::WrongNumberValueMessage
    "A ruta recibida non corresponde a ningún ficheiro existente", // Str::WrongPathValueMessage
    "A opción introducida non se recoñece como un parámetro válido", // Str::InvalidOptionMessage
    "Opción introducida", // Str::EnteredOptionText
    "Excepción descoñecida", // Str::UnknownExceptionText
    "Erro ao iniciar GLFW", // Str::GLFWErrorMessage
    "Erro ao iniciar GLAD", // Str::GLADErrorMessage
    "Erro: Non se puido abrir o ficheiro para lectura", // Str::ReadFileErrorMessage
    "Erro ao ler o contido do ficheiro", // Str::ErrorWhileReadingMessage
    "Erro: Non se puido abrir o ficheiro para escritura", // Str::WriteFileErrorMessage
    "Erro: A cadea hexadecimal debe ter un número par de caracteres", // Str::HexStringErrorMessage
    "Erro: Carácter hexadecimal non válido na cadea", // Str::InvalidHexCharacterErrorMessage
    "Erro: Non se puido gardar o ficheiro", // Str::SaveFileErrorMessage
    "Erro: Non se puido cargar o ficheiro", // Str::LoadFileErrorMessage
    "Erro: Formato de ficheiro non válido (agardábanse 5 campos: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Erro: O número de iteracións supera o máximo establecido (10.000.000)", // Str::MaxIterationsErrorMessage
    "Erro: Fallou a verificación de integridade, contrasinal incorrecto ou ficheiro danado/manipulado", // Str::IntegrityCheckErrorMessage
    "Erro: O contrasinal non pode estar baleiro", // Str::EmptyPasswordErrorMessage
    "Erro: A ruta do ficheiro de destino é un directorio", // Str::OutputFileIsDirectoryErrorMessage
    "Erro: A ruta do ficheiro de orixe é un directorio", // Str::InputFileIsDirectoryErrorMessage
    "Erro: A ruta do ficheiro de destino non pode estar baleira", // Str::EmptyOutputFilePathErrorMessage
    "Erro: A ruta do ficheiro de orixe non pode estar baleira", // Str::EmptyInputFilePathErrorMessage
    "Erro: O ficheiro de orixe non existe", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Idioma: Galego", // Str::LanguageLabel
    "Contrasinal", // Str::PasswordLabel
    "Lonxitude do contrasinal", // Str::PasswordLenghtLabel
    "Ficheiro", // Str::FileLabel
    "O ficheiro", // Str::TheFileLabel
    "Ruta", // Str::PathLabel
    "Ruta de entrada", // Str::InputFilePathLabel
    "Ruta de saída", // Str::OutputFilePathLabel
    "Intercambiar rutas", // Str::SwapPathsLabel
    "será sobrescrito", // Str::WillBeOverwrittenLabel
    "Cifrando...", // Str::EncryptingText
    "Descifrando...", // Str::DecryptingText
    "Cifrar", // Str::EncryptText
    "Descifrar", // Str::DecryptText
    "Ficheiro cifrado correctamente", // Str::FileEncryptedMessage
    "Ficheiro descifrado correctamente", // Str::FileDecryptedMessage
    "Atención!", // Str::WarningTitle
    "Estás seguro?", // Str::AreYouSureTitle
    "Axustes", // Str::SettingsTitle
    "Xerador de contrasinais", // Str::GeneratePasswordTitle
    "Seleccionar idioma", // Str::SelectLanguageTitle
    "Si", // Str::YesLabel
    "Non", // Str::NoLabel
    "Aceptar", // Str::OkLabel
    "Formato de saída", // Str::OutFormatLabel
    "Axustes da interface", // Str::InterfaceSettingsLabel
    "Tamaño", // Str::InterfaceSizeLabel
    "Modo", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Texto simple", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Cor", // Str::InterfaceColorLabel
    "Predeterminado (texto simple)", // Str::DefaultLabel
    "OpenSSL (binario)", // Str::OpenSSLLabel
    "Usar este contrasinal", // Str::UsePasswordLabel
    "Copiar", // Str::CopyLabel
    "Ctrl + clic esquerdo para obter o SHA256", // Str::GetSHA256Text
    // Themes
    "Claro", // Str::LightThemeName
    "Escuro", // Str::DarkThemeName
    // Colors
    "Azul", // Str::BlueName
    "Ciano", // Str::CyanName
    "Verde", // Str::GreenName
    "Lima", // Str::LimeName
    "Amarelo", // Str::YellowName
    "Marrón", // Str::BrownName
    "Laranxa", // Str::OrangeName
    "Vermello", // Str::RedName
    "Rosa", // Str::PinkName
    "Morado", // Str::PurpleName
    "Gris", // Str::GreyName
    "Branco", // Str::WhiteName
    "Negro", // Str::BlackName

};
static_assert(sizeof(textosGL) / sizeof(textosGL[0]) == N,
    "Faltan o sobran textos en gallego: revisa que coincidan con Str::Count.");

// Lietuvių (lt)
constexpr const char* textosLT[] = {

    
    
    // Info
    "Paspauskite Enter, kad išeitumėte...", // Str::ExitInfoMessage
    "Įjunkite tik tuo atveju, jei failo", // Str::PlainTextModeMessage_FirstLine
    "turinys yra paprastas tekstas", // Str::PlainTextModeMessage_SecondLine
    "Užšifruotas failas bus įrašytas", // Str::DefaultCipherModeText_FirstLine
    "kaip spausdinami simboliai", // Str::DefaultCipherModeText_SecondLine
    "Užšifruotas failas bus įrašytas", // Str::OpenSSLCipherModeText_FirstLine
    "dvejetainiu formatu, suderinamu su OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 iteracijos:", // Str::PBKDF2IterationsText
    // Errors
    "Klaida: neteisingi parametrai", // Str::WrongParamsText
    "Gauta reikšmė", // Str::InputValueText
    "Gautas kelias", // Str::InputPathText
    "Gautos reikšmės nepavyko konvertuoti į skaičių, didesnį arba lygų 0", // Str::WrongNumberValueMessage
    "Gautas kelias neatitinka jokio esamo failo", // Str::WrongPathValueMessage
    "Įvesta parinktis neatpažįstama kaip tinkamas parametras", // Str::InvalidOptionMessage
    "Įvesta parinktis", // Str::EnteredOptionText
    "Nežinoma išimtis", // Str::UnknownExceptionText
    "Nepavyko inicijuoti GLFW", // Str::GLFWErrorMessage
    "Nepavyko inicijuoti GLAD", // Str::GLADErrorMessage
    "Klaida: Nepavyko atidaryti failo skaitymui", // Str::ReadFileErrorMessage
    "Klaida skaitant failo turinį", // Str::ErrorWhileReadingMessage
    "Klaida: Nepavyko atidaryti failo rašymui", // Str::WriteFileErrorMessage
    "Klaida: Šešioliktainėje eilutėje turi būti lyginis simbolių skaičius", // Str::HexStringErrorMessage
    "Klaida: Netinkamas šešioliktainis simbolis eilutėje", // Str::InvalidHexCharacterErrorMessage
    "Klaida: Nepavyko įrašyti failo", // Str::SaveFileErrorMessage
    "Klaida: Nepavyko įkelti failo", // Str::LoadFileErrorMessage
    "Klaida: Netinkamas failo formatas (tikėtasi 5 laukų: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Klaida: Iteracijų skaičius viršija nustatytą maksimumą (10 000 000)", // Str::MaxIterationsErrorMessage
    "Klaida: Vientisumo patikra nepavyko, neteisingas slaptažodis arba sugadintas/pakeistas failas", // Str::IntegrityCheckErrorMessage
    "Klaida: Slaptažodis negali būti tuščias", // Str::EmptyPasswordErrorMessage
    "Klaida: Paskirties failo kelias yra aplankas", // Str::OutputFileIsDirectoryErrorMessage
    "Klaida: Šaltinio failo kelias yra aplankas", // Str::InputFileIsDirectoryErrorMessage
    "Klaida: Paskirties failo kelias negali būti tuščias", // Str::EmptyOutputFilePathErrorMessage
    "Klaida: Šaltinio failo kelias negali būti tuščias", // Str::EmptyInputFilePathErrorMessage
    "Klaida: Šaltinio failas neegzistuoja", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Kalba: Lietuvių", // Str::LanguageLabel
    "Slaptažodis", // Str::PasswordLabel
    "Slaptažodžio ilgis", // Str::PasswordLenghtLabel
    "Failas", // Str::FileLabel
    "Failas", // Str::TheFileLabel
    "Kelias", // Str::PathLabel
    "Įvesties failo kelias", // Str::InputFilePathLabel
    "Išvesties failo kelias", // Str::OutputFilePathLabel
    "Sukeisti kelius", // Str::SwapPathsLabel
    "bus perrašytas", // Str::WillBeOverwrittenLabel
    "Šifruojama...", // Str::EncryptingText
    "Iššifruojama...", // Str::DecryptingText
    "Užšifruoti", // Str::EncryptText
    "Iššifruoti", // Str::DecryptText
    "Failas sėkmingai užšifruotas", // Str::FileEncryptedMessage
    "Failas sėkmingai iššifruotas", // Str::FileDecryptedMessage
    "Įspėjimas!", // Str::WarningTitle
    "Ar tikrai?", // Str::AreYouSureTitle
    "Nustatymai", // Str::SettingsTitle
    "Slaptažodžių generatorius", // Str::GeneratePasswordTitle
    "Pasirinkite kalbą", // Str::SelectLanguageTitle
    "Taip", // Str::YesLabel
    "Ne", // Str::NoLabel
    "Gerai", // Str::OkLabel
    "Išvesties formatas", // Str::OutFormatLabel
    "Sąsajos nustatymai", // Str::InterfaceSettingsLabel
    "Dydis", // Str::InterfaceSizeLabel
    "Režimas", // Str::ModeLabel
    "Įprastas", // Str::NormalModeLabel
    "Paprastas tekstas", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Spalva", // Str::InterfaceColorLabel
    "Numatytasis (paprastas tekstas)", // Str::DefaultLabel
    "OpenSSL (dvejetainis)", // Str::OpenSSLLabel
    "Naudoti šį slaptažodį", // Str::UsePasswordLabel
    "Kopijuoti", // Str::CopyLabel
    "Ctrl + kairysis spustelėjimas SHA256 gauti", // Str::GetSHA256Text
    // Themes
    "Šviesi", // Str::LightThemeName
    "Tamsi", // Str::DarkThemeName
    // Colors
    "Mėlyna", // Str::BlueName
    "Žydra", // Str::CyanName
    "Žalia", // Str::GreenName
    "Laimo žalia", // Str::LimeName
    "Geltona", // Str::YellowName
    "Ruda", // Str::BrownName
    "Oranžinė", // Str::OrangeName
    "Raudona", // Str::RedName
    "Rožinė", // Str::PinkName
    "Violetinė", // Str::PurpleName
    "Pilka", // Str::GreyName
    "Balta", // Str::WhiteName
    "Juoda", // Str::BlackName

};
static_assert(sizeof(textosLT) / sizeof(textosLT[0]) == N,
    "Faltan o sobran textos en lituano: revisa que coincidan con Str::Count.");

// Slovenščina (sl)
constexpr const char* textosSL[] = {

    
    
    // Info
    "Pritisnite Enter za izhod...", // Str::ExitInfoMessage
    "Omogočite le, če je vsebina", // Str::PlainTextModeMessage_FirstLine
    "datoteke navadno besedilo", // Str::PlainTextModeMessage_SecondLine
    "Šifrirana datoteka bo shranjena", // Str::DefaultCipherModeText_FirstLine
    "kot natisljivi znaki", // Str::DefaultCipherModeText_SecondLine
    "Šifrirana datoteka bo shranjena", // Str::OpenSSLCipherModeText_FirstLine
    "v binarni obliki, združljivi z OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iteracije PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Napaka: napačni parametri", // Str::WrongParamsText
    "Prejeta vrednost", // Str::InputValueText
    "Prejeta pot", // Str::InputPathText
    "Prejete vrednosti ni bilo mogoče pretvoriti v število, večje ali enako 0", // Str::WrongNumberValueMessage
    "Prejeta pot se ne ujema z nobeno obstoječo datoteko", // Str::WrongPathValueMessage
    "Vnesena možnost ni prepoznana kot veljaven parameter", // Str::InvalidOptionMessage
    "Vnesena možnost", // Str::EnteredOptionText
    "Neznana izjema", // Str::UnknownExceptionText
    "Inicializacija GLFW ni uspela", // Str::GLFWErrorMessage
    "Inicializacija GLAD ni uspela", // Str::GLADErrorMessage
    "Napaka: Datoteke ni bilo mogoče odpreti za branje", // Str::ReadFileErrorMessage
    "Napaka pri branju vsebine datoteke", // Str::ErrorWhileReadingMessage
    "Napaka: Datoteke ni bilo mogoče odpreti za pisanje", // Str::WriteFileErrorMessage
    "Napaka: Šestnajstiški niz mora imeti sodo število znakov", // Str::HexStringErrorMessage
    "Napaka: Neveljaven šestnajstiški znak v nizu", // Str::InvalidHexCharacterErrorMessage
    "Napaka: Datoteke ni bilo mogoče shraniti", // Str::SaveFileErrorMessage
    "Napaka: Datoteke ni bilo mogoče naložiti", // Str::LoadFileErrorMessage
    "Napaka: Neveljavna oblika datoteke (pričakovanih 5 polj: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Napaka: Število iteracij presega določeni maksimum (10.000.000)", // Str::MaxIterationsErrorMessage
    "Napaka: Preverjanje celovitosti ni uspelo, napačno geslo ali poškodovana/spremenjena datoteka", // Str::IntegrityCheckErrorMessage
    "Napaka: Geslo ne sme biti prazno", // Str::EmptyPasswordErrorMessage
    "Napaka: Pot ciljne datoteke je mapa", // Str::OutputFileIsDirectoryErrorMessage
    "Napaka: Pot izvorne datoteke je mapa", // Str::InputFileIsDirectoryErrorMessage
    "Napaka: Pot ciljne datoteke ne sme biti prazna", // Str::EmptyOutputFilePathErrorMessage
    "Napaka: Pot izvorne datoteke ne sme biti prazna", // Str::EmptyInputFilePathErrorMessage
    "Napaka: Izvorna datoteka ne obstaja", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Jezik: Slovenščina", // Str::LanguageLabel
    "Geslo", // Str::PasswordLabel
    "Dolžina gesla", // Str::PasswordLenghtLabel
    "Datoteka", // Str::FileLabel
    "Datoteka", // Str::TheFileLabel
    "Pot", // Str::PathLabel
    "Pot vhodne datoteke", // Str::InputFilePathLabel
    "Pot izhodne datoteke", // Str::OutputFilePathLabel
    "Zamenjaj poti", // Str::SwapPathsLabel
    "bo prepisana", // Str::WillBeOverwrittenLabel
    "Šifriranje...", // Str::EncryptingText
    "Dešifriranje...", // Str::DecryptingText
    "Šifriraj", // Str::EncryptText
    "Dešifriraj", // Str::DecryptText
    "Datoteka je bila uspešno šifrirana", // Str::FileEncryptedMessage
    "Datoteka je bila uspešno dešifrirana", // Str::FileDecryptedMessage
    "Opozorilo!", // Str::WarningTitle
    "Ali ste prepričani?", // Str::AreYouSureTitle
    "Nastavitve", // Str::SettingsTitle
    "Generator gesel", // Str::GeneratePasswordTitle
    "Izberite jezik", // Str::SelectLanguageTitle
    "Da", // Str::YesLabel
    "Ne", // Str::NoLabel
    "V redu", // Str::OkLabel
    "Izhodna oblika", // Str::OutFormatLabel
    "Nastavitve vmesnika", // Str::InterfaceSettingsLabel
    "Velikost", // Str::InterfaceSizeLabel
    "Način", // Str::ModeLabel
    "Običajni", // Str::NormalModeLabel
    "Navadno besedilo", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Barva", // Str::InterfaceColorLabel
    "Privzeto (navadno besedilo)", // Str::DefaultLabel
    "OpenSSL (binarno)", // Str::OpenSSLLabel
    "Uporabi to geslo", // Str::UsePasswordLabel
    "Kopiraj", // Str::CopyLabel
    "Ctrl + levi klik za pridobitev SHA256", // Str::GetSHA256Text
    // Themes
    "Svetla", // Str::LightThemeName
    "Temna", // Str::DarkThemeName
    // Colors
    "Modra", // Str::BlueName
    "Cian", // Str::CyanName
    "Zelena", // Str::GreenName
    "Limeta", // Str::LimeName
    "Rumena", // Str::YellowName
    "Rjava", // Str::BrownName
    "Oranžna", // Str::OrangeName
    "Rdeča", // Str::RedName
    "Rožnata", // Str::PinkName
    "Vijolična", // Str::PurpleName
    "Siva", // Str::GreyName
    "Bela", // Str::WhiteName
    "Črna", // Str::BlackName

};
static_assert(sizeof(textosSL) / sizeof(textosSL[0]) == N,
    "Faltan o sobran textos en esloveno: revisa que coincidan con Str::Count.");

// Latviešu (lv)
constexpr const char* textosLV[] = {

    
    
    // Info
    "Nospiediet Enter, lai izietu...", // Str::ExitInfoMessage
    "Iespējojiet tikai tad, ja faila", // Str::PlainTextModeMessage_FirstLine
    "saturs ir vienkāršs teksts", // Str::PlainTextModeMessage_SecondLine
    "Šifrētais fails tiks saglabāts", // Str::DefaultCipherModeText_FirstLine
    "kā drukājamas rakstzīmes", // Str::DefaultCipherModeText_SecondLine
    "Šifrētais fails tiks saglabāts", // Str::OpenSSLCipherModeText_FirstLine
    "binārā formātā, saderīgā ar OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 iterācijas:", // Str::PBKDF2IterationsText
    // Errors
    "Kļūda: nepareizi parametri", // Str::WrongParamsText
    "Saņemtā vērtība", // Str::InputValueText
    "Saņemtais ceļš", // Str::InputPathText
    "Saņemto vērtību neizdevās pārvērst skaitlī, kas ir lielāks par 0 vai vienāds ar 0", // Str::WrongNumberValueMessage
    "Saņemtais ceļš neatbilst nevienam esošam failam", // Str::WrongPathValueMessage
    "Ievadītā opcija netiek atpazīta kā derīgs parametrs", // Str::InvalidOptionMessage
    "Ievadītā opcija", // Str::EnteredOptionText
    "Nezināms izņēmums", // Str::UnknownExceptionText
    "Neizdevās inicializēt GLFW", // Str::GLFWErrorMessage
    "Neizdevās inicializēt GLAD", // Str::GLADErrorMessage
    "Kļūda: Neizdevās atvērt failu lasīšanai", // Str::ReadFileErrorMessage
    "Kļūda, lasot faila saturu", // Str::ErrorWhileReadingMessage
    "Kļūda: Neizdevās atvērt failu rakstīšanai", // Str::WriteFileErrorMessage
    "Kļūda: Heksadecimālajā virknē jābūt pāra skaitam rakstzīmju", // Str::HexStringErrorMessage
    "Kļūda: Nederīga heksadecimālā rakstzīme virknē", // Str::InvalidHexCharacterErrorMessage
    "Kļūda: Neizdevās saglabāt failu", // Str::SaveFileErrorMessage
    "Kļūda: Neizdevās ielādēt failu", // Str::LoadFileErrorMessage
    "Kļūda: Nederīgs faila formāts (tika gaidīti 5 lauki: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Kļūda: Iterāciju skaits pārsniedz noteikto maksimumu (10 000 000)", // Str::MaxIterationsErrorMessage
    "Kļūda: Integritātes pārbaude neizdevās, nepareiza parole vai bojāts/mainīts fails", // Str::IntegrityCheckErrorMessage
    "Kļūda: Parole nedrīkst būt tukša", // Str::EmptyPasswordErrorMessage
    "Kļūda: Mērķa faila ceļš ir mape", // Str::OutputFileIsDirectoryErrorMessage
    "Kļūda: Avota faila ceļš ir mape", // Str::InputFileIsDirectoryErrorMessage
    "Kļūda: Mērķa faila ceļš nedrīkst būt tukšs", // Str::EmptyOutputFilePathErrorMessage
    "Kļūda: Avota faila ceļš nedrīkst būt tukšs", // Str::EmptyInputFilePathErrorMessage
    "Kļūda: Avota fails neeksistē", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Valoda: Latviešu", // Str::LanguageLabel
    "Parole", // Str::PasswordLabel
    "Paroles garums", // Str::PasswordLenghtLabel
    "Fails", // Str::FileLabel
    "Fails", // Str::TheFileLabel
    "Ceļš", // Str::PathLabel
    "Ievades faila ceļš", // Str::InputFilePathLabel
    "Izvades faila ceļš", // Str::OutputFilePathLabel
    "Apmainīt ceļus", // Str::SwapPathsLabel
    "tiks pārrakstīts", // Str::WillBeOverwrittenLabel
    "Šifrē...", // Str::EncryptingText
    "Atšifrē...", // Str::DecryptingText
    "Šifrēt", // Str::EncryptText
    "Atšifrēt", // Str::DecryptText
    "Fails veiksmīgi šifrēts", // Str::FileEncryptedMessage
    "Fails veiksmīgi atšifrēts", // Str::FileDecryptedMessage
    "Brīdinājums!", // Str::WarningTitle
    "Vai esat pārliecināts?", // Str::AreYouSureTitle
    "Iestatījumi", // Str::SettingsTitle
    "Paroļu ģenerators", // Str::GeneratePasswordTitle
    "Izvēlieties valodu", // Str::SelectLanguageTitle
    "Jā", // Str::YesLabel
    "Nē", // Str::NoLabel
    "Labi", // Str::OkLabel
    "Izvades formāts", // Str::OutFormatLabel
    "Saskarnes iestatījumi", // Str::InterfaceSettingsLabel
    "Izmērs", // Str::InterfaceSizeLabel
    "Režīms", // Str::ModeLabel
    "Parasts", // Str::NormalModeLabel
    "Vienkāršs teksts", // Str::PlaintextModeLabel
    "Motīvs", // Str::InterfaceThemeLabel
    "Krāsa", // Str::InterfaceColorLabel
    "Noklusējums (vienkāršs teksts)", // Str::DefaultLabel
    "OpenSSL (binārs)", // Str::OpenSSLLabel
    "Izmantot šo paroli", // Str::UsePasswordLabel
    "Kopēt", // Str::CopyLabel
    "Ctrl + kreisais klikšķis, lai iegūtu SHA256", // Str::GetSHA256Text
    // Themes
    "Gaišs", // Str::LightThemeName
    "Tumšs", // Str::DarkThemeName
    // Colors
    "Zils", // Str::BlueName
    "Ciāns", // Str::CyanName
    "Zaļš", // Str::GreenName
    "Laima zaļš", // Str::LimeName
    "Dzeltens", // Str::YellowName
    "Brūns", // Str::BrownName
    "Oranžs", // Str::OrangeName
    "Sarkans", // Str::RedName
    "Rozā", // Str::PinkName
    "Violets", // Str::PurpleName
    "Pelēks", // Str::GreyName
    "Balts", // Str::WhiteName
    "Melns", // Str::BlackName

};
static_assert(sizeof(textosLV) / sizeof(textosLV[0]) == N,
    "Faltan o sobran textos en leton: revisa que coincidan con Str::Count.");

// Македонски (mk)
constexpr const char* textosMK[] = {

    
    
    // Info
    "Притиснете Enter за излез...", // Str::ExitInfoMessage
    "Овозможете само ако содржината", // Str::PlainTextModeMessage_FirstLine
    "на датотеката е обичен текст", // Str::PlainTextModeMessage_SecondLine
    "Шифрираната датотека ќе биде зачувана", // Str::DefaultCipherModeText_FirstLine
    "како знаци што може да се печатат", // Str::DefaultCipherModeText_SecondLine
    "Шифрираната датотека ќе биде зачувана", // Str::OpenSSLCipherModeText_FirstLine
    "во бинарен формат, компатибилен со OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 итерации:", // Str::PBKDF2IterationsText
    // Errors
    "Грешка: неточни параметри", // Str::WrongParamsText
    "Примена вредност", // Str::InputValueText
    "Примена патека", // Str::InputPathText
    "Примената вредност не можеше да се претвори во број поголем или еднаков на 0", // Str::WrongNumberValueMessage
    "Примената патека не одговара на ниедна постоечка датотека", // Str::WrongPathValueMessage
    "Внесената опција не е препознаена како валиден параметар", // Str::InvalidOptionMessage
    "Внесена опција", // Str::EnteredOptionText
    "Непознат исклучок", // Str::UnknownExceptionText
    "Иницијализацијата на GLFW не успеа", // Str::GLFWErrorMessage
    "Иницијализацијата на GLAD не успеа", // Str::GLADErrorMessage
    "Грешка: Датотеката не може да се отвори за читање", // Str::ReadFileErrorMessage
    "Грешка при читање на содржината на датотеката", // Str::ErrorWhileReadingMessage
    "Грешка: Датотеката не може да се отвори за запишување", // Str::WriteFileErrorMessage
    "Грешка: Хексадецималната низа мора да има парен број знаци", // Str::HexStringErrorMessage
    "Грешка: Невалиден хексадецимален знак во низата", // Str::InvalidHexCharacterErrorMessage
    "Грешка: Датотеката не може да се зачува", // Str::SaveFileErrorMessage
    "Грешка: Датотеката не може да се вчита", // Str::LoadFileErrorMessage
    "Грешка: Невалиден формат на датотека (се очекуваа 5 полиња: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Грешка: Бројот на итерации го надминува утврдениот максимум (10.000.000)", // Str::MaxIterationsErrorMessage
    "Грешка: Проверката на интегритетот не успеа, неточна лозинка или оштетена/изменета датотека", // Str::IntegrityCheckErrorMessage
    "Грешка: Лозинката не може да биде празна", // Str::EmptyPasswordErrorMessage
    "Грешка: Патеката на одредишната датотека е папка", // Str::OutputFileIsDirectoryErrorMessage
    "Грешка: Патеката на изворната датотека е папка", // Str::InputFileIsDirectoryErrorMessage
    "Грешка: Патеката на одредишната датотека не може да биде празна", // Str::EmptyOutputFilePathErrorMessage
    "Грешка: Патеката на изворната датотека не може да биде празна", // Str::EmptyInputFilePathErrorMessage
    "Грешка: Изворната датотека не постои", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Јазик: Македонски", // Str::LanguageLabel
    "Лозинка", // Str::PasswordLabel
    "Должина на лозинката", // Str::PasswordLenghtLabel
    "Датотека", // Str::FileLabel
    "Датотеката", // Str::TheFileLabel
    "Патека", // Str::PathLabel
    "Патека на влезната датотека", // Str::InputFilePathLabel
    "Патека на излезната датотека", // Str::OutputFilePathLabel
    "Замени ги патеките", // Str::SwapPathsLabel
    "ќе биде презапишана", // Str::WillBeOverwrittenLabel
    "Шифрирање...", // Str::EncryptingText
    "Дешифрирање...", // Str::DecryptingText
    "Шифрирај", // Str::EncryptText
    "Дешифрирај", // Str::DecryptText
    "Датотеката е успешно шифрирана", // Str::FileEncryptedMessage
    "Датотеката е успешно дешифрирана", // Str::FileDecryptedMessage
    "Предупредување!", // Str::WarningTitle
    "Дали сте сигурни?", // Str::AreYouSureTitle
    "Поставки", // Str::SettingsTitle
    "Генератор на лозинки", // Str::GeneratePasswordTitle
    "Изберете јазик", // Str::SelectLanguageTitle
    "Да", // Str::YesLabel
    "Не", // Str::NoLabel
    "Во ред", // Str::OkLabel
    "Излезен формат", // Str::OutFormatLabel
    "Поставки на интерфејсот", // Str::InterfaceSettingsLabel
    "Големина", // Str::InterfaceSizeLabel
    "Режим", // Str::ModeLabel
    "Нормален", // Str::NormalModeLabel
    "Обичен текст", // Str::PlaintextModeLabel
    "Тема", // Str::InterfaceThemeLabel
    "Боја", // Str::InterfaceColorLabel
    "Стандардно (обичен текст)", // Str::DefaultLabel
    "OpenSSL (бинарен)", // Str::OpenSSLLabel
    "Користи ја оваа лозинка", // Str::UsePasswordLabel
    "Копирај", // Str::CopyLabel
    "Ctrl + лев клик за добивање SHA256", // Str::GetSHA256Text
    // Themes
    "Светла", // Str::LightThemeName
    "Темна", // Str::DarkThemeName
    // Colors
    "Сина", // Str::BlueName
    "Цијан", // Str::CyanName
    "Зелена", // Str::GreenName
    "Лимета", // Str::LimeName
    "Жолта", // Str::YellowName
    "Кафеава", // Str::BrownName
    "Портокалова", // Str::OrangeName
    "Црвена", // Str::RedName
    "Розова", // Str::PinkName
    "Виолетова", // Str::PurpleName
    "Сива", // Str::GreyName
    "Бела", // Str::WhiteName
    "Црна", // Str::BlackName

};
static_assert(sizeof(textosMK) / sizeof(textosMK[0]) == N,
    "Faltan o sobran textos en macedonio: revisa que coincidan con Str::Count.");

// Gaeilge (ga)
constexpr const char* textosGA[] = {

    
    
    // Info
    "Brúigh Enter chun scoir...", // Str::ExitInfoMessage
    "Cumasaigh é seo ach amháin má tá", // Str::PlainTextModeMessage_FirstLine
    "gnáth-théacs in ábhar an chomhaid", // Str::PlainTextModeMessage_SecondLine
    "Sábhálfar an comhad criptithe", // Str::DefaultCipherModeText_FirstLine
    "mar charachtair inphriontáilte", // Str::DefaultCipherModeText_SecondLine
    "Sábhálfar an comhad criptithe i bhformáid", // Str::OpenSSLCipherModeText_FirstLine
    "dhénártha, comhoiriúnach le OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Atriallta PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Earráid: paraiméadair mhíchearta", // Str::WrongParamsText
    "Luach faighte", // Str::InputValueText
    "Conair faighte", // Str::InputPathText
    "Níorbh fhéidir an luach a fuarthas a thiontú go huimhir atá níos mó ná 0 nó cothrom le 0", // Str::WrongNumberValueMessage
    "Ní fhreagraíonn an chonair a fuarthas d'aon chomhad atá ann", // Str::WrongPathValueMessage
    "Ní aithnítear an rogha a iontráladh mar pharaiméadar bailí", // Str::InvalidOptionMessage
    "Rogha a iontráladh", // Str::EnteredOptionText
    "Eisceacht anaithnid", // Str::UnknownExceptionText
    "Theip ar thúsú GLFW", // Str::GLFWErrorMessage
    "Theip ar thúsú GLAD", // Str::GLADErrorMessage
    "Earráid: Níorbh fhéidir an comhad a oscailt le léamh", // Str::ReadFileErrorMessage
    "Earráid agus ábhar an chomhaid á léamh", // Str::ErrorWhileReadingMessage
    "Earráid: Níorbh fhéidir an comhad a oscailt le scríobh", // Str::WriteFileErrorMessage
    "Earráid: Caithfidh líon cothrom carachtar a bheith sa teaghrán heicsidheachúil", // Str::HexStringErrorMessage
    "Earráid: Carachtar heicsidheachúil neamhbhailí sa teaghrán", // Str::InvalidHexCharacterErrorMessage
    "Earráid: Níorbh fhéidir an comhad a shábháil", // Str::SaveFileErrorMessage
    "Earráid: Níorbh fhéidir an comhad a lódáil", // Str::LoadFileErrorMessage
    "Earráid: Formáid comhaid neamhbhailí (bhíothas ag súil le 5 réimse: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Earráid: Sáraíonn líon na n-atriallta an t-uasmhéid socraithe (10,000,000)", // Str::MaxIterationsErrorMessage
    "Earráid: Theip ar fhíorú sláine, pasfhocal mícheart nó comhad truaillithe/athraithe", // Str::IntegrityCheckErrorMessage
    "Earráid: Ní féidir leis an bpasfhocal a bheith folamh", // Str::EmptyPasswordErrorMessage
    "Earráid: Is fillteán í conair an chomhaid sprice", // Str::OutputFileIsDirectoryErrorMessage
    "Earráid: Is fillteán í conair an chomhaid foinse", // Str::InputFileIsDirectoryErrorMessage
    "Earráid: Ní féidir le conair an chomhaid sprice a bheith folamh", // Str::EmptyOutputFilePathErrorMessage
    "Earráid: Ní féidir le conair an chomhaid foinse a bheith folamh", // Str::EmptyInputFilePathErrorMessage
    "Earráid: Níl an comhad foinse ann", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Teanga: Gaeilge", // Str::LanguageLabel
    "Pasfhocal", // Str::PasswordLabel
    "Fad an phasfhocail", // Str::PasswordLenghtLabel
    "Comhad", // Str::FileLabel
    "An comhad", // Str::TheFileLabel
    "Conair", // Str::PathLabel
    "Conair an chomhaid ionchurtha", // Str::InputFilePathLabel
    "Conair an chomhaid aschurtha", // Str::OutputFilePathLabel
    "Babhtáil conairí", // Str::SwapPathsLabel
    "– forscríobhfar é", // Str::WillBeOverwrittenLabel
    "Á chriptiú...", // Str::EncryptingText
    "Á dhíchriptiú...", // Str::DecryptingText
    "Criptigh", // Str::EncryptText
    "Díchriptigh", // Str::DecryptText
    "Criptíodh an comhad", // Str::FileEncryptedMessage
    "Díchriptíodh an comhad", // Str::FileDecryptedMessage
    "Rabhadh!", // Str::WarningTitle
    "An bhfuil tú cinnte?", // Str::AreYouSureTitle
    "Socruithe", // Str::SettingsTitle
    "Gineadóir pasfhocal", // Str::GeneratePasswordTitle
    "Roghnaigh teanga", // Str::SelectLanguageTitle
    "Tá", // Str::YesLabel
    "Níl", // Str::NoLabel
    "OK", // Str::OkLabel
    "Formáid aschuir", // Str::OutFormatLabel
    "Socruithe comhéadain", // Str::InterfaceSettingsLabel
    "Méid", // Str::InterfaceSizeLabel
    "Mód", // Str::ModeLabel
    "Gnáth", // Str::NormalModeLabel
    "Gnáth-théacs", // Str::PlaintextModeLabel
    "Téama", // Str::InterfaceThemeLabel
    "Dath", // Str::InterfaceColorLabel
    "Réamhshocrú (gnáth-théacs)", // Str::DefaultLabel
    "OpenSSL (dénártha)", // Str::OpenSSLLabel
    "Úsáid an pasfhocal seo", // Str::UsePasswordLabel
    "Cóipeáil", // Str::CopyLabel
    "Ctrl + clé-chliceáil chun SHA256 a fháil", // Str::GetSHA256Text
    // Themes
    "Geal", // Str::LightThemeName
    "Dorcha", // Str::DarkThemeName
    // Colors
    "Gorm", // Str::BlueName
    "Cian", // Str::CyanName
    "Glas", // Str::GreenName
    "Líoma", // Str::LimeName
    "Buí", // Str::YellowName
    "Donn", // Str::BrownName
    "Oráiste", // Str::OrangeName
    "Dearg", // Str::RedName
    "Bándearg", // Str::PinkName
    "Corcra", // Str::PurpleName
    "Liath", // Str::GreyName
    "Bán", // Str::WhiteName
    "Dubh", // Str::BlackName

};
static_assert(sizeof(textosGA) / sizeof(textosGA[0]) == N,
    "Faltan o sobran textos en irlandes: revisa que coincidan con Str::Count.");

// Eesti (et)
constexpr const char* textosET[] = {

    
    
    // Info
    "Väljumiseks vajutage Enter...", // Str::ExitInfoMessage
    "Lubage ainult siis, kui faili", // Str::PlainTextModeMessage_FirstLine
    "sisu on lihttekst", // Str::PlainTextModeMessage_SecondLine
    "Krüpteeritud fail salvestatakse", // Str::DefaultCipherModeText_FirstLine
    "prinditavate märkidena", // Str::DefaultCipherModeText_SecondLine
    "Krüpteeritud fail salvestatakse", // Str::OpenSSLCipherModeText_FirstLine
    "OpenSSL-iga ühilduvas binaarvormingus", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 iteratsioonid:", // Str::PBKDF2IterationsText
    // Errors
    "Viga: valed parameetrid", // Str::WrongParamsText
    "Saadud väärtus", // Str::InputValueText
    "Saadud tee", // Str::InputPathText
    "Saadud väärtust ei õnnestunud teisendada arvuks, mis on suurem kui 0 või sellega võrdne", // Str::WrongNumberValueMessage
    "Saadud tee ei vasta ühelegi olemasolevale failile", // Str::WrongPathValueMessage
    "Sisestatud suvandit ei tuvastatud kehtiva parameetrina", // Str::InvalidOptionMessage
    "Sisestatud suvand", // Str::EnteredOptionText
    "Tundmatu erand", // Str::UnknownExceptionText
    "GLFW lähtestamine nurjus", // Str::GLFWErrorMessage
    "GLAD lähtestamine nurjus", // Str::GLADErrorMessage
    "Viga: Faili ei õnnestunud lugemiseks avada", // Str::ReadFileErrorMessage
    "Viga faili sisu lugemisel", // Str::ErrorWhileReadingMessage
    "Viga: Faili ei õnnestunud kirjutamiseks avada", // Str::WriteFileErrorMessage
    "Viga: Kuueteistkümnendsüsteemi stringis peab olema paarisarv märke", // Str::HexStringErrorMessage
    "Viga: Stringis on vigane kuueteistkümnendmärk", // Str::InvalidHexCharacterErrorMessage
    "Viga: Faili ei õnnestunud salvestada", // Str::SaveFileErrorMessage
    "Viga: Faili ei õnnestunud laadida", // Str::LoadFileErrorMessage
    "Viga: Vigane failivorming (oodati 5 välja: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Viga: Iteratsioonide arv ületab määratud maksimumi (10 000 000)", // Str::MaxIterationsErrorMessage
    "Viga: Terviklikkuse kontroll nurjus, vale parool või rikutud/muudetud fail", // Str::IntegrityCheckErrorMessage
    "Viga: Parool ei tohi olla tühi", // Str::EmptyPasswordErrorMessage
    "Viga: Sihtfaili tee on kaust", // Str::OutputFileIsDirectoryErrorMessage
    "Viga: Lähtefaili tee on kaust", // Str::InputFileIsDirectoryErrorMessage
    "Viga: Sihtfaili tee ei tohi olla tühi", // Str::EmptyOutputFilePathErrorMessage
    "Viga: Lähtefaili tee ei tohi olla tühi", // Str::EmptyInputFilePathErrorMessage
    "Viga: Lähtefaili pole olemas", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Keel: Eesti", // Str::LanguageLabel
    "Parool", // Str::PasswordLabel
    "Parooli pikkus", // Str::PasswordLenghtLabel
    "Fail", // Str::FileLabel
    "Fail", // Str::TheFileLabel
    "Tee", // Str::PathLabel
    "Sisendfaili tee", // Str::InputFilePathLabel
    "Väljundfaili tee", // Str::OutputFilePathLabel
    "Vaheta teed", // Str::SwapPathsLabel
    "kirjutatakse üle", // Str::WillBeOverwrittenLabel
    "Krüpteerimine...", // Str::EncryptingText
    "Dekrüpteerimine...", // Str::DecryptingText
    "Krüpteeri", // Str::EncryptText
    "Dekrüpteeri", // Str::DecryptText
    "Fail krüpteeriti edukalt", // Str::FileEncryptedMessage
    "Fail dekrüpteeriti edukalt", // Str::FileDecryptedMessage
    "Hoiatus!", // Str::WarningTitle
    "Kas olete kindel?", // Str::AreYouSureTitle
    "Sätted", // Str::SettingsTitle
    "Paroolide generaator", // Str::GeneratePasswordTitle
    "Valige keel", // Str::SelectLanguageTitle
    "Jah", // Str::YesLabel
    "Ei", // Str::NoLabel
    "OK", // Str::OkLabel
    "Väljundvorming", // Str::OutFormatLabel
    "Liidese sätted", // Str::InterfaceSettingsLabel
    "Suurus", // Str::InterfaceSizeLabel
    "Režiim", // Str::ModeLabel
    "Tavaline", // Str::NormalModeLabel
    "Lihttekst", // Str::PlaintextModeLabel
    "Teema", // Str::InterfaceThemeLabel
    "Värv", // Str::InterfaceColorLabel
    "Vaikimisi (lihttekst)", // Str::DefaultLabel
    "OpenSSL (binaarne)", // Str::OpenSSLLabel
    "Kasuta seda parooli", // Str::UsePasswordLabel
    "Kopeeri", // Str::CopyLabel
    "Ctrl + vasakklõps SHA256 saamiseks", // Str::GetSHA256Text
    // Themes
    "Hele", // Str::LightThemeName
    "Tume", // Str::DarkThemeName
    // Colors
    "Sinine", // Str::BlueName
    "Tsüaan", // Str::CyanName
    "Roheline", // Str::GreenName
    "Laimiroheline", // Str::LimeName
    "Kollane", // Str::YellowName
    "Pruun", // Str::BrownName
    "Oranž", // Str::OrangeName
    "Punane", // Str::RedName
    "Roosa", // Str::PinkName
    "Lilla", // Str::PurpleName
    "Hall", // Str::GreyName
    "Valge", // Str::WhiteName
    "Must", // Str::BlackName

};
static_assert(sizeof(textosET) / sizeof(textosET[0]) == N,
    "Faltan o sobran textos en estonio: revisa que coincidan con Str::Count.");

// Esperanto (eo)
constexpr const char* textosEO[] = {

    
    
    // Info
    "Premu Enter por eliri...", // Str::ExitInfoMessage
    "Ŝaltu nur se la enhavo de la dosiero", // Str::PlainTextModeMessage_FirstLine
    "estas plata teksto", // Str::PlainTextModeMessage_SecondLine
    "La ĉifrita dosiero estos konservita", // Str::DefaultCipherModeText_FirstLine
    "kiel preseblaj signoj", // Str::DefaultCipherModeText_SecondLine
    "La ĉifrita dosiero estos konservita en", // Str::OpenSSLCipherModeText_FirstLine
    "duuma formo, kongrua kun OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-iteracioj:", // Str::PBKDF2IterationsText
    // Errors
    "Eraro: malĝustaj parametroj", // Str::WrongParamsText
    "Ricevita valoro", // Str::InputValueText
    "Ricevita vojo", // Str::InputPathText
    "Ne eblis konverti la ricevitan valoron al nombro pli granda ol aŭ egala al 0", // Str::WrongNumberValueMessage
    "La ricevita vojo ne respondas al iu ajn ekzistanta dosiero", // Str::WrongPathValueMessage
    "La enigita opcio ne estas rekonata kiel valida parametro", // Str::InvalidOptionMessage
    "Enigita opcio", // Str::EnteredOptionText
    "Nekonata escepto", // Str::UnknownExceptionText
    "Malsukcesis pravalorizi GLFW", // Str::GLFWErrorMessage
    "Malsukcesis pravalorizi GLAD", // Str::GLADErrorMessage
    "Eraro: Ne eblis malfermi la dosieron por legado", // Str::ReadFileErrorMessage
    "Eraro dum legado de la enhavo de la dosiero", // Str::ErrorWhileReadingMessage
    "Eraro: Ne eblis malfermi la dosieron por skribado", // Str::WriteFileErrorMessage
    "Eraro: La deksesuma ĉeno devas havi paran nombron de signoj", // Str::HexStringErrorMessage
    "Eraro: Nevalida deksesuma signo en la ĉeno", // Str::InvalidHexCharacterErrorMessage
    "Eraro: Ne eblis konservi la dosieron", // Str::SaveFileErrorMessage
    "Eraro: Ne eblis ŝargi la dosieron", // Str::LoadFileErrorMessage
    "Eraro: Nevalida dosierformo (atendataj 5 kampoj: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Eraro: La nombro de iteracioj superas la difinitan maksimumon (10 000 000)", // Str::MaxIterationsErrorMessage
    "Eraro: Kontrolo de integreco malsukcesis, malĝusta pasvorto aŭ difektita/modifita dosiero", // Str::IntegrityCheckErrorMessage
    "Eraro: La pasvorto ne povas esti malplena", // Str::EmptyPasswordErrorMessage
    "Eraro: La vojo de la cela dosiero estas dosierujo", // Str::OutputFileIsDirectoryErrorMessage
    "Eraro: La vojo de la fonta dosiero estas dosierujo", // Str::InputFileIsDirectoryErrorMessage
    "Eraro: La vojo de la cela dosiero ne povas esti malplena", // Str::EmptyOutputFilePathErrorMessage
    "Eraro: La vojo de la fonta dosiero ne povas esti malplena", // Str::EmptyInputFilePathErrorMessage
    "Eraro: La fonta dosiero ne ekzistas", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Lingvo: Esperanto", // Str::LanguageLabel
    "Pasvorto", // Str::PasswordLabel
    "Longo de pasvorto", // Str::PasswordLenghtLabel
    "Dosiero", // Str::FileLabel
    "La dosiero", // Str::TheFileLabel
    "Vojo", // Str::PathLabel
    "Eniga vojo", // Str::InputFilePathLabel
    "Eliga vojo", // Str::OutputFilePathLabel
    "Interŝanĝi vojojn", // Str::SwapPathsLabel
    "estos anstataŭigita", // Str::WillBeOverwrittenLabel
    "Ĉifrado...", // Str::EncryptingText
    "Malĉifrado...", // Str::DecryptingText
    "Ĉifri", // Str::EncryptText
    "Malĉifri", // Str::DecryptText
    "Dosiero sukcese ĉifrita", // Str::FileEncryptedMessage
    "Dosiero sukcese malĉifrita", // Str::FileDecryptedMessage
    "Averto!", // Str::WarningTitle
    "Ĉu vi certas?", // Str::AreYouSureTitle
    "Agordoj", // Str::SettingsTitle
    "Pasvortgenerilo", // Str::GeneratePasswordTitle
    "Elekti lingvon", // Str::SelectLanguageTitle
    "Jes", // Str::YesLabel
    "Ne", // Str::NoLabel
    "Bone", // Str::OkLabel
    "Eliga formo", // Str::OutFormatLabel
    "Agordoj de interfaco", // Str::InterfaceSettingsLabel
    "Grando", // Str::InterfaceSizeLabel
    "Reĝimo", // Str::ModeLabel
    "Normala", // Str::NormalModeLabel
    "Plata teksto", // Str::PlaintextModeLabel
    "Etoso", // Str::InterfaceThemeLabel
    "Koloro", // Str::InterfaceColorLabel
    "Defaŭlta (plata teksto)", // Str::DefaultLabel
    "OpenSSL (duuma)", // Str::OpenSSLLabel
    "Uzi ĉi tiun pasvorton", // Str::UsePasswordLabel
    "Kopii", // Str::CopyLabel
    "Ctrl + maldekstra klako por akiri SHA256", // Str::GetSHA256Text
    // Themes
    "Hela", // Str::LightThemeName
    "Malhela", // Str::DarkThemeName
    // Colors
    "Blua", // Str::BlueName
    "Ciana", // Str::CyanName
    "Verda", // Str::GreenName
    "Limeverda", // Str::LimeName
    "Flava", // Str::YellowName
    "Bruna", // Str::BrownName
    "Oranĝa", // Str::OrangeName
    "Ruĝa", // Str::RedName
    "Rozkolora", // Str::PinkName
    "Purpura", // Str::PurpleName
    "Griza", // Str::GreyName
    "Blanka", // Str::WhiteName
    "Nigra", // Str::BlackName

};
static_assert(sizeof(textosEO) / sizeof(textosEO[0]) == N,
    "Faltan o sobran textos en esperanto: revisa que coincidan con Str::Count.");

// Euskara (eu)
constexpr const char* textosEU[] = {

    
    
    // Info
    "Sakatu Enter irteteko...", // Str::ExitInfoMessage
    "Gaitu soilik fitxategiaren edukia", // Str::PlainTextModeMessage_FirstLine
    "testu arrunta bada", // Str::PlainTextModeMessage_SecondLine
    "Fitxategi zifratua", // Str::DefaultCipherModeText_FirstLine
    "karaktere inprimagarri gisa gordeko da", // Str::DefaultCipherModeText_SecondLine
    "Fitxategi zifratua formatu bitarrean", // Str::OpenSSLCipherModeText_FirstLine
    "gordeko da, OpenSSL-rekin bateragarria", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2 iterazioak:", // Str::PBKDF2IterationsText
    // Errors
    "Errorea: parametro okerrak", // Str::WrongParamsText
    "Jasotako balioa", // Str::InputValueText
    "Jasotako bidea", // Str::InputPathText
    "Ezin izan da jasotako balioa 0 baino handiagoa edo 0ren berdina den zenbaki bihurtu", // Str::WrongNumberValueMessage
    "Jasotako bidea ez dagokio lehendik dagoen inongo fitxategiri", // Str::WrongPathValueMessage
    "Sartutako aukera ez da parametro baliodun gisa ezagutzen", // Str::InvalidOptionMessage
    "Sartutako aukera", // Str::EnteredOptionText
    "Salbuespen ezezaguna", // Str::UnknownExceptionText
    "Ezin izan da GLFW hasieratu", // Str::GLFWErrorMessage
    "Ezin izan da GLAD hasieratu", // Str::GLADErrorMessage
    "Errorea: Ezin izan da fitxategia irakurtzeko ireki", // Str::ReadFileErrorMessage
    "Errorea fitxategiaren edukia irakurtzean", // Str::ErrorWhileReadingMessage
    "Errorea: Ezin izan da fitxategia idazteko ireki", // Str::WriteFileErrorMessage
    "Errorea: Kate hamaseitarrak karaktere kopuru bikoitia izan behar du", // Str::HexStringErrorMessage
    "Errorea: Karaktere hamaseitar baliogabea katean", // Str::InvalidHexCharacterErrorMessage
    "Errorea: Ezin izan da fitxategia gorde", // Str::SaveFileErrorMessage
    "Errorea: Ezin izan da fitxategia kargatu", // Str::LoadFileErrorMessage
    "Errorea: Fitxategi-formatu baliogabea (5 eremu espero ziren: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Errorea: Iterazio kopuruak ezarritako gehienezkoa gainditzen du (10.000.000)", // Str::MaxIterationsErrorMessage
    "Errorea: Osotasun-egiaztapenak huts egin du, pasahitz okerra edo fitxategi hondatua/manipulatua", // Str::IntegrityCheckErrorMessage
    "Errorea: Pasahitza ezin da hutsik egon", // Str::EmptyPasswordErrorMessage
    "Errorea: Helburuko fitxategiaren bidea direktorio bat da", // Str::OutputFileIsDirectoryErrorMessage
    "Errorea: Iturburuko fitxategiaren bidea direktorio bat da", // Str::InputFileIsDirectoryErrorMessage
    "Errorea: Helburuko fitxategiaren bidea ezin da hutsik egon", // Str::EmptyOutputFilePathErrorMessage
    "Errorea: Iturburuko fitxategiaren bidea ezin da hutsik egon", // Str::EmptyInputFilePathErrorMessage
    "Errorea: Iturburuko fitxategia ez dago", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Hizkuntza: Euskara", // Str::LanguageLabel
    "Pasahitza", // Str::PasswordLabel
    "Pasahitzaren luzera", // Str::PasswordLenghtLabel
    "Fitxategia", // Str::FileLabel
    "Fitxategia", // Str::TheFileLabel
    "Bidea", // Str::PathLabel
    "Sarrerako bidea", // Str::InputFilePathLabel
    "Irteerako bidea", // Str::OutputFilePathLabel
    "Trukatu bideak", // Str::SwapPathsLabel
    "gainidatziko da", // Str::WillBeOverwrittenLabel
    "Zifratzen...", // Str::EncryptingText
    "Deszifratzen...", // Str::DecryptingText
    "Zifratu", // Str::EncryptText
    "Deszifratu", // Str::DecryptText
    "Fitxategia behar bezala zifratu da", // Str::FileEncryptedMessage
    "Fitxategia behar bezala deszifratu da", // Str::FileDecryptedMessage
    "Kontuz!", // Str::WarningTitle
    "Ziur zaude?", // Str::AreYouSureTitle
    "Ezarpenak", // Str::SettingsTitle
    "Pasahitz-sorgailua", // Str::GeneratePasswordTitle
    "Hautatu hizkuntza", // Str::SelectLanguageTitle
    "Bai", // Str::YesLabel
    "Ez", // Str::NoLabel
    "Ados", // Str::OkLabel
    "Irteerako formatua", // Str::OutFormatLabel
    "Interfazearen ezarpenak", // Str::InterfaceSettingsLabel
    "Tamaina", // Str::InterfaceSizeLabel
    "Modua", // Str::ModeLabel
    "Normala", // Str::NormalModeLabel
    "Testu arrunta", // Str::PlaintextModeLabel
    "Gaia", // Str::InterfaceThemeLabel
    "Kolorea", // Str::InterfaceColorLabel
    "Lehenetsia (testu arrunta)", // Str::DefaultLabel
    "OpenSSL (bitarra)", // Str::OpenSSLLabel
    "Erabili pasahitz hau", // Str::UsePasswordLabel
    "Kopiatu", // Str::CopyLabel
    "Ctrl + ezkerreko klik SHA256 lortzeko", // Str::GetSHA256Text
    // Themes
    "Argia", // Str::LightThemeName
    "Iluna", // Str::DarkThemeName
    // Colors
    "Urdina", // Str::BlueName
    "Ziana", // Str::CyanName
    "Berdea", // Str::GreenName
    "Lima-berdea", // Str::LimeName
    "Horia", // Str::YellowName
    "Marroia", // Str::BrownName
    "Laranja", // Str::OrangeName
    "Gorria", // Str::RedName
    "Arrosa", // Str::PinkName
    "Morea", // Str::PurpleName
    "Grisa", // Str::GreyName
    "Zuria", // Str::WhiteName
    "Beltza", // Str::BlackName

};
static_assert(sizeof(textosEU) / sizeof(textosEU[0]) == N,
    "Faltan o sobran textos en euskera: revisa que coincidan con Str::Count.");

// Cymraeg (cy)
constexpr const char* textosCY[] = {

    
    
    // Info
    "Pwyswch Enter i adael...", // Str::ExitInfoMessage
    "Galluogwch dim ond os yw cynnwys", // Str::PlainTextModeMessage_FirstLine
    "y ffeil yn destun plaen", // Str::PlainTextModeMessage_SecondLine
    "Caiff y ffeil wedi'i hamgryptio", // Str::DefaultCipherModeText_FirstLine
    "ei chadw fel nodau argraffadwy", // Str::DefaultCipherModeText_SecondLine
    "Caiff y ffeil wedi'i hamgryptio ei chadw", // Str::OpenSSLCipherModeText_FirstLine
    "mewn fformat deuaidd sy'n gydnaws ag OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iteriadau PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Gwall: paramedrau anghywir", // Str::WrongParamsText
    "Gwerth a dderbyniwyd", // Str::InputValueText
    "Llwybr a dderbyniwyd", // Str::InputPathText
    "Nid oedd modd trosi'r gwerth a dderbyniwyd yn rhif sy'n fwy na 0 neu'n hafal i 0", // Str::WrongNumberValueMessage
    "Nid yw'r llwybr a dderbyniwyd yn cyfateb i unrhyw ffeil sy'n bodoli", // Str::WrongPathValueMessage
    "Nid yw'r dewis a roddwyd yn cael ei gydnabod fel paramedr dilys", // Str::InvalidOptionMessage
    "Dewis a roddwyd", // Str::EnteredOptionText
    "Eithriad anhysbys", // Str::UnknownExceptionText
    "Methwyd cychwyn GLFW", // Str::GLFWErrorMessage
    "Methwyd cychwyn GLAD", // Str::GLADErrorMessage
    "Gwall: Nid oedd modd agor y ffeil i'w darllen", // Str::ReadFileErrorMessage
    "Gwall wrth ddarllen cynnwys y ffeil", // Str::ErrorWhileReadingMessage
    "Gwall: Nid oedd modd agor y ffeil i ysgrifennu iddi", // Str::WriteFileErrorMessage
    "Gwall: Rhaid i'r llinyn hecsadegol gynnwys nifer eilrif o nodau", // Str::HexStringErrorMessage
    "Gwall: Nod hecsadegol annilys yn y llinyn", // Str::InvalidHexCharacterErrorMessage
    "Gwall: Nid oedd modd cadw'r ffeil", // Str::SaveFileErrorMessage
    "Gwall: Nid oedd modd llwytho'r ffeil", // Str::LoadFileErrorMessage
    "Gwall: Fformat ffeil annilys (disgwylid 5 maes: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Gwall: Mae nifer yr iteriadau'n fwy na'r uchafswm a osodwyd (10,000,000)", // Str::MaxIterationsErrorMessage
    "Gwall: Methodd y gwiriad cywirdeb, cyfrinair anghywir neu ffeil lygredig/wedi'i haddasu", // Str::IntegrityCheckErrorMessage
    "Gwall: Ni all y cyfrinair fod yn wag", // Str::EmptyPasswordErrorMessage
    "Gwall: Mae llwybr y ffeil gyrchfan yn ffolder", // Str::OutputFileIsDirectoryErrorMessage
    "Gwall: Mae llwybr y ffeil ffynhonnell yn ffolder", // Str::InputFileIsDirectoryErrorMessage
    "Gwall: Ni all llwybr y ffeil gyrchfan fod yn wag", // Str::EmptyOutputFilePathErrorMessage
    "Gwall: Ni all llwybr y ffeil ffynhonnell fod yn wag", // Str::EmptyInputFilePathErrorMessage
    "Gwall: Nid yw'r ffeil ffynhonnell yn bodoli", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Iaith: Cymraeg", // Str::LanguageLabel
    "Cyfrinair", // Str::PasswordLabel
    "Hyd y cyfrinair", // Str::PasswordLenghtLabel
    "Ffeil", // Str::FileLabel
    "Y ffeil", // Str::TheFileLabel
    "Llwybr", // Str::PathLabel
    "Llwybr mewnbwn", // Str::InputFilePathLabel
    "Llwybr allbwn", // Str::OutputFilePathLabel
    "Cyfnewid llwybrau", // Str::SwapPathsLabel
    "– bydd yn cael ei throsysgrifo", // Str::WillBeOverwrittenLabel
    "Yn amgryptio...", // Str::EncryptingText
    "Yn dadgryptio...", // Str::DecryptingText
    "Amgryptio", // Str::EncryptText
    "Dadgryptio", // Str::DecryptText
    "Ffeil wedi'i hamgryptio'n llwyddiannus", // Str::FileEncryptedMessage
    "Ffeil wedi'i dadgryptio'n llwyddiannus", // Str::FileDecryptedMessage
    "Rhybudd!", // Str::WarningTitle
    "Ydych chi'n siŵr?", // Str::AreYouSureTitle
    "Gosodiadau", // Str::SettingsTitle
    "Cynhyrchydd cyfrineiriau", // Str::GeneratePasswordTitle
    "Dewiswch iaith", // Str::SelectLanguageTitle
    "Ie", // Str::YesLabel
    "Na", // Str::NoLabel
    "Iawn", // Str::OkLabel
    "Fformat allbwn", // Str::OutFormatLabel
    "Gosodiadau'r rhyngwyneb", // Str::InterfaceSettingsLabel
    "Maint", // Str::InterfaceSizeLabel
    "Modd", // Str::ModeLabel
    "Arferol", // Str::NormalModeLabel
    "Testun plaen", // Str::PlaintextModeLabel
    "Thema", // Str::InterfaceThemeLabel
    "Lliw", // Str::InterfaceColorLabel
    "Rhagosodiad (testun plaen)", // Str::DefaultLabel
    "OpenSSL (deuaidd)", // Str::OpenSSLLabel
    "Defnyddio'r cyfrinair hwn", // Str::UsePasswordLabel
    "Copïo", // Str::CopyLabel
    "Ctrl + clic chwith i gael y SHA256", // Str::GetSHA256Text
    // Themes
    "Golau", // Str::LightThemeName
    "Tywyll", // Str::DarkThemeName
    // Colors
    "Glas", // Str::BlueName
    "Gwyrddlas", // Str::CyanName
    "Gwyrdd", // Str::GreenName
    "Gwyrdd leim", // Str::LimeName
    "Melyn", // Str::YellowName
    "Brown", // Str::BrownName
    "Oren", // Str::OrangeName
    "Coch", // Str::RedName
    "Pinc", // Str::PinkName
    "Porffor", // Str::PurpleName
    "Llwyd", // Str::GreyName
    "Gwyn", // Str::WhiteName
    "Du", // Str::BlackName

};
static_assert(sizeof(textosCY) / sizeof(textosCY[0]) == N,
    "Faltan o sobran textos en gales: revisa que coincidan con Str::Count.");

// Lëtzebuergesch (lb)
constexpr const char* textosLB[] = {

    
    
    // Info
    "Dréckt Enter fir erauszegoen...", // Str::ExitInfoMessage
    "Nëmmen aktivéieren, wann den Inhalt", // Str::PlainTextModeMessage_FirstLine
    "vum Fichier einfachen Text ass", // Str::PlainTextModeMessage_SecondLine
    "De verschlësselte Fichier gëtt als", // Str::DefaultCipherModeText_FirstLine
    "dréckbar Zeechen gespäichert", // Str::DefaultCipherModeText_SecondLine
    "De verschlësselte Fichier gëtt am", // Str::OpenSSLCipherModeText_FirstLine
    "OpenSSL-kompatibele Binärformat gespäichert", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-Iteratiounen:", // Str::PBKDF2IterationsText
    // Errors
    "Feeler: falsch Parameteren", // Str::WrongParamsText
    "Empfaangene Wäert", // Str::InputValueText
    "Empfaangene Pad", // Str::InputPathText
    "De Wäert konnt net an eng Zuel méi grouss wéi oder gläich 0 ëmgewandelt ginn", // Str::WrongNumberValueMessage
    "De Pad entsprécht kengem existéierende Fichier", // Str::WrongPathValueMessage
    "Déi aginn Optioun gëtt net als gültege Parameter erkannt", // Str::InvalidOptionMessage
    "Aginn Optioun", // Str::EnteredOptionText
    "Onbekannt Ausnam", // Str::UnknownExceptionText
    "GLFW konnt net initialiséiert ginn", // Str::GLFWErrorMessage
    "GLAD konnt net initialiséiert ginn", // Str::GLADErrorMessage
    "Feeler: De Fichier konnt net zum Liesen opgemaach ginn", // Str::ReadFileErrorMessage
    "Feeler beim Liese vum Inhalt vum Fichier", // Str::ErrorWhileReadingMessage
    "Feeler: De Fichier konnt net zum Schreiwen opgemaach ginn", // Str::WriteFileErrorMessage
    "Feeler: D'Hex-Zeecheketten muss eng gerued Zuel vun Zeechen hunn", // Str::HexStringErrorMessage
    "Feeler: Ongültegt Hex-Zeechen an der Zeecheketten", // Str::InvalidHexCharacterErrorMessage
    "Feeler: De Fichier konnt net gespäichert ginn", // Str::SaveFileErrorMessage
    "Feeler: De Fichier konnt net geluede ginn", // Str::LoadFileErrorMessage
    "Feeler: Ongültegt Fichiersformat (5 Felder erwaart: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Feeler: D'Zuel vun den Iteratiounen iwwerschreit de festgeluechte Maximum (10.000.000)", // Str::MaxIterationsErrorMessage
    "Feeler: Integritéitsiwwerpréiwung feelgeschloen, falscht Passwuert oder beschiedegte/manipuléierte Fichier", // Str::IntegrityCheckErrorMessage
    "Feeler: D'Passwuert däerf net eidel sinn", // Str::EmptyPasswordErrorMessage
    "Feeler: De Pad vum Zilfichier ass en Dossier", // Str::OutputFileIsDirectoryErrorMessage
    "Feeler: De Pad vum Quellfichier ass en Dossier", // Str::InputFileIsDirectoryErrorMessage
    "Feeler: De Pad vum Zilfichier däerf net eidel sinn", // Str::EmptyOutputFilePathErrorMessage
    "Feeler: De Pad vum Quellfichier däerf net eidel sinn", // Str::EmptyInputFilePathErrorMessage
    "Feeler: De Quellfichier existéiert net", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Sprooch: Lëtzebuergesch", // Str::LanguageLabel
    "Passwuert", // Str::PasswordLabel
    "Passwuertlängt", // Str::PasswordLenghtLabel
    "Fichier", // Str::FileLabel
    "De Fichier", // Str::TheFileLabel
    "Pad", // Str::PathLabel
    "Agabpad", // Str::InputFilePathLabel
    "Ausgabpad", // Str::OutputFilePathLabel
    "Paden tauschen", // Str::SwapPathsLabel
    "gëtt iwwerschriwwen", // Str::WillBeOverwrittenLabel
    "Gëtt verschlësselt...", // Str::EncryptingText
    "Gëtt entschlësselt...", // Str::DecryptingText
    "Verschlësselen", // Str::EncryptText
    "Entschlësselen", // Str::DecryptText
    "Fichier erfollegräich verschlësselt", // Str::FileEncryptedMessage
    "Fichier erfollegräich entschlësselt", // Str::FileDecryptedMessage
    "Opgepasst!", // Str::WarningTitle
    "Sidd Dir sécher?", // Str::AreYouSureTitle
    "Astellungen", // Str::SettingsTitle
    "Passwuertgenerator", // Str::GeneratePasswordTitle
    "Sprooch auswielen", // Str::SelectLanguageTitle
    "Jo", // Str::YesLabel
    "Nee", // Str::NoLabel
    "OK", // Str::OkLabel
    "Ausgabformat", // Str::OutFormatLabel
    "Interface-Astellungen", // Str::InterfaceSettingsLabel
    "Gréisst", // Str::InterfaceSizeLabel
    "Modus", // Str::ModeLabel
    "Normal", // Str::NormalModeLabel
    "Einfachen Text", // Str::PlaintextModeLabel
    "Design", // Str::InterfaceThemeLabel
    "Faarf", // Str::InterfaceColorLabel
    "Standard (einfachen Text)", // Str::DefaultLabel
    "OpenSSL (binär)", // Str::OpenSSLLabel
    "Dëst Passwuert benotzen", // Str::UsePasswordLabel
    "Kopéieren", // Str::CopyLabel
    "Ctrl + Lénksklick fir SHA256 ze kréien", // Str::GetSHA256Text
    // Themes
    "Hell", // Str::LightThemeName
    "Donkel", // Str::DarkThemeName
    // Colors
    "Blo", // Str::BlueName
    "Cyan", // Str::CyanName
    "Gréng", // Str::GreenName
    "Limettegréng", // Str::LimeName
    "Giel", // Str::YellowName
    "Brong", // Str::BrownName
    "Orange", // Str::OrangeName
    "Rout", // Str::RedName
    "Rosa", // Str::PinkName
    "Mof", // Str::PurpleName
    "Gro", // Str::GreyName
    "Wäiss", // Str::WhiteName
    "Schwaarz", // Str::BlackName

};
static_assert(sizeof(textosLB) / sizeof(textosLB[0]) == N,
    "Faltan o sobran textos en luxemburgues: revisa que coincidan con Str::Count.");

// Malti (mt)
constexpr const char* textosMT[] = {

    
    
    // Info
    "Agħfas Enter biex toħroġ...", // Str::ExitInfoMessage
    "Attiva biss jekk il-kontenut tal-fajl", // Str::PlainTextModeMessage_FirstLine
    "huwa test sempliċi", // Str::PlainTextModeMessage_SecondLine
    "Il-fajl ikkriptat se jiġi ssejvjat", // Str::DefaultCipherModeText_FirstLine
    "bħala karattri li jistgħu jiġu stampati", // Str::DefaultCipherModeText_SecondLine
    "Il-fajl ikkriptat se jiġi ssejvjat f'format", // Str::OpenSSLCipherModeText_FirstLine
    "binarju, kompatibbli ma' OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "Iterazzjonijiet PBKDF2:", // Str::PBKDF2IterationsText
    // Errors
    "Żball: parametri ħżiena", // Str::WrongParamsText
    "Valur riċevut", // Str::InputValueText
    "Mogħdija riċevuta", // Str::InputPathText
    "Il-valur riċevut ma setax jiġi kkonvertit f'numru akbar minn jew ugwali għal 0", // Str::WrongNumberValueMessage
    "Il-mogħdija riċevuta ma tikkorrispondi għal ebda fajl eżistenti", // Str::WrongPathValueMessage
    "L-għażla mdaħħla mhijiex rikonoxxuta bħala parametru validu", // Str::InvalidOptionMessage
    "Għażla mdaħħla", // Str::EnteredOptionText
    "Eċċezzjoni mhux magħrufa", // Str::UnknownExceptionText
    "L-inizjalizzazzjoni ta' GLFW falliet", // Str::GLFWErrorMessage
    "L-inizjalizzazzjoni ta' GLAD falliet", // Str::GLADErrorMessage
    "Żball: Il-fajl ma setax jinfetaħ għall-qari", // Str::ReadFileErrorMessage
    "Żball waqt il-qari tal-kontenut tal-fajl", // Str::ErrorWhileReadingMessage
    "Żball: Il-fajl ma setax jinfetaħ għall-kitba", // Str::WriteFileErrorMessage
    "Żball: Is-sekwenza eżadeċimali għandu jkollha numru par ta' karattri", // Str::HexStringErrorMessage
    "Żball: Karattru eżadeċimali mhux validu fis-sekwenza", // Str::InvalidHexCharacterErrorMessage
    "Żball: Il-fajl ma setax jiġi ssejvjat", // Str::SaveFileErrorMessage
    "Żball: Il-fajl ma setax jiġi mtella'", // Str::LoadFileErrorMessage
    "Żball: Format tal-fajl mhux validu (mistennija 5 oqsma: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Żball: In-numru ta' iterazzjonijiet jaqbeż il-massimu stabbilit (10,000,000)", // Str::MaxIterationsErrorMessage
    "Żball: Il-verifika tal-integrità falliet, password ħażina jew fajl korrott/manipulat", // Str::IntegrityCheckErrorMessage
    "Żball: Il-password ma tistax tkun vojta", // Str::EmptyPasswordErrorMessage
    "Żball: Il-mogħdija tal-fajl tad-destinazzjoni hija folder", // Str::OutputFileIsDirectoryErrorMessage
    "Żball: Il-mogħdija tal-fajl sors hija folder", // Str::InputFileIsDirectoryErrorMessage
    "Żball: Il-mogħdija tal-fajl tad-destinazzjoni ma tistax tkun vojta", // Str::EmptyOutputFilePathErrorMessage
    "Żball: Il-mogħdija tal-fajl sors ma tistax tkun vojta", // Str::EmptyInputFilePathErrorMessage
    "Żball: Il-fajl sors ma jeżistix", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Lingwa: Malti", // Str::LanguageLabel
    "Password", // Str::PasswordLabel
    "Tul tal-password", // Str::PasswordLenghtLabel
    "Fajl", // Str::FileLabel
    "Il-fajl", // Str::TheFileLabel
    "Mogħdija", // Str::PathLabel
    "Mogħdija tal-input", // Str::InputFilePathLabel
    "Mogħdija tal-output", // Str::OutputFilePathLabel
    "Ibdel il-mogħdijiet", // Str::SwapPathsLabel
    "se jinkiteb fuqu", // Str::WillBeOverwrittenLabel
    "Qed jiġi kkriptat...", // Str::EncryptingText
    "Qed jiġi dekriptat...", // Str::DecryptingText
    "Ikkripta", // Str::EncryptText
    "Iddekripta", // Str::DecryptText
    "Il-fajl ġie kkriptat b'suċċess", // Str::FileEncryptedMessage
    "Il-fajl ġie dekriptat b'suċċess", // Str::FileDecryptedMessage
    "Twissija!", // Str::WarningTitle
    "Int ċert?", // Str::AreYouSureTitle
    "Issettjar", // Str::SettingsTitle
    "Ġeneratur tal-password", // Str::GeneratePasswordTitle
    "Agħżel lingwa", // Str::SelectLanguageTitle
    "Iva", // Str::YesLabel
    "Le", // Str::NoLabel
    "OK", // Str::OkLabel
    "Format tal-output", // Str::OutFormatLabel
    "Issettjar tal-interfaċċja", // Str::InterfaceSettingsLabel
    "Daqs", // Str::InterfaceSizeLabel
    "Modalità", // Str::ModeLabel
    "Normali", // Str::NormalModeLabel
    "Test sempliċi", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Kulur", // Str::InterfaceColorLabel
    "Default (test sempliċi)", // Str::DefaultLabel
    "OpenSSL (binarju)", // Str::OpenSSLLabel
    "Uża din il-password", // Str::UsePasswordLabel
    "Ikkopja", // Str::CopyLabel
    "Ctrl + klikk tax-xellug biex tikseb l-SHA256", // Str::GetSHA256Text
    // Themes
    "Ċar", // Str::LightThemeName
    "Skur", // Str::DarkThemeName
    // Colors
    "Blu", // Str::BlueName
    "Ċjan", // Str::CyanName
    "Aħdar", // Str::GreenName
    "Aħdar lajm", // Str::LimeName
    "Isfar", // Str::YellowName
    "Kannella", // Str::BrownName
    "Oranġjo", // Str::OrangeName
    "Aħmar", // Str::RedName
    "Roża", // Str::PinkName
    "Vjola", // Str::PurpleName
    "Griż", // Str::GreyName
    "Abjad", // Str::WhiteName
    "Iswed", // Str::BlackName

};
static_assert(sizeof(textosMT) / sizeof(textosMT[0]) == N,
    "Faltan o sobran textos en maltes: revisa que coincidan con Str::Count.");

// Íslenska (is)
constexpr const char* textosIS[] = {

    
    
    // Info
    "Ýttu á Enter til að hætta...", // Str::ExitInfoMessage
    "Virkjaðu aðeins ef innihald", // Str::PlainTextModeMessage_FirstLine
    "skrárinnar er venjulegur texti", // Str::PlainTextModeMessage_SecondLine
    "Dulkóðaða skráin verður vistuð", // Str::DefaultCipherModeText_FirstLine
    "sem prentanlegir stafir", // Str::DefaultCipherModeText_SecondLine
    "Dulkóðaða skráin verður vistuð á", // Str::OpenSSLCipherModeText_FirstLine
    "tvíundarsniði, samhæfðu OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-ítranir:", // Str::PBKDF2IterationsText
    // Errors
    "Villa: rangar færibreytur", // Str::WrongParamsText
    "Móttekið gildi", // Str::InputValueText
    "Móttekin slóð", // Str::InputPathText
    "Ekki tókst að breyta mótteknu gildi í tölu sem er stærri en eða jöfn 0", // Str::WrongNumberValueMessage
    "Móttekin slóð samsvarar engri fyrirliggjandi skrá", // Str::WrongPathValueMessage
    "Valkosturinn sem sleginn var inn er ekki þekktur sem gild færibreyta", // Str::InvalidOptionMessage
    "Innsleginn valkostur", // Str::EnteredOptionText
    "Óþekkt undantekning", // Str::UnknownExceptionText
    "Ekki tókst að frumstilla GLFW", // Str::GLFWErrorMessage
    "Ekki tókst að frumstilla GLAD", // Str::GLADErrorMessage
    "Villa: Ekki tókst að opna skrána til lesturs", // Str::ReadFileErrorMessage
    "Villa við lestur á innihaldi skrárinnar", // Str::ErrorWhileReadingMessage
    "Villa: Ekki tókst að opna skrána til skrifunar", // Str::WriteFileErrorMessage
    "Villa: Sextándakerfisstrengurinn verður að hafa slétta tölu stafa", // Str::HexStringErrorMessage
    "Villa: Ógildur sextándakerfisstafur í strengnum", // Str::InvalidHexCharacterErrorMessage
    "Villa: Ekki tókst að vista skrána", // Str::SaveFileErrorMessage
    "Villa: Ekki tókst að hlaða skránni", // Str::LoadFileErrorMessage
    "Villa: Ógilt skráarsnið (búist var við 5 reitum: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Villa: Fjöldi ítrana er meiri en tilgreint hámark (10.000.000)", // Str::MaxIterationsErrorMessage
    "Villa: Heilleikaprófun mistókst, rangt lykilorð eða skemmd/breytt skrá", // Str::IntegrityCheckErrorMessage
    "Villa: Lykilorðið má ekki vera tómt", // Str::EmptyPasswordErrorMessage
    "Villa: Slóð markskrárinnar er mappa", // Str::OutputFileIsDirectoryErrorMessage
    "Villa: Slóð upprunaskrárinnar er mappa", // Str::InputFileIsDirectoryErrorMessage
    "Villa: Slóð markskrárinnar má ekki vera tóm", // Str::EmptyOutputFilePathErrorMessage
    "Villa: Slóð upprunaskrárinnar má ekki vera tóm", // Str::EmptyInputFilePathErrorMessage
    "Villa: Upprunaskráin er ekki til", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Tungumál: Íslenska", // Str::LanguageLabel
    "Lykilorð", // Str::PasswordLabel
    "Lengd lykilorðs", // Str::PasswordLenghtLabel
    "Skrá", // Str::FileLabel
    "Skráin", // Str::TheFileLabel
    "Slóð", // Str::PathLabel
    "Inntaksslóð", // Str::InputFilePathLabel
    "Úttaksslóð", // Str::OutputFilePathLabel
    "Víxla slóðum", // Str::SwapPathsLabel
    "verður skrifuð yfir", // Str::WillBeOverwrittenLabel
    "Dulkóðar...", // Str::EncryptingText
    "Afkóðar...", // Str::DecryptingText
    "Dulkóða", // Str::EncryptText
    "Afkóða", // Str::DecryptText
    "Skráin var dulkóðuð", // Str::FileEncryptedMessage
    "Skráin var afkóðuð", // Str::FileDecryptedMessage
    "Viðvörun!", // Str::WarningTitle
    "Ertu viss?", // Str::AreYouSureTitle
    "Stillingar", // Str::SettingsTitle
    "Lykilorðasmiður", // Str::GeneratePasswordTitle
    "Veldu tungumál", // Str::SelectLanguageTitle
    "Já", // Str::YesLabel
    "Nei", // Str::NoLabel
    "Í lagi", // Str::OkLabel
    "Úttakssnið", // Str::OutFormatLabel
    "Viðmótsstillingar", // Str::InterfaceSettingsLabel
    "Stærð", // Str::InterfaceSizeLabel
    "Hamur", // Str::ModeLabel
    "Venjulegur", // Str::NormalModeLabel
    "Venjulegur texti", // Str::PlaintextModeLabel
    "Þema", // Str::InterfaceThemeLabel
    "Litur", // Str::InterfaceColorLabel
    "Sjálfgefið (venjulegur texti)", // Str::DefaultLabel
    "OpenSSL (tvíundar)", // Str::OpenSSLLabel
    "Nota þetta lykilorð", // Str::UsePasswordLabel
    "Afrita", // Str::CopyLabel
    "Ctrl + vinstrismell til að fá SHA256", // Str::GetSHA256Text
    // Themes
    "Ljóst", // Str::LightThemeName
    "Dökkt", // Str::DarkThemeName
    // Colors
    "Blár", // Str::BlueName
    "Blágrænn", // Str::CyanName
    "Grænn", // Str::GreenName
    "Límónugrænn", // Str::LimeName
    "Gulur", // Str::YellowName
    "Brúnn", // Str::BrownName
    "Appelsínugulur", // Str::OrangeName
    "Rauður", // Str::RedName
    "Bleikur", // Str::PinkName
    "Fjólublár", // Str::PurpleName
    "Grár", // Str::GreyName
    "Hvítur", // Str::WhiteName
    "Svartur", // Str::BlackName

};
static_assert(sizeof(textosIS) / sizeof(textosIS[0]) == N,
    "Faltan o sobran textos en islandes: revisa que coincidan con Str::Count.");

// Føroyskt (fo)
constexpr const char* textosFO[] = {

    
    
    // Info
    "Trýst á Enter fyri at fara út...", // Str::ExitInfoMessage
    "Ger bert virkið, um innihaldið", // Str::PlainTextModeMessage_FirstLine
    "í fíluni er vanligur tekstur", // Str::PlainTextModeMessage_SecondLine
    "Bronglaða fílan verður goymd", // Str::DefaultCipherModeText_FirstLine
    "sum prentilig tekn", // Str::DefaultCipherModeText_SecondLine
    "Bronglaða fílan verður goymd", // Str::OpenSSLCipherModeText_FirstLine
    "í binerum sniði, samhæft við OpenSSL", // Str::OpenSSLCipherModeText_SecondLine
    "PBKDF2-endurtøkur:", // Str::PBKDF2IterationsText
    // Errors
    "Feilur: skeivir parametrar", // Str::WrongParamsText
    "Móttikið virði", // Str::InputValueText
    "Móttikin leið", // Str::InputPathText
    "Ikki bar til at umrokna móttikna virðið til eitt tal størri enn ella javnt við 0", // Str::WrongNumberValueMessage
    "Móttikna leiðin samsvarar ikki við nakra verandi fílu", // Str::WrongPathValueMessage
    "Innslegni møguleikin verður ikki viðurkendur sum galdandi parametur", // Str::InvalidOptionMessage
    "Innsleginn møguleiki", // Str::EnteredOptionText
    "Ókent undantak", // Str::UnknownExceptionText
    "Ikki bar til at byrja GLFW", // Str::GLFWErrorMessage
    "Ikki bar til at byrja GLAD", // Str::GLADErrorMessage
    "Feilur: Ikki bar til at lata fíluna upp at lesa", // Str::ReadFileErrorMessage
    "Feilur við lesing av innihaldinum í fíluni", // Str::ErrorWhileReadingMessage
    "Feilur: Ikki bar til at lata fíluna upp at skriva", // Str::WriteFileErrorMessage
    "Feilur: Sekstantalsstrongurin má hava eitt javnt tal av teknum", // Str::HexStringErrorMessage
    "Feilur: Ógildugt sekstantalstekn í stronginum", // Str::InvalidHexCharacterErrorMessage
    "Feilur: Ikki bar til at goyma fíluna", // Str::SaveFileErrorMessage
    "Feilur: Ikki bar til at innlesa fíluna", // Str::LoadFileErrorMessage
    "Feilur: Ógildugt fílusnið (5 teigar væntaðir: ciphertext|iv|salt|iterations|mac)", // Str::InvalidFileFormatErrorMessage
    "Feilur: Talið av endurtøkum fer upp um ásetta hámarkið (10.000.000)", // Str::MaxIterationsErrorMessage
    "Feilur: Heildarkanningin miseydnaðist, skeivt loyniorð ella skadd/broytt fíla", // Str::IntegrityCheckErrorMessage
    "Feilur: Loyniorðið kann ikki vera tómt", // Str::EmptyPasswordErrorMessage
    "Feilur: Leiðin til málfíluna er ein mappa", // Str::OutputFileIsDirectoryErrorMessage
    "Feilur: Leiðin til keldufíluna er ein mappa", // Str::InputFileIsDirectoryErrorMessage
    "Feilur: Leiðin til málfíluna kann ikki vera tóm", // Str::EmptyOutputFilePathErrorMessage
    "Feilur: Leiðin til keldufíluna kann ikki vera tóm", // Str::EmptyInputFilePathErrorMessage
    "Feilur: Keldufílan finst ikki", // Str::SourceFileDoesNotExistErrorMessage
    // Misc
    "Mál: Føroyskt", // Str::LanguageLabel
    "Loyniorð", // Str::PasswordLabel
    "Longd á loyniorði", // Str::PasswordLenghtLabel
    "Fíla", // Str::FileLabel
    "Fílan", // Str::TheFileLabel
    "Leið", // Str::PathLabel
    "Inntaksleið", // Str::InputFilePathLabel
    "Úttaksleið", // Str::OutputFilePathLabel
    "Být um leiðir", // Str::SwapPathsLabel
    "verður skrivað yvir", // Str::WillBeOverwrittenLabel
    "Bronglar...", // Str::EncryptingText
    "Avbronglar...", // Str::DecryptingText
    "Brongla", // Str::EncryptText
    "Avbrongla", // Str::DecryptText
    "Fílan er bronglað", // Str::FileEncryptedMessage
    "Fílan er avbronglað", // Str::FileDecryptedMessage
    "Ávaring!", // Str::WarningTitle
    "Ert tú vísur?", // Str::AreYouSureTitle
    "Stillingar", // Str::SettingsTitle
    "Loyniorðsgerð", // Str::GeneratePasswordTitle
    "Vel mál", // Str::SelectLanguageTitle
    "Ja", // Str::YesLabel
    "Nei", // Str::NoLabel
    "Í lagi", // Str::OkLabel
    "Úttakssnið", // Str::OutFormatLabel
    "Stillingar fyri markamót", // Str::InterfaceSettingsLabel
    "Stødd", // Str::InterfaceSizeLabel
    "Støða", // Str::ModeLabel
    "Vanlig", // Str::NormalModeLabel
    "Vanligur tekstur", // Str::PlaintextModeLabel
    "Tema", // Str::InterfaceThemeLabel
    "Litur", // Str::InterfaceColorLabel
    "Sjálvvirði (vanligur tekstur)", // Str::DefaultLabel
    "OpenSSL (binert)", // Str::OpenSSLLabel
    "Brúka hetta loyniorðið", // Str::UsePasswordLabel
    "Avrita", // Str::CopyLabel
    "Ctrl + vinstraklikk fyri at fáa SHA256", // Str::GetSHA256Text
    // Themes
    "Ljóst", // Str::LightThemeName
    "Myrkt", // Str::DarkThemeName
    // Colors
    "Blátt", // Str::BlueName
    "Blágrønt", // Str::CyanName
    "Grønt", // Str::GreenName
    "Limegrønt", // Str::LimeName
    "Gult", // Str::YellowName
    "Brúnt", // Str::BrownName
    "Appelsingult", // Str::OrangeName
    "Reytt", // Str::RedName
    "Ljósareytt", // Str::PinkName
    "Fjólublátt", // Str::PurpleName
    "Grátt", // Str::GreyName
    "Hvítt", // Str::WhiteName
    "Svart", // Str::BlackName

};
static_assert(sizeof(textosFO) / sizeof(textosFO[0]) == N,
    "Faltan o sobran textos en feroes: revisa que coincidan con Str::Count.");


// Matriz idioma x clave. El acceso sigue siendo O(1) real: dos
// indexaciones directas, sin hashing.
const std::array<std::array<std::string, N>, L>& Diccionario()
{
    static const std::array<std::array<std::string, N>, L> diccionario = [] {
        std::array<std::array<std::string, N>, L> arr;
        for (size_t i = 0; i < N; ++i) {
            arr[static_cast<size_t>(Language::English)][i] = textosEN[i];
            arr[static_cast<size_t>(Language::Spanish)][i] = textosES[i];
            arr[static_cast<size_t>(Language::ChineseSimplified)][i] = textosZH_HANS[i];
            arr[static_cast<size_t>(Language::French)][i] = textosFR[i];
            arr[static_cast<size_t>(Language::Portuguese)][i] = textosPT[i];
            arr[static_cast<size_t>(Language::Russian)][i] = textosRU[i];
            arr[static_cast<size_t>(Language::Indonesian)][i] = textosID[i];
            arr[static_cast<size_t>(Language::German)][i] = textosDE[i];
            arr[static_cast<size_t>(Language::Japanese)][i] = textosJA[i];
            arr[static_cast<size_t>(Language::Turkish)][i] = textosTR[i];
            arr[static_cast<size_t>(Language::Vietnamese)][i] = textosVI[i];
            arr[static_cast<size_t>(Language::Filipino)][i] = textosFIL[i];
            arr[static_cast<size_t>(Language::Swahili)][i] = textosSW[i];
            arr[static_cast<size_t>(Language::Hausa)][i] = textosHA[i];
            arr[static_cast<size_t>(Language::Korean)][i] = textosKO[i];
            arr[static_cast<size_t>(Language::Javanese)][i] = textosJV[i];
            arr[static_cast<size_t>(Language::Italian)][i] = textosIT[i];
            arr[static_cast<size_t>(Language::Malay)][i] = textosMS[i];
            arr[static_cast<size_t>(Language::Amharic)][i] = textosAM[i];
            arr[static_cast<size_t>(Language::Yoruba)][i] = textosYO[i];
            arr[static_cast<size_t>(Language::Oromo)][i] = textosOM[i];
            arr[static_cast<size_t>(Language::Sundanese)][i] = textosSU[i];
            arr[static_cast<size_t>(Language::Polish)][i] = textosPL[i];
            arr[static_cast<size_t>(Language::Lingala)][i] = textosLN[i];
            arr[static_cast<size_t>(Language::Ukrainian)][i] = textosUK[i];
            arr[static_cast<size_t>(Language::Fula)][i] = textosFF[i];
            arr[static_cast<size_t>(Language::ChineseTraditional)][i] = textosZH_HANT[i];
            arr[static_cast<size_t>(Language::Uzbek)][i] = textosUZ[i];
            arr[static_cast<size_t>(Language::Igbo)][i] = textosIG[i];
            arr[static_cast<size_t>(Language::Zulu)][i] = textosZU[i];
            arr[static_cast<size_t>(Language::Cebuano)][i] = textosCEB[i];
            arr[static_cast<size_t>(Language::Dutch)][i] = textosNL[i];
            arr[static_cast<size_t>(Language::Malagasy)][i] = textosMG[i];
            arr[static_cast<size_t>(Language::Romanian)][i] = textosRO[i];
            arr[static_cast<size_t>(Language::Azerbaijani)][i] = textosAZ[i];
            arr[static_cast<size_t>(Language::Somali)][i] = textosSO[i];
            arr[static_cast<size_t>(Language::Wolof)][i] = textosWO[i];
            arr[static_cast<size_t>(Language::Xhosa)][i] = textosXH[i];
            arr[static_cast<size_t>(Language::Afrikaans)][i] = textosAF[i];
            arr[static_cast<size_t>(Language::Kazakh)][i] = textosKK[i];
            arr[static_cast<size_t>(Language::Kurdish)][i] = textosKMR[i];
            arr[static_cast<size_t>(Language::Kinyarwanda)][i] = textosRW[i];
            arr[static_cast<size_t>(Language::Shona)][i] = textosSN[i];
            arr[static_cast<size_t>(Language::Chichewa)][i] = textosNY[i];
            arr[static_cast<size_t>(Language::Greek)][i] = textosEL[i];
            arr[static_cast<size_t>(Language::Hungarian)][i] = textosHU[i];
            arr[static_cast<size_t>(Language::Swedish)][i] = textosSV[i];
            arr[static_cast<size_t>(Language::HaitianCreole)][i] = textosHT[i];
            arr[static_cast<size_t>(Language::Czech)][i] = textosCS[i];
            arr[static_cast<size_t>(Language::Serbian)][i] = textosSR[i];
            arr[static_cast<size_t>(Language::Catalan)][i] = textosCA[i];
            arr[static_cast<size_t>(Language::Tigrinya)][i] = textosTI[i];
            arr[static_cast<size_t>(Language::Bulgarian)][i] = textosBG[i];
            arr[static_cast<size_t>(Language::Tajik)][i] = textosTG[i];
            arr[static_cast<size_t>(Language::Quechua)][i] = textosQU[i];
            arr[static_cast<size_t>(Language::Albanian)][i] = textosSQ[i];
            arr[static_cast<size_t>(Language::Slovak)][i] = textosSK[i];
            arr[static_cast<size_t>(Language::Turkmen)][i] = textosTK[i];
            arr[static_cast<size_t>(Language::Armenian)][i] = textosHY[i];
            arr[static_cast<size_t>(Language::Guarani)][i] = textosGN[i];
            arr[static_cast<size_t>(Language::Croatian)][i] = textosHR[i];
            arr[static_cast<size_t>(Language::Danish)][i] = textosDA[i];
            arr[static_cast<size_t>(Language::Finnish)][i] = textosFI[i];
            arr[static_cast<size_t>(Language::Kyrgyz)][i] = textosKY[i];
            arr[static_cast<size_t>(Language::Norwegian)][i] = textosNB[i];
            arr[static_cast<size_t>(Language::Belarusian)][i] = textosBE[i];
            arr[static_cast<size_t>(Language::Tatar)][i] = textosTT[i];
            arr[static_cast<size_t>(Language::Georgian)][i] = textosKA[i];
            arr[static_cast<size_t>(Language::Mongolian)][i] = textosMN[i];
            arr[static_cast<size_t>(Language::Bosnian)][i] = textosBS[i];
            arr[static_cast<size_t>(Language::Galician)][i] = textosGL[i];
            arr[static_cast<size_t>(Language::Lithuanian)][i] = textosLT[i];
            arr[static_cast<size_t>(Language::Slovenian)][i] = textosSL[i];
            arr[static_cast<size_t>(Language::Latvian)][i] = textosLV[i];
            arr[static_cast<size_t>(Language::Macedonian)][i] = textosMK[i];
            arr[static_cast<size_t>(Language::Irish)][i] = textosGA[i];
            arr[static_cast<size_t>(Language::Estonian)][i] = textosET[i];
            arr[static_cast<size_t>(Language::Esperanto)][i] = textosEO[i];
            arr[static_cast<size_t>(Language::Basque)][i] = textosEU[i];
            arr[static_cast<size_t>(Language::Welsh)][i] = textosCY[i];
            arr[static_cast<size_t>(Language::Luxembourgish)][i] = textosLB[i];
            arr[static_cast<size_t>(Language::Maltese)][i] = textosMT[i];
            arr[static_cast<size_t>(Language::Icelandic)][i] = textosIS[i];
            arr[static_cast<size_t>(Language::Faroese)][i] = textosFO[i];
        }
        return arr;
    }();
    return diccionario;
}

} // namespace

const std::string& T(Str id, Language lang)
{
    return Diccionario()[static_cast<size_t>(lang)][static_cast<size_t>(id)];
}

const std::string& T(Str id)
{
    return T(id, currentLanguage);
}
