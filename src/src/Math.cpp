#include "Main.h"

Hash joaat(const char* string)
{
	return MISC::GET_HASH_KEY(string);
}

//Converts Radians to Degrees
float degToRad(float degs)
{
	return degs * 3.141592653589793f / 180.f;
}

float radToDeg(float rad)
{
	return (rad * 180.0f) / 3.14159265;
}

//little one-line function called '$' to convert $TRING into a hash-key:
Hash $(std::string str) {
	return MISC::GET_HASH_KEY(&str[0u]);
}


//quick function to get distance between 2 points: eg - if (distanceBetween(coordsOf(player), targetCoords) < 50)
float distanceBetween(Vector3 A, Vector3 B) {
	return MISC::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}

//quick "get random int in range 0-x" function:
int rndInt(int start, int end) {
	return MISC::GET_RANDOM_INT_IN_RANGE(start, end);
}

//VECTOR AND FLOAT FUNCTIONS
Vector3 rot_to_direction(Vector3* rot) {
	float radiansZ = rot->z * 0.0174532924f;
	float radiansX = rot->x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}
Vector3 add(Vector3* vectorA, Vector3* vectorB) {
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;
	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;
	return result;
}

Vector3 multiply(Vector3* vector, float x) {
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;
	result.x *= x;
	result.y *= x;
	result.z *= x;
	return result;
}

float get_distance(Vector3* pointA, Vector3* pointB) {
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;
	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;
	double x_ba = (double)(b_x - a_x);
	double y_ba = (double)(b_y - a_y);
	double z_ba = (double)(b_z - a_z);
	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}

float get_vector_length(Vector3 vector) {
	double x = (double)vector.x;
	double y = (double)vector.y;
	double z = (double)vector.z;
	return(float)sqrt(x * x + y * y + z * z);
}

Vector3 cross(Vector3 left, Vector3 right)
{
	Vector3 result;
	result.x = left.y * right.z - left.z * right.y;
	result.y = left.z * right.x - left.x * right.z;
	result.z = left.x * right.y - left.y * right.x;
	return result;
}

float dotProduct(Vector3 a, Vector3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float angleBetweenVectors(Vector3 a, Vector3 b)
{
	//float aLength = (float)sqrt(a.x * a.x + a.y * a.y);
	//float bLength = (float)sqrt(b.x * b.x + b.y * b.y);
	//float mult = a.x * b.x + a.y * b.y;

	float aLength = get_vector_length(a);
	float bLength = get_vector_length(b);
	float mult = dotProduct(a, b);
	float radians = acos(mult / (aLength * bLength));
	return radToDeg(radians);
}

Vector3 getForwardVector(Entity entity)
{
	return ENTITY::GET_ENTITY_FORWARD_VECTOR(entity);
}

Vector3 getUpVector(Entity entity)
{
	return cross(getRightVector(entity), ENTITY::GET_ENTITY_FORWARD_VECTOR(entity));
}

Vector3 getRightVector(Entity entity)
{
	const double D2R = 0.01745329251994329576923690768489;
	Vector3 rotation = ENTITY::GET_ENTITY_ROTATION(entity, 2);
	double num1 = cos(rotation.y * D2R);
	double x = num1 * cos(-rotation.z * D2R);
	double y = num1 * sin(rotation.z * D2R);
	double z = sin(-rotation.y * D2R);
	return toVector3((float)x, (float)y, (float)z);
}

Vector3 operator+(Vector3 const& v, Vector3 const& u)
{
	Vector3 result;
	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return result;
}

Vector3 operator*(Vector3 const& u, float a)
{
	Vector3 result;
	result.x = u.x * a;
	result.y = u.y * a;
	result.z = u.z * a;
	return result;
}

Vector3 operator*(float a, Vector3 const& u)
{
	return u * a;
}

Vector3 operator-(Vector3 const& v, Vector3 const& u)
{
	return v + (u * (-1));
}

Vector3 operator* (Vector3 const& left, Vector3 const& right)
{
	Vector3 result;
	result.x = left.y * right.z - left.z * right.y;
	result.y = left.z * right.x - left.x * right.z;
	result.z = left.x * right.y - left.y * right.x;
	return result;
};

bool operator! (Vector3 const& left)
{
	return left.x == 0 && left.y == 0 && left.z == 0;
}

Vector3 toVector3(float x, float y, float z)
{
	Vector3 output;
	output.x = x;
	output.y = y;
	output.z = z;

	return output;
}

Position toPosition(float x, float y, float z, float heading)
{
	return make_pair(toVector3(x, y, z), heading);
}

Position toPosition(Vector3 coords, float heading)
{
	return make_pair(coords, heading);
}

float distance(Vector3 a, Vector3 b) {
	return distanceBetween(a, b);
}

float distance(Vector3 pos, Entity entity) {
	return distance(ENTITY::GET_ENTITY_COORDS(entity, 1, 0), pos);
}

float distance(Entity e1)
{
	return distance(e1, player);
}

float distance(Entity e1, Entity e2)
{
	return distance(ENTITY::GET_ENTITY_COORDS(e1, 1, 0), ENTITY::GET_ENTITY_COORDS(e2, 1, 0));
}

Vector3 normalized(Vector3 source)
{
	float length = get_vector_length(source);
	if (!length) {
		return toVector3(0,0,0);
	}

	float ratio = 1 / length;
	return toVector3(source.x * ratio, source.y * ratio, source.z * ratio);
}

Vector3 normalOf(Vector3 source)
{
	float length = get_vector_length(source);
	if (length == 0) {
		return toVector3(0, 0, 0);
	}

	Vector3 result;
	float num = 1 / length;
	result.x = source.x * num;
	result.y = source.y * num;
	result.z = source.z * num;
	return result;
}

Vector3 toDirectionVector3(float heading)
{
	heading  = ((int)heading + 90) % 360;
	return toVector3(BUILTIN::COS(heading), BUILTIN::SIN(heading), 0);
}

Vector3 around(Vector3 source, float distance, bool onGround)
{
	Vector3 random;
	double radian = MISC::GET_RANDOM_FLOAT_IN_RANGE(0, 1) * 2 * 3.14159;
	random.x = cos(radian);
	random.y = sin(radian);
	random.z = 0;
	random = normalized(random);

	Vector3 aroundSource = source + random * distance;
	aroundSource.z = source.z + 0.3;

	if (onGround) 
	{
		//return getGroundPos(aroundSource);
		float groundZ;
		MISC::GET_GROUND_Z_FOR_3D_COORD(aroundSource.x, aroundSource.y, source.z + 10, &groundZ, true);
		aroundSource.z = groundZ;
	}

	return aroundSource;
}

Vector3 calculatePointInDirection(Vector3 source, float heading, float distance)
{
	Vector3 direction = toVector3(BUILTIN::SIN(heading), BUILTIN::COS(heading), 0);
	return source + direction * distance;
}

float calculateHeadingToVector(Vector3 source, Vector3 destination)
{
	Vector3 direction = source - destination;
	float angle = radToDeg(atan2(direction.y, direction.x));
	int normalized = ((int)angle + 360) % 360;
	return normalized;
}