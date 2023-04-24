#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class LeftPlayer : public Player
{

private:

	Vector2f m_Leftposition;
	RectangleShape m_Shape;
	Color m_Color;

	float yLeftVelocity = 1;

public:
	void moveDown();
	void moveUp();
	RectangleShape getShape();

	LeftPlayer(Vector2f start_pos, Color p_color);
};



