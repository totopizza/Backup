#pragma once
#include "lib\framework.hpp"
#include "Utility.h"

class Marker
{
private:
	//描画位置指定用
	Vec2i position;
	// 移動値
	Vec2i movingValue;

public:
	Marker();

	void Update(AppEnv& env);

	void Draw();

	Vec2i GetMovingValue();

};