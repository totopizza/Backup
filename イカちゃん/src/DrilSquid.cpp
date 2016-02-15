#include "DrilSquid.h"

void DrilSquid::Setup()
{
	image = Texture("res/Character/SdrilSquid.png");
	DataInit();
}

void DrilSquid::DataInit()
{
	data.position = Vec2f(0, 0);
	data.size = Vec2f(256, 256);
	data.clipPosition = Vec2f(0, 0);
	data.clipSize = Vec2f(256, 256);
	data.isActive = false;
}

void DrilSquid::Update()
{

}

void DrilSquid::Draw()
{
	drawTextureBox(data.position.x(), data.position.y(),
				   data.size.x(), data.size.y(),
				   data.clipPosition.x(), data.clipPosition.y(),
				   data.clipSize.x(), data.clipSize.y(),
				   image);
}

void DrilSquid::SetIsActive(bool _TrueOrFalse)
{
	data.isActive = _TrueOrFalse;
}

bool DrilSquid::GetIsActive()
{
	if (data.isActive){
		return true;
	}


	return false;
}