#include "DrawInterface.h"

DrawInterface::DrawInterface(sf::Color color, sf::Vector2f position) : pen(sf::Color::White, 5.0f)
{
	this->setColorShape.setFillColor(color);
	this->setColorShape.setPosition(position);
	this->setColorShape.setRadius(radius);
	this->setColorShape.setOrigin(sf::Vector2f(radius, radius));
}

void DrawInterface::render(sf::RenderWindow& window)
{
	window.draw(setColorShape);
}

void DrawInterface::changePenColor(sf::Vector2f mousePosition)
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->setColorShape.getGlobalBounds().contains(mousePosition))
	{
		this->pen.setColor(setColorShape.getFillColor());
	}
}
