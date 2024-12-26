modded class MissionServer extends MissionBase
{
	void ~MissionServer() {
	}

	void MissionServer()
	{
		Print("Template mod has started !");

		GetRPCManager().AddRPC("BaseCamera", "SwitchBaseCameraRequest", this, SingeplayerExecutionType.Server);
	}

	void SwitchBaseCameraRequest(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if(type != CallType.Server)
            return;

        Param2<BaseCamera, bool> data;
        if (!ctx.Read(data))
            return;

        BaseCamera camera = data.param1;
		bool turnOn = data.param2;

		GetBaseCameraLogger().LogDebug("SwitchBaseCameraRequest: state: " + turnOn);

		if(!camera)
		{
			GetBaseCameraLogger().LogDebug("!camera");
			return;
		}
			

        if(turnOn && camera.GetCompEM().CanWork())
		{
			GetBaseCameraLogger().LogDebug("turnOn");
			camera.GetCompEM().SwitchOn();
			return;
		}

		if(camera.GetCompEM().CanSwitchOff())
		{
			camera.GetCompEM().SwitchOff();
			GetBaseCameraLogger().LogDebug("turnOff");
		}

		
    }
};
