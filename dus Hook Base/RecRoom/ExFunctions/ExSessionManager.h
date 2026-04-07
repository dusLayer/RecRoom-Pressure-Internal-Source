#pragma once
#include "../../natives.h"



bool (*get_IsDeveloper_O)(void*, void*);
bool get_IsDeveloper_H(void* SessionManager, void* MethodInfo) {

	if (Local::IsDeveloper) {
		return true;
	}
	return get_IsDeveloper_O(SessionManager, MethodInfo);

}



bool (*get_IsWhiteGloveCreator_O)(void*, void*);
bool get_IsWhiteGloveCreator_H(void* SessionManager, void* MethodInfo) {

	if (Local::IsWhiteGloveCreator) {
		return true;
	}
	return get_IsWhiteGloveCreator_O(SessionManager, MethodInfo);

}
