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

bool LeftPlayer::changeState(bool& checkCollision)
{
	if (checkCollision == false)
	{
		checkCollision = true;
	}

	if (checkCollision == true)
	{
		checkCollision = false;
	}

	return checkCollision;
}

void LeftPlayer::moveDownLeft(RenderWindow const& window, LeftPlayer const& leftplayer)
{
	m_Leftposition.y += yLeftVelocity;

	if ((leftplayer.m_Leftposition.y + leftplayer.m_ShapeLeft.getGlobalBounds().height) == window.getSize().y)
	{
		// you should make fucking collision with window
	}
	
	m_ShapeLeft.setPosition(m_Leftposition);
}

void LeftPlayer::moveUpLeft(RenderWindow const& window, LeftPlayer const& leftplayer)
{
	m_Leftposition.y -= yLeftVelocity;
	
	if ((leftplayer.m_Leftposition.y + leftplayer.m_ShapeLeft.getGlobalBounds().height) >= window.getSize().y)
	{
		changeState(stateDownLeft);
	}

	if (m_Leftposition.y <= -yLeftVelocity)
	{
		m_ShapeLeft.setPosition(m_Leftposition);
	}
	
	m_ShapeLeft.setPosition(m_Leftposition);
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
}

// set and get size

RectangleShape LeftPlayer::getShapeLeft()
{
	return m_ShapeLeft;
}

