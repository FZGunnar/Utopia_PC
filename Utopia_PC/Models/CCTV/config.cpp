class CfgPatches
{
	class Utopia_PC
	{
		units[]= 
		{
			"Utopia_CCTV"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Utopia_CCTV: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\CCTV\Utopia_CCTV.p3d";
		displayName = "CCTV";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {4,3};
		hiddenSelections[]={"camo","camo1"};
		rotationFlags = 17;
		overrideDrawArea = 3.0;
		carveNavmesh=1;
		forceFarBubble = "true";
		attachments[] = {"BatteryD"};
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\CCTV\Textures\CCTV_Body_co.paa",
			"Utopia_PC\Models\CCTV\Textures\CCTV_Glass_co.paa"
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
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
		};
	};
};