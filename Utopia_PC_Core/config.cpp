class CfgPatches
{
	class Utopia_PC_Core_Script
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};
class CfgMods
{
	class Utopia_PC_Core
	{
		dir="Utopia_PC_Core";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Utopia_PC_Core";
		credits="TheDmitri";
		author="TheDmitri";
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
					"Utopia_PC_Core/scripts/Common",
					"Utopia_PC_Core/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Utopia_PC/Scripts/4_World",
					"Utopia_PC_Core/scripts/Common",
					"Utopia_PC_Core/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"Utopia_PC_Core/scripts/Common",
					"Utopia_PC_Core/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgVehicles
{

};
