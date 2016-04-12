#pragma once
#include "lib\framework.hpp"
#include "Utility.h"
#include "Marker.h"

class Map
{
private:
	Marker marker;

	int ground[row][column];

	int ground_2[row][column];

	Vec2i position;

public:
	Map();

	void Update(AppEnv& env);

	void Draw();

};