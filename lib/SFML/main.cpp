/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include <dlfcn.h>
#include <iostream>
#include "SFMLDisplay.hpp"

int main(void)
{
    void *handle = dlopen("./lib_arcade_sfml.so", RTLD_LAZY | RTLD_GLOBAL);
    arcade::IDisplayModule *displayModule;
    arcade::inputs key = arcade::PAUSE;
    std::vector<arcade::Element *> elements;
    std::string image("./minecraft.png");
    std::unique_ptr<SFMLDisplay> (*fptr)();

    if (handle == NULL) {
        std::cout << "Handle is empty" << std::endl;
        std::cout << "Error: " << dlerror() << std::endl;
        return (84);
    }
    fptr = (std::unique_ptr<SFMLDisplay>(*)())dlsym(handle, "createObject");
    displayModule = fptr().get();
    elements[0] = new arcade::Element(arcade::WHITE, image, Point{0, 0});
    while (key != arcade::QUIT) {
        displayModule->display(elements);
    }
    dlclose(handle);
    return (0);
}
