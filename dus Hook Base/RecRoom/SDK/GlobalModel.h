#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"

class GlobalModel
{
private:
    void* gm_instance;

public:
    explicit GlobalModel(void* instance) : gm_instance(instance) {}



    void* GetInstance() const { return gm_instance; }





    bool GetLocalAccountIsDeveloper() const
    {
        if (!gm_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GlobalModel::get_LocalAccountIsDeveloperOffset;
        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gm_instance, (void*)nullptr);
    }

    bool GetLocalAccountIsModerator() const
    {
        if (!gm_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GlobalModel::get_LocalAccountIsModeratorOffset;
        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gm_instance, (void*)nullptr);
    }
};