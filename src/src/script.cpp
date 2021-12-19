/*
/*
	THIS FILE IS A PART OF RDR 2 SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2019
*/

#include "Main.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Ped player;

bool Initialize()
{
	player = PLAYER::PLAYER_PED_ID();

	ScriptSettings::load("DualSense/Settings.ini", new SettingsMap {
		{ "StaminaIndication", "1" },
		{ "HealthIndication", "1" },
		{ "WeaponDegregationStiffness", "1" }
	});

	return true;
}

ofstream dualsenseInput;
const char* mode = "OFF";
float stiffness = 0;
float pulseRate = 0;
float health = 0;

void writeDualsenseInput(const char* input)
{
	dualsenseInput.open("DualSense/inputs", std::ios_base::out);
	dualsenseInput << input;
	dualsenseInput.close();
}

void setDualsenseTriggerMode(const char* _mode, float _stiffness = 0)
{
	mode = _mode;

	if (ScriptSettings::getBool("WeaponDegregationStiffness"))
	{
		stiffness = _stiffness;
	}
	else
	{
		stiffness = 0;
	}
}

void updateTriggers()
{
	Hash weapon = getPedEquipedWeapon(player);
	Hash mountedWeapon = NULL;
	WEAPON::GET_CURRENT_PED_VEHICLE_WEAPON(player, &mountedWeapon);

	if (PED::IS_PED_RELOADING(player))
	{
		setDualsenseTriggerMode("RELOAD");
	}
	else if (WEAPON::_IS_WEAPON_THROWABLE(weapon) || WEAPON::IS_WEAPON_BOW(weapon))
	{
		setDualsenseTriggerMode("THROWABLE");
	}
	else if (WEAPON::IS_WEAPON_A_GUN(weapon))
	{
		if (PLAYER::IS_PLAYER_FREE_AIMING(PLAYER::PLAYER_ID()) && !WEAPON::IS_PED_WEAPON_READY_TO_SHOOT(player))
		{
			setDualsenseTriggerMode("GUN_COCK", WEAPON::GET_WEAPON_DEGRADATION(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(player, 0)));
		}
		else
		{
			setDualsenseTriggerMode("GUN_MANUAL", WEAPON::GET_WEAPON_DEGRADATION(WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(player, 0)));
		}

	}
	else if (
		mountedWeapon == -628784915 /* Gatling */ ||
		mountedWeapon == -1193642378 /* Maxim */)
	{
		if (PED::IS_PED_SHOOTING(player))
		{
			setDualsenseTriggerMode("GUN_AUTOMATIC", 0);
		}
		else
		{
			setDualsenseTriggerMode("GUN_AUTOMATIC_PREPARE");
		}
	}
	else if (
		mountedWeapon == 1609145491 /*normal cannon*/ ||
		mountedWeapon == -1829236809 /* Automatic cannon */ )
	{
		setDualsenseTriggerMode("CANNON");
	}
	else
	{
		setDualsenseTriggerMode("OFF");
	}
}

void updateLights()
{
	if (ScriptSettings::getBool("HealthIndication"))
	{
		health = (float)ENTITY::GET_ENTITY_HEALTH(player) / (float)PED::GET_PED_MAX_HEALTH(player);
	}
	else
	{
		health = 1;
	}

	if (ScriptSettings::getBool("StaminaIndication"))
	{
		Ped staminaTarget = player;
		if (PED::IS_PED_ON_MOUNT(player))
		{
			staminaTarget = PED::GET_MOUNT(player);
		}

		float stamina = PED::_GET_PED_STAMINA(staminaTarget) / PED::_GET_PED_MAX_STAMINA(staminaTarget);
		pulseRate = 1 - stamina;
	}
	else
	{
		pulseRate = 0;
	}
}

void main()
{
	WAIT(500);


	if (!Initialize())
	{
		return;
	}

	while (true)
	{

		player = PLAYER::PLAYER_PED_ID();

		try
		{
			updateTriggers();
			updateLights();

			writeDualsenseInput(
				string("MODE=").append(mode)
				.append("\n")
				.append("STIFFNESS=").append(to_string(stiffness)
				.append("\n")
				.append("PULSE_RATE=").append(to_string(pulseRate))
				.append("\n")
				.append("HEALTH=").append(to_string(health))
			).c_str());
		}
		catch (...)
		{
			log("Something wrong happened");
			std::exception_ptr ex = std::current_exception();
			try
			{
				if (ex)
				{
					rethrow_exception(ex);
				}
				else
				{
					log("No exception captured.");
				}
			}
			catch (const exception& e)
			{
				const char* logMsg =
					string("Fatal: ")
					.append(e.what())
					.append(", check the logs for more info.").c_str();

				log(logMsg);
				showSubtitle(logMsg);
			}
		}

		if (DevTools::isActive())
		{
			DevTools::update();
		}

		if (false && IsKeyJustUp(VK_F2))
		{
			DevTools::toggle();
		}

		WAIT(0);
	}
}

void ScriptMain()
{
	srand(GetTickCount());
	main();
}

void debug(const char* text)
{
	drawText((char*)text, 0, 0, 255, 255, 255, 255, false, 0.7, 0.7, "$title");
}

void debug(string text) {
	debug(text.c_str());
}

void debug(Vector3 pos) {
	stringstream str;
	str << pos.x << ", " << pos.y << ", " << pos.z;
	debug(str.str());
}

void debug(float f) {
	debug(to_string(f));
}

void debug(int n) {
	debug(to_string(n));
}

void debug(bool b) {
	debug(to_string(b));
}

void debug(Hash hash) {
	debug(to_string((int)hash));
}

void logPlayerPos()
{
	Vector3 playerPos = entityPos(player);
	float ground;
	MISC::GET_GROUND_Z_FOR_3D_COORD(playerPos.x, playerPos.y, playerPos.z, &ground, false);
	std::stringstream output;
	output << "\n"
		<< playerPos.x << ", " << playerPos.y << ", " << playerPos.z << "\n"
		<< playerPos.x << ", " << playerPos.y << ", " << ground << "\n"
		<< "heading: " << ENTITY::GET_ENTITY_HEADING(player);

	log(output.str().c_str());
	showSubtitle(to_string(getGroundPos(playerPos)));
}