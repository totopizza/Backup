#include "GameMain.h"

void GameMain::Setup()
{
	bgm = Media("res/BGM/bgm.wav");
	crickSE = Media("res/SE/crick.wav");

	bgImage = Texture("res/UI/background.png");
	DataInit();

	menu.Setup();

	baby.Setup();
	food.Setup();

	BoolInit();
}

void GameMain::DataInit()
{
	bgData.position = Vec2f(-WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);
	bgData.size = Vec2f(WINDOW_WIDTH, WINDOW_HEIGHT);
	bgData.clipPosition = Vec2f(0, 0);
	bgData.clipSize = Vec2f(512, 512);

	nowCrickPos = Vec2f(0, 0);
}

void GameMain::BoolInit()
{
	isCrick = false;

	isPlayMusic = false;
}

void GameMain::Update()
{
		if (!isPlayMusic){
			isPlayMusic = true;
			bgm.play();
			bgm.gain(0.2f);
		}

		Vec2f mousePos = App::Get().mousePosition();

		baby.Update();
		food.Update();
		//	baby.DistanceCalculation(nowCrickPos);

		if (App::Get().isPushButton(LEFT)){
			if (MouseToRect(mousePos, food.GetData().position, food.GetData().size)){
				crickSE.play();
				crickSE.gain(0.5f);
				isCrick = true;
				food.IsCrick(isCrick);
				baby.AddGrowPoint();
			}
		}

		menu.Update();
}

void GameMain::Draw()
{
		DrawBackground();
		baby.Draw();

		drawFillBox(100, 600, 400, 100, Color::gray);
		drawFillBox(100, 600, baby.GetGrowPoint().x(), baby.GetGrowPoint().y(), Color::blue);
		drawBox(100, 600, 400, 100, 10, Color::black);

		food.Draw();

		menu.Draw();

		//{
		//	font.size(30);
		//	font.draw(std::to_string(nowCrickPos.x()), Vec2f(-100, -50), Color::black);
		//	font.draw(std::to_string(nowCrickPos.y()), Vec2f(-100, -80), Color::black);
		//	font.draw(std::to_string(baby.GetDistance().x()), Vec2f(-100, -120), Color::black);
		//	font.draw(std::to_string(baby.GetDistance().y()), Vec2f(-100, -150), Color::black);
		//}
}

void GameMain::DrawBackground()
{
	drawTextureBox(bgData.position.x(), bgData.position.y(),
		bgData.size.x(), bgData.size.y(),
		bgData.clipPosition.x(), bgData.clipPosition.y(),
		bgData.clipSize.x(), bgData.clipSize.y(),
		bgImage);
}

