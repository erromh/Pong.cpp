#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include <vector>
#include "App.h"
#include "Players.h"
#include "GameMenu.h"

// Look at sfml book and try to rewrite ball trajectory 

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(1500, 800), "App", Style::Default);
App pvpGame; 
App game;

void App::show_menu(RenderWindow& window)
{
	int menuHeight = window.getSize().x;
	int menuWidth =  window.getSize().y;

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
	//window.setFramerateLimit(60);
	srand(time(NULL));
	
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

	float rightPlayerPosX = (window.getSize().x - playerZize.x);
	float rightPlayerPosY = ((window.getSize().y / 2.0) - (playerZize.y / 2));

	Vector2f rightPosition(rightPlayerPosX, rightPlayerPosY);
	Players rightPlayer(playerZize, rightPosition, playersColor);

	rightPlayer.setVelocity(Velocity);


	/* Ball */
	
	// Color ball
	Color colorBall(255, 0, 0);

	// Object of ball class

	// Position determination
	float ballPosX = (window.getSize().x / 2.0);
	float ballPosY = (window.getSize().y / 2.0);

	Ball ball1(colorBall);
	
	// Set posotion
	ball1.setBallPositionX(ballPosX);
	ball1.setBallPositionY(ballPosY);

	// Determination of coordinates
	float ballCoordinate = 10;

	// Set the coordinates
	ball1.setX(ballCoordinate);
	ball1.setY(ballCoordinate);

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

				if (Keyboard::isKeyPressed(Keyboard::G))
				{
					cout << "Ball width = " << ball1.getShape().getGlobalBounds().width << endl;
				}
			}
		}



		ball1.ballMoving(ball1);
		ball1.Collision(ball1, leftPlayer, rightPlayer, window);
		ball1.counter(ball1, window);

		Image icon;
		icon.loadFromFile("D:/c++++/SFML_Project/appicon.png");
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

		Color windowColor(0, 0, 205);
		window.clear(windowColor);

		// Players display
		window.draw(leftPlayer.getShape());
		window.draw(rightPlayer.getShape());
		
		// Ball display
		window.draw(ball1.getShape());

		window.display();
		sleep(milliseconds(int(1000/120)));
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
	
	int exitDecision = -1;

	Text *toBeContinued = new Text[3];

	toBeContinued[0].setFont(endGameFont);
	toBeContinued[0].setString("Play again");
	toBeContinued[0].setCharacterSize(CharacterSize);
	toBeContinued[0].setPosition(50, 100);

	toBeContinued[1].setFont(endGameFont);
	toBeContinued[1].setString("Go to menu");
	toBeContinued[1].setCharacterSize(CharacterSize);
	toBeContinued[1].setPosition(50, 200);

	toBeContinued[2].setFont(endGameFont);
	toBeContinued[2].setString("Exit");
	toBeContinued[2].setCharacterSize(CharacterSize);
	toBeContinued[2].setPosition(50, 300);

	// This window appears when the game ends.

	while (endGameWindow.isOpen())
	{
		Event endEvent;

		while (endGameWindow.pollEvent(endEvent))
		{
			if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (exitDecision < 3)
				{
					toBeContinued[exitDecision].setFillColor(Color::White);

					exitDecision++;

					if (exitDecision == 3)
					{
						exitDecision = 0;
					}

					toBeContinued[exitDecision].setFillColor(Color::Yellow);
				}
				cout << "Right keyboard pressed\n";
			}

			if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (exitDecision >= 0)
				{
					toBeContinued[exitDecision].setFillColor(Color::White);

					exitDecision--;

					if (exitDecision == -1)
					{
						exitDecision = 2;
					}

					toBeContinued[exitDecision].setFillColor(Color::Yellow);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::C))
			{
				cout << "exitDecision = " << exitDecision << endl;
			}

			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				if (exitDecision == 0)
				{
					endGameWindow.close();
					pvpGame.pvp_game(window);
				}

				if (exitDecision == 1)
				{
					endGameWindow.close();
					game.show_menu(window);
				}

				if (exitDecision == 2)
				{
					endGameWindow.close();
					window.close();
				}
			}
		}

		endGameWindow.clear();
		for (int i = 0; i < 3; i++)
		{ endGameWindow.draw(toBeContinued[i]); }
		endGameWindow.display();
	}

	delete[]toBeContinued;

	cout << "end game\n";
}