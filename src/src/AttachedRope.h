#pragma once

class AttachedRope : public Rope
{
private:
	int ropeId;
	Entity entity1;
	Entity entity2;
	const char* bone1;
	const char* bone2;
	float ropeLength;
	bool isAttachedToMap;
	bool isEntityHanging;
	bool isWinding;
	bool isUnwinding;

public:
	AttachedRope(Vector3 mapPosition, Entity entity, const char* bone, float length);
	AttachedRope(Entity entity, Vector3 mapPosition, const char* baseObjectName = "p_shotGlass01x", bool placeOnGround = false);
	AttachedRope(Entity entity, Entity base, const char* bone1, const char* bone2, float length);

	bool getIsAttachedToMap();
	bool getIsEntityHanging();
	bool isExist();
	Entity getAttached();
	Entity getBase();

	bool canWind();
	void startWinding();
	void stopWinding();
	bool canUnwind();
	void startUnwinding();
	void stopUnwinding();
	void detach();
	int update();

private:
	Object createMapProp(char* model, Vector3 position, bool placeOnGround = false);
};