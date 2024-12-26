class CraftFullUtopiaGraphicsCard660 extends RecipeBase
{
    override void Init()
    {
        m_Name = "Repair Utopia Graphics Card 660";  // Name of the crafting recipe
        m_IsInstaRecipe = false;  // The crafting process will take time
        m_AnimationLength = 10;  // Duration of the crafting animation (10 seconds)
        m_Specialty = 0.01;  // Defines crafting specialty

        // Conditions for Ingredient 1: Utopia_Graphics_Card_660 (damaged card)
        m_MinDamageIngredient[0] = -1;  // Allow any damage state (pristine or otherwise)
        m_MaxDamageIngredient[0] = -1;  // No maximum damage restriction
        m_MinQuantityIngredient[0] = -1;  // Minimum quantity of the GPU
        m_MaxQuantityIngredient[0] = -1;  // Maximum allowed quantity (for quantity-based GPU)

        // Conditions for Ingredient 2: Utopia_GpuRepairKit
        m_MinDamageIngredient[1] = -1;  // No minimum damage for the repair kit
        m_MaxDamageIngredient[1] = 3;  // Maximum damage for the repair kit
        m_MinQuantityIngredient[1] = 1;  // At least 1 repair kit needed
        m_MaxQuantityIngredient[1] = -1;  // No limit on the maximum quantity of repair kits

        // Ingredient 1: Utopia_Graphics_Card_660
        InsertIngredient(0, "Utopia_Graphics_Card_660");
        m_IngredientAddHealth[0] = 0;  // Health stays the same until repaired
        m_IngredientSetHealth[0] = -1;  // Keep the original health until the result
        m_IngredientAddQuantity[0] = 0;  // No quantity adjustment for the card
        m_IngredientDestroy[0] = true;  // The GPU will be consumed after repair

        // Ingredient 2: Utopia_GpuRepairKit
        InsertIngredient(1, "Utopia_GpuRepairKit");
        m_IngredientAddHealth[1] = 0;  // No health adjustment for the repair kit
        m_IngredientSetHealth[1] = -1;  // Health stays the same for the repair kit until used
        m_IngredientAddQuantity[1] = -1;  // The repair kit quantity will be reduced by 1
        m_IngredientDestroy[1] = true;  // The repair kit will be destroyed after use

        // Result: Utopia_Graphics_Card_660 (repaired)
        AddResult("Utopia_Graphics_Card_660");

        m_ResultSetFullQuantity[0] = true;  // Full quantity for items that stack
        m_ResultSetQuantity[0] = 1;  // The repaired GPU will have a quantity of 1
        m_ResultSetHealth[0] = 100;  // The result will have full health (repaired)
        m_ResultInheritsHealth[0] = -1;  // The health is not inherited from any ingredient
        m_ResultInheritsColor[0] = -1;  // The color is not inherited
        m_ResultToInventory[0] = 1;  // The result will go into the player's hands
        m_ResultUseSoftSkills[0] = false;  // No soft skills are applied
        m_ResultReplacesIngredient[0] = -1;  // No ingredient is replaced
    }

    override bool CanDo(ItemBase ingredients[], PlayerBase player)
    {
        return true;  // Allow the crafting recipe to always be performed
    }

    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        Debug.Log("CraftFullUtopiaGraphicsCard660 Recipe Do method called", "recipes");
    }
};
