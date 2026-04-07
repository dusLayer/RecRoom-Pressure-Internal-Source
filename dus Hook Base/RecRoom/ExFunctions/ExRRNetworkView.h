#pragma once
#include "../../Unity/il2cpp/globals.h"
#include "../Offsets.h"
#include <vector>
#include <string>
#include <cstdint>
#include <cstring>


void (*SendRPC_O)(void* networkView, Il2CppString* rpcname, void* player, void* array, void* method);

Il2CppString* SendRPC_H(void* networkView, const std::string& rpcname, void* player, void* array, void* method) {

  


    //SendRPC_O(networkView, str, player, array, method);
}