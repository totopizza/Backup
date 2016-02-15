#include "Menu.h"

void Menu::Setup()
{
	DataInit();

	image = Texture("res/UI/menu.png");
	frameImage = Texture("res/UI/menuFrame.png");

	time = 0.0f;

	positionControl_y = 300;

	fontPositionControl_y = 20;

	isMenuStart = false;

	isMenuEnd = false;
}

void Menu::DataInit()
{
	data.size = Vec2f(WINDOW_WIDTH - 200, 600);
	data.position = Vec2f((-WINDOW_WIDTH / 2) + 100, (-WINDOW_HEIGHT/2)-data.size.y());
	data.clipPosition = Vec2f(0, 0);
	data.clipSize = Vec2f(512, 512);

	frameData.position = Vec2f(data.position.x() + 100, data.position.y() + positionControl_y);
	frameData.size = Vec2f(300, 200);
	frameData.clipPosition = Vec2f(0, 0);
	frameData.clipSize = Vec2f(512, 256);

	fontData.position = Vec2f(frameData.position.x() + 20, frameData.position.y() + 20);
}

void Menu::Update()
{
	if (App::Get().isPushKey('A')){
		isMenuStart = true;
		isMenuEnd = false;
		time = 0;
	}else if (App::Get().isPushKey('S')){
		isMenuEnd = true;
		isMenuStart = false;
		time = 0;
	}

	if (isMenuStart){
		data.position.y() = EasingElasticOut(time, (-WINDOW_HEIGHT / 2) - data.size.y(), -WINDOW_HEIGHT / 2);
		frameData.position.y() = EasingElasticOut(time, (-WINDOW_HEIGHT / 2) - data.size.y() + positionControl_y, -WINDOW_HEIGHT / 2 + positionControl_y);
		time += 0.01;
		if (time > 1.0f){
			time = 1.0f;
		}
	}

	if (isMenuEnd){
		data.position.y() = EasingExpoOut(time, -WINDOW_HEIGHT / 2, (-WINDOW_HEIGHT / 2) - data.size.y());
		frameData.position.y() = EasingExpoOut(time, -WINDOW_HEIGHT / 2 + positionControl_y, (-WINDOW_HEIGHT / 2) - data.size.y() + positionControl_y);
		time += 0.01;
		if (time > 1.0f){
			time = 1.0f;
		}
	}
}

void Menu::Draw()
{
	drawTextureBox(data.position.x(), data.position.y(),
				   data.size.x(), data.size.y(),
				   data.clipPosition.x(), data.clipPosition.y(),
				   data.clipSize.x(), data.clipSize.y(),
				   image,Color::cyan);

	drawTextureBox(frameData.position.x(), frameData.position.y(),
		frameData.size.x(), frameData.size.y(),
		frameData.clipPosition.x(), frameData.clipPosition.y(),
		frameData.clipSize.x(), frameData.clipSize.y(),
		frameImage);

	font.size(100);
	font.draw("ÇﬂÇ…Ç„Å`", fontData.position, Color::black);
}