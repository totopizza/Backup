#pragma once 
#include "App_setup.h"

#include "Player.h"
#include "Enemy.h"

bool Width_decision(Character_data _player, Character_data _enemy);

class Game_manager
{
public:

	void Setup();

	void Update();

	void Draw();

private:
	Player player;
	Enemy enemy;

	// TODO : 他の方法も考える
	Texture player_image;
	Texture enemy_image;

	bool is_up;

};
