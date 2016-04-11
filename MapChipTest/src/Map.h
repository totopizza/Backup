#pragma once
#include "lib\framework.hpp"
#include "Marker.h"

const int row = 5;
const int column = 5;

class Map
{
private:
	Marker marker;

	int ground[row][column];

	Vec2i position;

public:
	Map();

	void Update(AppEnv& env);

	void Draw();

};