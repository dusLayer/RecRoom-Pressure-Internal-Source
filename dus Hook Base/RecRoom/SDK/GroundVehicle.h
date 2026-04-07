#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"
#include "../../includes.h"


class GroundVehicle
{
private:
    void* v_instance;

public:
    explicit GroundVehicle(void* instance) : v_instance(instance) {}



    void* GetInstance() const { return v_instance; }



    bool GetHasDriver() const
    {
        if (!v_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GroundVehicle::get_HasDriverOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, v_instance, (void*)nullptr);
    }

    float GetSpeed() const
    {
        if (!v_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GroundVehicle::get_SpeedOffset;

        if (!funcAddr)
            return -1;

        using Fn = float(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, v_instance, (void*)nullptr);
    }

    bool GetDidStart() const
    {
        if (!v_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GroundVehicle::get_DidStartOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, v_instance, (void*)nullptr);
    }
};