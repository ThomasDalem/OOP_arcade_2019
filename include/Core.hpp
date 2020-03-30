/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
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

            // Temaplate
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
                return (module);
            }

            // Functions
            int arcade();

            // Getter && setter
            // arcade::IDisplayModule getDisplayModule();
            // arcade::IGameModule getGameModule();

            // void setDisplayModule(arcade::IDisplayModule newModule);
            // void setGameModule(arcade::IGameModule newGame);

        protected:
        private:
            arcade::IDisplayModule *displayModule;
            arcade::IGameModule *gameModule;
    };
}

#endif /* !CORE_HPP_ */
