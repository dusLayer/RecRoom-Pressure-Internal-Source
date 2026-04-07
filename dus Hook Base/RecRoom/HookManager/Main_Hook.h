#pragma once
#include <stdio.h>
#include "PlayerMovement_Hooks.h"
#include "../../Deps/Logger/Logger.h"
#include "GlobalModel_Hooks.h"
#include "RangedWeapon_Hooks.h"
#include "SessionManager_Hooks.h"
#include "GameCombatManager_Hooks.h"
#include "Player_Hooks.h"
#include "Camera_Hooks.h"
#include "LegacyTlsAuthentication_Hooks.h"
#include "QuestManager_Hooks.h"
#include "RRNetworkView_Hooks.h"
#include "Tool_Hooks.h"
#include "GroundVehicle_Hooks.h"



Logger HookLogger("");

void HookingManager() {


	PlayerMovement_Hooks();
	GlobalModel_Hooks();
	RangedWeapon_Hooks();
	SessionManager_Hooks();
	GameCombatManager_Hooks();
	Player_Hooks();
	Camera_Hooks();
	LegacyTlsAuthentication_Hooks();
	GroundVehicle_Hooks();

	HookLogger.info("All Hooks successfully Hooked!");

}

