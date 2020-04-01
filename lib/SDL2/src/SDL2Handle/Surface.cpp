/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Surface
*/

#include "Surface.hpp"

using namespace sdl2;

Surface::Surface(): surface(nullptr)
{}

Surface::Surface(SDL_Surface *other): surface(other)
{}

Surface::Surface(Surface const& other): surface(other.surface)
{}

Surface::~Surface()
{
    SDL_FreeSurface(surface);
}

bool Surface::operator==(Surface const& other) const
{
    if (other.surface == surface) {
        return (true);
    }
    return (false);
}

void Surface::operator=(Surface const& other)
{
    if (surface) {
        SDL_FreeSurface(surface);
    }
    surface = other.surface;
}

void Surface::operator=(SDL_Surface *other)
{
    if (surface) {
        SDL_FreeSurface(surface);
    }
    surface = other;
}