#pragma once
#include <SFML/Graphics.hpp>
#include "App.h"
using namespace sf;

#define max_menu_items 4

class GameMenu
{
private:

	int gameMenuSelected;
	Font font;
	Text mainMenu[max_menu_items];

public:

	GameMenu(float width, float height, RenderWindow const& menuWindow);

	void showMenu(RenderWindow& menuWindow);
	void menuMoveUp();
	void menuMoveDown();

	int menuPress();

	~GameMenu();
};


