#include "Main.h"

MapAreasFactory::MapAreasFactory(PlacesFactory* placesFactory, PostOfficesFactory* postOffices)
{
	this->placesFactory = placesFactory;
	this->postOffices = postOffices;

	MapArea* thumbleweed = createTumbleweed();
	MapArea* valentine = createValentine();
	MapArea* annesburg = createAnnesburg();
	MapArea* strawberry = createStrawberry();
	MapArea* rhodes = createRhodes();
	MapArea* stDenis = createSaintDenis();
	MapArea* blackwater = createBlackwater();
	MapArea* armadillo = createArmadillo();

	cache = {
		{ MapAreas::Valentine, valentine },
		{ MapAreas::EmeraldRanch, valentine },
		{ MapAreas::Heartlands, valentine },
		{ MapAreas::Rhodes, rhodes },
		{ MapAreas::SaintDenis, stDenis },
		{ MapAreas::Blackwater, blackwater },
		{ MapAreas::Armadillo, armadillo },
		{ MapAreas::Tumbleweed, thumbleweed },
		{ MapAreas::BenedictPoint, thumbleweed },
		{ MapAreas::Annesburg, annesburg },
		{ MapAreas::VanHorn, annesburg },
		{ MapAreas::ButcherCreek, annesburg },
		{ MapAreas::Strawberry, strawberry },
		{ MapAreas::RiggsStation, strawberry }
	};

	areaNames = {
		{2025841068, "Bayou Nwa"},
		{822658194, "Big Valley"},
		{1308232528, "Bluewater Marsh"},
		{-108848014, "Cholla Springs"},
		{1835499550, "Cumberland"},
		{426773653, "Diez Coronas"},
		{-2066240242, "Gaptooth Ridge"},
		{476637847, "Great Plains"},
		{-120156735, "Grizzlies East"},
		{1645618177, "Grizzlies West"},
		{-512529193, "Guarma"},
		{131399519, "Heartlands"},
		{892930832, "Hennigans Stead"},
		{-1319956120, "Perdido"},
		{1453836102, "Punta Orgullo"},
		{-2145992129, "Rio Bravo"},
		{178647645, "Roanoke"},
		{-864275692, "Scarlett Meadows"},
		{1684533001, "Tall Trees"}
	};
}

MapArea* MapAreasFactory::getMapArea(MapAreas mapArea)
{
	if (cache.find(mapArea) == cache.end())
	{
		return NULL;
	}

	return cache.find(mapArea)->second;
}

MapArea* MapAreasFactory::getClosestTown(Vector3 location)
{
	float bestDistance = 9999;
	MapArea* best = NULL;

	for (pair<MapAreas, MapArea*> curr : cache)
	{
		float currDistance = distance(location, curr.second->getTownCoords());
		if (currDistance < bestDistance)
		{
			best = curr.second;
			bestDistance = currDistance;
		}
	}

	return best;
}

vector<MapArea*> MapAreasFactory::listMapAreas()
{
	vector<MapArea*> results;
	map<MapAreas, MapArea*>::iterator it;
	for (it = cache.begin(); it != cache.end(); it++)
	{
		results.push_back((*it).second);
	}

	return results;
}

const char* MapAreasFactory::getAreaName(int zoneId)
{
	if (areaNames.find(zoneId) == areaNames.end())
	{
		return NULL;
	}

	return areaNames.find(zoneId)->second;
}

MapArea* MapAreasFactory::createBlackwater()
{
	MapArea* blackwater = new MapArea(MapAreas::Blackwater, "Blackwater", placesFactory->getByArea(MapAreas::Blackwater));

	blackwater->setTownCoords(toVector3(-798.9842, -1247.722, 43.42519));
	blackwater->setTownRadius(200);
	blackwater->addPostOfficeLocation(toVector3(-875.477, -1328.74, 43.958));
	blackwater->addSaloonLocation(toVector3(-811.299, -1323.2, 43.6781));
	blackwater->addLocalGangPedModel("g_m_m_unimountainmen_01");

	blackwater->addTownLocation(toVector3(-849.628, -1370.93, 43.3835), 164.801);
	blackwater->addTownLocation(toVector3(-804.448, -1401.11, 43.2981), 16);
	blackwater->addTownLocation(toVector3(-749.886, -1363.58, 43.3828), 360);
	blackwater->addTownLocation(toVector3(-740.153, -1276.47, 43.6582), 148);
	blackwater->addTownLocation(toVector3(-738.638, -1228.56, 44.7334), 44);
	blackwater->addTownLocation(toVector3(-788.209, -1227.74, 43.5513), 165);
	blackwater->addTownLocation(toVector3(-858.12, -1272.49, 43.4032), 142);
	blackwater->addTownLocation(toVector3(-804.028, -1344.43, 43.5471), 2);
	blackwater->addTownLocation(toVector3(-1001.83, -1188.35, 58.3755), 298.701);
	blackwater->addTownLocation(toVector3(-838.153, -1194.8, 43.7234), 6);

	blackwater->addRoadLocation(toVector3(-860.656, -1761.56, 68.9407));
	blackwater->addRoadLocation(toVector3(-1919.17, -1693.41, 113.588));
	blackwater->addRoadLocation(toVector3(-1485.91, -1924.87, 52.0798));
	blackwater->addRoadLocation(toVector3(-1259.91, -1161.49, 70.7852));
	blackwater->addRoadLocation(toVector3(-1401.35, -1334.61, 86.6919));
	blackwater->addRoadLocation(toVector3(-1662.98, -2009.74, 48.5801));
	blackwater->addRoadLocation(toVector3(-1154.02, -1652.26, 74.125));
	blackwater->addRoadLocation(toVector3(-1205.02, -1820.29, 61.7065));
	blackwater->addRoadLocation(toVector3(-1815.68, -1932.37, 85.9787));

	blackwater->addWildernessCampingLocation(toVector3(-999.56, -1740.29, 73.6095));
	blackwater->addWildernessCampingLocation(toVector3(-2187.83, -1563.26, 150.772));
	blackwater->addWildernessCampingLocation(toVector3(-2306.33, -1398.12, 143.496));
	blackwater->addWildernessCampingLocation(toVector3(-1929.2, -1063.81, 76.6128));
	blackwater->addWildernessCampingLocation(toVector3(-1921.08, -1304.44, 107.183));
	blackwater->addWildernessCampingLocation(toVector3(-1473.38, -1116.02, 73.9677));
	blackwater->addWildernessCampingLocation(toVector3(-1528.25, -1956.22, 46.5845));
	blackwater->addWildernessCampingLocation(toVector3(-1182.63, -1022.22, 66.1585));
	blackwater->addWildernessCampingLocation(toVector3(-905.048, -991.685, 42.2384));
	blackwater->addWildernessCampingLocation(toVector3(-1366.02, -1401.57, 93.2458));
	blackwater->addWildernessCampingLocation(toVector3(-1412.68, -1698.94, 83.0534));
	blackwater->addWildernessCampingLocation(toVector3(-1644.28, -1760.08, 85.7222));
	blackwater->addWildernessCampingLocation(toVector3(-1218.9, -1890.54, 58.3857));
	blackwater->addWildernessCampingLocation(toVector3(-1245.62, -1987.87, 42.5789));
	blackwater->addWildernessCampingLocation(toVector3(-1442.49, -2012.45, 41.1117));
	blackwater->addWildernessCampingLocation(toVector3(-1614.59, -1929.19, 51.0559));
	blackwater->addWildernessCampingLocation(toVector3(-1745.61, -2125.86, 48.9082));
	blackwater->addWildernessCampingLocation(toVector3(-1836.49, -1841.72, 105.535));
	blackwater->addWildernessCampingLocation(toVector3(-2017.51, -1799.38, 110.728));
	blackwater->addWildernessCampingLocation(toVector3(-2176.04, -1755.19, 138.829));
	blackwater->addWildernessCampingLocation(toVector3(-2495.98, -1464.12, 146.478));
	
	blackwater->addOffroadLocation(toVector3(-2451.74, -1460.02, 149.767));
	blackwater->addOffroadLocation(toVector3(-1899.95, -2062.25, 57.0117));
	blackwater->addOffroadLocation(toVector3(-1926.89, -1861.52, 102.918));
	blackwater->addOffroadLocation(toVector3(-2319.11, -1584.86, 148.519));

	blackwater->setLocalGangName("Skinner Brothers");

	return blackwater;
}

