#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include "Deps/imgui/imgui.h"


namespace Local {

    extern bool DynamicFly;

    extern bool IsDeveloper;

    extern bool IsModerator;

    extern bool TrialItems;

    extern bool GameMaster;

    extern bool CustomeWalkspeed;
    extern float Walkspeed;

    extern bool airstuck;

    extern bool LevelLimiteBypass;
    extern int Level;

    extern bool IsWhiteGloveCreator;

}

namespace aimbot {
    extern bool AimbotFOV;
    extern bool AimbotEnabled;
    extern bool Lines;
    extern  float Smoothness;
    extern float FOVRadius;
}


namespace Visuals {

    extern bool ESP;

}

namespace Combat {
    extern bool Godmode;
    extern bool InstantRespawn;

    extern bool CustomeHealth;
    extern int32_t Health;

    extern bool CustomeShield;
    extern int32_t Shield;
}



namespace Weapons {
    extern bool get_IsOnCooldown;

    extern bool CustomeCurrentProjectileSpeed;
    extern float get_CurrentProjectileSpeed;

    extern bool NoRecoil;

    extern bool CustomeSpread;
    extern float Spread;

    extern bool CustomeBullets;
    extern int Bullets;

    extern bool InfAmmo;
    extern bool CustomeAmmo;
    extern int32_t Ammo;

    extern bool CustomeLifetime;
    extern float Lifetime;

    extern bool testCus;
    extern float test;
}



namespace Protection {

    extern bool AntiTeleport;
}

namespace Quest {

    extern bool Skipper;
    extern int RoomIndex;
}

namespace dev {
    extern bool ShowDebug;
}

namespace assetspawn {
    extern int selectedprefab;
    extern int count;
    extern float scale;
    extern std::string Name;
}

namespace UI
{
    extern bool show;
    extern bool showFPS;
    extern bool showLog;

    extern  bool showCrosshair;
    extern ImVec4 crosshairColor;
    extern float crosshairSize;
    extern float crosshairThickness;

}