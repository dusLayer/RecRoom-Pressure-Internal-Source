#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"

class PlayerMovement
{

    //PlayerMovement Instance in Player.h (get_PlayerMovement)
private:
    void* pm_instance;

public:
    explicit PlayerMovement(void* instance) : pm_instance(instance) {}



    void* GetInstance() const { return pm_instance; }

    bool GetIsFlyingEnabled() const
    {
        if (!pm_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::PlayerMovement::get_IsFlyingEnabledOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, pm_instance, (void*)nullptr);
    }

    float GetMaxWalkSpeed() const
    {
        if (!pm_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::PlayerMovement::get_MaxWalkSpeedOffset;

        if (!funcAddr)
            return -1;

        using Fn = float(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, pm_instance, (void*)nullptr);
    }
};