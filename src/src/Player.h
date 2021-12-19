#pragma once

enum class AttributeCores : int
{
	Heatlh,
	Stamina,
	Deadeye
};

Entity getPlayerTargetEntity();
MapAreas getPlayerMapArea();
bool isPlayerUsingCampfire();
bool isPlayerResting();
void setPlayerCoreValue(AttributeCores core, int value);
int getPlayerCoreValue(AttributeCores core);
void addToPlayerCore(AttributeCores core, int amount);
Ped getPlayerSaddleHorse();