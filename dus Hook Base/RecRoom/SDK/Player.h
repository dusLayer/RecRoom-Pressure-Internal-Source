#pragma once
#include "../../Deps/spoof/returnspoof.hpp"
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include "../il2cpp/il2cppString.h"
#include "../../includes.h"


class Player
{
private:
    void* p_instance;

public:
    explicit Player(void* instance) : p_instance(instance) {}



    void* GetInstance() const { return p_instance; }



    static void* GetFromAccountId(int32_t accountId, bool IncludeBroadcastPlayer)
    {

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::GetFromAccountIdOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(int32_t, bool, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, accountId, IncludeBroadcastPlayer, (void*)nullptr);
    }

    static void* GetLocalPlayer()
    {
        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
        uintptr_t funcAddr = base + RecRoom::Player::get_LocalPlayerOffset;

        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, (void*)nullptr);
    }

    static void* GetFromActorNumber(int32_t actorid)
    {

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::GetFromActorNumberOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(int32_t, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, actorid, (void*)nullptr);
    }


    static void* GetFromViewId(int32_t viewId)
    {

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::GetFromViewIdOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(int32_t, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, viewId, (void*)nullptr);
    }

    void* get_PlayerMovement() const
    {
        if (!p_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_PlayerMovementOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    void* GetNetworkedPlayer() const
    {
        if (!p_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_NetworkedPlayerOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void*(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    void* GetPhotonPlayer() const
    {
        if (!p_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_PhotonPlayerOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }



    void* GetNetworkBehavior() const
    {
        if (!p_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_NetworkBehaviorOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    void* GetPlayerLogicComponent() const
    {
        if (!p_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_PlayerLogicComponentOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }


    std::string GetPlayerName() const
    {
        if (!p_instance)
            return "";

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return "";

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_PlayerNameOffset;
        if (!funcAddr)
            return "";

        auto fn = reinterpret_cast<void* (*)(void*)>(funcAddr);

        void* str = spfc(spoof, fn, p_instance);


        return Getil2cppString((Il2CppString*)str);
    }


    int32_t GetActorNumber() const
    {
        if (!p_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
        uintptr_t funcAddr = base + RecRoom::Player::get_actorNumberOffset;
        if (!funcAddr)
            return -1;


        auto fn = reinterpret_cast<int32_t(*)(void*)>(funcAddr);

        return spfc(spoof, fn, p_instance);
    }


    bool GetIsMuted() const
    {
        if (!p_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_isMute;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    bool GetIsInVehicle() const
    {
        if (!p_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_IsInVehicle;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    int32_t GetPlayerIndex() const
    {
        if (!p_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_PlayerIndexOffset;

        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    int32_t GetPing() const
    {
        if (!p_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_PingOffset;

        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    bool GetIsVisible() const
    {
        if (!p_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_IsVisibleOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    bool GetIsSpawning() const
    {
        if (!p_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_IsSpawningOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    bool GetIsGameBackgrounded() const
    {
        if (!p_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_IsGameBackgroundedOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    bool GetIsFriend() const
    {
        if (!p_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_IsFriendOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }

    bool GetIsBlocked() const
    {
        if (!p_instance)
            return false;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return false;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_IsBlockedOffset;

        if (!funcAddr)
            return false;

        using Fn = bool(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }


    int32_t GetPlayerAccountId() const
    {
        if (!p_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
        uintptr_t funcAddr = base + RecRoom::Player::get_PlayerAccountIdOffset;
        if (!funcAddr)
            return -1;


        auto fn = reinterpret_cast<int32_t(*)(void*)>(funcAddr);

        return spfc(spoof, fn, p_instance);
    }

    int32_t GetPlayerId() const
    {
        if (!p_instance)
            return -1;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return -1;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_PlayerIdOffset;

        if (!funcAddr)
            return -1;

        using Fn = int32_t(*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }


    void* GetBoardedVehicle() const
    {
        if (!p_instance)
            return nullptr;

        HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
        if (!gameAssembly)
            return nullptr;

        uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);

        uintptr_t funcAddr = base + RecRoom::Player::get_BoardedVehicleOffset;
        if (!funcAddr)
            return nullptr;

        using Fn = void* (*)(void*, void*);

        Fn fn = reinterpret_cast<Fn>(funcAddr);

        return spfc(spoof, fn, p_instance, (void*)nullptr);
    }
};