class ActionTurnOnUtopiaPC: ActionInteractBase
{
	void ActionTurnOnUtopiaPC()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Power On";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Utopia_Desk laptop = Utopia_Desk.Cast(target.GetObject());
		
		if (laptop && !laptop.GetCompEM().IsWorking() && !laptop.m_IsShuttingDown && laptop.GetCompEM().IsPlugged() && laptop.GetCompEM().CanWork() && laptop.HasRequiredComponentsForCCTV())
			return true;
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		 GetUtopiaPcLogger().LogDebug("ActionTurnOnUtopiaPC OnExecuteServer");
		Utopia_Desk laptop = Utopia_Desk.Cast(action_data.m_Target.GetObject());
		if(laptop)
			laptop.GetCompEM().SwitchOn();
	}
};
