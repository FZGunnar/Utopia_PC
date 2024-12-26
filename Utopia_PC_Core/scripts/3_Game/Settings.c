class UtopiaPcSettings
{
    string version = UTOPIA_PC_VERSION;
    ref array<ref UtopiaGraphicCardLifetime> graphicCardLifetimes;
    ref map<string, ref UtopiaCoinSettings> coinSettings;

    void UtopiaPcSettings()
    {
        graphicCardLifetimes = new array<ref UtopiaGraphicCardLifetime>();
        coinSettings = new map<string, ref UtopiaCoinSettings>();
    }

    void LoadDefaultSettings()
    {
        // Load default graphic card lifetimes
        graphicCardLifetimes.Insert(new UtopiaGraphicCardLifetime("Utopia_Graphics_Card_660", 7200));
        graphicCardLifetimes.Insert(new UtopiaGraphicCardLifetime("Utopia_Graphics_Card_1080TI", 14400));
        graphicCardLifetimes.Insert(new UtopiaGraphicCardLifetime("Utopia_RTX_2080TI", 21600));
        graphicCardLifetimes.Insert(new UtopiaGraphicCardLifetime("Utopia_Graphics_Card_4090TI", 28800));

        // Load default coins (can be overridden via the config file)
        InsertDefaultCoinSettings();

        Save();
    }

    void InsertDefaultCoinSettings()
    {
        // Example for Bitcoin with different settings per GPU
        map<string, float> bitcoinHashRates = new map<string, float>();
        bitcoinHashRates.Insert("Utopia_Graphics_Card_1080TI", 10);
        bitcoinHashRates.Insert("Utopia_RTX_2080TI", 8);

        map<string, float> bitcoinYields = new map<string, float>();
        bitcoinYields.Insert("Utopia_Graphics_Card_1080TI", 0.1); // 0.1 Bitcoin per cycle for 1080TI
        bitcoinYields.Insert("Utopia_RTX_2080TI", 0.15); // 0.15 Bitcoin per cycle for 2080TI

        map<string, float> bitcoinDamageRates = new map<string, float>();
        bitcoinDamageRates.Insert("Utopia_Graphics_Card_1080TI", 0.001); // Damage rate for 1080TI
        bitcoinDamageRates.Insert("Utopia_RTX_2080TI", 0.002); // Damage rate for 2080TI

        coinSettings.Insert("Bitcoin", new UtopiaCoinSettings("Bitcoin", bitcoinHashRates, bitcoinYields, bitcoinDamageRates, "Bitcoin_Item"));

        // Repeat similarly for other coins...
    }



    UtopiaCoinSettings GetCoinSettings(string coinName)
    {
        return coinSettings.Get(coinName);
    }

    void Save()
    {
        JsonFileLoader<UtopiaPcSettings>.JsonSaveFile(UTOPIA_PC_CONFIG_FILE, this);
    }

    static UtopiaPcSettings Load()
    {
        UtopiaPcSettings settings = new UtopiaPcSettings();
        EnsureDirectoriesExist();

        if (FileExist(UTOPIA_PC_CONFIG_FILE))
        {
            JsonFileLoader<UtopiaPcSettings>.JsonLoadFile(UTOPIA_PC_CONFIG_FILE, settings);
            return settings;
        }

        settings.LoadDefaultSettings();
        return settings;
    }

    static void EnsureDirectoriesExist()
    {
        if (!FileExist(UTOPIA_PC_ROOT_FOLDER))
        {
            MakeDirectory(UTOPIA_PC_ROOT_FOLDER);
        }
        if (!FileExist(UTOPIA_PC_CONFIG_FOLDER))
        {
            MakeDirectory(UTOPIA_PC_CONFIG_FOLDER);
        }
        if (!FileExist(UTOPIA_PC_LOG_FOLDER))
        {
            MakeDirectory(UTOPIA_PC_LOG_FOLDER);
        }
    }

    int FindLifetimeForClassName(string className)
    {
        foreach(UtopiaGraphicCardLifetime graphicCardLifetime : graphicCardLifetimes)
        {
            if (CF_String.EqualsIgnoreCase(graphicCardLifetime.className, className))
                return graphicCardLifetime.lifetime;
        }
        return 0;
    }
}


class UtopiaCoinSettings
{
    string coinName;                     // Name of the cryptocurrency
    ref map<string, float> hashRates;    // Hash rates per GPU type for mining this coin
    ref map<string, float> yields;       // Coin yield per GPU type
    ref map<string, float> damageRates;  // Damage amount per GPU type
    string itemClass;                    // The class name of the item representing this coin in the game

    void UtopiaCoinSettings(string name, map<string, float> rates, map<string, float> yieldsMap, map<string, float> damageMap, string item)
    {
        coinName = name;
        hashRates = rates;
        yields = yieldsMap;
        damageRates = damageMap;
        itemClass = item;
    }

    float GetHashRate(string cardType)
    {
        return hashRates.Get(cardType);
    }

    float GetYield(string cardType)
    {
        return yields.Get(cardType);
    }

    float GetDamageRate(string cardType)
    {
        return damageRates.Get(cardType);
    }

    bool CanCardMine(string cardType)
    {
        return hashRates.Contains(cardType);
    }
}

