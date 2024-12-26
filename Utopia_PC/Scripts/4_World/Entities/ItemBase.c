modded class ItemBase extends InventoryItem
{
    override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		return true;
	}
	
	override bool CanLoadAttachment( EntityAI attachment )
	{				
		return true;
	}
};

modded class ItemBase 
{
	bool IsSIlenceFacingPlayer( PlayerBase player)
	{
		vector fence_pos = GetPosition();
		vector player_pos = player.GetPosition();
		vector ref_dir = GetDirection();
		
		//vector fence_player_dir = player_pos - fence_pos;
		vector fence_player_dir = player.GetDirection();
		fence_player_dir.Normalize();
		fence_player_dir[1] = 0; 	//ignore height
		
		ref_dir.Normalize();
		ref_dir[1] = 0;			//ignore height
		
		if ( ref_dir.Length() != 0 )
		{
			float angle = Math.Acos( fence_player_dir * ref_dir );
			
			if ( angle >= 1.3 )
			{
				return true;
			}
		}
		
		return false;
	}
	
	vector Get_ItemPlacingPos()
	{
		if(ConfigIsExisting("itemPlacingPos"))
			return ConfigGetVector("itemPlacingPos");		
		return "0 0 0";
	}

	vector Get_ItemPlacingOrientation()
	{
		if(ConfigIsExisting("itemPlacingOri"))
			return ConfigGetVector("itemPlacingOri");		
		return "0 0 0";
	}
	
	string Get_ItemName()
	{
		if(ConfigIsExisting("kitItemName"))
			return ConfigGetString("kitItemName");
		return GetType().Substring(0,GetType().Length() - 4);
	}

	string Get_KitName()
	{
		if(ConfigIsExisting("kitName"))
			return ConfigGetString("kitName");
		return GetType() + "_Kit";
	}

	bool IsInvEmpty()
	{   
		if (GetNumberOfItems() < 1 &&  GetInventory().AttachmentCount() < 1)
		{
			return true;
		}
		return false;
	}
};