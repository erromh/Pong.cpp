#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "App.h"
#include "Players.h"

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
	
	// Player size
	Vector2f leftSize(25, 150);

	// Position y
	float PlayersPosY = ((window.getSize().y / 2.0) - (leftSize.y / 2));
	
	// Velocity
	float leftVelocity = 20;

	// Position setting
	Vector2f leftPosition(0, PlayersPosY);
	
	// Player color
	Color colorleft(255, 255, 255);

	// Create player
	Players leftPlayer(leftSize, leftPosition, colorleft);
	
	// Set velocity
	leftPlayer.setVelocity(leftVelocity);


	// Player on the right

	Vector2f rightSize(25, 150);

	float rightPlayerPosX = (window.getSize().x - rightSize.x);
	float rightPlayerPosY = ((window.getSize().y / 2.0) - (rightSize.y / 2));

	Color colorRight(45, 0, 255);
	Vector2f rightPosition(rightPlayerPosX, rightPlayerPosY);
	Players rightPlayer(rightSize, rightPosition, colorRight);

	// Ball

	Vector2f ballVelocity(8, 8);	
	Color colorBall(0, 255, 255);

	Ball ball1(ballVelocity, colorBall);

	float ballPosX = (window.getSize().x / 2.0);
	float ballPosY = (window.getSize().y / 2.0);

	ball1.setBallPositionX(ballPosX);
	ball1.setBallPositionX(ballPosY);

	// Delete fucking Playersclass

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
					leftPlayer.moveDown(window, leftPlayer);
					
					if (leftPlayer.m_Shape.getGlobalBounds().top + leftPlayer.m_Shape.getGlobalBounds().height > window.getSize().y)
					{
						leftPlayer.moveUp(window, leftPlayer);
					}
				}
				
				if (event.key.code == Keyboard::W)
				{
					leftPlayer.moveUp(window, leftPlayer);

					if (leftPlayer.m_Shape.getGlobalBounds().top < 0)
					{
						leftPlayer.moveDown(window, leftPlayer);
					}
				}

				if (event.key.code == Keyboard::Up)
				{
					rightPlayer.moveUp(window, rightPlayer);
					
					if (rightPlayer.m_Shape.getGlobalBounds().top < rightPlayer.getShape().getGlobalBounds().left)
					{
						rightPlayer.moveDown(window, rightPlayer);
					}
				}

				if (event.key.code == Keyboard::Down)
				{
					rightPlayer.moveDown(window, rightPlayer);
					
					if (rightPlayer.m_Shape.getGlobalBounds().top + rightPlayer.m_Shape.getGlobalBounds().height > window.getSize().y)
					{
						rightPlayer.moveDown(window, rightPlayer);
					}
				}

				if (event.key.code == Keyboard::Q)
				{
					ball1.printBallLeft(ball1, leftPlayer, rightPlayer);
					//ball1.ballMoving(leftPlayer);
					cout << "window.getSize().x = " << window.getSize().x << endl; // 
					cout << "window.getSize().y = " << window.getSize().y << endl; //
					cout << "rightplayer = " << rightPlayer.getShape().getGlobalBounds().left << endl;
				}
			}
		}

		ball1.ballMoving(ball1, window);
		ball1.Collision(ball1, leftPlayer, rightPlayer);

		window.clear();
		window.draw(leftPlayer.getShape());
		window.draw(rightPlayer.getShape());
		window.draw(ball1.getShape());
		window.display();
	}	
}
