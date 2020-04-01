/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Renderer
*/

#include "Renderer.hpp"

using namespace sdl2;

Renderer::Renderer()
{}

Renderer::Renderer(SDL_Renderer *other): renderer(other)
{}

Renderer::Renderer(Renderer const& other): renderer(other.renderer)
{}

Renderer::~Renderer()
{}

bool Renderer::operator==(Renderer const& other) const
{
    if (other.renderer == renderer) {
        return (true);
    }
    return (false);
}

void Renderer::operator=(SDL_Renderer *other)
{
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    renderer = other;
}

void Renderer::operator=(Renderer const& other)
{
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    renderer = other.renderer;
}
