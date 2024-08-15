#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Button
{
public:
	Button(sf::Vector2f position, sf::Vector2f size);

    void hovered(sf::Vector2f mousePosition);
    void setText(std::string buttonString);
    void render(sf::RenderWindow& window);

    sf::RectangleShape buttonShape;
protected:

private:
    bool isChangingBg;

    sf::Font txtFont;
    sf::Text text;

    sf::Vector2f position;
};
