
#include "lib/framework.hpp"

#define MAX (500)

enum Window {
	WIDTH = 1000,
	HEIGHT = 1000
};

struct Miku
{
	Vec2f position;
	Vec2f size;
	Vec2f clip_position;
	Vec2f clip_size;
	bool is_show;
};

bool Collision(Vec2f _mouse_position, Vec2f _miku_position, Vec2f _miku_size){
	if (_mouse_position.x() > _miku_position.x() &&
		_mouse_position.x() < _miku_position.x() + _miku_size.x() &&
		_mouse_position.y() > _miku_position.y() &&
		_mouse_position.y() < _miku_position.y() + _miku_size.y()){
		return true;
	}
	return false;
}

int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT);

	Miku miku[MAX];
	Random random;
	random.setSeed(u_int(time(nullptr)));

	Texture image = Texture("res/miku.png");

	for (int i = 0; i < MAX; ++i){
		miku[i].position = Vec2f(random(-WIDTH / 2, WIDTH / 2 - 200), random(-HEIGHT / 2, HEIGHT / 2 - 200));
		miku[i].size = Vec2f(320, 270);
		miku[i].clip_position = Vec2f(0, 0);
		miku[i].clip_size = Vec2f(320, 270);
		miku[i].is_show = false;
	}

	int count = 600;

	while (env.isOpen()) {
		// 開始
		env.begin();

		Vec2f mouse_posision = env.mousePosition();

		count -= 1;
		for (int i = 0; i < MAX; i++){
			if (miku[i].is_show == false && count == 0){
				miku[i].is_show = true;
				count = 600;
				break;
			}
		}



		for (int i = 0; i < MAX; i++){
			if (miku[i].is_show){
			drawTextureBox(miku[i].position.x(), miku[i].position.y(),
						   miku[i].size.x(), miku[i].size.y(),
						   miku[i].clip_position.x(), miku[i].clip_position.y(),
						   miku[i].clip_size.x(), miku[i].clip_size.y(), image);
			}
	}
    
    
    // 終了
    env.end();
  }
}
