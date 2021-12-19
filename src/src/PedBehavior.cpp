#include "Main.h";

PedBehavior::PedBehavior(Ped ped, bool persistBlip)
{
	_pedHandle = ped;
	_isActive = false;
	_persistBlip = persistBlip;
}

Ped PedBehavior::ped()
{
	return _pedHandle;
}

bool PedBehavior::isActive()
{
	return _isActive;
}

void PedBehavior::start()
{
	_isActive = true;
}

void PedBehavior::update()
{
	if (!isAlive())
	{
		stop();
	}
}

void PedBehavior::stop()
{
	_isActive = false;
}

bool PedBehavior::isAlive()
{
	return !ENTITY::IS_ENTITY_DEAD(ped()) && !PED::IS_PED_DEAD_OR_DYING(ped(), true);
}

bool PedBehavior::isThreatenedByPlayer(int seeingRange, int hearingRange)
{
	Player playerId = PLAYER::PLAYER_ID();
	float distanceToPlayer = distanceBetweenEntities(ped(), player);

	if (PLAYER::IS_PLAYER_FREE_AIMING(playerId))
	{
		if (distanceToPlayer <= 10 && hasPedClearLosInFront(ped(), player, seeingRange))
		{
			return true;
		}

		if (PLAYER::IS_PLAYER_FREE_AIMING_AT_ENTITY(playerId, ped()) && hasPedClearLosInFront(ped(), player, seeingRange))
		{
			return true;
		}
	}

	if (PED::IS_PED_SHOOTING(player) && distanceToPlayer <= 15)
	{
		return true;
	}

	Vector3 lastImpactCoords;
	WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(player, &lastImpactCoords);
	if (PED::IS_PED_SHOOTING(player) && distance(lastImpactCoords, ped()) <= 15 && distanceToPlayer <= hearingRange)
	{
		return true;
	}

	return false;
}

void PedBehavior::setPersistBlip(bool persistBlip)
{
	_persistBlip = persistBlip;
}

bool PedBehavior::getPersistBlip()
{
	return _persistBlip;
}

void PedBehavior::addEnemyBlip()
{
	if (!MAP::DOES_BLIP_EXIST(MAP::GET_BLIP_FROM_ENTITY(ped())))
	{
		createBlip(ped(), BLIP_STYLE_ENEMY);
	}
}

void PedBehavior::removeBlip()
{
	if (!_persistBlip)
	{
		Blip pedBlip = MAP::GET_BLIP_FROM_ENTITY(ped());
		deleteBlipSafe(&pedBlip);
	}
}

void PedBehavior::fight(Ped enemy)
{
	// 117440512 unmount
	// 33554432 flee?
	PED::REGISTER_TARGET(ped(), enemy, 0);
	TASK::TASK_COMBAT_HATED_TARGETS_AROUND_PED(ped(), 100, 33554432, 16);
	//TASK::TASK_COMBAT_PED(ped(), enemy, 0, 16);
}

void PedBehavior::flee(Ped from)
{
	playAmbientSpeech(ped(), "SCARED_HELP");
	TASK::TASK_FLEE_PED(ped(), from, 3, 0, -999.0f, -1, 0);
	_isActive = false;
}
