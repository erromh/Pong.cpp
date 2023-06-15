#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class App
{
	friend class Leftplayer;
	friend class RightPlayer;
	friend class Ball;

public:
	void show(RenderWindow & window) const;

private:
	//RenderWindow window(VideoMode(1000, 600), " ", Style::Default);

	std::unique_ptr<RenderWindow> window = std::make_unique<RenderWindow>();

};

