/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include <ctime>
#include "Core.hpp"

arcade::Core::Core(std::string path):
    _displayModule(_displayLoader.createLib(path))
{}

arcade::Core::~Core()
{}

arcade::IDisplayModule *arcade::Core::getDisplayModule() const
{
    return (_displayModule.get());
}

arcade::IGameModule *arcade::Core::getGameModule() const
{
    return (_gameModule.get());
}

arcade::DlLoader<arcade::IDisplayModule> arcade::Core::getDisplayLoader() const
{
    return (_displayLoader);
}

arcade::DlLoader<arcade::IGameModule> arcade::Core::getGameLoader() const
{
    return (_gameLoader);
}

void arcade::Core::setDisplayModule(arcade::IDisplayModule *newDisplay)
{
    _displayModule.reset(newDisplay);
}

void arcade::Core::setGameModule(arcade::IGameModule *newgame)
{
    _gameModule.reset(newgame);
}

bool arcade::Core::checkQuit(std::vector<arcade::Inputs> const& inputs) const
{
    if (inputs.size() == 0)
        return (false);
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::QUIT) {
            return (true);
        }
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

int arcade::Core::playMenu()
{
    std::vector<arcade::Inputs> inputs;

    while (checkQuit(inputs) == false) {
        inputs.clear();
        inputs = _displayModule->getInputs();
        _menu.playMenu(inputs);
        std::vector<arcade::Element> elements = _menu.getElements();
        std::vector<arcade::Text> texts = _menu.getTexts();
        _displayModule->display(elements, texts);
        if (_menu.getChangeLibs() == true) {
            _displayModule.reset(nullptr);
            setDisplayModule(_displayLoader.reloadLib(_menu.getSelectedGraphLib()));
            setGameModule(_gameLoader.reloadLib(_menu.getSelectedGameLib()));
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
        retreivedInputs = _displayModule->getInputs();
        inputs.insert(inputs.end(), retreivedInputs.begin(), retreivedInputs.end());
        now = std::chrono::system_clock::now();
        if (getElapsedTime(last, now).count() > 0.005) {
            _gameModule->playLoop(inputs);
            std::vector<arcade::Element> elements = _gameModule->getElements();
            std::vector<arcade::Text> texts = _gameModule->getTexts();
            _displayModule->display(elements, texts);
            inputs.clear();
            last = std::chrono::system_clock::now();
        }
    }
    return (0);
}