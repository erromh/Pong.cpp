#include <SFML/Graphics.hpp>
#include "App.h"
#include "GameMenu.h"

RenderWindow window(VideoMode(1400, 700), " ", Style::Default);

int main()
{
    App application;
    //application.show_menu(window);
    application.pvp_game(window);

    GameMenu d;

    return 0;
}