#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class App
{
	friend class Players;
	friend class RightPlayer;
	friend class Ball;

public:
	void show(RenderWindow & window) const;

};

