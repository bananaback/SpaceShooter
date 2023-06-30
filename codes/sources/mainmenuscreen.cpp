#include <../codes/header/mainmenuscreen.h>

MainMenuScreen::MainMenuScreen()
{

}

MainMenuScreen::~MainMenuScreen()
{

}

void MainMenuScreen::update()
{

}

void MainMenuScreen::draw(sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::Cyan);
	rect.setPosition(sf::Vector2f(100, 100));
	window.draw(rect);
}