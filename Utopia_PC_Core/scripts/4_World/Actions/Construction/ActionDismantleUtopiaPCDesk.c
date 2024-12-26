class ActionDismantleUtopia_DeskCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DECONSTRUCT);
    }
}

class ActionDismantleUtopia_Desk : ActionContinuousBase
{
    void ActionDismantleUtopia_Desk()
    {
        m_CallbackClass = ActionDismantleUtopia_DeskCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
        m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
    }

    override void CreateConditionComponents()
    {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNonRuined(UAMaxDistances.BASEBUILDING);
    }

    override string GetText()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player)
        {
            return "#dismantle";
        }

        return "";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!target)
            return false;

        Utopia_Desk desk = Utopia_Desk.Cast(target.GetObject());

        if (!desk)
            return false;

        string selection = desk.GetActionComponentName(target.GetComponentIndex());

        if (selection == "interact_pos")
        {
            return true;
        }
        return false;
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        Utopia_Desk desk = Utopia_Desk.Cast(action_data.m_Target.GetObject());

        if (desk)
        {
            ReturnBuildingMaterials(desk);
            desk.Delete();
        }

        action_data.m_MainItem.DecreaseHealth(UADamageApplied.DISMANTLE, false);

        // Create the kit after dismantling
        ItemBase kit = ItemBase.Cast(GetGame().CreateObjectEx("Utopia_Desk_Manual", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
    }

    override string GetAdminLogMessage(ActionData action_data)
    {
        return " dismantled " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName() + " at " + action_data.m_Player.GetPosition();
    }

    void ReturnBuildingMaterials(Utopia_Desk desk)
    {
        vector spawnPos = desk.ModelToWorld(desk.GetMemoryPointPos("materials_spawn"));

        CreateDeskPart("PC_Bars", spawnPos);
        CreateDeskPart("PC_Desk_Top_1", spawnPos);
        CreateDeskPart("PC_Desk_Top_2", spawnPos);
        CreateDeskPart("PC_Desk_PC_Leg_1", spawnPos);
        CreateDeskPart("PC_Desk_PC_Leg_2", spawnPos);
        CreateDeskPart("PC_Desk_PC_Leg_3", spawnPos);
    }

    void CreateDeskPart(string partName, vector spawnPos)
    {
        ItemBase part = ItemBase.Cast(GetGame().CreateObjectEx(partName, spawnPos, ECE_PLACE_ON_SURFACE));
        part.PlaceOnSurface();
    }
}
