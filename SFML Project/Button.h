#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Pen.h"

class Button
{
public:
	Button(sf::Vector2f position, sf::Vector2f size);

    void hovered(sf::Vector2f mousePosition);
    void setText(std::string buttonString);
    void render(sf::RenderWindow& window);
    bool containMouse(sf::Vector2f mousePosition);

protected:
    sf::RectangleShape buttonShape;
    //Pen pen;

private:
    sf::Font txtFont;
    sf::Text text;

    sf::Vector2f position;
};

class ClearBtn : public Button
{
public:
	ClearBtn(sf::Vector2f position, sf::Vector2f size);
    void clearScreen();
    void clicked(sf::Vector2f mousePosition);

private:

};

class ChangeBackground : public Button
{
public:
	ChangeBackground(sf::Vector2f position, sf::Vector2f size);

private:

};

class StartDrawBtn : public Button
{
public:
	StartDrawBtn(sf::Vector2f position, sf::Vector2f size);

private:

};