
#include "AppSetup.h"

#include "GameManager.h"

#define MAX (9)

bool Collision(Vec2f mouse_pos, Vec2f image_pos, Vec2f image_size){
	
	if (mouse_pos.x() >= image_pos.x() &&
		mouse_pos.x() <= image_pos.x() + image_size.x() &&
		mouse_pos.y() >= image_pos.y() &&
		mouse_pos.y() <= image_pos.y() + image_size.y()){
		return true;
	}

	return false;
}

int main() {
	App::Get();

//	GameManager game;
//	game.Setup();

	Random random;
	random.setSeed(u_int(time(nullptr)));

	Texture image = Texture("res/new_squid.png");

	float x[MAX];
	float y[MAX];
	Vec2f pos[MAX];
	Vec2f size[MAX];


	for (int i = 0; i < MAX; ++i){
		x[i] = random(-WINDOW_WIDTH / 2, WINDOW_WIDTH / 2 - 200);
		y[i] = random(-WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2 - 200);
		pos[i] = Vec2f(x[i], y[i]);
		size[i] = Vec2f(128, 128);
	}

	Vec2f clip_pos[MAX] = {
		Vec2f(0, 0),
		Vec2f(128, 0),
		Vec2f(256, 0),
		Vec2f(0, 128),
		Vec2f(128, 128),
		Vec2f(256, 128),
		Vec2f(0, 256),
		Vec2f(128, 256),
		Vec2f(256, 256)
	};

	Vec2f mouse_prev_pos = Vec2f::Zero();

  while (App::Get().isOpen()) {
    App::Get().begin();

	Vec2f mouse_pos = App::Get().mousePosition();

	for (int i = 0; i < MAX; ++i){
		if (Collision(mouse_pos, pos[i], size[i])){
			if (App::Get().isPressButton(Mouse::LEFT)){
				pos[i] = mouse_prev_pos;

				mouse_prev_pos = mouse_pos;
			}
		}
	}

	

	for (int i = 0; i < MAX; ++i){
		drawTextureBox(pos[i].x(),pos[i].y(), size[i].x(), size[i].y(), clip_pos[i].x(),clip_pos[i].y(), 128, 128, image);
	}

//	game.Update();
//	game.Draw();

    App::Get().end();
  }
}