MapArea* MapAreasFactory::createRhodes()
{
	MapArea* rhodes = new MapArea(MapAreas::Rhodes, "Rhodes", placesFactory->getByArea(MapAreas::Rhodes));

	rhodes->setTownCoords(toVector3(1232.205, -1251.088, 73.67763));
	rhodes->setTownRadius(200);

	rhodes->addPostOfficeLocation(toVector3(1233.22, -1297.11, 76.9048));

	rhodes->addTownLocation(toVector3(1256.42, -1272.63, 75.4613), 278.663);
	rhodes->addTownLocation(toVector3(1299.08, -1340.51, 77.436), 321.014);
	rhodes->addTownLocation(toVector3(1375.93, -1395, 79.0422), 294.779);
	rhodes->addTownLocation(toVector3(1423.92, -1376.8, 81.7977), 203.622);
	rhodes->addTownLocation(toVector3(1420.97, -1294.35, 77.6096), 131.68);
	rhodes->addTownLocation(toVector3(1346, -1261.5, 78.0238), 306.664);
	rhodes->addTownLocation(toVector3(1289.54, -1238.24, 80.7329), 121.944);
	rhodes->addTownLocation(toVector3(1301.08, -1157.15, 81.2664), 353.817);

	rhodes->addRoadLocation(toVector3(1477.77, -1696.51, 62.7886));
	rhodes->addRoadLocation(toVector3(848.141, -638.13, 73.205));
	rhodes->addRoadLocation(toVector3(1185.68, -1569.81, 54.2474));
	rhodes->addRoadLocation(toVector3(942.362, -1162.27, 55.8837));
	rhodes->addRoadLocation(toVector3(1470.83, -822.47, 50.635));
	rhodes->addRoadLocation(toVector3(1794.68, -898.344, 41.6239));
	rhodes->addRoadLocation(toVector3(2007, -463.748, 42.1442));
	rhodes->addRoadLocation(toVector3(1804.2, -447.47, 43.4593));
	rhodes->addRoadLocation(toVector3(2548.62, -215.44, 43.0795));
	rhodes->addRoadLocation(toVector3(1706.14, -23.5356, 72.5854));
	rhodes->addRoadLocation(toVector3(1365.38, -228.303, 99.4452));

	rhodes->addWildernessCampingLocation(toVector3(842.959, -405.55, 82.7575));
	rhodes->addWildernessCampingLocation(toVector3(915.089, -514.035, 88.0796));
	rhodes->addWildernessCampingLocation(toVector3(1286.24, -546.471, 78.2081));
	rhodes->addWildernessCampingLocation(toVector3(1500.72, -9.72065, 95.6494));
	rhodes->addWildernessCampingLocation(toVector3(1280.13, -50.3411, 98.941));
	rhodes->addWildernessCampingLocation(toVector3(1469.78, -1584, 72.0809));
	rhodes->addWildernessCampingLocation(toVector3(1689.86, -1705.2, 53.9362));
	rhodes->addWildernessCampingLocation(toVector3(1684.87, -1768.07, 54.1169));
	rhodes->addWildernessCampingLocation(toVector3(1705.8, -1954.66, 46.16));
	rhodes->addWildernessCampingLocation(toVector3(1421.44, -2157.96, 48.8076));
	rhodes->addWildernessCampingLocation(toVector3(1366.78, -1791.81, 68.5731));
	rhodes->addWildernessCampingLocation(toVector3(949.596, -941.74, 63.2667));
	rhodes->addWildernessCampingLocation(toVector3(1055.54, -785.098, 85.8692));
	rhodes->addWildernessCampingLocation(toVector3(1082.95, -507.849, 89.3377));
	rhodes->addWildernessCampingLocation(toVector3(1154.32, -260.108, 100.411));
	rhodes->addWildernessCampingLocation(toVector3(1519.03, -261.348, 82.5368));
	rhodes->addWildernessCampingLocation(toVector3(1588.85, -172.851, 80.8783));
	rhodes->addWildernessCampingLocation(toVector3(1290.82, -713.219, 68.8282));
	rhodes->addWildernessCampingLocation(toVector3(884.391, -977.372, 57.3899));
	rhodes->addWildernessCampingLocation(toVector3(1099.53, -1049.33, 67.0744));
	rhodes->addWildernessCampingLocation(toVector3(1686.5, -1155.47, 40.8643));
	rhodes->addWildernessCampingLocation(toVector3(1883.86, -889.403, 41.4978));
	rhodes->addWildernessCampingLocation(toVector3(1969.45, -382.401, 40.8191));
	rhodes->addWildernessCampingLocation(toVector3(1795.26, -661.884, 41.5321));
	rhodes->addWildernessCampingLocation(toVector3(1826.59, -319.815, 46.0427));
	rhodes->addWildernessCampingLocation(toVector3(2592.62, -229.368, 43.5842));
	rhodes->addWildernessCampingLocation(toVector3(2108.52, -1233.13, 41.282));

	rhodes->addOffroadLocation(toVector3(1773.96, -1696.12, 49.1872));
	rhodes->addOffroadLocation(toVector3(1639.93, -2053.39, 41.5687));
	rhodes->addOffroadLocation(toVector3(1504.01, -446.767, 71.1988));
	rhodes->addOffroadLocation(toVector3(1662.19, -224.539, 76.7142));
	rhodes->addOffroadLocation(toVector3(1466.73, -1910.98, 47.7519));
	rhodes->addOffroadLocation(toVector3(1178.4, -1418.36, 64.7037));
	rhodes->addOffroadLocation(toVector3(1015.37, -919.122, 68.3708));
	rhodes->addOffroadLocation(toVector3(1147.32, -658.211, 85.4731));
	rhodes->addOffroadLocation(toVector3(1083.05, -420.973, 90.9717));
	rhodes->addOffroadLocation(toVector3(1517.94, -305.373, 83.4051));
	rhodes->addOffroadLocation(toVector3(1333.22, -771.357, 68.24691));
	rhodes->addOffroadLocation(toVector3(1333.22, -771.357, 68.24691));
	rhodes->addOffroadLocation(toVector3(1549.15, -1114.56, 43.9979));
	rhodes->addOffroadLocation(toVector3(1668.94, -1031.98, 42.2818));
	rhodes->addOffroadLocation(toVector3(1894.58, -560.608, 43.7524));

	rhodes->addTrainTrackLocation(toVector3(826.157, -625.888, 75.666), false);
	rhodes->addTrainTrackLocation(toVector3(926.296, -848.503, 68.7996), false);
	rhodes->addTrainTrackLocation(toVector3(1499.57, -731.214, 53.629), true);
	rhodes->addTrainTrackLocation(toVector3(1473.94, -441.804, 75.6443), true);
	rhodes->addTrainTrackLocation(toVector3(1825.92, -1002.65, 41.8784), true);
	rhodes->addTrainTrackLocation(toVector3(1856.03, -1661.73, 43.6683), false);
	rhodes->addTrainTrackLocation(toVector3(1515.37, -1549.67, 69.0728), false);

	rhodes->addSaloonLocation(toVector3(1344.6, -1374.88, 80.4805));
	rhodes->addJailCellLocation(toVector3(1355.65, -1301.64, 76.7606), 271.941345);

	rhodes->addLocalGangPedModel("g_m_o_uniexconfeds_01");
	rhodes->addLocalGangPedModel("g_m_y_uniexconfeds_01");

	rhodes->setLocalGangName("Lemoyne Raiders");

	// 1623.26, -1454.43, 54.77 Caliga hall

	return rhodes;
}

