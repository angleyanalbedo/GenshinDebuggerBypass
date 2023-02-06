#pragma once
#include "DebuggerBypass.h"
#include "CloseMhyprot2.h"

#include <stdio.h>
#include <format>
#define LOG(fmtstr, ...) printf("[ DebuggerBypass ] - %s\n", std::format(fmtstr, ##__VA_ARGS__).c_str())

void RunMain(HMODULE *phModule)
{
	// New Console
	
	

	DebuggerBypassPre();

	while (GetModuleHandle(L"UserAssembly.dll") == nullptr) {
		LOG("UserAssembly.dll isn't initialized. Waiting for 2 second.");
		Sleep(2000);
	}

	DebuggerBypassPost();

	LOG("Debug bypass complete.");

	// 这里不加大括号编译过不了 🖕Fuck C++🖕 🖕Fuck Microsoft🖕 
	//				^~~ Alukym#0615 是傻逼，不知道LOG展開會有分號，導致一個if出現兩個分號，而且要罵也是罵MSVC不是C++(?)；寫LOG Macro的也是傻逼，不要亂加分號 :(
	if (CloseHandleByName(L"\\Device\\mhyprot2"))
		LOG("Mhyprot2 was closed successfully.");
	else
		LOG("Failed to close mhyprot2 handle.");

	return;
}