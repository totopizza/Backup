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
	// ボタンが押された時用の関数
	void Pulled(bool _is_press_key);
	
	void Death();
	// プレイヤーに吸い込まれた時用の関数
	void Death_decision(Character_data _player, bool _is_press_key);
	// エネミーのポイントを足す関数
	void Add_point();
	// エネミーのポイントを渡す関数
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