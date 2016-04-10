#include "lib/framework.hpp"
#include "Map.h"
#include "Marker.h"

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
	Marker marker;

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

	while (env.isOpen()) {
		env.begin();

		marker.Update(env);

		map.Draw();
		marker.Draw();

		env.end();
	}
}
