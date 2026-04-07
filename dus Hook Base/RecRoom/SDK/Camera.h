#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"
#include "../../includes.h"


class Camera
{
private:
    void* c_instance;

public:
    explicit Camera(void* instance) : c_instance(instance) {}



    void* GetInstance() const { return c_instance; }



    Vector3 WorldToScreenPoint(Vector3 position) const
    {
        if (!c_instance)
            return { 0, 0, 0 };

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return { 0, 0, 0 };

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
        uintptr_t funcAddr = base + RecRoom::Camera::WorldToScreenPointOffset;
        if (!funcAddr)
            return { 0, 0, 0 };


        auto fn = reinterpret_cast<Vector3(*)(void*, Vector3, void*)>(funcAddr);

        return spfc(spoof, fn, c_instance, position, (void*)nullptr);
    }

    static void* GetCurrent()
    {

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Camera::get_currentOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, (void*)nullptr);
    }
};