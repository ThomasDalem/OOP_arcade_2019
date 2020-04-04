/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreException
*/

#ifndef COREEXCEPTION_HPP_
#define COREEXCEPTION_HPP_

#include <exception>
#include <string>

class CoreException : public std::exception {
    public:
        CoreException(std::string const& message) noexcept;
        ~CoreException();

        char const *what() const noexcept override;

    private:
        std::string _message;
};

#endif /* !COREEXCEPTION_HPP_ */
