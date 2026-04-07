#pragma once
#include "../ExFunctions/ExSessionManager.h"



void SessionManager_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::SessionManager::get_IsDeveloperOffset)), &get_IsDeveloper_H, (void**)&get_IsDeveloper_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::SessionManager::get_IsDeveloperOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::SessionManager::get_IsWhiteGloveCreatorOffset)), &get_IsWhiteGloveCreator_H, (void**)&get_IsWhiteGloveCreator_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::SessionManager::get_IsWhiteGloveCreatorOffset)));

}