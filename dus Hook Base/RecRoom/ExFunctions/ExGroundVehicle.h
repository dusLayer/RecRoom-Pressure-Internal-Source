#pragma once


void (*set_DidStart_O)(void*, bool, void*);
void set_DidStart_H(void* vehicle, bool Started, void* methodinfo) {



	return set_DidStart_O(vehicle, Started, methodinfo);
}


void (*AuthoritySetVehicleTransform_O)(void*, Vector3, Quaternion, bool, bool, void*);
void AuthoritySetVehicleTransform_H(void* Vehicle, Vector3 position, Quaternion rotation, bool arg1, bool arg2, void* methodinfo) {


	return AuthoritySetVehicleTransform_O(Vehicle, position, rotation, arg1, arg2, methodinfo);
}

