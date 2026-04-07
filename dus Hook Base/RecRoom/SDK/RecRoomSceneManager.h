#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"
#include "../../includes.h"

class RecRoomSceneManager
{


private:
    void* sm_instance;

public:
    explicit RecRoomSceneManager(void* instance) : sm_instance(instance) {}



    void* GetInstance() const { return sm_instance; }



    static void* GetRecRoomSceneManager()
    {
        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
        uintptr_t funcAddr = base + RecRoom::RecRoomSceneManager::get_InstanceOffset;

        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, (void*)nullptr);
    }

    bool GetIsInitialized() const
    {
        if (!sm_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RecRoomSceneManager::get_IsInitializedOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, sm_instance, (void*)nullptr);
    }

    bool GetSpawnPlayersInRoom() const
    {
        if (!sm_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RecRoomSceneManager::get_SpawnPlayersInRoomOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, sm_instance, (void*)nullptr);
    }
};