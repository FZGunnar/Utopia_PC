class BaseLaptop extends ItemBase 
{
    private int netSynch_laptopId = -1;

    ref array<BaseCamera> arrayCamera = new array<BaseCamera>();

    void BaseLaptop()
    {
        RegisterNetSyncVariableInt("netSynch_laptopId");
    }

    int GetLaptopId()
    {
        if (netSynch_laptopId == -1)
            GenerateLaptopId();
            
        return netSynch_laptopId;
    }

    array<BaseCamera> GetCameras()
    {
        GetBaseCameraLogger().LogDebug("Laptop:GetCameras");
        arrayCamera.Clear();
        array<BaseCamera> arrCamera = BaseCamera.GetCameras();
        foreach(BaseCamera baseCamera : arrCamera)
        {
            if(!baseCamera)
                continue;

            GetBaseCameraLogger().LogDebug("baseCamera.GetLaptopId()" + baseCamera.GetLaptopId());
            GetBaseCameraLogger().LogDebug("baseCamera.netSynch_laptopId" + netSynch_laptopId);
            if(baseCamera.GetLaptopId() == netSynch_laptopId)
                arrayCamera.Insert(baseCamera);
        }

        GetBaseCameraLogger().LogDebug("Laptop:GetCameras result count: " + arrayCamera.Count());

        return arrayCamera;
    }

	bool HasRequiredComponentsForCCTV() 
	{ 
		return HasWifiRouter() && HasRequiredKeyboard() && HasRequiredMonitor() && HasRequiredMouse() && HasRequiredMother_Board() && GetPSUCount() >= 1 && GetRamCount() >= 1 && GetKingstonCount() >= 1 && GetGraphicCardCount() >= 1 && GetFanCount() >= 1 && HasCooler();  
	}

	bool HasRequiredKeyboard()
	{
		return GetInventory().FindAttachmentByName("Keyboard") != null;
	}

	bool HasRequiredMonitor()
	{
		return GetInventory().FindAttachmentByName("Monitor") != null;
	}

	bool HasRequiredMouse()
	{
		return GetInventory().FindAttachmentByName("Mouse") != null;
	}

	bool HasRequiredMother_Board()
	{
		return GetInventory().FindAttachmentByName("Mother_Board") != null;
	}

	bool HasWifiRouter()
	{
        return GetInventory().FindAttachmentByName("WiFi_Router") != null;
    }

	int GetPSUCount()
	{
		int count = 0;
		if(GetInventory().FindAttachmentByName("PSU_1"))
			count++;

		if(GetInventory().FindAttachmentByName("PSU_2"))
			count++;

		return count;
	}  

	int GetKingstonCount()
	{
		int count = 0;
		if(GetInventory().FindAttachmentByName("Kingston_1"))
			count++;

		if(GetInventory().FindAttachmentByName("Kingston_2"))
			count++;

		if(GetInventory().FindAttachmentByName("Kingston_3"))
			count++;

		return count;
	}  

	int GetRamCount()
	{
		int count = 0;
		if(GetInventory().FindAttachmentByName("Ram_1"))
			count++;

		if(GetInventory().FindAttachmentByName("Ram_2"))
			count++;

		if(GetInventory().FindAttachmentByName("Ram_3"))
			count++;

		if(GetInventory().FindAttachmentByName("Ram_4"))
			count++;

		return count;
	}  

	int GetGraphicCardCount()
	{
		int count = 0;
		if(GetInventory().FindAttachmentByName("Graphics_Card_1"))
			count++;

		if(GetInventory().FindAttachmentByName("Graphics_Card_2"))
			count++;

		if(GetInventory().FindAttachmentByName("Graphics_Card_3"))
			count++;

		return count;
	}

	int GetFanCount()
	{
		int count = 0;
		if(GetInventory().FindAttachmentByName("Fan_1"))
			count++;

		if(GetInventory().FindAttachmentByName("Fan_2"))
			count++;

		return count;
	}

	bool HasCooler()
	{
        return GetInventory().FindAttachmentByName("Cooler")!= null;
    }

    override void EEInit()
	{
		super.EEInit();
    }

    void GenerateLaptopId()
    {
        GetBaseCameraLogger().LogDebug("Laptop:GenerateLaptopId");
        netSynch_laptopId = BaseCameraHelper.GetUniqueId(this);

        GetBaseCameraLogger().LogDebug("Laptop:netSynch_laptopId " + netSynch_laptopId.ToString());
        SetSynchDirty();
    }

    override void OnStoreSave( ParamsWriteContext ctx )
	{
		super.OnStoreSave( ctx );
		ctx.Write( netSynch_laptopId );
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		if (!ctx.Read( netSynch_laptopId ))
			return false;
		
		SetSynchDirty();	

		return true;
	}

    override void SetActions()
    {
		super.SetActions();
		AddAction(ActionPlugIn);
        AddAction( ActionTogglePlaceObject );
		AddAction( ActionDeployObject );
    }
};