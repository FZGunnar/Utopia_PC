class BaseCameraSettings
{
    float cameraBatteryPerCentConsumptionPerSec = 0.5;

    void TutorialDefaultSettings()
    {
        //default rooms
        Save();
    }

    void Save()
    {
        //save json file
        JsonFileLoader<BaseCameraSettings>.JsonSaveFile(BASE_CAMERA_CONFIG_FILE, this);
    }

    static void MakeDirectoryIfNotExist()
    {
        if(!FileExist(BASE_CAMERA_ROOT_FOLDER)){
            MakeDirectory(BASE_CAMERA_ROOT_FOLDER);
        }

        if(!FileExist(BASE_CAMERA_CONFIG_FOLDER)){
            MakeDirectory(BASE_CAMERA_CONFIG_FOLDER);
        }
    }

    static BaseCameraSettings Load()
    {
        BaseCameraSettings settings = new BaseCameraSettings();

        MakeDirectoryIfNotExist();

        if(FileExist(BASE_CAMERA_CONFIG_FILE))
        {
            JsonFileLoader<BaseCameraSettings>.JsonLoadFile(BASE_CAMERA_CONFIG_FILE, settings);
            return settings;
        }

        settings.TutorialDefaultSettings();
        return settings;
    }
}