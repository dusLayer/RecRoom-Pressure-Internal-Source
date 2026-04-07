#pragma once
#include "../ExFunctions/ExGlobalModel.h"
#include "../../Deps/kiero/minhook/include/MinHook.h"



void GlobalModel_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::GlobalModel::get_LocalAccountIsDeveloperOffset)), &get_LocalAccountIsDeveloper_H, (void**)&get_LocalAccountIsDeveloper_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::GlobalModel::get_LocalAccountIsDeveloperOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::GlobalModel::get_LocalAccountIsModeratorOffset)), &get_LocalAccountIsModerator_H, (void**)&get_LocalAccountIsModerator_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::GlobalModel::get_LocalAccountIsModeratorOffset)));

}