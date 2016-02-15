#include "Food.h"

void Food::Setup()
{
	image = Texture("res/Food/wakame.png");

	// TODO:�����͗�������Ȃ�
	random.setSeed(u_int(time(nullptr)));

	DataInit();
	IntInit();
	BoolInit();
}

void Food::DataInit()
{
	data.position = Vec2f(random((-WINDOW_WIDTH/2)+200,(WINDOW_WIDTH/2)-200), // x�� 
						  random(0,(WINDOW_HEIGHT/2)-200));					  // y��
	data.size = Vec2f(150, 150);
	data.clipPosition = Vec2f(0, 0);
	data.clipSize = Vec2f(256, 256);
}

void Food::IntInit()
{
	createTimer = 60;
}

void Food::BoolInit()
{
	isCreate = false;
}

void Food::Update()
{
	if (!isCreate){
		createTimer -= 1;
	}

	Create();
}

void Food::Draw()
{
	if (isCreate){
		drawTextureBox(data.position.x(), data.position.y(),
			data.size.x(), data.size.y(),
			data.clipPosition.x(), data.clipPosition.y(),
			data.clipSize.x(), data.clipSize.y(),
			image);
	}
}

// int�^createTimer�ݒ�(�b)
void Food::SetCreateTimer(int _Value)
{
	createTimer = _Value * 60;
}

// bool�^isCreate�ݒ�
void Food::SetIsCreate(bool _TrueOrFalse)
{
	isCreate = _TrueOrFalse;
}

void Food::IsCrick(bool _isCrick)
{
	if (_isCrick){
		isCreate = false;
		SetCreateTimer(1);
		data.position.x() = random((-WINDOW_WIDTH / 2) + 200, (WINDOW_WIDTH / 2) - 200);
		data.position.y() = random(0, (WINDOW_HEIGHT / 2) - 200);
	}
}

// ���������邩�𔻒f���Ă���֐�
void Food::Create()
{
	if (createTimer <= 0){
		SetIsCreate(true);
		SetCreateTimer(0);
	}
}

ObjectData Food::GetData()
{
	return data;
}

bool Food::GetIsCreate()
{
	if (isCreate){
		return true;
	}

	return false;
}