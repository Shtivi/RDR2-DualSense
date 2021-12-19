#include "Main.h";
#include <random>

using namespace std;

vector<const char*> TRAIN_MODELS = {
	"cart01",
	"cart02",
	"cart03",
	"cart04",
	"cart05",
	"cart06",
	"cart07",
	"cart08",
	"trolley01x",
	"handcart",
	"steamerDummy",
	"privatebaggage01x",
	"privateboxcar01x",
	"privateboxcar02x",
	"privateboxcar04x",
	"privatecoalcar01x",
	"privatedining01x",
	"privateflatcar01x",
	"privateObservationcar",
	"privateopensleeper01x",
	"privateopensleeper02x",
	"privatepassenger01x",
	"privaterooms01x",
	"privatesteamer01x",
	"northcoalcar01x",
	"northflatcar01x",
	"northpassenger01x",
	"northpassenger03x",
	"northsteamer01x",
	"wintercoalcar",
	"winterSteamer"
};

bool loadModel(Hash model, int timeout = 3000)
{
	while (!STREAMING::HAS_MODEL_LOADED(model) && timeout > 0)
	{
		STREAMING::REQUEST_MODEL(model, false);
		timeout -= 10;
		WAIT(10);
	}

	return STREAMING::HAS_MODEL_LOADED(model);
}

Vehicle createVehicle(char* modelName, Vector3 pos, float heading)
{
	Hash model = MISC::GET_HASH_KEY(modelName);
	return createVehicle(model, pos, heading);;
}

Vehicle createVehicle(VehicleHash vehicleHash, Vector3 position, float heading)
{
	return createVehicle((Hash)vehicleHash, position, heading);
}

Vehicle createVehicle(Hash model, Vector3 pos, float heading)
{
	Vehicle veh;

	if (!loadModel(model))
	{
		return NULL;
	}

	veh = VEHICLE::CREATE_VEHICLE(model, pos.x, pos.y, pos.z, heading, true, true, false, false);
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh, 0);

	return veh;
}

Vehicle createVehicleOnClosestRoad(VehicleHash model, Vector3 aroundLocation, bool flipDirection)
{
	Vector3 out;
	float heading;
	if (PATHFIND::GET_CLOSEST_VEHICLE_NODE_WITH_HEADING(aroundLocation.x, aroundLocation.y, aroundLocation.z, &out, &heading, 1, 3, 0))
	{
		return createVehicle(model, out, flipDirection ? 360 - heading : heading);
	}

	return NULL;
}


void placeVehicleOnClosestRoad(Vehicle vehicle, Vector3 around, bool flipDirection )
{
	Vector3 out;
	float heading;
	if (PATHFIND::GET_CLOSEST_VEHICLE_NODE_WITH_HEADING(around.x, around.y, around.z, &out, &heading, 1, 3, 0))
	{
		ENTITY::SET_ENTITY_COORDS(vehicle, out.x, out.y, out.z, 1, 1, 1, 1);
		ENTITY::SET_ENTITY_HEADING(vehicle, flipDirection ? 60 - heading : heading);
	}
}

Vector3 getClosestRoad(Vector3 source, float radius)
{
	Vector3 out;
	Vector3 best = toVector3(0,0,0);

	Vector3 directions[] = {
		toVector3(1,0,0),
		toVector3(-1,0,0),
		toVector3(0,1,0),
		toVector3(0,-1,0)
	};

	if (PATHFIND::GET_CLOSEST_VEHICLE_NODE(source.x, source.y, source.z, &out, 1, 3, 0))
	{
		return out;
	}

	for (int i = 0; i < 4; i++)
	{
		int dist = 10;
		Vector3 aroundLocation = Vector3(source + directions[i] * dist);
		while (!PATHFIND::GET_CLOSEST_VEHICLE_NODE(aroundLocation.x, aroundLocation.y, aroundLocation.z, &out, 1, 3, 0) && dist < radius)
		{
			dist += 10;
			aroundLocation = Vector3(source + directions[i] * dist);
		}

		if (distance(source, best) > distance(source, out))
		{
			best = Vector3(out);
		}
	}

	return best;
}

void setVehicleCargo(Vehicle vehicle, VehicleCargoHash cargoHash)
{
	PROPSET::_0xD80FAF919A2E56EA(vehicle, cargoHash);
}

Ped getPedVehicleOccupant(Ped ped, int seat)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(ped, true))
	{
		Vehicle pedVehicle = PED::GET_VEHICLE_PED_IS_IN(ped, 0);
		if (VEHICLE::IS_VEHICLE_SEAT_FREE(pedVehicle, seat))
		{
			return NULL;
		}
		return VEHICLE::GET_PED_IN_VEHICLE_SEAT(pedVehicle, seat);
	}
	else 
	{
		return NULL;
	}
}

Ped getPedVehicleDriverOrShotgun(Ped ped)
{
	Ped shotgun = getPedVehicleOccupant(ped, 0);
	if (!shotgun)
	{
		return getPedVehicleOccupant(ped, -1);
	}
}

