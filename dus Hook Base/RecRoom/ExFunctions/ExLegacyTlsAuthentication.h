#pragma once


void (*NotifyServerCertificate_O)();
void NotifyServerCertificate_H() {

	return;
}

bool (*IsValid_O)();
bool IsValid_H() {

	return true;
}


void (*FatalApplicationQuit_O)();
void FatalApplicationQuit_H() {

	return;
}