MapArea* MapAreasFactory::createValentine()
{
	MapArea* valentine = new MapArea(MapAreas::Valentine, "Valentine", placesFactory->getByArea(MapAreas::Valentine));

	valentine->setTownCoords(toVector3(-231.3357, 703.2683, 113.7415));
	valentine->setTownRadius(180);

	valentine->addPostOfficeLocation(toVector3(-180.543, 629.124, 114.09));
	valentine->addPostOfficeLocation(toVector3(1521.5, 439.356, 90.6807));

	//valentine->addQuestGiverLocation(toVector3(-291.888, 764.638, 118.662), 180.8);
	valentine->addTownLocation(toVector3(-312.085, 830.793, 119.576), 83.9105);
	valentine->addTownLocation(toVector3(-367.175, 692.238, 117.384), 324.596);
	valentine->addTownLocation(toVector3(-282.787, 841.352, 119.746), 229.106);
	valentine->addTownLocation(toVector3(-246.624, 777.583, 117.98), 121.131);
	valentine->addTownLocation(toVector3(-245.954, 685.097, 113.327), 117.901);
	valentine->addTownLocation(toVector3(-268.345, 651.291, 113.448), 307.575);
	valentine->addTownLocation(toVector3(-292.429, 734.007, 117.578), 22.9228);
	
	// Emerald ranch locations
	valentine->addTownLocation(toVector3(1426.09, 375.402, 89.2769), 236);
	valentine->addTownLocation(toVector3(1439.03, 359.503, 88.7072), 110);
	valentine->addTownLocation(toVector3(1453.64, 323.758, 89.4811), 130);
	
	valentine->addRoadLocation(toVector3(-3.59655, 258.348, 110.005));
	valentine->addRoadLocation(toVector3(-551.852, 241.873, 43.7083));
	valentine->addRoadLocation(toVector3(-690.214, 334.68, 91.3966));
	valentine->addRoadLocation(toVector3(867.913, 529.632, 105.629));// Good for emerald ranch as well
	valentine->addRoadLocation(toVector3(275.679, 194.249, 100.539));
	valentine->addRoadLocation(toVector3(737.33, 399.277, 108.57));// Good for emerald ranch as well
	valentine->addRoadLocation(toVector3(-320.702, -290.365, 91.2502)); //flantek station
	valentine->addRoadLocation(toVector3(126.021, 1102.32, 177.508));
	valentine->addRoadLocation(toVector3(-109.257, 1040.72, 155.171));
	valentine->addRoadLocation(toVector3(337.081, 1000.98, 189.671));
	valentine->addRoadLocation(toVector3(539.475, 1275.28, 182.144));
	valentine->addRoadLocation(toVector3(523.809, 881.895, 143.151));
	valentine->addRoadLocation(toVector3(874.315, 817.612, 116.473));
	valentine->addRoadLocation(toVector3(731.914, -138.756, 133.311));
	valentine->addRoadLocation(toVector3(481.292, 480.09, 110.045));
	valentine->addRoadLocation(toVector3(256.855, 470.31, 120.305));
	valentine->addRoadLocation(toVector3(1247.23, 219.136, 88.4058));
	valentine->addRoadLocation(toVector3(1410.03, 489.355, 87.301));
	valentine->addRoadLocation(toVector3(1575.92, 625.744, 95.6003));
	valentine->addRoadLocation(toVector3(-1046.95, 394.897, 52.6759));
	valentine->addRoadLocation(toVector3(-373.058, -27.0055, 42.701));
	valentine->addRoadLocation(toVector3(-471.538, -506.78, 57.2185));
	valentine->addRoadLocation(toVector3(468.46, 1.66757, 110.375));

	valentine->addWildernessCampingLocation(toVector3(-145.367, 256.394, 97.4866));
	valentine->addWildernessCampingLocation(toVector3(-661.155, 273.297, 90.8841));
	valentine->addWildernessCampingLocation(toVector3(-874.601, 185.966, 92.1477));
	valentine->addWildernessCampingLocation(toVector3(-997.163, 188.901, 86.0584));
	valentine->addWildernessCampingLocation(toVector3(-844.842, 457.312, 90.7082));
	valentine->addWildernessCampingLocation(toVector3(124.97, 975.713, 211.47));
	valentine->addWildernessCampingLocation(toVector3(291.66, 955.207, 199.083));
	valentine->addWildernessCampingLocation(toVector3(460.004, 1080.97, 196.957));
	valentine->addWildernessCampingLocation(toVector3(505.099, 1508.28, 173.645));
	valentine->addWildernessCampingLocation(toVector3(502.325, 861.413, 140.5));
	valentine->addWildernessCampingLocation(toVector3(917.735, 837.519, 115.629));
	valentine->addWildernessCampingLocation(toVector3(941.134, 707.72, 104.505));
	valentine->addWildernessCampingLocation(toVector3(840.884, 290.764, 117.637));
	valentine->addWildernessCampingLocation(toVector3(705.791, -41.1133, 157.577));
	valentine->addWildernessCampingLocation(toVector3(508.719, -233.383, 144.56));
	valentine->addWildernessCampingLocation(toVector3(212.091, -204.4, 131.601));
	valentine->addWildernessCampingLocation(toVector3(217.997, -43.6564, 103.084));
	valentine->addWildernessCampingLocation(toVector3(199.723, 314.163, 117.473));
	valentine->addWildernessCampingLocation(toVector3(723.906, 353.532, 110.012));
	valentine->addWildernessCampingLocation(toVector3(359.604, 471.057, 113.641));
	valentine->addWildernessCampingLocation(toVector3(56.2353, 479.142, 157.19));
	valentine->addWildernessCampingLocation(toVector3(125.676, 400.183, 135.821));
	valentine->addWildernessCampingLocation(toVector3(735.644, 151.327, 156.295));
	valentine->addWildernessCampingLocation(toVector3(1056.43, -7.66595, 86.6786));
	valentine->addWildernessCampingLocation(toVector3(1110.25, 85.7083, 86.2723));
	valentine->addWildernessCampingLocation(toVector3(1425.96, 564.714, 87.4452));
	valentine->addWildernessCampingLocation(toVector3(1389.13, 654.468, 88.2148));
	valentine->addWildernessCampingLocation(toVector3(1620.57, 345.705, 91.1813));
	valentine->addWildernessCampingLocation(toVector3(8.21019, 1010.86, 205.455));
	valentine->addWildernessCampingLocation(toVector3(-1138.48, 147.608, 50.2468));
	valentine->addWildernessCampingLocation(toVector3(-931.549, 106.425, 55.4949));
	valentine->addWildernessCampingLocation(toVector3(-744.667, 280.434, 94.8073));
	valentine->addWildernessCampingLocation(toVector3(-707.427, 457.981, 95.4101));
	valentine->addWildernessCampingLocation(toVector3(-607.46, -261.472, 40.6477));
	valentine->addWildernessCampingLocation(toVector3(-500.366, -574.581, 41.2516));
	valentine->addWildernessCampingLocation(toVector3(-31.1237, -563.639, 60.8188));
	valentine->addWildernessCampingLocation(toVector3(115.926, -534.338, 52.5348));
	valentine->addWildernessCampingLocation(toVector3(525.72, -486.919, 90.1189));
	valentine->addWildernessCampingLocation(toVector3(559.285, 169.523, 133.301));
	valentine->addWildernessCampingLocation(toVector3(1278.49, 551.944, 89.7247));

	// Grizzlies
	if (!ScriptSettings::getBool("DisableGrizzlies"))
	{
		valentine->addWildernessCampingLocation(toVector3(-1068.52, 2176.55, 356.601));
		valentine->addWildernessCampingLocation(toVector3(-967.042, 2181.84, 339.871));
		valentine->addWildernessCampingLocation(toVector3(-1438.82, 2246.19, 302.743));
		valentine->addWildernessCampingLocation(toVector3(-1675.93, 2046.5, 284.168));
		valentine->addWildernessCampingLocation(toVector3(-1909.05, 1814.68, 234.315));
		valentine->addWildernessCampingLocation(toVector3(-882.759, 1496.19, 245.988));
	}
	
	valentine->addOffroadLocation(toVector3(743.13, 74.8274, 150.109));// Good for emerald ranch as well
	valentine->addOffroadLocation(toVector3(397.131, 1054.06, 188.731));
	valentine->addOffroadLocation(toVector3(60.325, 313.7, 114.915));
	valentine->addOffroadLocation(toVector3(-335.464, 391.091, 53.8286));
	valentine->addOffroadLocation(toVector3(-78.5294, 1274.98, 169.374));
	valentine->addOffroadLocation(toVector3(-556.762, 650.693, 102.36));
	valentine->addOffroadLocation(toVector3(-542.393, 813.12, 96.1555));
	valentine->addOffroadLocation(toVector3(51.553, 1042.97, 196.686));
	valentine->addOffroadLocation(toVector3(210.171, 942.369, 197.281));
	valentine->addOffroadLocation(toVector3(716.988, 843.327, 122.239));
	valentine->addOffroadLocation(toVector3(143.601, 444.462, 132.429));
	valentine->addOffroadLocation(toVector3(-23.2251, 1472.28, 116.53));
	valentine->addOffroadLocation(toVector3(-275.541, -535.887, 44.3455));
	valentine->addOffroadLocation(toVector3(169.954, -487.065, 70.426));

	valentine->addSniperLocation(toPosition(513.548, 149.769, 134.447, 19.370733));

	valentine->addTrainTrackLocation(toVector3(138.295, -403.818, 89.9961), false);
	valentine->addTrainTrackLocation(toVector3(-155.984, -287.765, 92.593), false);
	valentine->addTrainTrackLocation(toVector3(49.7161, 20.3029, 102.605), true);
	valentine->addTrainTrackLocation(toVector3(4.79617, 273.884, 110.611), true);
	valentine->addTrainTrackLocation(toVector3(663.794, 699.399, 127.304), true);
	valentine->addTrainTrackLocation(toVector3(1064.68, 798.011, 106.312), false);

	valentine->addSaloonLocation(toVector3(-240.996, 769.99, 118.085));
	valentine->addSaloonLocation(toVector3(-307.937, 807.302, 118.98));

	valentine->addJailCellLocation(toVector3(-272.654, 811.582, 118.371), 94.467239);
	valentine->addJailCellLocation(toVector3(-271.714, 807.143, 118.371), 44.367867);

	// Downes ranch
	// -815.881, 353.935, 98.0971

	// Granger's hoggery
	//-72.9873, -400.9, 71.3955

	valentine->addLocalGangPedModel("g_m_m_uniduster_01");
	valentine->addLocalGangPedModel("g_m_m_uniduster_02");
	valentine->addLocalGangPedModel("g_m_m_uniduster_04");
	valentine->addLocalGangPedModel("g_m_m_uniduster_05");
	valentine->setLocalGangName("O'driscolls");

	return valentine;
}

