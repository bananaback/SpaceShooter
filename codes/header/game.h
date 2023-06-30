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
	template <typename T>
	void removeGameScreen();
	template <typename T>
	void switchGameScreen();
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
