class BaseCameraLoggingSettings 
{
    int logLevel = 1;
    int refreshRateInSeconds = 60;

    void MakeDirectoryIfNotExists()
    {
        if(!FileExist(BASE_CAMERA_ROOT_FOLDER))
            MakeDirectory(BASE_CAMERA_ROOT_FOLDER);

        if(!FileExist(BASE_CAMERA_LOG_FOLDER))
            MakeDirectory(BASE_CAMERA_LOG_FOLDER);

        if(!FileExist(BASE_CAMERA_LOGGER_CONFIG_DIR))
            MakeDirectory(BASE_CAMERA_LOGGER_CONFIG_DIR);
        
        if(!FileExist(BASE_CAMERA_LOGGER_LOG_DIR))
            MakeDirectory(BASE_CAMERA_LOGGER_LOG_DIR);
    }

    void Save()
    {
        JsonFileLoader<BaseCameraLoggingSettings>.JsonSaveFile(BASE_CAMERA_LOGGER_CONFIG_FILE, this);
    }

    static ref BaseCameraLoggingSettings Load()
    {
        BaseCameraLoggingSettings settings = new BaseCameraLoggingSettings();

        settings.MakeDirectoryIfNotExists();

        if(FileExist(BASE_CAMERA_LOGGER_CONFIG_FILE))
        {
            JsonFileLoader<BaseCameraLoggingSettings>.JsonLoadFile(BASE_CAMERA_LOGGER_CONFIG_FILE, settings);
            return settings;
        }

        settings.Save();
        return settings;
    }

}