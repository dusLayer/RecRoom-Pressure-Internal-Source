#pragma once
#include "../../natives.h"



bool (*get_IsFlyingEnabled_O)(void*, void*);
bool get_IsFlyingEnabled_H(void* PlayerMovement, void* MethodInfo) {

	if (Local::DynamicFly) {
		return true;
	}
	return get_IsFlyingEnabled_O(PlayerMovement, MethodInfo);

}

float (*get_MaxWalkSpeed_O)(void*, void*);
float get_MaxWalkSpeed_H(void* PlayerMovement, void* MethodInfo) {

	if (Local::CustomeWalkspeed) {
		return Local::Walkspeed;
	}

	return get_MaxWalkSpeed_O(PlayerMovement, MethodInfo);
}