#pragma once
#include "../ExFunctions/ExRangedWeapon.h"



void RangedWeapon_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_IsOnCooldownOffset)), &get_IsOnCooldown_H, (void**)&get_IsOnCooldown_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_IsOnCooldownOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_CurrentProjectileSpreadMultiplierOffset)), &get_CurrentProjectileSpreadMultiplier_H, (void**)&get_CurrentProjectileSpreadMultiplier_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_CurrentProjectileSpreadMultiplierOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_CurrentRecoilMultiplierOffset)), &get_CurrentRecoilMultiplier_H, (void**)&get_CurrentRecoilMultiplier_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_CurrentRecoilMultiplierOffset)));
	
	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_AmmunitionMagazineSizeOffset)), &get_AmmunitionMagazineSize_H, (void**)&get_AmmunitionMagazineSize_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_AmmunitionMagazineSizeOffset)));
	
	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_DefaultProjectileSpeedOffset)), &get_DefaultProjectileSpeed_H, (void**)&get_DefaultProjectileSpeed_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_DefaultProjectileSpeedOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_DefaultProjectileLifetimeSecondsOffset)), &get_DefaultProjectileLifetimeSeconds_H, (void**)&get_DefaultProjectileLifetimeSeconds_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::RangedWeapon::get_DefaultProjectileLifetimeSecondsOffset)));
}