#pragma once
#include "../ExFunctions/ExCamera.h"



void Camera_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Camera::WorldToScreenPointOffset)), &WorldToScreenPoint_H, (void**)&WorldToScreenPoint_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Camera::WorldToScreenPointOffset))); 

    MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Camera::get_currentOffset)), &get_main_H, (void**)&get_main_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Camera::get_currentOffset)));


}