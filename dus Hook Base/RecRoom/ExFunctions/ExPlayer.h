#pragma once
#include "../../Menu/Notification.h"



Vector3 (*GetCurrentHeadPosition_O)(void*);
Vector3 GetCurrentHeadPosition_H(void* instance) {


	return GetCurrentHeadPosition_O(instance);
}

Quaternion (*GetRotation_O)(void*);
Quaternion GetRotation_H(void* instance) {


	return GetRotation_O(instance);
}


void (*RpcAuthorityCV2SetPosition_O)(void*, Vector3);
void RpcAuthorityCV2SetPosition_H(void* player, Vector3 position) {

	if (Protection::AntiTeleport) {

		ShowNotification("Protected from RPC Teleport");
		void* Local = Player::GetLocalPlayer();

		Vector3 position = GetCurrentHeadPosition_O(Local);

		return RpcAuthorityCV2SetPosition_O(player, position);
	}

	return RpcAuthorityCV2SetPosition_O(player, position);
}