MapArea* MapAreasFactory::createTumbleweed()
{
	MapArea* tumbleweed = new MapArea(MapAreas::Tumbleweed, "Tumbleweed", placesFactory->getByArea(MapAreas::Tumbleweed));

	tumbleweed->setTownCoords(toVector3(-5517.375, -2936.821, -2.219434));
	tumbleweed->setTownRadius(100);

	tumbleweed->addPostOfficeLocation(toVector3(-5230.35, -3468.04, -20.5129));

	tumbleweed->addTownLocation(toVector3(-5453, -2916.41, 0.856282), 135);
	tumbleweed->addTownLocation(toVector3(-5516.76, -2926.7, -2.29738), 180);
	tumbleweed->addTownLocation(toVector3(-5525.86, -2961.06, -1.52391), 314);
	tumbleweed->addTownLocation(toVector3(-5461.17, -2950.15, -1.18708), 15);

	tumbleweed->addSaloonLocation(toVector3(-5513.87, -2912.25, -1.75131));

	tumbleweed->addRoadLocation(toVector3(-4383.25, -3386.95, 34.2612));
	tumbleweed->addRoadLocation(toVector3(-4572.45, -2969.38, -17.8434));
	tumbleweed->addRoadLocation(toVector3(-5431.88, -3401.77, -21.8704));
	tumbleweed->addRoadLocation(toVector3(-5227.54, -3175.71, -18.0914));
	tumbleweed->addRoadLocation(toVector3(-5018.67, -3003.61, -19.1357));
	tumbleweed->addRoadLocation(toVector3(-5057.78, -2695.92, -12.3599));
	tumbleweed->addRoadLocation(toVector3(-5789.44, -2704.6, -14.4634));
	tumbleweed->addRoadLocation(toVector3(-5703.18, -2942.68, -13.431));
	tumbleweed->addRoadLocation(toVector3(-5331.28, -2611.15, -10.9119));
	tumbleweed->addRoadLocation(toVector3(-5510.65, -2649.43, -8.49587));
	tumbleweed->addRoadLocation(toVector3(-5484.39, -2417.81, -8.75752));
	tumbleweed->addRoadLocation(toVector3(-5370.41, -3776.22, -21.0628));
	tumbleweed->addRoadLocation(toVector3(-5015.42, -3926.28, 0.827134));
	tumbleweed->addRoadLocation(toVector3(-5520.82, -3299.51, -22.1728));

	// Armadillo locations
	//tumbleweed->addRoadLocation(toVector3(-2185.5, -2497.93, 65.1441));
	//tumbleweed->addRoadLocation(toVector3(-3051, -2669.83, 73.2263));
	//tumbleweed->addRoadLocation(toVector3(-3267.89, -2623.13, 6.2166));
	//tumbleweed->addRoadLocation(toVector3(-3829.12, -2870.2, -15.8906));

	tumbleweed->addOffroadLocation(toVector3(-5183.22, -2869.55, 2.9918));
	tumbleweed->addOffroadLocation(toVector3(-5297.25, -2837.46, -1.74137));
	tumbleweed->addOffroadLocation(toVector3(-5982.89, -3728.33, -24.3159));
	tumbleweed->addOffroadLocation(toVector3(-5831.62, -3446.92, -23.3214));
	tumbleweed->addOffroadLocation(toVector3(-5551.51, -3464.65, -20.0417));
	tumbleweed->addOffroadLocation(toVector3(-5501.45, -3575.94, -20.9592));

	tumbleweed->addWildernessCampingLocation(toVector3(-4465.91, -3143.23, 8.50659));
	tumbleweed->addWildernessCampingLocation(toVector3(-4408.64, -2987.34, -14.0281));
	tumbleweed->addWildernessCampingLocation(toVector3(-5136.35, -2593.53, -11.0935));
	tumbleweed->addWildernessCampingLocation(toVector3(-5241.21, -2515.57, -9.10351));
	tumbleweed->addWildernessCampingLocation(toVector3(-5054.95, -2630.55, -11.7837));
	tumbleweed->addWildernessCampingLocation(toVector3(-5533.56, -3422.4, -20.9175));
	tumbleweed->addWildernessCampingLocation(toVector3(-5816.2, -3143.65, 3.53014));
	tumbleweed->addWildernessCampingLocation(toVector3(-5455.03, -2564.07, -0.939084));
	tumbleweed->addWildernessCampingLocation(toVector3(-5024.52, -3488.39, 9.26334));
	tumbleweed->addWildernessCampingLocation(toVector3(-4678.12, -3637.21, 12.1347));
	tumbleweed->addWildernessCampingLocation(toVector3(-5640.23, -2579.35, -3.53606));
	tumbleweed->addWildernessCampingLocation(toVector3(-5170.4, -2455.24, 0.260172));
	tumbleweed->addWildernessCampingLocation(toVector3(-5364.94, -3583.1, -12.2401));
	tumbleweed->addWildernessCampingLocation(toVector3(-5740.4, -3535.14, -22.1484));
	tumbleweed->addWildernessCampingLocation(toVector3(-5338.25, -3831.61, -19.8976));
	tumbleweed->addWildernessCampingLocation(toVector3(-5021.41, -3897.12, -3.28035));
	tumbleweed->addWildernessCampingLocation(toVector3(-5059.07, -3758.62, -3.01194));
	tumbleweed->addWildernessCampingLocation(toVector3(-5237.73, -3582.13, -8.33994));
	tumbleweed->addWildernessCampingLocation(toVector3(-5469.63, -3521.1, -19.3359));
	tumbleweed->addWildernessCampingLocation(toVector3(-5720.01, -3296.22, -24.2048));
	tumbleweed->addWildernessCampingLocation(toVector3(-5465.98, -3736.47, -18.2157));

	tumbleweed->addTrainTrackLocation(toVector3(-5778.21, -2923.8, -15.2829), false);
	tumbleweed->addTrainTrackLocation(toVector3(-5815.1, -3231.55, -20.6216), false);
	tumbleweed->addTrainTrackLocation(toVector3(-5971.83, -3524.32, -23.1888), true);
	tumbleweed->addTrainTrackLocation(toVector3(-5725.3, -3624.86, -23.6321), true);
	tumbleweed->addTrainTrackLocation(toVector3(-5272.58, -3543.43, -22.2517), true);
	tumbleweed->addTrainTrackLocation(toVector3(-5191.55, -3266.21, -16.5916), true);
	tumbleweed->addTrainTrackLocation(toVector3(-5017.34, -3108.24, -17.0841), true);
	tumbleweed->addTrainTrackLocation(toVector3(-5025.59, -2678.47, -13.0712), false);
	tumbleweed->addTrainTrackLocation(toVector3(-5095.79, -2394.18, -8.60132), false);
	tumbleweed->addTrainTrackLocation(toVector3(-5367.99, -2355.58, -5.59784), false);

	tumbleweed->addLocalGangPedModel("G_M_M_UniBanditos_01");
	tumbleweed->setLocalGangName("Del Lobos");
	
	return tumbleweed;
}

