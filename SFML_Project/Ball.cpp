#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <memory>
#include "Ball.h"
#include "LeftPlayer.h"
#include "RightPlayer.h"

Ball::Ball(Vector2f velocity, Color ballColor)
{
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

void Ball::ballMoving(Ball const& ball, RenderWindow const & window)
{
	m_position.x += m_xVelocity;
	m_position.y += m_yVelocity;

	if ((m_position.x + ball.m_ballShape.getGlobalBounds().width) > window.getSize().x || (m_position.x) < 0)
	{
		m_xVelocity *= -1;
		//gameOver();
	}

	if ((m_position.y) > (window.getSize().y - ball.m_ballShape.getGlobalBounds().width) || (m_position.y) < 0)
	{
		m_yVelocity *= -1;
	}
	
	m_ballShape.setPosition(m_position);
}


// Checking collisions

void Ball::Collision(Ball const& ball, LeftPlayer const& leftplayer, RightPlayer const& rightplayer)
{
	// Ñollision with left player

	if (leftplayer.m_ShapeLeft.getGlobalBounds().intersects(ball.m_ballShape.getGlobalBounds()))
	{
		m_xVelocity *= -1;
		std::cout << "Left collosion\n";
	}

	// Collision with right player

	if (rightplayer.m_Shape.getGlobalBounds().intersects(ball.m_ballShape.getGlobalBounds()))
	{
		m_xVelocity *= -1;
		std::cout << "Right collision getGlobalBounds()\n";
	}
}

bool Ball::gameOver()
{
	/* 
	 1) Stop tha ball
	 2) Display an insciption that the game is over
	 3) Indicate who won
	 4) Restart the game (button maybe. think about it !!!)
	 */

	setBallVelocityX(0);
	setBallVelocityY(0);

	//void LeftPlayer::getPositionX()

	m_ballShape.setFillColor(Color::Transparent);

	std::cout << "Game over\n";

	return true;
}

void Ball::printBallLeft(Ball const& ball, LeftPlayer const& leftplayer)
{
	std::cout << "\nPlayer width = " << leftplayer.m_ShapeLeft.getGlobalBounds().width << std::endl;
	std::cout << "Ball.width = " << ball.m_ballShape.getGlobalBounds().width << std::endl;
	std::cout << "Ball.Left + width = " << ball.m_ballShape.getGlobalBounds().left + 
		ball.m_ballShape.getGlobalBounds().width << std::endl;
	std::cout << "LeftPlayer.left = " << leftplayer.m_ShapeLeft.getGlobalBounds().left << std::endl;
	std::cout << "Ball::getBallPositionX() = " << Ball::getBallPositionX() << std::endl;
	std::cout << "leftplayer top = " << leftplayer.m_ShapeLeft.getGlobalBounds().top << std::endl;
	std::cout << "Left Y = " << leftplayer.m_Leftposition.y << std::endl;
}

// Get and set ball's X position 

float Ball::getBallPositionX()
{
	return m_position.x;
}

void Ball::setBallPositionX(float const& ball_x)
{
	m_position.x = ball_x;
}

// Get and set ball's Y position 

float Ball::getBallPositionY()
{
	return m_position.y;
}

void Ball::setBallPositionY(float const& ball_y)
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
