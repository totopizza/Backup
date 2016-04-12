#include "lib/framework.hpp"
#include "Utility.h"
#include "MapManager.h"

int main(void) {
	AppEnv env(Window::width, Window::height);

	MapManager mapManager;

	while (env.isOpen()) {
		env.begin();

		mapManager.Update(env);
		mapManager.Draw();

		env.end();
	}
}