MapArea* MapAreasFactory::createArmadillo()
{
	MapArea* armadillo = new MapArea(MapAreas::Armadillo, "Armadillo", placesFactory->getByArea(MapAreas::Armadillo));

	armadillo->setTownCoords(toVector3(-3665.947, -2612.442, -14.08434));
	armadillo->setTownRadius(100);

	armadillo->addPostOfficeLocation(toVector3(0, 0, 0));

	armadillo->addRoadLocation(toVector3(-2185.5, -2497.93, 65.1441));
	armadillo->addRoadLocation(toVector3(-3051, -2669.83, 73.2263));
	armadillo->addRoadLocation(toVector3(-3267.89, -2623.13, 6.2166));
	armadillo->addRoadLocation(toVector3(-3829.12, -2870.2, -15.8906));

	armadillo->addWildernessCampingLocation(toVector3(-2203.73, -2613.75, 71.2871));
	armadillo->addWildernessCampingLocation(toVector3(-2652.66, -2665.49, 70.603));
	armadillo->addWildernessCampingLocation(toVector3(-3404.94, -2772.85, -5.598));
	armadillo->addWildernessCampingLocation(toVector3(-3105.31, -2580.83, 70.8929));
	armadillo->addWildernessCampingLocation(toVector3(-3336.09, -3020.96, 2.76071));
	armadillo->addWildernessCampingLocation(toVector3(-3126.31, -3360.34, -16.0135));
	armadillo->addWildernessCampingLocation(toVector3(-3241.5, -3177.33, -8.28348));
	armadillo->addWildernessCampingLocation(toVector3(-3558.55, -3279.75, 6.36854));
	armadillo->addWildernessCampingLocation(toVector3(-3835.73, -3148.15, -13.0773));
	armadillo->addWildernessCampingLocation(toVector3(-4202.07, -2497.99, 3.6347));
	armadillo->addWildernessCampingLocation(toVector3(-3988.04, -2021.88, 1.95643));
	armadillo->addWildernessCampingLocation(toVector3(-3480.91, -2083.33, -1.25262));
	armadillo->addWildernessCampingLocation(toVector3(-3033.58, -2288.08, 46.9341));
	armadillo->addWildernessCampingLocation(toVector3(-2885.11, -2230.26, 67.5975));
	armadillo->addWildernessCampingLocation(toVector3(-3241, -3176.6, -9.19093));
	armadillo->addWildernessCampingLocation(toVector3(-3746.63, -3150.13, -7.08911));
	armadillo->addWildernessCampingLocation(toVector3(-3444.5, -2730.38, -5.08016));
	armadillo->addWildernessCampingLocation(toVector3(-3511.61, -2784.7, -4.2388));
	armadillo->addWildernessCampingLocation(toVector3(-3940.31, -2581.09, -9.50197));
	armadillo->addWildernessCampingLocation(toVector3(-4110.39, -2572.12, -2.05557));
	armadillo->addWildernessCampingLocation(toVector3(-4115.15, -2193.54, -3.57831));
	armadillo->addWildernessCampingLocation(toVector3(-1900.61, -2393.32, 49.0833));
	armadillo->addWildernessCampingLocation(toVector3(-1784.73, -2402.47, 42.3711));
	armadillo->addWildernessCampingLocation(toVector3(-1903.23, -2569.24, 66.144));
	armadillo->addWildernessCampingLocation(toVector3(-1897.93, -2677.7, 65.1451));

	armadillo->addOffroadLocation(toVector3(-3661.25, -3309.48, -0.930605));
	armadillo->addOffroadLocation(toVector3(-3321.11, -3086.23, 1.19869));
	armadillo->addOffroadLocation(toVector3(-3088.68, -3158.81, 0.218498));
	armadillo->addOffroadLocation(toVector3(-3936.37, -2338.51, -10.0636));
	armadillo->addOffroadLocation(toVector3(-4133.3, -2300.92, -2.06132));
	armadillo->addOffroadLocation(toVector3(-3482.72, -2239.72, -3.57368));
	armadillo->addOffroadLocation(toVector3(-3132.78, -2431.19, 24.1322));
	armadillo->addOffroadLocation(toVector3(-4043.67, -2653.27, -5.73923));
	armadillo->addOffroadLocation(toVector3(-4303.33, -2438.04, 9.33544));
	armadillo->addOffroadLocation(toVector3(-1763.1, -2461.59, 42.8502));
	armadillo->addOffroadLocation(toVector3(-1835.61, -2588.63, 63.57));
	armadillo->addOffroadLocation(toVector3(-1765, -2686.71, 65.641));

	armadillo->addTownLocation(toVector3(-3718.14, -2610.48, -13.3694), 317.822);
	armadillo->addTownLocation(toVector3(-3647.23, -2608.71, -13.9574), 115);
	armadillo->addTownLocation(toVector3(-3645.56, -2636.43, -13.9051), 101);
	armadillo->addTownLocation(toVector3(-3664.19, -2581.2, -13.6857), 345);

	armadillo->addTrainTrackLocation(toVector3(-2300.26, -2501.63, 61.8192), false);
	armadillo->addTrainTrackLocation(toVector3(-2520.75, -2237.98, 73.0209), false);
	armadillo->addTrainTrackLocation(toVector3(-3760.73, -2435.59, -11.9616), false);
	armadillo->addTrainTrackLocation(toVector3(-3854.28, -2833.88, -15.2828), false);
	armadillo->addTrainTrackLocation(toVector3(-4130.93, -3058.06, -8.03088), false);
	armadillo->addTrainTrackLocation(toVector3(-3813.01, -1902.1, 30.4352), false);
	armadillo->addTrainTrackLocation(toVector3(-3628.99, -1807.14, 45.2305), false);

	armadillo->addLocalGangPedModel("G_M_M_UniBanditos_01");
	armadillo->setLocalGangName("Del Lobos");

	return armadillo;
}

