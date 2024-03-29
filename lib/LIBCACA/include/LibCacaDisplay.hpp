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
#include <unordered_map>
#include "IDisplayModule.hpp"

static const std::pair<arcade::Color, caca_color> colorsPair[5] = {
    {arcade::RED, CACA_RED},
    {arcade::BLUE, CACA_BLUE},
    {arcade::GREEN, CACA_GREEN},
    {arcade::YELLOW, CACA_YELLOW},
    {arcade::BLACK, CACA_BLACK}
};

static const std::unordered_map<arcade::Inputs, caca_key> inputs = {
    {arcade::UP, CACA_KEY_UP},
    {arcade::DOWN, CACA_KEY_DOWN},
    {arcade::LEFT, CACA_KEY_LEFT},
    {arcade::RIGHT, CACA_KEY_RIGHT},
    {arcade::PAUSE, CACA_KEY_ESCAPE},
    {arcade::CONTINUE, CACA_KEY_RETURN},
};

static const std::unordered_map<arcade::Inputs, char> inputsChar = {
    {arcade::NEXT_LIB, 'm'},
    {arcade::PREV_LIB, 'p'},
    {arcade::NEXT_GAME, 'l'},
    {arcade::PREV_GAME, 'o'},
    {arcade::QUIT, 'q'},
    {arcade::MENU, 'e'}
};

class LibCacaDisplay : public arcade::IDisplayModule {
    public:
        LibCacaDisplay();
        ~LibCacaDisplay();

        void display(std::vector<arcade::Element> const& elements, std::vector<arcade::Text> const& text);
        std::vector<arcade::Inputs> getInputs();
        std::string getTextInput();

    private:
        arcade::Inputs getInput(caca_event_t &event);
        void setColor(arcade::Color color);
        void displayElement(arcade::Element const& element);
        void displayText(arcade::Text const& element);

    private:
        caca_display_t *_display;
        caca_canvas_t *_canvas;
        std::string _text;
};

#endif /* !LIBCACADISPLAY_HPP_ */
