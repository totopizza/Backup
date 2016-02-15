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
	// TODO:foodに向かう時の動きに使う
//	virtual void DistanceCalculation(Vec2f _nowCrickPos);

	virtual void AddGrowPoint();
	// TODO:foodに向かう時の動きに使う
//	virtual Vec2f GetDistance();
	// 位置情報やサイズなどを渡す
	virtual ObjectData GetData();
	// TODO:進化判定の時に使う
	virtual bool GetIsActive();
	// 成長ポイントを渡す
	virtual Vec2f GetGrowPoint();

private:
	ObjectData data;

	Texture image;
	// TODO:緊急措置　後で絶対直す
	Texture drilImage;

	Media growSE;

	// 成長ポイント
	Vec2f growPoint;

	Vec2f distance;

	bool isMove;
};