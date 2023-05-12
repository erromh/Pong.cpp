#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

class LeftPlayer : public Player
{
	friend class Ball;
	friend class App;

private:

	Vector2f m_Leftposition;
	RectangleShape m_Shape;
	Color m_Color;
	float yLeftVelocity = 20;

public:
	void moveDown();
	void moveUp();
	RectangleShape getShape();

	float getPositionX();
	void setPositionX(float x_Pos);

	float getPositionY();
	void setPositionY(float y_Pos);
	
	LeftPlayer(Vector2f position, Color p_color);

};



