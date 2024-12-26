class UtopiaPcLoggingSettings 
{
    int logLevel = 1;
    int refreshRateInSeconds = 60;

    void MakeDirectoryIfNotExists()
    {
        if(!FileExist(UTOPIA_PC_ROOT_FOLDER))
            MakeDirectory(UTOPIA_PC_ROOT_FOLDER);

        if(!FileExist(UTOPIA_PC_LOG_FOLDER))
            MakeDirectory(UTOPIA_PC_LOG_FOLDER);

        if(!FileExist(UTOPIA_PC_LOGGER_CONFIG_DIR))
            MakeDirectory(UTOPIA_PC_LOGGER_CONFIG_DIR);
        
        if(!FileExist(UTOPIA_PC_LOGGER_LOG_DIR))
            MakeDirectory(UTOPIA_PC_LOGGER_LOG_DIR);
    }

    void Save()
    {
        JsonFileLoader<UtopiaPcLoggingSettings>.JsonSaveFile(UTOPIA_PC_LOGGER_CONFIG_FILE, this);
    }

    static ref UtopiaPcLoggingSettings Load()
    {
        UtopiaPcLoggingSettings settings = new UtopiaPcLoggingSettings();

        settings.MakeDirectoryIfNotExists();

        if(FileExist(UTOPIA_PC_LOGGER_CONFIG_FILE))
        {
            JsonFileLoader<UtopiaPcLoggingSettings>.JsonLoadFile(UTOPIA_PC_LOGGER_CONFIG_FILE, settings);
            return settings;
        }

        settings.Save();
        return settings;
    }

}