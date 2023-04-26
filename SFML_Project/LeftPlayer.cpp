#include <iostream>
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
#define DEBUG

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

// Разобраться с этой фуекцией

void LeftPlayer::update(Time dt)
{
	if (m_moveUp)
	{
		m_Leftposition.y -= yLeftVelocity * dt.asSeconds();

		cout << "dt.asSeconds() = " << dt.asSeconds() << endl;
	}

	if (m_moveDown)
	{
		m_Leftposition.y += yLeftVelocity * dt.asSeconds();
	}

	m_Shape.setPosition(m_Leftposition);

	cout << "Y = " << m_Leftposition.y << endl << endl;
}

RectangleShape LeftPlayer::getShape()
{
	return m_Shape;
}

