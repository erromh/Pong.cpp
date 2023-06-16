#include <iostream>
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
//#define DEBUG

using namespace std;

LeftPlayer::LeftPlayer(Vector2f const& size, Vector2f const& position, Color const& p_color)
{
	m_ColorLeft = p_color;
	m_ShapeLeft.setFillColor(m_ColorLeft);
	m_ShapeLeft.setSize(size);
	
	setPositionY(position.y);
	setPositionX(position.x);
	
	m_ShapeLeft.setPosition(getPositionX(), getPositionY());

#ifdef DEBUG
	cout << "start position y - " << m_Leftposition.y << endl;
#endif 

}

void LeftPlayer::moveDownLeft(RenderWindow const& window, LeftPlayer const& leftplayer)
{
	m_Leftposition.y += yLeftVelocity;

	if ((leftplayer.m_Leftposition.y + leftplayer.m_ShapeLeft.getGlobalBounds().height) >= window.getSize().y)
	{
		std::cout << "LEFT COLLISION WORKS\n";
		yLeftVelocity = 0;
	}
	m_ShapeLeft.setPosition(m_Leftposition);


#ifdef DEBUG
	cout << "left Y moveDown() = " << m_Leftposition.y << endl;
#endif 
}

void LeftPlayer::moveUpLeft(RenderWindow const& window, LeftPlayer const& leftplayer)
{
	m_Leftposition.y -= yLeftVelocity;
	
	if (m_Leftposition.y <= -yLeftVelocity)
	{
		m_ShapeLeft.setPosition(m_Leftposition);
		//moveDown();
	}
	m_ShapeLeft.setPosition(m_Leftposition);

#ifdef DEBUG
	cout << "left Y moveUp() = " << m_Leftposition.y << endl;
#endif // DEBUG

}

// set and get X position

float LeftPlayer::getPositionX()
{
	return m_Leftposition.x;
}

void LeftPlayer::setPositionX(float x_Pos)
{
	m_Leftposition.x = x_Pos;
}

// set and get Y position

float LeftPlayer::getPositionY()
{
	return m_Leftposition.y;
}

void LeftPlayer::setPositionY(float y_Pos)
{
	m_Leftposition.y = y_Pos;
	cout << "setPosition y = " << m_Leftposition.y << endl;
}

// set and get size

RectangleShape LeftPlayer::getShapeLeft()
{
	return m_ShapeLeft;
}

