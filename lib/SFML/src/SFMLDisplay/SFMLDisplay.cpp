/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLDisplay
*/

#include "SFMLDisplay.hpp"

extern "C" std::unique_ptr<SFMLDisplay> createObject()
{
    return (std::make_unique<SFMLDisplay>());
}

SFMLDisplay::SFMLDisplay() : _window(sf::VideoMode(800, 600), "Game")
{}

SFMLDisplay::~SFMLDisplay()
{}

void SFMLDisplay::display(std::vector<arcade::Element *> &elements)
{
    _window.clear();
    for (auto it = elements.begin(); it != elements.end(); it++) {
        sf::Texture texture;
        if (texture.loadFromFile((*it)->getFilename()))
            throw(std::string("Error: failed to load texture from" + (*it)->getFilename()));
        sf::Sprite sprite(texture);
        _window.draw(sprite);
    }
    _window.display();
}

arcade::inputs SFMLDisplay::getInputs(void) const
{
    return (arcade::inputs::QUIT);
}
