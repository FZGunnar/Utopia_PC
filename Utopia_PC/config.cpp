class CfgPatches
{
	class Utopia_PC
	{
		units[]= 
		{
			"Utopia_PC"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= 
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class Utopia_PC
	{
		dir="Utopia_PC";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Utopia_PC";
		credits="Utopia";
		author="Genesis";
		authorID="76561198273516768";
		version="0.1";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Utopia_Basecameras/scripts/4_World",
					"Utopia_PC/Scripts/4_World"
				};
			};
			class imageSets
			{
				files[]= 
				{
					"Utopia_PC\GUI\ImageSets\Utopia_PC.imageset"
				};
			};
		};
	};
};
//State your sound shaders , then call the sound shaders in the sound set , call the sound set from your .C
class CfgSoundShaders
{
	class Utopia_PC_Run_SoundShader
	{
		samples[] = { {"Utopia_PC\Scripts\Sounds\FAN-NOISE",1} };
		range = 25;
		volume = 3.0;
	};
	class Utopia_PC_Start_SoundShader
	{
		samples[] = { {"Utopia_PC\Scripts\Sounds\Windows_11_Startup_sound",1} };
		range = 25;
		volume = 2.5;
	};
	class Utopia_PC_Shutdown_SoundShader
	{
		samples[] = { {"Utopia_PC\Scripts\Sounds\shutdown",1} };
		range = 25;
		volume = 4.0;
	};
};
//SoundSet
class CfgSoundSets
{
	class Utopia_FAN_SoundSet
	{
		soundShaders[] = { "Utopia_PC_Run_SoundShader" };
		frequencyRandomizer = 1;
	};
	class Utopia_BOOT_SoundSet
	{
		soundShaders[] = { "Utopia_PC_Start_SoundShader" };
		frequencyRandomizer = 1;
		volumeRandomizer = 1;
	};
	class Utopia_SHUTDOWN_SoundSet
	{
		soundShaders[] = { "Utopia_PC_Shutdown_SoundShader" };
		frequencyRandomizer = 1;
		volumeRandomizer = 1;
	};
};