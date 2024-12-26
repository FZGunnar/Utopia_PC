class CraftFullUtopiaRTX2080TI extends RecipeBase
{
    override void Init()
    {
        m_Name = "Repair Utopia RTX 2080TI";  // Name of the crafting recipe
        m_IsInstaRecipe = false;  // The crafting process will take time
        m_AnimationLength = 10;  // Duration of the crafting animation
        m_Specialty = 0.01;  // Defines crafting specialty

        // Conditions for Ingredient 1: Utopia_RTX_2080TI (damaged card)
        m_MinDamageIngredient[0] = -1;  // Minimum damage (must be at least somewhat damaged)
        m_MaxDamageIngredient[0] = -1;  // Maximum damage
        m_MinQuantityIngredient[0] = -1;  // No quantity limit for the graphics card
        m_MaxQuantityIngredient[0] = -1;

        // Conditions for Ingredient 2: Utopia_GpuRepairKit
        m_MinDamageIngredient[1] = -1;  // No minimum damage for the repair kit
        m_MaxDamageIngredient[1] = 3;  // Maximum damage for the repair kit
        m_MinQuantityIngredient[1] = 1;  // At least 1 repair kit needed
        m_MaxQuantityIngredient[1] = -1;

        // Ingredient 1: Utopia_RTX_2080TI
        InsertIngredient(0, "Utopia_RTX_2080TI");
        m_IngredientAddHealth[0] = 0;  // Health stays the same until repaired
        m_IngredientSetHealth[0] = -1;  // Keep the original health until the result
        m_IngredientAddQuantity[0] = 0;  // No quantity adjustment for the card
        m_IngredientDestroy[0] = true;  // The GPU won't be destroyed, it will be repaired

        // Ingredient 2: Utopia_GpuRepairKit
        InsertIngredient(1, "Utopia_GpuRepairKit");
        m_IngredientAddHealth[1] = 0;  // No health adjustment
        m_IngredientSetHealth[1] = -1;  // Health stays the same for the repair kit until used
        m_IngredientAddQuantity[1] = -1;  // The repair kit quantity will be reduced by 1
        m_IngredientDestroy[1] = true;  // The repair kit will be destroyed after use

        // Result: Utopia_RTX_2080TI (repaired)
        AddResult("Utopia_RTX_2080TI");

        m_ResultSetFullQuantity[0] = true;  // Full quantity (for items that stack)
        m_ResultSetQuantity[0] = 1;  // Quantity of the repaired GPU is 1
        m_ResultSetHealth[0] = 100;  // The result will have full health (repaired)
        m_ResultInheritsHealth[0] = -1;  // Not inheriting health from any ingredient
        m_ResultInheritsColor[0] = -1;  // Not inheriting color
        m_ResultToInventory[0] = 1;  // Goes into hands
        m_ResultUseSoftSkills[0] = false;  // No soft skills applied
        m_ResultReplacesIngredient[0] = -1;  // Doesn't replace any ingredient
    }

    override bool CanDo(ItemBase ingredients[], PlayerBase player)
    {
        return true;  // Allow the crafting recipe to always be performed
    }

    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        Debug.Log("CraftFullUtopiaRTX2080TI Recipe Do method called", "recipes");
    }
};
