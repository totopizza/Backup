#include "Game_manager.h"

void Game_manager::Setup()
{
	player.Setup();
	enemy.Setup();

	player_image = Texture("res/sweeper.png");
	enemy_image = Texture("res/dust.png");
}

void Game_manager::Update()
{
	player.Update();
	enemy.Update();
}

void Game_manager::Draw()
{
	player.Draw(player_image);
	enemy.Draw(enemy_image);
}