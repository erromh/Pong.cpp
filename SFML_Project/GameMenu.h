#pragma once
#include <SFML/Graphics.hpp>
#include "App.h"
using namespace sf;

class GameMenu
{
private:

	int menu_window_height;
	int menu_window_width;

	RectangleShape menu_shape;	

public:

	GameMenu(RenderWindow const& window, Vector2f const& menuSize, Color const& menuColor, Vector2f const& menuPosition);
	GameMenu(Vector2f const& menuSize, Color const& menuColor, Vector2f const& menuPosition);

	void show_menu(RenderWindow const& window);

	//void setSizeX(Vector2f const& )

	RectangleShape get_menu_shape();
};


