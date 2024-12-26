const string UTOPIA_PC_ROOT_FOLDER = "$profile:Utopia_PC\\";
const string UTOPIA_PC_CONFIG_FOLDER = UTOPIA_PC_ROOT_FOLDER + "Config\\";
const string UTOPIA_PC_CONFIG_FILE = UTOPIA_PC_CONFIG_FOLDER + "UtopiaPcSettings.json";


const string UTOPIA_PC_LOG_FOLDER = UTOPIA_PC_ROOT_FOLDER + "Logging\\";
const string UTOPIA_PC_LOGGER_CONFIG_DIR = UTOPIA_PC_LOG_FOLDER + "Config\\";
const string UTOPIA_PC_LOGGER_CONFIG_FILE = UTOPIA_PC_LOGGER_CONFIG_DIR + "LoggingSettings.json";
const string UTOPIA_PC_LOGGER_LOG_DIR = UTOPIA_PC_LOG_FOLDER + "Logs\\";
const string UTOPIA_PC_LOGGER_LOG_FILE = UTOPIA_PC_LOGGER_LOG_DIR + "UtopiaPc_%1.log";

const string UTOPIA_PC_VERSION = "1.0";

ref TStringArray g_UtopiaPcGraphicCardSlots = {
    "Graphics_Card_2",
	"Graphics_Card_1",
	"Graphics_Card_3",
};