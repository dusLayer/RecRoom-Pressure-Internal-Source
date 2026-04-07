#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"
#include "../../includes.h"


class LegacyTlsAuthentication
{
private:
    void* lt_instance;

public:
    explicit LegacyTlsAuthentication(void* instance) : lt_instance(instance) {}



    void* GetInstance() const { return lt_instance; }


    void* NotifyServerCertificate() const
    {
        if (!lt_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::LegacyTlsAuthentication::NotifyServerCertificateOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, lt_instance, (void*)nullptr);
    }
};