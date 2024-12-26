class CfgPatches
{
	class Utopia_PC
	{
		units[]= {};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Utopia_3D_Printer_Base: Inventory_Base
	{
		scope=0;
		model="Utopia_PC\Models\3D_Printer\Printer\Utopia_Printer.p3d";
		displayName = "3D Printer";
		descriptionShort = "A 3D printer is a computer-aided manufacturing (CAM) device that creates three-dimensional objects by layering materials such as molten plastic, powders, or other substances. Like traditional printers, 3D printers receive digital data from a computer as input, but instead of printing 2D images, they fabricate 3D models and products.";
		itemSize[] = {10,10};
		weight = 500;
		rotationFlags = 17;
		hiddenSelections[]=
		{
			"camo"
		};
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10,10,10};
		physLayer="item_large";
		attachments[]=
		{
			"Filament_1"
		};
		class GUIInventoryAttachmentsProps
		{
			class Filament
			{
				name="Filament";
				description="";
				attachmentSlots[]=
				{
					"Filament_1"
				};
				icon="set:dayz_inventory image:cat_common_cargo";
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
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class Utopia_3D_Printer: Utopia_3D_Printer_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"utopia_pc\models\3d_printer\printer\textures\Printer_co.paa"
		};
	};
	class Utopia_Filament_Holder_Kit_Base: Inventory_Base
	{
		scope=0;
		model="Utopia_PC\Models\3D_Printer\Filament_Holder\Filament_Holder_Kit\Utopia_Filament_Holder_Kit.p3d";
		hiddenSelections[]={"Utopia_Filament_Holder_Kit"};
		itemSize[]={6,3};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_large";
		rotationFlags=2;
		weight=500000;
		itemBehaviour=2;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
	};
	class Utopia_Filament_Holder_Kit: Utopia_Filament_Holder_Kit_Base
	{
		scope=2;
		displayName="Filament Holder Kit";
		descriptionShort="A Box for Deploying A Filament Holder";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\Desk_Box\Textures\Top_co.paa"
		};
	};
	class Utopia_Filament_Holder_Base: Container_Base
	{
		scope = 0;
		model = "Utopia_PC\Models\3D_Printer\Filament_Holder\Utopia_Filament_Holder.p3d";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		attachments[]=
		{
			"Filament_1",
			"Filament_2",
			"Filament_3",
			"Filament_4",
			"Filament_5",
			"Filament_6",
			"Filament_7",
			"Filament_8"
		};
		class GUIInventoryAttachmentsProps
		{
			class Filament_Holder
			{
				name="Filament_Holder";
				description="";
				attachmentSlots[]=
				{
					"Filament_1",
					"Filament_2",
					"Filament_3",
					"Filament_4",
					"Filament_5",
					"Filament_6",
					"Filament_7",
					"Filament_8"
				};
				icon="set:dayz_inventory image:cat_common_cargo";
			};
		};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=1;
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
	class Utopia_Filament_Holder: Utopia_Filament_Holder_Base
	{
		scope = 2;
		displayName = "Filament Holder";
		descriptionShort = "";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\3D_Printer\Filament_Holder\Textures\Wood_co.paa"
		};
	};
	class Utopia_Filament_Base: Inventory_Base
	{
		scope = 0;
		model = "Utopia_PC\Models\3D_Printer\Filament\Utopia_Filament.p3d";
		descriptionShort = "3D printing filament is the thermoplastic feedstock for fused deposition modeling 3D printers. There are many types of filament available with different properties.";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		hiddenSelections[]=
		{
			"camo"
		};
		inventorySlot[]=
		{
			"Filament_1",
			"Filament_2",
			"Filament_3",
			"Filament_4",
			"Filament_5",
			"Filament_6",
			"Filament_7",
			"Filament_8",
			"Filament_9",
			"Filament_10",
			"Filament_11",
			"Filament_12",
			"Filament_13",
			"Filament_14",
			"Filament_15",
			"Filament_16",
			"Filament_17",
			"Filament_18"
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
	class Utopia_Filament_Red: Utopia_Filament_Base
	{
		scope = 2;
		displayName = "Filament Red";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\3D_Printer\Filament\Textures\Printer_Red_co.paa"
		};
	};
	class Utopia_Filament_Green: Utopia_Filament_Base
	{
		scope = 2;
		displayName = "Filament Red";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\3D_Printer\Filament\Textures\Printer_Green_co.paa"
		};
	};
	class Utopia_Filament_Yellow: Utopia_Filament_Base
	{
		scope = 2;
		displayName = "Filament Yellow";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\3D_Printer\Filament\Textures\Printer_Yellow_co.paa"
		};
	};
	class Utopia_Filament_Blue: Utopia_Filament_Base
	{
		scope = 2;
		displayName = "Filament Blue";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\3D_Printer\Filament\Textures\Printer_Blue_co.paa"
		};
	};
	class Utopia_USB_Base: Inventory_Base
	{
		scope = 0;
		model = "Utopia_PC\Models\3D_Printer\Connections\Tier2_USB\Tier2_USB.p3d";
		weight = 500;
		itemSize[] = {1,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"USB_1"
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
	class Utopia_Tier1_USB: Utopia_USB_Base
	{
		scope = 2;
		displayName = "Tier1 USB";
		descriptionShort = "";
	};
	class Utopia_Tier2_USB: Utopia_USB_Base
	{
		scope = 2;
		displayName = "Tier2 USB";
		descriptionShort = "";
	};
	class Utopia_Tier3_USB: Utopia_USB_Base
	{
		scope = 2;
		displayName = "Tier3 USB";
		descriptionShort = "";
	};
	class Utopia_Tier4_USB: Utopia_USB_Base
	{
		scope = 2;
		displayName = "Tier4 USB";
		descriptionShort = "";
	};
	class Utopia_Tier5_USB: Utopia_USB_Base
	{
		scope = 2;
		displayName = "Tier5 USB";
		descriptionShort = "";
	};
};