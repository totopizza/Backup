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

	void Move_limit();

private:
	// キャラクターのデータ
	Character_data data;

};