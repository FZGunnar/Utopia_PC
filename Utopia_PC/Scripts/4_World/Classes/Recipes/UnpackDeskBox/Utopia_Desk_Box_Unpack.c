class Unpack_Utopia_Desk_Box extends RecipeBase
{    
    override void Init()
    {
        m_Name = "Open Utopia Desk Box";  // Action Display Name
        m_IsInstaRecipe = false;                
        m_AnimationLength = 2;                    
        m_Specialty = 0;                        

        // Begin Crafting Recipe
        InsertIngredient(0, "Utopia_Desk_Box");  // The desk kit to be unpacked
        m_MinDamageIngredient[0] = -1;            
        m_MaxDamageIngredient[0] = -1;            
        m_MinQuantityIngredient[0] = -1;        
        m_MaxQuantityIngredient[0] = -1;        
        m_IngredientAddHealth[0] = 0;            
        m_IngredientSetHealth[0] = -1;             
        m_IngredientAddQuantity[0] = -1;        
        m_IngredientDestroy[0] = true;            
        m_IngredientUseSoftSkills[0] = false;    
        
        // Define the results of unpacking
        AddResult("Utopia_PC_Desk_Top_1");
        AddResult("Utopia_PC_Desk_Top_2");
        AddResult("Utopia_PC_Leg_1");
        AddResult("Utopia_PC_Leg_2");
        AddResult("Utopia_PC_Leg_3");
        AddResult("Utopia_PC_Case");
        AddResult("Utopia_Desk_Manual");

        for (int i = 0; i < 7; i++)
        {
            m_ResultSetFullQuantity[i] = true;   // Set full quantity for all parts
            m_ResultSetQuantity[i] = -1;         // Use default quantity
            m_ResultSetHealth[i] = -1;           // Use default health
            m_ResultInheritsHealth[i] = -1;      // Do not inherit health from ingredients
            m_ResultInheritsColor[i] = -1;       // Do not inherit color from ingredients
            m_ResultToInventory[i] = -2;         // Place in inventory
            m_ResultUseSoftSkills[i] = false;    // Do not use soft skills
            m_ResultReplacesIngredient[i] = -1;  // Do not replace any ingredients
        }
    }

    override bool CanDo(ItemBase ingredients[], PlayerBase player)
    {
        return true;  // Allow the action to always be performed
    }

    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        array<ItemBase> spawned_objects = new array<ItemBase>();
        SpawnItems(ingredients, player, spawned_objects);
    }

    override void SpawnItems(ItemBase ingredients[], PlayerBase player, array<ItemBase> spawned_objects)
    {
        spawned_objects.Clear();
        EntityAI object = NULL;
        vector position = player.GetPosition();

        for (int i = 0; i < m_NumberOfResults; i++)
        {
            string item_to_spawn = m_ItemsToCreate[i];
            
            if (m_ResultInheritsColor[i] != -1)
            {
                ItemBase item = ingredients[m_ResultInheritsColor[i]];
                string color = item.ConfigGetString("color");
                string new_class_name = m_ItemsToCreate[i] + color;
                item_to_spawn = new_class_name;
            }
            
            if (m_ResultToInventory[i] == -1)
            {
                object = player.GetInventory().CreateInInventory(item_to_spawn);
            }
            else if (m_ResultToInventory[i] >= 0)
            {
                // Custom logic for placing items
            }
            else if (m_ResultToInventory[i] == -2)
            {
                object = player.GetInventory().CreateEntityInCargo(item_to_spawn);
            }
            
            if (!object)
            {
                object = player.SpawnEntityOnGroundOnCursorDir(item_to_spawn, m_ResultSpawnDistance[i]);
                if (!object)
                {
                    Error("Failed to spawn entity " + item_to_spawn + ", make sure the classname exists and item can be spawned");
                }
            }
            spawned_objects.Insert(ItemBase.Cast(object));
            object = NULL;
        }
    }
}
