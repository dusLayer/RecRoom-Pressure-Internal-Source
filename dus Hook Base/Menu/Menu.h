#pragma once
#include "main.h"
#include "Cursor.h"
#include "Style.h"
#include "../Deps/imgui/imgui.h"
#include <cstdlib>
#include <string>
#include <vector>
#include "../natives.h"
#include "../Deps/Logger/Logger.h"


#include "Notification.h"

#include "../RecRoom/SDK/Player.h"

#include <algorithm>
#include <cctype>

#include "../cheat/Exploits/Esp.h"
#include "../RecRoom/SDK/RRNetworkView.h"
#include "../RecRoom/SDK/RRNetworkBehavior.h"
#include "../RecRoom/SDK/PlayerMovement.h"
#include "../RecRoom/SDK/GameEncounter.h"
#include "../RecRoom/SDK/GameManager.h"
#include "../RecRoom/SDK/GameCombatManager.h"
#include "../RecRoom/SDK/RecRoomSceneManager.h"
#include "../RecRoom/SDK/PlayerLogicComponet.h"
#include "../RecRoom/ExFunctions/ExPlayer.h"
#include "../PlayerlistGlobal.h"
#include "../cheat/Exploits/Playerlist.h"
#include "../cheat/Exploits/Aimbot.h"
#include "../cheat/Exploits/Teleport.h"
#include "../RecRoom/SDK/QuestManager.h"

#include "../RecRoom/il2cpp/il2cppString.h"
#include "../RecRoom/ExFunctions/ExTool.h"

#include "../VehicleGlobal.h"
#include "../cheat/Exploits/Vehicle.h"


Logger logger1("Log.log");


std::string ToLower(const char* str) {
    if (!str) return "";

    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return result;
}


static int selectedQuest = 0;


void HandleMenuToggle()
{
    static bool wasDown = false;
    bool isDown = GetAsyncKeyState(VK_DELETE) & 0x8000;


    if (isDown && !wasDown)
    {
        UI::show = !UI::show;
        UI::showLog = !UI::show;
    }


    wasDown = isDown;
}


void DrawFPS()
{
    if (!UI::showFPS)
        return;

    ImGuiIO& io = ImGui::GetIO();
    float fps = io.Framerate;

    char buffer[64];
    sprintf_s(buffer, "Pressure Internal | By _dus FPS: %.0f", fps);

    ImDrawList* draw = ImGui::GetForegroundDrawList();

    ImVec2 textSize = ImGui::CalcTextSize(buffer);
    ImVec2 screenSize = io.DisplaySize;

    float paddingX = 8.0f;
    float paddingY = 4.0f;

    float boxWidth = textSize.x + paddingX * 2;
    float boxHeight = textSize.y + paddingY * 2;

   
    float x = floorf((screenSize.x * 0.5f) - (boxWidth * 0.5f));
    float y = 12.0f;

    ImVec2 boxMin(x, y);
    ImVec2 boxMax(x + boxWidth, y + boxHeight);

  
    draw->AddRectFilled(
        boxMin,
        boxMax,
        IM_COL32(0, 0, 0, 140), 
        0.0f 
    );

  
    draw->AddRect(
        boxMin,
        boxMax,
        IM_COL32(255, 255, 255, 60),
        0.0f,
        0,
        1.0f
    );


    draw->AddText(
        ImVec2(x + paddingX, y + paddingY),
        IM_COL32(255, 255, 255, 255),
        buffer
    );
}

void DrawCrosshair()
{
    if (!UI::showCrosshair)
        return;

    ImGuiIO& io = ImGui::GetIO();
    ImDrawList* draw = ImGui::GetForegroundDrawList();

    float cx = io.DisplaySize.x * 0.5f;
    float cy = io.DisplaySize.y * 0.5f;


    ImU32 color = IM_COL32(
        (int)(UI::crosshairColor.x * 255),
        (int)(UI::crosshairColor.y * 255),
        (int)(UI::crosshairColor.z * 255),
        (int)(UI::crosshairColor.w * 255)
    );

    float size = UI::crosshairSize;
    float thickness = UI::crosshairThickness;

    
    draw->AddLine(ImVec2(cx - size, cy), ImVec2(cx + size, cy), color, thickness);

 
    draw->AddLine(ImVec2(cx, cy - size), ImVec2(cx, cy + size), color, thickness);
}





