#include <SFML/Graphics.hpp>
#include "App.h"

RenderWindow window(VideoMode(1400, 700), " ", Style::Default);

int main()
{
    App application;
    application.pvp_game(window);

    return 0;
}