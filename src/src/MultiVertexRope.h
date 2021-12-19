#pragma once

using namespace std;

class MultiVertexRope : public Rope
{
private:
	vector<AttachedRope*> ropes;

public:
	MultiVertexRope(AttachedRope* base);

	Entity getBase();
	Entity getAttached();
	bool isExist();
	bool canWind();
	void startWinding();
	void stopWinding();
	bool canUnwind();
	void startUnwinding();
	void stopUnwinding();
	void detach();
	int update();

	void pinTo(Vector3 position);
};