modded class PluginRecipesManagerBase
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        
        // Registering custom GPU repair recipes
        RegisterRecipe(new CraftFullUtopiaGraphicsCard1080TI);
        RegisterRecipe(new CraftFullUtopiaRTX2080TI);
        RegisterRecipe(new CraftFullUtopiaGraphicsCard4090TI);
        RegisterRecipe(new CraftFullUtopiaGraphicsCard660);
    }
}
