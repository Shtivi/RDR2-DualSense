#include "Main.h"

Entity getPlayerTargetEntity()
{
	Entity targetEntity;
	if (PLAYER::GET_PLAYER_TARGET_ENTITY(PLAYER::PLAYER_ID(), &targetEntity))
	{
		return targetEntity;
	}

	return NULL;
}

MapAreas getPlayerMapArea()
{
	return getMapArea(player);
}

bool isPlayerUsingCampfire()
{
	// fire camp: 1020517461
	// fire camp: -1767895052
	// fire camp: 1984305068
	// tent: -2016812721

	int playerScenarioPointType = (int)TASK::_GET_SCENARIO_POINT_TYPE_PED_IS_USING(player);
	return playerScenarioPointType == -1767895052 || playerScenarioPointType == 1020517461 || playerScenarioPointType == 1984305068;
}

bool isPlayerResting()
{
	// fire camp: 1020517461
	// fire camp: -1767895052
	// fire camp: 1984305068
	// resting: -1241981548

	int playerScenarioPointType = (int)TASK::_GET_SCENARIO_POINT_TYPE_PED_IS_USING(player);
	return playerScenarioPointType == -1241981548;
}

void setPlayerCoreValue(AttributeCores core, int value)
{
	ATTRIBUTE::_SET_ATTRIBUTE_CORE_VALUE(player, (int)core, value);
}

int getPlayerCoreValue(AttributeCores core)
{
	return ATTRIBUTE::_GET_ATTRIBUTE_CORE_VALUE(player, (int)core);
}

void addToPlayerCore(AttributeCores core, int amount)
{
	setPlayerCoreValue(core, getPlayerCoreValue(core) + amount);
}

Ped getPlayerSaddleHorse()
{
	return PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(PLAYER::PLAYER_ID());
}