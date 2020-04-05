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

bool arcade::Core::checkInput(std::vector<arcade::Inputs> const& inputs, arcade::Inputs checkInput) const
{
    if (inputs.size() == 0)
        return (false);
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == checkInput) {
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
    std::vector<Score> scores;

    while (checkInput(inputs, arcade::QUIT) == false) {
        inputs.clear();
        inputs = _displayModule->getInputs();
        _menu.playMenu(inputs, _displayModule->getTextInput());
        _menu.setDisplayScores(_scoreManager.getScores());
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

int arcade::Core::playPause(std::vector<arcade::Inputs> & inputs)
{
    while (checkInput(inputs, arcade::QUIT) == false) {
        inputs.clear();
        inputs = _displayModule->getInputs();
        std::vector<arcade::Element> elements = _menu.getPauseElements();
        std::vector<arcade::Text> texts = _menu.getPauseTexts();
        _displayModule->display(elements, texts);
        if (checkInput(inputs, arcade::MENU) == true)
            return (42);
        if (_menu.getChangeLibs() == true) {
            _displayModule.reset(nullptr);
            setDisplayModule(_displayLoader.reloadLib(_menu.getSelectedGraphLib()));
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
    int resultPause = 0;
    std::vector<arcade::Inputs> inputs;
    std::vector<arcade::Inputs> retreivedInputs;

    if (playMenu() == -1) {
        return (0);
    }
    _scoreManager.addScore("pseudo");
    while (checkInput(inputs, arcade::QUIT) == false) {
        retreivedInputs = _displayModule->getInputs();
        inputs.insert(inputs.end(), retreivedInputs.begin(), retreivedInputs.end());
        if (checkInput(inputs, arcade::PAUSE) == true)
            resultPause = playPause(inputs);
        if (resultPause == -1)
            return (0);
        if (resultPause == 42)
            return (arcade());
        now = std::chrono::system_clock::now();
        if (getElapsedTime(last, now).count() > 0.005) {
            _scoreManager.updateActualScore(_gameModule->playLoop(inputs));
            std::vector<arcade::Element> elements = _gameModule->getElements();
            std::vector<arcade::Text> texts = _gameModule->getTexts();
            _displayModule->display(elements, texts);
            inputs.clear();
            last = std::chrono::system_clock::now();
        }
    }
    _scoreManager.registerActualScore();
    return (0);
}