#include "Main.h"

MapArea::MapArea(MapAreas areaId, const char* displayName, vector<Place*> places)
{
	id = areaId;
	lastEncounterTime = tm();
	this->displayName = displayName;
	this->places = places;
	this->gangName = NULL;
}

MapAreas MapArea::getAreaId()
{
	return id;
}

Vector3 MapArea::getTownCoords()
{
	return townCoords;
}

float MapArea::getTownRadius()
{
	return townRadius;
}

void MapArea::setTownCoords(Vector3 coords)
{
	townCoords = coords;
}

void MapArea::setTownRadius(float radius)
{
	townRadius = radius;
}

vector<pair<Vector3, float>>* MapArea::listTownLocations()
{
	return &(this->townLocations);
}

void MapArea::addTownLocation(Vector3 location, float heading)
{
	townLocations.push_back(make_pair(location, heading));
}

tm MapArea::getLastEncounterTime()
{
	return lastEncounterTime;
}

void MapArea::setLastEncounterTime(tm time)
{
	lastEncounterTime = time;
}

void MapArea::addRoadLocation(Vector3 location)
{
	roadLocations.push_back(location);
	addOffroadLocation(location);
}

vector<Vector3>* MapArea::listRoadLocations()
{
	return &(this->roadLocations);
}

Vector3 MapArea::getRandomRoadLocation()
{
	int index = rndInt(0, roadLocations.size());
	return roadLocations[index];
}

Vector3 MapArea::getClosestRoadLocation(Vector3 to)
{
	Vector3 best = roadLocations[0];
	float bestDistance = distance(best, to);

	for (vector<Vector3>::iterator itr = roadLocations.begin(); itr != roadLocations.end(); itr++)
	{
		float currDistance = distance((*itr), to);
		if (currDistance < bestDistance)
		{
			best = *itr;
			bestDistance = currDistance;
		}
	}

	return best;
}

pair<Vector3, float> MapArea::getClosestTownLocation(Vector3 to)
{
	pair<Vector3, float> best = townLocations[0];
	float bestDistance = distance(best.first, to);

	for (vector<pair<Vector3, float>>::iterator itr = townLocations.begin(); itr != townLocations.end(); itr++)
	{
		float currDistance = distance((*itr).first, to);
		if (currDistance < bestDistance)
		{
			best = *itr;
			bestDistance = currDistance;
		}
	}

	return best;
}

Vector3 MapArea::getRandomPostOfficeLocation()
{
	return postOfficeLocations.at(rndInt(0, postOfficeLocations.size()));
}

void MapArea::addPostOfficeLocation(Vector3 location)
{
	postOfficeLocations.push_back(location);
}

vector<Vector3>* MapArea::listPostOfficeLocations()
{
	return &postOfficeLocations;
}

Vector3 MapArea::getClosestPostOfficeTo(Vector3 location)
{
	if (!postOfficeLocations.size())
	{
		return toVector3(0, 0, 0);
	}

	Vector3 best = postOfficeLocations.at(0);
	float bestDistance = distance(best, location);
	for (vector<Vector3>::iterator itr = postOfficeLocations.begin(); itr != postOfficeLocations.end(); itr++)
	{
		Vector3 current = *itr;
		float currentDistance = distance(current, location);
		if (currentDistance < bestDistance)
		{
			best = current;
			bestDistance = currentDistance;
		}
	}

	return best;
}

Vector3 MapArea::randomLocationInTown()
{
	//Vector3 townLocation = questGiversLocations.at(rndInt(0, questGiversLocations.size())).first;
	//int radius = rndInt(0, 20);
	//return around(townLocation, radius, true);

	Vector3 townLocation = townLocations.at(rndInt(0, townLocations.size())).first;
	return townLocation;
}

void MapArea::addSaloonLocation(Vector3 location)
{
	saloonLocations.push_back(location);
}

Vector3 MapArea::getRandomSaloonLocation()
{
	if (!saloonLocations.size())
	{
		return toVector3(0, 0, 0);
	}

	return saloonLocations.at(rndInt(0, saloonLocations.size()));
}

void MapArea::addJailCellLocation(Vector3 location, float heading)
{
	jailCellLocations.push_back(make_pair(location, heading));
}

pair<Vector3, float> MapArea::getRandomJailCellLocation()
{
	return jailCellLocations.at(rndInt(0, jailCellLocations.size()));
}

const char* MapArea::getDisplayName()
{
	return displayName;
}

void MapArea::addWildernessCampingLocation(Vector3 location)
{
	wildrenessCampingLocations.push_back(location);
}

Vector3 MapArea::getRandomCampingLocation(bool allowGenerataion)
{
	return wildrenessCampingLocations[rndInt(0, wildrenessCampingLocations.size())];
}

Vector3 MapArea::getClosestCampingLocation(Vector3 to)
{
	if (!wildrenessCampingLocations.size())
	{
		return toVector3(0, 0, 0);
	}

	Vector3 best = wildrenessCampingLocations.at(0);
	float bestDistance = distance(best, to);
	for (vector<Vector3>::iterator itr = wildrenessCampingLocations.begin(); itr != wildrenessCampingLocations.end(); itr++)
	{
		Vector3 current = *itr;
		float currentDistance = distance(current, to);
		if (currentDistance < bestDistance)
		{
			best = current;
			bestDistance = currentDistance;
		}
	}

	return best;
}

vector<Vector3>* MapArea::listCampingLocations()
{
	return &wildrenessCampingLocations;
}

