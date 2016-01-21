
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

Miku mikus[MAX];

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

	Random random;
	random.setSeed(u_int(time(nullptr)));

	Texture image = Texture("res/miku.png");

	for (int i = 0; i < MAX; ++i){
		mikus[i].position = Vec2f(random(-WIDTH / 2, WIDTH / 2 - 200), random(-HEIGHT / 2, HEIGHT / 2 - 200));
		mikus[i].size = Vec2f(320, 270);
		mikus[i].clip_position = Vec2f(0, 0);
		mikus[i].clip_size = Vec2f(320, 270);
		mikus[i].is_show = false;
	}

	int count = 600;

	while (env.isOpen()) {
		// 開始
		env.begin();

		count -= 1;

		if (count == 0){
			for (int i = 0; i < MAX; ++i){
				if (mikus[i].is_show) continue;
				mikus[i].is_show = true;
				break;
			}
		}

		if (env.isPushButton(LEFT)){

			Vec2f mouse_position = env.mousePosition();

			for (int i = 0; i < MAX; ++i){

				if (!mikus[i].is_show) continue;

				if (Collision(mouse_position, mikus[i].position, mikus[i].size)){
					mikus[i].is_show = false;
					break;
				}
			}
		}

		for (int i = 0; i < MAX; ++i){
			if (!mikus[i].is_show) continue;
				drawTextureBox(mikus[i].position.x(), mikus[i].position.y(),
					mikus[i].size.x(), mikus[i].size.y(),
					mikus[i].clip_position.x(), mikus[i].clip_position.y(),
					mikus[i].clip_size.x(), mikus[i].clip_size.y(),
					image);
		}

		/*count -= 1;
		if (count == 0){
			for (int i = 0; i < MAX; i++){
				if (mikus[i].is_show) continue;

				mikus[i].is_show = true;
				break;
			}
		}

		if (env.isPushButton(LEFT)){

			Vec2f mouse_position = env.mousePosition();

			for (int i = 0; i < MAX; i++){

				if (!mikus[i].is_show) continue;

				if (Collision(mouse_position, mikus[i].position, mikus[i].size)){
					mikus[i].is_show = false;
					break;
				}
			}
		}

		for (int i = 0; i < MAX; i++){
			if (!mikus[i].is_show) continue;

			drawTextureBox(mikus[i].position.x(), mikus[i].position.y(),
						   mikus[i].size.x(), mikus[i].size.y(),
						   mikus[i].clip_position.x(), mikus[i].clip_position.y(),
						   mikus[i].clip_size.x(), mikus[i].clip_size.y(),
						   image);
		}*/
    
    
    // 終了
    env.end();
  }
}
