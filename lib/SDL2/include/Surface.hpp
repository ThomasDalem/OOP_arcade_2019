/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Surface
*/

#ifndef SURFACE_HPP_
#define SURFACE_HPP_

#include <SDL2/SDL.h>

namespace sdl2 {
    class Surface {
        public:
            explicit Surface();
            explicit Surface(SDL_Surface *other);
            explicit Surface(Surface const& other);
            ~Surface();

            bool operator==(Surface const& other) const;
            void operator=(Surface const& other);
            void operator=(SDL_Surface *other);

            SDL_Surface *surface;
    };
}

#endif /* !SURFACE_HPP_ */
