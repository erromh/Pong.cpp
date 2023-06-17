#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
using namespace sf;

class LeftPlayer
{
	friend class Ball;
	friend class App;

private:

	Vector2f m_Leftposition;
	RectangleShape m_ShapeLeft;
	Color m_ColorLeft;
	float yLeftVelocity = 20;

public:
	void moveDownLeft(RenderWindow const& window, LeftPlayer const& leftplayer);
	void moveUpLeft(RenderWindow const& window, LeftPlayer const& leftplayer);
	RectangleShape getShapeLeft();

	float getPositionX();
	void setPositionX(float x_Pos);

	float getPositionY();
	void setPositionY(float y_Pos);
	
	LeftPlayer(Vector2f const& size, Vector2f const& position, Color const& p_color);

	bool stopLeft(bool&);
};



