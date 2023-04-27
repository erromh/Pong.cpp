#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

class LeftPlayer : public Player
{

private:

	Vector2f m_Leftposition;
	RectangleShape m_Shape;
	Color m_Color;

	bool m_moveDown = false;
	bool m_moveUp = false;

	float yLeftVelocity = 20;

public:
	void moveDown();
	void moveUp();
	RectangleShape getShape();

	float getPositionX();
	void setPositionX(float xPos);

	float getPositionY();
	void setPositionY(float yPos);

	LeftPlayer(Color p_color);

};



