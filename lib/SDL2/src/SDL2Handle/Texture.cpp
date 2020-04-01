/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Texture
*/

#include "Texture.hpp"

using namespace sdl2;

Texture::Texture(): texture(nullptr)
{}

Texture::Texture(Texture const& other): texture(other.texture)
{}

Texture::Texture(SDL_Texture *other): texture(other)
{}

Texture::~Texture()
{
    SDL_DestroyTexture(texture);
}

bool Texture::operator==(Texture const& other) const
{
    if (other.texture == texture) {
        return (true);
    }
    return (false);
}

void Texture::operator=(SDL_Texture *other)
{
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    texture = other;
}

void Texture::operator=(Texture const& other)
{
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    texture = other.texture;
} 

