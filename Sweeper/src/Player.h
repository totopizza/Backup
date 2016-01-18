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
	// �L�����N�^�[�̃f�[�^
	Character_data data;

};