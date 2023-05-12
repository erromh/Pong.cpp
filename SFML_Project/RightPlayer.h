#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class RightPlayer : public Player
{
private:

	Vector2f m_rightPosition;
	RectangleShape m_Shape;
	Color m_Color;
	float yRightVelocity = 30;

public:

	void moveDown();
	void moveUp();
	RectangleShape getShape();
	RightPlayer(Vector2f start_pos, Color p_color);

	float getPositionX();
	void setPositionX(float x_PosRight);

	float getPositionY();
	void setPositionY(float y_PosRight);
};

