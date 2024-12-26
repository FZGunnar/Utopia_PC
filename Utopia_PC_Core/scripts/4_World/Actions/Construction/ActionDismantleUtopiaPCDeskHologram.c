class ActionDismantleUtopiaPCDeskHologramCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DEPLOY );
	}
};

class ActionDismantleUtopiaPCDeskHologram: ActionContinuousBase
{
	void ActionDismantleUtopiaPCDeskHologram()
	{
		m_CallbackClass = ActionDismantleUtopiaPCDeskHologramCB;
		m_SpecialtyWeight 	= UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
		m_FullBody			= true;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "#dismantle";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.LARGE);
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool HasProgress()
	{
		return true;
	}

	override bool HasAlternativeInterrupt()
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target )
			return false;

		Utopia_Desk_Build wallholo = Utopia_Desk_Build.Cast( target.GetObject() );

		if ( !wallholo )
			return false;

        string selection = wallholo.GetActionComponentName( target.GetComponentIndex() );

		array<string> selections = new array<string>;
		wallholo.GetActionComponentNameList(target.GetComponentIndex(), selections);

		for ( int s = 0; s < selections.Count(); s++ )
		{
			if ( selections[s] == "interact_pos" )
			{
				return wallholo.IsEmpty();
			}
		}
        return false;
	}

	override void OnStart(ActionData action_data)
	{
		super.OnStart(action_data);

		action_data.m_Player.TryHideItemInHands(true);
	}

	override void OnEnd(ActionData action_data)
	{
		super.OnEnd(action_data);

		action_data.m_Player.TryHideItemInHands(false);
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Utopia_Desk_Build wallholo = Utopia_Desk_Build.Cast( action_data.m_Target.GetObject() );

		ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( "Utopia_Desk_Manual", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE ) );

		if ( wallholo )
		{
			wallholo.Delete();
		}
		return;
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " dismantled " + action_data.m_Target.GetObject().GetDisplayName() + " with Hands at " + action_data.m_Player.GetPosition();
	}
};
