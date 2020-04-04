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
#include "Text.hpp"

namespace arcade {
    class IGameModule {
        public:
            virtual ~IGameModule() = default;

            virtual int playLoop(std::vector<arcade::Inputs> const& inputs) = 0;
            virtual void restart() = 0;
            virtual std::vector<arcade::Element> const& getElements() const = 0;
            virtual std::vector<arcade::Text> const& getTexts() const = 0;
    };
}

#endif /* !IGAMEMODULE_HPP_ */
