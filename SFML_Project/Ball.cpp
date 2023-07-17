#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <memory>
#include <ctime>
#include "Ball.h"
#include "Players.h"
#include "App.h"

Ball::Ball(Color ballColor)
{
	m_ballShape.setRadius(16.0);

	m_ballShape.setFillColor(ballColor);

	m_ballShape.setPosition(getBallPositionX(), getBallPositionY());
}

Ball::~Ball()
{
	std::cout << "destructor called\n";
}

void Ball::ballMoving(Ball const& ball)
{
	m_position.x += dx1;
	m_position.y += dy1;

	m_ballShape.setPosition(m_position);
}

void Ball::counter(Ball const& ball, RenderWindow const& window)
{
	// X
	if ((m_position.x + m_ballShape.getRadius()) > window.getSize().x)
	{
		countLeft++;
	}

	if ((m_position.x - m_ballShape.getRadius() < 0))
	{

	}

	// Y
	if ((m_position.y + m_ballShape.getRadius()) >= window.getSize().y || (m_position.y - m_ballShape.getRadius() <= 0))
	{

	}

	
	Font countFont;
	countFont.loadFromFile("D:/c++++/SFML_Project/MilkyMania.ttf");
	count.setFont(countFont);
	count.setCharacterSize(40);
	count.setPosition(200, 200);

	char cLeft = static_cast<char>(countLeft);
	char cRight = static_cast<char>(countRight);
	
	count.setString(cLeft);	
}

void Ball::Collision(Ball const& ball, Players const& leftPlayer, Players const& rightplayer, RenderWindow const& window)
{
	// Ñollision with LEFT player

	if (leftPlayer.m_Shape.getGlobalBounds().intersects(ball.m_ballShape.getGlobalBounds()))
	{
		dx1 = -dx1;
		std::cout << "Left collosion\n";
	}

	// Collision with right player

	if (rightplayer.m_Shape.getGlobalBounds().intersects(ball.m_ballShape.getGlobalBounds()))
	{
		dx1 = -dx1;
		std::cout << "Right collision getGlobalBounds()\n";
	}

	// X board collison

	App app;

	if ((m_position.x + m_ballShape.getRadius()) > window.getSize().x || (m_position.x - m_ballShape.getRadius() < 0))
	{
		dx1 = -dx1;
		app.endGame();
	}

	// Y board collision

	if ((m_position.y + m_ballShape.getRadius()) >= window.getSize().y || (m_position.y - m_ballShape.getRadius() <= 0))
	{
		dy1 = -dy1;
	}

}

// Get text counter

Text Ball::getCounter()
{
	return count;
}

// Get and set ball's X position 

float Ball::getBallPositionX()
{
	return m_position.x;
}

void Ball::setBallPositionX(float const& ball_x)
{
	m_position.x = ball_x;
}

// Get and set ball's Y position 

float Ball::getBallPositionY()
{
	return m_position.y;
}

void Ball::setBallPositionY(float const& ball_y)
{
	m_position.y = ball_y;
}

// Get and set direction vector coordinate

// X coordinate
float Ball::getX()
{
	return dx1;
}

void Ball::setX(const float& x)
{
	dx1 = x;
}

// Y coordinate

float Ball::getY()
{
	return dy1;
}

void Ball::setY(const float& y)
{
	dy1 = y;
}

// Return the shape of ball

CircleShape Ball::getShape()
{
	return m_ballShape;
}
