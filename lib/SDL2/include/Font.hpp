/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Font
*/

#ifndef FONT_HPP_
#define FONT_HPP_

#include <string>
#include <SDL2/SDL_ttf.h>

namespace sdl2 {
    class Font {
        public:
            explicit Font();
            explicit Font(std::string const& filepath);
            ~Font();
    
            void operator=(TTF_Font *font);
    
            TTF_Font *font;
    };
}

#endif /* !FONT_HPP_ */
