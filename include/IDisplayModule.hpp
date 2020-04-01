/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <vector>
#include "Inputs.hpp"
#include "Element.hpp"
#include "Text.hpp"

namespace arcade {
    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;

            virtual void display(std::vector<Element> const& elements, std::vector<Text> const& text) = 0;
            virtual std::vector<Inputs> getInputs(void) = 0;
    };
}

#endif /* !IDISPLAYMODULE_HPP_ */
