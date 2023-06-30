#include <iostream>
#include <../codes/header/game.h>
#include <../codes/header/mainmenuscreen.h>

int main()
{
	Game game;
	game.addGameScreen(std::make_shared<MainMenuScreen>());
	game.switchGameScreen<MainMenuScreen>();
	game.start();
	game.run();
	return 0;
}
