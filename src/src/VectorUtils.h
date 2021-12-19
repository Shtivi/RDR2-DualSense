#pragma once

class VectorUtils
{
public:
	template<class T> static T randomElement(vector<T>& vec)
	{
		return vec.at(rndInt(0, vec.size()));
	}

	static Vector3 getClosestLocationTo(vector<Vector3>* locations, Vector3 coords, float minDistanceTreshold = 0);
	static vector<int> numbers(int from, int to);
	static vector<int> numbers(int to);
	static Vector3 random(vector<Vector3>& vector);
	static string random(vector<string>& vector);
	static const char* random(vector<const char*>& vector);
};
