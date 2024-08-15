#pragma once

#include "ChangeBgInterface.h"
#include "DrawInterface.h"
#include "Button.h"

enum Modes
{
	SettingsMode,
	DrawMode
};

class Game {
public:
	Game();

	void run();
	void draw();
	void input();
	void handleEvents();
	void changingStates();
	void changePenColor();

	void insideScroll(sf::CircleShape& scroll);
	void useScroll();

	sf::Vector2f GetMousePosition(sf::RenderWindow& window);

private:
	sf::RenderWindow window;
	sf::Clock clock;
	float dt;

	sf::Vector2f mousePosition;
	sf::FloatRect mouseBounds;

	ChangeBgInterface scrollR;
	ChangeBgInterface scrollG;
	ChangeBgInterface scrollB;

	Pen pen;

	Button startDraw;
	Button changeBg;

	DrawInterface red;
	DrawInterface green;
	DrawInterface blue;
	DrawInterface black;
	DrawInterface white;

	Modes currentMode;
};