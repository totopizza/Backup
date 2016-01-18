//
// シューティング
//

#include "App_setup.h"

#include "Game_manager.h"

int main() {
	App::get();

	Game_manager game;
	game.Setup();

  while (App::get().isOpen()) {
	App::get().begin();

	game.Update();
	game.Draw();

	App::get().end();
  }
}
