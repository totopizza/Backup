#pragma once
#include "lib\framework.hpp"

class Marker
{
private:
	//�`��ʒu�w��p
	Vec2i position;
	// �ړ��l
	Vec2i movingValue;

public:
	Marker();

	void Update(AppEnv& env);

	void Draw();

	Vec2i GetMovingValue();

};