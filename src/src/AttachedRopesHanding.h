#pragma once

const float HANGING_TRESHOLD = 1.1f;

void UpdateRopes();
void addRope(Rope* rope);
bool doesEntityAttachedToRope(Entity entity);
Rope* getClosestRopeWithin(Vector3 position, float radius);
Rope* getRopeAttachedTo(Entity entity);
