#pragma once

#include "Pen.h"

class DrawInterface
{
public:
	DrawInterface();

	void render(sf::RenderWindow& window);
	void changePenColor(sf::Vector2f mousePosition);
	void construct(sf::Color color, sf::Vector2f position);

	sf::CircleShape setColorShape;

private:
	float radius = 15.0f;
	sf::RectangleShape box;

	Pen pen;
};

