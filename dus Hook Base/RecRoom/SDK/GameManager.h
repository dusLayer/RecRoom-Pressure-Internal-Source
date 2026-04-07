#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"

class GameManager
{
private:
    void* gm_instance;

public:
    explicit GameManager(void* instance) : gm_instance(instance) {}



    void* GetInstance() const { return gm_instance; }



    void* get_CombatManager() const
    {
        if (!gm_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::GameManager::get_CombatManagerOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, gm_instance, (void*)nullptr);
    }

};