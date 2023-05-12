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

	/*std::cout << "ball position.x - " << getBallPositionX() << std::endl;
	std::cout << "ball position.y - " << getBallPositionY() << std::endl;*/
}

void Ball::CheckPaddleCollision(Ball const& ball, LeftPlayer const& leftplayer, RightPlayer const& rightplayer)
{
	// допилить функцию
	// указать границы игрока 

	// Left player right collision

	/*bool checkCollision(const Rectangle & rect1, const Rectangle & rect2) 
	{
		bool xOverlap = (rect1.x + rect1.width >= rect2.x) && (rect2.x + rect2.width >= rect1.x);

		bool yOverlap = (rect1.y + rect1.height >= rect2.y) && (rect2.y + rect2.height >= rect1.y);

		return xOverlap && yOverlap;
	}*/
	
	bool xOverlap = (leftplayer.m_Shape.getGlobalBounds().left + leftplayer.m_Shape.getGlobalBounds().width 
		
		>= ball.m_ballShape.getGlobalBounds().left) && 
			
		(ball.m_ballShape.getGlobalBounds().left + ball.m_ballShape.getGlobalBounds().width 
		
			>= leftplayer.m_Shape.getGlobalBounds().left);


	bool yOverlap = (leftplayer.m_Shape.getGlobalBounds().top + leftplayer.m_Shape.getGlobalBounds().height

		>= ball.m_ballShape.getGlobalBounds().top) && 
		
		(ball.m_ballShape.getGlobalBounds().top + ball.m_ballShape.getGlobalBounds().height
			
			>= leftplayer.m_Shape.getGlobalBounds().top);

		
	

	if (/*leftplayer.m_Shape.getGlobalBounds().left + leftplayer.m_Shape.getGlobalBounds().width > ball.m_ballShape.getGlobalBounds().left*/
		xOverlap && yOverlap)
	
	{
		m_xVelocity *= -1;

		std::cout << "Leftplayer top = " << leftplayer.m_Shape.getGlobalBounds().top << std::endl;

		std::cout << "Leftplayer height = " << leftplayer.m_Shape.getGlobalBounds().height << std::endl;

		std::cout << "leftplayer top-height = " << leftplayer.m_Shape.getGlobalBounds().top + leftplayer.m_Shape.getGlobalBounds().height << std::endl;
	
		std::cout << "Leftplayer left = " << leftplayer.m_Shape.getGlobalBounds().left << std::endl;

		std::cout << "ball.left = " << ball.m_ballShape.getGlobalBounds().left << std::endl << std::endl;
	
	}

	// Left player down collision

	/*if (leftplayer.m_Shape.getGlobalBounds().top + leftplayer.m_Shape.getGlobalBounds().height
		<= ball.m_ballShape.getGlobalBounds().top + ball.m_ballShape.getGlobalBounds().height)
	{
		m_yVelocity *= -1;
	}*/
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
