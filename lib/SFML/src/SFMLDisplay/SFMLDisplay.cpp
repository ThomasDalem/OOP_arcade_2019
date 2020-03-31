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

void SFMLDisplay::display(std::vector<arcade::Element> const& elements)
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::IntRect rect;

    if (_window.isOpen() == false)
        return;
    _window.clear();
    for (auto it = elements.begin(); it != elements.end(); it++) {
        if (isTextureLoaded(it->filename)) {
            texture = _loadedTextures.find(it->filename)->second;
        } else {
            texture.loadFromFile(it->filename);
            _loadedTextures[it->filename] = texture;
        }
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
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                inputs.push_back(arcade::UP);
                break;
            case sf::Keyboard::Down:
                inputs.push_back(arcade::DOWN);
                break;
            case sf::Keyboard::Left:
                inputs.push_back(arcade::LEFT);
                break;
            case sf::Keyboard::Right:
                inputs.push_back(arcade::RIGHT);
                break;
            case sf::Keyboard::Q:
                inputs.push_back(arcade::QUIT);
                break;
            default:
                break;
            }
        }
        if (event.type == sf::Event::Closed)
            inputs.push_back(arcade::QUIT);
        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            _window.setView(sf::View(visibleArea));
        }
    }
    return (inputs);
}

void SFMLDisplay::setDisplayRect(sf::Sprite &sprite, arcade::Rect const& rect)
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

bool SFMLDisplay::isTextureLoaded(std::string const& filename) const
{
    return (_loadedTextures.count(filename) == 1);
}
