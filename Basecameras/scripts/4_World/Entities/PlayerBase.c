modded class PlayerBase
{
    ref ILaptopMenu iLaptopMenu;

    BaseLaptop registeredLaptop;

    int registeredLaptopID = -1;

    vector laptopPosition = Vector(0,0,0);

    void SetRegisteredLaptop(BaseLaptop registeredLaptop)
    {
        this.registeredLaptop = registeredLaptop;
        registeredLaptopID = registeredLaptop.GetLaptopId();
        laptopPosition = registeredLaptop.GetPosition();
    }

    bool IsLaptopTooFar()
    {
        return vector.Distance(GetPosition(), laptopPosition) > 1000;
    }

    int GetRegisteredLaptopId()
    {
        return registeredLaptopID;
    }

    override void SetActions()
    {
		super.SetActions();
        AddAction(ActionOpenCameraMenu);
        AddAction(ActionRegisterLaptopForCamera);
    }
}