#include "Enemy.h"

void Enemy::Setup()
{
	data.position = Vec2f(100, 0);
	data.size = Vec2f(128, 128);
	data.clip_position = Vec2f(0, 0);
	data.clip_size = Vec2f(512, 512);

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
		data.position.y() -= MOVE_POWER;
	}
}