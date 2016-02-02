#include "Food.h"

void Food::Setup()
{
	random.setSeed(u_int(time(nullptr)));
	DataInit();
	BoolInit();

	createTimer = 30;
}

void Food::DataInit()
{
	
}

void Food::BoolInit()
{
	isActive = true;
}

void Food::Update()
{
	createTimer -= 1;
	if (createTimer == 0){
		Vec2f pos(random(-300, 300),
			random(-300, 300));
		Create(pos);

		createTimer = 30;
	}

	Crick();
}

void Food::Crick()
{
	if (App::Get().isPushButton(Mouse::LEFT)){
		Vec2f mouse_pos = App::Get().mousePosition();

		for (std::list<DrawData>::iterator itr = datas.begin(); itr != datas.end(); ++itr){
			if (MouseToRectCollision(mouse_pos, itr->pos, itr->size)){
				itr = datas.erase(itr);
				break;
			}
		}
	}
}

void Food::Create(Vec2f _pos)
{
	if (datas.size() == FoodMax) return;

	DrawData data = 
	{
		_pos,
		Vec2f(100, 100),
		Vec2f(0, 0),
		Vec2f(256, 256)
	};

	datas.push_back(data);
}

void Food::Draw(Texture _image)
{
	if (isActive){
		for (std::list<DrawData>::iterator itr = datas.begin(); itr != datas.end(); itr++){
			drawTextureBox(itr->pos.x(), itr->pos.y(),
				itr->size.x(), itr->size.y(),
				itr->clipPos.x(), itr->clipPos.y(),
				itr->clipSize.x(), itr->clipSize.y(),
				_image);
		}
	}
	
}