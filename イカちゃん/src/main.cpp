#include "AppSetup.h"

//#include "SceneManager.h"

#include "GameMain.h"

int main() {
	App::Get();

//	SceneManager scene;
	GameMain game;
	game.Setup();

  while (App::Get().isOpen()) {
    App::Get().begin();

	game.Update();
	game.Draw();
//	scene.Update();
//	scene.Draw();

    App::Get().end();
  }
}
