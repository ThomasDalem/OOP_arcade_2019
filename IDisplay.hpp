/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

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
class IDisplay
{
public:
    virtual ~IDisplay() = default;
    virtual void clear() = 0;
    virtual void dispMap(std::string *map, Element *map_element) = 0;
    virtual void dispObject(std::vector<Element *> allElement) = 0;
    virtual int menu(std::vector<std::string> gameLib_path) = 0;
    virtual int getEvent() = 0;

protected:
private:
};

} // namespace arcade
#endif /* !IDISPLAY_HPP_ */
