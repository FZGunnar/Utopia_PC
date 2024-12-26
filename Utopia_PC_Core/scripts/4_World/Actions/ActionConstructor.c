modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert( ActionTurnOnUtopiaPC );
		actions.Insert( ActionTurnOffUtopiaPC );
        actions.Insert( ActionUnpackDeskBox);
        actions.Insert( ActionDismantleUtopia_Desk);
        actions.Insert( ActionDismantleUtopiaPCDeskHologram);
        actions.Insert( ActionBuildUtopiaDesk);
        actions.Insert( ActionStartMining);
        actions.Insert( ActionStopMining);
        actions.Insert( ActionWithdrawCrypto);
    }
}
