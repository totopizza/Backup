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

	is_up;

	player.Setup();
	enemy.Setup();
}

void Game_manager::Update()
{
	player.Update();
	enemy.Update();

	// 掃除機の横幅の範囲内かの判定
	if (Width_decision(player.Get_data(), enemy.Get_data())){
		player.Press_key();
	}
	else{
		player.Pull_key();
	}

	// 地面がせりあがる処理
	// TODO:Playerの方で関数化
	// void型 引数1個 int型(Get_point()の部分)
	// 新たにbool型 is_upをつくること
	if (enemy.Get_point() == 0 || enemy.Get_point() % 3 != 0){
		is_up = false;
	}
	else if (enemy.Get_point() % 3 == 0 && !is_up){
		is_up = true;
		player.Add_move_limit();
	}


	// 画面外に出た時や地面に落ちた時の処理
	// TODO:Enemyの方で関数化
	if (enemy.Get_data().position.y() + enemy.Get_data().size.y() < player.Get_move_limit()){
		enemy.Death();
		enemy.Set_position();
		enemy.Add_point();
	}

	enemy.Pulled(player.Get_is_press_key());

	enemy.Death_decision(player.Get_data(), player.Get_is_press_key());
}

void Game_manager::Draw()
{
	player.Draw(player_image);
	enemy.Draw(enemy_image);
}