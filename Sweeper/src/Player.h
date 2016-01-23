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
	// �ړ������p�̊֐�
	void Move_limit();

	void Press_key();

	void Pull_key();

	void Add_move_limit();

	float Get_move_limit();

	bool Get_is_press_key();

	Character_data Get_data();

private:
	// �L�����N�^�[�̏����܂Ƃ߂�����
	// �ʒu����T�C�Y�Ȃ�
	Character_data data;

	float move_limit_bottom;

	bool is_press_key;
};