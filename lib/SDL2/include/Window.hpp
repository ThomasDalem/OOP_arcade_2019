/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SDL2/SDL.h>
#include <memory>
#include "IDisplayModule.hpp"

namespace sdl2 {
    class Window {
        public:
            explicit Window();
            explicit Window(int sizeX, int sizeY);
            ~Window();

            bool operator==(Window const& other) const;
            void operator=(Window const& other);
            void operator=(SDL_Window *other);

            SDL_Window *window;
    };
}

#endif /* !Window_HPP_ */
