#include <SFML/Graphics.hpp>
#include "GameMenu.h"
using namespace sf;

GameMenu::GameMenu(RenderWindow const& window, Vector2f const& menuSize, Color const& menuColor, Vector2f const& menuPosition)
{
	menu_shape.setSize(menuSize);
	menu_shape.setFillColor(menuColor);
	menu_shape.setPosition(menuPosition);
}

GameMenu::GameMenu(Vector2f const& menuSize, Color const& menuColor, Vector2f const& menuPosition)
{
	menu_shape.setSize(menuSize);
	menu_shape.setFillColor(menuColor);
	menu_shape.setPosition(menuPosition);
}

void GameMenu::show_menu(RenderWindow const& window)
{
	RectangleShape menu_item1;
	menu_item1.setFillColor(Color::Green);

	float item1_Xposition = (window.getSize().x / 2.0);
	float item1_Yposition = (window.getSize().y / 2.0);
}

RectangleShape GameMenu::get_menu_shape()
{
	return menu_shape;
}