/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDL2Display
*/

#ifndef SDL2DISPLAY_HPP_
#define SDL2DISPLAY_HPP_

#include <unordered_map>
#include <SDL2/SDL.h>
#include "Window.hpp"
#include "IDisplayModule.hpp"
#include "Element.hpp"
#include "Text.hpp"
#include "Renderer.hpp"
#include "Font.hpp"
#include "Surface.hpp"

static const std::unordered_map<arcade::Inputs, SDL_Keycode> inputs = {
    {arcade::UP, SDLK_UP},
    {arcade::DOWN, SDLK_DOWN},
    {arcade::LEFT, SDLK_LEFT},
    {arcade::RIGHT, SDLK_RIGHT},
    {arcade::QUIT, SDLK_q},
    {arcade::NEXT_GAME, SDLK_l},
    {arcade::PREV_GAME, SDLK_o},
    {arcade::NEXT_LIB, SDLK_m},
    {arcade::PREV_LIB, SDLK_p},
    {arcade::PAUSE, SDLK_ESCAPE},
    {arcade::CONTINUE, SDLK_RETURN},
    {arcade::MENU, SDLK_e}
};

class SDL2Display : public arcade::IDisplayModule {
    public:
        SDL2Display();
        ~SDL2Display();

        void display(std::vector<arcade::Element> const& elements, std::vector<arcade::Text> const& texts);
        std::vector<arcade::Inputs> getInputs();
        std::string getTextInput();

    private:
        arcade::Inputs manageKeyboardInput(SDL_Keycode key);
        void displayElement(arcade::Element const& element);
        void displayText(arcade::Text const& text);

    private:
        std::unique_ptr<sdl2::Window> _window;
        std::unique_ptr<sdl2::Renderer> _renderer;
        sdl2::Font _font;
        std::unordered_map<std::string, std::unique_ptr<sdl2::Surface>> _loadedSurfaces;
        std::string _text;
};

#endif /* !SDL2DISPLAY_HPP_ */
