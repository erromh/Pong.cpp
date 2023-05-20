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
		//std::cout << "End game X\n";
	}

	if ((m_position.y) > 570 || (m_position.y) < 0)
	{
		m_yVelocity *= -1;
		//std::cout << "End game Y\n";
	}

	m_ballShape.setPosition(m_position);
}

// Checking collisions

void Ball::Collision(Ball const& ball, LeftPlayer const& leftplayer, RightPlayer const& rightplayer)
{

	// Left collision
	
	bool xOverlapLeft = (leftplayer.m_Shape.getGlobalBounds().left + leftplayer.m_Shape.getGlobalBounds().width

		>= ball.m_ballShape.getGlobalBounds().left) &&

		(ball.m_ballShape.getGlobalBounds().left + ball.m_ballShape.getGlobalBounds().width >= leftplayer.m_Shape.getGlobalBounds().left);



	bool yOverlapLeft = (leftplayer.m_Shape.getGlobalBounds().top + leftplayer.m_Shape.getGlobalBounds().height

		>= ball.m_ballShape.getGlobalBounds().top) &&
		
		(ball.m_ballShape.getGlobalBounds().top + ball.m_ballShape.getGlobalBounds().height >= leftplayer.m_Shape.getGlobalBounds().top);


	if (xOverlapLeft && yOverlapLeft)
	{
		m_yVelocity *= -1;
		std::cout << "Top collision works\n";
	}

	else
	{
		m_xVelocity *= 1;
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
		std::cout << "Right collision\n";
	}
}


void Ball::endGame()
{
	
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
