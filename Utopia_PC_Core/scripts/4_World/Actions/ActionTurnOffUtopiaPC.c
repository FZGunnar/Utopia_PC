class ActionTurnOffUtopiaPC: ActionInteractBase
{
	void ActionTurnOffUtopiaPC()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Power Off";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Utopia_Desk laptop = Utopia_Desk.Cast(target.GetObject());
		if(laptop &&  !laptop.m_IsStarting && laptop.GetCompEM().IsWorking())
			return true;

		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Utopia_Desk laptop = Utopia_Desk.Cast(action_data.m_Target.GetObject());
		if(laptop)
			laptop.GetCompEM().SwitchOff();
	}
}
