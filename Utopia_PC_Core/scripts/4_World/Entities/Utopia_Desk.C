modded class Utopia_Desk: BaseLaptop 
{
    bool PRINT_DEBUG_LOG = true;
    bool m_IsPCRunning = false; 
    bool m_IsStarting;
    bool m_IsShuttingDown;

    ref Timer m_FanLoopTimer;
    float m_FanAnimationPhase;
  
    protected EffectSound m_BootSound;
    protected EffectSound m_ShutdownSound; 
    protected EffectSound m_FanSound;

    const string	SOUND_DESK_BOOT 		= "Utopia_BOOT_SoundSet";
	const string	SOUND_DESK_SHUTDOWN 		= "Utopia_SHUTDOWN_SoundSet";
	const string	SOUND_DESK_FANS 		= "Utopia_FAN_SoundSet";
    
	protected bool m_PlayDeskStartupSound = false;
	protected bool m_PlayDeskFansSound = false;
	protected bool m_PlayShuttingdownSound = false;
	protected bool m_StopDeskFansSound = false;

    protected const string SELECTION_ID_SCREEN 	= "screen"; 
	protected const string SLOT_MONITOR	= 	        "Monitor";
	protected const string SLOT_KEYBOARD	= 		"Keyboard";
	protected const string SLOT_WIFI_ROUTER	= 		"WiFi_Router";
	protected const string SLOT_MOUSE	= 			"Mouse";
	protected const string SLOT_MOTHERBOARD	= 		"Mother_Board";
	protected const string SLOT_KINGSTON_1	= 		"Kingston_1";
	protected const string SLOT_KINGSTON_2	= 		"Kingston_2";
	protected const string SLOT_KINGSTON_3	= 	    "Kingston_3";
	protected const string SLOT_PSU_1	= 			"PSU_1";
	protected const string SLOT_GRAPHICS_CARD_1	= 	"Graphics_Card_1";
	protected const string SLOT_GRAPHICS_CARD_2	=   "Graphics_Card_2";
	protected const string SLOT_GRAPHICS_CARD_3	= 	"Graphics_Card_3";
	protected const string SLOT_COOLER	= 			"Cooler";
	protected const string SLOT_FAN_1	= 			"Fan_1";
	protected const string SLOT_HARD_DRIVE_1	= 	"Hard_Drive_1";
	protected const string SLOT_HARD_DRIVE_2	= 	"Hard_Drive_2";
	protected const string SLOT_SSD_1	= 			"SSD_1";
	protected const string SLOT_SSD_2	= 			"SSD_2";
	protected const string SLOT_USB_1	= 			"USB_1";
	protected const string SLOT_RAM_1	= 			"Ram_1";
	protected const string SLOT_RAM_2	= 			"Ram_2";
	protected const string SLOT_RAM_3	= 			"Ram_3";
	protected const string SLOT_RAM_4	= 			"Ram_4";
    protected const string MATERIAL_SCREENON = 		"Utopia_PC\\Models\\Core\\Monitor\\Textures\\monitor_on.rvmat";
	protected const string TEXTURE_SCREENON	=       "Utopia_PC\\Models\\Core\\Monitor\\Textures\\MonitorDESKTOP_co.paa";
	protected const string MATERIAL_SCREENOFF	= 	 "Utopia_PC\\Models\\Core\\Monitor\\Textures\\monitor_off.rvmat";
	protected const string TEXTURE_SCREENOFF	= 	"Utopia_PC\\Models\\Core\\Monitor\\Textures\\ScreenOFF_co.paa";
	protected const string TEXTURE_SCREENSHUTTINGDOWN	= 	"Utopia_PC\\Models\\Core\\Monitor\\Textures\\MonitorSHUTDOWN_co.paa";
    protected const string MATERIAL_KEYBOARDON = 		"Utopia_PC\\Models\\Core\\Keyboard\\Textures\\blueglow.rvmat";
	protected const string TEXTURE_KEYBOARDON	=   "Utopia_PC\\Models\\Core\\Keyboard\\Textures\\Key_Emissive.paa";
	protected const string MATERIAL_KEYBOARDOFF	= 	 "Utopia_PC\\Models\\Core\\Keyboard\\Textures\\glossy.rvmat";
	protected const string TEXTURE_KEYBOARDOFF	= 	"Utopia_PC\\Models\\Core\\Keyboard\\Textures\\Key_off.paa";
    protected const string MATERIAL_MOUSEON = 		"Utopia_PC\\Models\\Core\\Mouse\\Textures\\mouseblueglow.rvmat";
	protected const string TEXTURE_MOUSEON	=       "Utopia_PC\\Models\\Core\\Mouse\\Textures\\Mouse_lights_on.paa";
	protected const string MATERIAL_MOUSEOFF	= 	 "Utopia_PC\\Models\\Core\\Mouse\\Textures\\mouse.rvmat";
	protected const string TEXTURE_MOUSEOFF	= 	    "Utopia_PC\\Models\\Core\\Mouse\\Textures\\Mouse.paa";
    protected const string MATERIAL_COOLERON = 		"Utopia_PC\\Models\\Core\\PC\\Textures\\glow_on.rvmat";
	protected const string TEXTURE_COOLERON	=       "Utopia_PC\\Models\\Core\\PC\\Textures\\Cooler_And_Ram_Extra.paa";
	protected const string MATERIAL_COOLEROFF	= 	 "Utopia_PC\\Models\\Core\\Monitor\\Textures\\monitor_off.rvmat";
	protected const string TEXTURE_COOLEROFF	= 	"Utopia_PC\\Models\\Core\\PC\\Textures\\Cooler_And_Ram_Extra.paa";
    protected const string MATERIAL_MOTHERBOARDON = 		"Utopia_PC\\Models\\Core\\PC\\Textures\\glow_on.rvmat";
	protected const string TEXTURE_MOTHERBOARDON	=       "Utopia_PC\\Models\\Core\\PC\\Textures\\Board.paa";
	protected const string MATERIAL_MOTHERBOARDOFF	= 	 "Utopia_PC\\Models\\Core\\Keyboard\\Textures\\glossy.rvmat";
	protected const string TEXTURE_MOTHERBOARDOFF	= 	"Utopia_PC\\Models\\Core\\PC\\Textures\\Board.paa";
    protected const string MATERIAL_RAMON = 		"Utopia_PC\\Models\\Core\\PC\\Textures\\glow_on.rvmat";
	protected const string TEXTURE_RAMON	=       "Utopia_PC\\Models\\Core\\PC\\Textures\\Corsair_co.paa";
	protected const string MATERIAL_RAMOFF	= 	 "Utopia_PC\\Models\\Core\\PC\\Textures\\Corsair.rvmat";
	protected const string TEXTURE_RAMOFF	= 	"Utopia_PC\\Models\\Core\\PC\\Textures\\Corsair_lightsoff_co.paa";  
    
    protected const string MATERIAL_DESKON = 		"Utopia_PC\\Models\\Core\\PC\\Textures\\glow_on.rvmat";
	protected const string TEXTURE_DESKON	=       "Utopia_PC\\Models\\Core\\Desk\\Textures\\control.paa";
	protected const string MATERIAL_DESKOFF	= 	 "Utopia_PC\\Models\\Core\\Monitor\\Textures\\monitor_off.rvmat";
	protected const string TEXTURE_DESKOFF	= 	"Utopia_PC\\Models\\Core\\Desk\\Textures\\control_off.paa";

    protected const string MATERIAL_WIFI_ROUTERON = 		"Utopia_PC\\Models\\Core\\WiFi_Router\\Textures\\greenglow.rvmat";
	protected const string MATERIAL_WIFI_ROUTEROFF	= 	 "Utopia_PC\\Models\\Core\\WiFi_Router\\Textures\\WiFi.rvmat";
    protected const string MATERIAL_LOADINGON = 		"Utopia_PC\\Models\\Core\\Monitor\\Textures\\loadingscreen.rvmat";
	protected const string TEXTURE_LOADINGON	=       "Utopia_PC\\Models\\Core\\Monitor\\Textures\\loadingp22.paa";
	protected const string MATERIAL_LOADINGOFF	= 	 "Utopia_PC\\Models\\Core\\Monitor\\Textures\\monitor_on.rvmat";
	protected const string TEXTURE_LOADINGOFF	= 	"Utopia_PC\\Models\\Core\\Monitor\\Textures\\transparent.paa";
    protected const string TEXTURE_SHUTTINGOFF	= 	"Utopia_PC\\Models\\Core\\Monitor\\Textures\\MonitorSHUTDOWN_co.paa";
	protected const string TEXTURE_SHUTDOWNANIMON	=       "Utopia_PC\\Models\\Core\\Monitor\\Textures\\shuttingdown.paa";
	protected const string TEXTURE_SHUTDOWNANIMOFF	=       "Utopia_PC\\Models\\Core\\Monitor\\Textures\\transparent.paa";

    protected ref map<string, float> m_CoinsMined = new map<string, float>();
    protected bool m_IsMiningActive = false;
    protected int m_HashTime;
    protected int m_HashingTimer;
    

    protected ref UtopiaPcSettings m_Settings;


    string GetSOUND_DESK_BOOT()
    {
        return "Utopia_BOOT_SoundSet";
    }
    
    string GetSOUND_DESK_SHUTDOWN()
    {
        return "Utopia_SHUTDOWN_SoundSet";
    }
    
    string GetSOUND_DESK_FANS()
    {
        return "Utopia_FAN_SoundSet";
    }

    void Utopia_Desk()
    {
        m_Settings = UtopiaPcSettings.Load();
  		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");  
  		RegisterNetSyncVariableBool("m_PlayDeskStartupSound");
		RegisterNetSyncVariableBool("m_PlayDeskFansSound");
		RegisterNetSyncVariableBool("m_PlayShuttingdownSound");
		RegisterNetSyncVariableBool("m_StopDeskFansSound");       

		//Need this to allow execute of EOnPostSimulate in the cycle (will be used for managing action sounds)
		SetEventMask(EntityEvent.POSTSIMULATE);
    }

    void DeskDebug(string message) 
    {
        Print("[Utopia_Desk Debug] " + message);
    }

	int GetTotalGraphicCardLifeTime()
	{
		int lifetime = 0;
        foreach(string slotName : g_UtopiaPcGraphicCardSlots)
        {
            lifetime += GetLifeTimeForGraphicCardAtSlot(slotName);
        }
	    DeskDebug("GetTotalGraphicCardLifeTime called. Total lifetime: " + lifetime);	
        return lifetime;
	}

	int GetLifeTimeForGraphicCardAtSlot(string slotName)
    {
        ItemBase graphicCard = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName)); // Safe casting
        if (!graphicCard)
        {
            DeskDebug("Graphic card not found in slot: " + slotName);
            return 0;
        }
        string className = graphicCard.GetType();

        if (!GetUtopiaPcModule() || !GetUtopiaPcModule().GetSettings())
            return 0;

        return GetUtopiaPcModule().GetSettings().FindLifetimeForClassName(className);
    }


    void RaiseDesk()
    {   

        if (m_IsPCRunning)
        {
		    SetAnimationPhase("door1",1);
            SetAnimationPhase("door2",1);
        }
        DeskDebug("raise desk called. PC Running: " + m_IsPCRunning);
    }
   
    void lowerDesk()
    {   

        {
		    SetAnimationPhase("door1",0);
            SetAnimationPhase("door2",0);
        }
        DeskDebug("lower desk called.");
    }
   

    void LockAttachments()
	{
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_MONITOR), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_KEYBOARD), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_WIFI_ROUTER), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_MOUSE), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_MOTHERBOARD), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_KINGSTON_1), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_KINGSTON_2), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_KINGSTON_3), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_PSU_1), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_GRAPHICS_CARD_1), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_GRAPHICS_CARD_2), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_GRAPHICS_CARD_3), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_COOLER), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_FAN_1), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_HARD_DRIVE_1), true);
        GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_HARD_DRIVE_2), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_SSD_1), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_SSD_2), true);
        GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_USB_1), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_RAM_1), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_RAM_2), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_RAM_3), true);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_RAM_4), true);
	}
	
	void UnlockAttachments()
	{
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_MONITOR), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_KEYBOARD), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_WIFI_ROUTER), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_MOUSE), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_MOTHERBOARD), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_KINGSTON_1), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_KINGSTON_2), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_KINGSTON_3), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_PSU_1), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_GRAPHICS_CARD_1), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_GRAPHICS_CARD_2), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_GRAPHICS_CARD_3), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_COOLER), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_FAN_1), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_HARD_DRIVE_1), false);
        GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_HARD_DRIVE_2), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_SSD_1), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_SSD_2), false);
        GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_USB_1), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_RAM_1), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_RAM_2), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_RAM_3), false);
		GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(SLOT_RAM_4), false);
	}
    
    void SetAttachmentTexture(string slotName, string texture)
    {
        // Find the attachment by name and safely cast it to ItemBase
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("screen"); // Assuming "screen" is the name of the hidden selection
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'screen' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectTexture(hiddenSelectionIndex, texture);
    }

    
    void SetAttachmentMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("screen"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'screen' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    void SetKeyBoardTexture(string slotName, string texture)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("lights"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'lights' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectTexture(hiddenSelectionIndex, texture);
    }
    
    void SetKeyBoardMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("lights"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'lights' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    void SetMouseTexture(string slotName, string texture)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("Mouse"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'Mouse' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectTexture(hiddenSelectionIndex, texture);
    }
    
    void SetMouseMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("Mouse"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'Mouse' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    void SetMotherboardTexture(string slotName, string texture)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("lights"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'lights' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectTexture(hiddenSelectionIndex, texture);
    }
    
    void SetMotherboardMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("lights"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'lights' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    
    void SetCoolerTexture(string slotName, string texture)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("lights"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'lights' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectTexture(hiddenSelectionIndex, texture);
    }
    
    void SetCoolerMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("lights"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'lights' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    void SetRamTexture(string slotName, string texture)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("RGB"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'rgb' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectTexture(hiddenSelectionIndex, texture);
    }
    
    void SetRamMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("RGB"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'rgb' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    
    void SetDeskTexture(string texture)
    {
        // Find the desk entity
        EntityAI desk = this; // Assuming this script is attached to the desk entity itself

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = desk.GetHiddenSelectionIndex("camo1"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'camo1' not found on the desk entity.");
            return;
        }

        desk.SetObjectTexture(hiddenSelectionIndex, texture);
    }
    
    void SetDeskMaterial(string material)
    {
        // Find the desk entity
        EntityAI desk = this; // Assuming this script is attached to the desk entity itself

        // Set the material of the hidden selection
        int hiddenSelectionIndex = desk.GetHiddenSelectionIndex("camo1"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'camo1' not found on the desk entity.");
            return;
        }

        desk.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    
    void SetDeskLoadingTexture(string slotName, string texture)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("part2"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'part2' not found on the desk entity.");
            return;
        }

        attachment.SetObjectTexture(hiddenSelectionIndex, texture);
    }
    
    void SetDeskLoadingMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the material of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("part2"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'part2' not found on the desk entity.");
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    
    void SetshutdownanimTexture(string slotName, string texture)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("shutdown"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'shutdown' not found on the desk entity.");
            return;
        }

        attachment.SetObjectTexture(hiddenSelectionIndex, texture);
    }   
    void SetShutdownanimMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the material of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("shutdown"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'shutdown' not found on the desk entity.");
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    
    void SetWifirouterMaterial(string slotName, string material)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: " + slotName);
            return;
        }

        // Set the texture of the hidden selection
        int hiddenSelectionIndex = attachment.GetHiddenSelectionIndex("lights"); 
        if (hiddenSelectionIndex == -1)
        {
            DeskDebug("Hidden selection 'lights' not found on attachment in slot: " + slotName);
            return;
        }

        attachment.SetObjectMaterial(hiddenSelectionIndex, material);
    }
    
    void StartFanAnimationLoop() 
    {
        m_FanLoopTimer = new Timer();
        m_FanLoopTimer.Run(0.25, this, "UpdateFanAnimation", null, true); // Adjust interval as needed
        DeskDebug("Fan animation loop started.");

    }

    void StopFanAnimationLoop() 
    {
        if (m_FanLoopTimer) 
        {
        m_FanLoopTimer.Stop();

        DeskDebug("Fan animation loop stopped.");
        
        }
    }

    void UpdateFanAnimation() 
    {
        // Update fan animation phase (increment/decrement as needed)
        m_FanAnimationPhase += 0.1; // Adjust speed as needed

        // Ensure animation phase stays within range (0 to 1)
        if (m_FanAnimationPhase >= 1.0) {
            m_FanAnimationPhase -= 1.0; // Reset phase if it exceeds 1
        }

        // Set the animation phase for GPU fans
        SetGPU1FansAnimationPhase(m_FanAnimationPhase * 100); // Adjust multiplier as needed
        SetGPU2FansAnimationPhase(m_FanAnimationPhase * 100); // Adjust multiplier as needed
        SetGPU3FansAnimationPhase(m_FanAnimationPhase * 100); // Adjust multiplier as needed
        SetCoolerFansAnimationPhase(m_FanAnimationPhase * 100); // Adjust multiplier as needed
        SetPSUFansAnimationPhase(m_FanAnimationPhase * 100); // Adjust multiplier as needed
        SetSmallFansAnimationPhase(m_FanAnimationPhase * 100); // Adjust multiplier as needed
    }

   void SetSmallFansAnimationPhase(float phase)
    {
        // Find the attachment by name and safely cast it to ItemBase
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName("Fan_1"));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: Fan_1");
            return;
        }

        // Set the animation phase of the GPU 1 fans
        attachment.SetAnimationPhase("fans_rotate", phase);
        //DeskDebug("Attachment found in slot: Graphics_Card_1 turned animation on");
        //DeskDebug("GPU 1 fans animation phase set to: " + phase);
    }


    void SetPSUFansAnimationPhase(float phase)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName("PSU_1"));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: PSU_1");
            return;
        }

        // Set the animation phase of the GPU 1 fans
        attachment.SetAnimationPhase("fans_rotate", phase);
        //DeskDebug("Attachment found in slot: Graphics_Card_1 turned animation on");
        //DeskDebug("GPU 1 fans animation phase set to: " + phase);
    }

    void SetCoolerFansAnimationPhase(float phase)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName("Cooler"));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: Cooler");
            return;
        }

        // Set the animation phase of the GPU 1 fans
        attachment.SetAnimationPhase("fans_rotate", phase);
        //DeskDebug("Attachment found in slot: Cooler turned animation on");
        //DeskDebug("Cooler fans animation phase set to: " + phase);
    }

    void SetGPU1FansAnimationPhase(float phase)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName("Graphics_Card_1"));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: Graphics_Card_1");
            return;
        }

        // Set the animation phase of the GPU 1 fans
        attachment.SetAnimationPhase("fans_rotate", phase);
        //DeskDebug("Attachment found in slot: Graphics_Card_1 turned animation on");
        //DeskDebug("GPU 1 fans animation phase set to: " + phase);
    }

    void SetGPU2FansAnimationPhase(float phase)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName("Graphics_Card_2"));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: Graphics_Card_2");
            return;
        }

        // Set the animation phase of the GPU 1 fans
        attachment.SetAnimationPhase("fans_rotate", phase);
       // DeskDebug("Attachment found in slot: Graphics_Card_2 turned animation on");
        //DeskDebug("GPU 2 fans animation phase set to: " + phase);
    }
    void SetGPU3FansAnimationPhase(float phase)
    {
        // Find the attachment by name
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName("Graphics_Card_3"));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: Graphics_Card_3");
            return;
        }

        // Set the animation phase of the GPU 1 fans
        attachment.SetAnimationPhase("fans_rotate", phase);
       // DeskDebug("Attachment found in slot: Graphics_Card_3 turned animation on");
        //DeskDebug("GPU 3 fans animation phase set to: " + phase);
    }

    void SetScreenAnimationPhase(float phase)
    {
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName("Monitor"));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: Monitor");
            return;
        }

        attachment.SetAnimationPhase("Screen_rotate", phase);
    }
    
    void SetShutDownScreenAnimationPhase(float phase)
    {
        ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachmentByName("Monitor"));
        if (!attachment)
        {
            DeskDebug("Attachment not found in slot: Monitor");
            return;
        }

        attachment.SetAnimationPhase("Shutdown_rotate", phase);
    }
    
    void Setlightson()
    {
        SetDeskLoadingTexture("Monitor",TEXTURE_LOADINGON);
        SetDeskLoadingMaterial("Monitor",MATERIAL_LOADINGON);
        SetAttachmentMaterial("Monitor", MATERIAL_SCREENON);
        SetKeyBoardTexture("Keyboard", TEXTURE_KEYBOARDON);
        SetKeyBoardMaterial("Keyboard", MATERIAL_KEYBOARDON);
        SetMouseTexture("Mouse", TEXTURE_MOUSEON);
        SetMouseMaterial("Mouse", MATERIAL_MOUSEON);
        SetMotherboardTexture("Mother_Board", TEXTURE_MOTHERBOARDON);
        SetMotherboardMaterial("Mother_Board", MATERIAL_MOTHERBOARDON);
        SetCoolerTexture("Cooler", TEXTURE_COOLERON);
        SetCoolerMaterial("Cooler", MATERIAL_COOLERON);
        SetRamTexture("Ram_1", TEXTURE_RAMON);
        SetRamMaterial("Ram_1", MATERIAL_RAMON);
        SetRamTexture("Ram_2", TEXTURE_RAMON);
        SetRamMaterial("Ram_2", MATERIAL_RAMON);
        SetRamTexture("Ram_3", TEXTURE_RAMON);
        SetRamMaterial("Ram_3", MATERIAL_RAMON);
        SetRamTexture("Ram_4", TEXTURE_RAMON);
        SetRamMaterial("Ram_4", MATERIAL_RAMON);
        SetWifirouterMaterial("Wifi_Router", MATERIAL_WIFI_ROUTERON);
        SetDeskTexture(TEXTURE_DESKON);
        SetDeskMaterial(MATERIAL_DESKON);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(LoadingscreenDisplayOff, 21000);   
    }

    void Setlightsoff()
    {
        SetshutdownanimTexture("Monitor", TEXTURE_SHUTDOWNANIMON);
        SetShutdownanimMaterial("Monitor", MATERIAL_LOADINGON);
        SetAttachmentTexture("Monitor", TEXTURE_SHUTTINGOFF);
        SetKeyBoardTexture("Keyboard", TEXTURE_KEYBOARDOFF);
        SetKeyBoardMaterial("Keyboard", MATERIAL_KEYBOARDOFF);
        SetMouseTexture("Mouse", TEXTURE_MOUSEOFF);
        SetMouseMaterial("Mouse", MATERIAL_MOUSEOFF);
        SetMotherboardTexture("Mother_Board", TEXTURE_MOTHERBOARDOFF);
        SetMotherboardMaterial("Mother_Board", MATERIAL_MOTHERBOARDOFF);
        SetCoolerTexture("Cooler", TEXTURE_COOLEROFF);
        SetCoolerMaterial("Cooler", MATERIAL_COOLEROFF);
        SetRamTexture("Ram_1", TEXTURE_RAMOFF);
        SetRamMaterial("Ram_1", MATERIAL_RAMOFF);
        SetRamTexture("Ram_2", TEXTURE_RAMOFF);
        SetRamMaterial("Ram_2", MATERIAL_RAMOFF);
        SetRamTexture("Ram_3", TEXTURE_RAMOFF);
        SetRamMaterial("Ram_3", MATERIAL_RAMOFF);
        SetRamTexture("Ram_4", TEXTURE_RAMOFF);
        SetRamMaterial("Ram_4", MATERIAL_RAMOFF);
        SetWifirouterMaterial("Wifi_Router", MATERIAL_WIFI_ROUTEROFF);
        SetDeskTexture(TEXTURE_DESKOFF);
        SetDeskMaterial(MATERIAL_DESKOFF);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ShutdownscreenDisplayOff, 21000);
    }
	  
    void LoadingscreenDisplayOff()
    {
        m_IsStarting = false;
        SetDeskLoadingTexture("Monitor",TEXTURE_LOADINGOFF);
        SetDeskLoadingMaterial("Monitor", MATERIAL_LOADINGOFF);
        SetAttachmentTexture("Monitor", TEXTURE_SCREENON);
        DeskDebug("Loadingscreendisplay off called");
    }
    void ShutdownscreenDisplayOff()
    {
        m_IsShuttingDown = false;
        SetShutDownScreenAnimationPhase(0)
        UnlockAttachments();
        SetshutdownanimTexture("Monitor", TEXTURE_SHUTDOWNANIMOFF);
        SetShutdownanimMaterial("Monitor", MATERIAL_LOADINGOFF);
        SetAttachmentTexture("Monitor", TEXTURE_SCREENOFF);
        SetAttachmentMaterial("Monitor", MATERIAL_SCREENOFF);
        DeskDebug("Shutdownscreendisplay off called");
    }

    void PlayDeskFansSound()
    {
		PlaySoundSetLoop( m_FanSound, SOUND_DESK_FANS, 1.0, 1.0 );
        DeskDebug("fansound starting called");
    }

    void StopDeskFansSound()
    {
		StopSoundSet( m_FanSound );
        DeskDebug("soundstop called"); 
    }

    void PlayDeskStartupSound()
    {
        PlaySoundSet( m_BootSound, SOUND_DESK_BOOT, 1.0, 1.0 );
        DeskDebug("startup sound starting called");
    }

    void PlayShuttingdownSound()
    {
        PlaySoundSet( m_ShutdownSound, SOUND_DESK_SHUTDOWN, 1.0, 1.0 );
        DeskDebug("shutting down sound starting called");
    }

    override void OnWorkStart()
    {
        super.OnWorkStart();
        if (!GetGame().IsServer()) return;
        m_IsPCRunning = true;
        m_IsStarting = true;
        m_IsShuttingDown = false;
        StartFanAnimationLoop();
		m_PlayDeskFansSound = true;
		m_PlayDeskStartupSound = true;
        DeskDebug("OnWorkStart called.");
        SetGPU1FansAnimationPhase(1);
        SetGPU2FansAnimationPhase(1);
        SetGPU3FansAnimationPhase(1);
        SetCoolerFansAnimationPhase(1);
        SetPSUFansAnimationPhase(1);
        SetSmallFansAnimationPhase(1);
        SetScreenAnimationPhase(1);
        LockAttachments();
        Setlightson();
        int gpuCount = GetGraphicCardCount();
        DeskDebug("GPU Count: " + gpuCount);
        DeskDebug("Fansrunning: " + m_FanSound);

		//Clean up
		m_PlayShuttingdownSound = false;
		m_StopDeskFansSound = false;

        if (gpuCount < 1)
        {
            GetCompEM().SwitchOff();
            m_IsPCRunning = false;
            DeskDebug("PC is OFF due to insufficient graphic cards.");
            GetUtopiaPcLogger().LogDebug("PC is not running due to insufficient graphic cards.");
        }
        else
        {
            GetCompEM().SwitchOn();
            DeskDebug("PC is ON.");
            GetUtopiaPcLogger().LogDebug("PC is running.");
        }
        
        // Add debug messages to print GPU attachments in specified slots
        foreach (string slotName : g_UtopiaPcGraphicCardSlots)
        {
            int slotId = InventorySlots.GetSlotIdFromString(slotName);
            ItemBase attachment = ItemBase.Cast(GetInventory().FindAttachment(slotId));

            if (attachment)
            {
                DeskDebug("GPU in slot " + slotName + ": " + attachment.GetType());
            }
            else
            {
                DeskDebug("No GPU found in slot " + slotName);
            }
        }
        RaiseDesk();
    }


    override void OnWork(float consumed_energy)
    {
        super.OnWork(consumed_energy);
        if (!GetGame().IsServer()) return;
        GetUtopiaPcLogger().LogDebug("OnWork");

        if (GetGraphicCardCount() < 1)
        {
            GetCompEM().SwitchOff();
            return;
        }

        int lifetime = GetTotalGraphicCardLifeTime();
        GetUtopiaPcLogger().LogDebug("lifetime:" + GetTotalGraphicCardLifeTime());

        float quantityToRemoveGraphicCard = 0;

        // Ensure that lifetime is not zero to avoid division by zero
        if (lifetime != 0)
        {
            quantityToRemoveGraphicCard = (6000) / lifetime;
        }
        DeskDebug("OnWork called. Consumed energy: " + consumed_energy); 
        DecreaseAllGraphicCardQuantity(quantityToRemoveGraphicCard);

        if(GetTotalQuantityGraphicCardQuantity() < 1)
        {
            GetCompEM().SwitchOff();
            return;
        }
    }
    
    override void OnWorkStop() 
    {
        super.OnWorkStop();
        if (!GetGame().IsServer()) return;
        foreach (string coinName, bool isMiningActive : m_CoinMiningStatus)
        {
            if (isMiningActive)
            {
                StopMining(coinName);
            }
        }

        m_IsPCRunning = false;
        m_IsStarting = false;
        m_IsShuttingDown = true;
        SetGPU1FansAnimationPhase(0);
        SetGPU2FansAnimationPhase(0);
        SetGPU3FansAnimationPhase(0);
        SetCoolerFansAnimationPhase(0);
        SetPSUFansAnimationPhase(0);
        SetSmallFansAnimationPhase(0);
        SetScreenAnimationPhase(0);
        SetShutDownScreenAnimationPhase(1)
        StopFanAnimationLoop();
        Setlightsoff();
		m_PlayShuttingdownSound = true;
		m_StopDeskFansSound = true;
        DeskDebug("OnWorkStop called. GPU Count: " + GetGraphicCardCount());
        DeskDebug("OnWorkStop called. m_IsPCRunning: " + m_IsPCRunning);
        if (!m_IsPCRunning) {
            DeskDebug("OnWorkStop called.");
            GetUtopiaPcLogger().LogDebug("OnWorkStop");
            lowerDesk();
        }
		
		//Cleanup
		m_PlayDeskFansSound = false;
		m_PlayDeskStartupSound = false;
    }
 
	//Need this in order to ensure that sounds are played on the client side
	protected void EOnPostSimulate(IEntity other, float timeSlice)
	{
		if (GetGame().IsClient())
		{
			if (m_PlayDeskStartupSound)
			{
				PlayDeskStartupSound();	
				m_PlayDeskStartupSound = false;
			}
			
			if (m_PlayDeskFansSound)
			{
				PlayDeskFansSound();	
				m_PlayDeskFansSound = false;
			}
			
			if (m_PlayShuttingdownSound)
			{
				PlayShuttingdownSound();	
				m_PlayShuttingdownSound = false;
			}
			
			if (m_StopDeskFansSound)
			{
				StopDeskFansSound();	
				m_StopDeskFansSound = false;
			}
		}
	}

 
    void DecreaseAllGraphicCardQuantity(float quantityToRemove)
    {
        GetUtopiaPcLogger().LogDebug("DecreaseAllGraphicCardQuantity:" + quantityToRemove);
        
        DeskDebug("DecreaseAllGraphicCardQuantity called. Quantity to remove: " + quantityToRemove);
        
        foreach(string slotName : g_UtopiaPcGraphicCardSlots)
        {
            DecreaseGraphicCardQuantityAtSlot(slotName, quantityToRemove);
        }
    }

    int GetTotalQuantityGraphicCardQuantity()
    {
        int qty = 0;
        foreach(string slotName : g_UtopiaPcGraphicCardSlots)
        {
            // Find the attachment by name and safely cast it to ItemBase
            ItemBase graphicCard = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
            if (!graphicCard)
                continue;

            qty += graphicCard.GetQuantity();
        }

        return qty;
    }


    void DecreaseGraphicCardQuantityAtSlot(string slotName, float quantityToRemove)
    {
        ItemBase graphicCard = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
        if(!graphicCard)
        {
            DeskDebug("No graphic card in slot: " + slotName + ". Cannot decrease quantity.");
            return;           
        }
        int currentQuantity = graphicCard.GetQuantity();

        graphicCard.SetQuantity(currentQuantity - quantityToRemove);

        GetUtopiaPcLogger().LogDebug("new graphic card quantity :" + graphicCard.GetQuantity());
    }

    bool HasRequiredComponentsForMining()
    {
        // Implement logic to check if the necessary components (e.g., GPUs, power, etc.) are present
        return GetGraphicCardCount() > 0 && GetCompEM().IsWorking(); // Example condition
    }

    void InitializeCoinMiningStatus()
    {
        foreach (string coinName, UtopiaCoinSettings coinSettings : GetUtopiaPcModule().GetSettings().coinSettings)
        {
            if (!m_CoinMiningStatus.Contains(coinName))
            {
                m_CoinMiningStatus.Insert(coinName, false); // Initialize all coins to 'not mining'
            }
        }
    }


    bool IsMiningActive()
    {
        foreach (bool isMiningActive : m_CoinMiningStatus)
        {
            if (isMiningActive)
            {
                return true;
            }
        }
        return false;
    }


    ref map<string, bool> m_CoinMiningStatus = new map<string, bool>();

    bool IsAnyMiningActive()
    {
        foreach (bool isMining : m_CoinMiningStatus)
        {
            if (isMining)
            {
                return true;
            }
        }
        return false;
    }


    void StartMining()
    {
        DeskDebug("StartMining method called.");

        foreach (string coinName, UtopiaCoinSettings coinSettings : GetUtopiaPcModule().GetSettings().coinSettings)
        {
            if (!m_CoinMiningStatus.Contains(coinName))
            {
                m_CoinMiningStatus.Insert(coinName, false);
            }

            if (!coinSettings)
            {
                DeskDebug("Coin settings not found for " + coinName + ". Cannot start mining.");
                continue;
            }

            if (CheckForSufficientPowerAndGPUs(coinSettings))
            {
                m_CoinMiningStatus.Set(coinName, true); // Mark mining as active
                DeskDebug(coinName + " mining started.");

                foreach (string gpuType, float hashRate : coinSettings.hashRates)
                {
                    if (IsGPUTypeInUse(gpuType))
                    {
                        float yield = coinSettings.GetYield(gpuType);
                        int hashTime = hashRate;

                        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(HandleMining, hashTime * 1000, false, coinName, gpuType, yield);
                    }
                }
            }
            else
            {
                DeskDebug("Insufficient power or GPUs for mining " + coinName + ". Cannot start mining.");
            }
        }
    }


    float GetGPUSpecificYield(UtopiaCoinSettings coinSettings)
    {
        // Loop through the GPU types in the hashRates map to check if any is in use
        foreach (string gpuType, float _ : coinSettings.hashRates)
        {
            if (IsGPUTypeInUse(gpuType))
            {
                return coinSettings.GetYield(gpuType); // Get the yield for the specific GPU
            }
        }
        return 0; // Default or fallback yield
    }


    int GetGPUSpecificHashTime(UtopiaCoinSettings coinSettings)
    {
        // Loop through the GPU types in the hashRates map to check if any is in use
        foreach (string gpuType, float _ : coinSettings.hashRates)
        {
            if (IsGPUTypeInUse(gpuType))
            {
                return coinSettings.GetHashRate(gpuType); // Get the hash rate for the specific GPU
            }
        }
        return 10; // Default or fallback hash time
    }


    bool IsGPUTypeInUse(string gpuType)
    {
        // Implement the logic to check if a particular GPU type is currently in use
        // This might involve checking slots, availability, etc.
        foreach (string slotName : g_UtopiaPcGraphicCardSlots)
        {
            ItemBase graphicCard = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
            if (graphicCard && graphicCard.GetType() == gpuType)
            {
                return true;
            }
        }
        return false;
    }

    void HandleMining(string coinName, string gpuType, float yield)
    {
        ProcessMining(coinName, gpuType, yield);
    }


    void ProcessMining(string coinName, string gpuType, float yield)
    {
        if (m_CoinMiningStatus.Contains(coinName) && m_CoinMiningStatus.Get(coinName))
        {
            DeskDebug("Processing mining for coin: " + coinName + " with GPU: " + gpuType);

            UtopiaCoinSettings coinSettings = GetUtopiaPcModule().GetSettings().GetCoinSettings(coinName);
            if (coinSettings && CheckForSufficientPowerAndGPUs(coinSettings))
            {
                IncrementCoin(coinName, coinSettings, yield);
                DamageGPUsAndPowerSupply(coinSettings); // Decrease GPU health and damage the power supply

                if (AreAllGPUsDepleted())
                {
                    DeskDebug("All GPUs depleted. Stopping mining for " + coinName + ".");
                    StopMining(coinName);
                }
                else
                {
                    DeskDebug("Continuing mining for coin: " + coinName);
                    ScheduleNextMiningCycle(coinSettings, gpuType);
                }
            }
            else
            {
                DeskDebug("Insufficient power or GPUs for mining " + coinName + ". Stopping mining.");
                StopMining(coinName);
            }
        }
        else
        {
            DeskDebug("Mining is not active for " + coinName + ". ProcessMining should not be called.");
        }
    }

    void ScheduleNextMiningCycle(UtopiaCoinSettings coinSettings, string gpuType)
    {
        int hashTime = coinSettings.GetHashRate(gpuType);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(HandleMining, hashTime * 1000, false, coinSettings.coinName, gpuType, coinSettings.GetYield(gpuType));
    }

    void StopMining(string coinName)
    {
        if (!m_CoinMiningStatus.Contains(coinName) || !m_CoinMiningStatus.Get(coinName))
        {
            DeskDebug(coinName + " mining is already stopped. No action taken.");
            return;
        }

        m_CoinMiningStatus.Set(coinName, false); // Mark mining as inactive
        DeskDebug(coinName + " mining stopped.");
    }


    void DamageGPUsAndPowerSupply(UtopiaCoinSettings coinSettings)
    {
        // Damage the GPUs
        foreach (string slotName : g_UtopiaPcGraphicCardSlots)
        {
            ItemBase gpu = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
            if (gpu && coinSettings.CanCardMine(gpu.GetType()))
            {
                float gpuDamageAmount = coinSettings.GetDamageRate(gpu.GetType()); 
                gpu.DecreaseHealth(gpuDamageAmount, false); // Decrease health by the damage amount
            }
        }

        // Damage the Power Supply Unit (PSU)
        ItemBase psu = ItemBase.Cast(GetInventory().FindAttachmentByName("PSU_1"));
        if (psu)
        {
            float psuDamageAmount = 0.001; 
            psu.DecreaseHealth(psuDamageAmount, false); // Decrease health by the damage amount
        }
    }


    bool AreAllGPUsDepleted()
    {
        foreach (string slotName : g_UtopiaPcGraphicCardSlots)
        {
            ItemBase gpu = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
            if (gpu && gpu.GetHealth() > 0)
            {
                return false;
            }
        }
        return true; // All GPUs are depleted
    }

    bool CheckForSufficientPowerAndGPUs(UtopiaCoinSettings coinSettings) {
        foreach (string slotName : g_UtopiaPcGraphicCardSlots) {
            ItemBase gpu = ItemBase.Cast(GetInventory().FindAttachmentByName(slotName));
            if (gpu && coinSettings.CanCardMine(gpu.GetType()) && PowerSupplyCheck()) {
                return true;
            }
        }
        return false;
    }

    bool PowerSupplyCheck() 
    {
        ItemBase powerSupply = ItemBase.Cast(GetInventory().FindAttachmentByName("PSU_1"));
        return powerSupply && powerSupply.GetHealth() > 0;
    }


    void IncrementCoin(string coinName, UtopiaCoinSettings coinSettings, float yield)
    {
        CargoBase cargo = GetInventory().GetCargo();
        float incrementAmount = yield; // Yield based on the GPU
        float quantityToAdd;

        if (cargo)
        {
            bool coinAdded = false;

            // Loop through all available slots in the cargo
            for (int i = 0; i < cargo.GetItemCount(); i++)
            {
                EntityAI itemInCargo = cargo.GetItem(i);
                ItemBase coinItem = ItemBase.Cast(itemInCargo);

                if (coinItem && coinItem.GetType() == coinSettings.itemClass)
                {
                    float maxQuantity = coinItem.GetQuantityMax();

                    if (coinItem.GetQuantity() < maxQuantity)
                    {
                        quantityToAdd = Math.Min(maxQuantity - coinItem.GetQuantity(), incrementAmount);
                        coinItem.AddQuantity(quantityToAdd);
                        incrementAmount -= quantityToAdd;

                        if (incrementAmount <= 0)
                        {
                            coinAdded = true;
                            break;
                        }
                    }
                }
            }

            // If there is still some amount left, create new items in available slots
            while (incrementAmount > 0)
            {
                ItemBase newCoinItem = ItemBase.Cast(GetInventory().CreateInInventory(coinSettings.itemClass));

                if (newCoinItem)
                {
                    quantityToAdd = Math.Min(newCoinItem.GetQuantityMax(), incrementAmount);
                    newCoinItem.SetQuantity(quantityToAdd);
                    incrementAmount -= quantityToAdd;

                    if (incrementAmount <= 0)
                    {
                        coinAdded = true;
                        break;
                    }
                }
                else
                {
                    break; // Stop if no more items can be created
                }
            }

            if (!coinAdded)
            {
                DeskDebug("Failed to add the coin to the cargo.");
            }
        }
        else
        {
            DeskDebug("No cargo found in the desk.");
        }
    }


    void WithdrawCoins(PlayerBase player)
    {
        foreach (string coinName, float amount : m_CoinsMined)
        {
            if (amount > 0)
            {
                UtopiaCoinSettings coinSettings = GetUtopiaPcModule().GetSettings().GetCoinSettings(coinName);
                if (coinSettings)
                {
                    float remainingAmount = WithdrawCoin(player, coinSettings.itemClass, amount);
                    m_CoinsMined.Set(coinName, remainingAmount); // Update remaining amount after withdrawal
                }
            }
        }
    }

    float WithdrawCoin(PlayerBase player, string itemType, float amount)
    {
        int fullCoins = Math.Floor(amount);
        float fractionalCoin = amount - fullCoins;
        float remainingAmount = amount;

        for (int i = 0; i < fullCoins; i++)
        {
            ItemBase coinItem = ItemBase.Cast(player.GetInventory().CreateInInventory(itemType));
            if (!coinItem)
            {
                // If inventory is full, drop the item at player's feet
                coinItem = ItemBase.Cast(GetGame().CreateObject(itemType, player.GetPosition()));
            }

            if (coinItem)
            {
                coinItem.SetQuantity(1);
                remainingAmount -= 1;
            }
            else
            {
                break; // Stop if no more items can be created
            }
        }

        // Handle fractional coins if the game supports it
        if (fractionalCoin > 0 && remainingAmount > 0)
        {
            ItemBase fractionalItem = ItemBase.Cast(player.GetInventory().CreateInInventory(itemType));
            if (!fractionalItem)
            {
                // If inventory is full, drop the item at player's feet
                fractionalItem = ItemBase.Cast(GetGame().CreateObject(itemType, player.GetPosition()));
            }

            if (fractionalItem)
            {
                fractionalItem.SetQuantity(fractionalCoin);
                remainingAmount -= fractionalCoin;
            }
        }

        return remainingAmount; // Return any remaining amount that wasn't withdrawn
    }






	override bool IsElectricAppliance()
	{
		return true;
	}

    override void SetActions()
    {
		super.SetActions();
		AddAction(ActionTurnOffUtopiaPC);
        AddAction( ActionTurnOnUtopiaPC );
        AddAction(ActionStartMining);
        AddAction(ActionStopMining);
        AddAction(ActionWithdrawCrypto);
    }
};