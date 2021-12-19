#include "Main.h"

void getGroundPos(Vector3 originalPos, Vector3* outPos)
{
	float groundZ;
	MISC::GET_GROUND_Z_FOR_3D_COORD(originalPos.x, originalPos.y, originalPos.z, &groundZ, false);

	outPos->x = originalPos.x;
	outPos->y = originalPos.y;
	outPos->z = groundZ;
}

float distanceBetweenEntities(Entity entity1, Entity entity2)
{
	Vector3 pos1 = ENTITY::GET_ENTITY_COORDS(entity1, 1, 0);
	Vector3 pos2 = ENTITY::GET_ENTITY_COORDS(entity2, 1, 0);

	return MISC::GET_DISTANCE_BETWEEN_COORDS(pos1.x, pos1.y, pos1.z, pos2.x, pos2.y, pos2.z, 1);
}

Object createProp(char* model, Vector3 position, float heading, bool isStatic, bool isVisible)
{
	Hash modelHash = MISC::GET_HASH_KEY(model);

	if (!STREAMING::HAS_MODEL_LOADED(modelHash))
	{
		STREAMING::REQUEST_MODEL(modelHash, false);
	}

	while (!STREAMING::HAS_MODEL_LOADED(modelHash))
	{
		WAIT(0);
	}

	Object prop = OBJECT::CREATE_OBJECT(modelHash, position.x, position.y, position.z, false, false, !isStatic, 0, 0);
	ENTITY::SET_ENTITY_HEADING(prop, heading);
	ENTITY::FREEZE_ENTITY_POSITION(prop, isStatic);
	ENTITY::SET_ENTITY_VISIBLE(prop, isVisible);
	
	if (!isStatic) {
		OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(prop, 0);
	}

	return prop;
}

tm getGameTime()
{
	tm gameTime;
	gameTime.tm_year = 70; // make problems only with years aroud 1970, not 1900.
	gameTime.tm_mon = CLOCK::GET_CLOCK_MONTH();
	gameTime.tm_mday = CLOCK::GET_CLOCK_DAY_OF_MONTH();
	gameTime.tm_wday = CLOCK::GET_CLOCK_DAY_OF_WEEK();
	gameTime.tm_hour = CLOCK::GET_CLOCK_HOURS();
	gameTime.tm_min = CLOCK::GET_CLOCK_MINUTES();
	gameTime.tm_sec = CLOCK::GET_CLOCK_SECONDS();

	return gameTime;
}

RaycastResult raycast(Vector3 source, Vector3 direction, float maxDist, RaycastIntersectionOptions intersectionOptions, Entity ignore)
{
	RaycastResult result;
	Vector3 target = source + direction * maxDist;
	int rayHandle = SHAPETEST::START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE(source.x, source.y, source.z, target.x, target.y, target.z, intersectionOptions, ignore, 7);
	SHAPETEST::GET_SHAPE_TEST_RESULT(rayHandle, (BOOL*)&result.didHit, &result.hitPos, &result.normal, &result.hitEntity);
	return result;
}

RaycastResult raycastCrosshair(float maxDist, RaycastIntersectionOptions intersectionOptions, Entity ignore)
{
	Vector3 source = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 rot = ((float)3.1452 / 180.0) * CAM::GET_FINAL_RENDERED_CAM_ROT(2);
	Vector3 forward = normalOf(toVector3(
		-sin(rot.z) * abs(cos(rot.x)),
		cos(rot.z) * abs(cos(rot.x)),
		sin(rot.x)
	));
	return raycast(source, forward, maxDist, intersectionOptions, ignore);
}

RaycastResult shapeTestSphere(Vector3 source, Vector3 target, float radius, RaycastIntersectionOptions intersectionOptions, Entity ignore)
{
	RaycastResult result;
	int rayHandle = SHAPETEST::START_SHAPE_TEST_CAPSULE(source.x, source.y, source.z, target.x, target.y, target.z, radius, intersectionOptions, ignore, 7);
	SHAPETEST::GET_SHAPE_TEST_RESULT(rayHandle, (BOOL*)&result.didHit, &result.hitPos, &result.normal, &result.hitEntity);
	return result;
}

