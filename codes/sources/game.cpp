#include <../codes/header/game.h>

Game::Game() : gameScreens{}, currentGameScreen{nullptr}, window{ sf::VideoMode(800, 600), "My Game" }, isRunning{false}, dt{.0}, clock{}
{

}

Game::~Game()
{
	
}

void Game::addGameScreen(const std::shared_ptr<GameScreen>& gameScreen)
{
	gameScreens.push_back(gameScreen);
}

void Game::handleEvents()
{

}

void Game::update()
{
    
}

void Game::render()
{
    window.clear();
    currentGameScreen->draw(window);
    window.display();
}

void Game::start()
{
    isRunning = true;
}

void Game::run()
{
    while (isRunning)
    {
        dt = clock.restart().asSeconds();
        //do the game 
        update();
        handleEvents();
        render();
        checkQuit();
    }
}

void Game::setRunning(bool isRunning)
{
    this->isRunning = isRunning;
}

void Game::checkQuit()
{
    if (!isRunning) window.close();
}
