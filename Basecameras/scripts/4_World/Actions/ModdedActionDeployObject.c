modded class ActionPlaceObject
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item )
    {
        BaseCamera camera = BaseCamera.Cast(item);
        if(camera && player.GetRegisteredLaptopId() == -1 && !player.IsLaptopTooFar())
            return false;

        return super.ActionCondition(player, target, item);
    }

    override void OnStartServer(ActionData action_data)
	{
        super.OnStartServer(action_data);

        BaseCamera camera = BaseCamera.Cast(action_data.m_MainItem);
        if(!camera)
            return;

        GetBaseCameraLogger().LogDebug("PlaceCamera:OnStartServer");
        camera.SetLaptopId(action_data.m_Player.GetRegisteredLaptopId());
    }
}