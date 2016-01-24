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

	// ‘|œ‹@‚Ì‰¡•‚Ì”ÍˆÍ“à‚©‚Ì”»’è
	if (Width_decision(player.Get_data(), enemy.Get_data())){
		player.Press_key();
	}
	else{
		player.Pull_key();
	}

	// ’n–Ê‚ª‚¹‚è‚ ‚ª‚éˆ—
	// TODO:Player‚Ì•û‚ÅŠÖ”‰»
	// voidŒ^ ˆø”1ŒÂ intŒ^(Get_point()‚Ì•”•ª)
	// V‚½‚ÉboolŒ^ is_up‚ğ‚Â‚­‚é‚±‚Æ
	if (enemy.Get_point() == 0 || enemy.Get_point() % 3 != 0){
		is_up = false;
	}
	else if (enemy.Get_point() % 3 == 0 && !is_up){
		is_up = true;
		player.Add_move_limit();
	}


	// ‰æ–ÊŠO‚Éo‚½‚â’n–Ê‚É—‚¿‚½‚Ìˆ—
	// TODO:Enemy‚Ì•û‚ÅŠÖ”‰»
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