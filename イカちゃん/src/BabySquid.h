#pragma once
#include "AppSetup.h"
#include "Utility.h"

#include "Character.h"

class BabySquid : public Character
{
public:

	virtual ~BabySquid(){}

	virtual void Setup();

	virtual void DataInit();

	virtual void BoolInit();

	virtual void Update();

	virtual void Draw();

	virtual void Move();

	void SetIsMove();

	virtual void SetIsActive(bool _TrueOrFalse);
	// TODO:food�Ɍ��������̓����Ɏg��
//	virtual void DistanceCalculation(Vec2f _nowCrickPos);

	virtual void AddGrowPoint();
	// TODO:food�Ɍ��������̓����Ɏg��
//	virtual Vec2f GetDistance();
	// �ʒu����T�C�Y�Ȃǂ�n��
	virtual ObjectData GetData();
	// TODO:�i������̎��Ɏg��
	virtual bool GetIsActive();
	// �����|�C���g��n��
	virtual Vec2f GetGrowPoint();

private:
	ObjectData data;

	Texture image;
	// TODO:�ً}�[�u�@��Ő�Β���
	Texture drilImage;

	Media growSE;

	// �����|�C���g
	Vec2f growPoint;

	Vec2f distance;

	bool isMove;
};