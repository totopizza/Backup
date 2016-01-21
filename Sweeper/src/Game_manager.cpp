#include "Game_manager.h"

bool Width_decision(Character_data _player, Character_data _enemy)
{
	if (_player.position.x() < _enemy.position.x() &&
		_player.position.x() + _player.size.x() > _enemy.position.x() + _enemy.size.x()){
		return true;
	}

	return false;
}

void Game_manager::Setup()
{
	player_image = Texture("res/sweeper.png");
	enemy_image = Texture("res/dust.png");

	player.Setup();
	enemy.Setup();
}

void Game_manager::Update()
{
	player.Update();
	enemy.Update();

	if (Width_decision(player.Get_data(),enemy.Get_data())){
		player.Press_key();
	}
	else{
		player.Pull_key();
	}

	enemy.Pulled(player.Get_is_press_key());

	enemy.Death_decision(player.Get_data(), player.Get_is_press_key());
}

void Game_manager::Draw()
{
	player.Draw(player_image);
	enemy.Draw(enemy_image);
}