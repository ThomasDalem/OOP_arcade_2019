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
            // arcade::Menu menu;
            arcade::DlLoader<arcade::IDisplayModule> displayLoader;
            arcade::DlLoader<arcade::IGameModule> gameLoader;
            arcade::IDisplayModule *displayModule;
            arcade::IGameModule *gameModule;
            arcade::Menu _menu;

            // Functions
            bool checkQuit(std::vector<arcade::Inputs> inputs) const;
            std::chrono::duration<double> getElapsedTime(
                std::chrono::time_point<std::chrono::system_clock> start,
                std::chrono::time_point<std::chrono::system_clock> end
            ) const;
            int playMenu(void);
    };
}

#endif /* !CORE_HPP_ */
