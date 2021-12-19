#include "Main.h";

vector<const char*> AMBIENT_HORSE_MODELS = {
	"a_c_horse_kentuckysaddle_black",
	"a_c_horse_kentuckysaddle_buttermilkbuckskin_pc",
	"a_c_horse_kentuckysaddle_chestnutpinto",
	"a_c_horse_kentuckysaddle_grey",
	"a_c_horse_kentuckysaddle_silverbay",
	"a_c_horse_morgan_bay",
	"a_c_horse_morgan_bayroan",
	"a_c_horse_morgan_flaxenchestnut",
	"a_c_horse_morgan_liverchestnut_pc",
	"a_c_horse_morgan_palomino",
	"a_c_horse_americanpaint_greyovero",
	"a_c_horse_americanpaint_overo",
	"a_c_horse_americanpaint_splashedwhite",
	"a_c_horse_americanpaint_tobiano",
	"a_c_horse_americanstandardbred_black",
	"a_c_horse_americanstandardbred_buckskin",
	"a_c_horse_americanstandardbred_lightbuckskin",
	"a_c_horse_americanstandardbred_palominodapple",
	"a_c_horse_americanstandardbred_silvertailbuckskin"
};

struct SpeechArgs
{
	alignas(8) char* speechName;
	alignas(8) char* voiceName;
	alignas(8) int unk1;
	alignas(8) int unk2;
	alignas(8) int ped;
	alignas(8) int unk3;
	alignas(8) int unk4;
};

Ped createHorse(char* model, Vector3 pos, HorseSaddleHashes saddleType)
{
	Ped horse = createPed(model, pos);
	giveSaddleToHorse(horse, saddleType);
	return horse;
}

Ped createAmbientHorse(Vector3 pos)
{
	const char* model = AMBIENT_HORSE_MODELS.at(rndInt(0, AMBIENT_HORSE_MODELS.size()));
	return createHorse((char*)model, pos);
}

Ped createPed(char* modelName, Vector3 pos, float heading)
{
	Hash model = MISC::GET_HASH_KEY(modelName);
	STREAMING::REQUEST_MODEL(model, false);
	while (!STREAMING::HAS_MODEL_LOADED(model))
	{
		WAIT(0);
	}

	Ped ped = PED::CREATE_PED(model, pos.x, pos.y, pos.z, heading, false, false, false, false);
	PED::_SET_RANDOM_OUTFIT_VARIATION(ped, true);

	return ped;
}

Ped createPedOnHorse(char* modelName, Ped horse, int seatIndex)
{
	Hash model = MISC::GET_HASH_KEY(modelName);
	STREAMING::REQUEST_MODEL(model, false);
	while (!STREAMING::HAS_MODEL_LOADED(model))
	{
		STREAMING::REQUEST_MODEL(model, false);
		WAIT(10);
	}

	Ped ped = PED::CREATE_PED_ON_MOUNT(horse, model, seatIndex, 1, 1, 0, 0);

	PED::_SET_RANDOM_OUTFIT_VARIATION(ped, true);
	return ped;
}

bool isPedHogtied(Ped ped)
{
	return TASK::GET_IS_TASK_ACTIVE(ped, 400);
}

void playAmbientSpeech(Ped ped, char* speechName, char* voice)
{
	SpeechArgs args;
	args.speechName = speechName;
	args.voiceName = voice;
	args.unk1 = 1;
	args.unk2 = 1744022339;
	args.unk3 = 1;
	args.unk4 = 1;
	args.ped = ped;

	invoke<BOOL>(0x8E04FEDD28D42462, ped, &args);
}

void giveSaddleToHorse(Ped horse, HorseSaddleHashes saddleHash)
{
	PED::_APPLY_SHOP_ITEM_TO_PED(horse, saddleHash, true, false, false);
}

