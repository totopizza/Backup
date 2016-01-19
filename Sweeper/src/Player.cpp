#include "Player.h"

void Player::Setup()
{
	data.position = Vec2f(0, move_limit_bottom);
	data.size = Vec2f(256, 400);
	data.clip_position = Vec2f(0, 0);
	data.clip_size = Vec2f(128, 256);

	move_limit_bottom = -WINDOW_HEIGHT / 2;

	is_pulled = false;
}

void Player::Update()
{
	Move();

	Move_limit();

	if (App::get().isPressKey(GLFW_KEY_A)){
		is_pulled = true;
	}
	else{
		is_pulled = false;
	}
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
		data.position.x() += MOVE_POWER*1.2;
	}
	else if (App::get().isPressKey(GLFW_KEY_LEFT)){
		data.position.x() -= MOVE_POWER*1.2;
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

	if (data.position.y() < move_limit_bottom){
		data.position.y() = move_limit_bottom;
	}
}

bool Player::Get_is_pulled()
{
	if (is_pulled){
		return true;
	}

	return false;
}