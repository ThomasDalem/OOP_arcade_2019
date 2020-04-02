/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <string>
#include <vector>
#include <map>
#include "Element.hpp"
#include "Text.hpp"
#include "Inputs.hpp"

namespace arcade {
    class Menu {
        public:
            Menu();
            ~Menu();

            bool getChangeLibs(void) const;
            void setChangeLibs(bool status);
            std::string const& getSelectedGraphLib(void) const;
            std::string const& getSelectedGameLib(void) const;

            void retreiveLibs(void);
            void playMenu(std::vector<arcade::Inputs> const& inputs);
            std::vector<arcade::Element> const& getElements(void) const;
            std::vector<arcade::Text> const& getTexts(void) const;

        private:
            void manageInputs(std::vector<arcade::Inputs> const& inputs);
            std::string getLibName(std::string const& filename) const;

        private:
            std::map<std::string, std::string> _gamesLibs;
            std::map<std::string, std::string> _graphLibs;
            std::vector<arcade::Element> _elements;
            std::vector<arcade::Text> _texts;
            std::map<std::string, std::string>::iterator _selectedGameLib;
            std::map<std::string, std::string>::iterator _selectedGraphLib;
            bool _changeLibs;
    };
}

#endif /* !MENU_HPP_ */