vector<Ped>* getPedGroupMembers(Group group)
{
	if (!PED::DOES_GROUP_EXIST(group))
	{
		return NULL;
	}
	else
	{
		vector<Ped>* results = new vector<Ped>;
		int count, val1;
		PED::GET_GROUP_SIZE(group, &val1, &count);

		for (int i = 0; i < count; i++)
		{
			Ped current = PED::GET_PED_AS_GROUP_MEMBER(group, i);
			if (ENTITY::DOES_ENTITY_EXIST(current) && !ENTITY::IS_ENTITY_DEAD(current))
			{
				results->push_back(current);
			}
		}

		Ped leader = PED::GET_PED_AS_GROUP_LEADER(group);
		if (ENTITY::DOES_ENTITY_EXIST(leader))
		{
			results->push_back(leader);
		}
	}
}

vector<Ped> getNearbyPeds(Ped origin, int limit)
{
	return getNearbyPeds(origin, limit, -1);
}

vector<Ped> getNearbyPeds(Ped origin, int limit, float radius, int ignoredPedType, bool filterDead)
{
	int arrSize = limit * 2 + 2;
	int total;
	Ped results[256];
	vector<Ped> asVector;

	results[0] = limit;
	total = PED::GET_PED_NEARBY_PEDS(origin, (Any*)results, ignoredPedType, -1);

	for (int i = 0; i < total; i++)
	{
		int offset = i * 2 + 2;
		Ped current = results[offset];
		if (ENTITY::DOES_ENTITY_EXIST(current))
		{
			if (ENTITY::IS_ENTITY_DEAD(current) && filterDead)
			{
				continue;
			}

			if (radius == -1 || distanceBetweenEntities(origin, current) <= radius)
			{
				asVector.push_back(current);
			}
		}
	}

	return asVector;
}

vector<Ped> getNearbyDeadBodies(Ped origin, int limit, float radius)
{
	vector<Ped> results = getNearbyPeds(origin, limit, radius, -1, false);
	vector<Ped>::iterator itr = results.begin();
	while (itr != results.end())
	{
		Ped current = *itr;
		if (!PED::IS_PED_HUMAN(current) || !ENTITY::IS_ENTITY_DEAD(current))
		{
			itr = results.erase(itr);
		}
		else
		{
			itr++;
		}
	}

	return results;
}

bool hasPedClearLosInFront(Ped ped, Entity toEntity, float maxDistance)
{
	return distanceBetweenEntities(ped, toEntity) <= maxDistance && ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT(ped, toEntity, 1);
}


Object findUnoccupiedObjectAround(Vector3 location, float maxDistance, int objectHash, float occupationRadius)
{
	Object obj = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(location.x, location.y, location.z, 10, objectHash, 0, 0, 0);
	if (!obj)
	{
		return NULL;
	}

	Vector3 objPos = entityPos(obj);
	Ped closestPed = getClosestPed(objPos, occupationRadius);
	if (closestPed)
	{
		return NULL;
	}

	return obj;
}

Object findUnoccupiedObjectAround(Vector3 location, float maxDistance, vector<int> objectHashes, float occupationRadius)
{
	for (vector<int>::iterator itr = objectHashes.begin(); itr != objectHashes.end(); itr++)
	{
		Object result = findUnoccupiedObjectAround(location, maxDistance, *itr, occupationRadius);
		if (result)
		{
			return result;
		}
	}

	return NULL;
}

void playSeatedScenario(Ped ped, Object object, const char* scenarioType, float heading)
{
	Vector3 objectPos = entityPos(object);
	int scenarioPoint = TASK::CREATE_SCENARIO_POINT_HASH_ATTACHED_TO_ENTITY(object, MISC::GET_HASH_KEY((char*)scenarioType), 0, 0, 0.5f, heading, 0, -1, 1); // TASK_CREATE_SCENARIO_POINT_ATTACHED_TO_ENTITY
	TASK::_SET_SCENARIO_POINT_FLAG(scenarioPoint, 23, 1);
	PED::ADD_SCENARIO_BLOCKING_AREA(objectPos.x - 0.75, objectPos.y - 0.75, objectPos.z - 0.75, objectPos.x + 0.75, objectPos.y + 0.75, objectPos.z + 0.75, false, 15);
	TASK::TASK_USE_SCENARIO_POINT(ped, scenarioPoint, 0, -1, 0, 1, 0, 0, -1082130432, 0);
}

