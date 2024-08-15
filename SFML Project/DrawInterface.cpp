#include "DrawInterface.h"

DrawInterface::DrawInterface() : pen(sf::Color::White, 5.0f)
{

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

void DrawInterface::construct(sf::Color color, sf::Vector2f position)
{
	this->setColorShape.setFillColor(color);
	this->setColorShape.setPosition(position);
	this->setColorShape.setRadius(radius);
	this->setColorShape.setOrigin(sf::Vector2f(radius, radius));
}
