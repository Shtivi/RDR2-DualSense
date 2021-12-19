#pragma once

struct ScenarioPoint
{
private:
	int id = 0;
	Entity entity = NULL;
	Vector3 location;
	const char* scenario;
	Vector3 offset;
	float heading = 0;

public:
	ScenarioPoint(Entity entity, const char* scenario, Vector3 offset, float heading);
	ScenarioPoint(Vector3 location, const char* scenario, float heading);

	int getId();
	Entity getEntity();
	Vector3 getLocation();
	bool isAttachedToEntity();
	Vector3 getOffset();
	float getHeading();
	bool isExist();
	int getScenarioHashKey();
	int create();
};