int findUnoccupiedScenarioPointAround(Vector3 source, float radius)
{
	int arrSize = 15;
	int scenarios[100];
	int count = TASK::GET_SCENARIO_POINTS_IN_AREA(source.x, source.y, source.z, radius, (Any*)scenarios, arrSize);
	
	if (!count) {
		return -1;
	}

	int best = -1;
	float bestDistance = 99999;
	for (int i = 0; i < count; i++)
	{
		int scenario = scenarios[i];
		if (!TASK::DOES_SCENARIO_POINT_EXIST(scenario))
		{
			continue;
		}

		Ped pedUsingScenario = TASK::_GET_PED_USING_SCENARIO_POINT(scenario);
		if (pedUsingScenario)
		{
			continue;
		}

		Vector3 scenarioCoords = TASK::_GET_SCENARIO_POINT_COORDS(scenario, 1);
		float scenarioDistance = distance(scenarioCoords, source);
		if (scenarioDistance < bestDistance)
		{
			best = scenario;
			bestDistance = scenarioDistance;
		}
	}

	return best;
}

bool isPedCop(Ped ped)
{
	return PED::GET_PED_RELATIONSHIP_GROUP_HASH(ped) == MISC::GET_HASH_KEY("REL_COP");
}

bool isPedLawman(Ped ped)
{
	int pedRelationshipGroup = PED::GET_PED_RELATIONSHIP_GROUP_HASH(ped);
	return 
		isPedCop(ped) || 
		pedRelationshipGroup == -886193798 /* Bounty hunters */;
}

Ped createPed(const char* modelName, Vector3 pos)
{
	Hash model = MISC::GET_HASH_KEY((char*)modelName);
	STREAMING::REQUEST_MODEL(model, false);
	while (!STREAMING::HAS_MODEL_LOADED(model))
	{
		WAIT(0);
	}

	Ped ped = PED::CREATE_PED(model, pos.x, pos.y, pos.z, 0, false, false, false, false);
	PED::_SET_RANDOM_OUTFIT_VARIATION(ped, true);

	return ped;
}

Ped createPed(int model, Vector3 pos)
{
	STREAMING::REQUEST_MODEL(model, false);
	while (!STREAMING::HAS_MODEL_LOADED(model))
	{
		WAIT(0);
	}

	Ped ped = PED::CREATE_PED(model, pos.x, pos.y, pos.z, 0, false, false, false, false);
	PED::_SET_RANDOM_OUTFIT_VARIATION(ped, true);

	return ped;
}


Ped createPed(const char* modelName, Vehicle vehicle, int seatIndex)
{
	Hash model = MISC::GET_HASH_KEY((char*)modelName);
	STREAMING::REQUEST_MODEL(model, false);
	while (!STREAMING::HAS_MODEL_LOADED(model))
	{
		WAIT(0);
	}

	Ped ped = PED::CREATE_PED_INSIDE_VEHICLE(vehicle, model, seatIndex, 0, 0, 0);
	PED::_SET_RANDOM_OUTFIT_VARIATION(ped, true);
	return ped;
}

Ped findCarriedPedBy(Ped carrier)
{
	return PED::_GET_FIRST_ENTITY_PED_IS_CARRYING(carrier);
}

