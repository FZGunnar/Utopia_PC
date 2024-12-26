class CfgPatches
{
	class Utopia_PC
	{
		units[]= 
		{
			"Utopia_Desk",
			"Utopia_Desk_manual",
			"Utopia_WiFi_Router",
			"Utopia_Keyboard",
			"Utopia_Monitor",
			"Utopia_Mouse"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class FenceKit;
	class Utopia_Desk_Box_Base: Inventory_Base
	{
		scope=0;
		model="Utopia_PC\Models\Core\Desk_Box\Utopia_Desk_Box.p3d";
		itemSize[]={6,3};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_large";
		rotationFlags = 2;
		weight=5000;
		itemBehaviour=2;
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4"
		};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
	};
	class Utopia_Desk_Box : Utopia_Desk_Box_Base
	{
		scope=2;
		displayName="Desk Box";
		descriptionShort="A Box for building a desk";
		hiddenSelectionsTextures[]=
		{
			"utopia_pc\models\core\desk_box\textures\back_co.paa",
			"utopia_pc\models\core\desk_box\textures\top_co.paa",
			"utopia_pc\models\core\desk_box\textures\label_co.paa",
			"utopia_pc\models\core\desk_box\textures\back_co.paa"
		};
	};
	class Utopia_Desk_Manual_Base: FenceKit
	{
		scope=0;
		model="Utopia_PC\Models\Core\Desk_Parts\Desk_Manual.p3d";
		hiddenSelections[]={"camo"};
		itemSize[]={6,3};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_large";
		rotationFlags = 2;
		weight=100;
		itemBehaviour=2;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
	};
	class Utopia_Desk_Manual : Utopia_Desk_Manual_Base
	{
		scope=2;
		displayName="Desk Manual";
		descriptionShort="A Manual for Deploying A Desk";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\Desk_Parts\Textures\Desk_Manual.paa"
		};
	};
	class Utopia_Desk_Base: Container_Base
	{
		scope=0;
		displayName = "Desk";
		model="Utopia_PC\Models\Core\Desk\Utopia_Desk.p3d";
		hiddenSelections[]=
		{
			"camo",
			"camo1"
		};
		descriptionShort = "This can be dismantled with a screwdriver";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10,10,10};
		physLayer="item_large";
		attachments[] = 
		{
			"WiFi_Router",
			"Keyboard",
			"Monitor",
			"Mouse",
			"Mother_Board",
			"Kingston_1",
			"Kingston_2",
			"Kingston_3",
			"PSU_1",
			"Graphics_Card_2",
			"Graphics_Card_1",
			"Graphics_Card_3",
			"Cooler",
			"Fan_1",
			"Hard_Drive_1",
			"Hard_Drive_2",
			"SSD_1",
			"SSD_2",
			"USB_1",
			"Ram_1",
			"Ram_2",
			"Ram_3",
			"Ram_4",
			"Filament_1",
			"Mousepad",
			"Radar_Link"
		};
		class GUIInventoryAttachmentsProps
		{
			class Desk_Parts
			{
				name="Desk Parts";
				description="";
				attachmentSlots[]=
				{
					"WiFi_Router",
					"Keyboard",
					"Monitor",
					"Mouse",
					"Mousepad",
					"USB_1"
				};
				icon="set:dayz_inventory image:cat_common_cargo";
			};
			class PC_Parts
			{
				name="PC Parts";
				description="";
				attachmentSlots[]=
				{
					"Mother_Board",
					"Cooler",
					"Fan_1",
					"PSU_1",
					"Graphics_Card_2",
					"Graphics_Card_1",
					"Graphics_Card_3",
					"Kingston_1",
					"Kingston_2",
					"Kingston_3",
					"Hard_Drive_1",
					"Hard_Drive_2",
					"SSD_1",
					"SSD_2",
					"Ram_1",
					"Ram_2",
					"Ram_3",
					"Ram_4"
				};
				icon="set:dayz_inventory image:cat_common_cargo";
			};
			class Radar_Link
			{
				name="Radar Link";
				description="";
				attachmentSlots[]=
				{
					"Radar_Link"
				};
				icon="set:dayz_inventory image:cat_common_cargo";
			};
		};
		class Cargo
		{
			itemsCargoSize[]={10,4};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimationSources
		{
			class door1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 5.0;
			};
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
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.14;
			cordLength = 5;
			plugType = 2;
			updateInterval = 60;
		};
	};
	class Utopia_Desk: Utopia_Desk_Base
	{
		scope = 2;
		displayName = "Desk";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\Desk\Textures\desk_co.paa",
			"Utopia_PC\Models\Core\Desk\Textures\control_off.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_PC\Models\Core\Desk\Textures\Desk.rvmat",
			"Utopia_PC\Models\Core\Desk\Textures\Desk.rvmat"
		};
	};
	class Utopia_WiFi_Router: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\WiFi_Router\Utopia_WiFi_Router.p3d";
		displayName = "WiFi_Router";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 2;
		inventorySlot[]=
		{
			"WiFi_Router"
		};
		hiddenSelections[]=
		{
			"zbytek",
			"lights"
		};
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\WiFi_Router\Textures\WiFi_co.paa",
			"Utopia_PC\Models\Core\WiFi_Router\Textures\WiFi_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_PC\Models\Core\WiFi_Router\Textures\WiFi.rvmat",
			"Utopia_PC\Models\Core\WiFi_Router\Textures\WiFi.rvmat"
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
	class Utopia_Keyboard: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Keyboard\Utopia_Keyboard.p3d";
		displayName = "Keyboard";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {3,2};
		rotationFlags = 2;
		inventorySlot[]=
		{
			"Keyboard"
		};
		hiddenSelections[]=
		{
			"keyboard",
			"lights"
		};
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\Keyboard\Textures\Keyboard_Base_Color.paa",
			"Utopia_PC\Models\Core\Keyboard\Textures\Key_off.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_PC\Models\Core\Keyboard\Textures\glossy.rvmat",
			"Utopia_PC\Models\Core\Keyboard\Textures\glossy.rvmat"
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
	class Utopia_Monitor: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Monitor\Utopia_Monitor.p3d";
		displayName = "Monitor";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {5,5};
		rotationFlags = 2;
		inventorySlot[]=
		{
			"Monitor"
		};
		hiddenSelections[]=
		{
			"screen",
			"camo",
			"part2",
			"shutdown"
		};
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\Monitor\Textures\ScreenOFF_co.paa",
			"Utopia_PC\Models\Core\Monitor\Textures\MonitorOFF_co.paa",
			"Utopia_PC\Models\Core\Monitor\Textures\transparent.paa",
			"Utopia_PC\Models\Core\Monitor\Textures\transparent.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_PC\Models\Core\Monitor\Textures\monitor_off.rvmat",
			"Utopia_PC\Models\Core\Monitor\Textures\Monitor.rvmat",
			"Utopia_PC\Models\Core\Monitor\Textures\monitor_off.rvmat",
			"Utopia_PC\Models\Core\Monitor\Textures\monitor_off.rvmat"
			
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
		class AnimationSources
		{
			class Screen_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 20;
			};
			class Shutdown_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 20;
			};
		};
	};
	class Utopia_Mouse: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Mouse\Utopia_Mouse.p3d";
		displayName = "Mouse";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 2;
		inventorySlot[]=
		{
			"Mouse"
		};
		hiddenSelections[]=
		{
			"Mouse"
		};
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\Mouse\Textures\Mouse.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_PC\Models\Core\Mouse\Textures\Mouse.rvmat"
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
	class Utopia_MousePad: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Mouse\MousePad.p3d";
		displayName = "MousePad";
		descriptionShort = "MousePad";
		weight = 500;
		itemSize[] = {5,5};
		rotationFlags = 2;
		physLayer="item_large";
		inventorySlot[]=
		{
			"Mousepad"
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
	class Utopia_MousePad_Rolled: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Mouse\MousePad_Rolled.p3d";
		displayName = "MousePad";
		descriptionShort = "MousePad";
		weight = 500;
		itemSize[] = {5,5};
		rotationFlags = 2;
		physLayer="item_large";
		inventorySlot[]=
		{
			"Mousepad"
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
	class Utopia_MousePad_Case: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\Mouse\Package.p3d";
		displayName = "MousePad Case";
		descriptionShort = "MousePad Case";
		weight = 500;
		itemSize[] = {5,5};
		rotationFlags = 2;
		physLayer="item_large";
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
