/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** LibCacaDisplay
*/

#include <iostream>
#include "LibCacaDisplay.hpp"

extern "C" LibCacaDisplay *createObject()
{
    return (new LibCacaDisplay);
}

LibCacaDisplay::LibCacaDisplay() :
    _display(caca_create_display(NULL)), _canvas(caca_get_canvas(_display))
{}

LibCacaDisplay::~LibCacaDisplay()
{
    caca_free_display(_display);
}

void LibCacaDisplay::display(std::vector<arcade::Element> const& elements, std::vector<arcade::Text> const &texts)
{
    caca_clear_canvas(_canvas);
    for (auto it = elements.begin(); it != elements.end(); it++) {
        displayElement(*it);
    }
    for (auto it = texts.begin(); it != texts.end(); it++) {
        displayText(*it);
    }
    caca_refresh_display(_display);
}

std::vector<arcade::Inputs> LibCacaDisplay::getInputs()
{
    std::vector<arcade::Inputs> inputs;
    caca_event_t ev;
    caca_event_type type;

    if (caca_get_event(_display, CACA_EVENT_KEY_PRESS | CACA_EVENT_QUIT, &ev, 10000) == 0) {
        return (inputs);
    }
    type = caca_get_event_type(&ev);
    if (type == CACA_EVENT_QUIT) {
        inputs.push_back(arcade::QUIT);
        return (inputs);
    }
    inputs.push_back(getInput(ev));
    return (inputs);
}

std::string LibCacaDisplay::getTextInput()
{
    std::string save = _text;

    _text.clear();
    return (save);
}

arcade::Inputs LibCacaDisplay::getInput(caca_event_t &ev)
{
    int key;

    key = caca_get_event_key_ch(&ev);
    _text += key;
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (key == it->second) {
            return (it->first);
        }
    }
    for (auto it = inputsChar.begin(); it != inputsChar.end(); it++) {
        if (key == it->second) {
            return(it->first);
        }
    }
    return (arcade::UNDEFINED);
}

void LibCacaDisplay::setColor(arcade::Color color)
{
    for (int i = 0; i < 5; i++) {
        if (colorsPair[i].first == color) {
            caca_set_color_ansi(_canvas, colorsPair[i].second, CACA_BLACK);
        }
    }
}

void LibCacaDisplay::displayElement(arcade::Element const& element)
{
    setColor(element.color);
    caca_fill_box(_canvas, element.position.x * 2, element.position.y * 2, 2, 2, (uint32_t)0x00002588);
    caca_set_color_ansi(_canvas, CACA_WHITE, CACA_BLACK);
}

void LibCacaDisplay::displayText(arcade::Text const& text)
{
    caca_put_str(_canvas, text.pos.x * 2, text.pos.y * 2, text.text.c_str());
}
