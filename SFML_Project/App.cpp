#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "LeftPlayer.h"
#include "RightPlayer.h"
#include "Ball.h"
#include "App.h"

using namespace sf;

void App::show(RenderWindow & window) const
{
	using namespace std;

	srand(time(NULL));

	float ballPosX = rand() % 930;
	float ballPosY = rand() % 570;

	window.setFramerateLimit(60);

	Texture textureBackGround;
	textureBackGround.loadFromFile("D:/c++++/SFML_Project/Background.png");

	Sprite spriteBackgrund;
	spriteBackgrund.setTexture(textureBackGround);
	spriteBackgrund.setPosition(0, 0);

	Vector2f leftPosition(0, 225);
	Vector2f leftSize(0, 150);

	// Don't forget -  rightPosition(950, 225);
	
	Color colorleft(0, 0, 255);
	LeftPlayer leftpl(leftPosition, colorleft);

	Color colorRight(0, 0, 255);
	Vector2f rightPosition(950, 225);
	RightPlayer rightPlayer(rightPosition, colorRight);

	Vector2f ballPosition(ballPosX, ballPosY);
	Vector2f ballVelocity(8, 8);
	Color colorBall(0, 255, 255);
	Ball ball1(ballPosition, ballVelocity, colorBall);
	
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
					ball1.printBallLeft(ball1, leftpl);
					//ball1.ballMoving(leftpl);
				}
			}
		}

		ball1.ballMoving(leftpl);
		ball1.Collision(ball1, leftpl, rightPlayer);

		window.clear();
		window.draw(spriteBackgrund);
		window.draw(leftpl.getShape());
		window.draw(rightPlayer.getShape());
		window.draw(ball1.getShape());
		window.display();

	}
	
}