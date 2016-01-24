#pragma once
#include "Character.h"

#include "Utility.h"

#include <string>

class Enemy
{
public:

	void Setup();

	void Update();

	void Draw(Texture _image);

	void Move();

	void Set_position();

	void Pulled(bool _is_press_key);

	void Death();

	void Death_decision(Character_data _player, bool _is_press_key);

	void Add_point();

	int Get_point();

	Character_data Get_data();

private:
	// キャラクターの情報をまとめたもの
	// 位置情報やサイズなど
	Character_data data;

	Random random;

	Font font = Font("res/font.ttf");

	int speed;

	int point;

	bool is_active;

};