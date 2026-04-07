#pragma once
#include "il2cppString.h"
#include "il2cpp-object-internals.h"
#include <Windows.h>
#include "../../Deps/spoof/returnspoof.hpp"




std::string Getil2cppString(Il2CppString* str)
{
    if (!str || str->length <= 0)
        return "";

    int size_needed = WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)str->chars, str->length, NULL, 0, NULL, NULL);
    if (size_needed <= 0)
        return "";

    std::string result(size_needed, '\0');
    WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)str->chars, str->length, result.data(), size_needed, NULL, NULL);
    return result;
}





Il2CppString* il2cpp_string_new(const char* str)
{
    HMODULE gameAssembly = GetModuleHandleA("GameAssembly.dll");
    if (!gameAssembly)
        return nullptr;

    uintptr_t base = reinterpret_cast<uintptr_t>(gameAssembly);
    uintptr_t funcAddr = base + RecRoom::il2cpp::il2cpp_String_NewOffset;
    if (!funcAddr)
        return nullptr;

    using Fn = Il2CppString * (*)(const char*);
    Fn fn = reinterpret_cast<Fn>(funcAddr);

    return spfc(spoof, fn, str);
}


