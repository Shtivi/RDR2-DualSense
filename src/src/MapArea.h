#pragma once

class MapArea
{
private:
	MapAreas id;
	Vector3 townCoords;
	float townRadius;
	tm lastEncounterTime;
	const char* displayName;
	const char* gangName;

	vector<pair<Vector3, float>> townLocations;
	vector<Vector3> roadLocations;
	vector<Vector3> saloonLocations;
	vector<Vector3> postOfficeLocations;
	vector<pair<Vector3, float>> jailCellLocations;
	vector<Vector3> wildrenessCampingLocations;
	vector<Vector3> offroadLocations;
	vector<const char*> localGangModels;
	vector<Place*> places;
	vector<pair<Vector3, bool>> trainTrackLocations;
	vector<Position> sniperLocations;

public:
	MapArea(MapAreas areaId, const char* displayName, vector<Place*> places);
	
	MapAreas getAreaId();
	Vector3 getTownCoords();
	float getTownRadius();
	void setTownCoords(Vector3 coords);
	void setTownRadius(float radius);
	const char* getDisplayName();

	tm getLastEncounterTime();
	void setLastEncounterTime(tm time);

	vector<pair<Vector3, float>>* listTownLocations();
	pair<Vector3, float> getClosestTownLocation(Vector3 to);
	void addTownLocation(Vector3 location, float heading);

	vector<Vector3>* listRoadLocations();
	Vector3 getRandomRoadLocation();
	Vector3 getClosestRoadLocation(Vector3 to);
	void addRoadLocation(Vector3 location);

	Vector3 getRandomPostOfficeLocation();
	void addPostOfficeLocation(Vector3 location);
	Vector3 getClosestPostOfficeTo(Vector3 location);
	vector<Vector3>* listPostOfficeLocations();

	Vector3 randomLocationInTown();
	void addSaloonLocation(Vector3 interiorLocation);
	Vector3 getRandomSaloonLocation();

	void addJailCellLocation(Vector3 location, float heading);
	pair<Vector3, float> getRandomJailCellLocation();

	void addWildernessCampingLocation(Vector3 location);
	Vector3 getRandomCampingLocation(bool allowGenerataion = false);
	Vector3 getClosestCampingLocation(Vector3 to);
	vector<Vector3>* listCampingLocations();

	void addOffroadLocation(Vector3 location);
	Vector3 getRandomOffroadLocation();
	Vector3 getRandomOffroadLocation(Vector3 source, float minDistance);
	vector<Vector3>* listOffroadLocations();

	const char* getRandomLocalGangPedModel();
	void addLocalGangPedModel(const char* model);
	const char* getLocalGangName();
	void setLocalGangName(const char* gangName);

	Place* getRandomPlaceByType(PlaceType type);
	vector<Place*> listPlaces();
	Place* getClosestPlaceTo(Vector3 coord);
	Place* getClosestPlaceOfType(PlaceType type, Vector3 coord);

	vector<Vector3> listTrainTrackLocations();
	void addTrainTrackLocation(Vector3 trainTrackLocation, bool flipDirection);
	pair<Vector3, bool> getRandomTrainTrackLocation();
	pair<Vector3, bool> getClosestTrainTrackTo(Vector3 location, float minDistance = 0);
	Vehicle createTrainHeadingTowardsLocation(TrainConfiguration trainConfig, Vector3 location);

	void addSniperLocation(Position loc);
	Position getRandonSniperLocation();
};

#include "MapAreasFactory.h"