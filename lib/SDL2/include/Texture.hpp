/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <SDL2/SDL.h>

namespace sdl2 {
    class Texture {
        public:
            explicit Texture();
            explicit Texture(SDL_Texture *other);
            explicit Texture(Texture const& other);
            ~Texture();

            bool operator==(Texture const& other) const;
            void operator=(SDL_Texture *other);
            void operator=(Texture const& other);

            SDL_Texture *texture;
    };
}

#endif /* !TEXTURE_HPP_ */
