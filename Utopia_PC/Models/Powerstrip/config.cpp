class CfgPatches
{
	class Utopia_PC
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Utopia_Powerstrip: Inventory_Base
	{
		scope = 2;
		displayName = "Powerstrip";
		descriptionShort = "A surge protector with 8 plugs";
		model = "Utopia_PC\Models\Powerstrip\Powerstrip.p3d";
		weight = 300;
		itemSize[] = {1,2};
		itemBehaviour = 1;
		rotationFlags = 1;
		slopeTolerance = 0.3;
		class EnergyManager
		{
			switchOnAtSpawn = 1;
			powerSocketsCount = 8;
			cordTextureFile = "DZ\gear\camping\Data\plug_orange_CO.paa";
			isPassiveDevice = 1;
			cordLength = 6;
			plugType = 2;
			compatiblePlugTypes[] = {2,6};
		};
		class AnimationSources
		{
			class socket_1_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_2_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_3_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_4_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_5_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_6_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_7_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_8_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
};
