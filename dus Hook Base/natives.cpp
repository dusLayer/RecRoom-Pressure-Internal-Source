#include <Windows.h>
#include <vector>
#include <string>
#include "natives.h"
#include "Deps/imgui/imgui.h"




namespace Local {

   
    bool DynamicFly = false;

 
    bool IsDeveloper = false;

    bool IsModerator = false;

    bool TrialItems = false;

    bool GameMaster = false;

    bool CustomeWalkspeed = false;
    float Walkspeed = 2.8;

    bool airstuck = false;

    bool IsWhiteGloveCreator = false;

}


namespace Visuals {


    bool ESP = false;

}

namespace aimbot {
    bool AimbotFOV = false;
    bool AimbotEnabled = false;
    bool Lines = false;
    float Smoothness = 2.0f;
    float FOVRadius = 120.0f;
}

namespace Combat {
    bool Godmode = false;
    bool InstantRespawn = false;

    bool CustomeHealth = false;
    int32_t Health = 100;

    bool CustomeShield = false;
    int32_t Shield = 100;
}

namespace Weapons {
    bool get_IsOnCooldown = false;

    bool CustomeCurrentProjectileSpeed = false;
    float get_CurrentProjectileSpeed = 1;
    bool NoRecoil = false;
    bool CustomeSpread = false;
    float Spread = 1;

    bool CustomeBullets = false;
    int Bullets = 1;

    bool InfAmmo = false;
    bool CustomeAmmo = false;
    int32_t Ammo = 1;

    bool CustomeLifetime = false;
    float Lifetime = 1;

    bool testCus = false;
    float test = 1;
}



namespace Protection {

    bool AntiTeleport = false;
}

namespace Quest {

    bool Skipper = false;
    int RoomIndex = 0;
}


namespace dev {
    bool ShowDebug = false;
}

namespace assetspawn {
    int selectedprefab = -1;
    int count = 1;
    float scale = 1;
    std::string Name = "";
}


namespace UI
{
    bool show = false;
    bool showFPS = true;
    bool showLog = false;

    bool showCrosshair = true;
    ImVec4 crosshairColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    float crosshairSize = 10.0f;
    float crosshairThickness = 1.5f;

}