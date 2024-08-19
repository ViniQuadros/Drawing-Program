#pragma once

#include "Pen.h"

class DrawInterface
{
public:
	DrawInterface(sf::Color color, sf::Vector2f position);

	void render(sf::RenderWindow& window);
	void changePenColor(sf::Vector2f mousePosition);

	sf::CircleShape setColorShape;

private:
	float radius = 15.0f;
	sf::RectangleShape box;

	Pen pen;
};

