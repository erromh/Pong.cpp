#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Ball.h"
#include "LeftPlayer.h"
#include "RightPlayer.h"

Ball::Ball(Vector2f start_position, Vector2f velocity, Color ballColor)
{
	setBallPositionX(start_position.x);
	setBallPositionY(start_position.y);

	m_ballShape.setSize(Vector2f(32, 32));

	setBallVelocityX(velocity.x);
	setBallVelocityY(velocity.y);

	m_ballShape.setFillColor(ballColor);

	m_ballShape.setPosition(getBallPositionX(), getBallPositionY());
}

Ball::~Ball()
{
	std::cout << "destructor called\n";
}

void Ball::ballMoving(LeftPlayer const& leftplayer)
{
	m_position.x += m_xVelocity;

	m_position.y += m_yVelocity;

	if ((m_position.x + 32) > 1000 || (m_position.x) < 0)
	{
		m_xVelocity *= -1;
		gameOver();
	}

	if ((m_position.y) > 570 || (m_position.y) < 0)
	{
		m_yVelocity *= -1;
//		gameOver();
	}
	
	m_ballShape.setPosition(m_position);
}

// Checking collisions

void Ball::Collision(Ball const& ball, LeftPlayer const& leftplayer, RightPlayer const& rightplayer)
{
	// Left player collision


	//if (rect1.getGlobalBounds().intersects(rect2.getGlobalBounds()))
	//{
	//	if (rect1.getPosition().y + rect1.getSize().y <= rect2.getPosition().y)
	//	{
	//		// ¬ерхн€€ сторона rect1 столкнулась с нижней стороной rect2
	//	}
	//}

	/*if (ball.m_ballShape.getGlobalBounds().intersects(leftplayer.m_Shape.getGlobalBounds()))
	{
		if (ball.m_ballShape.getPosition().y + ball.m_ballShape.getSize().y <= (leftplayer.m_Shape.getPosition().y))
		{
			m_xVelocity *= -1;
		}
	}*/
	
	bool leftCollisionX = (leftplayer.m_Shape.getGlobalBounds().left + leftplayer.m_Shape.getGlobalBounds().width

		>= ball.m_ballShape.getGlobalBounds().left) &&

		(ball.m_ballShape.getGlobalBounds().left + ball.m_ballShape.getGlobalBounds().width >= leftplayer.m_Shape.getGlobalBounds().left);


	bool leftCollisionY = (leftplayer.m_Shape.getGlobalBounds().top + leftplayer.m_Shape.getGlobalBounds().height

		>= ball.m_ballShape.getGlobalBounds().top) &&
		
		(ball.m_ballShape.getGlobalBounds().top + ball.m_ballShape.getGlobalBounds().height >= leftplayer.m_Shape.getGlobalBounds().top);


	if (leftCollisionX && leftCollisionY)
	{
		m_yVelocity *= -1;
		std::cout << "Top collision works\n";
	}

	if (leftplayer.m_Shape.getGlobalBounds().intersects(ball.m_ballShape.getGlobalBounds()))
	{
		m_xVelocity *= -1;
		std::cout << "Left collosion\n";
	}

	



	// Right collision

	bool rightCollisionX = (ball.m_ballShape.getGlobalBounds().left + ball.m_ballShape.getGlobalBounds().width

		>= rightplayer.m_Shape.getGlobalBounds().left);

	bool rightCollisionY = (rightplayer.m_Shape.getGlobalBounds().top + rightplayer.m_Shape.getGlobalBounds().height

		>= ball.m_ballShape.getGlobalBounds().top) &&

		(ball.m_ballShape.getGlobalBounds().top + ball.m_ballShape.getGlobalBounds().height >= rightplayer.m_Shape.getGlobalBounds().top);

	   
	if (rightCollisionX && rightCollisionY)
	{
		m_xVelocity *= -1;
		std::cout << "Top and bottom right collision\n";
	}


	if (rightplayer.m_Shape.getGlobalBounds().intersects(ball.m_ballShape.getGlobalBounds()))
	{
		m_yVelocity *= -1;
		std::cout << "Right collision \n";
	}
}


void Ball::gameOver()
{
	// 1) Stop tha ball
	// 2) Display an insciption that the game is over
	// 3) Indicate who won
	// 4) Restart the game (button maybe. think about it !!!)


	/*setBallVelocityX(0);*/
	//setBallVelocityY(0);

	/*setBallPositionX(100);
	setBallPositionY(160);*/

	RectangleShape gameOverRect;

	gameOverRect.setSize(Vector2f(500, 100));
	gameOverRect.setFillColor(Color::Green);


	std::cout << "Game over\n";
}

void Ball::printBallLeft(Ball const& ball, LeftPlayer const& leftplayer)
{
	std::cout << "\nBall.left (X) = " << ball.m_ballShape.getGlobalBounds().left << std::endl;
	std::cout << "Ball.top (Y) = " << ball.m_ballShape.getGlobalBounds().top << std::endl;
	std::cout << "Ball position X = " << ball.m_position.x << std::endl;
	std::cout << "Ball position Y = " << ball.m_position.y << std::endl;
	std::cout << "Ball.width = " << ball.m_ballShape.getGlobalBounds().width << std::endl;
	std::cout << "Ball.Left + width = " << ball.m_ballShape.getGlobalBounds().left + 
		ball.m_ballShape.getGlobalBounds().width << std::endl;
	std::cout << "LeftPlayer.left = " << leftplayer.m_Shape.getGlobalBounds().left << std::endl;
}

// Get and set ball's X position 

float Ball::getBallPositionX()
{
	return m_position.x;
}

void Ball::setBallPositionX(float ball_x)
{
	m_position.x = ball_x;
}

// Get and set ball's Y position 

float Ball::getBallPositionY()
{
	return m_position.y;
}

void Ball::setBallPositionY(float ball_y)
{
	m_position.y = ball_y;
}

// Get and set ball's X velocity

float Ball::getBallVelocityX()
{
	return m_xVelocity;
}

void Ball::setBallVelocityX(float xVelocity)
{
	m_xVelocity = xVelocity;
}

// Get and set ball's Y velocity

float Ball::getBallVelocityY()
{
	return m_yVelocity;
}

void Ball::setBallVelocityY(float yVelocity)
{
	m_yVelocity = yVelocity;
}

// Return the shape of ball

RectangleShape Ball::getShape()
{
	return m_ballShape;
}
