#pragma once
#include "../../natives.h"




bool (*PlayerIsInvincible_O)(void*, void*);
bool PlayerIsInvincible_H(void* GameCombatManager, void* MethodInfo) {

	if (Combat::Godmode) {
		return true;
	}
	return PlayerIsInvincible_O(GameCombatManager, MethodInfo);

}


float (*get_RespawnDuration_O)(void*, void*);
float get_RespawnDuration_H(void* GameCombatManager, void* MethodInfo) {

	if (Combat::InstantRespawn) {
		return 0;
	}
	return get_RespawnDuration_O(GameCombatManager, MethodInfo);

}

int32_t (*get_MaxHealth_O)(void*, void*);
int32_t get_MaxHealth_H(void* GameCombatManager, void* MethodInfo) {

	if (Combat::CustomeHealth) {
		return Combat::Health;
	}
	return get_MaxHealth_O(GameCombatManager, MethodInfo);

}

int32_t(*get_MaxShield_O)(void*, void*);
int32_t get_MaxShield_H(void* GameCombatManager, void* MethodInfo) {

	if (Combat::CustomeShield) {
		return Combat::Shield;
	}
	return get_MaxShield_O(GameCombatManager, MethodInfo);

}

int32_t(*GetPlayerHealth_O)(void*, void*);
int32_t GetPlayerHealth_H(void* GameCombatManager, void* MethodInfo) {

	if (Combat::CustomeHealth) {
		return Combat::Health;
	}
	return GetPlayerHealth_O(GameCombatManager, MethodInfo);

}

int32_t(*GetPlayerShield_O)(void*, void*);
int32_t GetPlayerShield_H(void* GameCombatManager, void* MethodInfo) {

	if (Combat::CustomeShield) {
		return Combat::Shield;
	}
	return GetPlayerShield_O(GameCombatManager, MethodInfo);

}