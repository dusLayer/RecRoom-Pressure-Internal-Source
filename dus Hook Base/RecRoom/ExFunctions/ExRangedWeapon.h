#pragma once
#include "../../natives.h"



bool (*get_IsOnCooldown_O)(void*, void*);
bool get_IsOnCooldown_H(void* RangedWeapon, void* MethodInfo) {

	if (Weapons::get_IsOnCooldown) {
		return false;
	}
	return get_IsOnCooldown_O(RangedWeapon, MethodInfo);

}


float (*get_CurrentProjectileSpreadMultiplier_O)(void*, void*);
float get_CurrentProjectileSpreadMultiplier_H(void* RangedWeapon, void* MethodInfo) {

	if (Weapons::CustomeSpread) {
		return Weapons::Spread;
	}
	return get_CurrentProjectileSpreadMultiplier_O(RangedWeapon, MethodInfo);

}


float (*get_CurrentRecoilMultiplier_O)(void*, void*);
float get_CurrentRecoilMultiplier_H(void* RangedWeapon, void* MethodInfo) {

	if (Weapons::NoRecoil) {
		return 0;
	}
	return get_CurrentRecoilMultiplier_O(RangedWeapon, MethodInfo);

}


int32_t (*get_AmmunitionMagazineSize_O)(void*, void*);
int32_t get_AmmunitionMagazineSize_H(void* RangedWeapon, void* MethodInfo) {

	if (Weapons::InfAmmo) {
		return 9999999;
	}

	if (Weapons::CustomeAmmo) {
		return Weapons::Ammo;
	}

	return get_AmmunitionMagazineSize_O(RangedWeapon, MethodInfo);

}

float (*get_DefaultProjectileSpeed_O)(void*, void*);
float get_DefaultProjectileSpeed_H(void* RangedWeapon, void* MethodInfo) {

	if (Weapons::CustomeCurrentProjectileSpeed) {
		return Weapons::get_CurrentProjectileSpeed;
	}
	return get_DefaultProjectileSpeed_O(RangedWeapon, MethodInfo);

}

float (*get_DefaultProjectileLifetimeSeconds_O)(void*, void*);
float get_DefaultProjectileLifetimeSeconds_H(void* RangedWeapon, void* MethodInfo) {

	if (Weapons::CustomeLifetime) {
		return Weapons::Lifetime;
	}
	return get_DefaultProjectileLifetimeSeconds_O(RangedWeapon, MethodInfo);

}


