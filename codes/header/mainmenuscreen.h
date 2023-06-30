#pragma once
#ifndef MAIN_MENU_SCREEN_H
#define MAIN_MENU_SCREEN_H

#include <SFML/Graphics.hpp>

#include <../codes/header/gamescreen.h>

class MainMenuScreen : public GameScreen
{
public:
	MainMenuScreen();
	~MainMenuScreen();
	virtual void update() override;
	virtual void draw(sf::RenderWindow& window) override;
};

#endif // !MAIN_MENU_SCREEN_H
