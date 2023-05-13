#include <iostream>
#include <SFML/Graphics.hpp>
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

void Ball::ballPosition(LeftPlayer const& leftplayer)
{
	m_position.x += m_xVelocity;
	m_position.y += m_yVelocity;

	if ((m_position.x + 32) > 1000 || (m_position.x) < 0)
	{
		m_xVelocity *= -1;
	}

	if ((m_position.y) > 570 || (m_position.y) < 0)
	{
		m_yVelocity *= -1;
	}

	float dx1 = rand() % 10;
	float dy1 = rand() % 10;

	m_position.x;

	m_ballShape.setPosition(m_position);

}

// Checking collisions

void Ball::CheckPaddleCollision(Ball const& ball, LeftPlayer const& leftplayer, RightPlayer const& rightplayer)
{
	// допилить функцию

	/*bool checkCollision(const Rectangle & rect1, const Rectangle & rect2) 
	{
		bool xOverlapLeft = (rect1.x + rect1.width >= rect2.x) && (rect2.x + rect2.width >= rect1.x);

		bool yOverlapLeft = (rect1.y + rect1.height >= rect2.y) && (rect2.y + rect2.height >= rect1.y);

		return xOverlapLeft && yOverlapLeft;
	}*/
	
	// Left collision X

	bool xOverlapLeft = (leftplayer.m_Shape.getGlobalBounds().left + leftplayer.m_Shape.getGlobalBounds().width

		>= ball.m_ballShape.getGlobalBounds().left) &&

		(ball.m_ballShape.getGlobalBounds().left + ball.m_ballShape.getGlobalBounds().width >= leftplayer.m_Shape.getGlobalBounds().left);

	// Left collision Y

	bool yOverlapLeft = (leftplayer.m_Shape.getGlobalBounds().top + leftplayer.m_Shape.getGlobalBounds().height

		>= ball.m_ballShape.getGlobalBounds().top) &&

		(ball.m_ballShape.getGlobalBounds().top + ball.m_ballShape.getGlobalBounds().height >= leftplayer.m_Shape.getGlobalBounds().top);

		
	if (xOverlapLeft && yOverlapLeft)
	{
		m_xVelocity *= -1;


		std::cout << "Lefttplayer top = " << leftplayer.m_Shape.getGlobalBounds().top << std::endl;

		std::cout << "Rightplayer top = " << rightplayer.m_Shape.getGlobalBounds().top << std::endl;

		std::cout << "Rightplayer height = " << rightplayer.m_Shape.getGlobalBounds().height << std::endl;

		//std::cout << "Rightplayer top + height = " << rightplayer.m_Shape.getGlobalBounds().top + rightplayer.m_Shape.getGlobalBounds().height << std::endl;

		std::cout << "Rightplayer left = " << rightplayer.m_Shape.getGlobalBounds().left << std::endl;

		std::cout << "Rightplayer left position (X) = " << rightplayer.m_rightPosition.x << std::endl;

		std::cout << "Rightplayer left + width = " << rightplayer.m_Shape.getGlobalBounds().left
			+ rightplayer.m_Shape.getGlobalBounds().width << std::endl;

		std::cout << "Rightplayer top + wigth = " << rightplayer.m_Shape.getGlobalBounds().top +
			rightplayer.m_Shape.getGlobalBounds().width << std::endl << std::endl;

		//std::cout << "Rightplayer contains = " << rightplayer.m_Shape.getGlobalBounds() << std::endl;
	}


	// right collision 

	bool rightCollisionX = (ball.m_ballShape.getGlobalBounds().left + ball.m_ballShape.getGlobalBounds().width

		>= rightplayer.m_Shape.getGlobalBounds().left);


	bool rightCollisionY = (rightplayer.m_Shape.getGlobalBounds().top + rightplayer.m_Shape.getGlobalBounds().height

		>= ball.m_ballShape.getGlobalBounds().top) &&

		(ball.m_ballShape.getGlobalBounds().top + ball.m_ballShape.getGlobalBounds().height >= rightplayer.m_Shape.getGlobalBounds().top);


	if (rightCollisionX && rightCollisionY)
	{
		std::cout << "Right collision is works\n\n";

		m_xVelocity *= -1;
	}
}

void Ball::printBallLeft(Ball const& ball)
{
	std::cout << "\nBall.left (X) = " << ball.m_ballShape.getGlobalBounds().left << std::endl;
	std::cout << "Ball.top (Y) = " << ball.m_ballShape.getGlobalBounds().top << std::endl;
	std::cout << "Ball position X = " << ball.m_position.x << std::endl;
	std::cout << "Ball position Y = " << ball.m_position.y << std::endl;

	std::cout << "Ball.width = " << ball.m_ballShape.getGlobalBounds().width << std::endl << std::endl;
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
