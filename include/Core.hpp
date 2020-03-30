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

namespace arcade {
    class Core {
        public:

            // Ctor && Dtor
            Core(std::string path);
            ~Core();

            // Template
            template<typename T>
            T *createLib(const std::string &path)
            {
                void *libHandle = dlopen(path.c_str(), RTLD_LAZY);

                if (!libHandle) {
                    std::cerr << "dlopen: " << dlerror() << std::endl;
                    return (nullptr);
                }
                T *(*fptr)();
                T *module;
                fptr = (T *(*)()) dlsym(libHandle, "createObject");
                module = fptr();
                // dlclose(libHandle);
                return (module);
            }

            // Functions
            int arcade();

            // Getter && setter
            arcade::IDisplayModule *getDisplayModule() const;
            arcade::IGameModule *getGameModule() const;

            void setDisplayModule(arcade::IDisplayModule *newDisplay);
            void setGameModule(arcade::IGameModule *newGame);

        protected:
        private:
            // variables
            arcade::IDisplayModule *displayModule;
            arcade::IGameModule *gameModule;

            // Functions
            bool checkQuit(std::vector<arcade::Inputs> inputs) const;
            std::chrono::duration<double> getElapsedTime(
                std::chrono::time_point<std::chrono::system_clock> start,
                std::chrono::time_point<std::chrono::system_clock> end
            ) const;
    };
}

#endif /* !CORE_HPP_ */
