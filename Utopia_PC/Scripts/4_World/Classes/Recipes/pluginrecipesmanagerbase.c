modded class PluginRecipesManager extends PluginBase
{
	override void RegisterRecipies()
    {
        super.RegisterRecipies();			
        RegisterRecipe(new Pack_Utopia_Desk);
        RegisterRecipe(new Pack_Utopia_Filament_Holder);
        RegisterRecipe(new Unpack_Utopia_Desk_Box);
    }
}