void Menu_Initi() {
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();


    DrawFPS();
    HandleMenuToggle();
    DrawCrosshair();
    DrawNotification();

    if (ESP::espEnabled) {
        DrawESP();
    }

   
    if (Aimbot::aimbotEnabled) {
        DrawFOV();
        RunAimbot(UI::show);
    }

  


    if (Vehicle::CustomTransform) {

        CustomTransform();

    }


    if (UI::show)
    {
        ShowCursor(FALSE);
        DrawCustomCursor();

        ImGui::SetNextWindowSize(ImVec2(850, 550), ImGuiCond_Always);
        ImGui::Begin("Pressure Internal | By _dus", &UI::show,
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoScrollbar |
            ImGuiWindowFlags_NoTitleBar);

        ImDrawList* draw = ImGui::GetWindowDrawList();
        ImVec2 winPos = ImGui::GetWindowPos();
        ImVec2 winSize = ImGui::GetWindowSize();

        float rounding = 10.0f;

        
        draw->AddRect(
            winPos,
            ImVec2(winPos.x + winSize.x, winPos.y + winSize.y),
            IM_COL32(0, 0, 0, 200),
            rounding,
            0,
            2.0f
        );

      
        draw->AddRectFilled(
            winPos,
            ImVec2(winPos.x + winSize.x, winPos.y + 45),
            IM_COL32(25, 25, 28, 255),
            rounding,
            ImDrawFlags_RoundCornersTop
        );

        
        ImVec2 titleSize = ImGui::CalcTextSize("Pressure Internal | By _dus");
        draw->AddText(
            ImVec2(
                winPos.x + (winSize.x / 2) - (titleSize.x / 2),
                winPos.y + 12
            ),
            IM_COL32(255, 255, 255, 255),
            "Pressure Internal | By _dus"
        );

        ImGui::Dummy(ImVec2(0, 30)); 

        if (ImGui::BeginTabBar("##MainTabBar"))
        {
            
            ImVec2 contentMin = ImGui::GetWindowPos();
            ImVec2 contentMax = ImVec2(
                contentMin.x + ImGui::GetWindowSize().x,
                contentMin.y + ImGui::GetWindowSize().y
            );

            
            draw->PushClipRect(
                ImVec2(contentMin.x, contentMin.y + 45),
                contentMax,
                true
            );

            for (auto& s : snowflakes)
            {
                s.pos.y += s.speed;

                if (s.pos.y > ImGui::GetWindowSize().y)
                {
                    s.pos.y = 0;
                    s.pos.x = (float)(rand() % (int)ImGui::GetWindowSize().x);
                }

                float px = contentMin.x + s.pos.x;
                float py = contentMin.y + 45 + s.pos.y; 

                draw->AddRectFilled(
                    ImVec2(px, py),
                    ImVec2(px + s.size, py + s.size),
                    IM_COL32(255, 255, 255, 180),
                    2.0f
                );
            }

            draw->PopClipRect();

            if (ImGui::BeginTabItem("Local"))
            {
                ImGui::Checkbox("Dynamic fly", &Local::DynamicFly);

                ImGui::Checkbox("Custome Walkspeed", &Local::CustomeWalkspeed);

                if (Local::CustomeWalkspeed) {

                    ImGui::SliderFloat("Walkspeed", &Local::Walkspeed, 0, 1000);
                }


                

              

                ImGui::Checkbox("Is Developer", &Local::IsDeveloper);

                ImGui::Checkbox("Is WhiteGloveCreator", &Local::IsWhiteGloveCreator);

                ImGui::Checkbox("Is Volunteery Moderator", &Local::IsModerator);

                ImGui::Text("Works in all games with a Game Chip");
                
                ImGui::Checkbox("Instant Respawn", &Combat::InstantRespawn);

                ImGui::Checkbox("Custome Health", &Combat::CustomeHealth);

                if (Combat::CustomeHealth) {
                    ImGui::InputInt("Health", &Combat::Health);
                }

                ImGui::Checkbox("Custome Shield", &Combat::CustomeShield);

                if (Combat::CustomeShield) {
                    ImGui::InputInt("Shield", &Combat::Shield);
                }

                if (ImGui::Button("Test")) {

                    ShowNotification("Test");
                }

                ImGui::EndTabItem();
            }


            if (ImGui::BeginTabItem("Visuals"))
            {
                ImGui::Checkbox("Enable ESP", &ESP::espEnabled);


                ImGui::Separator();


                ImGui::Checkbox("Box ESP", &ESP::espBox);
                ImGui::Checkbox("Name ESP", &ESP::espName);

                ImGui::Separator();

                ImGui::Text("Lines");
                ImGui::Checkbox("Top", &ESP::espLinesTop);
                ImGui::Checkbox("Center", &ESP::espLinesCenter);
                ImGui::Checkbox("Bottom", &ESP::espLinesBottom);

                ImGui::Separator();

                ImGui::ColorEdit4("Box Color", ESP::boxColor);
                ImGui::ColorEdit4("Name Color", ESP::nameColor);
                ImGui::ColorEdit4("Line Color", ESP::lineColor);
                ImGui::ColorEdit4("Head Color", ESP::headColor);


                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Aimbot"))
            {
                ImGui::Checkbox("Enable Aimbot", &Aimbot::aimbotEnabled);
                ImGui::SliderFloat("FOV", &Aimbot::aimbotFov, 50.0f, 400.0f);

                ImGui::SliderFloat("Smoothness", &Aimbot::smooth, 0.7, 10);

                ImGui::Separator();

                ImGui::ColorEdit4("FOV Color", Aimbot::fovColor);

                const char* keys[] = { "Left Mouse", "Right Mouse", "Left Alt" };
                ImGui::Combo("Aimbot Hotkey", &Aimbot::aimKey, keys, IM_ARRAYSIZE(keys));
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Playerlist"))
            {
                UpdatePlayers();
                CleanupPlayers();


                if (selectedPlayerIndex >= g_PlayerList.size())
                    selectedPlayerIndex = -1;


                ImGui::Columns(3, nullptr, true);


                ImGui::BeginChild("Playerlist", ImVec2(0, 0), true);
                for (size_t i = 0; i < g_PlayerList.size(); i++)
                {
                    auto& p = g_PlayerList[i];
                    const char* name = p.playerName.empty() ? "Unknown" : p.playerName.c_str();

                    if (ImGui::Selectable(name, selectedPlayerIndex == i))
                        selectedPlayerIndex = i;
                }
                ImGui::EndChild();
                ImGui::NextColumn();


                ImGui::BeginChild("PlayerInfo", ImVec2(0, 0), true);
                if (selectedPlayerIndex >= 0 && selectedPlayerIndex < g_PlayerList.size())
                {
                    auto& p = g_PlayerList[selectedPlayerIndex];

                    ImGui::Text("Name: %s", p.playerName.c_str());
                    ImGui::Text("ActorId: %d", p.actorId);
                    ImGui::Text("Account Id: %d", p.playerAccountId);
                    ImGui::Text("Player Id: %d", p.playerId);
                    ImGui::Text("Actor: %p", p.playerActor);

                    ImGui::Separator();

                    ImGui::Text("Ping: %d", p.Ping);
                    ImGui::Text("RoomIndex: %d", p.RoomIndex);

                    ImGui::Text("Muted: %s", p.isMuted ? "true" : "false");
                    ImGui::Text("Vehicle: %s", p.isInVehicle ? "true" : "false");

                    ImGui::Text("Visible: %s", p.IsVisible ? "true" : "false");
                    ImGui::Text("Spawning: %s", p.IsSpawning ? "true" : "false");
                    ImGui::Text("Backgrounded: %s", p.IsGameBackgrounded ? "true" : "false");
                    ImGui::Text("CanFly: %s", p.CanFly ? "true" : "false");

                    ImGui::Text("Friend: %s", p.IsFriend ? "true" : "false");
                    ImGui::Text("Blocked: %s", p.IsBlocked ? "true" : "false");

                }
                ImGui::EndChild();
                ImGui::NextColumn();


                ImGui::BeginChild("PlayerFunctions", ImVec2(0, 0), true);
                if (selectedPlayerIndex >= 0 && selectedPlayerIndex < g_PlayerList.size())
                {
                    auto& p = g_PlayerList[selectedPlayerIndex];


                    if (ImGui::Button("Teleport To Player"))
                    {
                        TeleportToPlayer(selectedPlayerIndex);
                    }

                }
                ImGui::EndChild();

                ImGui::Columns(1);
                
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Vehicle"))
            {
                UpdateVehicle();

                ImGui::Columns(2, nullptr, true);

                ImGui::BeginChild("VehicleInfos", ImVec2(0, 0), true);

                if (g_Vehicle.boardedVehicle)
                {
                    ImGui::Text("Vehicle: %p", g_Vehicle.boardedVehicle);

                    ImGui::Separator();

                    ImGui::Text("Has driver: %s", g_Vehicle.HasDriver ? "true" : "false");
                    ImGui::Text("Speed: %.2f", g_Vehicle.Speed);
                    ImGui::Text("Is Started: %s", g_Vehicle.IsStarted ? "true" : "false");
                }

                ImGui::EndChild();
                ImGui::NextColumn();

                ImGui::BeginChild("VehicleFunction", ImVec2(0, 0), true);

                if (g_Vehicle.boardedVehicle)
                {
                    if (ImGui::Button(g_Vehicle.IsStarted ? "Turn Car Off" : "Turn Car On"))
                    {
                        ToggleVehicle();
                    }

                    ImGui::Checkbox("Custom Transform", &Vehicle::CustomTransform);
                    ImGui::SliderFloat("Speed", &Vehicle::speedMultiplier, 0.05, 100);


                }


                ImGui::EndChild();

                ImGui::Columns(1);
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Weapons"))
            {
                ImGui::Checkbox("Rapid Fire", &Weapons::get_IsOnCooldown);

                ImGui::Checkbox("Custome Spread", &Weapons::CustomeSpread);

                if (Weapons::CustomeSpread) {
                    ImGui::SliderFloat("Spread Multiplier", &Weapons::Spread, 0, 100);
                }

                ImGui::Checkbox("No Recoil", &Weapons::NoRecoil);

                ImGui::Checkbox("Infinity Ammo", &Weapons::InfAmmo);

                ImGui::Checkbox("Custome Ammo", &Weapons::CustomeAmmo);

                if (Weapons::CustomeAmmo) {
                    ImGui::InputInt("Ammo", &Weapons::Ammo);
                }

                ImGui::Checkbox("Custome Projectile Lifetime", &Weapons::CustomeLifetime);

                if (Weapons::CustomeLifetime) {
                    ImGui::SliderFloat("Lifetime", &Weapons::Lifetime, 0, 1000);
                }

                ImGui::Checkbox("Custome Projectile Speed", &Weapons::CustomeCurrentProjectileSpeed);

                if (Weapons::CustomeCurrentProjectileSpeed) {
                    ImGui::SliderFloat("Speed", &Weapons::get_CurrentProjectileSpeed, 0, 200);
                }



                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Protection"))
            {
                ImGui::Checkbox("Anti Teleport", &Protection::AntiTeleport);


                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Asset"))
            {
                static char searchBuf[128] = "";
                ImGui::InputText("Search", searchBuf, IM_ARRAYSIZE(searchBuf));
                ImGui::Separator();

              
                ImGui::Columns(2, nullptr, true);

              
                if (ImGui::BeginChild("PrefabList", ImVec2(0, 0), true))
                {
                    std::string search = ToLower(searchBuf);

                    for (size_t i = 0; i < IM_ARRAYSIZE(list); i++)
                    {
                        const char* prefabName = list[i];

                        if (!search.empty())
                        {
                            std::string prefabLower = ToLower(prefabName);
                            if (prefabLower.find(search) == std::string::npos)
                                continue;
                        }

                        if (ImGui::Selectable(prefabName, assetspawn::selectedprefab == i))
                        {
                            assetspawn::selectedprefab = static_cast<int>(i);
                        }
                    }

                    ImGui::EndChild();
                }

                ImGui::NextColumn();

         
                if (assetspawn::selectedprefab >= 0)
                {
                    ImGui::Text("Selected: %s", list[assetspawn::selectedprefab]);
                    assetspawn::Name = list[assetspawn::selectedprefab];

                    ImGui::Spacing();
                    ImGui::Text("Settings");
                    ImGui::SliderFloat("Scale", &assetspawn::scale, 0.1f, 1000.0f);
                    ImGui::SliderInt("Amount", &assetspawn::count, 1, 100);

                    ImGui::Spacing();
                    if (ImGui::Button("Spawn", ImVec2(-1, 0)))
                    {

                    }
                }

                ImGui::Columns(1); 
                ImGui::EndTabItem();
            }




            if (ImGui::BeginTabItem("Quest"))
            {
                ImGui::BeginChild("LeftSide", ImVec2(ImGui::GetContentRegionAvail().x * 0.4f, 0), true);
                {
                    ImGui::Text("Infos");
                    ImGui::Separator();

                    void* qm_instance = QuestManager::get_Instance();

                    QuestManager quest(qm_instance);

                    bool isRunning = quest.GetIsQuestRunning();

                    ImGui::Text("Current Gameplay Room Index: %d", Quest::RoomIndex);
                    ImGui::Text("Is Quest Running: %s", isRunning ? "true" : "false");
                }
                ImGui::EndChild();

                ImGui::SameLine();

                ImGui::BeginChild("RightSide", ImVec2(0, 0), true);
                {
                    ImGui::Text("Functions");
                    ImGui::Separator();

                    ImGui::Checkbox("Godmode", &Combat::Godmode);

                    ImGui::Checkbox("Skipper", &Quest::Skipper);

                    if (Quest::Skipper)
                    {
                        ImGui::Combo("Select Quest", &selectedQuest, questItems, IM_ARRAYSIZE(questItems));

                        
                        switch (selectedQuest)
                        {
                        case 0: Quest::RoomIndex = 9; break;
                        case 1: Quest::RoomIndex = 9; break;
                        case 2: Quest::RoomIndex = 9; break;
                        case 3: Quest::RoomIndex = 7; break;
                        case 4: Quest::RoomIndex = 12; break;
                        case 5: Quest::RoomIndex = 99; break;
                        }
                    }
                }
                ImGui::EndChild();

                ImGui::EndTabItem();
            }


            
            if (ImGui::BeginTabItem("Settings"))
            {
                ImGui::Checkbox("Show FPS", &UI::showFPS);

                if (ImGui::CollapsingHeader("Crosshair"))
                {
                    ImGui::Checkbox("Show Crosshair", &UI::showCrosshair);
                    ImGui::ColorEdit4("Crosshair Color", (float*)&UI::crosshairColor);
                    ImGui::SliderFloat("Size", &UI::crosshairSize, 5.0f, 30.0f);
                    ImGui::SliderFloat("Thickness", &UI::crosshairThickness, 1.0f, 5.0f);
                }
               

                ImGui::Checkbox("Playerlist Marker", &Marker::MarkerEnabled); 


                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

        ImGui::End();
    }

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}