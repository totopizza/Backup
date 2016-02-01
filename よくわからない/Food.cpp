#include "Food.h"

void Food::Setup()
{
	random.setSeed(u_int(time(nullptr)));
	DataInit();
	BoolInit();
}

void Food::DataInit()
{
	data.pos = Vec2f(random(-300, 300),
					 random(-300, 300));
	data.size = Vec2f(100.0f, 100.0f);
	data.clipPos = Vec2f(0, 0);
	data.clipSize = Vec2f(256.0f, 256.0f);
}

void Food::BoolInit()
{
	isActive = true;
}

void Food::Update()
{

}

void Food::Draw(Texture _image)
{
	if (isActive){
		drawTextureBox(data.pos.x(), data.pos.y(),
			data.size.x(), data.size.y(),
			data.clipPos.x(), data.clipPos.y(),
			data.clipSize.x(), data.clipSize.y(),
			_image);
	}
}