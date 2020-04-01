/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include <SDL2/SDL.h>

namespace sdl2 {
    class Renderer {
        public:
            explicit Renderer();
            explicit Renderer(SDL_Renderer *other);
            explicit Renderer(Renderer const& other);
            ~Renderer();

            bool operator==(Renderer const& other) const;
            void operator=(SDL_Renderer *other);
            void operator=(Renderer const& other);

            SDL_Renderer *renderer;
    };
}

#endif /* !RENDERER_HPP_ */
