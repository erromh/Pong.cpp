#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class App
{
	friend class Players;
	friend class RightPlayer;
	friend class Ball;

public:
	void pvp_game(RenderWindow & window) const;
	void show_menu(RenderWindow& window);
	void online_game();
	void startGame();
};

