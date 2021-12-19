#pragma once

enum class PlaceType : int 
{
	Shack,
	Ranch,
	GangHideout,
	CaligaHall,
	BraithwaiteManor,
	Mine,
	Mansion,
	HotelRoom,
	Graveyard,
	Other
};

class Place {
protected:
	int id;
	MapAreas area;
	Vector3 coords;
	float radius;
	PlaceType type;
	const char* typicalPedModel;
	vector<ScenarioPoint> scenarioPoints;
	const char* displayName;

public:
	Place(int id, MapAreas areaId, Vector3 coords, float radius, PlaceType type, const char* displayName);
	Place(Vector3 coords, float radius);

	int getId();
	MapAreas getAreaId();
	Vector3 getCoords();
	float getRadius();
	PlaceType getPlaceType();
	const char* getTypicalPedModel();
	void setTypicalPedModel(const char* model);
	const char* getDisplayName();

	int getClosestScenarioPointId(Vector3 location);
	vector<Vector3> listScenarioPointLocations();
	vector<int> listScenarioPointIds();
	vector<ScenarioPoint> listScenarioPoints();
	ScenarioPoint getRandomScenarioPoint();
	Place* addScenarioPoint(ScenarioPoint scenarioPoint);
	Place* addScenarioPoint(Entity entity, const char* scenario, Vector3 offset, float heading);
	Place* addScenarioPoint(Vector3 location, const char* scenario, float heading);
	Place* addScenarioPoint(Vector3 estimatedLocation, int searchRadius, int entityModel, const char* scenario, Vector3 offset, float heading);

	virtual void populate();
	virtual void cleanup();
};

#include "PlacesFactory.h"