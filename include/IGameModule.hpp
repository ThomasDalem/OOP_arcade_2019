/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <vector>
#include "Inputs.hpp"
#include "Element.hpp"

namespace arcade {
    class IGameModule {
        public:
            virtual ~IGameModule() = default;

            virtual void initGame(void) = 0;
            virtual void playLoop(std::vector<arcade::Inputs> inputs) = 0;
            virtual void restart() = 0;
            virtual const std::vector<arcade::Element> &getElements() const = 0;
    };
}

#endif /* !IGAMEMODULE_HPP_ */
