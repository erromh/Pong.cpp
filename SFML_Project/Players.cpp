#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Players.h"
//#define DEBUG

using namespace std;

Players::Players(Vector2f const& size, Vector2f const& position, Color const& p_color)
{
	m_playersColor = p_color;
	m_Shape.setFillColor(m_playersColor);
	m_Shape.setSize(size);
	
	setPositionY(position.y);
	setPositionX(position.x);
	
	m_Shape.setPosition(getPositionX(), getPositionY());

#ifdef DEBUG
	cout << "start position y - " << m_Position.y << endl;
#endif
}

void Players::moveDown(RenderWindow const& window, Players const& players)
{
 	m_Position.y += yVelocity;
	
	m_Shape.setPosition(m_Position);
}

void Players::moveUp(RenderWindow const& window, Players const& players)
{
	m_Position.y -= yVelocity;

	m_Shape.setPosition(m_Position);
}

// set and get X position

float Players::getPositionX()
{
	return m_Position.x;
}

void Players::setPositionX(float x_Pos)
{
	m_Position.x = x_Pos;
}

// set and get Y position

float Players::getPositionY()
{
	return m_Position.y;
}

void Players::setPositionY(float y_Pos)
{
	m_Position.y = y_Pos;
}

// set and get size

RectangleShape Players::getShape()
{
	return m_Shape;
}

// get and set velocity

float Players::getVelocity()
{
	return yVelocity;
}

void Players::setVelocity(float velocity)
{
	yVelocity = velocity;
}

