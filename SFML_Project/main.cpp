#include <SFML/Graphics.hpp>
#include "App.h"

RenderWindow window(VideoMode(1000, 600), " ", Style::None);

int main()
{
    App application;
    application.show(window);

    return 0;
}