#include "Main.h"

bool DevTools::active = false;

bool DevTools::isActive()
{
	return active;
}

void DevTools::toggle()
{
	if (active)
	{
		disable();
	}
	else
	{
		enable();
	}
}

void DevTools::enable()
{
	showSubtitle("Debug tools ON");
	ENTITY::SET_ENTITY_INVINCIBLE(player, true);
	active = true;
}

void DevTools::disable()
{
	showSubtitle("Debug tools OFF");
	ENTITY::SET_ENTITY_INVINCIBLE(player, false);
	active = false;
}

HANDLE g_hChildStd_IN_Rd = NULL;
HANDLE g_hChildStd_IN_Wr = NULL;
HANDLE g_hChildStd_OUT_Rd = NULL;
HANDLE g_hChildStd_OUT_Wr = NULL;


void DevTools::update()
{
	ENTITY::SET_ENTITY_INVINCIBLE(player, true);
	Vector3 pos = playerPos();

	Hash weaponHash;
	WEAPON::GET_CURRENT_PED_WEAPON(player, &weaponHash, 0, 0, 0);
	if (weaponHash != MISC::GET_HASH_KEY("WEAPON_UNARMED")) {
		Entity e;
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &e) /*&& distanceBetweenEntities(player, e) < 20*/) 
		{
			if (IsKeyJustUp(VK_KEY_K))
			{
			}

			if (IsKeyJustUp(VK_KEY_Z))
			{
			}
		}
		else
		{
			if (IsKeyJustUp(VK_KEY_Z))
			{
			}
		}
	}
	else
	{
		Entity targetEntity;
		if (PLAYER::GET_PLAYER_TARGET_ENTITY(PLAYER::PLAYER_ID(), &targetEntity))
		{
			
			if (IsKeyJustUp(VK_KEY_Z))
			{
			}
		}
		else
		{

		}
	}

	if (IsKeyJustUp(VK_KEY_X))
	{
		//WEAPON::SET_PED_AMMO(player, getPedEquipedWeapon(player), 100);
	}

	if (IsKeyJustUp(VK_F1))
	{
		WEAPON::SET_PED_INFINITE_AMMO(player, true, getPedEquipedWeapon(player));
	}

	LAW::_SET_WANTED_INTENSITY_FOR_PLAYER(PLAYER::PLAYER_ID(), 0);
	PLAYER::SET_MAX_WANTED_LEVEL(0);

	if (IsKeyJustUp(VK_KEY_Z))
	{
		if (getEntityHealthLevel(player) < 0.5)
		{
			ENTITY::SET_ENTITY_HEALTH(player, ENTITY::GET_ENTITY_MAX_HEALTH(player, 1), 0);
		}
		else
		{
			ENTITY::SET_ENTITY_HEALTH(player, ENTITY::GET_ENTITY_MAX_HEALTH(player, 1) / 4, 0);
		}
	}


	if (IsKeyJustUp(VK_F3))
	{
		createVehicle("hotchkiss_cannon", playerPos() + getForwardVector(player) * 8);
	}



	if (IsKeyJustUp(VK_KEY_K))
	{
		SECURITY_ATTRIBUTES saAttr;
		saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
		saAttr.bInheritHandle = TRUE;
		saAttr.lpSecurityDescriptor = NULL;

		if (!CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0))
		{
			showSubtitle("failed to create stdout");
			return;
		}

		if (!SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0))
		{
			showSubtitle("Stdout SetHandleInformation");
			return;
		}

		if (!CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
		{
			showSubtitle("failed to create stdin");
			return;
		}

		if (!SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0))
		{
			showSubtitle("Stdin SetHandleInformation");
			return;
		}

		// Create the child process. 

		TCHAR szCmdline[] = TEXT("py main.py");
		PROCESS_INFORMATION piProcInfo;
		STARTUPINFO siStartInfo;
		BOOL bSuccess = FALSE;

		// Set up members of the PROCESS_INFORMATION structure. 

		ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

		// Set up members of the STARTUPINFO structure. 
		// This structure specifies the STDIN and STDOUT handles for redirection.

		ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
		siStartInfo.cb = sizeof(STARTUPINFO);
		siStartInfo.hStdError = g_hChildStd_OUT_Wr;
		siStartInfo.hStdOutput = g_hChildStd_OUT_Wr;
		siStartInfo.hStdInput = g_hChildStd_IN_Rd;
		siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

		//bSuccess = CreateProcess(NULL,
		//	szCmdline,     // command line 
		//	NULL,          // process security attributes 
		//	NULL,          // primary thread security attributes 
		//	TRUE,          // handles are inherited 
		//	0,             // creation flags 
		//	NULL,          // use parent's environment 
		//	NULL,          // use parent's current directory 
		//	&siStartInfo,  // STARTUPINFO pointer 
		//	&piProcInfo);  // receives PROCESS_INFORMATION 

		HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, 21840);


		 // If an error occurs, exit the application. 
		//if (!bSuccess)
		//	showSubtitle("CreateProcess failed");
		if (!processHandle)
		{
			showSubtitle("OpenProcess failed");
		}
		else
		{
			GetProcessInformation(
				processHandle,
				ProcessInformationClassMax,
				&piProcInfo,
				sizeof(PROCESS_INFORMATION)
			);

			bool wasAiming = PLAYER::IS_PLAYER_FREE_AIMING(0);

			while (true)
			{
				DWORD written = 0;
				CHAR chBuf[128];
				bool isAiming = PLAYER::IS_PLAYER_FREE_AIMING(0);

				if (isAiming != wasAiming)
				{
					if (isAiming)
					{
						strcpy(chBuf, "ON\n");
						if (!WriteFile(g_hChildStd_IN_Wr, chBuf, strlen(chBuf), &written, NULL) || written == 0)
						{
							showSubtitle("failed to write");
						}
						else
						{
							showSubtitle(chBuf);
						}
					}
					else
					{
						strcpy(chBuf, "OFF\n");
						if (!WriteFile(g_hChildStd_IN_Wr, chBuf, strlen(chBuf), &written, NULL) || written == 0)
						{
							showSubtitle("failed to write");
						}
						else
						{
							showSubtitle(chBuf);
						}
					}
				}

				wasAiming = isAiming;

				WAIT(0);
			}

			CloseHandle(piProcInfo.hProcess);
			CloseHandle(piProcInfo.hThread);
			CloseHandle(g_hChildStd_OUT_Wr);
			CloseHandle(g_hChildStd_IN_Rd);
		}
	}

}

