#include "Main.h"

Place::Place(int id, MapAreas areaId, Vector3 coords, float radius, PlaceType type, const char* displayName)
{
	this->id = id;
	this->area = areaId;
	this->radius = radius;
	this->coords = coords;
	this->typicalPedModel = NULL;
	this->type = type;
	this->displayName = displayName;
}

Place::Place(Vector3 coords, float radius)
	: Place(0, (MapAreas)0, coords, radius, PlaceType::Other, "")
{
}

int Place::getId()
{
	return id;
}

MapAreas Place::getAreaId()
{
	return area;
}

Vector3 Place::getCoords()
{
	return coords;
}

float Place::getRadius()
{
	return radius;
}

PlaceType Place::getPlaceType()
{
	return type;
}

const char* Place::getTypicalPedModel()
{
	return typicalPedModel;
}

const char* Place::getDisplayName()
{
	return displayName;
}

void Place::setTypicalPedModel(const char* model)
{
	typicalPedModel = model;
}

Place* Place::addScenarioPoint(ScenarioPoint scenarioPoint)
{
	scenarioPoints.push_back(scenarioPoint);
	return this;
}

void Place::populate()
{
	for (vector<ScenarioPoint>::iterator current = scenarioPoints.begin(); current != scenarioPoints.end(); current++)
	{
		current->create();
	}
}


void Place::cleanup()
{
	for each (ScenarioPoint scenarioPoint in scenarioPoints)
	{
		if (scenarioPoint.isExist())
		{
			TASK::_DELETE_SCENARIO_POINT(scenarioPoint.getId());
		}
	}
}

int Place::getClosestScenarioPointId(Vector3 location)
{
	if (!scenarioPoints.size())
	{
		return 0;
	}

	ScenarioPoint* best = &scenarioPoints.at(0);
	float bestDistance = distance(location, best->getLocation());

	for (vector<ScenarioPoint>::iterator current = scenarioPoints.begin(); current != scenarioPoints.end(); current++)
	{
		float currentDistance = distance(current->getLocation(), location);
		if (currentDistance < bestDistance)
		{
			best = &(*current);
			bestDistance = currentDistance;
		}
	}

	return best->getId();
}

vector<Vector3> Place::listScenarioPointLocations()
{
	vector<Vector3> list;
	for (vector<ScenarioPoint>::iterator current = scenarioPoints.begin(); current != scenarioPoints.end(); current++)
	{
		list.push_back(current->getLocation());
	}
	return list;
}

vector<int> Place::listScenarioPointIds()
{
	vector<int> list;
	for (vector<ScenarioPoint>::iterator current = scenarioPoints.begin(); current != scenarioPoints.end(); current++)
	{
		list.push_back(current->getId());
	}
	return list;
}

vector<ScenarioPoint> Place::listScenarioPoints()
{
	return vector<ScenarioPoint>(scenarioPoints);
}

ScenarioPoint Place::getRandomScenarioPoint()
{
	return scenarioPoints.at(rndInt(0, scenarioPoints.size()));
}

Place* Place::addScenarioPoint(Entity entity, const char* scenario, Vector3 offset, float heading)
{
	addScenarioPoint(ScenarioPoint(entity, scenario, offset, heading));
	return this;
}

Place* Place::addScenarioPoint(Vector3 location, const char* scenario, float heading)
{
	addScenarioPoint(ScenarioPoint(location, scenario, heading));
	return this;
}

Place* Place::addScenarioPoint(Vector3 estimatedLocation, int searchRadius, int entityModel, const char* scenario, Vector3 offset, float heading)
{
	Object entity = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(estimatedLocation.x, estimatedLocation.y, estimatedLocation.z, searchRadius, entityModel, 0, 0, 0);
	if (entity)
	{
		addScenarioPoint(entity, scenario, offset, heading);
	}
	return this;
}
