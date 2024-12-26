class Utopia_Desk: BaseLaptop 
{
	override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        return false;
    }
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return IsOpen();
	}

	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}

    override bool CanDisplayAttachmentSlot(string slot_name)
	{
		return true;
	}
};