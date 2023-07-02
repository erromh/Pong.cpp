#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
using namespace sf;

class Players
{
	friend class Ball;
	friend class App;

private:

	Vector2f m_Position;
	RectangleShape m_Shape;
	Color m_playersColor;
	float yVelocity;

public:
	void moveDown(Players const& players);
	void moveUp(Players const& players);
	RectangleShape getShape();

	float getPositionX();
	void setPositionX(float x_Pos);

	float getPositionY();
	void setPositionY(float y_Pos);
	
	float getVelocity();
	void setVelocity(float velocityLeft);

	Players(Vector2f const& size, Vector2f const& position, Color const& p_color);

};



