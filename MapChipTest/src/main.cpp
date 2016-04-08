#include "lib/framework.hpp"

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

	// マップチップ用二次元配列の中に入れる用の配列
	int groundStatus[25];
	for (int i = 0; i < 25; ++i) {
		groundStatus[i] = 0;
	}

	// 地面マップチップ用二次元配列
	int* ground[5][5] = {
		{ &groundStatus[0], &groundStatus[1], &groundStatus[2], &groundStatus[3], &groundStatus[4] },
		{ &groundStatus[5], &groundStatus[6], &groundStatus[7], &groundStatus[8], &groundStatus[9] },
		{ &groundStatus[10], &groundStatus[11], &groundStatus[12], &groundStatus[13], &groundStatus[14] },
		{ &groundStatus[15], &groundStatus[16], &groundStatus[17], &groundStatus[18], &groundStatus[19] },
		{ &groundStatus[20], &groundStatus[21], &groundStatus[22], &groundStatus[23], &groundStatus[24] }
	};

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
	int markerX = 0;	// x
	int markerY = 0;	// y

	while (env.isOpen()) {
		env.begin();

		// 選択マーカー移動処理＆移動制限
		if (markerX < MARKER_X_MAX && env.isPushKey(GLFW_KEY_RIGHT)) {
			markerX += 1;
		}
		else if (markerX >= MARKER_X_MIN && env.isPushKey(GLFW_KEY_LEFT)) {
			markerX -= 1;
		}
		else if (markerY > MARKER_Y_MIN && env.isPushKey(GLFW_KEY_UP)){
			markerY -= 1;
		}
		else if (markerY < MARKER_Y_MAX && env.isPushKey(GLFW_KEY_DOWN)){
			markerY += 1;
		}


		// マップチップ描画
		for (int y = 0; y < 5; ++y) {
			for (int x = 0; x < 5; ++x) {

				int _x = (x * 105) - 100;
				int _y = -y * 105;

				if (*ground[x][y] == 0) {
					drawFillBox(_x, _y, 100, 100, Color::blue);
				}
				else if (*ground[x][y] == 1){
					drawFillBox(_x, _y, 100, 100, Color::cyan);
				}
			}
		}

		// 選択マーカー描画
		drawBox((markerX * 105) - 100, -markerY * 105, 100, 100, 3, Color::red);

		env.end();
	}
}
