/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Menu
*/

#include <fstream>
#include <filesystem>
#include <regex>
#include <iostream>
#include <iterator>
#include "Menu.hpp"

namespace fs = std::filesystem;
using namespace arcade;

Menu::Menu(): _changeLibs(false), _pressedContinue(false), _playerName("Unknown")
{
    retreiveLibs();
}

Menu::~Menu()
{}

bool Menu::getChangeLibs() const
{
    return (_changeLibs);
}

void Menu::setChangeLibs(bool status)
{
    _changeLibs = status;
}

std::string const& Menu::getSelectedGraphLib() const
{
    return(_selectedGraphLib->second);
}

std::string const& Menu::getSelectedGameLib() const
{
    return(_selectedGameLib->second);
}

std::vector<arcade::Element> const& Menu::getElements() const
{
    return (_elements);
}

std::vector<arcade::Element> const& Menu::getPauseElements() const
{
    return (_pauseElements);
}

std::vector<arcade::Text> const& Menu::getTexts() const
{
    return (_texts);
}

std::vector<arcade::Text> const& Menu::getPauseTexts() const
{
    return (_pauseTexts);
}

std::string const& Menu::getPlayerName() const
{
    return (_playerName);
}

void Menu::retreiveLibs()
{
    const std::string gamesPath = "./games/";
    const std::string graphPath = "./lib/";
    const std::regex libReg("lib_arcade_\\w+.so");

    for (auto &it: std::filesystem::directory_iterator(gamesPath)) {
        if (std::regex_match(it.path().filename().string(), libReg)) {
            _gamesLibs[getLibName(it.path().filename().string())] = it.path();
        }
    }
    for (auto &it: std::filesystem::directory_iterator(graphPath)) {
        if (std::regex_match(it.path().filename().string(), libReg)) {
            _graphLibs[getLibName(it.path().filename().string())] = it.path();
        }
    }
    _selectedGraphLib = _graphLibs.begin();
    _selectedGameLib = _gamesLibs.begin();
}

void Menu::playMenu(std::vector<arcade::Inputs> const& inputs, std::string const& textInputs)
{
    _changeLibs = false;
    _texts.clear();
    if (_pressedContinue) {
        getPlayerName(inputs, textInputs);
    } else {
        manageInputs(inputs);
    }
    _texts.push_back({"ARCADE", {18, 5}, arcade::RED});
    _texts.push_back({"Games:", {5, 10}, arcade::RED});
    _texts.push_back({"Graphics:", {15, 10}, arcade::RED});
    displayLibs(_gamesLibs, _selectedGameLib, 5);
    displayLibs(_graphLibs, _selectedGraphLib, 15);
}

void Menu::pauseMenu(std::vector<arcade::Inputs> const& inputs)
{
    double pos = 10;

    _changeLibs = false;
    _pauseTexts.clear();
    if (manageInputs(inputs) == 1) {
        _pressedContinue = false;
        _changeLibs = true;
    }
    _pauseTexts.push_back(Text{"ARCADE", Point{18, 4}, arcade::RED});
    _pauseTexts.push_back(Text{"Press E to return to menu", Point{22, 8}, arcade::RED});
    _pauseTexts.push_back(Text{"Press Q to quit", Point{22, 10}, arcade::RED});
    _pauseTexts.push_back(Text{"Graphics:", Point{13, 8}, arcade::RED});
    for (auto it = _graphLibs.begin(); it != _graphLibs.end(); it++, pos += 2) {
        if (it == _selectedGraphLib) {
            _pauseTexts.push_back(Text{it->first + " <-", Point{13, pos}, arcade::RED});
        } else {
            _pauseTexts.push_back(Text{it->first, Point{13, pos}, arcade::RED});
        }
    }
}

int Menu::manageInputs(std::vector<arcade::Inputs> const& inputs)
{
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::NEXT_LIB && std::next(_selectedGraphLib, 1) != _graphLibs.end()) {
            _selectedGraphLib++;
        } else if (*it == arcade::PREV_LIB && _selectedGraphLib != _graphLibs.begin()) {
            _selectedGraphLib--;
        } else if (*it == arcade::NEXT_GAME && std::next(_selectedGameLib, 1) != _gamesLibs.end()) {
            _selectedGameLib++;
        } else if (*it == arcade::PREV_GAME && _selectedGameLib != _gamesLibs.begin()) {
            _selectedGameLib--;
        } else if (*it == arcade::CONTINUE) {
            _pressedContinue = true;
            return (1);
        }
    }
    return (0);
}

std::string Menu::getLibName(std::string const& filename) const
{
    std::string libName = filename.substr(11, filename.find_last_of('.') - 11);

    libName[0] = std::toupper(libName[0]);
    return (libName);
}

void Menu::setDisplayScores(std::vector<Score> const& scores)
{
    double pos = 12;

    _texts.push_back({"Scores:", {28, 10}, arcade::RED});
    for (auto it = scores.begin(); it != scores.end(); it++) {
        _texts.push_back({it->playerName, {25, pos}, arcade::RED});
        _texts.push_back({std::to_string(it->score), {32, pos}, arcade::RED});
        pos += 2;
    }
}

void Menu::displayLibs(std::map<std::string, std::string> const& libs,
                       std::map<std::string, std::string>::iterator &selectedLib,
                       double posX)
{
    double pos = 12;

    for (auto it = libs.begin(); it != libs.end(); it++) {
        if (it == selectedLib) {
            _texts.push_back({it->first + " <-", {posX, pos}, arcade::RED});
        } else {
            _texts.push_back({it->first, {posX, pos}, arcade::RED});
        }
        pos += 2;
    }
}

void Menu::getPlayerName(std::vector<arcade::Inputs> const& inputs, std::string const& textInputs)
{
    _texts.push_back({"Enter your name: (max 10 characters)", {5, 18}, arcade::RED});
    if (textInputs[0] == '\b' && _playerName.length() > 0) {
        _playerName.pop_back();
    }
    if (_playerName.length() < 10 && textInputs[0] > 32 && std::isalpha(textInputs[0])) {
        _playerName += textInputs;
    }
    _texts.push_back({_playerName, {5, 20}, arcade::RED});
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::CONTINUE) {
            _pressedContinue = false;
            _changeLibs = true;
        }
    }
}
