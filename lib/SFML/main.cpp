/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include <dlfcn.h>
#include <iostream>
#include "IDisplayModule.hpp"

using namespace std;

bool checkQuit(vector<arcade::inputs> inputs)
{
    if (inputs.size() == 0)
        return (false);
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::QUIT)
            return (true);
    }
    return (false);
}

int main(void)
{
    void *handle = dlopen("./lib_arcade_sfml.so", RTLD_LAZY);
    arcade::inputs key = arcade::PAUSE;
    vector<arcade::Element *> elements;
    string image("./minecraft.png");
    arcade::IDisplayModule *(*fptr)();
    arcade::IDisplayModule *displayModule;

    fptr = (arcade::IDisplayModule *(*)()) dlsym(handle, "createObject");
    displayModule = fptr();
    elements.push_back(new arcade::Element(arcade::WHITE, image, Point{0, 0}));
    while (checkQuit(displayModule->getInputs()) != true) {
        displayModule->display(elements);
    }
    delete(elements[0]);
    delete(displayModule);
    dlclose(handle);
    return (0);
}
