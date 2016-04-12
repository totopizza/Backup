#include "lib/framework.hpp"
#include "Utility.h"
#include "SceneManager.h"

int main(void) {
	AppEnv env(Window::width, Window::height);

	SceneManager sceneManager;

	while (env.isOpen()) {
		env.begin();

		sceneManager.Update(env);
		sceneManager.Draw();

		env.end();
	}

	delete sceneManager.GetScene();
}
