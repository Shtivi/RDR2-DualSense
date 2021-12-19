#include "Main.h"

ScenarioPoint::ScenarioPoint(Entity entity, const char* scenario, Vector3 offset, float heading)
{
	this->id = 0;
	this->entity = entity;
	this->location = toVector3(0, 0, 0);
	this->scenario = scenario;
	this->offset = offset;
	this->heading = heading;
}

ScenarioPoint::ScenarioPoint(Vector3 location, const char* scenario, float heading)
{
	this->id = 0;
	this->location = location;
	this->scenario = scenario;
	this->heading = heading;
	this->entity = NULL;
	this->offset = toVector3(0,0,0);
}

int ScenarioPoint::getId()
{
	return id;
}

Entity ScenarioPoint::getEntity()
{
	return entity;
}

Vector3 ScenarioPoint::getLocation()
{
	if (isAttachedToEntity())
	{
		return entityPos(entity);
	}
	else
	{
		return location;
	}
}

bool ScenarioPoint::isAttachedToEntity()
{
	return entity != NULL;
}

Vector3 ScenarioPoint::getOffset()
{
	return offset;
}

float ScenarioPoint::getHeading()
{
	return heading;
}

bool ScenarioPoint::isExist()
{
	return getId() != 0 && TASK::DOES_SCENARIO_POINT_EXIST(getId());
}

int ScenarioPoint::getScenarioHashKey()
{
	return MISC::GET_HASH_KEY((char*)scenario);
}

int ScenarioPoint::create()
{
	if (entity)
	{
		id = TASK::CREATE_SCENARIO_POINT_HASH_ATTACHED_TO_ENTITY(entity, getScenarioHashKey(), offset.x, offset.y, offset.z, heading, 0, -1, 1);
	}
	else
	{
		id = TASK::CREATE_SCENARIO_POINT_HASH(getScenarioHashKey(), location.x, location.y, location.z, heading, -77412868, -1, 1);
	}

	TASK::_SET_SCENARIO_POINT_COORDS(id, location.x, location.y, location.z, 1);
	TASK::_SET_SCENARIO_POINT_HEADING(id, heading, 1);

	return id;
}