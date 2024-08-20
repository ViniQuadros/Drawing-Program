#include "Pen.h"

Pen::Pen(sf::Color penColor, float radius)
{
	this->pen.setFillColor(penColor);
	this->pen.setRadius(radius);
	this->pen.setOrigin(radius, radius);
	this->isDrawing = false;
}

void Pen::render(sf::RenderWindow& window)
{
	if (!this->lines.empty())
	{
		window.draw(&this->lines[0], this->lines.size(), sf::LineStrip);
	}

	window.draw(this->pen);
}

void Pen::drawScreen(sf::RenderWindow& window, sf::Vector2f mousePos)
{
	if (isDrawing == true)
	{
		this->lines.push_back(sf::Vertex(sf::Vector2f(mousePos.x, mousePos.y), sf::Color(pen.getFillColor())));
	}
}

void Pen::changeColor(sf::Color penColor)
{
	this->pen.setFillColor(penColor);
}

void Pen::increaseSize(float radius)
{
	this->pen.setRadius(radius);
	this->pen.setOrigin(radius, radius);
}

void Pen::decreaseSize(float radius)
{
	this->pen.setRadius(radius);
	this->pen.setOrigin(radius, radius);
}

void Pen::setPosition(sf::Vector2f mousePosition)
{
	this->pen.setPosition(mousePosition);
}

void Pen::setColor(sf::Color color)
{
	this->pen.setFillColor(color);
}

void Pen::setDrawing(bool isDrawing)
{
	this->isDrawing = isDrawing;
}

void Pen::clearDraw()
{
	this->lines.clear();
}
