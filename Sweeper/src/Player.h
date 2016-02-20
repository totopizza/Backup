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
	// �ړ������p�̊֐�
	void Move_limit();
	// �{�^�������������p�̊֐�
	void Press_key();
	// is_press_key��false�ɂ���֐�
	void Pull_key();
	// move_limit_bottom��n���֐�
	float Get_move_limit();
	// �n�ʂ�����グ��֐�
	int Add_move_limit();
	// is_press_key��n���֐�
	bool Get_is_press_key();

	Character_data Get_data();

private:
	Font font = Font("res/font.ttf");

	// �L�����N�^�[�̏����܂Ƃ߂�����
	// �ʒu����T�C�Y�Ȃ�
	Character_data data;
	// �n�ʂ̈ʒu
	float move_limit_bottom;
	// �{�^����������Ă��邩�ǂ���
	bool is_press_key;
};