void getGroundPos(Vector3* originalPos)
{
	getGroundPos(*originalPos, originalPos);
}

Vector3 getGroundPos(Vector3 originalPos)
{
	float groundZ;
	MISC::GET_GROUND_Z_FOR_3D_COORD(originalPos.x, originalPos.y, originalPos.z, &groundZ, false);
	return toVector3(originalPos.x, originalPos.y, groundZ);
}

Vector3 getRandomPositionInRange(Vector3 center, int radius)
{
	int x = rndInt((int)center.x - radius, (int)center.x + radius + 1);
	int topOrBottom = rndInt(0, 2) == 1 ? 1 : -1;
	double y = topOrBottom * sqrt(pow(radius, 2) - pow(x - center.x, 2)) + center.y;

	Vector3 output;
	output.x = x;
	output.y = (float)y;
	return getGroundPos(output);
}

Vector3 getRandomPedPositionInRange(Vector3 source, int radius)
{
	Vector3 position = getRandomPositionInRange(source, radius);
	if (!PATHFIND::GET_SAFE_COORD_FOR_PED(position.x, position.y, position.z, true, &position, 16))
	{
		return toVector3(0, 0, 0);
	}

	return position;
}

Vector3 playerPos()
{
	return ENTITY::GET_ENTITY_COORDS(player, 1, 0);
}

float getModelLength(Hash model)
{
	Vector3 front, back;
	MISC::GET_MODEL_DIMENSIONS(model, &front, &back);
	float length = get_vector_length(front - back);
	return length;
}

Vector3 getRelativeEntityCoords(Entity entity, int offsetFromCenter)
{
	float length = getModelLength(ENTITY::GET_ENTITY_MODEL(entity));
	Vector3 entityPos = ENTITY::GET_ENTITY_COORDS(entity, 1, 0);
	Vector3 forwardVec = ENTITY::GET_ENTITY_FORWARD_VECTOR(entity);
	
	return entityPos + forwardVec * offsetFromCenter * (length / 4);
}

Vehicle getClosestVehicle(Ped around)
{
	int nearbyEntities[5 * 2 + 2];
	nearbyEntities[0] = 5;
	int n = PED::GET_PED_NEARBY_VEHICLES(around, (Any*)&nearbyEntities);

	if (n == 0)
	{
		return NULL;
	}

	Vehicle best = nearbyEntities[0];
	float bestDistance = distanceBetweenEntities(around, best);

	for (int i = 0; i < n; i++)
	{
		float dist = distanceBetweenEntities(around, nearbyEntities[i]);
		if (ENTITY::DOES_ENTITY_EXIST(nearbyEntities[i]) && dist < bestDistance)
		{
			best = nearbyEntities[i];
			bestDistance = dist;
		}
	}

	return best;
}

Vector3 entityPos(Entity entity)
{
	return ENTITY::GET_ENTITY_COORDS(entity, 1, 0);
}

float calculateHeadingToPosition(Entity entity, Vector3 dest)
{
	float entityHeading = ENTITY::GET_ENTITY_HEADING(entity);
	float angle = angleBetweenVectors(entityPos(entity), dest);
	return entityHeading - angle;
}

Ped findHogtiedTargetEntity()
{
	Entity targetEntity = NULL;
	Ped asPed;
	
	if (!PLAYER::GET_PLAYER_TARGET_ENTITY(PLAYER::PLAYER_ID(), &targetEntity))
	{
		return false;
	}

	if (ENTITY::IS_ENTITY_A_PED(targetEntity) &&
		PED::IS_PED_HUMAN(targetEntity) &&
		TASK::GET_IS_TASK_ACTIVE(targetEntity, 400))
	{
		return (Ped)targetEntity;
	}

	return false;
}

