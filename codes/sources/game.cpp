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

template<typename T>
void Game::removeGameScreen()
{
    auto const it = std::find_if(gameScreens.begin(), gameScreens.end(), [](const std::shared_ptr<GameScreen>& screen) {
        return dynamic_cast<T*>(screen.get()) != nullptr;
        });

    if (it != gameScreens.end())
    {
        gameScreens.erase(it);
    }
}

template<typename T>
void Game::switchGameScreen()
{
    for (const auto& screen : gameScreens)
    {
        if (dynamic_cast<T*>(screen.get()) != nullptr)
        {
            GameScreen currentGameScreen = screen;
            break;
        }
    }
}

void Game::handleEvents()
{

}

void Game::update()
{
    
}

void Game::render()
{

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