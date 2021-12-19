/*
	THIS FILE IS A PART OF RDR 2 SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2019
*/

#pragma once

#include <windows.h>

typedef DWORD Void;
typedef uint64_t Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Instructional;
typedef int Sphere;
typedef int ScrHandle;
typedef int Scaleform;
typedef int AnimScene;
typedef int UIPrompt;
typedef int PopZone;
typedef int Volume;
typedef int PropSet;
typedef int ItemSet;
typedef int PersChar;

#define ALIGN8 __declspec(align(8))

//struct Vector3
//{
//	ALIGN8 float x;
//	ALIGN8 float y;
//	ALIGN8 float z;
//};
typedef struct
{
	float x;
	DWORD _paddingx;
	float y;
	DWORD _paddingy;
	float z;
	DWORD _paddingz;

} Vector3;
static_assert(sizeof(Vector3) == 24, "");