Ped getClosestPed(Ped around)
{
	int nearbyEntities[5 * 2 + 2];
	Ped targetEntity = NULL;

	nearbyEntities[0] = 5;
	int n = PED::GET_PED_NEARBY_PEDS(around, (Any*)&nearbyEntities, -1, -1);

	if (n == 0)
	{
		return NULL;
	}

	Ped best = nearbyEntities[0];
	float bestDistance = distanceBetweenEntities(around, best);

	for (int i = 0; i < n; i++)
	{
		float dist = distanceBetweenEntities(around, nearbyEntities[i]);
		if (ENTITY::DOES_ENTITY_EXIST(nearbyEntities[i]) && dist < bestDistance)
		{
			best = nearbyEntities[i];
			bestDistance = dist;
		}
	}

	return best;
}

Ped getClosestPed(Vector3 around, float radius)
{
	Ped ped;
	PED::GET_CLOSEST_PED(around.x, around.y, around.z, radius, 1, 0, (Any)&ped, 0, 0, 26, 26);
	return ped;
}

Vector3* getSafeCoordForPed(Vector3 destination)
{
	Vector3* out = new Vector3();
	if (!PATHFIND::GET_SAFE_COORD_FOR_PED(destination.x, destination.y, destination.z, false, out, 16))
	{
		*out = toVector3(0, 0, 0);
	}

	return out;
}

void loadImap(Hash imapHash)
{
	if (!STREAMING::IS_IPL_ACTIVE_HASH(imapHash))
	{
		STREAMING::REQUEST_IPL_HASH(imapHash);
	}
}

void loadInteriorSet(Interior interior, const char* setName)
{
	if (!INTERIOR::IS_INTERIOR_ENTITY_SET_ACTIVE(interior, (char*) setName)) {
		INTERIOR::ACTIVATE_INTERIOR_ENTITY_SET(interior, (char*) setName, 1);
	}
}

MapAreas getMapArea(Vector3 pos)
{
	int town = ZONE::_GET_MAP_ZONE_AT_COORDS(pos.x, pos.y, pos.z, 1);
	if (town) 
	{
		return (MapAreas)town;
	}
	else 
	{
		int district = ZONE::_GET_MAP_ZONE_AT_COORDS(pos.x, pos.y, pos.z, 10);
		if (district) 
		{
			return (MapAreas)district;
		}
		return (MapAreas)ZONE::_GET_MAP_ZONE_AT_COORDS(pos.x, pos.y, pos.z, 11);
	}
}

MapAreas getMapArea(Entity entity)
{
	return getMapArea(entityPos(entity));
}

Position getClosestVehicleNode(Vector3 around, bool flipDirection)
{
	Vector3 out;
	float heading;
	if (PATHFIND::GET_CLOSEST_VEHICLE_NODE_WITH_HEADING(around.x, around.y, around.z, &out, &heading, 1, 3, 0))
	{
		return make_pair(out, heading);
	}

	return make_pair(toVector3(0, 0, 0), 0);
}

float getWindSpeed()
{
	return MISC::GET_WIND_SPEED();
}

Vector3 getWindDirection()
{
	return MISC::GET_WIND_DIRECTION();
}

void setWindDirection(float direction)
{
	MISC::SET_WIND_DIRECTION(direction);
}

void setWindSpeed(float speed)
{
	MISC::SET_WIND_SPEED(speed);
}

void setWindSpeedSmoothly(float speed, float step, float interval)
{
	float previousSpeed = getWindSpeed();
	float speedDiff = speed - previousSpeed;

	int sign = speedDiff > 0 ? 1 : -1;
	while (abs(speedDiff) >= step)
	{
		previousSpeed = previousSpeed + sign * step;
		speedDiff = speed - previousSpeed;
		setWindSpeed(previousSpeed);
		WAIT(interval);
	}
}