MapArea* MapAreasFactory::createSaintDenis()
{
	MapArea* saintDenis = new MapArea(MapAreas::SaintDenis, "Saint Denis", placesFactory->getByArea(MapAreas::SaintDenis));

	saintDenis->setTownCoords(toVector3(2328.742, -1096.286, 44.7446));
	saintDenis->setTownRadius(450);

	saintDenis->addPostOfficeLocation(toVector3(2749.14, -1400.79, 46.1927));

	saintDenis->addTownLocation(toVector3(2365.03, -1124.68, 46.3264), 220);
	saintDenis->addTownLocation(toVector3(2425.86, -1222.82, 45.8817), 266.252);
	saintDenis->addTownLocation(toVector3(2403.66, -1518.87, 46.0503), 178.549);
	saintDenis->addTownLocation(toVector3(2562.08, -1467.8, 46.2585), 271.59);
	saintDenis->addTownLocation(toVector3(2604.94, -1333.96, 48.529), 311.781);
	saintDenis->addTownLocation(toVector3(2685.58, -1412.35, 46.6108), 355);
	saintDenis->addTownLocation(toVector3(2611.85, -1417.79, 46.2834), 156);
	saintDenis->addTownLocation(toVector3(2531.92, -1247.78, 50.058), 9);
	saintDenis->addTownLocation(toVector3(2564.97, -1201.02, 53.9089), 99.5);
	saintDenis->addTownLocation(toVector3(2695.43, -1213.44, 52.38), 277.475);
	saintDenis->addTownLocation(toVector3(2761.99, -1189.03, 48.9113), 150);
	saintDenis->addTownLocation(toVector3(2817.6, -1163.24, 47.4364), 45.5);
	saintDenis->addTownLocation(toVector3(2717.38, -1239.96, 50.0062), 220);
	saintDenis->addTownLocation(toVector3(2651.38, -1264.27, 52.2697), 186);

	saintDenis->addSaloonLocation(toVector3(2634.01, -1225.79, 53.3804));
	saintDenis->addSaloonLocation(toVector3(2794.42, -1168.74, 47.928));

	saintDenis->addJailCellLocation(toVector3(-272.654, 811.582, 118.371), 94.467239);
	saintDenis->addJailCellLocation(toVector3(2499.75, -1311.06, 47.9537), 30);

	saintDenis->addRoadLocation(toVector3(2410.63, -1209.03, 45.7719));
	saintDenis->addRoadLocation(toVector3(2576.02, -1131.46, 51.1221));
	saintDenis->addRoadLocation(toVector3(2651.83, -1048.29, 46.3205));
	saintDenis->addRoadLocation(toVector3(2698.22, -1252.84, 50.3217));
	saintDenis->addRoadLocation(toVector3(2788.32, -1258.63, 47.5313));
	saintDenis->addRoadLocation(toVector3(2785.41, -1331.27, 46.3874));
	saintDenis->addRoadLocation(toVector3(2696.69, -1388.83, 46.5137));
	saintDenis->addRoadLocation(toVector3(2575.55, -1359.54, 46.2705));
	saintDenis->addRoadLocation(toVector3(2388.18, -1323.49, 45.4888));
	saintDenis->addRoadLocation(toVector3(2348.35, -1120.55, 46.4179));
	saintDenis->addRoadLocation(toVector3(2233.6, -1013.25, 45.1071));

	saintDenis->addTrainTrackLocation(toVector3(2565.71, -1481.82, 46.2255), false);
	saintDenis->addTrainTrackLocation(toVector3(2787.16, -1395.75, 46.1335), false);
	saintDenis->addTrainTrackLocation(toVector3(2897.89, -1198.08, 46.0307), false);
	//saintDenis->addTrainTrackLocation(toVector3(2811.47, -955.048, 43.8146), false);

	saintDenis->addWildernessCampingLocation(toVector3(1833.76, -1070.07, 40.7458));
	saintDenis->addWildernessCampingLocation(toVector3(1749.88, -920.909, 40.036));
	saintDenis->addWildernessCampingLocation(toVector3(1736.71, -693.168, 40.4001));
	saintDenis->addWildernessCampingLocation(toVector3(2281.35, -867.252, 40.5534));
	saintDenis->addWildernessCampingLocation(toVector3(2394.53, -762.233, 41.1388));
	saintDenis->addWildernessCampingLocation(toVector3(2711.41, -448.69, 40.7706));
	saintDenis->addWildernessCampingLocation(toVector3(2865.87, -220.298, 41.2289));

	saintDenis->addLocalGangPedModel("g_m_o_uniexconfeds_01");
	saintDenis->addLocalGangPedModel("g_m_y_uniexconfeds_01");
	saintDenis->setLocalGangName("Lemoyne Raiders");

	return saintDenis;
}

