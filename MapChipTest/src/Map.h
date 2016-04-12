#pragma once
#include "lib\framework.hpp"
#include "Utility.h"
#include "Marker.h"

#include <vector>

class Map
{
private:
	Marker marker;

	Direction dir;

	std::vector<std::vector<int>> ground;
	std::vector<std::vector<int>> ground_2;

	//int ground[row][column];

	//int ground_2[row][column];

	Vec2i position;

public:
	Map();

	void Update(AppEnv& env);

	void Draw();

};