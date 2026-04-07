#pragma once
#include "Windows.h"

namespace RecRoom {

	namespace Player {


		//Player get_LocalPlayer
		uintptr_t get_LocalPlayerOffset = 0x17D0700;

		//System.Boolean get_IsMuted();
		uintptr_t get_isMute = 0x17CFC70;

		//System.Boolean get_IsInVehicle();
		uintptr_t get_IsInVehicle = 0x17CFBA0;

		//System.Boolean get_IsFriend();
		uintptr_t get_IsFriendOffset = 0x17CFA60;

		//System.Boolean get_IsBlocked
		uintptr_t get_IsBlockedOffset = 0x17CF8E0;

		//System.Int32 get_PlayerAccountId();
		uintptr_t get_PlayerAccountIdOffset = 0x17D0C00;

		//RecRoom.Networking.DataTypes.VPDKWOIWOKH get_PhotonPlayer();
		uintptr_t get_PhotonPlayerOffset = 0x17D0AE0;

		//System.Int32 get_PlayerId();
		uintptr_t get_PlayerIdOffset = 0x17D0D40;

		//Player GetFromActorNumber(System.Int32);
		uintptr_t GetFromActorNumberOffset = 0x17B11A0;

		//System.Int32 get_PlayerIndex();
		uintptr_t get_PlayerIndexOffset = 0x17D0D90;

		//RecRoom.Networking.DataTypes.VPDKWOIWOKH get_NetworkedPlayer();
		uintptr_t get_NetworkedPlayerOffset = 0x17D0940;

		//RecRoom.Networking.RRNetworkBehavior get_NetworkBehavior();
		uintptr_t get_NetworkBehaviorOffset = 0xBD1650;

		//System.String get_PlayerName();
		uintptr_t get_PlayerNameOffset = 0x17D0E90;

		//Player GetFromAccountId(System.Int32, System.Boolean);
		uintptr_t GetFromAccountIdOffset = 0x17B10D0;

		//RecRoom.Core.Locomotion.PlayerMovement get_PlayerMovement();
		uintptr_t get_PlayerMovementOffset = 0xD47DC0;

		//System.Collections.Generic.IEnumerable<Player> GetAllPlayers(System.Boolean);
		uintptr_t GetAllPlayersOffset = 0x17B0080;

		//RecRoom.CircuitsV2.GraphNodes.PlayerLogicComponent get_PlayerLogicComponent();
		uintptr_t get_PlayerLogicComponentOffset = 0x17D0E80;

		//Player GetFromViewId(System.Int32);
		uintptr_t GetFromViewIdOffset = 0x17B1260;


		//MAIN actor         System.Int32 UDJQPSJPDUO();    ( "RecRoom.Networking.NetcodeImpl.Runtime.dll", "RecRoom/Networking", "JCGPEIGMXFW" );
		//                                 ( "RecRoom.RoomLoading.Runtime.dll", "RecRoom/RoomLoading", "DummyPlayer" );
		//                               ( "RecRoom.Foundation.Identifiers.Runtime.dll", "RecRoom/Foundation", "ViewId" );

		uintptr_t get_actorNumberOffset = 0xAD3AA0;

		//UnityEngine.Vector3 get_CurrentHeadPosition();
		uintptr_t get_CurrentHeadPositionOffset = 0x17CF1D0;

		//System.Void RpcAuthorityCV2SetPosition(UnityEngine.Vector3);
		uintptr_t RpcAuthorityCV2SetPositionOffset = 0x17C7490;

		//System.Int32 get_Ping();
		uintptr_t get_PingOffset = 0x17D0BB0;

		//System.Boolean get_IsVisible();
		uintptr_t get_IsVisibleOffset = 0x17CFDE0;

		//System.Boolean get_IsSpawning();
		uintptr_t get_IsSpawningOffset = 0x17CFDA0;

		//System.Boolean get_IsGameBackgrounded();
		uintptr_t get_IsGameBackgroundedOffset = 0x17CFAA0;

		//UnityEngine.Vector3 get_CurrentFloorPosition();
		uintptr_t get_CurrentFloorPosition = 0x17CF040;

		//System.Void RpcLocalGoToRoom(System.String, System.String, System.String, RecRoom.Protobuf.RoomDoorData.FZNFAKTBVRO.RoomDoorInviteMode, System.Boolean);
		uintptr_t RpcLocalGoToRoomOffset = 0x17C8510;

