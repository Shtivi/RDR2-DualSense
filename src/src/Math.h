#pragma once

typedef pair<Vector3, float> Position;

//little one-line function called '$' to convert $TRING into a hash-key:
//Hash $(std::string str);
//Converts Radians to Degrees

Hash joaat(const char* string);

float degToRad(float degs);
float radToDeg(float rad);
float distanceBetween(Vector3 A, Vector3 B);
int rndInt(int start, int end);
Vector3 rot_to_direction(Vector3* rot);
Vector3 add(Vector3* vectorA, Vector3* vectorB);
Vector3 multiply(Vector3* vector, float x);
float get_distance(Vector3* pointA, Vector3* pointB);
float get_vector_length(Vector3 vector);
Vector3 cross(Vector3 left, Vector3 right);
float dotProduct(Vector3 a, Vector3 b);
Vector3 getUpVector(Entity entity);
Vector3 getRightVector(Entity entity);
Vector3 getForwardVector(Entity entity);
Vector3 toVector3(float x, float y, float z);
Position toPosition(float x, float y, float z, float heading);
Position toPosition(Vector3 coords, float heading);
float distance(Vector3 a, Vector3 b);
float distance(Vector3 pos, Entity entity);
float distance(Entity e1, Entity e2);
float distance(Entity e1);
float angleBetweenVectors(Vector3 a, Vector3 b);
Vector3 normalized(Vector3 source);
Vector3 around(Vector3 source, float distance, bool onGround = true);
Vector3 normalOf(Vector3 source);
Vector3 toDirectionVector3(float heading);

Vector3 operator+(Vector3 const& v, Vector3 const& u);
Vector3 operator*(Vector3 const& u, float a);
Vector3 operator*(float a, Vector3 const& u);
Vector3 operator-(Vector3 const& v, Vector3 const& u);
Vector3 operator* (Vector3 const& left, Vector3 const& right);
bool operator! (Vector3 const& left);
Vector3 calculatePointInDirection(Vector3 source, float heading, float distance);
float calculateHeadingToVector(Vector3 source, Vector3 destination);