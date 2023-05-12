#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "LeftPlayer.h"
#include "RightPlayer.h"
#include "Ball.h"
#include "App.h"

using namespace sf;

//bool App::checkPlayerCollision(Ball& ball, LeftPlayer& leftplayer, RightPlayer& rightPlayer)
//{
//	if (leftplayer.m_Leftposition.x == ball.m_position.x)
//	{
//		return true;
//	}
//
//	return false;
//}

void App::show()
{
	using namespace std;

	const int WINDOW_HEIGHT = 600;
	const int WINDOW_WIDTH = 1000;

	srand(time(NULL));

	float ballPosX = rand() % 990 - 50;
	float ballPosY = rand() % 580;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), " ", Style::Default);
	window.setFramerateLimit(60);

	Texture textureBackGround;
	textureBackGround.loadFromFile("D:/c++++/SFML_Project/Background.png");

	Sprite spriteBackgrund;
	spriteBackgrund.setTexture(textureBackGround);
	spriteBackgrund.setPosition(0, 0);


	Vector2f leftPosition(0, 225);
	Vector2f leftSize(0, 150);

	// Don't forget -  rightPosition(950, 225)

	Vector2f rightPosition(950, 225);
	Vector2f ballPosition(ballPosX, ballPosY);
	Vector2f ballVelocity(8, 8);


	LeftPlayer leftpl(leftPosition, Color::Yellow);

	RightPlayer rightPlayer(rightPosition, Color::Red);

	Ball ball1(ballPosition, ballVelocity, Color::Cyan);

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

				if (event.key.code == Keyboard::Q)
				{
					//ball1.ballPosition(leftpl);
				}
			}
		}

		ball1.ballPosition(leftpl);

		ball1.CheckPaddleCollision(ball1, leftpl, rightPlayer);

		window.clear();
		window.draw(spriteBackgrund);
		window.draw(leftpl.getShape());
		window.draw(rightPlayer.getShape());
		window.draw(ball1.getShape());
		window.display();

	}
	
}