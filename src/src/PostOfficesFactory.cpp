#include "Main.h"

PostOfficesFactory::PostOfficesFactory()
{
	cache = {
		{ PostOffices::Valentine, toVector3(-180.543, 629.124, 114.09) },
		{ PostOffices::EmeraldRanch, toVector3(1521.5, 439.356, 90.6807) },
		{ PostOffices::Annesburg, toVector3(2931.73, 1283.24, 44.6528) },
		{ PostOffices::VanHorn, toVector3(2985.22, 568.669, 44.6279) },
		{ PostOffices::SaintDenis, toVector3(2749.14, -1400.79, 46.1927) },
		{ PostOffices::Rhodes, toVector3(1233.22, -1297.11, 76.9048) },
		{ PostOffices::WallaceStation, toVector3(-1298.77, 401.872, 95.3839) },
		{ PostOffices::Strawberry, toVector3(-1765.09, -383.61, 157.737) },
		{ PostOffices::RiggsStation, toVector3(-1095.53, -575.422, 82.4099) },
		{ PostOffices::Blackwater, toVector3(-875.477, -1328.74, 43.958) },
		{ PostOffices::Armadillo, toVector3(-3729.61, -2603.14, -12.9377) },
		{ PostOffices::Tumbleweed, toVector3(-5230.35, -3468.04, -20.5129) },
	};
}

Vector3 PostOfficesFactory::getLocation(PostOffices postOfficeId)
{
	if (cache.find(postOfficeId) == cache.end())
	{
		return toVector3(0, 0, 0);
	}

	return cache.at(postOfficeId);
}

PostOffices PostOfficesFactory::closestTo(Vector3 coords)
{
	PostOffices bestId = cache.begin()->first;
	Vector3 bestLocation = cache.begin()->second;
	float bestDistance = distance(coords, bestLocation);

	for each (pair<PostOffices, Vector3> postOffice in cache)
	{
		float currentDistance = distance(postOffice.second, coords);
		if (currentDistance < bestDistance)
		{
			bestId = postOffice.first;
			bestLocation = postOffice.second;
			bestDistance = currentDistance;
		}
	}

	return bestId;
}
