#pragma once
#include "AppSetup.h"
#include "Utility.h"

#include "Menu.h"

#include "Food.h"

#include "BabySquid.h"
#include "DrilSquid.h"

class GameMain
{
public:

	void Setup();

	void DataInit();

	void BoolInit();

	void Update();

	void Draw();

	void DrawBackground();

private:
	Texture bgImage;
	ObjectData bgData;

	Vec2f nowCrickPos;

	bool isCrick;

	bool isPlayMusic;

	Font font = Font("res/UI/font.ttf");

	Media bgm;
	Media crickSE;

	// インスタンス化
	Menu menu;

	Food food;
	BabySquid baby;


};