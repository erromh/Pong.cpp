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
	window.setFramerateLimit(60);

	Texture textureBackGround;
	textureBackGround.loadFromFile("D:/c++++/SFML_Project/Background.png");

	Sprite spriteBackgrund;
	spriteBackgrund.setTexture(textureBackGround);
	spriteBackgrund.setPosition(0, 0);

	// Player on the left
	
	Vector2f leftSize(50, 150);
	float leftPlayerPosY = ((window.getSize().y / 2.0) - (leftSize.y / 2));
	Vector2f leftPosition(0, leftPlayerPosY);
	Color colorleft(0, 0, 255);

	LeftPlayer leftpl(leftSize, leftPosition, colorleft);


	// Player on the right

	Vector2f rightSize(50, 150);

	float rightPlayerPosX = (window.getSize().x - rightSize.x);
	float rightPlayerPosY = ((window.getSize().y / 2.0) - (rightSize.y / 2));

	Color colorRight(0, 0, 255);
	Vector2f rightPosition(rightPlayerPosX, rightPlayerPosY);
	RightPlayer rightPlayer(rightSize, rightPosition, colorRight);

	// Ball

	Vector2f ballVelocity(8, 8);	
	Color colorBall(0, 255, 255);

	Ball ball1(ballVelocity, colorBall);

	float ballPosX = (window.getSize().x / 2.0);
	float ballPosY = (window.getSize().y / 2.0);

	ball1.setBallPositionX(ballPosX);
	ball1.setBallPositionX(ballPosY);

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
					leftpl.moveDown(window);
				}

				if (event.key.code == Keyboard::W)
				{
					leftpl.moveUp(window);
				}

				if (event.key.code == Keyboard::Up)
				{
					rightPlayer.moveUp(window);
				}

				if (event.key.code == Keyboard::Down)
				{
					rightPlayer.moveDown(window);
				}

				if (event.key.code == Keyboard::Q)
				{
					ball1.printBallLeft(ball1, leftpl);
					//ball1.ballMoving(leftpl);
					cout << "window.getSize().x = " << window.getSize().x << endl; // 1000
					cout << "window.getSize().y = " << window.getSize().y << endl; // 600 

				}
			}
		}

		ball1.ballMoving(ball1, window);
		ball1.Collision(ball1, leftpl, rightPlayer);


		window.clear();
		//window.draw(spriteBackgrund);
		window.draw(leftpl.getShape());
		window.draw(rightPlayer.getShape());
		window.draw(ball1.getShape());
		window.display();

	}
	
}