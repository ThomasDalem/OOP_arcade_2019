/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Element
*/

#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

#include <iostream>
#include <vector>
#include <ncurses.h>
#include <unordered_map>
#include "Position.hpp"
#include "Image.hpp"

namespace arcade
{
    class Element; // pour que les structure connaissent la class Element
}

enum Color {
    WHITE = 0,
    RED = 1,
    BLUE = 2,
    GREEN = 3,
    BLACK = 4,
};

typedef struct CoreGame_s {
    std::vector<std::string> map;
    arcade::Element *map_style;
    std::vector<arcade::Element *> allElements;
    bool end;
    bool pause;
    bool restart;
    int score;
    std::string name;
} CoreGame_t;

namespace arcade
{
    enum Input
    {
        QUIT = -1,
        PAUSE = 0,
        RESTART = 1,
        NEXT_LIB = 2,
        PREV_LIB = 3,
        NEXT_GAME = 4,
        PREV_GAME = 5,
        UP = 6,
        DOWN = 7,
        LEFT = 8,
        RIGHT = 9,

    };

    class ICoreGame
    {
        public:
            virtual ~ICoreGame() = default;
            virtual void SendInput(Input &input) = 0;
            virtual CoreGame_t *getData() = 0;
            //virtual int gameLoop() = 0;

        protected:
        private:
    };
} // namespace arcade

namespace arcade
{
    class Element {
        public:
            Element(Position pos, std::string elem, Color color, Image image);
            ~Element();
            Position getPosition() const;
            std::string getElement() const;
            Color getColor() const;
            Image getImage() const;
            void setPosition(Position &position);
            void setElement(std::string &element);
            void setColor(Color &color);
            void setImage(Image &image);

        protected:
        private:
            Color _color;
            Image _image;
            std::string _element;
            Position _position;
    };
} // namespace arcade

#endif /* !ELEMENT_HPP_ */
