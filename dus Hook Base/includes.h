#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include "Deps/kiero/kiero.h"
#include "Deps/imgui/imgui.h"
#include "Deps/imgui/imgui_impl_win32.h"
#include "Deps/imgui/imgui_impl_dx11.h"
#include <thread>
#include <string>
#include <iostream>
#include <cmath>

uintptr_t ModuleGA = (uintptr_t)GetModuleHandleA(("GameAssembly.dll"));
uintptr_t ModuleREF = (uintptr_t)GetModuleHandleA(("Referee.dll"));



typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;



struct Quaternion {
	float x, y, z, w;
};

struct Vector3 {
	float x, y, z;

	Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

	Vector3 operator+(const Vector3& other) const {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3 operator-(const Vector3& other) const {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3 operator*(float scalar) const {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	float magnitude() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	Vector3 normalize() const {
		float mag = magnitude();
		if (mag > 0)
			return Vector3(x / mag, y / mag, z / mag);
		return Vector3(0, 0, 0);
	}

	
	static float Dot(const Vector3& a, const Vector3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	static Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		);
	}

	static Vector3 RotateVector(const Quaternion& q, const Vector3& v)
	{
		Vector3 u(q.x, q.y, q.z);
		float s = q.w;

		return u * (2.0f * Dot(u, v))
			+ v * (s * s - Dot(u, u))
			+ Cross(u, v) * (2.0f * s);
	}
};

struct Vector2 {
	float x, y;

};


inline Quaternion EulerToQuaternion(float pitch, float yaw, float roll)
{

    const float DEG2RAD = 3.14159265f / 180.0f;
    float halfPitch = pitch * 0.5f * DEG2RAD;
    float halfYaw = yaw * 0.5f * DEG2RAD;
    float halfRoll = roll * 0.5f * DEG2RAD;

    float cp = cosf(halfPitch);
    float sp = sinf(halfPitch);
    float cy = cosf(halfYaw);
    float sy = sinf(halfYaw);
    float cr = cosf(halfRoll);
    float sr = sinf(halfRoll);

    Quaternion q;
    q.w = cr * cp * cy + sr * sp * sy;
    q.x = sr * cp * cy - cr * sp * sy;
    q.y = cr * sp * cy + sr * cp * sy;
    q.z = cr * cp * sy - sr * sp * cy;

    return q;
}

const char* questItems[] = {
    "Golden Trophy",
    "Crimson Cauldron",
    "Jumbotron",
    "Isle Of Lost Skulls",
    "Crescendo",
    "Skip Boss"
};

//Player.h
enum HardwareType
{
    Desktop_Valve = 0,
    Desktop_Oculus = 1,
    PS4 = 2,
    Desktop_MicrosoftVR = 3,
    Desktop_VRMissing = 4,
    OculusQuest = 5,
    iOS = 6,
    XboxOne = 7,
    AndroidMobile = 8,
    PS5 = 9,
    XboxSeries = 10,
    PicoNeo3 = 11,
    PicoPhoenix = 12,
    NintendoSwitch = 13,
};

enum RecNetDeviceClasses
{
    IDontKnow = 0,
    VR = 1,
    Screen = 2,
    Mobile = 3,
    VRLow = 4,
    Quest2 = 5,
};

enum class RoomDoorInviteMode
{
    UnknownMode = 0,
    Normal = 1,
    PartyAutoFollow = 2,
    EveryoneAutoFollow = 3,
};


//AudioPlayer
enum class Channel
{
	Voice = 0,
	Sfx = 1,
	Music = 2,
	Ambience = 3,
	Master = 4,
	CoachVO = 5,
	VoiceCall = 6,
};

//Photon Events Send To
enum PhotonTargets {
	All = 0,
	Others = 1,
	MasterClient = 2,
	AllBuffered = 3,
	OthersBuffered = 4,
	AllViaServer = 5,
	AllBufferedViaServer = 6
};


inline const char* list[] = {
	"(FullBodyPuppetProp)",
	"[RootBeer_HackolaConsumableTool]",
	"[RootBeer_PixelPop_ConsumableTool]",
	"[CakePops_CandylandConsumableTool]",
	"[Popcorn_MonsterMunchies_ConsumableTool]",
	"[Microphone_Conference]",
	"[Sandbox_Mirror]",
	"[AudioEffectZone]",
	"[Consumables_Sparkler]",
	"[Consumables_Sparkler]",
	"[Consumables_Donut_BostonCreme]",
	"(HolotarProjector_CV1)",
	"(HolotarProjector_CV2)",
	"[ArenaManager]",
	"[Arena_AutomaticGun]",
	"[Arena_EMP]",
	"[Arena_Grenade]",
	"[Arena_Pistol]",
	"[Arena_PowerWeapon_BeamGun]",
	"[Arena_RailGun]",
	"[Arena_RocketLauncher]",
	"[Arena_Shotgun]",
	"[Arrow]",
	"[Basketball]",
	"[BattleRoyaleManager]",
	"[BowlingManager]",
	"[Bucket]",
	"[CharadesManager]",
	"[CharadesPen]",
	"[Charades_Stage]",
	"[Crossbow]",
	"[Crossbow_Hunter]",
	"[DiscGolfManager]",
	"[DodgeballManager]",
	"[ElectricalPole_Sandbox]",
	"[FlagAndGoal]",
	"[Giftbox]",
	"[Glider]",
	"[Grenade]",
	"[IBeam_10M_Sandbox]",
	"[Longbow]",
	"[LootChest]",
	"[LootChest_SciFi]",
	"[LootChest_Stuntrunner]",
	"[LootChest_Stuntrunner_Store_Smaller]",
	"[MakerPen]",
	"[MakerPen_Giftbox]",
	"[MicrophoneManager]",
	"[Microphone]",
	"[MiniLootChest_SciFi]",
	"[OrientationManager]",
	"[PaddleballBall]",
	"[PaddleballManager]",
	"[PaintballAssaultRifle]",
	"[PaintballGrenadeLauncher]",
	"[PaintballGun]",
	"[PaintballManager]",
	"[PaintballRifleScoped]",
	"[PaintballShield]",
	"[PaintballShotgun]",
	"[Paintball_PaintThrower]",
	"[PingpongBall]",
	"[PoolCue]",
	"[PoolTable]",
	"[ProximityMine]",
	"[QuestMeatSword]",
	"[QuestShield]",
	"[QuestSword]",
	"[Quest_Boulder]",
	"[Quest_Dracula1_1H-Crossbow]",
	"[Quest_Dracula1_BasicBoneMeleeEnemy]",
	"[Quest_Dracula1_BasicChargingWolfEnemy]",
	"[Quest_Dracula1_BasicLungingBatEnemy]",
	"[Quest_Dracula1_BasicRangedBatEnemy]",
	"[Quest_Dracula1_Bat_Plushy]",
	"[Quest_Dracula1_BlunderBuss]",
	"[Quest_Dracula1_BossBatDecoyEnemy]",
	"[Quest_Dracula1_ChestCoins_Large]",
	"[Quest_Dracula1_ChestCoins_Medium]",
	"[Quest_Dracula1_ChestCoins_Small]",
	"[Quest_Dracula1_CollectablePumpkin_Small]",
	"[Quest_Dracula1_Collectable_Large]",
	"[Quest_Dracula1_Collectable_Small]",
	"[Quest_Dracula1_Collectable_Wall]",
	"[Quest_Dracula1_Crossbow_Hunter]",
	"[Quest_Dracula1_DraculaBossBat]",
	"[Quest_Dracula1_DraculaBoss]",
	"[Quest_Dracula1_Flintlock]",
	"[Quest_Dracula1_Ground_Bone_ThrownEnemy]",
	"[Quest_Dracula1_Ground_MusketEnemy]",
	"[Quest_Dracula1_LootChest]",
	"[Quest_Dracula1_Manager]",
	"[Quest_Dracula1_MiniBossBoneMeleeEnemy]",
	"[Quest_Dracula1_MiniBossCoins_Bat]",
	"[Quest_Dracula1_MiniBossCoins_BoneMelee]",
	"[Quest_Dracula1_MiniBossCoins_BoneThrower]",
	"[Quest_Dracula1_MiniBossCoins_Musket]",
	"[Quest_Dracula1_MiniBossCoins_Wolf]",
	"[Quest_Dracula1_MiniBossGroundBoneThrownEnemy]",
	"[Quest_Dracula1_MiniBossGround_Musket]",
	"[Quest_Dracula1_MiniBossLungingWolfEnemy]",
	"[Quest_Dracula1_MiniBossRangedBatEnemy]",
	"[Quest_Dracula1_MiniBossSkeletonBone]",
	"[Quest_Dracula1_PitchFork]",
	"[Quest_Dracula1_Rake]",
	"[Quest_Dracula1_Rope]",
	"[Quest_Dracula1_Shovel]",
	"[Quest_Dracula1_SkeletonBone]",
	"[Quest_Dracula1_StoreLootChest]",
	"[Quest_Goblin1_Manager]",
	"[Quest_Goblin2_Manager]",
	"[Quest_Goblin_BasicFlyingRangedEnemy]",
	"[Quest_Goblin_BasicGroundMeleeEnemy]",
	"[Quest_Goblin_BasicGroundMeleeEnemy_Pike]",
	"[Quest_Goblin_BasicGroundRangedEnemy]",
	"[Quest_Goblin_BogMonster]",
	"[Quest_Goblin_BogMonster_Tentacle]",
	"[Quest_Goblin_EliteFlyingRangedEnemy]",
	"[Quest_Goblin_EliteGroundMeleeEnemy]",
	"[Quest_Goblin_FirePotion]",
	"[Quest_Goblin_FirePowerup]",
	"[Quest_Goblin_KnightChargeEnemy]",
	"[Quest_Goblin_KnightSpinEnemy]",
	"[Quest_Goblin_RotatingBossEnemy]",
	"[Quest_Goblin_VolleyRangedEnemy]",
	"[Quest_Goblin_Wand]",
	"[Quest_Goblin_WitchBoss]",
	"[Quest_Pirate1_BarStool]",
	"[Quest_Pirate1_BeerBottle]",
	"[Quest_Pirate1_BreakableFish]",
	"[Quest_Pirate1_CoconutBomb]",
	"[Quest_Pirate1_CoinStack_Small]",
	"[Quest_Pirate1_Cutlass]",
	"[Quest_Pirate1_Flintlock]",
	"[Quest_Pirate1_FryingPan]",
	"[Quest_Pirate1_Gibbet]",
	"[Quest_Pirate1_LootChest]",
	"[Quest_Pirate1_LostLoot]",
	"[Quest_Pirate1_Manager]",
	"[Quest_Pirate1_Mug]",
	"[Quest_Pirate1_Oar]",
	"[Quest_Pirate1_Plate]",
	"[Quest_Pirate1_PushBroom]",
	"[Quest_Pirate1_RumJug]",
	"[Quest_Pirate1_StoreLootChest]",
	"[Quest_Pirate1_Torch]",
	"[Quest_Pirate_BasicGroundMeleeEnemy]",
	"[Quest_Pirate_BossEnemy]",
	"[Quest_Pirate_CannoneerEnemy]",
	"[Quest_Pirate_Ground_Bottle_ThrownEnemy]",
	"[Quest_Pirate_Ground_Explosive_ThrownEnemy]",
	"[Quest_Pirate_Ground_RangedEnemy]",
	"[Quest_SciFi1_Manager]",
	"[Quest_SciFi_AutomaticGun]",
	"[Quest_SciFi_BasicFlyingRangedEnemy]",
	"[Quest_SciFi_BasicGroundRangedEnemy]",
	"[Quest_SciFi_EliteFlyingRangedEnemy]",
	"[Quest_SciFi_EliteGroundRangedEnemy]",
	"[Quest_Scifi_JumbotronBossEnemy]",
	"[Quest_SciFi_KnightAssassinEnemy]",
	"[Quest_SciFi_Pistol]",
	"[Quest_SciFi_RailGun]",
	"[Quest_SciFi_Shotgun]",
	"[Quest_SciFi_TinyGroundExplosiveEnemy]",
	"[Quest_Witch_Projectile]",
	"[RecRallyManager]",
	"[Sandbox_CodeOfConduct_Poster]",
	"[Sandbox_CouchChair]",
	"[Sandbox_Friendotron]",
	"[Sandbox_Lockers]",
	"[Sandbox_SnowballPile]",
	"[SciFi_Grenade]",
	"[SoccerManager]",
	"[SoccerPowerup_Star]",
	"[Soccer_SpeedPowerup]",
	"[SoloCup]",
	"[Standee_Bear01]",
	"[StNMonsterCostumeDummy]",
	"[StuntRunner_BoostManager]",
	"[StuntRunner_Manager]",
	"[StuntRunner_Wall_Long]",
	"[Trophy_Oscar]",
	"[Vehicle_50sCar]",
	"[Vehicle_RallyBuggy]",
	"[Vehicle_Truck]",
	"[Vehicle_Wolf]",
	"[VendingMachine]",
	"[Whip]"
};