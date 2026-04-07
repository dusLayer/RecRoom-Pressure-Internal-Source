#pragma once
#include "../../cheat/Exploits/Playerlist.h"
#include "../ExFunctions/ExPlayer.h"



void Player_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Player::RpcAuthorityCV2SetPositionOffset)), &RpcAuthorityCV2SetPosition_H, (void**)&RpcAuthorityCV2SetPosition_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Player::RpcAuthorityCV2SetPositionOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Player::get_PlayerNameOffset)), &GetPlayerName_H, (void**)&GetPlayerName_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Player::get_PlayerNameOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Player::get_CurrentHeadPositionOffset)), &GetCurrentHeadPosition_H, (void**)&GetCurrentHeadPosition_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::Player::get_CurrentHeadPositionOffset)));

}



