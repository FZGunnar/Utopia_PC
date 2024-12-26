class ActionOpenCameraMenu: ActionInteractBase
{
	void ActionOpenCameraMenu()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Access Camera Menu";
    }

	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		BaseLaptop laptop = BaseLaptop.Cast(target.GetObject());
		if(laptop && laptop.GetCompEM().IsWorking())
			return true;

		return false;
	}

	override void OnStartClient(ActionData action_data)
	{
		OpenLaptopMenu(ItemBase.Cast(action_data.m_Target.GetObject()));
	}

	void OpenLaptopMenu(ItemBase item)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if ( g_Game.GetUIManager().GetMenu() == NULL )
		{
			player.iLaptopMenu = new ILaptopMenu();
			player.iLaptopMenu.SetLaptop(BaseLaptop.Cast(item));
			GetGame().GetUIManager().ShowScriptedMenu( player.iLaptopMenu, NULL );
			player.iLaptopMenu.InitLoading();
		}
	}
};
