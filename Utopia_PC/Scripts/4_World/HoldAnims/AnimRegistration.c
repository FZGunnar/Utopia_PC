modded class ModItemRegisterCallbacks
{
    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		super.RegisterHeavy(pType, pBehavior);
        pType.AddItemInHandsProfileIK("Utopia_Desk_Box", 	            "dz/anims/workspaces/player/player_main/player_main_heavy.asi",	pBehavior,	"dz/anims/anm/player/ik/heavy/wooden_crate.anm");
        pType.AddItemInHandsProfileIK("Utopia_Filament_Holder_Kit", 	"dz/anims/workspaces/player/player_main/player_main_heavy.asi",	pBehavior,	"dz/anims/anm/player/ik/heavy/wooden_crate.anm");
        pType.AddItemInHandsProfileIK("Utopia_Printer", 	            "dz/anims/workspaces/player/player_main/player_main_heavy.asi",	pBehavior,	"dz/anims/anm/player/ik/heavy/wooden_crate.anm");
        pType.AddItemInHandsProfileIK("Utopia_Mining_Chassis", 	        "dz/anims/workspaces/player/player_main/player_main_heavy.asi",	pBehavior,	"dz/anims/anm/player/ik/heavy/wooden_crate.anm");
        pType.AddItemInHandsProfileIK("Utopia_PC_Case", 	            "dz/anims/workspaces/player/player_main/player_main_heavy.asi",	pBehavior,	"dz/anims/anm/player/ik/heavy/wooden_crate.anm");
        pType.AddItemInHandsProfileIK("Utopia_PC_Desk_Top_1",           "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, 		"dz/anims/anm/player/ik/two_handed/alice_g.anm");
        pType.AddItemInHandsProfileIK("Utopia_PC_Desk_Top_2",           "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, 		"dz/anims/anm/player/ik/two_handed/alice_g.anm");
        pType.AddItemInHandsProfileIK("Utopia_PC_Leg_1",                "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, 		"dz/anims/anm/player/ik/two_handed/alice_g.anm");
        pType.AddItemInHandsProfileIK("Utopia_PC_Leg_2",                "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, 		"dz/anims/anm/player/ik/two_handed/alice_g.anm");
        pType.AddItemInHandsProfileIK("Utopia_PC_Leg_3",                "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, 		"dz/anims/anm/player/ik/two_handed/alice_g.anm");
    }
};