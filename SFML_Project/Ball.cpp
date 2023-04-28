#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "LeftPlayer.h"

Ball::Ball(Vector2f start_position, Vector2f velocity, Color ballColor)
{
	setBallPositionX(start_position.x);
	setBallPositionY(start_position.y);

	setBallVelocityX(velocity.x);
	setBallVelocityY(velocity.y);

	m_CircleShape.setFillColor(ballColor);
	m_CircleShape.setRadius(16);

	m_CircleShape.setPosition(getBallPositionX(), getBallPositionY());
}

void Ball::ballPosition()
{
	m_position.x += m_xVelocity;
	m_position.y += m_yVelocity;

	m_CircleShape.setPosition(m_position);

	if (m_position.x == 0 || m_position.x >= 970 || m_position.x < 0)
	{
		m_xVelocity *= -1;
	}

	if (m_position.y >= 570.0 || m_position.y < 0)
	{
		m_yVelocity *= -1;
	}

	std::cout << "Ball X = " << m_position.x << std::endl;
	std::cout << "Ball Y = " << m_position.y << std::endl;

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

void Ball::setBallVelocityY(float yVelocity)
{
	m_yVelocity = yVelocity;
}

CircleShape Ball::getShape()
{
	return m_CircleShape;
}
