#include "BabySquid.h"

void BabySquid::Setup()
{
	image = Texture("res/Character/babySquid.png");
	drilImage = Texture("res/Character/SdrilSquid.png");

	growSE = Media("res/SE/grow.wav");

	growPoint = Vec2f(0, 100);

	DataInit();
	BoolInit();
}

void BabySquid::DataInit()
{
	data.position = Vec2f(-50, -50);
	data.size = Vec2f(150, 150);
	data.clipPosition = Vec2f(0, 0);
	data.clipSize = Vec2f(512, 512);
	data.isActive = true;
}

void BabySquid::BoolInit()
{
	isMove = false;
}

void BabySquid::Update()
{
	if (growPoint.x() > 399){
		growPoint.x() = 0;
		// TODO:Œã‚Å’¼‚·
		image = drilImage;
		data.size = Vec2f(300, 300);
		data.clipSize = Vec2f(256, 256);
		growSE.play();
		growSE.gain(0.5f);
	}
}

void BabySquid::Draw()
{
	drawTextureBox(data.position.x(), data.position.y(),
				   data.size.x(), data.size.y(),
				   data.clipPosition.x(), data.clipPosition.y(),
				   data.clipSize.x(), data.clipSize.y(),
				   image);
}

void BabySquid::Move()
{
	
}

void BabySquid::SetIsMove()
{
	isMove = true;
}

void BabySquid::SetIsActive(bool _TrueOrFalse)
{
	data.isActive = _TrueOrFalse;
}
/*
void BabySquid::DistanceCalculation(Vec2f _nowCrickPos)
{
	distance.x() = abs(_nowCrickPos.x() - data.position.x());
	distance.y() = abs(_nowCrickPos.y() - data.position.y());
}
*/

void BabySquid::AddGrowPoint()
{
	growPoint.x() += 100;
}

/*
Vec2f BabySquid::GetDistance()
{
	return distance;
}
*/

ObjectData BabySquid::GetData()
{
	return data;
}

bool BabySquid::GetIsActive()
{
	if (data.isActive){
		return true;
	}

	return false;
}

Vec2f BabySquid::GetGrowPoint()
{
	return growPoint;
}