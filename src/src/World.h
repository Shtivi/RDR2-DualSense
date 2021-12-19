#pragma once

#include "CarriableTypes.h"
#include "Blips.h"
#include "Weapons.h"
#include "Vehicles.h"
#include "Rope.h"
#include "Propset.h"

typedef struct RaycastResult
{
	bool didHit;
	Vector3 hitPos;
	Entity hitEntity;
	Vector3 normal;
};

enum RaycastIntersectionOptions
{
	Everything = -1,
	Map = 1,
	MissionEntities,
	Peds1 = 12,
	Objects = 16,
	Unk1 = 32,
	Unk2 = 64,
	Unk3 = 128,
	Vegetation = 256,
	Unk4 = 512
};

enum class MapAreas : int
{
	Blackwater = 1053078005,
	Rhodes = 2046780049,
	Valentine = 459833523,
	SaintDenis = -765540529,
	Strawberry = 427683330,
	Annesburg = 7359335,
	VanHorn = 2126321341,
	Tumbleweed = -1524959147,
	Armadillo = -744494798,
	EmeraldRanch = -473051294,
	BenedictPoint = -2145992129,
	Heartlands = 131399519,
	ButcherCreek = -1947415645,
	RiggsStation = 822658194
};

enum class PostOffices : int
{
	Valentine,
	EmeraldRanch,
	Annesburg,
	VanHorn,
	SaintDenis,
	Rhodes,
	WallaceStation,
	Strawberry,
	RiggsStation,
	Blackwater,
	Armadillo,
	Tumbleweed,
	Count
};

extern Ped player;

Vector3 entityPos(Entity entity);
void getGroundPos(Vector3 originalPos, Vector3* outPos);
float distanceBetweenEntities(Entity entity1, Entity entity2);

Object createProp(char* model, Vector3 position, float heading = 0, bool isStatic = false, bool isVisible = true);
RaycastResult raycast(Vector3 source, Vector3 direction, float maxDist, RaycastIntersectionOptions intersectionOptions = Everything, Entity ignore = NULL);
RaycastResult raycastCrosshair(float maxDist, RaycastIntersectionOptions intersectionOptions = Everything, Entity ignore = NULL);
RaycastResult shapeTestSphere(Vector3 source, Vector3 target, float radius, RaycastIntersectionOptions intersectionOptions = Everything, Entity ignore = NULL);
tm getGameTime();
void getGroundPos(Vector3* position);
Vector3 getGroundPos(Vector3 originalPos);
Vector3 getRandomPositionInRange(Vector3 source, int radius);
Vector3 getRandomPedPositionInRange(Vector3 source, int radius);
Vector3 playerPos();
float getModelLength(Hash model);
Vector3 getRelativeEntityCoords(Entity entity, int offsetFromCenter = 0);
Ped getClosestPed(Ped around);
Ped getClosestPed(Vector3 around, float radius);
Vehicle getClosestVehicle(Ped around);
float calculateHeadingToPosition(Entity entity, Vector3 dest);
Ped findHogtiedTargetEntity();
Vector3* getSafeCoordForPed(Vector3 destination);
void loadImap(Hash imapHash);
void loadInteriorSet(Interior interior, const char* setName);
MapAreas getMapArea(Vector3 position);
MapAreas getMapArea(Entity entity);
Position getClosestVehicleNode(Vector3 around, bool flipDirection = false);
float getWindSpeed();
Vector3 getWindDirection();
void setWindDirection(float direction);
void setWindSpeed(float speed);
void setWindSpeedSmoothly(float speed, float step = 0.5, float interval = 100);
Ped findClosestPredatorAround(Ped origin, float radius);
Vector3 calculateLocationAlongRoad(Vector3 source, float distance, bool flipDirection = false, int step = 20);
float getEntityHealthLevel(Entity entity);
void playSoundFromEntity(Entity e, char* soundset, char* soundname);
void playSoundFromCoord(Vector3 coords, char* soundset, char* soundname);
void playEntityAnimation(Entity entity, const char* animName, const char* animDict, float duration, bool loop = false, bool stayInAnim = false, float delta = 0, int bitset = 0);
bool isNight();
bool isDaylight();

#include "Player.h"
#include "ScenarioPoint.h"
#include "Place.h"
#include "MapArea.h"
