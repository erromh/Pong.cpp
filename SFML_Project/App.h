#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class App
{
public:
	void pvp_game(RenderWindow & window) const;
	void show_menu(/*RenderWindow& window*/);
	void online_game();
	void startGame();
	void endGame();
};

