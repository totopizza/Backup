#pragma once
#include "lib\framework.hpp"
#include "Utility.h"

class Marker
{
private:
	Direction dir;

	//�`��ʒu�w��p
	Vec2i position;

	Vec2i positionInfront;
	// �ړ��l
	Vec2i movingValue;

	Vec2i movingValueInfront;

public:
	Marker();

	void Update(AppEnv& env);

	void Draw();

	Vec2i GetMovingValue();

	Vec2i GetMovingValueInFront();

};