#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"


class RRNetworkView
{
private:
    void* n_instance;

public:
    explicit RRNetworkView(void* instance) : n_instance(instance) {}

    void* GetInstance() const { return n_instance; }



    int32_t GetControllerActorNr() const
    {
        if (!n_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
        uintptr_t funcAddr = base + RecRoom::RRNetworkView::get_ControllerActorNrOffset;
        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*);
        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, n_instance);
    }
};