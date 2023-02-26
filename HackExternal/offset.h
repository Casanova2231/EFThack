
#pragma once

#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <iostream>
#include  <d3dx9.h>
#include "singleton.h"
#include "vector.h"
inline HANDLE driver_handle;
inline LPCWSTR drivername = L"\\\\.\\n1ttld";

inline namespace RogueCompany
{
	class Variables : public Singleton<Variables>
	{
	public:
		//const char* dwProcessName = "WTL-Win64-Shipping.exe";

		DWORD PID;
		const char* dwProcessName = NULL;
		
		//

		D3DXMATRIX m_Matrix;

		//DWORD dwProcessId = NULL;
		uint64_t dwProcess_Base = NULL;
	    HWND gameHWND = NULL;

		int actor_count = NULL;
		int ScreenHeight = NULL;
		int ScreenWidth = NULL;
		int ScreenLeft = NULL;
		int ScreenRight = NULL;
		int ScreenTop = NULL;
		int ScreenBottom = NULL;
		int Meshpoint = NULL;

		float ScreenCenterX = ScreenWidth / 2;
		float ScreenCenterY = ScreenHeight / 2;

		int ste = NULL;
		DWORD_PTR gameManager = NULL;
		DWORD_PTR g_gameWorld = NULL;
		DWORD_PTR localGameWorld = NULL;
		DWORD_PTR GNameAddr = NULL;
		DWORD_PTR game_instance = NULL;
		DWORD_PTR LocalPlayerAddr = NULL;
		DWORD_PTR u_world = NULL;
		DWORD_PTR local_player_pawn = NULL;
		DWORD_PTR local_player_array = NULL;
		DWORD_PTR local_player = NULL;
		DWORD_PTR local_player_root = NULL;
		DWORD_PTR local_player_controller = NULL;
		DWORD_PTR local_player_state = NULL;
		DWORD_PTR local_player_Team = NULL;
		DWORD_PTR persistent_level = NULL;
		D3DMATRIX tempMatrix ;

		DWORD_PTR actors = NULL;
		DWORD_PTR equipped_flashlight = NULL;
		DWORD_PTR equipped_weapon_type = NULL;
		DWORD_PTR CameraManagerAddress = NULL;
		DWORD_PTR cam = NULL;
	};
#define GameVars RogueCompany::Variables::Get()

	class Offsets : public Singleton<Offsets>
	{
	public:

	};

#define GameOffset RogueCompany::Offsets::Get()
}
