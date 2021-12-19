#include "Main.h"

PlacesFactory::PlacesFactory()
{
	placesCount = 0;

	fillArmadillo();
	fillTumbleweed();
	fillBlackwater();
	fillStrawberry();
	fillValentine();
	fillRhodes();
	fillStDenis();
	fillAnnesburg();
}

vector<Place*> PlacesFactory::getByArea(MapAreas area)
{
	if (cache.find(area) == cache.end())
	{
		cache[area] = {};
	}

	return cache[area];
}

int PlacesFactory::nextId()
{
	int id = placesCount;
	placesCount++;
	return id;
}

void PlacesFactory::fillAnnesburg()
{
	MapAreas area = MapAreas::Annesburg;

	Place* macleansHouse = new Place(nextId(), area, toVector3(2244.77, -137.912, 46.7928), 70, PlaceType::Ranch, "MacLean's House");
	macleansHouse->setTypicalPedModel("a_m_m_rancher_01");	
	
	Place* butcherCreekFarm = new Place(nextId(), area, toVector3(2706.4, 708.593, 78.0256), 70, PlaceType::Ranch, "Butcher Creek's Farm");
	butcherCreekFarm->setTypicalPedModel("a_m_m_rancher_01");

	Place* manitoGlade = new Place(nextId(), area, toVector3(3026.44, 1777.98, 84.1283), 60, PlaceType::Ranch, "Manito Glade");
	manitoGlade->setTypicalPedModel("cs_tinyhermit");

	Place* osmanGrove = new Place(nextId(), area, toVector3(1888.86, 300.964, 77.0615), 60, PlaceType::Shack, "Osman Grove");
	osmanGrove->addScenarioPoint(osmanGrove->getCoords(), 10, -1443906703, "PROP_HUMAN_SEAT_CHAIR_TABLE_DRINKING_BADASS_BEER", toVector3(0, 0, 0.5), 180);
	osmanGrove->addScenarioPoint(toVector3(1898.65, 295.165, 75.7811), 2, 1229219138, "PROP_HUMAN_SEAT_BENCH_TIRED", toVector3(0, 0, 0.5), 0);
	osmanGrove->addScenarioPoint(toVector3(1897.12, 297.832, 75.9793), 2, -1937484496, "PROP_CAMP_SEAT_CHAIR_STEW", toVector3(0, 0, 0.5), 180);
	osmanGrove->addScenarioPoint(toVector3(1894.92, 299.828, 76.9728), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 296);
	osmanGrove->addScenarioPoint(toVector3(1876.5, 288.787, 75.7943), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 120.2);
	osmanGrove->addScenarioPoint(toVector3(1893.13, 288.248, 76.4853), "WORLD_HUMAN_LEAN_BACK_RAILING_DRINKING", 194.2);

	//Place* marthasCabin = new Place(nextId(), area, toVector3(1983.2, 1191.46, 171.403), 45, PlaceType::Shack, "Martha's Swain Cabin");	

	Place* reedCottage = new Place(nextId(), area, toVector3(2836.8, 1685.39, 129.684), 45, PlaceType::Shack, "Reed Cottage");
	reedCottage->addScenarioPoint(reedCottage->getCoords(), 15, -1025740342, "PROP_CAMP_SEAT_CHAIR_STEW", toVector3(0, 0, 0.5), 180);
	reedCottage->addScenarioPoint(reedCottage->getCoords(), 15, -1937484496, "PROP_HUMAN_SEAT_CHAIR_KNIFE_BADASS", toVector3(0, 0, 0.5), 90);
	reedCottage->addScenarioPoint(toVector3(2837.84, 1688.2, 129.706), "WORLD_HUMAN_LEAN_TABLE_SHARPEN_KNIFE", 283);
	reedCottage->addScenarioPoint(toVector3(2836.93, 1680.24, 129.431), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 176);
	reedCottage->addScenarioPoint(toVector3(2836.63, 1677.44, 129.456), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 34.6);
	reedCottage->addScenarioPoint(toVector3(2839.96, 1692.11, 129.648), "WORLD_HUMAN_LEAN_BACK_RAILING_DRINKING", 355);

	Place* deerCottage = new Place(nextId(), area, toVector3(2625.21, 1694.32, 115.688), 45, PlaceType::Shack, "Black Baslam Rise");
	deerCottage->addScenarioPoint(deerCottage->getCoords(), 15, -895862876, "PROP_HUMAN_SEAT_CHAIR_DRINKING", toVector3(0, 0, 0.5), 180);
	deerCottage->addScenarioPoint(deerCottage->getCoords(), 15, 1489783104, "PROP_CAMP_SEAT_CHAIR_TABLE_STEW", toVector3(0, 0, 0.5), 180);
	deerCottage->addScenarioPoint(toVector3(2635.56, 1687.25, 115.574), 15, -1937484496, "PROP_HUMAN_SEAT_CHAIR_KNIFE_BADASS", toVector3(0, 0, 0.5), 90);
	deerCottage->addScenarioPoint(toVector3(2625.28, 1696.66, 115.691), "WORLD_HUMAN_LEAN_TABLE_SHARPEN_KNIFE", 166.16);
	deerCottage->addScenarioPoint(toVector3(2642.73, 1693.88, 117.239), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 56.3);
	deerCottage->addScenarioPoint(toVector3(2624.67, 1701.41, 114.467), "WORLD_HUMAN_LEAN_WALL_LEFT", 90.2);

	Place* abandonedTradingPost = new Place(nextId(), area, toVector3(2450.51, 2099.05, 173.269), 45, PlaceType::Shack, "Abandoned Trading Post");
	abandonedTradingPost->addScenarioPoint(abandonedTradingPost->getCoords(), 10, 1749359648, "PROP_HUMAN_SEAT_BENCH_TIRED", toVector3(0, 0, 0.5), 0);
	abandonedTradingPost->addScenarioPoint(toVector3(2451.29, 2098.08, 173.265), "WORLD_HUMAN_SIT_GROUND_DRINK_DRUNK", 53.7);
	abandonedTradingPost->addScenarioPoint(toVector3(2451.74, 2099.94, 173.269), "WORLD_HUMAN_LEAN_TABLE_SHARPEN_KNIFE", 134.5);
	abandonedTradingPost->addScenarioPoint(toVector3(2456.73, 2096.38, 171.657), "WORLD_HUMAN_SEAT_STEPS", 223.4);
	abandonedTradingPost->addScenarioPoint(toVector3(2448.59, 2094.38, 172.919), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 120.3);
	abandonedTradingPost->addScenarioPoint(toVector3(2446.37, 2092.4, 172.879), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 317.6);

	Place* theLoft = new Place(nextId(), area, toVector3(1934.2, 1946.19, 266.103), 60, PlaceType::Shack, "The Loft");
	theLoft->addScenarioPoint(theLoft->getCoords(), 15, -1025740342, "PROP_CAMP_SEAT_CHAIR_STEW", toVector3(0, 0, 0.5), 180);
	theLoft->addScenarioPoint(toVector3(1933.52, 1968.46, 262.777), 2, 1872659725, "WORLD_HUMAN_SLEEP_GROUND_ARM", toVector3(0, 0, 1), 0);
	theLoft->addScenarioPoint(toVector3(1929.13, 1968.68, 263.52), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 193);
	theLoft->addScenarioPoint(toVector3(1945.46, 1945.13, 265.64), "WORLD_HUMAN_LEAN_WALL_LEFT", 233.65);
	theLoft->addScenarioPoint(toVector3(1932.2, 1943.22, 273.346), "WORLD_HUMAN_GUARD_MILITARY", 177.76);
	theLoft->addScenarioPoint(toVector3(1928.91, 1945.74, 265.802), "WORLD_HUMAN_LEAN_BACK_RAILING_DRINKING", 80.16);
	theLoft->addScenarioPoint(toVector3(1930.69, 1953.51, 264.457), "WORLD_HUMAN_SEAT_STEPS", 21.32);
	theLoft->addScenarioPoint(toVector3(1925.22, 1966.57, 263.366), "WORLD_HUMAN_SIT_GROUND_DRINK_DRUNK", 253);

	cache[area] = {
		macleansHouse,
		butcherCreekFarm,
		manitoGlade,
		osmanGrove,
		reedCottage,
		deerCottage,
		abandonedTradingPost,
		theLoft
	};
}

