#include "ChangeBgInterface.h"

ChangeBgInterface::ChangeBgInterface(sf::Vector2f position)
{
	Radius = 10.0f;

	if (!this->changeColorFont.loadFromFile("PlayfairDisplayRegular-ywLOY.ttf"))
	{
		std::cout << "Error loading font" << std::endl;
	}
	this->changeColorText.setFont(changeColorFont);
	this->changeColorText.setFillColor(sf::Color::White);
	this->changeColorText.setCharacterSize(30);
	this->changeColorText.setString("Scroll to change the background color:");
	this->changeColorText.setOrigin(changeColorText.getGlobalBounds().getSize().x / 2, changeColorText.getGlobalBounds().getSize().y / 2);
	this->changeColorText.setPosition(400, 200);

	this->drawText.setFont(changeColorFont);
	this->drawText.setFillColor(sf::Color::White);
	this->drawText.setCharacterSize(30);
	this->drawText.setString("Click to Draw!");
	this->drawText.setOrigin(drawText.getGlobalBounds().getSize().x / 2, drawText.getGlobalBounds().getSize().y / 2);

	this->scroll.setRadius(Radius);
	this->scroll.setFillColor(sf::Color::White);
	this->scroll.setPosition(position);
	this->scroll.setOrigin(Radius, Radius);

	this->scrollPosition = scroll.getPosition().x;

	scrollLineR.setPosition(400, 300);
	scrollLineR.setSize(sf::Vector2f(400, 2));
	scrollLineR.setOrigin(scrollLineR.getSize().x / 2, scrollLineR.getSize().y / 2);

	scrollLineG.setPosition(400, 350);
	scrollLineG.setSize(sf::Vector2f(400, 2));
	scrollLineG.setOrigin(scrollLineG.getSize().x / 2, scrollLineB.getSize().y / 2);

	scrollLineB.setPosition(400, 400);
	scrollLineB.setSize(sf::Vector2f(400, 2));
	scrollLineB.setOrigin(scrollLineG.getSize().x / 2, scrollLineB.getSize().y / 2);

	box.setFillColor(sf::Color::Red);
	box.setSize(sf::Vector2f(550.0f, 400.f));
	box.setOrigin(sf::Vector2f(275.0f, 200.f));
	box.setOutlineThickness(2.0f);
	box.setOutlineColor(sf::Color::Black);
	box.setPosition(sf::Vector2f(400, 300));
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
	window.draw(this->scrollLineR);
	window.draw(this->scrollLineG);
	window.draw(this->scrollLineB);
}

//Change the background color based on RGB the values 
//The equation makes de bar value goes from 0 to 255. 
void ChangeBgInterface::changeColor(sf::RenderWindow& window)
{
	scrollPosition = ((this->scroll.getPosition().x - 600) + 400) / 1.5686f;

	window.clear(sf::Color(scrollPosition, scrollPosition, scrollPosition, 1));
}
