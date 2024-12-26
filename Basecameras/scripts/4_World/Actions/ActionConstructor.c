modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(ActionOpenCameraMenu);
        actions.Insert(ActionRegisterLaptopForCamera);
        actions.Insert( ActionTurnOnUtopiaPC );
		actions.Insert( ActionTurnOffUtopiaPC );
    }
}
