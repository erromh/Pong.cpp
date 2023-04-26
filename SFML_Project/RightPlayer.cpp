#include <iostream>
#include <SFML/Graphics.hpp>
#include "RightPlayer.h"

RightPlayer::RightPlayer(Vector2f start_pos, Color p_color)
{
	m_rightPosition.x = start_pos.x;
	m_rightPosition.y = start_pos.y;
	m_Color = p_color;

	m_Shape.setFillColor(m_Color);
	m_Shape.setSize(Vector2f(50, 150));
	m_Shape.setPosition(m_rightPosition);
}

void RightPlayer::moveDown()
{
	m_rightPosition.y += yRightVelocity;

	if (m_rightPosition.y >= (450 + yRightVelocity))
	{
		m_Shape.setPosition(m_rightPosition);
		moveUp();
	}
	m_Shape.setPosition(m_rightPosition);

	std::cout << "RIGHT Y moveDown() = " << m_rightPosition.y << std::endl;

}

void RightPlayer::moveUp()
{
	m_rightPosition.y -= yRightVelocity;

	if (m_rightPosition.y <= -yRightVelocity)
	{
		m_Shape.setPosition(m_rightPosition);
		moveDown();
	}
	m_Shape.setPosition(m_rightPosition);

	std::cout << "RIGHT Y moveUp() = " << m_rightPosition.y << std::endl;

}

RectangleShape RightPlayer::getShape()
{
	return m_Shape;
}