#pragma once
#include "Character.h"

#include "Utility.h"

class Enemy
{
public:

	void Setup();

	void Update();

	void Draw(Texture _image);

	void Move();

	void Set_position();

	void Pulled(bool _is_pull);

private:
	// キャラクターの情報をまとめたもの
	// 位置情報やサイズなど
	Character_data data;

	Random random;

	int speed;

	bool is_active;

};