#include "ChangeBgInterface.h"

ChangeBgInterface::ChangeBgInterface(sf::Vector2f position)
{
	Radius = 10.0f;

	scrollLine.setPosition(400, 350);
	scrollLine.setSize(sf::Vector2f(400, 2));
	scrollLine.setOrigin(scrollLine.getSize().x / 2, scrollLine.getSize().y / 2);

	box.setFillColor(sf::Color::Red);
	box.setSize(sf::Vector2f(550.0f, 300.f));
	box.setOrigin(sf::Vector2f(275.0f, 200.f));
	box.setOutlineThickness(2.0f);
	box.setOutlineColor(sf::Color::Black);
	box.setPosition(sf::Vector2f(400, 300));

	if (!changeColorFont.loadFromFile("PlayfairDisplayRegular-ywLOY.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}
	changeColorText.setFont(changeColorFont);
	changeColorText.setFillColor(sf::Color::White);
	changeColorText.setCharacterSize(30);
	changeColorText.setString("Scroll to change the background color:");
	changeColorText.setOrigin(changeColorText.getGlobalBounds().getSize().x / 2, changeColorText.getGlobalBounds().getSize().y / 2);
	changeColorText.setPosition(400, 200);

	this->scroll.setRadius(Radius);
	this->scroll.setFillColor(sf::Color::White);
	this->scroll.setPosition(position);
	this->scroll.setOrigin(Radius, Radius);

	this->scrollPosition = scroll.getPosition().x;
}

void ChangeBgInterface::renderBg(sf::RenderWindow& window)
{
	changeColor(window);
}

void ChangeBgInterface::renderBox(sf::RenderWindow& window)
{
	window.draw(this->box);
	window.draw(this->changeColorText);
	window.draw(this->scroll);
	window.draw(this->scrollLine);
}

//Change the background color based on RGB the values 
//The equation makes de bar value goes from 0 to 255. 
void ChangeBgInterface::changeColor(sf::RenderWindow& window)
{
	scrollPosition = ((this->scroll.getPosition().x - 600) + 400) / 1.5686f;

	window.clear(sf::Color(scrollPosition, scrollPosition, scrollPosition, 1));
}
