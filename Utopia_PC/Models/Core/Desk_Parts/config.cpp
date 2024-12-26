class CfgPatches
{
	class Utopia_PC
	{
		units[]=
		{
			"Utopia_Desk_Build",
			"Utopia_PC_Desk_Top_1",
			"Utopia_PC_Desk_Top_2",
			"Utopia_PC_Leg_1",
			"Utopia_PC_Leg_2",
			"Utopia_PC_Leg_3",
			"Utopia_PC_Case"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Utopia_Desk_Build: Inventory_Base
	{
		scope = 2;
		displayName = "Desk Hologram";
		model = "Utopia_PC\Models\Core\Desk_Parts\Desk.p3d";
		alignHologramToTerain = 0;
		slopeTolerance = 0.3;
		physLayer = "item_small";
		itemBehaviour = 2;
		attachments[] = {"Slot_Desk_Top_1","Slot_Desk_Top_2","Slot_Leg_1","Slot_Leg_2","Slot_Leg_3","Slot_PC_Case"};
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name = "PC Materials";
				description = "";
				attachmentSlots[] = {"Slot_Desk_Top_1","Slot_Desk_Top_2","Slot_Leg_1","Slot_Leg_2","Slot_Leg_3","Slot_PC_Case"};
				icon = "set:dayz_inventory image:cat_bb_material";
				selection = "interact_pos";
			};
		};
	};
	class Utopia_PC_Case: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Desk_Parts\PC_Case.p3d";
		displayName = "PC Case Parts";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Slot_PC_Case"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_PC_Desk_Top_1: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Desk_Parts\Desk_Top_1.p3d";
		displayName = "PC Desk_Top_1";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Slot_Desk_Top_1"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_PC_Desk_Top_2: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Desk_Parts\Desk_Top_2.p3d";
		displayName = "PC Desk Top 2";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Slot_Desk_Top_2"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_PC_Leg_1: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Desk_Parts\Leg_1.p3d";
		displayName = "PC Leg 1";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Slot_Leg_1"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_PC_Leg_2: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Desk_Parts\Leg_2.p3d";
		displayName = "PC Leg 2";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Slot_Leg_2"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_PC_Leg_3: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Desk_Parts\Leg_3.p3d";
		displayName = "PC Leg 3";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Slot_Leg_3"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
};
class CfgSlots 
{
	class Slot_PC_Case
    {
        name = "Slot_PC_Case";
        displayName = "PC Case";
        ghostIcon = "set:dayz_inventory image:ico_craft_iron";
    };
	class Slot_Desk_Top_1
    {
        name = "Slot_Desk_Top_1";
        displayName = "Desk Top 1";
        ghostIcon = "set:dayz_inventory image:ico_craft_iron";
    };
    class Slot_Desk_Top_2
    {
        name = "Slot_Desk_Top_2";
        displayName = "Desk Top 2";
        ghostIcon = "set:dayz_inventory image:ico_craft_iron";
    };
    class Slot_Leg_1
    {
        name = "Slot_Leg_1";
        displayName = "Leg 1";
        ghostIcon = "set:dayz_inventory image:ico_craft_iron";
    };
    class Slot_Leg_2
    {
        name = "Slot_Leg_2";
        displayName = "Leg 2";
        ghostIcon = "set:dayz_inventory image:ico_craft_iron";
    };
    class Slot_Leg_3
    {
        name = "Slot_Leg_3";
        displayName = "Leg 3";
        ghostIcon = "set:dayz_inventory image:ico_craft_iron";
    };
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyPC_Case: ProxyAttachment
	{
		inventorySlot[] = {"Slot_PC_Case"};
		model = "Utopia_PC\Models\Core\Desk_Parts\Proxies\PC_Case.p3d";
	};
	class ProxyDesk_Top_1: ProxyAttachment
	{
		inventorySlot[] = {"Slot_Desk_Top_1"};
		model = "Utopia_PC\Models\Core\Desk_Parts\Proxies\Desk_Top_1.p3d";
	};
	class ProxyDesk_Top_2: ProxyAttachment
	{
		inventorySlot[] = {"Slot_Desk_Top_2"};
		model = "Utopia_PC\Models\Core\Desk_Parts\Proxies\Desk_Top_2.p3d";
	};
	class ProxyLeg_1: ProxyAttachment
	{
		inventorySlot[] = {"Slot_Leg_1"};
		model = "Utopia_PC\Models\Core\Desk_Parts\Proxies\Leg_1.p3d";
	};
	class ProxyLeg_2: ProxyAttachment
	{
		inventorySlot[] = {"Slot_Leg_2"};
		model = "Utopia_PC\Models\Core\Desk_Parts\Proxies\Leg_2.p3d";
	};
	class ProxyLeg_3: ProxyAttachment
	{
		inventorySlot[] = {"Slot_Leg_3"};
		model = "Utopia_PC\Models\Core\Desk_Parts\Proxies\Leg_3.p3d";
	};
};