class Utopia_Desk_Build : Container_Base
{
    // Constructor
    void Utopia_Desk_Build()
    {
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionBuildUtopiaDesk);
        AddAction(ActionDismantleUtopiaPCDeskHologram);
    }

    override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }

    override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }

    override bool CanSwapItemInCargo(EntityAI child_entity, EntityAI new_entity)
    {
        return false;
    }

    bool IsDeskTop1Attached()
    {
        return FindAttachmentBySlotName("Slot_Desk_Top_1") != null;
    }

    bool IsDeskTop2Attached()
    {
        return FindAttachmentBySlotName("Slot_Desk_Top_2") != null;
    }

    bool IsLeg1Attached()
    {
        return FindAttachmentBySlotName("Slot_Leg_1") != null;
    }

    bool IsLeg2Attached()
    {
        return FindAttachmentBySlotName("Slot_Leg_2") != null;
    }

    bool IsLeg3Attached()
    {
        return FindAttachmentBySlotName("Slot_Leg_3") != null;
    }

    bool IsPCCaseAttached()
    {
        return FindAttachmentBySlotName("Slot_PC_Case") != null;
    }
}
