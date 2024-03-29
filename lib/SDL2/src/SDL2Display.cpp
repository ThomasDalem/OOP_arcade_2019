/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SDL2Display
*/

#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "SDL2Display.hpp"
#include "Surface.hpp"
#include "Texture.hpp"

extern "C" SDL2Display *createObject()
{
    return (new SDL2Display);
}

SDL2Display::SDL2Display()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw(std::string("Error while SDL2 init"));
    }
    if (TTF_Init() == -1) {
        throw(std::string("Error while SDL2 ttf init"));
    }
    _window = std::make_unique<sdl2::Window>(1300, 1200);
    if (_window->window == nullptr) {
        throw(std::string("Error: cannot create SDL2 window"));
    }
    _renderer = std::make_unique<sdl2::Renderer>(SDL_CreateRenderer(_window->window, -1, 0));
    SDL_SetRenderDrawColor(_renderer->renderer, 0, 0, 0, 255);
    _font = sdl2::Font("./lib/SDL2/font/font.ttf");
}

SDL2Display::~SDL2Display()
{
    TTF_Quit();
    SDL_Quit();
}

void SDL2Display::display(std::vector<arcade::Element> const& elements, std::vector<arcade::Text> const& texts)
{
    SDL_RenderClear(_renderer->renderer);
    for (auto it = elements.begin(); it != elements.end(); it++) {
        displayElement(*it);
    }
    for (auto it = texts.begin(); it != texts.end(); it++) {
        displayText(*it);
    }
    SDL_RenderPresent(_renderer->renderer);
}

std::vector<arcade::Inputs> SDL2Display::getInputs()
{
    std::vector<arcade::Inputs> retreivedInputs;
    SDL_Event event;

    SDL_StartTextInput();
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            retreivedInputs.push_back(arcade::QUIT);
            return(retreivedInputs);
        }
        if (event.type == SDL_KEYDOWN) {
            retreivedInputs.push_back(manageKeyboardInput(event.key.keysym.sym));
        }
        if (event.type == SDL_TEXTINPUT) {
            _text += event.text.text;
        }
    }
    SDL_StopTextInput();
    return (retreivedInputs);
}

arcade::Inputs SDL2Display::manageKeyboardInput(SDL_Keycode key)
{
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (key == it->second) {
            return(it->first);
        }
        if (key == SDLK_BACKSPACE) {
            _text += '\b';
        }
    }
    return(arcade::UNDEFINED);
}

void SDL2Display::displayElement(arcade::Element const& element)
{
    sdl2::Surface surface;
    sdl2::Texture texture;
    SDL_Rect rect;
    SDL_Rect spriteRect = {
        static_cast<int>(element.rect.pos.x),
        static_cast<int>(element.rect.pos.y),
        static_cast<int>(element.rect.size.x),
        static_cast<int>(element.rect.size.y)
    };

    rect.h = 33;
    rect.w = 33;
    rect.x = element.position.x * 33;
    rect.y = element.position.y * 33;
    if (_loadedSurfaces.count(element.filename) == 1) {
       _loadedSurfaces[element.filename];
    } else {
        _loadedSurfaces[element.filename] = std::make_unique<sdl2::Surface>(IMG_Load(element.filename.c_str()));
    }
    texture = SDL_CreateTextureFromSurface(_renderer->renderer, _loadedSurfaces[element.filename]->surface);
    if (spriteRect.h == 0 || spriteRect.w == 0) {
        SDL_RenderCopy(_renderer->renderer, texture.texture, NULL, &rect);
        return;
    }
    SDL_RenderCopy(_renderer->renderer, texture.texture, &spriteRect, &rect);
}

void SDL2Display::displayText(arcade::Text const& text)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Rect rect = {
        static_cast<int>(text.pos.x * 33),
        static_cast<int>(text.pos.y * 33),
        static_cast<int>(12 * text.text.size()),
        24
    };
    sdl2::Surface surface;
    sdl2::Texture texture;

    surface = TTF_RenderText_Solid(_font.font, text.text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(_renderer->renderer, surface.surface);
    SDL_RenderCopy(_renderer->renderer, texture.texture, NULL, &rect);
}

std::string SDL2Display::getTextInput()
{
    std::string save = _text;

    _text.clear();
    return (save);
}
