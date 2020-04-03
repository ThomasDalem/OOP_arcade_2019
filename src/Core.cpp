/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include <ctime>
#include "Core.hpp"

arcade::Core::Core(std::string path)
{
    displayModule = displayLoader.createLib(path);
    gameModule = nullptr;
}

arcade::Core::~Core()
{
    delete(displayModule);
    delete(gameModule);
}

arcade::IDisplayModule *arcade::Core::getDisplayModule() const
{
    return (displayModule);
}

arcade::IGameModule *arcade::Core::getGameModule() const
{
    return (gameModule);
}

arcade::DlLoader<arcade::IDisplayModule> arcade::Core::getDisplayLoader() const
{
    return (displayLoader);
}

arcade::DlLoader<arcade::IGameModule> arcade::Core::getGameLoader() const
{
    return (gameLoader);
}

void arcade::Core::setDisplayModule(arcade::IDisplayModule *newDisplay)
{
    if (displayModule) {
        delete(displayModule);
    }
    displayModule = newDisplay;
}

void arcade::Core::setGameModule(arcade::IGameModule *newgame)
{
    if (gameModule) {
        delete(gameModule);
    }
    gameModule = newgame;
}

bool arcade::Core::checkQuit(std::vector<arcade::Inputs> inputs) const
{
    if (inputs.size() == 0)
        return (false);
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::QUIT)
            return (true);
    }
    return (false);
}

std::chrono::duration<double> arcade::Core::getElapsedTime(
    std::chrono::time_point<std::chrono::system_clock> start,
    std::chrono::time_point<std::chrono::system_clock> end
) const
{
    std::chrono::duration<double> elapsedSeconds = end - start;

    return (elapsedSeconds);
}

int arcade::Core::playMenu(void)
{
    std::vector<arcade::Inputs> inputs;

    while (checkQuit(inputs) == false) {
        inputs = displayModule->getInputs();
        _menu.playMenu(inputs);
        std::vector<arcade::Element> elements = _menu.getElements();
        std::vector<arcade::Text> texts = _menu.getTexts();
        displayModule->display(elements, texts);
        inputs.clear();
        if (_menu.getChangeLibs() == true) {
            delete(displayModule);
            displayModule = displayLoader.reloadLib(_menu.getSelectedGraphLib());
            gameModule = gameLoader.reloadLib(_menu.getSelectedGameLib());
            _menu.setChangeLibs(false);
            return (0);
        }
    }
    return (-1);
}

int arcade::Core::arcade()
{
    std::chrono::time_point<std::chrono::system_clock> now;
    std::chrono::time_point<std::chrono::system_clock> last = std::chrono::system_clock::now();

    std::vector<arcade::Inputs> inputs;
    std::vector<arcade::Inputs> retreivedInputs;

    if (playMenu() == -1) {
        return (0);
    }
    while (checkQuit(inputs) == false) {
        retreivedInputs = displayModule->getInputs();
        inputs.insert(inputs.end(), retreivedInputs.begin(), retreivedInputs.end());
        now = std::chrono::system_clock::now();
        if (getElapsedTime(last, now).count() > 0.005) {
            gameModule->playLoop(inputs);
            std::vector<arcade::Element> elements = gameModule->getElements();
            std::vector<arcade::Text> texts = gameModule->getTexts();
            displayModule->display(elements, texts);
            inputs.clear();
            last = std::chrono::system_clock::now();
        }
    }
    return (0);
}