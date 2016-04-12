#pragma once
#include "lib\framework.hpp"
#include "Utility.h"

class Marker
{
private:
	Direction dir;

	//描画位置指定用
	Vec2i position;

	Vec2i positionInfront;
	// 移動値
	Vec2i movingValue;

	Vec2i movingValueInfront;

public:
	Marker();

	void Update(AppEnv& env);

	void Draw();

	Vec2i GetMovingValue();

	Vec2i GetMovingValueInFront();

};