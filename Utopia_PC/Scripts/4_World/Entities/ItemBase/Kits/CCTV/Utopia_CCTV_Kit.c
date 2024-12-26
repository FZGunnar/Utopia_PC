class Utopia_CCTV_Kit extends ItemBase
{
	ref protected EffectSound 						m_DeployLoopSound;
	protected Object								Utopia_CCTV_Kit1;



	void Utopia_CCTV_Kit()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}

	override void EEInit()
	{
		super.EEInit();
	}


	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner )
	{
		super.OnItemLocationChanged( old_owner, new_owner );
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( IsDeploySound() )
		{
			PlayDeploySound();
		}

		if ( CanPlayDeployLoopSound() )
		{
			PlayDeployLoopSound();
		}

		if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
		{
			StopDeployLoopSound();
		}
	}

	//================================================================
	// ADVANCED PLACEMENT
	//================================================================

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0"  )
	{
		super.OnPlacementComplete( player, position, orientation );

		PlayerBase pb = PlayerBase.Cast( player );
		if ( GetGame().IsServer() )
		{
			PlayerBase player_base = PlayerBase.Cast( player );
			//vector position = player_base.GetLocalProjectionPosition();
			//vector orientation = player_base.GetLocalProjectionOrientation();

			Utopia_CCTV_Kit1 = GetGame().CreateObject("Utopia_CCTV", pb.GetLocalProjectionPosition(), false );
			Utopia_CCTV_Kit1.SetPosition( position);
			Utopia_CCTV_Kit1.SetOrientation( orientation );

			this.Delete();
		}

		SetIsDeploySound( true );
	}

	override bool IsDeployable()
	{
		return true;
	}

	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}

	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}

	void PlayDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
		}
	}

	void StopDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			m_DeployLoopSound.SoundStop();
			delete m_DeployLoopSound;
		}
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
}