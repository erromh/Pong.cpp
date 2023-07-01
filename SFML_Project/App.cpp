#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "App.h"
#include "Players.h"
#include "GameMenu.h"

using namespace sf;

void App::pvp_game(RenderWindow & window) const
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
	float Velocity = 20;

	// Position setting
	Vector2f leftPosition(0, PlayersPosY);
	
	// Player color
	Color playersColor(135, 206, 235);

	// Create player
	Players leftPlayer(leftSize, leftPosition, playersColor);
	
	// Set velocity
	leftPlayer.setVelocity(Velocity);


	// Player on the right

	Vector2f rightSize(25, 150);

	float rightPlayerPosX = static_cast<float>(window.getSize().x - rightSize.x);
	float rightPlayerPosY = static_cast<float>((window.getSize().y / 2.0) - (rightSize.y / 2));

	Vector2f rightPosition(rightPlayerPosX, rightPlayerPosY);
	Players rightPlayer(rightSize, rightPosition, playersColor);

	rightPlayer.setVelocity(Velocity);

	// Ball

	Vector2f ballVelocity(8, 8);	
	Color colorBall(96, 18, 223);

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

				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					leftPlayer.moveDown(window, leftPlayer);
					
					if (leftPlayer.m_Shape.getGlobalBounds().top + leftPlayer.m_Shape.getGlobalBounds().height > window.getSize().y)
					{
						leftPlayer.moveUp(window, leftPlayer);
					}
				}
				
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					leftPlayer.moveUp(window, leftPlayer);

					if (leftPlayer.m_Shape.getGlobalBounds().top < 0)
					{
						leftPlayer.moveDown(window, leftPlayer);
					} 
				}

				if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					rightPlayer.moveUp(window, rightPlayer);
					
					if (rightPlayer.m_Shape.getGlobalBounds().top <= 0)
					{
						rightPlayer.moveDown(window, rightPlayer);
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::Down))
				{
					rightPlayer.moveDown(window, rightPlayer);
					
					if (rightPlayer.m_Shape.getGlobalBounds().top + rightPlayer.m_Shape.getGlobalBounds().height > window.getSize().y)
					{
						rightPlayer.moveUp(window, rightPlayer);
					}
				}

				if (event.key.code == Keyboard::Q)
				{
					cout << "window.getSize().x = " << window.getSize().x << endl;  
					cout << "window.getSize().y = " << window.getSize().y << endl;
					cout << "rightplayer Y = " << rightPlayer.getPositionY() << endl;
					cout << "LeftPlayer Y = " << leftPlayer.getPositionY() << endl;
					cout << "rightplayer X = " << rightPlayer.getPositionX() << endl << endl;
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


void App::show_menu(RenderWindow& window)
{
	RectangleShape menu;
	menu.setFillColor(Color::Yellow);
	menu.setSize(Vector2f(300, 400));

	std::cout << "menu works\n";

	window.draw(menu);
}
