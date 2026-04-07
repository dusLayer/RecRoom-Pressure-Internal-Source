#pragma once
#include "../ExFunctions/ExGroundVehicle.h"



void GroundVehicle_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::GroundVehicle::AuthoritySetVehicleTransformOffset)), &AuthoritySetVehicleTransform_H, (void**)&AuthoritySetVehicleTransform_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::GroundVehicle::AuthoritySetVehicleTransformOffset)));

}
