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
	class Utopia_Bitcoin: Inventory_Base
	{
		scope = 2;
		displayName = "Bitcoin";
		descriptionShort = "Bitcoin is a decentralized digital currency, created in 2009 by Satoshi Nakamoto. It enables peer-to-peer transactions without intermediaries, using blockchain technology for transparency and security. Limited to 21 million coins, Bitcoin is often seen as digital gold due to its scarcity and value.";
		model = "Utopia_PC\Models\Bitcoin\Crypto\Bitcoin\Utopia_Bitcoin.p3d";
		canBeSplit = 1;
		rotationFlags = 0;
		lootCategory = "Materials";
		lootTag[] = {"Civilian","Work"};
		itemSize[] = {1,1};
		weight = 0.1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 1;
		destroyOnEmpty = 1;
		absorbency = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLabels[] = {1,0.7,0.5,0.3,0};
					healthLevels[] = {{1,{}},{0.5,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_XRP: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Bitcoin\Crypto\XRP\Utopia_XRP.p3d";
		displayName = "XRP";
		descriptionShort = "A digital payment protocol and cryptocurrency designed for fast and low-cost international money transfers. XRP is primarily used by financial institutions to facilitate cross-border payments.";
		itemSize[] = {1,1};
		rotationFlags = 0;
        canBeSplit = 1;
		weight = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		destroyOnEmpty = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
	};
	class Utopia_Ethereum: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Bitcoin\Crypto\Ethereum\Utopia_Ethereum.p3d";
		displayName = "Ethereum";
		descriptionShort = "A decentralized blockchain platform that enables smart contracts and decentralized applications (dApps). It’s known for its versatility and the ability to create and deploy decentralized autonomous organizations (DAOs) and NFTs.";
		itemSize[] = {1,1};
		rotationFlags = 0;
        canBeSplit = 1;
		weight = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		destroyOnEmpty = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
	};
	class Utopia_Solana: Inventory_Base
	{
		scope = 2;
		model = "Utopia_PC\Models\Bitcoin\Crypto\Solana\Utopia_Solana.p3d";
		displayName = "Solana";
		descriptionShort = "A high-performance blockchain platform focused on scalability, enabling fast and low-cost transactions. It's popular for decentralized finance (DeFi) applications and NFTs due to its high throughput and low fees.";
		itemSize[] = {1,1};
		rotationFlags = 0;
        canBeSplit = 1;
		weight = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		destroyOnEmpty = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
	};
	class Utopia_Mining_Chassis_Base: Inventory_Base
	{
		scope = 0;
		model = "Utopia_PC\Models\Bitcoin\Mining_Chassis\Mining_Chassis.p3d";
		descriptionShort = "A mining chassis is a specialized computer case designed specifically for cryptocurrency mining operations. These cases are designed to accommodate multiple graphics cards (GPUs) and provide efficient cooling, power supply, and cable management.";
		weight = 500;
		itemSize[] = {10,10};
		rotationFlags = 17;
		hiddenSelections[]=
		{
			"body",
			"parts"
		};
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10,10,10};
		physLayer="item_large";
		attachments[] = 
		{
			"Graphics_Card_1",
			"Graphics_Card_2",
			"Graphics_Card_3",
			"Graphics_Card_4",
			"Graphics_Card_5",
			"Graphics_Card_6",
			"PSU_1",
			"PSU_2",
			"Fan_1",
			"Fan_2",
			"Fan_3"
		};
		class GUIInventoryAttachmentsProps
		{
			class PC_Parts
			{
				name="PC_Parts";
				description="";
				attachmentSlots[]=
				{
					"Graphics_Card_1",
					"Graphics_Card_2",
					"Graphics_Card_3",
					"Graphics_Card_4",
					"Graphics_Card_5",
					"Graphics_Card_6",
					"PSU_1",
					"PSU_2",
					"Fan_1",
					"Fan_2",
					"Fan_3"
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
			itemsCargoSize[]={10,5};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class Utopia_Mining_Chassis: Utopia_Mining_Chassis_Base
	{
		scope = 2;
		displayName = "Mining Chassis";
		hiddenSelectionsTextures[]=
		{
			"Utopia_PC\Models\Bitcoin\Mining_Chassis\Textures\Body_co.paa",
			"Utopia_PC\Models\Bitcoin\Mining_Chassis\Textures\Parts_co.paa"
		};
	};
};
