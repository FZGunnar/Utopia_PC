class CfgPatches
{
	class Basecameras_Script
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};
class CfgMods
{
	class Basecameras
	{
		dir="Basecameras";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Basecameras";
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
					"Basecameras/scripts/Common",
					"Basecameras/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Basecameras/scripts/Common",
					"Basecameras/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"Basecameras/scripts/Common",
					"Basecameras/scripts/5_Mission"
				};
			};
		};
	};
};