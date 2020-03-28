/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLDisplay
*/

#include <iostream>
#include <memory>
#include "SFMLDisplay.hpp"

extern "C" SFMLDisplay *createObject()
{
    return (new SFMLDisplay);
}

SFMLDisplay::SFMLDisplay() : _window(sf::VideoMode(1300, 1200), "Game")
{
    _window.setFramerateLimit(120);
}

SFMLDisplay::~SFMLDisplay()
{
    if (_window.isOpen())
        _window.close();
}

void SFMLDisplay::display(std::vector<arcade::Element> &elements)
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::IntRect rect;

    if (_window.isOpen() == false)
        return;
    _window.clear();
    for (auto it = elements.begin(); it != elements.end(); it++) {
        texture.loadFromFile(it->filename);
        sprite.setTexture(texture);
        position = sf::Vector2f(it->position.x * 32, it->position.y * 32);
        sprite.setPosition(position);
        setDisplayRect(sprite, it->rect);
        _window.draw(sprite);
    }
    _window.display();
}

std::vector<arcade::Inputs> SFMLDisplay::getInputs(void)
{
    sf::Event event;
    std::vector<arcade::Inputs> inputs;

    if (_window.isOpen() == false)
        return (inputs);
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)
                inputs.push_back(arcade::UP);
            if (event.key.code == sf::Keyboard::Down)
                inputs.push_back(arcade::DOWN);
            if (event.key.code == sf::Keyboard::Left)
                inputs.push_back(arcade::LEFT);
            if (event.key.code == sf::Keyboard::Right)
                inputs.push_back(arcade::RIGHT);
            if (event.key.code == sf::Keyboard::Q)
                inputs.push_back(arcade::QUIT);
        }
        if (event.type == sf::Event::Closed)
            inputs.push_back(arcade::QUIT);
    }
    return (inputs);
}

void SFMLDisplay::setDisplayRect(sf::Sprite &sprite, arcade::Rect rect)
{
    sf::IntRect sfRect;

    if (rect.size.x == 0 || rect.size.y == 0)
        return;
    sfRect.top = rect.pos.y;
    sfRect.left = rect.pos.x;
    sfRect.height = rect.size.y;
    sfRect.width = rect.size.x;
    sprite.setTextureRect(sfRect);
}
