#include "Game.h"

Game::Game() : 
    pen(sf::Color::White, 5.0f), 
    changeBg(sf::Vector2f(250.0f, 20.0f), sf::Vector2f(210.0f, 40.0f)), 
    startDraw(sf::Vector2f(550.0f, 20.0f), sf::Vector2f(210.0f, 40.0f)),
    myScroll(sf::Vector2f(400.0f, 350.0f)),
    red(sf::Color::Red, sf::Vector2f(20.0f, 200.0f)),
    green(sf::Color::Green, sf::Vector2f(20.0f, 250.0f)),
    blue(sf::Color::Blue, sf::Vector2f(20.0f, 300.0f)),
    black(sf::Color::Black, sf::Vector2f(20.0f, 350.0f)),
    white(sf::Color::White, sf::Vector2f(20.0f, 400.0f))
{
	window.create(sf::VideoMode(800, 600), "My Window");
    window.setFramerateLimit(60);
    dt = clock.restart().asSeconds();

    changeBg.setText("Set Background Color");
    startDraw.setText("Draw");

    penIncrease = 6.0f;

    currentMode = SettingsMode;
}

void Game::run()
{
    while (window.isOpen())
    {
        handleEvents();
        input();
        draw();
    }
}

void Game::draw()
{
    window.clear();

    myScroll.renderBg(window);

    if(currentMode == SettingsMode)
    {
        myScroll.renderBox(window);
    }

    if(currentMode == DrawMode)
    {
        red.render(window);
        green.render(window);
        blue.render(window);
        black.render(window);
        white.render(window);
        pen.render(window);
    }

    changeBg.render(window);
    startDraw.render(window);

    window.display();
}

void Game::input()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && currentMode == DrawMode)
    {
        pen.setDrawing(true);
    }
    else
    {
        pen.setDrawing(false);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        pen.increaseSize(penIncrease);
        if (penIncrease <= 15.0f)
        {
            penIncrease += 0.5f;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        pen.decreaseSize(penIncrease);
        if (penIncrease <= 16.0f && penIncrease >= 5.0f)
        {
            penIncrease -= 0.5f;
        }
    }
}

void Game::handleEvents()
{
    dt = clock.restart().asSeconds();

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

     GetMousePosition(window);
     if(currentMode == SettingsMode)
     {
         useScroll();
     }

     startDraw.hovered(mousePosition);
     changeBg.hovered(mousePosition);

     pen.setPosition(mousePosition);
     pen.drawScreen(window, mousePosition);

     changingStates();
     changePenColor();
}

void Game::changingStates()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && startDraw.buttonShape.getGlobalBounds().contains(mousePosition))
    {
        currentMode = DrawMode;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && changeBg.buttonShape.getGlobalBounds().contains(mousePosition))
    {
        currentMode = SettingsMode;
    }
}

void Game::changePenColor()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (red.setColorShape.getGlobalBounds().contains(mousePosition))
        {
            pen.setColor(red.setColorShape.getFillColor());
        }
        else if (green.setColorShape.getGlobalBounds().contains(mousePosition))
        {
            pen.setColor(green.setColorShape.getFillColor());
        }
        else if (blue.setColorShape.getGlobalBounds().contains(mousePosition))
        {
            pen.setColor(blue.setColorShape.getFillColor());
        }
        else if (black.setColorShape.getGlobalBounds().contains(mousePosition))
        {
            pen.setColor(black.setColorShape.getFillColor());
        }
        else if (white.setColorShape.getGlobalBounds().contains(mousePosition))
        {
            pen.setColor(white.setColorShape.getFillColor());
        }
    }
}

void Game::insideScroll(sf::CircleShape& scroll)
{
    float posY = scroll.getPosition().y;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mousePosition.x > 200 && mousePosition.x < 600)
    {
        scroll.setPosition(mousePosition.x, posY);
    }
}

void Game::useScroll()
{
    if (myScroll.scroll.getGlobalBounds().contains(mousePosition))
    {
        insideScroll(myScroll.scroll);
    }
}

sf::Vector2f Game::GetMousePosition(sf::RenderWindow& window)
{
    mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    return mousePosition;
}