Ped findClosestPredatorAround(Ped origin, float radius)
{
	vector<Ped> peds = getNearbyPeds(origin, 40, radius, -1, true);
	
	if (!peds.size())
	{
		return NULL;
	}

	Ped best = 0;
	float bestDistance = radius + 1;
	
	for (Ped current : peds)
	{
		if (!ENTITY::_GET_IS_PREDATOR(current) ||
			ENTITY::IS_ENTITY_DEAD(current)) 
		{
			continue;
		}

		float currentDistance = distance(origin, current);
		if (currentDistance < bestDistance)
		{
			best = current;
			bestDistance = currentDistance;
		}
	}

	return best;
}

Vector3 calculateLocationAlongRoad(Vector3 source, float dist, bool flipDirection, int step)
{
	if (step <= 0)
	{
		step = 20;
	}

	int iterations = dist / step;
	int counter = 0;
	Position nextRoadLocation = getClosestVehicleNode(source);
	nextRoadLocation.second = flipDirection ? nextRoadLocation.second - 180 : nextRoadLocation.second;
	while (counter < iterations)
	{
		//setBlipLabel(createBlip(nextRoadLocation.first, 0xC19DA63), to_string(counter).c_str());
		Vector3 nextEstimatedLocation = calculatePointInDirection(nextRoadLocation.first, nextRoadLocation.second, step);
		//setBlipLabel(createBlip(nextEstimatedLocation, 0x19365607), to_string(counter).append(" -> ").append(to_string(counter+1)).c_str());
		Vector3 previousRoadLocation = nextRoadLocation.first;
		nextRoadLocation = getClosestVehicleNode(nextEstimatedLocation);
		nextRoadLocation.second = calculateHeadingToVector(nextRoadLocation.first, previousRoadLocation);
		counter++;
	}

	return nextRoadLocation.first;
}

float getEntityHealthLevel(Entity entity)
{
	if (!ENTITY::DOES_ENTITY_EXIST(entity))
	{
		return 0;
	}

	float health = (float)ENTITY::GET_ENTITY_HEALTH(entity);
	float maxHealth = (float)ENTITY::GET_ENTITY_MAX_HEALTH(entity, 1);

	if (!maxHealth)
	{
		return 0;
	}

	return health / maxHealth;
}

void playSoundFromEntity(Entity e, char* soundset, char* soundname)
{
	int i = 1;
	while (i <= 50 && !AUDIO::PREPARE_SOUNDSET(soundset, 0)) {
		i++;
		WAIT(100);
	}
	AUDIO::PLAY_SOUND_FROM_ENTITY(soundname, e, soundset, 1, 0, 0);
}

void playSoundFromCoord(Vector3 coords, char* soundset, char* soundname)
{
	int i = 1;
	while (i <= 50 && !AUDIO::PREPARE_SOUNDSET(soundset, 0)) {
		i++;
		WAIT(100);
	}
	AUDIO::_PLAY_SOUND_FROM_POSITION(soundname, coords.x, coords.y, coords.z, soundset, 1, 0, 0, 0);
}

void playEntityAnimation(Entity entity, const char* animName, const char* animDict, float duration, bool loop, bool stayInAnim, float delta, int bitset) 
{
	int i = 0;
	while (!STREAMING::HAS_ANIM_DICT_LOADED((char*)animDict) && i <= 500)
	{
		STREAMING::REQUEST_ANIM_DICT((char*)animDict);
		i++;
		WAIT(10);
	}

	ENTITY::PLAY_ENTITY_ANIM(entity, (char*)animName, (char*)animDict, duration, loop, stayInAnim, 1, delta, bitset);
}

bool isNight()
{
	int hours = CLOCK::GET_CLOCK_HOURS();
	return hours >= 21 || hours < 6;
}

bool isDaylight()
{
	int hours = CLOCK::GET_CLOCK_HOURS();
	return hours >= 7 && hours < 18;
}