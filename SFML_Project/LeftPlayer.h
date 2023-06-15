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
	void moveDown(RenderWindow const& window);
	void moveUp(RenderWindow const& window);
	RectangleShape getShape();

	float getPositionX();
	void setPositionX(float x_Pos);

	float getPositionY();
	void setPositionY(float y_Pos);
	
	LeftPlayer(Vector2f const& size, Vector2f const& position, Color const& p_color);

};



