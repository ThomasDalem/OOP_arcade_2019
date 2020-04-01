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
    _font.loadFromFile("./lib/SFML/font/font.ttf");
}

SFMLDisplay::~SFMLDisplay()
{
    if (_window.isOpen())
        _window.close();
}

void SFMLDisplay::display(std::vector<arcade::Element> const& elements, std::vector<arcade::Text> const& text)
{
    if (_window.isOpen() == false)
        return;
    _window.clear();
    for (auto it = elements.begin(); it != elements.end(); it++) {
        displayElement(*it);
    }
    for (auto it = text.begin(); it != text.end(); it++) {
        displayText(*it);
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

void SFMLDisplay::displayElement(arcade::Element const& element)
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (isTextureLoaded(element.filename)) {
        texture = _loadedTextures.find(element.filename)->second;
    } else {
        texture.loadFromFile(element.filename);
        _loadedTextures[element.filename] = texture;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(element.position.x * 32, element.position.y * 32));
    setDisplayRect(sprite, element.rect);
    _window.draw(sprite);
}

void SFMLDisplay::displayText(arcade::Text const& text)
{
    sf::Text displayText(text.text, _font, 22);
    sf::Vector2f pos(text.pos.x * 32, text.pos.y * 32);

    displayText.setPosition(pos);
    _window.draw(displayText);
}
