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
	// �{�^���������ꂽ���p�̊֐�
	void Pulled(bool _is_press_key);
	
	void Death();
	// �v���C���[�ɋz�����܂ꂽ���p�̊֐�
	void Death_decision(Character_data _player, bool _is_press_key);
	// �G�l�~�[�̃|�C���g�𑫂��֐�
	void Add_point();
	// �G�l�~�[�̃|�C���g��n���֐�
	int Get_point();

	Character_data Get_data();

private:
	// �L�����N�^�[�̏����܂Ƃ߂�����
	// �ʒu����T�C�Y�Ȃ�
	Character_data data;

	Random random;

	Font font = Font("res/font.ttf");

	int speed;

	int point;

	bool is_active;

};