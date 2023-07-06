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
App pvpGame; 
App game;

void App::show_menu(RenderWindow& window)
{
	// Object 
	

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

					if (choise == 2)
					{
						std::cout << "About game\n";
					}

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
	game.show_menu(window);
}

void App::endGame()
{
	RenderWindow endGameWindow(VideoMode(600, 400), "", Style::Default);
	
	Font endGameFont;
	endGameFont.loadFromFile("D:/c++++/SFML_Project/MilkyMania.ttf");
	int CharacterSize = 40;
	int exitDecision = 0;

	Text toBeContinued[2];

	toBeContinued[0].setFont(endGameFont);
	toBeContinued[0].setString("Play again ?");
	toBeContinued[0].setCharacterSize(CharacterSize);
	toBeContinued[0].setPosition(50, 200);

	toBeContinued[1].setFont(endGameFont);
	toBeContinued[1].setString("Go to menu");
	toBeContinued[1].setCharacterSize(CharacterSize);
	toBeContinued[1].setPosition(300, 200);

	while (endGameWindow.isOpen())
	{
		Event endEvent;

		while (endGameWindow.pollEvent(endEvent))
		{
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				exitDecision++;

				if (exitDecision > 1)
				{
					exitDecision = 0;
				}

				cout << "Right keyboard pressed\n";
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				exitDecision--;

				if (exitDecision < 0)
				{
					exitDecision = 1;
				}

				cout << "Left keyboard pressed\n";
			}

			if (exitDecision == 0)
			{
				toBeContinued[0].setFillColor(Color::Yellow);
				toBeContinued[1].setFillColor(Color::White);
			}

			if (exitDecision == 1)
			{
				toBeContinued[0].setFillColor(Color::White);
				toBeContinued[1].setFillColor(Color::Yellow);
			}

			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				if (exitDecision == 0)
				{
					pvpGame.pvp_game(window);
					endGameWindow.close();
				}

				if (exitDecision == 1)
				{
					game.show_menu(window);
					endGameWindow.close();
				}
			}
		}


		endGameWindow.clear();
		for (int i = 0; i < 2; i++)
		{ endGameWindow.draw(toBeContinued[i]); }
		endGameWindow.display();
	}

	cout << "end game\n";
}