#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"

class Pen
{
public:
	Pen(sf::Color penColor, float radius);

	void render(sf::RenderWindow& window);
	void drawScreen(sf::RenderWindow& window, sf::Vector2f mousePosition);
	void changeColor(sf::Color penColor);
	void increaseSize(float radius);
	void decreaseSize(float radius);
	void setPosition(sf::Vector2f mousePosition);
	void setColor(sf::Color color);
	void setDrawing(bool isDrawing);
	void clearDraw();

private:
	bool isDrawing;
	sf::CircleShape pen;
	std::vector<sf::Vertex> lines;
};

