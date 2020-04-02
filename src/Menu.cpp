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
#include "Menu.hpp"

namespace fs = std::filesystem;
using namespace arcade;

Menu::Menu(): _changeLibs(false)
{
    retreiveLibs();
}

Menu::~Menu()
{}

bool Menu::getChangeLibs(void) const
{
    return (_changeLibs);
}

void Menu::setChangeLibs(bool status)
{
    _changeLibs = status;
}

std::string const& Menu::getSelectedGraphLib(void) const
{
    return(_selectedGraphLib->second);
}

std::string const& Menu::getSelectedGameLib(void) const
{
    return(_selectedGameLib->second);
}

void Menu::retreiveLibs(void)
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

void Menu::playMenu(std::vector<arcade::Inputs> const& inputs)
{
    double pos = 10;

    _texts.clear();
    manageInputs(inputs);
    _texts.push_back(Text{"ARCADE", Point{18, 5}, arcade::RED});
    for (auto it = _gamesLibs.begin(); it != _gamesLibs.end(); it++) {
        if (it == _selectedGameLib) {
            _texts.push_back(Text{it->first + "<-", Point{5, pos}, arcade::RED});    
        } else {
            _texts.push_back(Text{it->first, Point{5, pos}, arcade::RED});
        }
        pos += 2;
    }
    pos = 10;
    for (auto it = _graphLibs.begin(); it != _graphLibs.end(); it++) {
        if (it == _selectedGraphLib) {
            _texts.push_back(Text{it->first + " <-", Point{20, pos}, arcade::RED});
        } else {
            _texts.push_back(Text{it->first, Point{20, pos}, arcade::RED});
        }
        pos += 2;
    }
}

std::vector<arcade::Element> const& Menu::getElements(void) const
{
    return (_elements);
}

std::vector<arcade::Text> const& Menu::getTexts(void) const
{
    return (_texts);
}

void Menu::manageInputs(std::vector<arcade::Inputs> const& inputs)
{
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::NEXT_LIB && _selectedGraphLib != _graphLibs.end()) {
            _selectedGraphLib++;
        } else if (*it == arcade::PREV_LIB && _selectedGraphLib != _graphLibs.begin()) {
            _selectedGraphLib--;
        } else if (*it == arcade::NEXT_GAME && _selectedGameLib != _gamesLibs.end()) {
            _selectedGameLib++;
        } else if (*it == arcade::PREV_GAME && _selectedGameLib != _gamesLibs.begin()) {
            _selectedGameLib--;
        } else if (*it == arcade::CONTINUE) {
            _changeLibs = true;
        }
    }
}

std::string Menu::getLibName(std::string const& filename) const
{
    std::string libName = filename.substr(11, filename.find_last_of('.') - 11);

    libName[0] = std::toupper(libName[0]);
    return (libName);
}
