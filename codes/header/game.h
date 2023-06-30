#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <vector>

#include <../codes/header/gamescreen.h>

class Game
{
public:
	Game();
	~Game();
	void addGameScreen(const std::shared_ptr<GameScreen>& gameScreen);
	// https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file/495056#495056
	template<typename T>
	void removeGameScreen()
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
	void switchGameScreen()
	{
		for (const auto& screen : gameScreens)
		{
			if (dynamic_cast<T*>(screen.get()) != nullptr)
			{
				currentGameScreen = screen;
				break;
			}
		}
	}
	void handleEvents();
	void update();
	void render();
	void start();
	void run();
	void setRunning(bool isRunning);
	void checkQuit();
private:
	std::vector<std::shared_ptr<GameScreen>> gameScreens;
	std::shared_ptr<GameScreen> currentGameScreen;
	sf::RenderWindow window;
	bool isRunning;
	float dt;
	sf::Clock clock;
};

#endif // !GAME_H
