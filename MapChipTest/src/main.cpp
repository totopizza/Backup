#include "lib/framework.hpp"
#include "MapManager.h"

enum Window
{
	WIDTH = 1024,
	HEIGHT = 1024
};

int main(void) {
	AppEnv env(Window::WIDTH, Window::HEIGHT);

	MapManager mapManager;

	while (env.isOpen()) {
		env.begin();

		mapManager.Update(env);
		mapManager.Draw();

		env.end();
	}
}
