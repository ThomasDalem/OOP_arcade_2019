/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DlLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>
#include <iostream>
#include <dlfcn.h>

namespace arcade {
    class DlLoader {
        public:

            // Ctor && Dtor
            DlLoader();
            ~DlLoader();

            // Template
            template<typename T>
            T *createLib(const std::string &path)
            {
                libHandle = dlopen(path.c_str(), RTLD_LAZY);
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

            template<typename T>
            T *reloadLib(const std::string &path)
            {
                dlclose(libHandle);
                return (createLib(path));
            }
        protected:
        private:
            void *libHandle;
    };
}

#endif /* !DLLOADER_HPP_ */
