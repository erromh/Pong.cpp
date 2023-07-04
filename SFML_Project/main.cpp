#include <SFML/Graphics.hpp>
#include "App.h"

RenderWindow window(VideoMode(1400, 700), "", Style::Default);

int main()
{
    App application;
    application.show_menu(window);

    return 0;
}