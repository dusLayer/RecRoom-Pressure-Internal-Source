#pragma once
#include "../ExFunctions/ExGameCombatManager.h"



void GameCombatManager_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::GameCombatManager::PlayerIsInvincibleOffset)), &PlayerIsInvincible_H, (void**)&PlayerIsInvincible_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::GameCombatManager::PlayerIsInvincibleOffset)));

}
