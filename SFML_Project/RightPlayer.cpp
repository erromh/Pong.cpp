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
	m_rightPosition.y += yVelocity;
	m_Shape.setPosition(m_rightPosition);
}

void RightPlayer::moveUp()
{
	m_rightPosition.y -= yVelocity;
	m_Shape.setPosition(m_rightPosition);
}

RectangleShape RightPlayer::getShape()
{
	return m_Shape;
}