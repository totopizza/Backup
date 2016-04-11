#include "MapManager.h"

void MapManager::Update(AppEnv& env)
{
	map.Update(env);
}

void MapManager::Draw()
{
	map.Draw();
}