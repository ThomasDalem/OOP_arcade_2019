#include <caca.h>
#include <dlfcn.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include "Point.hpp"
#include "IDisplayModule.hpp"

/*
int main(void)
{
    caca_canvas_t *cv; caca_display_t *dp; caca_event_t ev;
    dp = caca_create_display(NULL);
    if(!dp) return 1;
    cv = caca_get_canvas(dp);
    caca_set_display_title(dp, "Hello!");
    caca_set_color_ansi(cv, CACA_BLACK, CACA_WHITE);
    caca_put_str(cv, 0, 0, "This is a message");
    caca_refresh_display(dp);
    caca_get_event(dp, CACA_EVENT_KEY_PRESS, &ev, -1);
    caca_free_display(dp);
    return 0;
}
*/

using namespace std;

bool checkQuit(vector<arcade::Inputs> inputs)
{
    if (inputs.size() == 0)
        return (false);
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::QUIT)
            return (true);
    }
    return (false);
}

chrono::duration<double> getElapsedTime(
    chrono::time_point<chrono::system_clock> start,
    chrono::time_point<chrono::system_clock> end
)
{
    chrono::duration<double> elapsedSeconds = end - start;

    return (elapsedSeconds);
}

int main(void)
{
    void *handle = dlopen("./lib_arcade_sfml.so", RTLD_LAZY);
    arcade::Inputs key = arcade::PAUSE;
    vector<arcade::Element> elements;
    string image("./minecraft.png");
    arcade::IDisplayModule *(*fptr)();
    arcade::IDisplayModule *displayModule;
    chrono::time_point<chrono::system_clock> now;
    chrono::time_point<chrono::system_clock> last = chrono::system_clock::now();

    fptr = (arcade::IDisplayModule *(*)()) dlsym(handle, "createObject");
    displayModule = fptr();
    elements.push_back(arcade::Element{image, arcade::WHITE, Point{0, 0}, arcade::Rect{Point{0, 0}, Point{0, 0}}});
    while (checkQuit(displayModule->getInputs()) != true) {
        now = chrono::system_clock::now();
        if (getElapsedTime(last, now).count() > 0.5) {
            displayModule->display(elements);
            last = chrono::system_clock::now();
            elements[0].position.x += 1; // décale le perso de 1 pour test
        }
    }
    delete(displayModule);
    dlclose(handle);
    return (0);
}
