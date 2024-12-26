class CfgPatches
{
	class Utopia_PC
	{
		units[]= 
		{
			"Utopia_Graphics_Card_660",
			"Utopia_Graphics_Card_1080Ti",
			"Utopia_Graphics_Card_2060",
			"Utopia_Graphics_Card_4090TI",
			"Utopia_Hard_Drive",
			"Utopia_Kingston",
			"Utopia_PSU",
			"Utopia_SSD"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Utopia_Graphics_Card_4090TI: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Graphics_Card_4090TI.p3d";
		displayName = "Graphics_Card_4090TI";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,3};
		rotationFlags = 17;
		quantityBar = 1;
		varQuantityInit = 100;
		varQuantityMin = 0.0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 0;
		inventorySlot[]=
		{
			"Graphics_Card_1",
			"Graphics_Card_2",
			"Graphics_Card_3",
			"Graphics_Card_4",
			"Graphics_Card_5",
			"Graphics_Card_6"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"Utopia_PC\Models\Core\PC\Textures\blackPlastic.rvmat"}},{0.7,{"Utopia_PC\Models\Core\PC\Textures\blackPlastic.rvmat"}},{0.5,{"Utopia_PC\Models\Core\PC\Textures\blackPlastic_damage.rvmat"}},{0.3,{"Utopia_PC\Models\Core\PC\Textures\blackPlastic_damage.rvmat"}},{0.0,{"Utopia_PC\Models\Core\PC\Textures\blackPlastic_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class fans_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
		};
	};
	class Utopia_RTX_2080TI: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\RTX_2080TI.p3d";
		displayName = "RTX 2080TI";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,3};
		rotationFlags = 17;
		quantityBar = 1;
		varQuantityInit = 100;
		varQuantityMin = 0.0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 0;
		inventorySlot[]=
		{
			"Graphics_Card_1",
			"Graphics_Card_2",
			"Graphics_Card_3",
			"Graphics_Card_4",
			"Graphics_Card_5",
			"Graphics_Card_6"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"Utopia_PC\Models\Core\PC\Textures\660.rvmat"}},{0.7,{"Utopia_PC\Models\Core\PC\Textures\660.rvmat"}},{0.5,{"Utopia_PC\Models\Core\PC\Textures\660_damaged.rvmat"}},{0.3,{"Utopia_PC\Models\Core\PC\Textures\660_damaged.rvmat"}},{0.0,{"Utopia_PC\Models\Core\PC\Textures\660_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class fans_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
		};
	};
	class Utopia_Graphics_Card_1080TI: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Graphics_Card_1080TI.p3d";
		displayName = "Graphics Card 1080TI";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,3};
		rotationFlags = 17;
		quantityBar = 1;
		varQuantityInit = 100;
		varQuantityMin = 0.0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 0;
		inventorySlot[]=
		{
			"Graphics_Card_1",
			"Graphics_Card_2",
			"Graphics_Card_3",
			"Graphics_Card_4",
			"Graphics_Card_5",
			"Graphics_Card_6"
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
			class fans_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
		};
	};
	class Utopia_Graphics_Card_660: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Graphics_Card_660.p3d";
		displayName = "Graphics_Card_660";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,3};
		rotationFlags = 17;
		quantityBar = 1;
		varQuantityInit = 100;
		varQuantityMin = 0.0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 0;
		inventorySlot[]=
		{
			"Graphics_Card_1",
			"Graphics_Card_2",
			"Graphics_Card_3",
			"Graphics_Card_4",
			"Graphics_Card_5",
			"Graphics_Card_6"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"Utopia_PC\Models\Core\PC\Textures\2060.rvmat"}},{0.7,{"Utopia_PC\Models\Core\PC\Textures\2060.rvmat"}},{0.5,{"Utopia_PC\Models\Core\PC\Textures\2060_damaged.rvmat"}},{0.3,{"Utopia_PC\Models\Core\PC\Textures\2060_damaged.rvmat"}},{0.0,{"Utopia_PC\Models\Core\PC\Textures\2060_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class fans_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
		};
	};
	class Utopia_Back_Cover: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Back_Cover.p3d";
		displayName = "PC Case Back Cover";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Back_Cover"
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
	class Utopia_Hard_Drive: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Hard_Drive.p3d";
		displayName = "Hard_Drive";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Hard_Drive_1",
			"Hard_Drive_2"
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
	class Utopia_Mother_Board: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Mother_Board.p3d";
		displayName = "Mother_Board";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {4,4};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Mother_Board"
		};
		hiddenSelections[]=
		{
			"lights",
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\PC\Textures\Board.paa",
			"Utopia_PC\Models\Core\PC\Textures\Board.paa"
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
	class Utopia_GSKILL_TridentZ: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\GSKILL_TridentZ.p3d";
		displayName = "G.SKILL Trident Z";
		descriptionShort = "G.SKILL Trident Z RGB 3200 MHz";
		weight = 500;
		itemSize[] = {2,1};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Ram_1",
			"Ram_2",
			"Ram_3",
			"Ram_4"
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
	class Utopia_Corsair_Vengeance: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Corsair_Vengeance.p3d";
		displayName = "Corsair Vengeance";
		descriptionShort = "Corsair Vengeance RGB PRO DDR4 3600 MHz";
		weight = 500;
		itemSize[] = {2,1};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Ram_1",
			"Ram_2",
			"Ram_3",
			"Ram_4"
		};
		hiddenSelections[]=
		{
			"RGB",
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\PC\Textures\Corsair_lightsoff_co.paa",
			"Utopia_PC\Models\Core\PC\Textures\Corsair_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_PC\Models\Core\PC\Textures\Corsair.rvmat",
			"Utopia_PC\Models\Core\PC\Textures\Corsair.rvmat"
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
	class Utopia_Corsair_Platinum: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Corsair_Platinum.p3d";
		displayName = "Corsair Platinum";
		descriptionShort = "Corsair Dominator Platinum DDR4 3000 MHz";
		weight = 500;
		itemSize[] = {2,1};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Ram_1",
			"Ram_2",
			"Ram_3",
			"Ram_4"
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
	class Utopia_Kingston: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Kingston.p3d";
		displayName = "Kingston";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Kingston_1",
			"Kingston_2",
			"Kingston_3"
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
	class Utopia_PSU: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\PSU.p3d";
		displayName = "PSU";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {4,3};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"PSU_1",
			"PSU_2"
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
			class fans_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
		};
	};
	class Utopia_SSD: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\SSD.p3d";
		displayName = "SSD";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"SSD_1",
			"SSD_2"
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
	class Utopia_Cooler: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Cooler.p3d";
		displayName = "Cooler";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,4};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Cooler"
		};
		hiddenSelections[]=
		{
			"camo",
			"camo2",
			"camo3",
			"camo4",
			"lights"
		};
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Core\pc\textures\plastic_fan.paa",
			"Utopia_PC\Models\Core\PC\textures\cable.paa",
			"Utopia_PC\Models\Core\PC\textures\silver.paa",
			"Utopia_PC\Models\Core\PC\textures\cooler_and_ram_extra.paa",
			"Utopia_PC\Models\Core\PC\textures\cooler_and_ram_extra.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_PC\Models\Core\Keyboard\Textures\glossy.rvmat",
			"Utopia_PC\Models\Core\Keyboard\Textures\glossy.rvmat",
			"Utopia_PC\Models\Core\Keyboard\Textures\glossy.rvmat",
			"Utopia_PC\Models\Core\Keyboard\Textures\glossy.rvmat",
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
			class fans_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
		};
	};
	class Utopia_Fan: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Core\PC\Parts\Fan.p3d";
		displayName = "Fan";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {2,2};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Fan_1",
			"Fan_2",
			"Fan_3"
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
			class fans_rotate
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
		};
	};
};