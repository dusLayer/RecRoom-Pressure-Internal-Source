#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"

class RRNetworkBehavior
{
private:
    void* b_instance;

public:
    explicit RRNetworkBehavior(void* instance) : b_instance(instance) {}



    void* GetInstance() const { return b_instance; }


    void* GetNetworkedView() const
    {
        if (!b_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::RRNetworkBehavior::get_NetworkedViewOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, b_instance, (void*)nullptr);
    }

};