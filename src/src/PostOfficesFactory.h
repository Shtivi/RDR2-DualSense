#pragma once

class PostOfficesFactory
{
private:
	map<PostOffices, Vector3> cache;

public:
	PostOfficesFactory();
	Vector3 getLocation(PostOffices postOfficeId);
	PostOffices closestTo(Vector3 coords);
};