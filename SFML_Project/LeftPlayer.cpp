#include <iostream>
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
//#define DEBUG

using namespace std;

LeftPlayer::LeftPlayer(Vector2f position, Color p_color)
{
	m_Color = p_color;
	m_Shape.setFillColor(m_Color);
	m_Shape.setSize(Vector2f(50, 150));
	
	setPositionY(position.y);

	setPositionX(position.x);
	
	m_Shape.setPosition(getPositionX(), getPositionY());

#ifdef DEBUG
	cout << "start position y - " << m_Leftposition.y << endl;
#endif 

}


void LeftPlayer::moveDown()
{
	m_Leftposition.y += yLeftVelocity;

	cout << "left Y moveDown() = " << m_Leftposition.y << endl;

	if (m_Leftposition.y >= (450 + yLeftVelocity))
	{
		m_Shape.setPosition(m_Leftposition);
		moveUp();
	}
	m_Shape.setPosition(m_Leftposition);

#ifdef DEBUG
	cout << "left Y moveDown() = " << m_Leftposition.y << endl;
#endif 

}

void LeftPlayer::moveUp()
{
	m_Leftposition.y -= yLeftVelocity;
	cout << "left Y moveUp() = " << m_Leftposition.y << endl;

	if (m_Leftposition.y <= -yLeftVelocity)
	{
		m_Shape.setPosition(m_Leftposition);
		moveDown();
	}
	m_Shape.setPosition(m_Leftposition);

#ifdef DEBUG
	cout << "left Y moveUp() = " << m_Leftposition.y << endl;
#endif // DEBUG

}

float LeftPlayer::getPositionX()
{
	return m_Leftposition.x;
}

void LeftPlayer::setPositionX(float x_Pos)
{
	m_Leftposition.x = x_Pos;
}

float LeftPlayer::getPositionY()
{
	return m_Leftposition.y;
}

void LeftPlayer::setPositionY(float y_Pos)
{
	m_Leftposition.y = y_Pos;
	cout << "setPosition y = " << m_Leftposition.y << endl;
}

RectangleShape LeftPlayer::getShape()
{
	return m_Shape;
}

