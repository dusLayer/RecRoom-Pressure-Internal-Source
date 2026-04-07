#pragma once
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <array>
#include <string>
#include "RecRoom/SDK/Player.h"

struct PlayerInfo {
    std::string playerName;
    int playerAccountId;
    int playerId;
    int32_t actorId;
    void* playerActor;
    void* photonPlayer;
    void* networkedPlayer;

    bool isMuted;
    bool isInVehicle;
    int32_t RoomIndex;
    int32_t Ping;
    bool IsVisible;
    bool IsSpawning;
    bool IsGameBackgrounded;
    bool IsFriend;
    bool IsBlocked;
    bool CanFly;

};

inline std::vector<PlayerInfo> g_PlayerList;
inline std::chrono::steady_clock::time_point g_LastUpdate;
inline int selectedPlayerIndex = -1;


namespace ESP {
    inline bool espEnabled = false;
    inline bool espLinesTop = false;
    inline bool espLinesCenter = false;
    inline bool espLinesBottom = false;
    inline bool espBox = false;
    inline bool espName = false;

    inline float nameColor[4] = { 1.f, 1.f, 1.f, 1.f };
    inline float boxColor[4] = { 0.7f, 0.5f, 1.0f, 1.f };
    inline float lineColor[4] = { 0.7f, 0.5f, 1.0f, 1.f };
    inline float headColor[4] = { 0.8f, 0.6f, 1.0f, 1.f };
    inline float textOffsetY = 20.0f;
    inline float boxOffsetY = 5.0f;
    inline ImFont* espFont = nullptr;
}

namespace Aimbot {
    inline bool aimbotEnabled = false;
    inline float aimbotFov = 150.0f;
    inline float fovColor[4] = { 1.f, 1.f, 1.f, 1.f };
    inline float smooth = 5.0f;
    inline int aimKey = 0;

    inline int lockedTarget = -1;
}

namespace Marker {

    inline bool MarkerEnabled = true;
}

