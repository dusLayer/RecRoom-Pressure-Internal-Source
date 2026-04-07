#pragma once




typedef Vector3(*worldtoscreen_t)(void*, Vector3, int);
worldtoscreen_t WorldToScreenPoint_O = nullptr;

Vector3 WorldToScreenPoint_H(void* camera, Vector3 position, int eye)
{
    return WorldToScreenPoint_O(camera, position, eye);
}



typedef void* (__thiscall* get_main_t)();
get_main_t get_main_O = nullptr;

void* __fastcall get_main_H() {


    void* camera = get_main_O();



    return camera;
}