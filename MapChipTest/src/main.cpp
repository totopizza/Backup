#include "lib/framework.hpp"
#include"Map.h"

#define MARKER_X_MAX (4)
#define MARKER_X_MIN (1)

#define MARKER_Y_MAX (4)
#define MARKER_Y_MIN (0)

enum Window
{
	WIDTH = 1024,
	HEIGHT = 1024
};

int main(void) {
	AppEnv env(Window::WIDTH, Window::HEIGHT);

	Map map;

	// 地面のマップチップに重ねる用二次元配列
	// 種や障害物を置く時などに使用
	// 今は関係ない
	int ground2[5][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 }
	};

	// 選択マーカー用位置指定変数
	// 後で消す

	Vec2f marker = Vec2f(0, 0);

	int markerX = 0;	// x
	int markerY = 0;	// y

	while (env.isOpen()) {
		env.begin();

		marker.x() = (markerX * 105) - 100;
		marker.y() = -markerY * 105;

		// 選択マーカー移動処理＆移動制限
		if (markerX < MARKER_X_MAX && env.isPushKey(GLFW_KEY_RIGHT)) {
			markerX += 1;
		}
		else if (markerX >= MARKER_X_MIN && env.isPushKey(GLFW_KEY_LEFT)) {
			markerX -= 1;
		}
		else if (markerY > MARKER_Y_MIN && env.isPushKey(GLFW_KEY_UP)) {
			markerY -= 1;
		}
		else if (markerY < MARKER_Y_MAX && env.isPushKey(GLFW_KEY_DOWN)) {
			markerY += 1;
		}

		map.Draw();

		// 選択マーカー描画
		drawBox(marker.x(), marker.y(), 100, 100, 3, Color::red);

		env.end();
	}
}
