#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"
#include "../../includes.h"

class RangedWeapon
{

    //RangedWeapon Instance in Player.h (get_PlayerMovement)
private:
    void* rw_instance;

public:
    explicit RangedWeapon(void* instance) : rw_instance(instance) {}



    void* GetInstance() const { return rw_instance; }

    bool GetIsOnCooldown() const
    {
        if (!rw_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RangedWeapon::get_IsOnCooldownOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, rw_instance, (void*)nullptr);
    }

    Vector3 GetAimDirection() const
    {
        if (!rw_instance)
            return { 0, 0, 0 };

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return { 0, 0, 0 };

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RangedWeapon::get_AimDirectionOffset;

        if (!funcAddr)
            return { 0, 0, 0 };

        using Fn = Vector3(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, rw_instance, (void*)nullptr);
    }

    bool GetCurrentProjectileGravityEnabled() const
    {
        if (!rw_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RangedWeapon::get_CurrentProjectileGravityEnabledOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, rw_instance, (void*)nullptr);
    }

    float GetCurrentProjectileSpreadMultiplier() const
    {
        if (!rw_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RangedWeapon::get_CurrentProjectileSpreadMultiplierOffset;

        if (!funcAddr)
            return -1;

        using Fn = float(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, rw_instance, (void*)nullptr);
    }

    float GetCurrentRecoilMultiplier() const
    {
        if (!rw_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RangedWeapon::get_CurrentRecoilMultiplierOffset;

        if (!funcAddr)
            return -1;

        using Fn = float(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, rw_instance, (void*)nullptr);
    }

    int32_t GetAmmunitionMagazineSize() const
    {
        if (!rw_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RangedWeapon::get_AmmunitionMagazineSizeOffset;

        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, rw_instance, (void*)nullptr);
    }


    float GetDefaultProjectileSpeed() const
    {
        if (!rw_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RangedWeapon::get_DefaultProjectileSpeedOffset;

        if (!funcAddr)
            return -1;

        using Fn = float(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, rw_instance, (void*)nullptr);
    }

    float GetDefaultProjectileLifetimeSeconds() const
    {
        if (!rw_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RangedWeapon::get_DefaultProjectileLifetimeSecondsOffset;

        if (!funcAddr)
            return -1;

        using Fn = float(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, rw_instance, (void*)nullptr);
    }

};