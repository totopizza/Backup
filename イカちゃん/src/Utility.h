#pragma once
#include "AppSetup.h"

enum SceneType
{
	Title_,
	GameMain_,
	Result_
};

// TODO:�񋓌^���g��Ȃ��Ă����悤�ȏ���������������
enum SquidType
{
	Baby,
	Dril
};

// isActive�͐�������ł͂Ȃ��i������Ɏg��
struct ObjectData
{
	Vec2f position;
	Vec2f size;
	Vec2f clipPosition;
	Vec2f clipSize;
	bool isActive;
};

// Easing�̊֐�
float EasingElasticOut(float t, float b, float e);

float EasingExpoOut(float t, float b, float e);

/* �����蔻��n�͂������牺�ɐ錾����cpp�̕��ɓ��e���������� */
// TODO:�����蔻�肾���W�߂��w�b�_��cpp������
bool MouseToRect(Vec2f mousePos, Vec2f rectPos, Vec2f rectSize);