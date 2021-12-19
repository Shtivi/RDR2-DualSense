#include "Main.h"

vector<const char*> HispanicMale = {
	"Antonio","Jose","Manuel","Francisco","Juan","David","Javier","Daniel","Jesus","Carlos","Miguel","Alejandro","Rafael","Pedro","Angel","Jose Maria","Fernando","Pablo","Luis","Sergio","Jorge","Alberto","Alvaro","Diego","Adrian","Raul","Enrique","Ramon","Ivan","Vicente","Ruben","Oscar","Andres","Joaquin","Santiago","Eduardo","Victor","Roberto","Jaime","Mario","Ignacio","Alfonso","Marcos","Salvador","Ricardo","Jordi","Emilio","Julian","Guillermo","Julio","Gabriel","Tomas","Agustin","Jose Miguel","Hugo","Marc","Gonzalo","Jose Ramon","Mohamed","Felix","Joan","Nicolas","Ismael","Cristian","Samuel","Martin","Josep","Mariano","Domingo","Alfredo","Sebastian",
};

vector<const char*> HispanicSurnames = {
	"Garcia","Gonzalez","Rodriguez","Fernandez","Lopez","Martinez","Sanchez","Perez","Gomez","Martin","Jimenez","Ruiz","Hernandez","Diaz","Moreno","Munoz","Alvarez","Romero","Alonso","Gutierrez","Navarro","Torres","Dominguez","Vazquez","Ramos","Gil","Ramirez","Serrano","Blanco","Molina","Morales","Suarez","Ortega","Delgado","Castro","Ortiz","Rubio","Marin",
};

vector<const char*> WhiteMale = {
	"John","William","James","George","Charles","Robert","Joseph","Frank","Edward","Thomas","Henry","Walter","Harry","Willie","Arthur","Albert","Clarence","Fred","Harold","Paul","Raymond","Richard","Roy","Joe","Louis","Carl","Ralph","Earl","Jack","Ernest","David","Samuel","Howard","Charlie","Francis","Herbert","Lawrence","Theodore","Alfred","Andrew","Elmer","Sam","Eugene","Leo","Michael","Lee","Herman","Anthony","Daniel","Leonard","Floyd","Donald","Kenneth","Jesse","Russell","Clyde","Oscar","Peter","Lester","Leroy","Ray","Stanley","Clifford","Lewis","Benjamin","Edwin","Frederick","Chester","Claude","Eddie","Cecil","Lloyd","Jessie","Martin","Bernard","Tom","Will","Norman","Edgar","Harvey","Ben","Homer","Luther","Leon","Melvin","Philip","Johnnie","Jim","Milton","Everett","Allen","Leslie","Alvin","Victor","Marvin","Stephen","Alexander","Jacob","Hugh","Patrick","Virgil","Horace","Glenn","Oliver","Morris","Vernon","Archie","Julius","Gerald","Maurice","Sidney","Marion","Otis","Vincent",
};

vector<const char*> WhiteFemale = {
	"Mary","Helen","Margaret","Anna","Ruth","Elizabeth","Dorothy","Marie","Florence","Mildred","Alice","Ethel","Lillian","Gladys","Edna","Frances","Rose","Annie","Grace","Bertha","Emma","Bessie","Clara","Hazel","Irene","Gertrude","Louise","Catherine","Martha","Mabel","Pearl","Edith","Esther","Minnie","Myrtle","Ida","Josephine","Evelyn","Elsie","Eva","Thelma","Ruby","Agnes","Sarah","Viola","Nellie","Beatrice","Julia","Laura","Lillie","Lucille","Ella","Virginia","Mattie","Pauline","Carrie","Alma","Jessie","Mae","Lena","Willie","Katherine","Blanche","Hattie","Marion","Lucy","Stella","Mamie","Vera","Cora","Fannie","Eleanor","Bernice","Jennie","Ann","Leona","Beulah","Lula","Rosa","Ada","Ellen","Kathryn","Maggie","Doris","Dora","Betty","Marguerite","Violet","Lois","Daisy","Anne","Sadie","Susie","Nora","Georgia","Maude","Marjorie","Opal","Hilda","Velma","Emily","Theresa","Charlotte","Inez","Olive","Flora","Della","Lola","Jean","Effie","Nancy","Nettie","Sylvia","May",
};

