class CfgPatches
{
	class Custom_Proxies
	{
		units[]=
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
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = 
		{
			"DZ_Data"
		};
	};
};

class CfgSlots {
	class Slot_Filament_1
	{
		name = "Filament_1";
		displayName = "Filament";
		ghostIcon = "set:Utopia_PC image:Filament";
	};
	class Slot_Filament_2
	{
		name = "Filament_2";
		displayName = "Filament";
		ghostIcon = "set:Utopia_PC image:Filament";
	};
	class Slot_Filament_3
	{
		name = "Filament_3";
		displayName = "Filament";
		ghostIcon = "set:Utopia_PC image:Filament";
	};
	class Slot_Filament_4
	{
		name = "Filament_4";
		displayName = "Filament";
		ghostIcon = "set:Utopia_PC image:Filament";
	};
	class Slot_Filament_5
	{
		name = "Filament_5";
		displayName = "Filament";
		ghostIcon = "set:Utopia_PC image:Filament";
	};
	class Slot_Filament_6
	{
		name = "Filament_6";
		displayName = "Filament";
		ghostIcon = "set:Utopia_PC image:Filament";
	};
	class Slot_Filament_7
	{
		name = "Filament_7";
		displayName = "Filament";
		ghostIcon = "set:Utopia_PC image:Filament";
	};
	class Slot_Filament_8
	{
		name = "Filament_8";
		displayName = "Filament";
		ghostIcon = "set:Utopia_PC image:Filament";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyFilament_1: ProxyAttachment
	{
		inventorySlot[] = {"Filament_1"};
		model = "Utopia_PC\Models\3D_Printer\Filament\Proxies\Filament_1.p3d";
	};
	class ProxyFilament_2: ProxyAttachment
	{
		inventorySlot[] = {"Filament_2"};
		model = "Utopia_PC\Models\3D_Printer\Filament\Proxies\Filament_2.p3d";
	};
	class ProxyFilament_3: ProxyAttachment
	{
		inventorySlot[] = {"Filament_3"};
		model = "Utopia_PC\Models\3D_Printer\Filament\Proxies\Filament_3.p3d";
	};
	class ProxyFilament_4: ProxyAttachment
	{
		inventorySlot[] = {"Filament_4"};
		model = "Utopia_PC\Models\3D_Printer\Filament\Proxies\Filament_4.p3d";
	};
	class ProxyFilament_5: ProxyAttachment
	{
		inventorySlot[] = {"Filament_5"};
		model = "Utopia_PC\Models\3D_Printer\Filament\Proxies\Filament_5.p3d";
	};
	class ProxyFilament_6: ProxyAttachment
	{
		inventorySlot[] = {"Filament_6"};
		model = "Utopia_PC\Models\3D_Printer\Filament\Proxies\Filament_6.p3d";
	};
	class ProxyFilament_7: ProxyAttachment
	{
		inventorySlot[] = {"Filament_7"};
		model = "Utopia_PC\Models\3D_Printer\Filament\Proxies\Filament_7.p3d";
	};
	class ProxyFilament_8: ProxyAttachment
	{
		inventorySlot[] = {"Filament_8"};
		model = "Utopia_PC\Models\3D_Printer\Filament\Proxies\Filament_8.p3d";
	};
};