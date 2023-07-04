#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "App.h"
#include "Players.h"
#include "GameMenu.h"

using namespace sf;
using namespace std;


void App::show_menu(RenderWindow& window)
{
	App pvpGame;


	float menuHeight = window.getSize().x;
	float menuWidth = window.getSize().y;

	RenderWindow MENU(VideoMode(menuHeight, menuWidth), "Menu", Style::Default);
	GameMenu menu(MENU.getSize().x, MENU.getSize().y, MENU);

	while (MENU.isOpen())
	{
		Event menuEvent;

		while (MENU.pollEvent(menuEvent))
		{
			if (menuEvent.type == menuEvent.Closed())
			{
				MENU.close();
			}

			if (menuEvent.type == Event::KeyReleased)
			{
				if (menuEvent.key.code == Keyboard::Up)
				{
					menu.menuMoveUp();
					cout << "menu.menuPress() = " << menu.menuPress() << endl;
					break;
				}

				if (menuEvent.key.code == Keyboard::Down)
				{
					menu.menuMoveDown();
					cout << "menu.menuPress() = " << menu.menuPress() << endl;
					break;
				}

				if (menuEvent.key.code == Keyboard::Enter)
				{
					int choise = menu.menuPress();

					if (choise == 0)
					{
						pvpGame.pvp_game(window);
					}

				}
			}
		}

		MENU.clear();
		menu.showMenu(MENU);
		MENU.display();
	}
}

void App::pvp_game(RenderWindow& window) const
{
	srand(time(NULL));
	window.setFramerateLimit(60);

	/* Player on the left */
	
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


	/* Player on the right */

	Vector2f rightSize(25, 150);

	float rightPlayerPosX = (window.getSize().x - rightSize.x);
	float rightPlayerPosY = ((window.getSize().y / 2.0) - (rightSize.y / 2));

	Vector2f rightPosition(rightPlayerPosX, rightPlayerPosY);
	Players rightPlayer(rightSize, rightPosition, playersColor);

	rightPlayer.setVelocity(Velocity);


	/* Ball */

	Vector2f ballVelocity(8, 8);	
	Color colorBall(96, 18, 223);

	Ball ball1(ballVelocity, colorBall);

	float ballPosX = (window.getSize().x / 2.0);
	float ballPosY = (window.getSize().y / 2.0);

	ball1.setBallPositionX(ballPosX);
	ball1.setBallPositionX(ballPosY);

	/* Menu */ 

	


	// Game window

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
					leftPlayer.moveDown(leftPlayer);

					if (leftPlayer.m_Shape.getGlobalBounds().top + leftPlayer.m_Shape.getGlobalBounds().height > window.getSize().y)
					{
						leftPlayer.moveUp(leftPlayer);
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					leftPlayer.moveUp(leftPlayer);

					if (leftPlayer.m_Shape.getGlobalBounds().top < 0)
					{
						leftPlayer.moveDown(leftPlayer);
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					rightPlayer.moveUp(rightPlayer);

					if (rightPlayer.m_Shape.getGlobalBounds().top <= 0)
					{
						rightPlayer.moveDown(rightPlayer);
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::Down))
				{
					rightPlayer.moveDown(rightPlayer);

					if (rightPlayer.m_Shape.getGlobalBounds().top + rightPlayer.m_Shape.getGlobalBounds().height > window.getSize().y)
					{
						rightPlayer.moveUp(rightPlayer);
					}
				}
			}
		}

		ball1.ballMoving(ball1, window);
		ball1.Collision(ball1, leftPlayer, rightPlayer);

		window.clear();

		// Players display
		window.draw(leftPlayer.getShape());
		window.draw(rightPlayer.getShape());
		
		// Ball display
		window.draw(ball1.getShape());

		// Menu display


		window.display();
	}	
}