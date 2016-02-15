#pragma once
#include "AppSetup.h"

enum SceneType
{
	Title_,
	GameMain_,
	Result_
};

// TODO:列挙型を使わなくていいような書き方を研究する
enum SquidType
{
	Baby,
	Dril
};

// isActiveは生死判定ではなく進化判定に使う
struct ObjectData
{
	Vec2f position;
	Vec2f size;
	Vec2f clipPosition;
	Vec2f clipSize;
	bool isActive;
};

// Easingの関数
float EasingElasticOut(float t, float b, float e);

float EasingExpoOut(float t, float b, float e);

/* 当たり判定系はここから下に宣言してcppの方に内容を書くこと */
// TODO:当たり判定だけ集めたヘッダとcppを書く
bool MouseToRect(Vec2f mousePos, Vec2f rectPos, Vec2f rectSize);