#pragma once 
#include "App_setup.h"

#include "Player.h"
#include "Enemy.h"

class Game_manager
{
public:

	void Setup();

	void Update();

	void Draw();

private:
	Player player;
	Enemy enemy;

	// TODO : ���̕��@���l����
	Texture player_image;
	Texture enemy_image;

};