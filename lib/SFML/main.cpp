/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include <dlfcn.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include "Point.hpp"
#include "IDisplayModule.hpp"

using namespace std;

bool checkQuit(vector<arcade::Inputs> inputs)
{
    if (inputs.size() == 0)
        return (false);
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::QUIT)
            return (true);
    }
    return (false);
}

chrono::duration<double> getElapsedTime(
    chrono::time_point<chrono::system_clock> start,
    chrono::time_point<chrono::system_clock> end
)
{
    chrono::duration<double> elapsedSeconds = end - start;

    return (elapsedSeconds);
}

int main(void)
{
    void *handle = dlopen("./lib_arcade_sfml.so", RTLD_LAZY);
    arcade::Inputs key = arcade::PAUSE;
    vector<arcade::Element> elements;
    string image("./minecraft.png");
    arcade::IDisplayModule *(*fptr)();
    arcade::IDisplayModule *displayModule;
    chrono::time_point<chrono::system_clock> now;
    chrono::time_point<chrono::system_clock> last = chrono::system_clock::now();

    fptr = (arcade::IDisplayModule *(*)()) dlsym(handle, "createObject");
    displayModule = fptr();
    elements.push_back(arcade::Element{image, arcade::WHITE, Point{0, 0}});
    while (checkQuit(displayModule->getInputs()) != true) {
        now = chrono::system_clock::now();
        if (getElapsedTime(last, now).count() > 0.5) {
            displayModule->display(elements);
            last = chrono::system_clock::now();
            elements[0].position.x += 1; // décale le perso de 1 pour test
        }
    }
    delete(displayModule);
    dlclose(handle);
    return (0);
}
