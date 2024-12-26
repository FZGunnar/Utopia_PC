class CfgPatches
{
	class Custom_Proxies
	{
		units[]=
		{
			"WiFi_Router",
			"Keyboard",
			"Monitor",
			"Mouse",
			"PC_Case",
			"Filament_Holder",
			"Printer",
			"SSD_1",
			"SSD_2",
			"Graphics_Card_1",
			"Graphics_Card_2",
			"Graphics_Card_3",
			"Graphics_Card_4",
			"Graphics_Card_5",
			"Graphics_Card_6",
			"Mother_Board",
			"Cooler",
			"Fan_1",
			"Fan_2",
			"Fan_3",
			"Hard_Drive_1",
			"Hard_Drive_2",
			"USB_1",
			"Ram_1",
			"Ram_2",
			"Ram_3",
			"Ram_4",
			"PSU_1",
			"PSU_2"
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
	class Slot_WiFi_Router 
	{
		name = "WiFi_Router";
		displayName = "WiFi_Router";
		ghostIcon = "set:Utopia_PC image:Wi_Fi";
	};
	class Slot_Monitor {
		name = "Monitor";
		displayName = "Monitor";
		ghostIcon = "set:Utopia_PC image:Monitor";
	};
	class Slot_Mouse {
		name = "Mouse";
		displayName = "Mouse";
		ghostIcon = "set:Utopia_PC image:Mouse";
	};
	class Slot_Keyboard {
		name = "Keyboard";
		displayName = "Keyboard";
		ghostIcon = "set:Utopia_PC image:Keyboard";
	};
	class Slot_Graphics_Card_1 {
		name = "Graphics_Card_1";
		displayName = "Graphics_Card";
		ghostIcon = "set:Utopia_PC image:GPU";
	};
	class Slot_Graphics_Card_2 {
		name = "Graphics_Card_2";
		displayName = "Graphics_Card";
		ghostIcon = "set:Utopia_PC image:GPU";
	};
	class Slot_Graphics_Card_3 {
		name = "Graphics_Card_3";
		displayName = "Graphics_Card";
		ghostIcon = "set:Utopia_PC image:GPU";
	};
	class Slot_Graphics_Card_4 {
		name = "Graphics_Card_4";
		displayName = "Graphics_Card";
		ghostIcon = "set:Utopia_PC image:GPU";
	};
	class Slot_Graphics_Card_5 {
		name = "Graphics_Card_5";
		displayName = "Graphics_Card";
		ghostIcon = "set:Utopia_PC image:GPU";
	};
	class Slot_Graphics_Card_6 {
		name = "Graphics_Card_6";
		displayName = "Graphics_Card";
		ghostIcon = "set:Utopia_PC image:GPU";
	};
	class Slot_Kingston_1 {
		name = "Kingston_1";
		displayName = "Kingston";
		ghostIcon = "set:Utopia_PC image:Kingston";
	};
	class Slot_Kingston_2 {
		name = "Kingston_2";
		displayName = "Kingston";
		ghostIcon = "set:Utopia_PC image:Kingston";
	};
	class Slot_Kingston_3 {
		name = "Kingston_3";
		displayName = "Kingston";
		ghostIcon = "set:Utopia_PC image:Kingston";
	};
	class Slot_PSU_1 {
		name = "PSU_1";
		displayName = "PSU";
		ghostIcon = "set:Utopia_PC image:PSU";
	};
	class Slot_PSU_2 {
		name = "PSU_2";
		displayName = "PSU";
		ghostIcon = "set:Utopia_PC image:PSU";
	};
	class Slot_Mother_Board {
		name = "Mother_Board";
		displayName = "Mother_Board";
		ghostIcon = "set:Utopia_PC image:Mother_Board";
	};
	class Slot_Cooler {
		name = "Cooler";
		displayName = "Cooler";
		ghostIcon = "set:Utopia_PC image:Cooler";
	};
	class Slot_Fan_1 {
		name = "Fan_1";
		displayName = "Fan";
		ghostIcon = "set:Utopia_PC image:Fan";
	};
	class Slot_Fan_2 {
		name = "Fan_2";
		displayName = "Fan";
		ghostIcon = "set:Utopia_PC image:Fan";
	};
	class Slot_Fan_3 {
		name = "Fan_3";
		displayName = "Fan";
		ghostIcon = "set:Utopia_PC image:Fan";
	};
	class Slot_SSD_1 {
		name = "SSD_1";
		displayName = "SSD";
		ghostIcon = "set:Utopia_PC image:SSD";
	};
	class Slot_SSD_2_1 {
		name = "SSD_2";
		displayName = "SSD";
		ghostIcon = "set:Utopia_PC image:SSD";
	};
	class Slot_Hard_Drive_1 {
		name = "Hard_Drive_1";
		displayName = "Hard_Drive";
		ghostIcon = "set:Utopia_PC image:Hard_Drive";
	};
	class Slot_Hard_Drive_2 {
		name = "Hard_Drive_2";
		displayName = "Hard_Drive";
		ghostIcon = "set:Utopia_PC image:Hard_Drive";
	};
	class Slot_USB_1 {
		name = "USB_1";
		displayName = "USB";
		ghostIcon = "set:Utopia_PC image:USB";
	};
	class Slot_Ram_1 {
		name = "Ram_1";
		displayName = "Ram";
		ghostIcon = "set:Utopia_PC image:Ram";
	};
	class Slot_Ram_2 {
		name = "Ram_2";
		displayName = "Ram";
		ghostIcon = "set:Utopia_PC image:Ram";
	};
	class Slot_Ram_3 {
		name = "Ram_3";
		displayName = "Ram";
		ghostIcon = "set:Utopia_PC image:Ram";
	};
	class Slot_Ram_4 {
		name = "Ram_4";
		displayName = "Ram";
		ghostIcon = "set:Utopia_PC image:Ram";
	};
	class Slot_PC_Case {
		name = "PC_Case";
		displayName = "PC Case";
		ghostIcon = "set:Utopia_PC image:PC_Case";
	};
	class Slot_Mousepad {
		name = "Mousepad";
		displayName = "Mousepad";
		ghostIcon = "set:Utopia_PC image:Mousepad";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyWiFi_Router: ProxyAttachment
	{
		inventorySlot[] = {"WiFi_Router"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\WiFi_Router.p3d";
	};
	class ProxyKeyboard: ProxyAttachment
	{
		inventorySlot[] = {"Keyboard"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Keyboard.p3d";
	};
	class ProxyMouse: ProxyAttachment
	{
		inventorySlot[] = {"Mouse"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Mouse.p3d";
	};
	class ProxyMonitor: ProxyAttachment
	{
		inventorySlot[] = {"Monitor"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Monitor.p3d";
	};
	class ProxyGraphics_Card_1: ProxyAttachment
	{
		inventorySlot[] = {"Graphics_Card_1"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Graphics_Card_1.p3d";
	};
	class ProxyGraphics_Card_2: ProxyAttachment
	{
		inventorySlot[] = {"Graphics_Card_2"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Graphics_Card_2.p3d";
	};
	class ProxyGraphics_Card_3: ProxyAttachment
	{
		inventorySlot[] = {"Graphics_Card_3"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Graphics_Card_3.p3d";
	};
	class ProxyGraphics_Card_4: ProxyAttachment
	{
		inventorySlot[] = {"Graphics_Card_4"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Graphics_Card_4.p3d";
	};
	class ProxyGraphics_Card_5: ProxyAttachment
	{
		inventorySlot[] = {"Graphics_Card_5"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Graphics_Card_5.p3d";
	};
	class ProxyGraphics_Card_6: ProxyAttachment
	{
		inventorySlot[] = {"Graphics_Card_6"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Graphics_Card_6.p3d";
	};
	class ProxyKingston_1: ProxyAttachment
	{
		inventorySlot[] = {"Kingston_1"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Kingston_1.p3d";
	};
	class ProxyKingston_2: ProxyAttachment
	{
		inventorySlot[] = {"Kingston_2"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Kingston_2.p3d";
	};
	class ProxyKingston_3: ProxyAttachment
	{
		inventorySlot[] = {"Kingston_3"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Kingston_3.p3d";
	};
	class ProxyPSU_1: ProxyAttachment
	{
		inventorySlot[] = {"PSU_1"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\PSU_1.p3d";
	};
	class ProxyPSU_2: ProxyAttachment
	{
		inventorySlot[] = {"PSU_2"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\PSU_2.p3d";
	};
	class ProxyMother_Board: ProxyAttachment
	{
		inventorySlot[] = {"Mother_Board"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Mother_Board.p3d";
	};
	class ProxyCooler: ProxyAttachment
	{
		inventorySlot[] = {"Cooler"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Cooler.p3d";
	};
	class ProxyFan_1: ProxyAttachment
	{
		inventorySlot[] = {"Fan_1"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Fan_1.p3d";
	};
	class ProxyFan_2: ProxyAttachment
	{
		inventorySlot[] = {"Fan_2"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Fan_2.p3d";
	};
	class ProxyFan_3: ProxyAttachment
	{
		inventorySlot[] = {"Fan_3"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Fan_3.p3d";
	};
	class ProxySSD_1: ProxyAttachment
	{
		inventorySlot[] = {"SSD_1"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\SSD_1.p3d";
	};
	class ProxySSD_2: ProxyAttachment
	{
		inventorySlot[] = {"SSD_2"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\SSD_2.p3d";
	};
	class ProxyHard_Drive_1: ProxyAttachment
	{
		inventorySlot[] = {"Hard_Drive_1"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Hard_Drive_1.p3d";
	};
	class ProxyHard_Drive_2: ProxyAttachment
	{
		inventorySlot[] = {"Hard_Drive_2"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Hard_Drive_2.p3d";
	};
	class ProxyUSB_1: ProxyAttachment
	{
		inventorySlot[] = {"USB_1"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\USB_1.p3d";
	};
	class ProxyRam_1: ProxyAttachment
	{
		inventorySlot[] = {"Ram_1"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Ram_1.p3d";
	};
	class ProxyRam_2: ProxyAttachment
	{
		inventorySlot[] = {"Ram_2"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Ram_2.p3d";
	};
	class ProxyRam_3: ProxyAttachment
	{
		inventorySlot[] = {"Ram_3"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Ram_3.p3d";
	};
	class ProxyRam_4: ProxyAttachment
	{
		inventorySlot[] = {"Ram_4"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\Ram_4.p3d";
	};
	class ProxyPC_Case: ProxyAttachment
	{
		inventorySlot[] = {"PC_Case"};
		model = "Utopia_PC\Models\Core\Desk\Proxies\PC_Case.p3d";
	};
	class ProxyMousepad: ProxyAttachment
	{
		inventorySlot[] = {"Mousepad"};
		model = "Utopia_PC\Models\Core\Mouse\MousePad.p3d";
	};
};