#include <iostream>
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"

using namespace std;

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
	m_Leftposition.y += yLeftVelocity;

	if (m_Leftposition.y == 0)
	{
		yLeftVelocity *= 0;
	}
	
	m_Shape.setPosition(m_Leftposition);

	cout << "left y = " << m_Leftposition.y << endl;
}

void LeftPlayer::moveUp()
{
	m_Leftposition.y -= yLeftVelocity;

	m_Shape.setPosition(m_Leftposition);

	cout << "left y = " << m_Leftposition.y << endl;
}

RectangleShape LeftPlayer::getShape()
{
	return m_Shape;
}

