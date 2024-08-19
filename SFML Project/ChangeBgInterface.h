#pragma once

#include <iostream>
#include <algorithm>
#include "SFML/Graphics.hpp"

class ChangeBgInterface
{
public:
	ChangeBgInterface(sf::Vector2f position);

	void renderBg(sf::RenderWindow& window);
	void renderBox(sf::RenderWindow& window);
	void changeColor(sf::RenderWindow& window);

	sf::CircleShape scroll;

private:
	sf::Font changeColorFont;
	sf::Text changeColorText;
	sf::Text drawText;

	sf::RectangleShape scrollLine;
	sf::RectangleShape box;

	float Radius;
	float scrollPosition;
};
