#include <SFML/Graphics.hpp>
#include "GameMenu.h"
#include <iostream>

using namespace std;
using namespace sf;

GameMenu::GameMenu(float width, float height, RenderWindow const& menuWindow)
{
	if (!font.loadFromFile("D:/c++++/SFML_Project/MilkyMania.ttf"))
	{
		cout << "No fonts\n";
	}

	float MenuItemX = static_cast<float>(menuWindow.getSize().x - 1200);
	float MenuItemY = static_cast<float>(menuWindow.getSize().y / 2);

	// Header
	header.setFont(font);
	header.setFillColor(Color::Cyan);
	header.setString("Cool pong");
	header.setCharacterSize(90);
	header.setPosition(MenuItemX, 100);

	// PvP game
	int fontSize = 50;
	
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("PvP game");
	mainMenu[0].setCharacterSize(fontSize);
	mainMenu[0].setPosition(MenuItemX, 300);

	// Online game
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::Blue);
	mainMenu[1].setString("Online game");
	mainMenu[1].setCharacterSize(fontSize);
	mainMenu[1].setPosition(MenuItemX, 400);

	// About game
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::Blue);
	mainMenu[2].setString("About game");
	mainMenu[2].setCharacterSize(fontSize);
	mainMenu[2].setPosition(MenuItemX, 500);

	// Exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::Blue);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(fontSize);
	mainMenu[3].setPosition(MenuItemX, 600);

	gameMenuSelected = -1;
}

GameMenu::~GameMenu()
{

}

int GameMenu::menuPress()
{
	return gameMenuSelected;
}

void GameMenu::showMenuItems(RenderWindow& menuWindow)
{
	for (int i = 0; i < max_menu_items; ++i)
	{
		menuWindow.draw(mainMenu[i]);
	}
}

void GameMenu::showHeader(RenderWindow& menuWindow)
{
	menuWindow.draw(header);
}

void GameMenu::menuMoveUp()
{
	if (gameMenuSelected - 1 >= 0)
	{
		mainMenu[gameMenuSelected].setFillColor(Color::Blue);

		gameMenuSelected--;

		if (gameMenuSelected == -1)
		{
			gameMenuSelected = 4;
		}

		mainMenu[gameMenuSelected].setFillColor(Color::White);
	}
}

void GameMenu::menuMoveDown()
{
	if (gameMenuSelected + 1 <= max_menu_items)
	{
		mainMenu[gameMenuSelected].setFillColor(Color::Blue);
		gameMenuSelected++;

		if (gameMenuSelected == 4)
		{
			gameMenuSelected = 0;
		}

		mainMenu[gameMenuSelected].setFillColor(Color::White);
	}
}