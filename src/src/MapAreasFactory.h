#pragma once

#include "PostOfficesFactory.h"

class MapAreasFactory
{
private:
	map<MapAreas, MapArea*> cache;
	map<int, const char*> areaNames;
	PlacesFactory* placesFactory;

public:
	PostOfficesFactory* postOffices;

public:
	MapAreasFactory(PlacesFactory* placesFactory, PostOfficesFactory* postOffices);
	MapArea* getMapArea(MapAreas mapArea);
	MapArea* getClosestTown(Vector3 location);
	vector<MapArea*> listMapAreas();
	const char* getAreaName(int zoneId);

private:
	MapArea* createBlackwater();
	MapArea* createRhodes();
	MapArea* createValentine();
	MapArea* createStrawberry();
	MapArea* createTumbleweed();
	MapArea* createArmadillo();
	MapArea* createSaintDenis();
	MapArea* createAnnesburg();
};