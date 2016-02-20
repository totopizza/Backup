#pragma once
#include "Character.h"

#include "Utility.h"
#include <string>

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
	// ボタンを押した時用の関数
	void Press_key();
	// is_press_keyをfalseにする関数
	void Pull_key();
	// move_limit_bottomを渡す関数
	float Get_move_limit();
	// 地面をせり上げる関数
	int Add_move_limit();
	// is_press_keyを渡す関数
	bool Get_is_press_key();

	Character_data Get_data();

private:
	Font font = Font("res/font.ttf");

	// キャラクターの情報をまとめたもの
	// 位置情報やサイズなど
	Character_data data;
	// 地面の位置
	float move_limit_bottom;
	// ボタンが押されているかどうか
	bool is_press_key;
};