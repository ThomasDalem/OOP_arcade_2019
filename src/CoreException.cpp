/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreException
*/

#include "CoreException.hpp"

CoreException::CoreException(std::string const& message) noexcept : _message(message)
{}

CoreException::~CoreException()
{}

char const *CoreException::what() const noexcept
{
    return (_message.data());
}
