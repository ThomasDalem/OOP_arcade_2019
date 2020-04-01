/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Font
*/

#include "Font.hpp"

using namespace sdl2;

Font::Font(): font(nullptr)
{}

Font::Font(std::string const& filepath): font(TTF_OpenFont(filepath.c_str(), 22))
{}

Font::~Font()
{}

void Font::operator=(TTF_Font *other)
{
    if (font) {
        TTF_CloseFont(font);
    }
    font = other;
}