		//Circuits.Dynamic.Api.LegacyCV2Result<RecRoom.NoEngine.Common.None> CV2GoToRoom(CircuitsV2.Lang.TNNPXTPLORO, Circuits.Shared.RecRoom.Api.XVNRGWBKEIW);
		uintptr_t CV2GoToRoomOffset = 0x17A6FB0;

		//RecRoom.Core.Vehicles.GXCZDRNABGG get_BoardedVehicle();
		uintptr_t get_BoardedVehicleOffset = 0x14F11C0;

		//UnityEngine.Quaternion GetRotation();
		uintptr_t GetRotationOffset = 0x17B15B0;
	}


	namespace PlayerMovement {

		//System.Boolean get_IsFlyingEnabled();
		uintptr_t get_IsFlyingEnabledOffset = 0x1A52A00;

		//System.Single get_MaxWalkSpeed();
		uintptr_t get_MaxWalkSpeedOffset = 0x1A53380;
	}


	namespace RRNetworkView {

		//System.Int32 get_ControllerActorNr();
		uintptr_t get_ControllerActorNrOffset = 0x864FFD0;

		//RecRoom.Networking.DataTypes.OVSEBXDBUJS get_Controller();
		uintptr_t get_ControllerOffset = 0x864FFA0;

		//System.Void RPC(System.String, RecRoom.Networking.DataTypes.OVSEBXDBUJS, System.Object[]);
		uintptr_t RPCOffset = 0x864D3F0;
	}


	namespace RRNetworkBehavior {

		//RecRoom.Networking.RRNetworkView get_NetworkedView();
		uintptr_t get_NetworkedViewOffset = 0x864B280;

		//RecRoom.Networking.RRNetworkView get_photonView();
		uintptr_t get_photonViewOffset = 0x864B280;


	}

	namespace GlobalModel {

		//System.Boolean get_LocalAccountIsDeveloper();
		uintptr_t get_LocalAccountIsDeveloperOffset = 0x262C800;

		//System.Boolean get_LocalAccountIsModerator();
		uintptr_t get_LocalAccountIsModeratorOffset = 0x262C960;
	}

	namespace RangedWeapon {

		//System.Boolean get_IsOnCooldown();
		uintptr_t get_IsOnCooldownOffset = 0x1CC6750;

		//UnityEngine.Vector3 get_AimDirection();
		uintptr_t get_AimDirectionOffset = 0x1CC5C80;

		//System.Boolean get_CurrentProjectileGravityEnabled();
		uintptr_t get_CurrentProjectileGravityEnabledOffset = 0x1CC5F20;

		//System.Single get_CurrentProjectileSpreadMultiplier();
		uintptr_t get_CurrentProjectileSpreadMultiplierOffset = 0x1CC61B0;

		//System.Single get_CurrentRecoilMultiplier();
		uintptr_t get_CurrentRecoilMultiplierOffset = 0x1CC6290;

		//System.Int32 get_AmmunitionMagazineSize();
		uintptr_t get_AmmunitionMagazineSizeOffset = 0x1CC5DC0;

		//System.Single get_DefaultProjectileSpeed();
		uintptr_t get_DefaultProjectileSpeedOffset = 0x1CC63F0;

		//System.Single get_DefaultProjectileLifetimeSeconds();
		uintptr_t get_DefaultProjectileLifetimeSecondsOffset = 0x1CC6390;
	}

	namespace SessionManager {

		//System.Boolean get_IsDeveloper();
		uintptr_t get_IsDeveloperOffset = 0x204CB30;

		//System.Boolean get_IsWhiteGloveCreator();
		uintptr_t get_IsWhiteGloveCreatorOffset = 0x204CE20;
	}

	namespace GameCombatManager {

		//System.Boolean PlayerIsInvincible(RecRoom.Networking.DataTypes.OVSEBXDBUJS);
		uintptr_t PlayerIsInvincibleOffset = 0x211E640;

		//System.Single get_RespawnDuration();
		uintptr_t get_RespawnDurationOffset = 0x2126780;

		//System.Int32 get_MaxHealth();
		uintptr_t get_MaxHealthOffset = 0x21266E0;

		//System.Int32 get_MaxShield();
		uintptr_t get_MaxShieldOffset = 0x2126710;

