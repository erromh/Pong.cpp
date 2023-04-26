#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"

Ball::Ball(Vector2f start_position, Color ballColor)
{
	m_position.x = start_position.x;
	m_position.y = start_position.y;

	m_CircleShape.setFillColor(ballColor);
	m_CircleShape.setRadius(16);
	m_CircleShape.setPosition(m_position);
}

void Ball::ballPosirion()
{
	m_position.x += m_xVelocity;
	m_position.y += m_yVelocity;

	m_CircleShape.setPosition(m_position);

	if (m_position.x == 0 || m_position.x >= 970)
	{
		m_xVelocity *= -1;
	}

	//Fix this peace of shit ff

	if (m_position.y >= 530.0 || m_position.y >= 42 || m_position.y < 0)
	{
		m_yVelocity *= -1;
	}

	std::cout << "Ball X = " << m_position.x << std::endl;
	std::cout << "Ball Y = " << m_position.y << std::endl;

}

CircleShape Ball::getShape()
{
	return m_CircleShape;
}
