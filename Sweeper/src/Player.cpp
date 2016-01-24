#include "Player.h"

void Player::Setup()
{
	data.position = Vec2f(0, -WINDOW_HEIGHT / 2);
	data.size = Vec2f(256, 400);
	data.clip_position = Vec2f(0, 0);
	data.clip_size = Vec2f(128, 256);

	move_limit_bottom = -WINDOW_HEIGHT / 2;

	is_press_key = false;

}

void Player::Update()
{
	data.position.y() = Get_move_limit();

	Move();

	Move_limit();
}

void Player::Draw(Texture _image)
{
	drawTextureBox(data.position.x(), data.position.y(),
				   data.size.x(), data.size.y(),
				   data.clip_position.x(), data.clip_position.y(),
				   data.clip_size.x(), data.clip_size.y(),
				   _image);
}

void Player::Move()
{
	if (App::get().isPressKey(GLFW_KEY_RIGHT)){
		data.position.x() += MOVE_POWER * 1.2;
	}
	else if (App::get().isPressKey(GLFW_KEY_LEFT)){
		data.position.x() -= MOVE_POWER * 1.2;
	}
}

void Player::Move_limit()
{
	if (data.position.x() <= -WINDOW_WIDTH / 2){
		data.position.x() = -WINDOW_WIDTH / 2;
	}
	else if (data.position.x() + data.size.x() > WINDOW_WIDTH / 2){
		data.position.x() = (WINDOW_WIDTH / 2) - data.size.x();
	}
}

void Player::Press_key()
{
	if (App::get().isPressKey(GLFW_KEY_A)){
		is_press_key = true;
	}
	else{
		is_press_key = false;
	}
}

void Player::Pull_key()
{
	is_press_key = false;
}

float Player::Get_move_limit()
{
	return move_limit_bottom;
}

int Player::Add_move_limit()
{
	move_limit_bottom += 100;

	return move_limit_bottom;
}

bool Player::Get_is_press_key()
{
	if (is_press_key){
		return true;
	}

	return false;
}

Character_data Player::Get_data()
{
	return data;
}