		//System.Int32 GetPlayerHealth(RecRoom.Networking.DataTypes.OVSEBXDBUJS);
		uintptr_t GetPlayerHealthOffset = 0x2116B70;

		//System.Int32 GetPlayerShield(RecRoom.Networking.DataTypes.OVSEBXDBUJS);
		uintptr_t GetPlayerShieldOffset = 0x2116C00;

		//System.Void RequestSelfRevive();
		uintptr_t RequestSelfReviveOffset = 0x21201F0;
	}

	namespace GameManager {

		//GameCombatManager get_CombatManager();
		uintptr_t get_CombatManagerOffset = 0xAC63F0;
	}

	namespace PlayerCombatUI {

		//GameManager get_GameManager();
		uintptr_t get_GameOffset = 0xAD5950;
	}

	namespace RecRoomSceneManager {

		//RecRoomSceneManager get_Instance();
		uintptr_t get_InstanceOffset = 0x23BD340;

		//System.Boolean get_IsInitialized();
		uintptr_t get_IsInitializedOffset = 0x23BD440;

		//System.Boolean get_SpawnPlayersInRoom();
		uintptr_t get_SpawnPlayersInRoomOffset = 0xAE24A0;
	}

	namespace PlayerLogicComponet {

		//System.Int32 get_PlayerNumber();
		uintptr_t get_PlayerNumberOffset = 0x107AFE0;
	}

	namespace Camera {

		//UnityEngine.Vector3 WorldToScreenPoint(UnityEngine.Vector3);
		uintptr_t WorldToScreenPointOffset = 0x9D9DDA0;

		//UnityEngine.Camera get_current();
		uintptr_t get_currentOffset = 0x9D9F110;
	}


	namespace LegacyTlsAuthentication {

		//System.Void NotifyServerCertificate(BestHTTP.SecureProtocol.Org.BouncyCastle.Crypto.Tls.Certificate);
		uintptr_t NotifyServerCertificateOffset = 0x8FA7870;

		//System.Boolean IsValid(System.Uri, BestHTTP.SecureProtocol.Org.BouncyCastle.Asn1.X509.X509CertificateStructure[]);
		uintptr_t IsValid = 0x8FABD90;

		//System.Void FatalApplicationQuit(System.Int32, System.String);
		uintptr_t FatalApplicationQuitOffset = 0x2043CF0;

	}
		
	namespace QuestManager {

		//RecRoom.Activities.Quest.QuestManager get_Instance();
		uintptr_t get_InstanceOffset = 0x16475F0;

		//System.Int32 GetCurrentGameplayRoomIndex();
		uintptr_t GetCurrentGameplayRoomIndexOffset = 0x163FEF0;

		//System.Boolean get_IsQuestRunning();
		uintptr_t get_IsQuestRunningOffset = 0x1647740;
	}

	namespace il2cpp {

		//il2cpp_string_new
		uintptr_t il2cpp_String_NewOffset = 0xA1C9B0;
	}


	namespace Tool {

		//Tool PhotonInstantiate(System.String, UnityEngine.Vector3, UnityEngine.Quaternion, System.Single);
		uintptr_t PhotonInstantiateOffset = 0x1EE29C0;

		//RecRoom.DataLayer.CreationInstantiationParameters get_InstantiationParameters();
		uintptr_t get_InstantiationParametersOffset = 0x1EF1150;

		//RecRoom.Foundation.ViewId get_InstantiatorPhotonViewId();
		uintptr_t get_InstantiatorPhotonViewIdOffset = 0x1EF1170;
	}

	namespace GroundVehicle {

		//System.Boolean get_HasDriver();
		uintptr_t get_HasDriverOffset = 0x15CE850;

		//System.Single get_Speed();
		uintptr_t get_SpeedOffset = 0x15CEA80;

		//System.Void set_DidStart(System.Boolean);
		uintptr_t set_DidStartOffset = 0x15CECB0;

		//System.Void AuthorityStartEngine(System.Boolean);
		uintptr_t get_DidStartOffset = 0x15CE840;

		//System.Void AuthoritySetVehicleTransform(UnityEngine.Vector3, UnityEngine.Quaternion, System.Boolean, System.Boolean);
		uintptr_t AuthoritySetVehicleTransformOffset = 0x15C6B10;

	}
}