bool isPedDriverOrShotgun(Ped ped)
{
	if (ENTITY::IS_ENTITY_DEAD(ped))
	{
		return false;
	}

	if (PED::IS_PED_IN_ANY_VEHICLE(ped, false))
	{
		Vehicle pedVehicle = PED::GET_VEHICLE_PED_IS_IN(ped, 0);
		return VEHICLE::GET_PED_IN_VEHICLE_SEAT(pedVehicle, 0) == ped || VEHICLE::GET_PED_IN_VEHICLE_SEAT(pedVehicle, -1) == ped;
	}
	else if (PED::IS_PED_ON_MOUNT(ped))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Vehicle createTrain(TrainConfiguration trainConfigration, Vector3 location, bool direction, bool withPeds)
{
	bool areModelsLoading = false;
	for (const char* model : TRAIN_MODELS)
	{
		int modelHash = MISC::GET_HASH_KEY((char*)model);
		if (!STREAMING::HAS_MODEL_LOADED(modelHash))
		{
			areModelsLoading = true;
		}
		STREAMING::REQUEST_MODEL(modelHash, false);
	}	
	
	int iterations = 20;
	while (areModelsLoading && iterations--)
	{
		WAIT(250);
		areModelsLoading = false;
		for (const char* model : TRAIN_MODELS)
		{
			int modelHash = MISC::GET_HASH_KEY((char*)model);
			if (!STREAMING::HAS_MODEL_LOADED(modelHash))
			{
				areModelsLoading = true;
			}
		}
		iterations--;
	}

	if (areModelsLoading)
	{
		log("failed to load all models");
		for (const char* model : TRAIN_MODELS)
		{
			int modelHash = MISC::GET_HASH_KEY((char*)model);
			if (!STREAMING::HAS_MODEL_LOADED(modelHash))
			{
				log(model);
			}
		}
	}

	Vector3 spawnLocation = getClosestTrainTracks(location);
	Vehicle train = VEHICLE::_CREATE_MISSION_TRAIN((int)trainConfigration, spawnLocation.x, spawnLocation.y, spawnLocation.z, direction, withPeds, 0, 0);
	VEHICLE::SET_MISSION_TRAIN_COORDS(train, location.x, location.y, location.z);
	return train;
}

int countTrainCarriages(Vehicle train)
{
	int count = 0;
	Entity carriage = VEHICLE::GET_TRAIN_CARRIAGE(train, count);
	while (carriage && count < 100)
	{
		count++;
		carriage = VEHICLE::GET_TRAIN_CARRIAGE(train, count);
	}

	return count;
}

bool isEntityOnTrainTracks(Entity entity)
{
	return ENTITY::_IS_ENTITY_ON_TRAIN_TRACK(entity);
}

void setTrainCoords(Entity train, Vector3 coords)
{
	VEHICLE::SET_MISSION_TRAIN_COORDS(train, coords.x, coords.y, coords.z);
}

Vector3 getClosestTrainTracks(Vector3 location)
{
	return VEHICLE::_GET_NEAREST_TRAIN_TRACK_POSITION(location.x, location.y, location.z);
}

Ped getRandomPedInTrain(Vehicle train, int ignoreCarriage)
{
	int carriagesCount = countTrainCarriages(train);
	vector<int> carriages = VectorUtils::numbers(carriagesCount);
	shuffle(carriages.begin(), carriages.end(), default_random_engine(MISC::GET_RANDOM_INT_IN_RANGE(0, 100)));

	Ped candidate = NULL;
	for (vector<int>::iterator itr = carriages.begin(); itr != carriages.end() && !candidate; itr++)
	{
		int currentCarriage = *itr;
		if (currentCarriage == ignoreCarriage)
		{
			continue;
		}

		Entity carriage = VEHICLE::GET_TRAIN_CARRIAGE(train, currentCarriage);
		
		candidate = getClosestPed(entityPos(carriage), 10);
		if (!candidate || !PED::IS_PED_IN_ANY_TRAIN(candidate))
		{
			candidate = NULL;
		}
		
		if (candidate)
		{
			log(string("random train ped was found on carriage number: ").append(to_string(currentCarriage)).c_str());
		}
	}

	return candidate;
}

int getClosestTrainCarriage(Vehicle train, Vector3 location)
{
	int count = 0;
	int best = -1;
	int bestDistance = 9999;
	Entity carriage = VEHICLE::GET_TRAIN_CARRIAGE(train, 0);
	while (carriage && count < 100)
	{
		carriage = VEHICLE::GET_TRAIN_CARRIAGE(train, count);
		float carriageDistance = distance(location, entityPos(carriage));
		if (carriageDistance < bestDistance)
		{
			best = count;
			bestDistance = carriageDistance;
		}

		count++;
	}

	return best;
}

int getClosestTrainCarriage(Vehicle train, Entity entity)
{
	return getClosestTrainCarriage(train, entityPos(entity));
}