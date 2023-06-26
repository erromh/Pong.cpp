#pragma once
#include <SFML/Graphics.hpp>
#include "App.h"
using namespace sf;

class GameMenu
{
private:

	friend class App;

	float menuX;
	float menuY;
	float menuStep;
	float maxMenu;
	int sizeFont;
	int mainMenuSelected;

	Font font;
	Text* mainMenu;
	Color menuColor = Color::Magenta;
	Color changeTextColor = Color::Blue;
	Color borderColor = Color::Red;

	void setInitText(Text& text, String str, float xPos, float yPos);	

	RenderWindow& myWindow;

public:

	GameMenu(RenderWindow& window, float menuX, float menuY,
		int index, String name[], int sizeFont = 60, int step = 80);

	~GameMenu()
	{
		delete[] mainMenu;
	}

	void draw(); // draw the menu

	void moveUpMenu(); 

	void moveDownMenu();

	void setColorTextMenu(Color menColor, Color ChoColor, Color BordColor);

	void alignMenu(int posx);

	int getSelectedMenuNumber() // Возвращает номер выбранного элемента меню
	{
		return mainMenuSelected;
	}

};

