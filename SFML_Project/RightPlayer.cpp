#include <iostream>
#include <SFML/Graphics.hpp>
#include "RightPlayer.h"

RightPlayer::RightPlayer(Vector2f const& size,Vector2f const& start_pos, Color const& p_color)
{
	m_Color = p_color;
	m_Shape.setFillColor(m_Color);
	m_Shape.setSize(size);

	setPositionX(start_pos.x);
	setPositionY(start_pos.y);

	m_Shape.setPosition(getPositionX(), getPositionY());
}

void RightPlayer::moveDown(RenderWindow const& window)
{
	m_rightPosition.y += yRightVelocity;

	if (m_rightPosition.y >= (450 + yRightVelocity))
	{
		m_Shape.setPosition(m_rightPosition);
		/*moveUp();*/
	}
	m_Shape.setPosition(m_rightPosition);
}

void RightPlayer::moveUp(RenderWindow const& window)
{
	m_rightPosition.y -= yRightVelocity;

	if (m_rightPosition.y <= -yRightVelocity)
	{
		m_Shape.setPosition(m_rightPosition);
		//moveDown();
	}
	m_Shape.setPosition(m_rightPosition);
}

float RightPlayer::getPositionX()
{
	return m_rightPosition.x;
}

void RightPlayer::setPositionX(float x_PosRight)
{
	m_rightPosition.x = x_PosRight;
}

float RightPlayer::getPositionY()
{
	return m_rightPosition.y;
}

void RightPlayer::setPositionY(float y_PosRight)
{
	m_rightPosition.y = y_PosRight;
}

RectangleShape RightPlayer::getShape()
{
	return m_Shape;
}