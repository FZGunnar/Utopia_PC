class ActionStartMining : ActionInteractBase
{
    void ActionStartMining()
    {
        m_Text = "Start Mining";
    }

    override void CreateConditionComponents()  
    {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTNonRuined;
    }

    override string GetText()
    {
        return m_Text;
    }


    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        Utopia_Desk desk = Utopia_Desk.Cast(target.GetObject());
        
        if (desk && desk.GetCompEM().IsWorking() && !desk.m_IsShuttingDown && !desk.IsAnyMiningActive())
        {
            return true; // Start mining condition
        }
        return false;
    }

    override void OnExecuteServer(ActionData action_data)
    {
        Utopia_Desk desk = Utopia_Desk.Cast(action_data.m_Target.GetObject());
        if (desk)
        {
            desk.StartMining(); // Start mining using the desk’s configuration
        }
    }
}
