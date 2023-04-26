#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class LeftPlayer : public Player
{

private:

	Vector2f m_Leftposition;
	RectangleShape m_Shape;
	Color m_Color;

	bool m_moveDown = false;
	bool m_moveUp = false;

	float yLeftVelocity = 10;

public:
	void moveDown();
	void moveUp();
	RectangleShape getShape();
	void update(Time dt);

	LeftPlayer(Vector2f start_pos, Color p_color);
};



