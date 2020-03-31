/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLDisplay
*/

#ifndef SFMLDISPLAY_HPP_
#define SFMLDISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"

class SFMLDisplay : public arcade::IDisplayModule {
    public:
        SFMLDisplay();
        ~SFMLDisplay();

        void display(std::vector<arcade::Element> const& elements, std::vector<arcade::Text> const& text);
        std::vector<arcade::Inputs> getInputs(void);

    private:
        void setDisplayRect(sf::Sprite &sprite, arcade::Rect const& rect);
        bool isTextureLoaded(std::string const& filename) const;
        void displayElement(arcade::Element const& element);
        void displayText(arcade::Text const& text);

    private:
        sf::RenderWindow _window;
        std::map<std::string, sf::Texture> _loadedTextures;
        sf::Font _font;
};

#endif /* !SFMLDISPLAY_HPP_ */
