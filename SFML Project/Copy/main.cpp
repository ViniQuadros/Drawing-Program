#include <iostream>
#include <string>
#include <cmath>

#include "player.h"
#include "SFML/Graphics.hpp"

static void moveEnemy(sf::Sprite& sprite_enemy, const sf::Sprite& sprite, float speed)
{
    // Calcule o vetor direção entre o sprite e o alvo
    sf::Vector2f direction = sprite.getPosition() - sprite_enemy.getPosition();

    // Normalize o vetor direção (transforme-o em um vetor unitário)
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        direction /= length;
    }

    // Mova o sprite na direção do vetor direção
    sprite_enemy.move(direction * speed);

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Survivor"); // Crie uma janela SFML

    sf::Texture texture; // Crie uma textura vazia do player
    texture.create(50, 50); // Defina a largura e a altura da textura
    sf::Uint8 pixels[100 * 100 * 4]; // Preencha a textura com uma cor
    for (int i = 0; i < 100 * 100; ++i)
    {
        pixels[i * 4 + 0] = 255; // R
        pixels[i * 4 + 1] = 0;   // G
        pixels[i * 4 + 2] = 0;   // B
        pixels[i * 4 + 3] = 255; // A
    }
    texture.update(pixels);
    sf::Sprite sprite; // Crie um sprite usando a textura
    sprite.setTexture(texture);
    sprite.setPosition(400, 550);

    sf::Texture texture_weapon; // Crie uma textura vazia da arma
    texture_weapon.create(25, 25); // Defina a largura e a altura da textura
    sf::Uint8 pixels_w[100 * 100 * 4]; // Preencha a textura com uma cor 
    for (int i = 0; i < 100 * 100; ++i)
    {
        pixels_w[i * 4 + 0] = 255; // R
        pixels_w[i * 4 + 1] = 255;   // G
        pixels_w[i * 4 + 2] = 0;   // B
        pixels_w[i * 4 + 3] = 255; // A
    }
    texture_weapon.update(pixels_w);
    sf::Sprite sprite_weapon; // Crie um sprite usando a textura
    sprite_weapon.setTexture(texture_weapon);
    sprite_weapon.setPosition(400, 300);
    bool hasGun = false;

    sf::Texture texture_enemy;
    texture_enemy.create(30, 30);
    sf::Uint8 pixels_e[100 * 100 * 4]; // Preencha a textura com uma cor 
    for (int i = 0; i < 100 * 100; ++i)
    {
        pixels_e[i * 4 + 0] = 255; // R
        pixels_e[i * 4 + 1] = 200;   // G
        pixels_e[i * 4 + 2] = 255;   // B
        pixels_e[i * 4 + 3] = 255; // A
    }
    texture_enemy.update(pixels_e);
    sf::Sprite sprite_enemy;
    sprite_enemy.setTexture(texture_enemy);

    sf::Font font; //Cria a fonte
    if (!font.loadFromFile("sans.ttf"))
    {
        std::cerr << "Erro ao carregar a fonte!" << std::endl;
        return 1;
    }

    int life = 3; //Vidas do jogador
    sf::Text text; // Cria um texto
    text.setFont(font); // Define a fonte
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    int score_value = 0; //Score do Jogador
    sf::Text score; 
    score.setFont(font);
    score.setCharacterSize(24);
    score.setFillColor(sf::Color::White);

    while (window.isOpen()) // Loop principal
    {
        sf::Event event; // Verifique os eventos
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        text.setString("Vidas: " + std::to_string(life));
        score.setString("Score: " + std::to_string(score_value));

        float move_speed = 0.1f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sprite.getPosition().x > 0)
        {
            sprite.move(-move_speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite.getPosition().x + sprite.getGlobalBounds().width < window.getSize().x)
        {
            sprite.move(move_speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sprite.getPosition().y > 0)
        {
            sprite.move(0, -move_speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sprite.getPosition().y + sprite.getGlobalBounds().height < window.getSize().y)
        {
            sprite.move(0, move_speed);
        }

        if (sprite.getGlobalBounds().intersects(sprite_weapon.getGlobalBounds())) // Destroi a arma após colisão
        {
            sprite_weapon.setColor(sf::Color::Transparent);
            hasGun = true;
        }
        if (sprite_enemy.getGlobalBounds().intersects(sprite.getGlobalBounds())) // Destroi a arma após colisão
        {
            sprite_enemy.setPosition(-1000, -1000);
        }

        if (hasGun == true)
        {
            sprite_enemy.setPosition(100, 100);
            window.draw(sprite_enemy);

            float enemySpeed = 0.1f;
            moveEnemy(sprite_enemy, sprite, enemySpeed);
        }
 
        window.clear(); // Limpe a janela

        window.draw(sprite); // Desenhe o sprite do Player na janela
        window.draw(sprite_weapon); // Desenhe o sprite da Arma na janela 

        int text_pixel = 10; //Posição do texto
        text.setPosition(text_pixel, text_pixel);
        score.setPosition(text_pixel, text.getPosition().y + text.getGlobalBounds().height + text_pixel);
        window.draw(text);
        window.draw(score);

        window.display(); // Atualize a janela
    }

    return 0;
}

