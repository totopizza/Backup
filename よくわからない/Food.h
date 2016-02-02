#pragma once
#include "AppSetup.h"

#include "Utility.h"

#include <list>

class Food
{
public:
	Food(){}

	~Food(){}

	void Setup();

	void DataInit();

	void BoolInit();

	void Update();

	void Create(Vec2f _pos);

	void Draw(Texture _image);

private:
	std::list<DrawData> datas;

	Random random;

	int createTimer;

	bool isActive;
};