#pragma once
#include "lib\framework.hpp"

const int row = 5;
const int column = 5;

class Map
{
private:
	int ground[row][column];

	Vec2i position;

public:
	Map();

	void Update();

	void Draw();

};