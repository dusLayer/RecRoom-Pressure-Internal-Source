#pragma once
#include "../ExFunctions/ExPlayerMovement.h"


void PlayerMovement_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::PlayerMovement::get_IsFlyingEnabledOffset)), &get_IsFlyingEnabled_H, (void**)&get_IsFlyingEnabled_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::PlayerMovement::get_IsFlyingEnabledOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::PlayerMovement::get_MaxWalkSpeedOffset)), &get_MaxWalkSpeed_H, (void**)&get_MaxWalkSpeed_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::PlayerMovement::get_MaxWalkSpeedOffset)));
}