vector<const char*> WhiteSurnames = {
	"Abrim","Alcock","Allen","Anderson","Arhile","Baily","Barner","Bedord","Blake","Blakely","Bolton","Borine","Bornce","Bornhisn","Boucha","Braussaw","Brock","Brockman","Brown","Burnette","Caffey","Calahan","Cambell","Cantan","Cantei","Cardinal","Casy","Chalouf","Clearson","Cocharn","Collins","Condene","Cotter","Coutu","Crowell","Darfu","Davis","Day","Densmore","Derwin","Dutcher","Eakley","Easswin","Eckley","Edwards","Ellis","Elsner","Fandrick","Fandric","Farma","Fergin","Fisher","Fox","Frazier","Friskey","Frisky","Furlong","Gengras","Gordon","Gorham","Gornelle","Greenwood","Gregsby","Hankins","Harden","Hasseling","Hayh","Held","Hendrox","Hepiner","Highland","Hoolahan","Houle","Kendlisna","Kensies","King","Laboner","Lamenski","Lapinance","Leach","Leobo","Marquis","Martin","Mattis","Mcallum","Mccloud","Mccutcheon","Mcdonald","Mcdonals","Mcglen","Mcquada","Mctire","Mezyenski","Miller","Mitchal","Moore","Moris","Musgrave","Noland","Oconal","O'Neal","Paquin","Pauin","Paulie","Perkins","Pollard","Pond","Poor","Price","Rapin","Roberts","Rosebush","Rourck","Russel","Sarafin","Savore","Schofield","Serrone","Simon","Slack","Small","Sonical","St. Denis","St. Johns","Stiles","Stolens","Store","Strong","Sullivan","Tarner","Thomas","Ubend","Vallier","Visnau","Wagner","Wall","Whitmore",
};

const char* Empty = "";

map<Hash, const char*> NamesGenerator::decodeMap;

void NamesGenerator::init()
{
	log("NamesGenerator: initializing");

	cacheList(HispanicMale);
	cacheList(HispanicSurnames);
	cacheList(WhiteMale);
	cacheList(WhiteFemale);
	cacheList(WhiteSurnames);

	log(string("NamesGenerator: initialized. ")
		.append(to_string(decodeMap.size()))
		.append(" string.")
	);
}

pair<Hash, Hash> NamesGenerator::generateName(int ethnicity, int gender)
{
	vector<const char*>* firstNamesList = NULL;
	vector<const char*>* surNamesList = NULL;

	switch (ethnicity)
	{
		case 1:
		{
			firstNamesList = &HispanicMale;
			surNamesList = &HispanicSurnames;
			break;
		}
		case 2:
		{
			if (gender == 1)
			{
				firstNamesList = &WhiteFemale;
			}
			else
			{
				firstNamesList = &WhiteMale;
			}
			surNamesList = &WhiteSurnames;
			break;
		}
		default:
		{
			firstNamesList = &WhiteMale;
			surNamesList = &WhiteSurnames;
			break;
		}
	}

	return make_pair(
		joaat(VectorUtils::random(*firstNamesList)),
		joaat(VectorUtils::random(*surNamesList))
	);
}

const char* NamesGenerator::retrieve(Hash nameIndex)
{
	map<Hash, const char*>::iterator itr = decodeMap.find(nameIndex);
	if (itr == decodeMap.end())
	{
		return Empty;
	}

	return itr->second;
}

const char* NamesGenerator::retrieve(Hash firstnameHash, Hash surnameHash)
{
	const char* firstname = retrieve(firstnameHash);
	const char* surname = retrieve(surnameHash);

	int firstnameLen = strlen(firstname);
	int surnameLen = strlen(surname);

	char* name = new char[firstnameLen + surnameLen + 1];
	strcpy(name, firstname);
	strcpy(name + firstnameLen, " ");
	strcpy(name + firstnameLen + 1, surname);
	return name;
}

void NamesGenerator::cacheList(vector<const char*> list)
{
	for each (const char* item in list)
	{
		decodeMap[joaat(item)] = item;
	}
}