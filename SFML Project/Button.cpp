#include "Button.h"

Button::Button(sf::Vector2f position, sf::Vector2f size)
{
	this->buttonShape.setSize(sf::Vector2f(size));
	this->buttonShape.setFillColor(sf::Color::Cyan);
	this->buttonShape.setOrigin(this->buttonShape.getSize().x / 2, this->buttonShape.getSize().y / 2);
	this->buttonShape.setPosition(sf::Vector2f(position));
	this->buttonShape.setOutlineThickness(3.0f);
	this->buttonShape.setOutlineColor(sf::Color::Black);
}

void Button::hovered(sf::Vector2f mousePosition)
{
	if (this->buttonShape.getGlobalBounds().contains(mousePosition))
	{
		this->buttonShape.setFillColor(sf::Color(0, 0, 255, 150));
	}
	else
	{
		this->buttonShape.setFillColor(sf::Color(0, 0, 255, 255));
	}
}

void Button::setText(std::string buttonString)
{
	if (!txtFont.loadFromFile("PlayfairDisplayRegular-ywLOY.ttf"))
	{
		std::cout << "Error" << std::endl;
	}
	this->text.setFont(txtFont);
	this->text.setCharacterSize(20);
	this->text.setString(buttonString);
	this->text.setOrigin(this->text.getGlobalBounds().getSize().x / 2, this->text.getGlobalBounds().getSize().y / 2);
	this->text.setPosition(this->buttonShape.getPosition());
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(this->buttonShape);
	window.draw(this->text);
}