MapArea* MapAreasFactory::createAnnesburg()
{
	MapArea* annesburg = new MapArea(MapAreas::Annesburg, "Annesburg", placesFactory->getByArea(MapAreas::Annesburg));

	annesburg->setTownCoords(toVector3(2904.366, 1248.808, 44.87448));
	annesburg->setTownRadius(200);

	annesburg->addPostOfficeLocation(toVector3(2985.22, 568.669, 44.6279));
	annesburg->addPostOfficeLocation(toVector3(2931.73, 1283.24, 44.6528));

	annesburg->addSaloonLocation(toVector3(2944.27, 521.257, 45.3776));

	annesburg->addLocalGangPedModel("G_M_M_UniInbred_01");

	// Butcher creek
	//annesburg->addQuestGiverLocation(toVector3(2548.02, 754.276, 76.8743), 290);
	//annesburg->addQuestGiverLocation(toVector3(2535.48, 779.902, 75.7498), 50);
	//annesburg->addQuestGiverLocation(toVector3(2545.5, 845.896, 80.4114), 170);
	//annesburg->addQuestGiverLocation(toVector3(2587.57, 834.197, 84.1837), 35);
	//annesburg->addQuestGiverLocation(toVector3(2956.67, 559.033, 44.8607), 255);

	// Van horn
	annesburg->addTownLocation(toVector3(2935.2, 569.433, 44.8467), 324);
	annesburg->addTownLocation(toVector3(3003.46, 562.224, 44.4523), 187);
	annesburg->addTownLocation(toVector3(2997.56, 478.051, 42.0424), 100);
	annesburg->addTownLocation(toVector3(2971.27, 537.798, 43.5114), 83);

	// Annesburg
	annesburg->addTownLocation(toVector3(2903.23, 1442.13, 57.7138), 50);
	annesburg->addTownLocation(toVector3(2903.42, 1326.94, 48.1328), 248);
	annesburg->addTownLocation(toVector3(2912.48, 1344.59, 48.1177), 203);
	annesburg->addTownLocation(toVector3(2908.57, 1355.14, 51.7569), 271);
	annesburg->addTownLocation(toVector3(2904.62, 1371.27, 54.532), 238);
	annesburg->addTownLocation(toVector3(2861.85, 1374.01, 66.0807), 228);
	annesburg->addTownLocation(toVector3(2855.03, 1360.72, 64.7981), 228);

	annesburg->addRoadLocation(toVector3(1996.07, 198.181, 80.4));
	annesburg->addRoadLocation(toVector3(2606.01, 311.124, 68.429));
	annesburg->addRoadLocation(toVector3(2584.78, 572.778, 74.8153));
	annesburg->addRoadLocation(toVector3(2216.79, 806.363, 108.037));
	annesburg->addRoadLocation(toVector3(2249.06, 603.308, 90.9739));
	annesburg->addRoadLocation(toVector3(2871.45, 772.655, 53.0788));
	annesburg->addRoadLocation(toVector3(2839.92, 610.89, 64.3119));
	annesburg->addRoadLocation(toVector3(2149.81, 1671.2, 123.745));
	annesburg->addRoadLocation(toVector3(2766.54, 1355.61, 86.1645));

	annesburg->addWildernessCampingLocation(toVector3(2030.75, 128.785, 80.775));
	annesburg->addWildernessCampingLocation(toVector3(2346.46, 332.365, 56.3566));
	annesburg->addWildernessCampingLocation(toVector3(2482.92, 109.386, 44.1429));
	annesburg->addWildernessCampingLocation(toVector3(2426.78, 777.403, 68.4336));
	annesburg->addWildernessCampingLocation(toVector3(2103.37, 812.081, 156.805));
	annesburg->addWildernessCampingLocation(toVector3(2046.95, 708.482, 169.725));
	annesburg->addWildernessCampingLocation(toVector3(1986.3, 604.758, 156.545));
	annesburg->addWildernessCampingLocation(toVector3(2758.72, 720.328, 80.1201));
	annesburg->addWildernessCampingLocation(toVector3(2810.95, 364.58, 51.491));
	annesburg->addWildernessCampingLocation(toVector3(2392.8, 1022.22, 90.4311));
	annesburg->addWildernessCampingLocation(toVector3(2300.85, 1049.54, 116.537));
	annesburg->addWildernessCampingLocation(toVector3(2697.49, 1676.37, 148.402));
	annesburg->addWildernessCampingLocation(toVector3(2853.18, 1647.55, 126.734));
	annesburg->addWildernessCampingLocation(toVector3(2885.9, 1982.91, 159.816));
	annesburg->addWildernessCampingLocation(toVector3(2871.99, 2215.5, 157.574));
	annesburg->addWildernessCampingLocation(toVector3(2621.51, 2103.55, 174.045));
	annesburg->addWildernessCampingLocation(toVector3(2470.62, 1754.02, 86.7986));
	annesburg->addWildernessCampingLocation(toVector3(2608.51, 1461, 82.05));
	annesburg->addWildernessCampingLocation(toVector3(2892.31, 1674.33, 135.455));
	annesburg->addWildernessCampingLocation(toVector3(2754.98, 1944.98, 160.036));
	annesburg->addWildernessCampingLocation(toVector3(2766.03, 2296.96, 157.609));
	annesburg->addWildernessCampingLocation(toVector3(2334.51, 1980.22, 164.682));
	
	// Ambarino
	annesburg->addWildernessCampingLocation(toVector3(1600.32, 2130.17, 317.863));
	annesburg->addWildernessCampingLocation(toVector3(1882.51, 2052.05, 270.241));
	annesburg->addWildernessCampingLocation(toVector3(1956.14, 1881.69, 249.608));
	annesburg->addWildernessCampingLocation(toVector3(1557.6, 1375.99, 145.179));
	annesburg->addWildernessCampingLocation(toVector3(711.664, 1868.5, 238.444));

	annesburg->addOffroadLocation(toVector3(1830.4, 230.858, 84.4285));
	annesburg->addOffroadLocation(toVector3(2282.62, 328.178, 47.0641));
	annesburg->addOffroadLocation(toVector3(2544.85, 251.401, 69.1723));
	annesburg->addOffroadLocation(toVector3(2438.08, 861.787, 72.8739));
	annesburg->addOffroadLocation(toVector3(2029.27, 694.666, 170.669));
	annesburg->addOffroadLocation(toVector3(2661.64, 893.712, 88.9398));
	annesburg->addOffroadLocation(toVector3(2789, 807.203, 69.917));
	annesburg->addOffroadLocation(toVector3(2562.07, 989.944, 117.282));
	annesburg->addOffroadLocation(toVector3(2207.51, 1134.7, 139.327));
	annesburg->addOffroadLocation(toVector3(2735.28, 1216.69, 94.5737));
	annesburg->addOffroadLocation(toVector3(2708.69, 1553.55, 135.781));
	annesburg->addOffroadLocation(toVector3(2841.43, 1630.82, 120.367));
	annesburg->addOffroadLocation(toVector3(2910.87, 1828.48, 108.531));
	annesburg->addOffroadLocation(toVector3(2845.61, 2100.23, 159.995));
	annesburg->addOffroadLocation(toVector3(2726.57, 2261.14, 157.639));
	annesburg->addOffroadLocation(toVector3(2492.64, 2179.38, 172.149));
	annesburg->addOffroadLocation(toVector3(2392.06, 1918.36, 133.82));
	annesburg->addOffroadLocation(toVector3(2599.02, 1572.21, 95.1943));
	annesburg->addOffroadLocation(toVector3(2599.02, 1572.21, 95.1943));
	annesburg->addOffroadLocation(toVector3(2657.69, 697.965, 79.1139));

	annesburg->addTrainTrackLocation(toVector3(2769.88, 375.054, 54.108), false);
	annesburg->addTrainTrackLocation(toVector3(2910.06, 749.63, 50.9415), false);
	annesburg->addTrainTrackLocation(toVector3(2858.84, 1176.61, 44.652), false);
	annesburg->addTrainTrackLocation(toVector3(3013.59, 1448.71, 45.9993), false);
	annesburg->addTrainTrackLocation(toVector3(3104.81, 1819.77, 103.092), true);
	annesburg->addTrainTrackLocation(toVector3(2904.76, 2041.45, 151.763), true);
	annesburg->addTrainTrackLocation(toVector3(2323.42, 2015.42, 176.925), true);
	annesburg->addTrainTrackLocation(toVector3(2526.44, 2167.2, 166.389), true);

	// Strange hut near van horn (ranch)
	// inside: 2716.91, 710.304, 79.5403
	// outside 1: 2696.5, 709.65, 76.852
	// outside 2: 2722.48, 703.792, 78.2882
	// Chair model: -1510839859
	// Bed model: 737690157

	// Black baslam rise (cabin)
	// inside: 2836.46, 1684.92, 129.681
	// chair model: -1025740342
	// porch: 
	// stool: -1937484496, 2841.99, 1685.64, 129.36
	// scouting position (rock behind): 2806.44, 1678.55, 139.914
	// parking spot: 2837.17, 1695.79, 130.141, heading: 274.874

	// Hermit hut:
	// inside: 3027.82, 1780.53, 84.1272
	// chairs inside: -876203942, -1510839859, -1936130724
	// porch: 3027.57, 1773.42, 84.1684, chair: -1443906703

	// Mine locations:
	// guard model: -1842133876
	// office: chair: 70472470, 2920.47, 1379.14, 56.2244, heading: 268
	// 2936.19, 1384.29, 51.3229, heading: 220.391
	// 2935.87, 1386.34, 57.8306, heading: 180.11
	// 2892.12, 1401.76, 64.9407, heading: 184.748
	// 2789.74, 1339.43, 71.3096 - mine enterace: 321

	// MacLeans House
	// a_m_m_rancher_01
	// 2244.77, -137.912, 46.7928

	annesburg->setLocalGangName("Murfree Brood");
	
	return annesburg;
}

