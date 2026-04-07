#pragma once
#include "../ExFunctions/ExLegacyTlsAuthentication.h"
#include "../../Deps/kiero/minhook/include/MinHook.h"



void LegacyTlsAuthentication_Hooks() {

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::LegacyTlsAuthentication::NotifyServerCertificateOffset)), &NotifyServerCertificate_H, (void**)&NotifyServerCertificate_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::LegacyTlsAuthentication::NotifyServerCertificateOffset)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::LegacyTlsAuthentication::IsValid)), &IsValid_H, (void**)&IsValid_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::LegacyTlsAuthentication::IsValid)));

	MH_CreateHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::LegacyTlsAuthentication::FatalApplicationQuitOffset)), &FatalApplicationQuit_H, (void**)&FatalApplicationQuit_O);
	MH_EnableHook(reinterpret_cast<void**>(ModuleGA + (RecRoom::LegacyTlsAuthentication::FatalApplicationQuitOffset)));
}