const char* MapArea::getRandomLocalGangPedModel()
{
	return localGangModels[rndInt(0, localGangModels.size())];
}

void MapArea::addLocalGangPedModel(const char* model)
{
	localGangModels.push_back(model);
}

const char* MapArea::getLocalGangName()
{
	return gangName;
}

void MapArea::setLocalGangName(const char* gangName)
{
	this->gangName = gangName;
}

void MapArea::addOffroadLocation(Vector3 location)
{
	offroadLocations.push_back(location);
}

Vector3 MapArea::getRandomOffroadLocation()
{
	int index = rndInt(0, offroadLocations.size());
	return offroadLocations[index];
}

Vector3 MapArea::getRandomOffroadLocation(Vector3 source, float minDistance)
{
	vector<Vector3> locations;

	for each (Vector3 loc in offroadLocations)
	{
		if (distance(source, loc) >= minDistance)
		{
			locations.push_back(loc);
		}
	}

	if (!locations.size()) 
	{
		return toVector3(0, 0, 0);
	}

	return VectorUtils::random(locations);
}

vector<Vector3>* MapArea::listOffroadLocations()
{
	return &offroadLocations;
}

Place* MapArea::getRandomPlaceByType(PlaceType type)
{
	vector<Place*> filtered;
	for (vector<Place*>::iterator itr = places.begin(); itr != places.end(); itr++)
	{
		Place* current = *itr;
		if (current->getPlaceType() == type)
		{
			filtered.push_back(current);
		}
	}

	if (filtered.empty())
	{
		return NULL;
	}

	return filtered.at(rndInt(0, filtered.size()));
}

vector<Place*> MapArea::listPlaces()
{
	return this->places;
}

Place* MapArea::getClosestPlaceTo(Vector3 coord)
{
	if (places.empty())
	{
		return NULL;
	}

	Place* best = places.at(0);
	float bestDistance = distance(coord, best->getCoords());

	for (vector<Place*>::iterator itr = places.begin(); itr != places.end(); itr++)
	{
		Place* current = *itr;
		float currentDistance = distance(current->getCoords(), coord);
		if (currentDistance < bestDistance)
		{
			best = current;
			bestDistance = currentDistance;
		}
	}

	return best;
}

Place* MapArea::getClosestPlaceOfType(PlaceType type, Vector3 coord)
{
	vector<Place*> places = listPlaces();
	vector<Place*> typePlaces(places.size());

	vector<Place*>::iterator it = copy_if(places.begin(), places.end(), typePlaces.begin(), [type](Place* place) { return place->getPlaceType() == type; });
	typePlaces.resize(std::distance(typePlaces.begin(), it));

	if (typePlaces.size() == 0)
	{
		return NULL;
	}

	nth_element(typePlaces.begin(), typePlaces.begin(), typePlaces.end(), [coord](Place* place1, Place* place2) { return distance(coord, place1->getCoords()) <= distance(coord, place2->getCoords()); });
	return typePlaces.at(0);
}

vector<Vector3> MapArea::listTrainTrackLocations()
{
	vector<Vector3> result;
	for (vector<pair<Vector3, bool>>::iterator itr = trainTrackLocations.begin(); itr != trainTrackLocations.end(); itr++)
	{
		result.push_back(itr->first);
	}

	return result;
}

void MapArea::addTrainTrackLocation(Vector3 trainTrackLocation, bool flip)
{
	trainTrackLocations.push_back(pair<Vector3, bool>(trainTrackLocation, flip));
}

pair<Vector3, bool> MapArea::getRandomTrainTrackLocation()
{
	if (!trainTrackLocations.size())
	{
		return pair<Vector3, bool>(toVector3(0, 0, 0), false);
	}

	return trainTrackLocations.at(rndInt(0, trainTrackLocations.size()));
}

pair<Vector3, bool> MapArea::getClosestTrainTrackTo(Vector3 location, float minDistance)
{
	if (!trainTrackLocations.size())
	{
		return pair<Vector3, bool>(toVector3(0, 0, 0), false);
	}

	Vector3 best = toVector3(0, 0, 0);
	bool bestFlip = false;
	float bestDistance = 99999;

	for (vector<pair<Vector3, bool>>::iterator itr = trainTrackLocations.begin(); itr != trainTrackLocations.end(); itr++)
	{
		pair<Vector3, bool> curr = *itr;
		float currDistance = distance(curr.first, location);
		if (currDistance < bestDistance && currDistance >= minDistance)
		{
			best = curr.first;
			bestFlip = curr.second;
			bestDistance = currDistance;
		}
	}

	return pair<Vector3, bool>(best, bestFlip);
}

Vehicle MapArea::createTrainHeadingTowardsLocation(TrainConfiguration trainConfig, Vector3 location)
{
	pair<Vector3, bool> locationTracks = getClosestTrainTrackTo(location);
	pair<Vector3, bool> spawn = getClosestTrainTrackTo(locationTracks.first, 10);	
	bool direction = locationTracks.first.x < spawn.first.x;
	if (spawn.second) 
	{
		direction = !direction;
	}

	Vehicle train = createTrain(TrainConfiguration::Passangers, spawn.first, direction);
	return train;
}

void MapArea::addSniperLocation(Position loc)
{
	this->sniperLocations.push_back(loc);
}

Position MapArea::getRandonSniperLocation()
{
	return sniperLocations.at(rndInt(0, sniperLocations.size()));
}