MapArea* MapAreasFactory::createStrawberry()
{
	MapArea* strawberry = new MapArea(MapAreas::Strawberry, "Strawberry", placesFactory->getByArea(MapAreas::Strawberry));

	strawberry->setTownCoords(toVector3(-1731.426, -412.8995, 154.8678));
	strawberry->setTownRadius(100);

	strawberry->addTownLocation(toVector3(-1774.89, -404.685, 156.469), 298);
	strawberry->addTownLocation(toVector3(-1779.55, -374.42, 159.91), 201);
	strawberry->addTownLocation(toVector3(-1831.66, -415.426, 161.15), 286);
	strawberry->addTownLocation(toVector3(-1771.29, -429.388, 155.219), 68);

	strawberry->addJailCellLocation(toVector3(-1812.43, -355.92, 160.462), 62);

	strawberry->addPostOfficeLocation(toVector3(-1765.09, -383.61, 157.737));
	strawberry->addPostOfficeLocation(toVector3(-1095.53, -575.422, 82.4099));
	strawberry->addPostOfficeLocation(toVector3(-1298.77, 401.872, 95.3839));

	strawberry->addRoadLocation(toVector3(-1305.48, 83.0963, 70.9794));
	strawberry->addRoadLocation(toVector3(-1627.44, 251.143, 105.568));
	strawberry->addRoadLocation(toVector3(-1745.87, 390.156, 110.331));
	strawberry->addRoadLocation(toVector3(-2475.32, 595.874, 130.795));
	strawberry->addRoadLocation(toVector3(-2700.06, 47.965, 162.372));
	strawberry->addRoadLocation(toVector3(-2759.83, -163.682, 152.075));
	strawberry->addRoadLocation(toVector3(-1965.32, -572.565, 140.825));
	strawberry->addRoadLocation(toVector3(-1836.82, -774.483, 105.298));
	strawberry->addRoadLocation(toVector3(-1016.62, -102.56, 45.0627));
	strawberry->addRoadLocation(toVector3(-874.383, -341.147, 44.0197));

	strawberry->addOffroadLocation(toVector3(-1720.74, -213.506, 177.924));
	strawberry->addOffroadLocation(toVector3(-1662.1, -141.21, 168.852));
	strawberry->addOffroadLocation(toVector3(-1383.27, -145.872, 95.5328));
	strawberry->addOffroadLocation(toVector3(-1940.76, 630.286, 116.116));
	strawberry->addOffroadLocation(toVector3(-2455.89, -40.8411, 184.501));
	strawberry->addOffroadLocation(toVector3(-2209.64, -199.687, 184.224));
	strawberry->addOffroadLocation(toVector3(-1649.51, -925.086, 96.7719));
	strawberry->addOffroadLocation(toVector3(-1759.94, -698.366, 128.271));
	strawberry->addOffroadLocation(toVector3(-1647.58, -561.807, 139.763));
	strawberry->addOffroadLocation(toVector3(-1436.78, -358.508, 111.737));
	strawberry->addOffroadLocation(toVector3(-1280.66, -300.345, 100.309));
	strawberry->addOffroadLocation(toVector3(-1059.53, -590.889, 81.5675));
	strawberry->addOffroadLocation(toVector3(-1021.76, -703.134, 66.6907));
	strawberry->addOffroadLocation(toVector3(-802.477, -805.755, 51.4228));
	strawberry->addOffroadLocation(toVector3(-1191.04, -722.206, 71.8886));
	strawberry->addOffroadLocation(toVector3(-1401.64, -850.129, 83.537));

	strawberry->addWildernessCampingLocation(toVector3(-1489.3, -139.891, 120.881));
	strawberry->addWildernessCampingLocation(toVector3(-1286.39, 97.8282, 71.5427));
	strawberry->addWildernessCampingLocation(toVector3(-1755.05, 436.895, 110.981));
	strawberry->addWildernessCampingLocation(toVector3(-1855.2, 515.211, 114.964));
	strawberry->addWildernessCampingLocation(toVector3(-2151.34, 574.237, 117.186));
	strawberry->addWildernessCampingLocation(toVector3(-2260.91, 547.342, 119.518));
	strawberry->addWildernessCampingLocation(toVector3(-2534.44, 575.546, 139.643));
	strawberry->addWildernessCampingLocation(toVector3(-2552.04, -94.6294, 165.91));
	strawberry->addWildernessCampingLocation(toVector3(-2407.98, -103.233, 220.82));
	strawberry->addWildernessCampingLocation(toVector3(-2361.49, -349.114, 145.369));
	strawberry->addWildernessCampingLocation(toVector3(-2571.66, -229.022, 169.784));
	strawberry->addWildernessCampingLocation(toVector3(-2672.18, -280.72, 158.056));
	strawberry->addWildernessCampingLocation(toVector3(-2791.42, -109.878, 155.755));
	strawberry->addWildernessCampingLocation(toVector3(-2647.49, -99.07, 158.82));
	strawberry->addWildernessCampingLocation(toVector3(-2198.97, -478.749, 155.152));
	strawberry->addWildernessCampingLocation(toVector3(-2038.77, -567.01, 139.151));
	strawberry->addWildernessCampingLocation(toVector3(-1912, -796.348, 118.571));
	strawberry->addWildernessCampingLocation(toVector3(-1799.76, -903.454, 104.384));
	strawberry->addWildernessCampingLocation(toVector3(-1922.98, -1073.54, 75.1244));
	strawberry->addWildernessCampingLocation(toVector3(-1761.98, -1016.79, 114.878));
	strawberry->addWildernessCampingLocation(toVector3(-1588.6, -722.943, 133.476));
	strawberry->addWildernessCampingLocation(toVector3(-1598.79, -625.423, 136.249));
	strawberry->addWildernessCampingLocation(toVector3(-1518.04, -440.696, 154.983));
	strawberry->addWildernessCampingLocation(toVector3(-1504.3, -379.033, 134.016));
	strawberry->addWildernessCampingLocation(toVector3(-1337.15, -350.957, 108.619));
	strawberry->addWildernessCampingLocation(toVector3(-1248.97, -105.207, 83.4982));
	strawberry->addWildernessCampingLocation(toVector3(-871.423, -92.9503, 72.1008));
	strawberry->addWildernessCampingLocation(toVector3(-717.645, -272.192, 40.8668));
	strawberry->addWildernessCampingLocation(toVector3(-1278.57, -478.082, 114.104));
	strawberry->addWildernessCampingLocation(toVector3(-809.795, -854.479, 53.2799));
	strawberry->addWildernessCampingLocation(toVector3(-1446.7, 102.418, 89.5185));

	strawberry->addTrainTrackLocation(toVector3(-1058.18, -609.794, 76.8099), false);
	strawberry->addTrainTrackLocation(toVector3(-1302.03, -315.808, 100.093), false);
	strawberry->addTrainTrackLocation(toVector3(-1491.48, 20.4975, 101.723), true);
	strawberry->addTrainTrackLocation(toVector3(-1475.33, 278.158, 100.345), true);
	strawberry->addTrainTrackLocation(toVector3(-1292.3, 438.406, 93.38095), true);
	strawberry->addTrainTrackLocation(toVector3(-1037.79, 630.62, 92.6613), true);

	strawberry->addLocalGangPedModel("g_m_m_uniduster_01");
	strawberry->addLocalGangPedModel("g_m_m_uniduster_02");
	strawberry->addLocalGangPedModel("g_m_m_uniduster_04");
	strawberry->addLocalGangPedModel("g_m_m_uniduster_05");

	// Hanging dog ranch
	// -2211.29, 714.621, 121.436

	// Tree house - hunter's hut
	// -2459.66, 840.687, 146.381
	// Bed model: -1775373677
	// chair model: -876203942
	// porch chair model: -1443906703
	
	// Bounty hunters camp:
	// sniper position: -1503.13, -779.794, 110.696, heading: 220
	// camp fire: -1493.39, -778.947, 103.154
	// porch: -1504.51, -792.41, 103.446, heading: 330

	strawberry->setLocalGangName("O'driscolls");

	return strawberry;
}