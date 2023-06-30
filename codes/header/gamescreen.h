#pragma once
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>

class GameScreen
{
public:
	GameScreen();
	virtual ~GameScreen() = default;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};

#endif // !GAME_SCREEN_H
