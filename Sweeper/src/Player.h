#pragma once
#include "Character.h"

#include "Utility.h"

class Player : public Character
{
public:
	Player(){}

	~Player(){}

	void Setup();

	void Update();

	void Draw(Texture _image);

	void Move();
	// 移動制限用の関数
	void Move_limit();

	void Press_key();

	void Pull_key();

	bool Get_is_press_key();

	Character_data Get_data();

private:
	// キャラクターの情報をまとめたもの
	// 位置情報やサイズなど
	Character_data data;

	float move_limit_bottom;

	bool is_press_key;
};