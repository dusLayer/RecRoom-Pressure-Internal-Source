#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"

class GameEncounter
{
private:
    void* ge_instance;

public:
    explicit GameEncounter(void* instance) : ge_instance(instance) {}



    void* GetInstance() const { return ge_instance; }



    static void* GetGame()
    {
        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
        uintptr_t funcAddr = base + RecRoom::PlayerCombatUI::get_GameOffset;

        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, (void*)nullptr);
    }

};