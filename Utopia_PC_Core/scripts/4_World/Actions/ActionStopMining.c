class ActionStopMining : ActionInteractBase
{
    void ActionStopMining()
    {
        m_Text = "Stop Mining";
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
        
        if (desk && desk.GetCompEM().IsWorking() && desk.m_IsPCRunning && desk.IsAnyMiningActive())
        {
            return true; // Stop mining condition
        }
        return false;
    }

    override void OnExecuteServer(ActionData action_data)
    {
        Utopia_Desk desk = Utopia_Desk.Cast(action_data.m_Target.GetObject());
        if (desk)
        {
            // Stop mining for all active coins
            foreach (string coinName, bool isMiningActive : desk.m_CoinMiningStatus)
            {
                if (isMiningActive)
                {
                    desk.StopMining(coinName); // Pass the coin name to StopMining
                }
            }
        }
    }
}
