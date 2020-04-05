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
#include "ScoresManager.hpp"

namespace arcade {
    class Menu {
        public:
            Menu();
            ~Menu();

            bool getChangeLibs() const;
            void setChangeLibs(bool status);
            std::string const& getSelectedGraphLib() const;
            std::string const& getSelectedGameLib() const;
            std::vector<arcade::Element> const& getElements() const;
            std::vector<arcade::Text> const& getTexts() const;
            std::vector<arcade::Text> const& getPauseTexts() const;
            std::vector<arcade::Element> const& getPauseElements() const;
            std::string const& getPlayerName() const;

            void retreiveLibs();
            void retreivePause();
            void playMenu(std::vector<arcade::Inputs> const& inputs, std::string const& textInputs);
            void pauseMenu(std::vector<arcade::Inputs> const& inputs);
            void setDisplayScores(std::vector<Score> const& scores);

        private:
            int manageInputs(std::vector<arcade::Inputs> const& inputs);
            std::string getLibName(std::string const& filename) const;
            void getPlayerName(std::vector<arcade::Inputs> const& inputs, std::string const& textInputs);
            void displayLibs(
                std::map<std::string, std::string> const& map,
                std::map<std::string, std::string>::iterator &selectedLib,
                double posX
            );

        private:
            std::map<std::string, std::string> _gamesLibs;
            std::map<std::string, std::string> _graphLibs;
            std::map<std::string, std::string> _pauseGraphLibs;
            std::vector<arcade::Element> _elements;
            std::vector<arcade::Element> _pauseElements;
            std::vector<arcade::Text> _texts;
            std::vector<arcade::Text> _pauseTexts;
            std::map<std::string, std::string>::iterator _selectedGameLib;
            std::map<std::string, std::string>::iterator _selectedGraphLib;
            bool _changeLibs;
            bool _pressedContinue;
            std::string _playerName;
    };
}

#endif /* !MENU_HPP_ */
