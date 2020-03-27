/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibCacaDisplay
*/

#ifndef LIBCACADISPLAY_HPP_
#define LIBCACADISPLAY_HPP_

#include <caca.h>
#include <memory>
#include "IDisplayModule.hpp"

static const std::pair<arcade::color, caca_color> colorsPair[5] = {
    {arcade::RED, CACA_RED},
    {arcade::BLUE, CACA_BLUE},
    {arcade::GREEN, CACA_GREEN},
    {arcade::YELLOW, CACA_YELLOW},
    {arcade::BLACK, CACA_BLACK}
};

static const std::pair<arcade::Inputs, caca_key> inputsPair[4] = {
    {arcade::UP, CACA_KEY_UP},
    {arcade::DOWN, CACA_KEY_DOWN},
    {arcade::LEFT, CACA_KEY_LEFT},
    {arcade::RIGHT, CACA_KEY_RIGHT}
};

class LibCacaDisplay : public arcade::IDisplayModule {
    public:
        LibCacaDisplay();
        ~LibCacaDisplay();

        void display(std::vector<arcade::Element> &elements);
        std::vector<arcade::Inputs> getInputs(void);

    private:
        arcade::Inputs getInput(caca_event_t &event);
        void setColor(arcade::color color);

    private:
        caca_display_t *_display;
        caca_canvas_t *_canvas;
};

#endif /* !LIBCACADISPLAY_HPP_ */
