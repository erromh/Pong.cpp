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

	float rightPlayerPosX = static_cast<float>(window.getSize().x - rightSize.x);
	float rightPlayerPosY = static_cast<float>((window.getSize().y / 2.0) - (rightSize.y / 2));

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

	// Background
	Color menu_background_color(0, 255, 127);
	Vector2f menu_background_size(window.getSize().x, window.getSize().y);
	Vector2f menu_position(0, 0);
	GameMenu menu_background(window, menu_background_size, menu_background_color, menu_position);

	// Menu items

	Color menu_item1_color(255, 192, 203);
	Vector2f menu_item1_size(400, 90);
	Vector2f menu_item1_pos((window.getSize().x / 2) - (menu_item1_size.x / 2), ((window.getSize().y / 2) - (menu_item1_size.y / 2)));
	GameMenu menu_item1(menu_item1_size, menu_item1_color, menu_item1_pos);

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
					rightPlayer.moveUp( rightPlayer);
					
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

		window.draw(menu_background.get_menu_shape());
		window.draw(menu_item1.get_menu_shape());


		window.display();
	}	
}