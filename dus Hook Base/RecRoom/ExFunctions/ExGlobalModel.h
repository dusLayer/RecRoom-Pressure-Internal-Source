#pragma once
#include "../../natives.h"



bool (*get_LocalAccountIsDeveloper_O)(void*, void*);
bool get_LocalAccountIsDeveloper_H(void* GlobalModel, void* MethodInfo) {

	if (Local::IsDeveloper) {
		return true;
	}
	return get_LocalAccountIsDeveloper_O(GlobalModel, MethodInfo);

}


bool (*get_LocalAccountIsModerator_O)(void*, void*);
bool get_LocalAccountIsModerator_H(void* GlobalModel, void* MethodInfo) {

	if (Local::IsModerator) {
		return true;
	}
	return get_LocalAccountIsModerator_O(GlobalModel, MethodInfo);

}