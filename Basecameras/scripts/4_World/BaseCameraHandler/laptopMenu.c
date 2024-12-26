class ILaptopMenu : UIScriptedMenu
{
    private Widget wNoBatteryPanel;
    private XComboBoxWidget wComboSwitchCamera;
    private TextWidget wTextBatteryPerCent;

	private Widget wBackground;

    BaseLaptop laptop;

	BaseCamera currentCamera;

	ref array<BaseCamera> arrCamera;

	protected Camera cameraScreen;

	protected Utopia_Desk desk;

	private int HOME_SCREEN = 0;

	private bool CAMERA_TURN_ON = true;
	private bool CAMERA_TURN_OFF = false;

	private bool screenIsOn = false;

	vector playerPosition;
	vector playerCameraPos;

	void ILaptopMenu()
	{
		arrCamera = new array<BaseCamera>();
	}

    override Widget Init()
	{
		layoutRoot 			= GetGame().GetWorkspace().CreateWidgets( "Basecameras/datasets/layouts/laptopMenu.layout" );
		wBackground         = Widget.Cast(layoutRoot.FindAnyWidget("background"));
		wNoBatteryPanel		= Widget.Cast(layoutRoot.FindAnyWidget("noBatteryPanel"));
		wComboSwitchCamera	= XComboBoxWidget.Cast(layoutRoot.FindAnyWidget("comboSwitchCamera"));
		wTextBatteryPerCent = TextWidget.Cast(layoutRoot.FindAnyWidget("textBatteryPerCent"));
		layoutRoot.Show(false);

		return layoutRoot;
	}

	void InitLoading()
	{
		GetBaseCameraLogger().LogDebug("InitLoading");
		arrCamera = laptop.GetCameras();
		InitLoadingCameras();
		CreateCameraScreen();
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(UpdateScreen, 1000, true);
	}

	void InitLoadingCameras()
	{
		wComboSwitchCamera.ClearAll();
		wComboSwitchCamera.AddItem("HOME");
        for (int i = 0; i < arrCamera.Count(); i++)
        {
            wComboSwitchCamera.AddItem(string.Format("Camera %1", i));
        }

		wComboSwitchCamera.SetCurrentItem(0);
	}

	void ResetEffects()
	{
		PPEffects.ResetDOFOverride();
		PPEffects.ResetAll();
		PPEffects.SetNVParams(1.0, 0.0, 2.35, 2.75);
	}

	void GiveEffects()
	{
		PPEffects.SetColorizationNV(0.75, 0.75, 0.75);
		PPEffects.SetNVParams(3.0, GetNoiseIntensity(), 9.0, 1.0);
	}

	float GetNoiseIntensity()
	{
		GetBaseCameraLogger().LogDebug("GetNoiseIntensity");
		if(!currentCamera)
			return 0;

		float distance = vector.Distance(currentCamera.GetPosition(), laptop.GetPosition());

		GetBaseCameraLogger().LogDebug("distance = " + distance);

		if(distance > 1000)
			return 100;

		if(distance > 750)
			return 75;
		
		if(distance > 500)
			return 50;

		if(distance > 250)
            return 25;

		return 0.0;
	}

	void UpdateScreen()
	{
		GetBaseCameraLogger().LogDebug("UpdateScreen");
		if(!currentCamera)
			return;
		
		UpdateBattery();

		if(IsCameraTurnedOff() || IsBatteryOut()){
			GetBaseCameraLogger().LogDebug("IsCameraTurnedOff");
			SwitchOffPreviousCamera();
			ShowBlackScreen();
            return;
		}

		HideBlackScreen();
		UpdateCameraScreen();
	}

	bool IsCameraTurnedOff()
	{
		return !currentCamera.GetCameraState();
	}

	bool IsBatteryOut()
    {
		int energyBattery = currentCamera.GetBatteryQuantity() * 2;
		if(energyBattery > 0)
			return false;
		
        return true;
    }

	void UpdateBattery()
	{
		GetBaseCameraLogger().LogDebug("UpdateBattery");
		int energyBattery = currentCamera.GetBatteryQuantity() * 2;
        wTextBatteryPerCent.SetText(energyBattery.ToString() + "%");
	}

	void CreateCameraScreen()
	{
		GetBaseCameraLogger().LogDebug("CreateCameraScreen");
		playerPosition = GetGame().GetPlayer().GetPosition();
		playerPosition[1] = playerPosition[1] + 2;

		vector playerCameraPos = GetGame().GetCurrentCameraDirection();

		cameraScreen = g_Game.CreateObject( "staticcamera", playerPosition, true );
		cameraScreen.SetActive( true );
		ShowCameraOnPlayer();
	}

	void UpdateCameraScreen()
	{
		if(!currentCamera)
			return;

		cameraScreen.SetPosition( currentCamera.ModelToWorld( currentCamera.GetMemoryPointPos("camera_start") ) );
		cameraScreen.LookAt( currentCamera.ModelToWorld( currentCamera.GetMemoryPointPos("camera_end") ) );
	}

	void ShowCameraOnPlayer()
	{
		Utopia_Desk desk = Utopia_Desk.Cast(laptop);

		cameraScreen.SetPosition( desk.ModelToWorld( desk.GetMemoryPointPos("pos_start") ));
		cameraScreen.LookAt( desk.ModelToWorld( desk.GetMemoryPointPos("pos_end") ) );
	}

	void DeleteCameraScreen()
	{
		GetBaseCameraLogger().LogDebug("DeleteCameraScreen");

		if(!cameraScreen)
			return;
		
		screenIsOn = false;
		cameraScreen.SetActive( false );
		GetGame().ObjectDelete(cameraScreen);
	}

	void ShowBlackScreen()
	{
		GetBaseCameraLogger().LogDebug("ShowBlackScreen");
		wBackground.SetColor(ARGB(255, 0, 0, 0) );
		wNoBatteryPanel.Show(true);
	}

	void HideBlackScreen()
	{
		GetBaseCameraLogger().LogDebug("ShowBlackScreen");
		wBackground.SetColor(ARGB(0, 0, 0, 0) );
		wNoBatteryPanel.Show(false);
	}

	void ShowHomeScreen()
	{
		GetBaseCameraLogger().LogDebug("ShowHomeScreen");
		HideBlackScreen();
		wComboSwitchCamera.SetCurrentItem(HOME_SCREEN);
		ShowCameraOnPlayer();
	}

	void OnSwitchCamera()
    {
		GetBaseCameraLogger().LogDebug("SwitchCamera");
		SwitchOffPreviousCamera();
		
		currentCamera = GetCurrentCamera();
		if(!currentCamera){
			ShowHomeScreen();
            return;
		}

		GiveEffects();
		SwitchOnCamera();
	}

	BaseCamera GetCurrentCamera()
	{	
		GetBaseCameraLogger().LogDebug("GetCurrentCamera");
		int idx = wComboSwitchCamera.GetCurrentItem();

		if(idx == HOME_SCREEN)
            return null;

		return arrCamera[idx - 1];
	}

	void SwitchOnCamera()
	{
		GetBaseCameraLogger().LogDebug("SwitchOnCamera");
		if(!currentCamera)
			return;

		SwitchCameraState(currentCamera, CAMERA_TURN_ON);
	}

	void SwitchOffPreviousCamera()
	{
		GetBaseCameraLogger().LogDebug("SwitchOffPreviousCamera");
		if(!currentCamera)
			return;

        SwitchCameraState(currentCamera, CAMERA_TURN_OFF);
	}

	void SwitchCameraState(BaseCamera camera, bool state)
	{
		GetRPCManager().SendRPC("BaseCamera", "SwitchBaseCameraRequest",  new Param2<BaseCamera,bool>(camera, state), true, null);
	}

    override void OnShow()
	{
		super.OnShow();
		GetGame().GetMission().PlayerControlDisable( INPUT_EXCLUDE_ALL );
		layoutRoot.Show(true);
		GetGame().GetUIManager().ShowUICursor(true);
        GetGame().GetMission().GetHud().Show(false);
		SetFocus(layoutRoot);
		GiveEffects();
	}

	void ResetPlayerCamera()
	{
		PlayerBase player = GetGame().GetPlayer();
		GetGame().SelectPlayer( NULL, player );
	}

	override void OnHide()
	{
		super.OnHide();
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(UpdateScreen);
		GetGame().GetInput().ResetGameFocus();
		GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetUIManager().ShowUICursor(false);
        GetGame().GetMission().GetHud().Show(true);
		SwitchOffPreviousCamera();
		DeleteCameraScreen();
		arrCamera.Clear();
		ResetPlayerCamera();
		ResetEffects();
	}

    override bool OnClick(Widget w, int x, int y, int button)
	{
		if(w == wComboSwitchCamera)
        {
            OnSwitchCamera();
			return true;
        }

		return true;
	}

    void SetLaptop(BaseLaptop _laptop)
	{
		laptop = _laptop;
	}
}