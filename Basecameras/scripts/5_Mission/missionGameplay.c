modded class MissionGameplay extends MissionBase
{
	void MissionGameplay()
	{

	}

	override void OnUpdate( float timeslice )
	{
		super.OnUpdate( timeslice );
		if ( GetGame().GetInput().LocalPress( "UAUIBack", false )) {
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
			if(!player)
				return;

			if(!player.iLaptopMenu)
				return;

			player.iLaptopMenu.Close();
		}
	}
};
