#pragma once
#include "lib\framework.hpp"

class Map
{
public:
	Map();

	void Update();

	void Draw();

private:
	int ground[5][5];

	Vec2i position;

};