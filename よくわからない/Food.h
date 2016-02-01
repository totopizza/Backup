#pragma once
#include "AppSetup.h"

#include "Utility.h"

class Food
{
public:
	Food(){}

	~Food(){}

	void Setup();

	void DataInit();

	void BoolInit();

	void Update();

	void Draw(Texture _image);

private:
	DrawData data;

	Random random;

	bool isActive;
};