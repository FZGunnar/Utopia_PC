modded class Hologram
{
	override void EvaluateCollision(ItemBase action_item = null)
    {
        ItemBase itemInHand = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if(!itemInHand)
		{
			super.EvaluateCollision();
			return;
		}
        
        if (itemInHand.IsKindOf("Utopia_CCTV"))
        {
            SetIsColliding(false);
            return;
        }
        
        super.EvaluateCollision();
    }
}