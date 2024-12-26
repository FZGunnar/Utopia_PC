class Utopia_Desk_Box : ItemBase
{
    override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
    {
        super.OnPlacementComplete(player, position, orientation);
        SetIsPlaceSound(true);
    }
    
    override string GetPlaceSoundset()
    {
        return "placeBarrel_SoundSet";
    }
    
    override bool IsDeployable()
    {
        return true;
    }
    
    override bool IsTwoHandedBehaviour() 
    {
        return true;
    }
    
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionUnpackDeskBox);
    }
}
