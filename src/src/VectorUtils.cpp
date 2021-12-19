#include "Main.h"

Vector3 VectorUtils::getClosestLocationTo(vector<Vector3>* locations, Vector3 coords, float minDistanceTreshold)
{
	if (!locations->size())
	{
		return toVector3(0, 0, 0);
	}

	Vector3 best = toVector3(0, 0, 0);
	float bestDistance = 99999;

	for (vector<Vector3>::iterator itr = locations->begin(); itr != locations->end(); itr++)
	{
		Vector3 curr = *itr;
		float currDistance = distance(curr, coords);
		if (currDistance < bestDistance && currDistance >= minDistanceTreshold)
		{
			best = curr;
			bestDistance = currDistance;
		}
	}

	return best;
}

vector<int> VectorUtils::numbers(int from, int to)
{
	vector<int> results;
	int next = from;
	while (next < to) 
	{
		results.push_back(next);
		next++;
	}

	return results;
}

vector<int> VectorUtils::numbers(int to)
{
	return numbers(0, to);
}

Vector3 VectorUtils::random(vector<Vector3>& vector)
{
	if (!vector.size())
	{
		return toVector3(0, 0, 0);
	}

	return vector.at(rndInt(0, vector.size()));
}

const char* VectorUtils::random(vector<const char*>& vector)
{
	if (!vector.size())
	{
		return NULL;
	}

	return vector.at(rndInt(0, vector.size()));
}

string VectorUtils::random(vector<string>& vector)
{
	if (!vector.size())
	{
		return string();
	}

	return vector.at(rndInt(0, vector.size()));
}