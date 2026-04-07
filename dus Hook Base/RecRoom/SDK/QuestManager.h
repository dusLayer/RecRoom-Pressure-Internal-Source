#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"

class QuestManager
{

    
private:
    void* qm_instance;

public:
    explicit QuestManager(void* instance) : qm_instance(instance) {}



    void* GetCurrentInstance() const { return qm_instance; }

    static void* get_Instance()
    {

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::QuestManager::get_InstanceOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, (void*)nullptr);
    }

    int32_t GetCurrentGameplayRoomIndex() const
    {
        if (!qm_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::QuestManager::GetCurrentGameplayRoomIndexOffset;
        if (!funcAddr)
            return -1;


        auto fn = reinterpret_cast<int32_t(*)(void*, void*)>(funcAddr);

        return spfc(spoof, fn, qm_instance, (void*)nullptr);
    }

    bool GetIsQuestRunning() const
    {
        if (!qm_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::QuestManager::get_IsQuestRunningOffset;
        if (!funcAddr)
            return false;


        auto fn = reinterpret_cast<bool(*)(void*, void*)>(funcAddr);

        return spfc(spoof, fn, qm_instance, (void*)nullptr);
    }
};