class ActionBuildUtopiaDeskCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
        float time = SetBuildingDuration(m_ActionData.m_MainItem);
        m_ActionData.m_ActionComponent = new CAContinuousTime(time);
    }

    float SetBuildingDuration(ItemBase item)
    {
        if (item.IsInherited(Screwdriver))
        {
            return 15.0;
        }
        return UATimeSpent.DEFAULT_DECONSTRUCT;
    }
}

class ActionBuildUtopiaDesk : ActionContinuousBase
{
    void ActionBuildUtopiaDesk()
    {
        m_CallbackClass = ActionBuildUtopiaDeskCB; // Using the vanilla callback class
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
    }

    override string GetText()
    {
        return "Assemble Utopia Desk";
    }

    override void CreateConditionComponents()  
    {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }

    override typename GetInputType()
    {
        return ContinuousInteractActionInput;
    }

    override bool CanBeUsedLeaning()
    {
        return false;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        Object target_object = target.GetObject();
        Utopia_Desk_Build hologram;

        if (player.IsPlacingLocal() || player.IsPlacingServer())
            return false;

        if(!player.GetItemInHands().IsKindOf("Screwdriver") && !player.GetItemInHands().IsInherited(Screwdriver))
			return false;

        if (CastTo(hologram, target_object))
            return hologram.IsDeskTop1Attached() && hologram.IsDeskTop2Attached() && hologram.IsLeg1Attached() && hologram.IsLeg2Attached() && hologram.IsLeg3Attached() && hologram.IsPCCaseAttached();

        return false;
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        Object target_object = action_data.m_Target.GetObject();
        Utopia_Desk_Build hologramBuild;
        vector position, orientation;

        if (CastTo(hologramBuild, target_object))
        {
            position = hologramBuild.GetPosition();
            orientation = hologramBuild.GetOrientation();
            GetGame().ObjectDelete(hologramBuild);
            hologramBuild.DeleteSave();
            EntityAI hologram = EntityAI.Cast(GetGame().CreateObjectEx("Utopia_Desk", position, ECE_PLACE_ON_SURFACE));
            hologram.SetPosition(position);
            hologram.SetOrientation(orientation);
        }
    }
}
