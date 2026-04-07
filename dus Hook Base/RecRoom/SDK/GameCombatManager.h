#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"

class GameCombatManager
{
    //GameCombatManager instance in GameManager.h
private:
    void* gcm_instance;

public:
    explicit GameCombatManager(void* instance) : gcm_instance(instance) {}



    void* GetInstance() const { return gcm_instance; }





    bool PlayerIsInvincible(void* networkedplayer) const
    {
        if (!gcm_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GameCombatManager::PlayerIsInvincibleOffset;
        if (!funcAddr)
            return false;

        using Fn = bool* (*)(void*, void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gcm_instance, networkedplayer, (void*)nullptr);
    }


    float GetRespawnDuration() const
    {
        if (!gcm_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GameCombatManager::get_RespawnDurationOffset;
        if (!funcAddr)
            return -1;

        using Fn = float(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gcm_instance, (void*)nullptr);
    }

    int32_t GetMaxHealth() const
    {
        if (!gcm_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GameCombatManager::get_MaxHealthOffset;
        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gcm_instance, (void*)nullptr);
    }

    int32_t GetMaxShield() const
    {
        if (!gcm_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GameCombatManager::get_MaxShieldOffset;
        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gcm_instance, (void*)nullptr);
    }

    int32_t GetPlayerHealth(void* networkedplayer) const
    {
        if (!gcm_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GameCombatManager::GetPlayerHealthOffset;
        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*, void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gcm_instance, networkedplayer, (void*)nullptr);
    }

    int32_t GetPlayerShield(void* networkedplayer) const
    {
        if (!gcm_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GameCombatManager::GetPlayerShieldOffset;
        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*, void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gcm_instance, networkedplayer, (void*)nullptr);
    }

    void* RequestSelfRevive() const
    {
        if (!gcm_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GameCombatManager::RequestSelfReviveOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void*(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gcm_instance, (void*)nullptr);
    }
};