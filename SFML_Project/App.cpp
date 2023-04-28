#include <iostream>
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
#include "RightPlayer.h"
#include "Ball.h"
#include "App.h"

using namespace sf;
using namespace std;

void App::show()
{
	const int WINDOW_HEIGHT = 600;
	const int WINDOW_WIDTH = 1000;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), " ", Style::None);
	window.setFramerateLimit(60);

	Texture textureBackGround;
	textureBackGround.loadFromFile("D:/c++++/SFML_Project/Background.png");

	Sprite spriteBackgrund;

	spriteBackgrund.setTexture(textureBackGround);
	spriteBackgrund.setPosition(0, 0);

	Vector2f leftPosition(0, 225);
	Vector2f rightPosition(950, 225);
	Vector2f ballPosition(484, 284);

	LeftPlayer leftpl(leftPosition, Color::Red);

	RightPlayer rightPlayer(rightPosition, Color::Blue);
	Ball ball1(ballPosition, Color::Cyan);

	Clock clock;
	Time dt = clock.restart();

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
				{
					window.close();
				}

				if (event.key.code == Keyboard::S)
				{
					leftpl.moveDown();
				}

				if (event.key.code == Keyboard::W)
				{
					leftpl.moveUp();
				}

				if (event.key.code == Keyboard::Up)
				{
					rightPlayer.moveUp();
				}

				if (event.key.code == Keyboard::Down)
				{
					rightPlayer.moveDown();
				}
			}
		}

		//ball1.ballPosition();

		window.clear();
		window.draw(spriteBackgrund);
		window.draw(leftpl.getShape());
		window.draw(rightPlayer.getShape());
		//window.draw(ball1.getShape());
		window.display();

	}
}