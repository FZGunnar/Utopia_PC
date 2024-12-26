[CF_RegisterModule(UtopiaPcCoreModule)]
class UtopiaPcCoreModule : CF_ModuleWorld
{
    ref UtopiaPcSettings settings;

    override void OnInit()
    {
        super.OnInit();

        EnableInvokeConnect();
        EnableMissionStart();
        EnableUpdate();
    }

    UtopiaPcSettings GetSettings()
    {
        return settings;
    }

    void InitializeModule()
    {
        GetUtopiaPcLogger().LogInfo("Utopia_PC_Core has started");

        if(GetGame().IsServer())
        {
            settings = UtopiaPcSettings.Load();
        }
        else
        {
            settings = new UtopiaPcSettings();
        }

        InitRPCs();
    }

    void InitRPCs()
    {
        //client
        if(GetGame().IsClient())
        {
            GetRPCManager().AddRPC("UtopiaPcSystem", "GetConfigResponse", this, SingeplayerExecutionType.Client);
        }
        else //server
        {
            /*example : Register RPC on the server side
            GetRPCManager().AddRPC("UtopiaPcSystem", "FunctionName", this, SingeplayerExecutionType.Server);
            */
        }
    }

    //RPC Method trigger when the method GetRPCmANA
    void GetConfigResponse(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if(type != CallType.Client)
            return;

        Param1<UtopiaPcSettings> data;
        if(!ctx.Read(data)){
            return;
        }

        settings = data.param1;
    }

    void OnPlayerConnect(PlayerBase player, PlayerIdentity identity)
    {
        GetRPCManager().SendRPC("UtopiaPcSystem", "GetConfigResponse", new Param1<UtopiaPcSettings>(settings), true, identity);
    }

    override void OnInvokeConnect(Class sender, CF_EventArgs args)
    {
        super.OnInvokeConnect(sender, args);

        auto cArgs = CF_EventPlayerArgs.Cast(args);

        if(!IsMissionHost()){
            return;
        }

        if(!cArgs.Player || !cArgs.Identity)
            return;

        OnPlayerConnect(cArgs.Player, cArgs.Identity);
    }

    override void OnMissionStart(Class sender, CF_EventArgs args)
    {
        super.OnMissionStart(sender, args);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(InitializeModule, 1000); 
    }

    override void OnUpdate(Class sender, CF_EventArgs args)
    {
        super.OnUpdate(sender, args);
    }
}

static ref UtopiaPcCoreModule GetUtopiaPcModule()
{
    return UtopiaPcCoreModule.Cast(CF_ModuleCoreManager.Get(UtopiaPcCoreModule));
}

