#pragma once
#include "AppSetup.h"

#include "Utility.h"

class Menu
{
public:

	void Setup();

	void DataInit();

	void Update();

	void Draw();

private:
	ObjectData data;
	ObjectData frameData;
	ObjectData fontData;

	Texture image;
	Texture frameImage;

	Font font = Font("res/UI/font.ttf");

	float time;

	float positionControl_y;

	float fontPositionControl_y;

	bool isMenuStart;

	bool isMenuEnd;

};