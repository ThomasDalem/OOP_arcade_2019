/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include <chrono>
#include <ctime>
#include "Core.hpp"

arcade::Core::Core(std::string path)
{
    displayModule = createLib<arcade::IDisplayModule>(path);
    gameModule = createLib<arcade::IGameModule>("./games/pacman/lib_arcade_pacman.so");
}

arcade::Core::~Core()
{
    delete(displayModule);
    delete(gameModule);
}

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

int arcade::Core::arcade()
{
    chrono::time_point<chrono::system_clock> now;
    chrono::time_point<chrono::system_clock> last = chrono::system_clock::now();

    std::vector<arcade::Inputs> inputs;
    std::vector<arcade::Inputs> retreivedInputs;

    while (checkQuit(inputs) != true) {
        retreivedInputs = displayModule->getInputs();
        inputs.insert(inputs.end(), retreivedInputs.begin(), retreivedInputs.end());
        now = chrono::system_clock::now();
        if (getElapsedTime(last, now).count() > 0.05) {
            gameModule->playLoop(inputs);
            std::vector<arcade::Element> elements = gameModule->getElements();
            displayModule->display(elements);
            inputs.clear();
            last = chrono::system_clock::now();
        }
    }
    return (0);
}