/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLDisplay
*/

#ifndef SFMLDISPLAY_HPP_
#define SFMLDISPLAY_HPP_

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"

static const std::unordered_map<arcade::Inputs, sf::Keyboard::Key> inputs = {
    {arcade::UP, sf::Keyboard::Up},
    {arcade::DOWN, sf::Keyboard::Down},
    {arcade::LEFT, sf::Keyboard::Left},
    {arcade::RIGHT, sf::Keyboard::Right},
    {arcade::QUIT, sf::Keyboard::Q},
    {arcade::NEXT_GAME, sf::Keyboard::L},
    {arcade::PREV_GAME, sf::Keyboard::O},
    {arcade::NEXT_LIB, sf::Keyboard::M},
    {arcade::PREV_LIB, sf::Keyboard::P},
    {arcade::PAUSE, sf::Keyboard::Escape},
    {arcade::CONTINUE, sf::Keyboard::Return},
    {arcade::MENU, sf::Keyboard::E}
};

class SFMLDisplay : public arcade::IDisplayModule {
    public:
        SFMLDisplay();
        ~SFMLDisplay();

        void display(std::vector<arcade::Element> const& elements, std::vector<arcade::Text> const& text);
        std::vector<arcade::Inputs> getInputs();
        std::string getTextInput();

    private:
        arcade::Inputs checkKeys(sf::Keyboard::Key key);
        void setDisplayRect(sf::Sprite &sprite, arcade::Rect const& rect);
        bool isTextureLoaded(std::string const& filename) const;
        void displayElement(arcade::Element const& element);
        void displayText(arcade::Text const& text);

    private:
        sf::RenderWindow _window;
        std::map<std::string, sf::Texture> _loadedTextures;
        sf::Font _font;
        std::string _text;
};

#endif /* !SFMLDISPLAY_HPP_ */
