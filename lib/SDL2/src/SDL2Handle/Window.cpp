/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Window
*/

#include <iostream>
#include "Window.hpp"

using namespace sdl2;

Window::Window(): window(nullptr)
{}

Window::Window(int x, int y)
{
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        throw(std::string("Error: Window could not be created"));
    }
}

Window::~Window()
{
    if (window) {
        SDL_DestroyWindow(window);
    }
}

bool Window::operator==(Window const& other) const
{
    if (other.window == window) {
        return (true);
    }
    return (false);
}

void Window::operator=(Window const& other)
{
    if (window) {
        SDL_DestroyWindow(window);
    }
    window = other.window;
}

void Window::operator=(SDL_Window *other)
{
    if (window) {
        SDL_DestroyWindow(window);
    }
    window = other;
}
