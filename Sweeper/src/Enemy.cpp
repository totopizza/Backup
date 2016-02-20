#include "Enemy.h"

void Enemy::Setup()
{
	random.setSeed(u_int(time(nullptr)));

	data.position = Vec2f(random(-WINDOW_WIDTH / 2, (WINDOW_WIDTH / 2) - 200),	// x²
						  (WINDOW_HEIGHT / 2) + 20);							// y²
	data.size = Vec2f(128, 128);
	data.clip_position = Vec2f(0, 0);
	data.clip_size = Vec2f(512, 512);

	speed = MOVE_POWER;

	point = 0;

	is_active = true;

	is_death = false;

}

void Enemy::Update()
{
	Move();
}

void Enemy::Draw(Texture _image)
{
	if (is_active){
		drawTextureBox(data.position.x(), data.position.y(),
					   data.size.x(), data.size.y(),
					   data.clip_position.x(), data.clip_position.y(),
					   data.clip_size.x(), data.clip_size.y(),
					   _image);
	}

	font.size(100);
	font.draw(std::to_string(point), Vec2f(WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 100), Color::red);
}

void Enemy::Move()
{
	if (is_active){
		data.position.y() -= speed;
	}
}

void Enemy::Set_position()
{
	data.position.x() = random(-WINDOW_WIDTH / 2, (WINDOW_WIDTH / 2) - 200);
	data.position.y() = (WINDOW_HEIGHT / 2) + 20;

	is_active = true;

	is_death = false;
}

void Enemy::Pulled(bool _is_press_key)
{
	if (_is_press_key){
		speed = MOVE_POWER * 5;
	}
	else{
		speed = MOVE_POWER;
	}
}

void Enemy::Death()
{
	is_active = false;
}

void Enemy::Death_decision(Character_data _player, bool _is_press_key)
{
	if (_player.position.y() + _player.size.y() >= data.position.y()){
		if (_is_press_key){
			is_death = true;
			Death();
			Set_position();
		}
	}
}

void Enemy::Add_point()
{
	point += 1;
}

int Enemy::Get_point()
{
	return point;
}

bool Enemy::Get_is_death()
{
	if (is_death){
		return true;
	}

	return false;
}

Character_data Enemy::Get_data()
{
	return data;
}

