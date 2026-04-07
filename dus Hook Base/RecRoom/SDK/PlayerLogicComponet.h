#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"

class PlayerLogicComponet
{
private:
    void* pc_instance;

public:
    explicit PlayerLogicComponet(void* instance) : pc_instance(instance) {}



    void* GetInstance() const { return pc_instance; }


    int32_t GetPlayerNumber() const
    {
        if (!pc_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
        uintptr_t funcAddr = base + RecRoom::PlayerLogicComponet::get_PlayerNumberOffset;
        if (!funcAddr)
            return -1;


        using Fn = int32_t(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, pc_instance, (void*)nullptr);
    }
};