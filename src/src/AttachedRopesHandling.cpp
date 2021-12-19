#include "Main.h"

std::vector<Rope*> attachedRopes;
Stopwatch ropesUpdateStopwatch;
double nextTickIn = 0;

void UpdateRopes()
{
	if (ropesUpdateStopwatch.isStarted())
	{
		if (ropesUpdateStopwatch.getElapsedSeconds() < nextTickIn)
		{
			return;
		}
		else
		{
			ropesUpdateStopwatch.stop();
		}
	}

	std::vector<Rope*>::iterator it;
	for (it = attachedRopes.begin(); it != attachedRopes.end(); ++it)
	{
		if (!(*it)->isExist())
		{
			continue;
		}

		nextTickIn = max(nextTickIn, (*it)->update());
	}

	nextTickIn = nextTickIn / 1000;
	ropesUpdateStopwatch.start();
}

void addRope(Rope* rope)
{
	attachedRopes.push_back(rope);
}

bool doesEntityAttachedToRope(Entity entity)
{
	std::vector<Rope*>::iterator it;
	Rope* curr;

	for (it = attachedRopes.begin(); it != attachedRopes.end(); ++it)
	{
		curr = *it;

		if (!curr->isExist())
		{
			return false;
		}

		return curr->getAttached() == entity || curr->getBase() == entity;
	}
}

Rope* getClosestRopeWithin(Vector3 position, float radius) {
	std::vector<Rope*>::iterator it;
	Rope* curr;
	Vector3 ropeBase;
	float currDistance;
	Rope* best = NULL;
	float bestDistance = radius;

	for (it = attachedRopes.begin(); it != attachedRopes.end(); ++it)
	{
		curr = *it;
		Vector3 ropeBase = ENTITY::GET_ENTITY_COORDS(curr->getBase(), 1, 0);
		currDistance = distanceBetween(ropeBase, position);

		if (currDistance <= radius && currDistance <= bestDistance) {
			best = *it;
			bestDistance = currDistance;
		}
	}

	return best;
}

Rope* getRopeAttachedTo(Entity entity) {
	std::vector<Rope*>::iterator it;
	Rope* curr;

	if (!entity) {
		return NULL;
	}

	for (it = attachedRopes.begin(); it != attachedRopes.end(); ++it)
	{
		curr = *it;
		if (curr->isExist() && (curr->getAttached() == entity || curr->getBase() == entity)) {
			return &(*curr);
		}
	}

	return NULL;
}