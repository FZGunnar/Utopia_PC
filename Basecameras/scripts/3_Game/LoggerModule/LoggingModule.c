
static ref BaseCameraLoggingModule GetBaseCameraLogger()
{
    return BaseCameraLoggingModule.Cast(CF_ModuleCoreManager.Get(BaseCameraLoggingModule));
}

[CF_RegisterModule(BaseCameraLoggingModule)]
class BaseCameraLoggingModule : CF_ModuleGame
{
    private int networkSync_LogLevel;

    ref BaseCameraLoggingSettings settings;

    FileHandle fileHandle;

    float dtime = 0;

    float dtimeTemp = 0;


    override void OnInit()
    {
        super.OnInit();
        
        EnableUpdate();
        EnableMissionStart();
    }

    override void OnMissionStart(Class sender, CF_EventArgs args)
    {
        super.OnMissionStart(sender, args);

        fileHandle = CreateNewLogFile();

        if(GetGame().IsServer())
        {
            settings = BaseCameraLoggingSettings.Load();

            networkSync_LogLevel = settings.logLevel;
            SynchLogLevel();       
        }
        else
        {
            AddLegacyRPC("GetLogLevelResponse", SingleplayerExecutionType.Client);
        }
    }

    void GetLogLevelResponse(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		 if (type != CallType.Client)
			 return;

		 Param1<int> data;
		 if (!ctx.Read(data))
            return;

		 networkSync_LogLevel = data.param1;
	}

    void SynchLogLevel()
    {
        GetRPCManager().SendRPC(ClassName(), "GetLogLevelResponse",  new Param1<int>(networkSync_LogLevel), true, NULL);
    }

    override void OnUpdate(Class sender, CF_EventArgs args)
    {
        auto update = CF_EventUpdateArgs.Cast(args);

        dtime += update.DeltaTime;
        dtimeTemp += update.DeltaTime;

        if(GetGame().IsServer() && settings && dtime >= settings.refreshRateInSeconds)
        {
            dtime = 0;

            settings = BaseCameraLoggingSettings.Load();

            networkSync_LogLevel = settings.logLevel;
            SynchLogLevel();
        }
    }


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
    
    string GenerateShortDateString()
    {
        int year, month, day;
        GetYearMonthDay(year, month, day);
        return "" + year + "_" + month + "_" + day;
    }

    string GenerateShortTimeString()
    {
        int hour, minute, second;
        GetHourMinuteSecond(hour, minute, second);
        return "" + hour + "_" + minute + "_" + second;
    }

    string GenerateFullTimestamp()
    {
        string dateStr = GenerateShortDateString();
        string timeStr = GenerateShortTimeString();

        return dateStr + "-" + timeStr;
    }

    FileHandle CreateNewLogFile()
    {
        MakeDirectoryIfNotExists();

        string filePath = string.Format(BASE_CAMERA_LOGGER_LOG_FILE, GenerateFullTimestamp());

        fileHandle = OpenFile(filePath, FileMode.WRITE);

        if(fileHandle != 0)
        {
            FPrintln(fileHandle, "Creation Time: " + GenerateFullTimestamp());
            return fileHandle;
        }

        return null;
    }

    void Log(string content, BaseCameraLogLevel logLevel)
    {
        if(logLevel < networkSync_LogLevel)
            return;
        
        string timestamp = GenerateShortTimeString();
        FPrintln(fileHandle, timestamp + " | " + GetLogLevelString(logLevel) + " | " + content);
    }

    void LogInfo(string content)
    {
        Log(content, BaseCameraLogLevel.Info);
    }

    void LogWarning(string content)
    {
        Log(content, BaseCameraLogLevel.Warn);
    }

    void LogError(string content)
    {
        Log(content, BaseCameraLogLevel.Error);
    }

    void LogDebug(string content)
    {
        Log(content, BaseCameraLogLevel.Debug);
    }

    string GetLogLevelString(BaseCameraLogLevel logLevel)
    {
        switch(logLevel)
        {
             case BaseCameraLogLevel.Debug:
                return "DEBUG";
            case BaseCameraLogLevel.Info:
                return "INFO";
            case BaseCameraLogLevel.Warn:
                return "WARNING";
            case BaseCameraLogLevel.Error:
                return "ERROR";
            default:
                return "";
        }

        return "";
    }

}