#include "Main.h"

int roundToNearestMultipleOf(float number, int multipleOf)
{
	return ((int)((number + multipleOf / 2) / multipleOf)) * multipleOf;
}