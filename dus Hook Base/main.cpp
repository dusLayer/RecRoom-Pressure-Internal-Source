#include "includes.h"
#include "natives.h"
#include <chrono>
#include <algorithm>  
#include <string>
#include <vector>
#include <thread>
#include <cstdlib>
#include "Deps/Logger/Logger.h"
#include "Menu/Menu.h"
#include "Menu/Style.h"
#include "Menu/Cursor.h"
#include "cheat/AC Bypass/Bypass.h"
#include "main.h"
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include "Unity/il2cpp/globals.h"
#include "Unity/il2cpp/il2cpp.h"
#include "RecRoom/HookManager/Main_Hook.h"


HMODULE g_hMod = nullptr;




ID3D11Device* pDevice = nullptr;
ID3D11DeviceContext* pContext = nullptr;
ID3D11RenderTargetView* mainRenderTargetView = nullptr;
HWND window = nullptr;
WNDPROC oWndProc = nullptr;
std::vector<Snowflake> snowflakes;
bool init = false;
float rainbowTimer = 0.0f;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(__stdcall* Present)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
Present oPresent;
Logger logger("");

void CreateConsole() {
    AllocConsole();
    SetConsoleTitleA("Pressure Internal by _dus Github: dusLayer");
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONOUT$", "w", stderr);
    freopen_s(&f, "CONIN$", "r", stdin);
    std::cout.clear();
}

LRESULT __stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_KEYUP && wParam == VK_DELETE)
        UI::show = !UI::show;

    if (UI::show) {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        ImGuiIO& io = ImGui::GetIO();
        if (io.WantCaptureMouse || io.WantCaptureKeyboard)
            return true;
    }
    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

void il2cpp_Initi() {
    vars::ga = (uintptr_t)GetModuleHandle("GameAssembly.dll");
    vars::up = (uintptr_t)GetModuleHandle("UnityPlayer.dll");
    spoof = scanpat<uint64_t*>("FF 23", vars::ga);
    il2cppAPI::api();
    resolve();
    logger.info("[+] il2cpp resolved!\n");
    Sleep(500);
    auto dom = getdom();
    if (dom) {
        attach(dom);
        logger.info("[+] il2cpp_domain_get Found!\n");
    }
}

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
    if (!init) {
        if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice))) {
            pDevice->GetImmediateContext(&pContext);
            DXGI_SWAP_CHAIN_DESC sd;
            pSwapChain->GetDesc(&sd);
            window = sd.OutputWindow;
            ID3D11Texture2D* pBackBuffer;
            pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
            pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &mainRenderTargetView);
            pBackBuffer->Release();
            oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
            InitImGui();
            init = true;
            for (int i = 0; i < 120; i++) {
                snowflakes.push_back({
                    ImVec2((float)(rand() % 750), (float)(rand() % 550)),
                    0.4f + (rand() % 100) / 200.0f,
                    1.5f + (rand() % 3)
                    });
            }
        }
        else return oPresent(pSwapChain, SyncInterval, Flags);
    }
    pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
    static bool wasDown = false;
    bool isDown = GetAsyncKeyState(VK_DELETE) & 0x8000;
    if (isDown && !wasDown) UI::show = !UI::show;
    wasDown = isDown;
    Menu_Initi();
    return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved) {
    CreateConsole();
    if (MH_Initialize() != MH_OK) {
        logger.error("Minhook failed");
        return 0;
    }
    logger.info("Minhook MH_Initialized");

    bool init_hook = false;
    do {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
            Sleep(700);
            logger.info("Waiting for Referee...");
            while (!ModuleREF) {
                ModuleREF = (uintptr_t)GetModuleHandleA("Referee.dll");
                Sleep(500);
            }
            logger.info("Waiting for GameAssembly...");
            while (!ModuleGA) {
                ModuleGA = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
                Sleep(500);
            }
            Sleep(1000);
            Bypass();
            HookingManager();
            il2cpp_Initi();
            kiero::bind(8, (void**)&oPresent, hkPresent);
            init_hook = true;
        }
    } while (!init_hook);
    return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved) {
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
        g_hMod = hMod;
        DisableThreadLibraryCalls(hMod);

        
        std::thread([]() {
            Sleep(2500); 
            }).detach();


        std::thread(MainThread, hMod).detach();
        break;
    case DLL_PROCESS_DETACH:
        kiero::shutdown();
        MH_Uninitialize();
        break;
    }
    return TRUE;
}