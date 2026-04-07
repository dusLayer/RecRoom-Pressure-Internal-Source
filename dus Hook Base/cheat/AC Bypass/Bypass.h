#pragma once
#include <Windows.h>
#include "../../Deps/kiero/minhook/include/MinHook.h"
#include <iostream>
#include "../../natives.h"
#include "../../includes.h"
#include "../../Deps/Logger/Logger.h"


Logger BypassLogger("Log.log");


namespace ACOffsets {

    //No Leaks
    uintptr_t refOffset1 = 0x0;

    uintptr_t refOffset2 = 0x0;

    uintptr_t refOffset3 = 0x0;


}


void (*nop_o)();
void nop_h() {

    return;
}


void Bypass()
{ 
    MH_CreateHook(reinterpret_cast<void**>(ModuleREF + (ACOffsets::refOffset1)), &nop_h, (void**)&nop_o);
    MH_EnableHook(reinterpret_cast<void**>(ModuleREF + (ACOffsets::refOffset1)));

    MH_CreateHook(reinterpret_cast<void**>(ModuleREF + (ACOffsets::refOffset2)), &nop_h, (void**)&nop_o);
    MH_EnableHook(reinterpret_cast<void**>(ModuleREF + (ACOffsets::refOffset2)));

    MH_CreateHook(reinterpret_cast<void**>(ModuleREF + (ACOffsets::refOffset3)), &nop_h, (void**)&nop_o);
    MH_EnableHook(reinterpret_cast<void**>(ModuleREF + (ACOffsets::refOffset3)));


    BypassLogger.info("Anti Cheat successfully bypassed");

}
