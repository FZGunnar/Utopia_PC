class ActionRegisterLaptopForCamera: ActionInteractBase
{
	void ActionRegisterLaptopForCamera()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Register PC for placing camera";
    }

	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		BaseLaptop laptop = BaseLaptop.Cast(target.GetObject());
		if(laptop && laptop.HasRequiredComponentsForCCTV() )
			return true;

		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		BaseLaptop laptop = BaseLaptop.Cast(action_data.m_Target.GetObject());
		if(!laptop)
			return;

		action_data.m_Player.SetRegisteredLaptop(laptop);
	}

	override void OnStartClient(ActionData action_data)
	{
		BaseLaptop laptop = BaseLaptop.Cast(action_data.m_Target.GetObject());
		if(!laptop)
			return;

		action_data.m_Player.SetRegisteredLaptop(laptop);
	}
};
