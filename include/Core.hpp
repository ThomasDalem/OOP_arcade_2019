/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <chrono>
#include <iostream>
#include <dlfcn.h>
#include <memory>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "DlLoader.hpp"
#include "Menu.hpp"

namespace arcade {
    class Core {
        public:

            // Ctor && Dtor
            Core(std::string path);
            ~Core();

            // Functions
            int arcade();

            // Getter && setter
            arcade::IDisplayModule *getDisplayModule() const;
            arcade::IGameModule *getGameModule() const;
            arcade::DlLoader<arcade::IDisplayModule> getDisplayLoader() const;
            arcade::DlLoader<arcade::IGameModule> getGameLoader() const;
            void setDisplayModule(arcade::IDisplayModule *newDisplay);
            void setGameModule(arcade::IGameModule *newGame);

        private:
            // variables
            arcade::DlLoader<arcade::IDisplayModule> _displayLoader;
            arcade::DlLoader<arcade::IGameModule> _gameLoader;
            std::unique_ptr<arcade::IDisplayModule> _displayModule;
            std::unique_ptr<arcade::IGameModule> _gameModule;
            arcade::Menu _menu;
            ScoresManager _scoreManager;

            // Functions
            bool checkInput(std::vector<arcade::Inputs> const& inputs, arcade::Inputs checkInput) const;
            std::chrono::duration<double> getElapsedTime(
                std::chrono::time_point<std::chrono::system_clock> start,
                std::chrono::time_point<std::chrono::system_clock> end
            ) const;
            int playPause(std::vector<arcade::Inputs> & inputs);
            int playMenu();
    };
}

#endif /* !CORE_HPP_ */
