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

        void display(std::vector<arcade::Element> &elements);
        std::vector<arcade::Inputs> getInputs(void);

    private:
        sf::RenderWindow _window;
};

#endif /* !SFMLDISPLAY_HPP_ */
