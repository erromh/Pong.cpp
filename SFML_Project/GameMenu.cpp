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

	// PvP game
	float firstMenuItemX = static_cast<float>(menuWindow.getSize().x / 2);
	float firstMenuItemY = static_cast<float>(menuWindow.getSize().y / 2);
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("PvP game");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(firstMenuItemX, firstMenuItemY);

	// Online game
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::Blue);
	mainMenu[1].setString("Online game");
	mainMenu[1].setCharacterSize(40);
	mainMenu[1].setPosition(400, 700);

	// About game
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::Blue);
	mainMenu[2].setString("About game");
	mainMenu[2].setCharacterSize(40);
	mainMenu[2].setPosition(400, 800);

	// Exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::Blue);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(40);
	mainMenu[3].setPosition(400, 900);

	gameMenuSelected = -1;
}

GameMenu::~GameMenu()
{

}

int GameMenu::menuPress()
{
	return gameMenuSelected;
}

void GameMenu::showMenu(RenderWindow& menuWindow)
{
	for (int i = 0; i < max_menu_items; i++)
	{
		menuWindow.draw(mainMenu[i]);
	}
}

void GameMenu::menuMoveUp()
{
	if (gameMenuSelected - 1 >= 0)
	{
		mainMenu[gameMenuSelected].setFillColor(Color::Blue);

		gameMenuSelected--;

		if (gameMenuSelected == -1)
		{
			gameMenuSelected = 2;
		}

		mainMenu[gameMenuSelected].setFillColor(Color::Red);
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

		mainMenu[gameMenuSelected].setFillColor(Color::Red);
	}
}