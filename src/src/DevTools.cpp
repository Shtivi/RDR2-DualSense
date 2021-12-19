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

	}


	if (IsKeyJustUp(VK_F3))
	{
		createVehicle("hotchkiss_cannon", playerPos() + getForwardVector(player) * 8);
	}



	if (IsKeyJustUp(VK_KEY_K))
	{
		showSubtitle(getEntityHealthLevel(player));

		if (getEntityHealthLevel(player) < 0.5)
		{
			ENTITY::SET_ENTITY_HEALTH(player, ENTITY::GET_ENTITY_MAX_HEALTH(player, 1), 0);
		}
		else
		{
			ENTITY::SET_ENTITY_HEALTH(player, ENTITY::GET_ENTITY_MAX_HEALTH(player, 1) / 10	, 0);
		}
	}

}

