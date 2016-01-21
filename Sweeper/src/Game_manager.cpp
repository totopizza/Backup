#include "Game_manager.h"

void Game_manager::Setup()
{
	player_image = Texture("res/sweeper.png");
	enemy_image = Texture("res/dust.png");

	is_pull = false;

	player.Setup();
	enemy.Setup();
}

void Game_manager::Update()
{
	player.Update();
	enemy.Update();

	if (player.Get_data().position.x() < enemy.Get_data().position.x() &&
		player.Get_data().position.x() + player.Get_data().size.x() > enemy.Get_data().position.x() + enemy.Get_data().size.x()){
		if (App::get().isPressKey(GLFW_KEY_A)){
			is_pull = true;
		}
		else{
			is_pull = false;
		}
	}
	else{
		is_pull = false;
	}

	enemy.Pulled(is_pull);
}

void Game_manager::Draw()
{
	player.Draw(player_image);
	enemy.Draw(enemy_image);
}