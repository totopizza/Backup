#pragma once
#include "lib\framework.hpp"

static enum SceneType
{
	None_,
	Title_,
	GameMain_
}sceneType;

enum Direction
{
	Up_,
	Down_,
	Right_,
	Left_
};

struct ChipData
{
	static int row;
	static int column;
	static int gap;
	static int size;
};

struct Window
{
	static int width;
	static int height;
	static int widthFit;
	static int heightFit;
};