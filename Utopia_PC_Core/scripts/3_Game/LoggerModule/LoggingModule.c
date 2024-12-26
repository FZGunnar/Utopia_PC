
static ref UtopiaPcLoggingModule GetUtopiaPcLogger()
{
    return UtopiaPcLoggingModule.Cast(CF_ModuleCoreManager.Get(UtopiaPcLoggingModule));
}

[CF_RegisterModule(UtopiaPcLoggingModule)]
class UtopiaPcLoggingModule : CF_ModuleGame
{
    private int networkSync_LogLevel;

    ref UtopiaPcLoggingSettings settings;

    FileHandle fileHandle;

    float dtime = 0;


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
            settings = UtopiaPcLoggingSettings.Load();

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

        if(!GetGame().IsServer())
            return;

        if(!settings)
            return;

        dtime += update.DeltaTime;
        if(dtime >= settings.refreshRateInSeconds)
        {
            dtime = 0;

            settings = UtopiaPcLoggingSettings.Load();

            networkSync_LogLevel = settings.logLevel;
            SynchLogLevel();
        }
    }


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

        string filePath = string.Format(UTOPIA_PC_LOGGER_LOG_FILE, GenerateFullTimestamp());

        fileHandle = OpenFile(filePath, FileMode.WRITE);

        if(fileHandle != 0)
        {
            FPrintln(fileHandle, "Creation Time: " + GenerateFullTimestamp());
            return fileHandle;
        }

        return null;
    }

    void Log(string content, UtopiaPcLogLevel logLevel)
    {
        if(logLevel < networkSync_LogLevel)
            return;
        
        string timestamp = GenerateShortTimeString();
        FPrintln(fileHandle, timestamp + " | " + GetLogLevelString(logLevel) + " | " + content);
    }

    void LogInfo(string content)
    {
        Log(content, UtopiaPcLogLevel.Info);
    }

    void LogWarning(string content)
    {
        Log(content, UtopiaPcLogLevel.Warn);
    }

    void LogError(string content)
    {
        Log(content, UtopiaPcLogLevel.Error);
    }

    void LogDebug(string content)
    {
        Log(content, UtopiaPcLogLevel.Debug);
    }

    string GetLogLevelString(UtopiaPcLogLevel logLevel)
    {
        switch(logLevel)
        {
             case UtopiaPcLogLevel.Debug:
                return "DEBUG";
            case UtopiaPcLogLevel.Info:
                return "INFO";
            case UtopiaPcLogLevel.Warn:
                return "WARNING";
            case UtopiaPcLogLevel.Error:
                return "ERROR";
            default:
                return "";
        }

        return "";
    }

}