class CfgPatches
{
	class Utopia_PC_Crafting
	{
		units[]=
			{
				"Utopia_GpuRepairKit"
			};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};
class CfgMods
{
	class Utopia_PC_Crafting
	{
		dir="Utopia_PC_Crafting";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Utopia_PC_Crafting";
		credits="";
		author="";
		authorID="0";
		version="1.1";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"Utopia_PC_Crafting/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Utopia_PC_Crafting/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"Utopia_PC_Crafting/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgVehicles
{
	class SewingKit;
	class Utopia_GpuRepairKit: SewingKit
	{
		scope=2;
        displayName = "Utopia GPU Repair Kit";
        descriptionShort = "A specialized kit for repairing high-end GPUs.";
		hiddenSelectionsTextures[]=
        {
            "Utopia_PC_Crafting\Data\gpukit_co.paa",
            "Utopia_PC_Crafting\Data\gpukit_co.paa",
            "Utopia_PC_Crafting\Data\gpukit_co.paa"
        };
        hiddenSelections[]=
        {
            "zbytek"
        };
		debug_ItemCategory=2;
		animClass="Knife";
		rotationFlags=17;
		stackedUnit="percentage";
		quantityBar=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		itemSize[]={1,2};
		weight=210;
		weightPerQuantityUnit=0.2;
		fragility=0.0099999998;
		repairKitType=2;
	};
};
