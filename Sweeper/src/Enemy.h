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

private:
	// キャラクターの情報をまとめたもの
	// 位置情報やサイズなど
	Character_data data;

	bool is_active;

};