void playAnimation(Ped ped, const char* animName, const char* animDict, int duration, float blendInSpeed, float blendOutSpeed, int flags)
{
	if (!STREAMING::DOES_ANIM_DICT_EXIST(animDict))
	{
		log(string("anim dict does not exist: ").append(animDict));
		return;
	}

	if (!STREAMING::HAS_ANIM_DICT_LOADED((char*)animDict))
	{
		STREAMING::REQUEST_ANIM_DICT((char*)animDict);
	}

	Stopwatch stopwatch;
	stopwatch.start();
	while (!STREAMING::HAS_ANIM_DICT_LOADED((char*)animDict) && stopwatch.getElapsedSeconds() <= 1)
	{
		STREAMING::REQUEST_ANIM_DICT((char*)animDict);
		WAIT(25);
	}

	TASK::TASK_PLAY_ANIM(ped, (char*)animDict, (char*)animName, blendInSpeed, blendOutSpeed, duration, flags, 0, 0, 0, 0, 0, 0);
}

bool isPedADog(Ped ped)
{

	Hash animalType = ENTITY::_GET_PED_ANIMAL_TYPE(ped);
	return
		animalType == (Hash)eAnimalType::AT_DOG ||
		animalType == (Hash)eAnimalType::AT_DOG_AUSTRALIAN ||
		animalType == (Hash)eAnimalType::AT_DOG_BLOODHOUND ||
		animalType == (Hash)eAnimalType::AT_DOG_BLUETICK ||
		animalType == (Hash)eAnimalType::AT_DOG_BORDER ||
		animalType == (Hash)eAnimalType::AT_DOG_CATAHOULA ||
		animalType == (Hash)eAnimalType::AT_DOG_CHESAPEAKE ||
		animalType == (Hash)eAnimalType::AT_DOG_FOXHOUND ||
		animalType == (Hash)eAnimalType::AT_DOG_HUSKY ||
		animalType == (Hash)eAnimalType::AT_DOG_LAB ||
		animalType == (Hash)eAnimalType::AT_DOG_MUTT ||
		animalType == (Hash)eAnimalType::AT_DOG_POODLE ||
		animalType == (Hash)eAnimalType::AT_DOG_RUFUS;
}

bool isPedASnake(Ped ped)
{
	eAnimalType animalType = (eAnimalType)ENTITY::_GET_PED_ANIMAL_TYPE(ped);
	return
		animalType == eAnimalType::AT_SNAKE_BLACK ||
		animalType == eAnimalType::AT_SNAKE_BOA ||
		animalType == eAnimalType::AT_SNAKE_BOA_RAINBOW ||
		animalType == eAnimalType::AT_SNAKE_BOA_SUN ||
		animalType == eAnimalType::AT_SNAKE_COPPER_NORTH ||
		animalType == eAnimalType::AT_SNAKE_COPPER_SOUTH ||
		animalType == eAnimalType::AT_SNAKE_COTTON ||
		animalType == eAnimalType::AT_SNAKE_DIAMOND ||
		animalType == eAnimalType::AT_SNAKE_FERDELANCE ||
		animalType == eAnimalType::AT_SNAKE_NORTHERN ||
		animalType == eAnimalType::AT_SNAKE_TIMBER ||
		animalType == eAnimalType::AT_SNAKE_WATER;
}

int getPedSize(Ped ped)
{
	debug(invoke<int>(0xA65AA1ACE81E5A77, ENTITY::GET_ENTITY_MODEL(ped)));
}

int getGroupSize(int groupId)
{
	BOOL b;
	int size;

	PED::GET_GROUP_SIZE(groupId, &b, &size);

	return size;
}

float getPedFoliageHeight(Ped ped)
{
	long foliageRaw = PED::_0x56E58D4D118FB45E(player, (Any)"FoliageHeight");
	float foliage = (((float)((foliageRaw / 1000000) % 100)) / 10);
	foliage = (foliage - 5.5) / (1.7);

	foliage *= PED::GET_PED_CROUCH_MOVEMENT(ped) ? 2 : 1;

	return min(1, max(0, foliage));
}