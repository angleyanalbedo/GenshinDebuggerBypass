#pragma once
#include "DebuggerBypass.h"
#include "CloseMhyprot2.h"

#include <stdio.h>
#include <format>
#define LOG(fmtstr, ...) printf("[ DebuggerBypass ] - %s\n", std::format(fmtstr, ##__VA_ARGS__).c_str())

void RunMain(HMODULE *phModule)
{
	
	DebuggerBypassPre();

	while (GetModuleHandle(L"UserAssembly.dll") == nullptr) {
		LOG("UserAssembly.dll isn't initialized. Waiting for 2 second.");
		Sleep(2000);
	}

	DebuggerBypassPost();

	LOG("Debug bypass complete.");

	
	if (CloseHandleByName(L"\\Device\\mhyprot2"))
		LOG("Mhyprot2 was closed successfully.");
	else
		LOG("Failed to close mhyprot2 handle.");

	return;
}