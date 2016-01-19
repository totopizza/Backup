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
	// �L�����N�^�[�̏����܂Ƃ߂�����
	// �ʒu����T�C�Y�Ȃ�
	Character_data data;

	Random random;

	int speed;

	bool is_active;

};