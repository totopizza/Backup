#include "Enemy.h"

void Enemy::Setup()
{
	random.setSeed(u_int(time(nullptr)));

	data.position = Vec2f(random(-WINDOW_WIDTH / 2, (WINDOW_WIDTH / 2) - 50),	// xé≤
						  (WINDOW_HEIGHT / 2) + 20);							// yé≤
	data.size = Vec2f(128, 128);
	data.clip_position = Vec2f(0, 0);
	data.clip_size = Vec2f(512, 512);

	speed = MOVE_POWER;

	is_active = true;
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
}

void Enemy::Move()
{
	if (is_active){
		Speed_control();
		data.position.y() -= speed;
	}

	if (data.position.y() + data.size.y() < -WINDOW_HEIGHT / 2){
		is_active = false;
		Set_position();
	}
}

void Enemy::Set_position()
{
	data.position.x() = random(-WINDOW_WIDTH / 2, (WINDOW_WIDTH / 2) - 50);
	data.position.y() = (WINDOW_HEIGHT / 2) + 20;

	is_active = true;
}

void Enemy::Speed_control()
{
	if (is_pulled){
		speed = MOVE_POWER * 5;
	}
	else{
		speed = MOVE_POWER;
	}
}