void PlacesFactory::fillStDenis()
{
	MapAreas area = MapAreas::SaintDenis;

	Place* trappersCabin = new Place(nextId(), area, toVector3(2103.35, -283.935, 43.0005), 55, PlaceType::Shack, "Trapper's Cabin");
	trappersCabin->setTypicalPedModel("g_m_y_uniexconfeds_01");
	trappersCabin->addScenarioPoint(toVector3(2112.25, -292.327, 41.839), "WORLD_HUMAN_LEAN_BACK_WHITTLE", 346.6);
	trappersCabin->addScenarioPoint(toVector3(2103.7, -290.9, 42.9863), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 168.5);
	trappersCabin->addScenarioPoint(toVector3(2106.76, -287.506, 42.8505), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 277.5);
	trappersCabin->addScenarioPoint(toVector3(2105.2, -278.975, 42.9865), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 354);

	Place* copperheadLanding = new Place(nextId(), area, toVector3(2878.81, -255.577, 42.5763), 50, PlaceType::Shack, "Copperhead Landing");
	copperheadLanding->setTypicalPedModel("g_m_y_uniexconfeds_01");
	copperheadLanding->addScenarioPoint(copperheadLanding->getCoords(), 15, -2070273503, "PROP_HUMAN_SEAT_BENCH_TIRED", toVector3(0, 0, 0.5), 180);
	copperheadLanding->addScenarioPoint(toVector3(2871.07, -256.091, 42.2888), "WORLD_HUMAN_LEAN_BACK_RAILING_DRINKING", 14.5);
	copperheadLanding->addScenarioPoint(toVector3(2887.25, -256.438, 42.4156), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 158.8);
	copperheadLanding->addScenarioPoint(toVector3(2886.38, -266.322, 41.7129), "WORLD_HUMAN_SIT_GROUND_DRINK_DRUNK", 211.68);
	copperheadLanding->addScenarioPoint(toVector3(2889.98, -249.443, 41.7334), "WORLD_HUMAN_SEAT_STEPS", 263.817);

	Place* bayuRuins = new Place(nextId(), area, toVector3(1997.17, -1613.91, 42.2466), 50, PlaceType::Shack, "Bayu Ruins");
	bayuRuins->setTypicalPedModel("g_m_y_uniexconfeds_01");
	bayuRuins->addScenarioPoint(toVector3(1998.35, -1621.42, 41.7456), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 199);
	bayuRuins->addScenarioPoint(toVector3(1996.01, -1611.05, 42.0426), "WORLD_HUMAN_LEAN_WALL_LEFT", 37.6046);
	bayuRuins->addScenarioPoint(toVector3(2008.24, -1607.58, 41.5104), "WORLD_HUMAN_LEAN_BACK_WHITTLE", 45);
	bayuRuins->addScenarioPoint(toVector3(1999.63, -1605.39, 42.0728), "WORLD_HUMAN_LEAN_WALL_RIGHT", 39.6);
	bayuRuins->addScenarioPoint(toVector3(1996.59, -1605.34, 42.1431), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 303.5);
	bayuRuins->addScenarioPoint(toVector3(1992.65, -1613.06, 45.2582), "WORLD_HUMAN_GUARD_MILITARY", 40.8);
	bayuRuins->addScenarioPoint(toVector3(2002.87, -1592.76, 42.08), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 336.5);
	bayuRuins->addScenarioPoint(toVector3(2003.88, -1590.94, 41.3714), "WORLD_HUMAN_SEAT_STEPS", 213.56);

	Place* bronesMansion = new Place(nextId(), area, toVector3(2329.99, -1219.22, 44.2889), 65, PlaceType::Mansion, "Bronte's Mansion");
	bronesMansion->setTypicalPedModel("g_m_m_unibrontegoons_01");

	Place* hotelRoom = new Place(nextId(), area, toVector3(2638.62, -1222.11, 59.6005), 15, PlaceType::HotelRoom, "Hotel Room");
	//hotelRoom->addScenarioPoint(hotelRoom->getCoords(), 10, 987924370, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	//hotelRoom->addScenarioPoint(toVector3(2637.29, -1217.73, 58.557), 10, 349691805, "PROP_HUMAN_SEAT_CHAIR_READING", toVector3(0, 0, 0.5), 180);
	hotelRoom->addScenarioPoint(toVector3(2631.22, -1217.61, 58.5933), 10, 325252933, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	hotelRoom->addScenarioPoint(toVector3(2638.67, -1216.57, 59.6092), "WORLD_HUMAN_LEAN_RAILING_DRINKING", 348);

	Place* mainGraveyard = new Place(nextId(), area, toVector3(2724.81, -1068.2, 47.4046), 80, PlaceType::Graveyard, "Cemetery");
	mainGraveyard->addScenarioPoint(toVector3(2759.86, -1094.66, 45.8904), "WORLD_HUMAN_CROUCH_INSPECT", -24);
	mainGraveyard->addScenarioPoint(toVector3(2775.18, -1053.13, 45.8904), "WORLD_HUMAN_CROUCH_INSPECT", 61);
	mainGraveyard->addScenarioPoint(toVector3(2733.65, -1052.24, 45.8904), "WORLD_HUMAN_CROUCH_INSPECT", 168);
	mainGraveyard->addScenarioPoint(toVector3(2747.7, -1075.16, 45.8905), "WORLD_HUMAN_CROUCH_INSPECT", 219);
	mainGraveyard->addScenarioPoint(toVector3(2764.6, -1084.45, 45.8905), "WORLD_HUMAN_CROUCH_INSPECT", 256);
	mainGraveyard->addScenarioPoint(toVector3(2708.61, -1087.93, 46.2153), "WORLD_HUMAN_CROUCH_INSPECT", 153);
	mainGraveyard->addScenarioPoint(toVector3(2699.31, -1045.57, 45.8647), "WORLD_HUMAN_CROUCH_INSPECT", 153);
	mainGraveyard->addScenarioPoint(toVector3(2677.79, -1053.99, 46.491), "WORLD_HUMAN_CROUCH_INSPECT", -79);
	mainGraveyard->addScenarioPoint(toVector3(2685.04, -1101.28, 48.2662), "WORLD_HUMAN_CROUCH_INSPECT", 184);
	mainGraveyard->addScenarioPoint(toVector3(2749.55, -1053.06, 45.8904), "WORLD_HUMAN_CROUCH_INSPECT", 153);

	cache[area] = {
		trappersCabin,
		copperheadLanding,
		bayuRuins,
		bronesMansion,
		hotelRoom,
		mainGraveyard
	};
}

void PlacesFactory::fillRhodes()
{
	MapAreas area = MapAreas::Rhodes;

	Place* oldGreenbankMill = new Place(nextId(), area, toVector3(735.354, -466.754, 77.9084), 55, PlaceType::Shack, "Old Greenbank Mill");
	oldGreenbankMill->addScenarioPoint(toVector3(725.84, -462.705, 79.3082), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 307.8);
	oldGreenbankMill->addScenarioPoint(toVector3(722.807, -471.553, 78.5374), "WORLD_HUMAN_LEAN_CHECK_PISTOL", 146.75);
	oldGreenbankMill->addScenarioPoint(toVector3(732.657, -474.235, 77.1393), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 243);
	oldGreenbankMill->addScenarioPoint(toVector3(743.805, -457.01, 78.7307), "WORLD_HUMAN_LEAN_BACK_WHITTLE", 320.75);
	oldGreenbankMill->addScenarioPoint(toVector3(727.616, -470.352, 85.8848), "WORLD_HUMAN_SIT_GROUND_COFFEE_DRINK", 186.34);

	Place* robardFarm = new Place(nextId(), area, toVector3(1127.76, -979.631, 68.8226), 55, PlaceType::Shack, "Robard Farm");
	robardFarm->addScenarioPoint(toVector3(1140.27, -978.526, 68.311), 2, -1194133100, "PROP_HUMAN_SEAT_CHAIR_DRINKING", toVector3(0,0,0.5), 180);
	robardFarm->addScenarioPoint(toVector3(1139.39, -982.888, 68.4049), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 257.9);
	robardFarm->addScenarioPoint(toVector3(1133.47, -970.28, 68.36), "WORLD_HUMAN_SEAT_STEPS", 319.85);
	robardFarm->addScenarioPoint(toVector3(1138.65, -975.917, 69.369), "WORLD_HUMAN_LEAN_RAILING_DRINKING", 321.5);
	robardFarm->addScenarioPoint(toVector3(1131.22, -972.765, 69.3752), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 150.4);
	robardFarm->addScenarioPoint(toVector3(1128.69, -989.285, 68.7466), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 102.2);

	Place* radleysHouse = new Place(nextId(), area, toVector3(1111.4, -1301.66, 66.4055), 60, PlaceType::Shack, "Radley's House");
	radleysHouse->addScenarioPoint(radleysHouse->getCoords(), 10, -1510839859, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	radleysHouse->addScenarioPoint(radleysHouse->getCoords(), 10, 325252933, "PROP_HUMAN_SEAT_CHAIR_TABLE_DRINKING_BADASS_BEER", toVector3(0, 0, 0.5), 180);
	radleysHouse->addScenarioPoint(toVector3(1114.6, -1298.14, 65.3939), 5, -661790979, "WORLD_HUMAN_SLEEP_GROUND_ARM", toVector3(0, 0, 1.5), 180);
	radleysHouse->addScenarioPoint(toVector3(1112.32, -1306.98, 65.4579), 2, 822992091, "PROP_HUMAN_SEAT_BENCH_TIRED", toVector3(0, 0, 0.5), 180);
	radleysHouse->addScenarioPoint(toVector3(1116.15, -1306.76, 66.4429), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 197.65);
	radleysHouse->addScenarioPoint(toVector3(1111.39, -1294.93, 65.369), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 340);

	Place* macombosEnd = new Place(nextId(), area, toVector3(1887.02, -748.824, 41.8338), 60, PlaceType::Shack, "Macombo's End");
	macombosEnd->addScenarioPoint(toVector3(1883.68, -751.917, 41.8731), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 248);
	macombosEnd->addScenarioPoint(toVector3(1883.33, -773.578, 42.4584), "WORLD_HUMAN_LEAN_BACK_WHITTLE", 0);
	macombosEnd->addScenarioPoint(toVector3(1878.76, -776.685, 42.4669), "WORLD_HUMAN_STAND_FISHING", 185.7);
	macombosEnd->addScenarioPoint(toVector3(1891.75, -744.925, 41.944), "WORLD_HUMAN_LEAN_WALL_RIGHT", 179);
	macombosEnd->addScenarioPoint(toVector3(1883.6, -748.646, 42.0214), "WORLD_HUMAN_LEAN_WALL_RIGHT", 283);
	macombosEnd->addScenarioPoint(toVector3(1874.84, -767.761, 42.4615), "WORLD_HUMAN_LEAN_BACK_RAILING_DRINKING", 270);

	Place* hagensOrchards = new Place(nextId(), area, toVector3(2068.23, -849.794, 43.3636), 60, PlaceType::Ranch, "Hagens Orchards");
	hagensOrchards->setTypicalPedModel("a_m_m_rhdforeman_01");
	
	Place* caligaHall = new Place(nextId(), area, toVector3(1789.37, -1391.09, 44.3887), 200, PlaceType::CaligaHall, "Caliga Hall");
	caligaHall->setTypicalPedModel("g_m_m_unigrays_01");

	Place* braithwaiteManor = new Place(nextId(), area, toVector3(1014.62, -1747.2, 46.6925), 200, PlaceType::BraithwaiteManor, "Braithwaite Manor");
	braithwaiteManor->setTypicalPedModel("g_m_m_unibraithwaites_01");

	Place* graveyard = new Place(nextId(), area, toVector3(1292.55, -1236.75, 80.8972), 50, PlaceType::Graveyard, "Rhodes Cemetery");
	graveyard->addScenarioPoint(toVector3(1276.79, -1228.94, 79.9272), "WORLD_HUMAN_CROUCH_INSPECT", 0);
	graveyard->addScenarioPoint(toVector3(1274.47, -1217.8, 80.6816), "WORLD_HUMAN_CROUCH_INSPECT", -2);
	graveyard->addScenarioPoint(toVector3(1275.98, -1208.64, 81.5887), "WORLD_HUMAN_CROUCH_INSPECT", 181);
	graveyard->addScenarioPoint(toVector3(1274.34, -1222.84, 80.2007), "WORLD_HUMAN_CROUCH_INSPECT", -6);
	graveyard->addScenarioPoint(toVector3(1272.61, -1223.48, 79.9665), "WORLD_HUMAN_CROUCH_INSPECT", -3);
	graveyard->addScenarioPoint(toVector3(1278.86, -1240.92, 79.0125), "WORLD_HUMAN_CROUCH_INSPECT", 7);
	graveyard->addScenarioPoint(toVector3(1294.67, -1209.94, 80.9774), "WORLD_HUMAN_CROUCH_INSPECT", -1);
	graveyard->addScenarioPoint(toVector3(1292.38, -1213.92, 80.9212), "WORLD_HUMAN_CROUCH_INSPECT", -18);

	cache[area] = {
		oldGreenbankMill,
		robardFarm,
		radleysHouse,
		macombosEnd,
		hagensOrchards,
		caligaHall,
		braithwaiteManor,
		graveyard
	};
}

void PlacesFactory::fillValentine()
{
	MapAreas area = MapAreas::Valentine;
	
	Place* firwoodRise = new Place(nextId(), area, toVector3(222.584, 986.904, 190.886), 60, PlaceType::Shack, "Firwood Rise");
	firwoodRise->addScenarioPoint(firwoodRise->getCoords(), 15, -51310680, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	firwoodRise->addScenarioPoint(firwoodRise->getCoords(), 15, -1025740342, "PROP_HUMAN_SEAT_CHAIR_TABLE_DRINKING_BADASS_BEER", toVector3(0, 0, 0.5), 180);
	firwoodRise->addScenarioPoint(toVector3(225.608, 990.445, 189.123), 2, 401642131, "PROP_HUMAN_SEAT_BENCH", toVector3(0, 0, 0.5), 180);
	firwoodRise->addScenarioPoint(toVector3(199.437, 984.531, 190.242), "WORLD_HUMAN_LEAN_CHECK_PISTOL", 280.9);
	firwoodRise->addScenarioPoint(toVector3(225.335, 1001.81, 189.656), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 83);
	firwoodRise->addScenarioPoint(toVector3(218.655, 987.554, 190.901), "WORLD_HUMAN_LEAN_BACK_WHITTLE", 180.6);
	firwoodRise->addScenarioPoint(toVector3(201.605, 984.218, 190.292), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 98.8);

	Place* windowRock = new Place(nextId(), area, toVector3(-154.874, 1490.18, 116.166), 60, PlaceType::Shack, "WindowRock");
	windowRock->addScenarioPoint(windowRock->getCoords(), 15, -1510839859, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	windowRock->addScenarioPoint(toVector3(-153.693, 1488.27, 116.183), "WORLD_HUMAN_LEAN_CHECK_PISTOL", 202.3);
	windowRock->addScenarioPoint(toVector3(-154.91, 1494.09, 115.765), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 294);

	Place* gillLanding = new Place(nextId(), area, toVector3(343.95, -664.18, 42.8268), 60, PlaceType::Shack, "Gill Landing");
	gillLanding->addScenarioPoint(gillLanding->getCoords(), 15, -1523455647, "PROP_HUMAN_SEAT_CHAIR_DRINKING", toVector3(0, 0, 0.5), 180);
	gillLanding->addScenarioPoint(toVector3(344.865, -668.206, 42.8272), 1, -1025740342, "PROP_CAMP_SEAT_CHAIR_STEW_LAZY", toVector3(0, 0, 0.5), 180);
	gillLanding->addScenarioPoint(toVector3(340.168, -674.331, 42.8037), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 156);
	gillLanding->addScenarioPoint(toVector3(338.791, -673.582, 42.813), "WORLD_HUMAN_LEAN_RAILING_DRINKING", 151.37);
	gillLanding->addScenarioPoint(toVector3(338.046, -680.98, 42.8381), "WORLD_HUMAN_STAND_FISHING", 73);
	gillLanding->addScenarioPoint(toVector3(332.42, -653.875, 41.7611), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 68.3);

	Place* carmodyDell = new Place(nextId(), area, toVector3(784.661, 866.449, 119.798), 70, PlaceType::Ranch, "Carmody Dell");
	carmodyDell->setTypicalPedModel("u_m_m_crdhomesteadtenant_01");

	Place* larnedLod = new Place(nextId(), area, toVector3(893.302, 270.594, 116.34), 55, PlaceType::Ranch, "Larned Lod");
	larnedLod->setTypicalPedModel("u_m_m_lrshomesteadtenant_01");

	Place* guthrieFarm = new Place(nextId(), area, toVector3(1129.51, 493.295, 95.9943), 70, PlaceType::Ranch, "Guthrie Farm");
	larnedLod->setTypicalPedModel("a_m_m_rancher_01");

	Place* hotelRoom1A = new Place(nextId(), area, toVector3(-325.663, 765.258, 117.437), 10, PlaceType::HotelRoom, "Hotel Room 1A");
	hotelRoom1A->addScenarioPoint(hotelRoom1A->getCoords(), 6, -807250478, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	hotelRoom1A->addScenarioPoint(toVector3(-325.152, 766.447, 117.434), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 196.3);

	Place* hotelRoom1B = new Place(nextId(), area, toVector3(-326.517, 760.32, 117.298), 10, PlaceType::HotelRoom, "Hotel Room 1B");
	hotelRoom1B->addScenarioPoint(toVector3(-323.35, 759.652, 117.436), "WORLD_HUMAN_INSPECT", 193);
	hotelRoom1B->addScenarioPoint(toVector3(-325.122, 760.421, 117.436), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 271.4);


	cache[area] = {
		windowRock,
		firwoodRise,
		gillLanding,
		carmodyDell,
		larnedLod,
		guthrieFarm,
		hotelRoom1A,
		hotelRoom1B
	};
}

void PlacesFactory::fillStrawberry()
{
	MapAreas area = MapAreas::Strawberry;

	Place* treehouse = new Place(nextId(), area, toVector3(-2459.66, 840.687, 146.381), 40, PlaceType::Shack, "Treehouse");
	treehouse->addScenarioPoint(toVector3(-2459.66, 840.687, 146.381), 5, -1443906703, "PROP_HUMAN_SEAT_CHAIR_CLEAN_RIFLE", toVector3(0, 0, 0.5), 180);
	treehouse->addScenarioPoint(toVector3(-2459.66, 840.687, 146.381), 5, -1775373677, "PROP_HUMAN_SEAT_CHAIR_DRINKING", toVector3(0, 0, 0.5), 180);

	Place* hotelRoom = new Place(nextId(), area, toVector3(-1819.35, -368.283, 166.504), 10, PlaceType::HotelRoom, "Hotel Room");
	hotelRoom->addScenarioPoint(hotelRoom->getCoords(), 10, -591288884, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	hotelRoom->addScenarioPoint(hotelRoom->getCoords(), 10, -1510839859, "PROP_HUMAN_SEAT_CHAIR_READING", toVector3(0, 0, 0.5), 180);

	cache[area] = {
		treehouse,
		hotelRoom
	};
}

void PlacesFactory::fillBlackwater()
{
	MapAreas area = MapAreas::Blackwater;

	Place* tannersReach = new Place(nextId(), area, toVector3(-2377.49, -1589.68, 154.283), 40, PlaceType::Shack, "Tanner's Reach");
	tannersReach->addScenarioPoint(tannersReach->getCoords(), 10, -289651159, "PROP_CAMP_SEAT_CHAIR_TABLE_STEW", toVector3(0, 0, 0.5), 180);
	tannersReach->addScenarioPoint(tannersReach->getCoords(), 10, 612486560, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	tannersReach->addScenarioPoint(toVector3(-2377.46, -1594.52, 154.143), "WORLD_HUMAN_LEAN_BACK_WHITTLE", 157);
	tannersReach->addScenarioPoint(toVector3(-2385.13, -1598.09, 154.25), "WORLD_HUMAN_LEAN_BACK_WALL_DRINKING", 257);

	Place* swadbassPoint = new Place(nextId(), area, toVector3(-2579.09, -1382.25, 149.255), 50, PlaceType::Shack, "Swadbass Point");
	swadbassPoint->addScenarioPoint(swadbassPoint->getCoords(), 10, 1072182776, "WORLD_HUMAN_SIT_FALL_ASLEEP", toVector3(0, 0, 1.5), 0);
	swadbassPoint->addScenarioPoint(toVector3(-2580.22, -1382.31, 149.255), "WORLD_HUMAN_LEAN_CHECK_PISTOL", 293.9);
	swadbassPoint->addScenarioPoint(toVector3(-2581.69, -1388.56, 149.248), "WORLD_HUMAN_LEAN_RAILING_DRINKING", 171.5);
	swadbassPoint->addScenarioPoint(toVector3(-2578.11, -1388.52, 149.31), "WORLD_HUMAN_LEAN_RAILING_DYNAMIC", 183);

	Place* graveyard = new Place(nextId(), area, toVector3(-968.537, -1196.28, 58.2461), 50, PlaceType::Graveyard, "Church of Holy Ascension");
	graveyard->addScenarioPoint(toVector3(-959.74, -1194.86, 55.7672), "WORLD_HUMAN_CROUCH_INSPECT", 173);
	graveyard->addScenarioPoint(toVector3(-959.592, -1197.21, 55.3592), "WORLD_HUMAN_CROUCH_INSPECT", 20);
	graveyard->addScenarioPoint(toVector3(-993.177, -1192.64, 57.9882), "WORLD_HUMAN_CROUCH_INSPECT", 1);
	graveyard->addScenarioPoint(toVector3(-986.404, -1181.44, 57.4566), "WORLD_HUMAN_CROUCH_INSPECT", 18);
	graveyard->addScenarioPoint(toVector3(-1009.45, -1187.39, 57.4353), "WORLD_HUMAN_CROUCH_INSPECT", 351);
	graveyard->addScenarioPoint(toVector3(-1014.83, -1198.72, 58.8453), "WORLD_HUMAN_CROUCH_INSPECT", 14);
	graveyard->addScenarioPoint(toVector3(-963.471, -1191.91, 56.967), "WORLD_HUMAN_CROUCH_INSPECT", 15);

	cache[area] = {
		tannersReach,
		swadbassPoint,
		graveyard
	};
}

void PlacesFactory::fillArmadillo()
{
	MapAreas area = MapAreas::Armadillo;

	Place* lakeDonJulioHouse = new Place(nextId(), area, toVector3(-3400.69, -3304.99, -4.44399), 60, PlaceType::Shack, "Lake Don Julio House");
	lakeDonJulioHouse->addScenarioPoint(lakeDonJulioHouse->getCoords(), 10, 612486560, "PROP_HUMAN_SEAT_CHAIR_CIGAR", toVector3(0, 0, 0.5), 180);
	lakeDonJulioHouse->addScenarioPoint(lakeDonJulioHouse->getCoords(), 10, -1510839859, "PROP_HUMAN_SEAT_CHAIR_DRINKING", toVector3(0, 0, 0.5), 180);
	lakeDonJulioHouse->addScenarioPoint(lakeDonJulioHouse->getCoords(), 15, -1025740342, "PROP_HUMAN_SEAT_CHAIR_KNIFE_BADASS", toVector3(0, 0, 0.5), 180);
	lakeDonJulioHouse->addScenarioPoint(toVector3(-3387.94, -3287.35, -6.7718), "WORLD_HUMAN_STAND_FISHING", 18);
	lakeDonJulioHouse->addScenarioPoint(toVector3(-3382.79, -3329.71, 5.81855), "WORLD_HUMAN_SIT_GROUND_COFFEE_DRINK", 298);
	lakeDonJulioHouse->addScenarioPoint(toVector3(-3421.33, -3317.35, 5.53333), "WORLD_HUMAN_SMOKE", 336);
	lakeDonJulioHouse->addScenarioPoint(toVector3(-3401.35, -3287.65, -6.46296), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 16.2);
	lakeDonJulioHouse->addScenarioPoint(toVector3(-3402.53, -3300.21, -4.44013), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 8.6);

	Place* rioDelLoboHouse = new Place(nextId(), area, toVector3(-3484.61, -3468.83, 0.176982), 60, PlaceType::Shack, "Rio Del Lobo House");
	rioDelLoboHouse->addScenarioPoint(rioDelLoboHouse->getCoords(), 10, -1510839859, "PROP_HUMAN_SEAT_CHAIR_TABLE_DRINKING_BADASS_BEER", toVector3(0, 0, 0.5), 180);
	rioDelLoboHouse->addScenarioPoint(rioDelLoboHouse->getCoords(), 10, 612486560, "PROP_HUMAN_SEAT_CHAIR_KNIFE_BADASS", toVector3(0, 0, 0.5), 180);
	rioDelLoboHouse->addScenarioPoint(rioDelLoboHouse->getCoords(), 10, 401642131, "PROP_HUMAN_SEAT_BENCH_HARMONICA", toVector3(0, 0, 0.5), 0);

	Place* pleasanceHouse = new Place(nextId(), area, toVector3(-4369.45, -2416.51, 20.4066), 60, PlaceType::Shack, "Pleasance House");
	pleasanceHouse->addScenarioPoint(pleasanceHouse->getCoords(), 10, -1025740342, "PROP_CAMP_SEAT_CHAIR_STEW_LAZY", toVector3(0, 0, 0.5), 180);
	pleasanceHouse->addScenarioPoint(pleasanceHouse->getCoords(), 10, 1072182776, "WORLD_HUMAN_SIT_FALL_ASLEEP", toVector3(0, 0, 1.5), 180);
	pleasanceHouse->addScenarioPoint(toVector3(-4359.97, -2414.58, 19.8841), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 119);
	pleasanceHouse->addScenarioPoint(toVector3(-4366.01, -2414.2, 20.6556), "WORLD_HUMAN_LEAN_CHECK_PISTOL", 291);

	Place* stillwaterCreek = new Place(nextId(), area, toVector3(-1814.6, -2394.05, 43.1581), 50, PlaceType::Shack, "Stillwater Creek");
	stillwaterCreek->addScenarioPoint(stillwaterCreek->getCoords(), 10, -821713083, "PROP_HUMAN_SEAT_CHAIR_DRINKING", toVector3(0, 0, 0.5), 180);
	stillwaterCreek->addScenarioPoint(stillwaterCreek->getCoords(), 10, -2070273503, "PROP_HUMAN_SEAT_BENCH_TIRED", toVector3(0, 0, 0.5), 180);
	stillwaterCreek->addScenarioPoint(toVector3(-1815.46, -2393.45, 43.1581), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 105.4);
	stillwaterCreek->addScenarioPoint(toVector3(-1810.77, -2398.67, 43.1581), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 193.5);
	stillwaterCreek->addScenarioPoint(toVector3(-1809.9, -2384.84, 43.9741), "WORLD_HUMAN_SIT_GROUND_COFFEE_DRINK", 293);

	Place* oldBacchusPlace = new Place(nextId(), area, toVector3(-1412.55, -2671.49, 42.1798), 50, PlaceType::Shack, "Old Bacchus Place");
	oldBacchusPlace->addScenarioPoint(oldBacchusPlace->getCoords(), 10, -289651159, "PROP_CAMP_SEAT_CHAIR_STEW_LAZY", toVector3(0, 0, 0.5), 180);
	oldBacchusPlace->addScenarioPoint(toVector3(-1423.61, -2686.24, 39.8089), 10, -2070273503, "PROP_HUMAN_SEAT_BENCH_MANDOLIN_DOWNBEAT", toVector3(0, 0, 0.5), 180);
	oldBacchusPlace->addScenarioPoint(toVector3(-1415.16, -2683.26, 40.8117), "WORLD_HUMAN_STAND_FISHING", 212);
	oldBacchusPlace->addScenarioPoint(toVector3(-1413.89, -2674.92, 42.2229), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 112);
	oldBacchusPlace->addScenarioPoint(toVector3(-1409.59, -2674.46, 42.1359), "WORLD_HUMAN_LEAN_BACK_WHITTLE", 207);

	Place* twinRocks = new Place(nextId(), area, toVector3(-3948.38, -2145.8, -5.63904), 70, PlaceType::GangHideout, "Twin Rocks");
	Place* thievesLanding = new Place(nextId(), area, toVector3(-1395, -2290.9, 43.5151), 70, PlaceType::GangHideout, "Thieves Landing");

	Place* macfarlanesRanch = new Place(nextId(), area, toVector3(-2356.13, -2392.53, 62.1805), 110, PlaceType::Ranch, "MacFarlanes Ranch");
	macfarlanesRanch->setTypicalPedModel("a_m_m_rancher_01");

	cache[area] = {
		lakeDonJulioHouse,
		//rioDelLoboHouse,
		pleasanceHouse,
		twinRocks,
		thievesLanding,
		macfarlanesRanch,
		stillwaterCreek,
		oldBacchusPlace
	};
}

void PlacesFactory::fillTumbleweed()
{
	MapAreas area = MapAreas::Tumbleweed;

	Place* silentStead = new Place(nextId(), area, toVector3(-5551.39, -2399.01, -8.7313), 50, PlaceType::Shack, "Silent Stead");
	silentStead->addScenarioPoint(toVector3(-5552.22, -2398.33, -8.74323), 1, -289651159, "PROP_HUMAN_SEAT_CHAIR_DRINKING", toVector3(0, 0, 0.5), 180);
	silentStead->addScenarioPoint(toVector3(-5554.6, -2399.14, -8.7277), 1, -289651159, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	silentStead->addScenarioPoint(toVector3(-5555.05, -2392.34, -8.99274), 1, -876203942, "PROP_HUMAN_SEAT_CHAIR_KNIFE_BADASS", toVector3(0, 0, 0.5), 180);
	silentStead->addScenarioPoint(toVector3(-5560.13, -2384.56, -8.61856), "WORLD_HUMAN_LEAN_CHECK_PISTOL", 269.5);
	silentStead->addScenarioPoint(toVector3(-5548.41, -2400.86, -9.08367), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 197);

	Place* scratchingPost = new Place(nextId(), area, toVector3(-5851.46, -3743.35, -24.8026), 55, PlaceType::Shack, "Scratching Post");
	scratchingPost->addScenarioPoint(scratchingPost->getCoords(), 10, -1528680970, "PROP_HUMAN_SEAT_CHAIR_DRINKING", toVector3(0, 0, 0.5), 180);
	scratchingPost->addScenarioPoint(scratchingPost->getCoords(), 10, 1230724566, "PROP_CAMP_SEAT_CHAIR_TABLE_STEW", toVector3(0, 0, 0.5), 0);
	scratchingPost->addScenarioPoint(toVector3(-5851.53, -3740.15, -25.14), 10, 401642131, "PROP_HUMAN_SEAT_BENCH_TIRED", toVector3(0, 0, 0.5), 0); // porch
	scratchingPost->addScenarioPoint(toVector3(-5841.53, -3735.22, -25.2991), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 312.5);
	scratchingPost->addScenarioPoint(toVector3(-5853.69, -3739.51, -25.2874), "WORLD_HUMAN_LEAN_RAILING_SMOKING", 109);
	scratchingPost->addScenarioPoint(toVector3(-5855.64, -3757.46, -24.8506), "WORLD_HUMAN_LEAN_CHECK_PISTOL", 172);

	Place* plainviewAbandonedCamp = new Place(nextId(), area, toVector3(-4685.91, -3756.13, 13.1862), 50, PlaceType::Shack, "Plainview");
	plainviewAbandonedCamp->addScenarioPoint(plainviewAbandonedCamp->getCoords(), 10, 1872659725, "WORLD_HUMAN_SLEEP_GROUND_ARM", toVector3(0, 0, 1), 0);
	plainviewAbandonedCamp->addScenarioPoint(plainviewAbandonedCamp->getCoords(), 10, 488855249, "PROP_HUMAN_SEAT_CHAIR_SMOKING", toVector3(0, 0, 0.5), 180);
	plainviewAbandonedCamp->addScenarioPoint(toVector3(-4698.88, -3754.34, 12.9828), "WORLD_HUMAN_LEAN_BACK_WALL_SMOKING", 38.6);
	plainviewAbandonedCamp->addScenarioPoint(toVector3(-4683.86, -3733.86, 13.0055), "WORLD_HUMAN_LEAN_CHECK_PISTOL", 315.1);
	plainviewAbandonedCamp->addScenarioPoint(toVector3(-4687.97, -3758.79, 13.0556), "WORLD_CAMP_SIT_GROUND_STEW_LAZY", 320);
	plainviewAbandonedCamp->addScenarioPoint(toVector3(-4697.9, -3753.35, 12.9762), "WORLD_HUMAN_LEAN_BACK_WALL_DRINKING", 42.6);

	Place* solomonsFolly = new Place(nextId(), area, toVector3(-5422.94, -3653.62, -22.0662), 80, PlaceType::GangHideout, "Solomon's Folly");
	Place* gaptoothBreach = new Place(nextId(), area, toVector3(-5997.33, -3245.67, -21.5301), 110, PlaceType::GangHideout, "Gaptooth Breach");
	Place* fortMercer = new Place(nextId(), area, toVector3(-4208.39, -3441.83, 37.0753), 110, PlaceType::GangHideout, "Fort Mercer");

	Place* rathskellerFork = new Place(nextId(), area, toVector3(-5196.57, -2126.6, 12.1282), 70, PlaceType::Ranch, "Rathskeller Fork Ranch");
	rathskellerFork->setTypicalPedModel("a_m_m_rancher_01");

	Place* ridgewoodFarm = new Place(nextId(), area, toVector3(-4826.43, -2714.55, -13.912), 110, PlaceType::Ranch, "Ridegewood Farm");
	ridgewoodFarm->setTypicalPedModel("u_m_m_rwfrancher_01");

	Place* graveyard = new Place(nextId(), area, toVector3(-5437.64, -2926.68, 0.932585), 40, PlaceType::Graveyard, "Tumbleweed Cemetery");
	graveyard->addScenarioPoint(toVector3(-5457.81, -2906.62, -0.123377), "WORLD_HUMAN_CROUCH_INSPECT", 66);
	graveyard->addScenarioPoint(toVector3(-5456.9, -2910.09, -0.133873), "WORLD_HUMAN_CROUCH_INSPECT", 76);
	graveyard->addScenarioPoint(toVector3(-5453.49, -2916.35, -0.160307), "WORLD_HUMAN_CROUCH_INSPECT", 104);
	graveyard->addScenarioPoint(toVector3(-5454.63, -2895.65, -0.0679491), "WORLD_HUMAN_CROUCH_INSPECT", -15);
	graveyard->addScenarioPoint(toVector3(-5440.23, -2908.03, -0.155223), "WORLD_HUMAN_CROUCH_INSPECT", -62);
	graveyard->addScenarioPoint(toVector3(-5453.24, -2922.8, -0.132283), "WORLD_HUMAN_CROUCH_INSPECT", -105);

	cache[area] = {
		silentStead,
		scratchingPost,
		plainviewAbandonedCamp,
		solomonsFolly,
		gaptoothBreach,
		fortMercer,
		rathskellerFork,
		ridgewoodFarm,
		graveyard
	};
}