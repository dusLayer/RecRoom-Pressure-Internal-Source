#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"

class SessionManager
{
private:
    void* sn_instance;

public:
    explicit SessionManager(void* instance) : sn_instance(instance) {}



    void* GetInstance() const { return sn_instance; }



    bool GetIsDeveloper() const
    {
        if (!sn_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::SessionManager::get_IsDeveloperOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, sn_instance, (void*)nullptr);
    }

    bool GetIsWhiteGloveCreator() const
    {
        if (!sn_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::SessionManager::get_IsWhiteGloveCreatorOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, sn_instance, (void*)nullptr);
    }

};