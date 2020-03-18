/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <vector>
#include "Element.hpp"

namespace arcade {
    enum inputs {
        QUIT,
        PAUSE,
        RESTART,
        NEXT_LIB,
        PREV_LIB,
        NEXT_GAME,
        PREV_GAME,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;
    
            virtual void display(std::vector<Element *> &elements) = 0;
            virtual inputs getInputs(void) const = 0;
    };
}

#endif /* !IDISPLAYMODULE_HPP_ */
