#include "Main.h";

AttachedRope::AttachedRope(Vector3 mapPosition, Entity entity, const char* bone, float length) :
	AttachedRope(entity, createMapProp("p_shotGlass01x", mapPosition), bone, NULL, length)
{
	isAttachedToMap = true;
}

AttachedRope::AttachedRope(Entity entity, Vector3 mapPosition, const char* objectName, bool placeOnGround) :
	AttachedRope(entity, createMapProp((char*)objectName, mapPosition, placeOnGround), NULL, NULL, 0)
{
	isAttachedToMap = true;
}

AttachedRope::AttachedRope(Entity entity1, Entity entity2, const char* bone1, const char* bone2, float length)
{
	Vector3 pos1 = ENTITY::GET_ENTITY_COORDS(entity1, true, 0);
	Vector3 pos2 = ENTITY::GET_ENTITY_COORDS(entity2, true, 0);

	if (length <= 0)
	{
		length = MISC::GET_DISTANCE_BETWEEN_COORDS(pos1.x, pos1.y, pos1.z, pos2.x, pos2.y, pos2.z, true);
	}

	this->entity1 = entity1;
	this->entity2 = entity2;
	this->ropeLength = length;
	this->bone1 = bone1;
	this->bone2 = bone2;
	this->ropeId = PHYSICS::ADD_ROPE(pos1.x, pos1.y, pos1.z, 0, 0, 0, length, 14, length + 3.0f, 10, 0, 0, 0, 0, 1.25f, true, 0, 0);
	//PHYSICS::_0x462FF2A432733A44(ropeId, entity1, entity2, 0, 0, 0, 0, 0, 0, (Any)bone1, (Any)bone2);
	invoke<Void>(0x462FF2A432733A44, ropeId, entity1, entity2, 0, 0, 0, 0, 0, 0, bone1, bone2);
	//PHYSICS::ACTIVATE_PHYSICS(ropeId);
	//PHYSICS::_0x3C6490D940FF5D0B(ropeId, 0, (Any)"noose01x_Rope_03", length, length);
	invoke<Void>(0x3C6490D940FF5D0B, ropeId, 0, (Any)"noose01x_Rope_03", length, length);

	this->isAttachedToMap = false;
	this->isEntityHanging = false;
	this->isWinding = false;
	this->isUnwinding = false;
}

bool AttachedRope::getIsAttachedToMap()
{
	return isAttachedToMap;
}

bool AttachedRope::getIsEntityHanging()
{
	return isEntityHanging;
}

Entity AttachedRope::getAttached()
{
	return entity1;
}

Entity AttachedRope::getBase()
{
	return entity2;
}

bool AttachedRope::isExist()
{
	return PHYSICS::GET_ROPE_VERTEX_COUNT(ropeId) > 0;
}

void AttachedRope::startWinding() {
	if (!isWinding && canWind())
	{
		PHYSICS::START_ROPE_WINDING(this->ropeId);
		stopUnwinding();
		isWinding = true;

		if (ENTITY::IS_ENTITY_A_PED(entity1) && !isEntityHanging)
		{
			PED::SET_PED_TO_RAGDOLL(entity1, 5000, 5000, 1, false, false, false);
		}
		WAIT(100);
	}
}

void AttachedRope::stopWinding()
{
	PHYSICS::STOP_ROPE_WINDING(this->ropeId);
	isWinding = false;
	WAIT(100);
}

void AttachedRope::startUnwinding()
{
	if (!isUnwinding && canUnwind())
	{
		PHYSICS::START_ROPE_UNWINDING_FRONT(this->ropeId);
		stopWinding();
		isUnwinding = true;
	}
	WAIT(100);
}

void AttachedRope::stopUnwinding()
{
	PHYSICS::STOP_ROPE_UNWINDING_FRONT(this->ropeId);
	isUnwinding = false;
	WAIT(100);
}

bool AttachedRope::canWind()
{
	return isExist() && distanceBetweenEntities(entity1, entity2) >= 1.0f;
}

bool AttachedRope::canUnwind()
{
	return isExist();
}


int AttachedRope::update()
{
	if (!isExist())
	{
		return 0;
	}

	int wait = 100;
	float heightAboveGround;
	int currHealth;
	Ped ped;

	if (!isAttachedToMap || !entity1)
	{
		return 0;
	}

	if (ENTITY::DOES_ENTITY_EXIST(entity1) &&
		ENTITY::IS_ENTITY_A_PED(entity1))
	{
		ped = (Ped)entity1;

		if (ENTITY::IS_ENTITY_DEAD(ped) || !PED::IS_PED_HUMAN(ped) || findCarriedPedBy(player) == ped)
		{
			return 0;
		}

		RaycastResult ray = raycast(entityPos(ped), getUpVector(ped) * -1, 10, Everything, ped);
		float heightAboveGround = distance(entityPos(ped), ray.hitPos);

		if (isEntityHanging && heightAboveGround < HANGING_TRESHOLD)
		{
			isEntityHanging = false;
			wait = 1000;
		}

		if (!isEntityHanging && heightAboveGround >= HANGING_TRESHOLD)
		{
			isEntityHanging = true;
		}

		if (isEntityHanging)
		{
			PED::SET_PED_TO_RAGDOLL(ped, 5000, 5000, 0, false, false, false);
			currHealth = ENTITY::GET_ENTITY_HEALTH(ped);
			ENTITY::SET_ENTITY_HEALTH(ped, max(currHealth - 2, 0), 0);
		}
	}

	if (isWinding && !canWind()) {
		stopWinding();
	}

	if (isUnwinding && !canUnwind())
	{
		stopUnwinding();
	}

	return wait;
}

void AttachedRope::detach()
{
	PHYSICS::DETACH_ROPE_FROM_ENTITY(ropeId, this->getAttached());
	Vector3 downVec = -1 * getUpVector(this->getAttached());
	ENTITY::APPLY_FORCE_TO_ENTITY(this->getAttached(), 0, downVec.x, downVec.y, downVec.z, 0, 0, 0, 0, 0, 1, 1, 0, 0);
}

Object AttachedRope::createMapProp(char* model, Vector3 position, bool placeOnGround)
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
	Object prop = OBJECT::CREATE_OBJECT(modelHash, position.x, position.y, position.z, false, false, true, 0, 0);
	ENTITY::FREEZE_ENTITY_POSITION(prop, true);
	ENTITY::SET_ENTITY_VISIBLE(prop, true);

	if (placeOnGround)
	{
		OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(prop, 0);
	}

	return prop;
}