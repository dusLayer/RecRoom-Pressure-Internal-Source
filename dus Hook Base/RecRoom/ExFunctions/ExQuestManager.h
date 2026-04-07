#pragma once




int32_t(*GetCurrentGameplayRoomIndex_O)(void*, void*);
int32_t GetCurrentGameplayRoomIndex_H(void* QuestManager, void* MethodInfo) {

	if (Quest::Skipper) {

		return Quest::RoomIndex;
	}
	return GetCurrentGameplayRoomIndex_O(QuestManager, MethodInfo);
}