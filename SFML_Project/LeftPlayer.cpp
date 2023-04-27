#include <iostream>
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
//#define DEBUG

using namespace std;

LeftPlayer::LeftPlayer(Color p_color)
{
	
	m_Color = p_color;

	m_Shape.setFillColor(m_Color);
	m_Shape.setSize(Vector2f(50, 150));
//	m_Shape.setPosition(m_Leftposition);
	cout << "start position y - " << m_Leftposition.y << endl;
}

// переделать функции под сеттеры и геттеры 

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

void LeftPlayer::setPositionX(float xPos)
{
	m_Leftposition.x = xPos;
}

float LeftPlayer::getPositionY()
{
	return m_Leftposition.y;
}

void LeftPlayer::setPositionY(float yPos)
{
	m_Leftposition.y = yPos;
}

RectangleShape LeftPlayer::getShape()
{
	return m_Shape;
}

