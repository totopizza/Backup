#pragma once
#include "lib\framework.hpp"

#include "Map.h"

class MapManager
{
private:
	Map map;

public:

	void Update(AppEnv& env);

	void Draw();

};