#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include "App.h"
#include "Players.h"
#include "GameMenu.h"

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(1500, 800), "", Style::Default);

void App::show_menu(RenderWindow& window)
{
	// Object 
	App pvpGame;

	float menuHeight = window.getSize().x;
	float menuWidth = window.getSize().y;

	GameMenu menu(window.getSize().x, window.getSize().y, window);

	while (window.isOpen())
	{
		Event menuEvent;

		while (window.pollEvent(menuEvent))
		{

			if (menuEvent.type == Event::KeyReleased)
			{
				if (menuEvent.key.code == Keyboard::Up || menuEvent.key.code == Keyboard::W)
				{
					menu.menuMoveUp();
					cout << "menu.menuPress() = " << menu.menuPress() << endl;
					break;
				}

				if (menuEvent.key.code == Keyboard::Down || menuEvent.key.code == Keyboard::S)
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

					if (choise == 1)
					{
						pvpGame.online_game();
					}



					//////////////////////////////////////////////////
					if (choise == 2)
					{
						RenderWindow newWindow(VideoMode(500, 500), "", Style::Default);

						while (newWindow.isOpen())
						{
							Event jokeEvent;

							Texture text;
							text.loadFromFile("D:/c++++/SFML_Project/sovok.PNG");

							Sprite sss;
							sss.setTexture(text);

							while (newWindow.pollEvent(jokeEvent))
							{
								if (jokeEvent.key.code == Keyboard::Escape)
								{
									newWindow.close();
								}
							}

							newWindow.clear();
							newWindow.draw(sss);
							newWindow.display();
						}

						std::cout << "About game\n";
					}
					///////////////////////////////////////////////////////////////////////////


					if (choise == 3)
					{
						window.close();
					}

				}
			}
		}

		window.clear();
		menu.showMenuItems(window);
		menu.showHeader(window);
		window.display();
	}
}

void App::online_game()
{
	cout << "Online is work\n";
}

void App::pvp_game(RenderWindow& window) const
{
	srand(time(NULL));
	window.setFramerateLimit(60);
	/* Player on the left */
	
	// Players size
	Vector2f playerZize(25, 150);

	// Position y
	float PlayersPosY = ((window.getSize().y / 2.0) - (playerZize.y / 2));
	
	// Velocity
	float Velocity = 20;

	// Position setting
	Vector2f leftPosition(0, PlayersPosY);
	
	// Player color
	Color playersColor(240, 255, 240);

	// Create player
	Players leftPlayer(playerZize, leftPosition, playersColor);
	
	// Set velocity
	leftPlayer.setVelocity(Velocity);


	/* Player on the right */

	// 

	float rightPlayerPosX = (window.getSize().x - playerZize.x);
	float rightPlayerPosY = ((window.getSize().y / 2.0) - (playerZize.y / 2));

	Vector2f rightPosition(rightPlayerPosX, rightPlayerPosY);
	Players rightPlayer(playerZize, rightPosition, playersColor);

	rightPlayer.setVelocity(Velocity);


	/* Ball */

	// Velocity
	Vector2f ballVelocity(8, 8);	
	
	// Color ball
	Color colorBall(255, 0, 0);

	// Object of ball class
	Ball ball1(ballVelocity, colorBall);

	// Posotion
	float ballPosX = (window.getSize().x / 2.0);
	float ballPosY = (window.getSize().y / 2.0);

	ball1.setBallPositionX(ballPosX);
	ball1.setBallPositionX(ballPosY);


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

		Color windowColor(0, 0, 205);

		window.clear(windowColor);

		// Players display
		window.draw(leftPlayer.getShape());
		window.draw(rightPlayer.getShape());
		
		// Ball display
		window.draw(ball1.getShape());

		// Menu display
		window.display();
	}	
}

void App::startGame()
{
	App game;
	game.show_menu(window);
}

void App::endGame()
{
	cout << "end game\n";
}