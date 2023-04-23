#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"

LeftPlayer::LeftPlayer(Vector2f start_pos, Color p_color)
{
	m_Leftposition.x = start_pos.x;
	m_Leftposition.y = start_pos.y;
	m_Color = p_color;

	m_Shape.setFillColor(m_Color);
	m_Shape.setSize(Vector2f(50, 150));
	m_Shape.setPosition(m_Leftposition);
}

void LeftPlayer::moveDown()
{
	m_Leftposition.y += yVelocity;
	m_Shape.setPosition(m_Leftposition);
}

void LeftPlayer::moveUp()
{
	m_Leftposition.y -= yVelocity;
	m_Shape.setPosition(m_Leftposition);
}

RectangleShape LeftPlayer::getShape()
{
	return m_Shape;
}

