class ActionWithdrawCrypto : ActionInteractBase
{
    void ActionWithdrawCrypto()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
    }

    override string GetText()
    {
        return "Withdraw Cryptocurrency";
    }

    override void CreateConditionComponents()  
    { 
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTSelf;
    }

    override bool HasTarget()
    {
        return false;
    }

    override void OnExecuteServer(ActionData action_data)
    {
        PlayerBase player = PlayerBase.Cast(action_data.m_Player);
        if (player)
        {
            Utopia_Desk desk = Utopia_Desk.Cast(action_data.m_Target.GetObject());
            if (desk)
            {
                desk.WithdrawCoins(player);
            }
        }
    }
}
