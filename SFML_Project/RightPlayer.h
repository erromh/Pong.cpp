#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class RightPlayer
{
	friend class Ball;
	friend class App;

private:

	Vector2f m_rightPosition;
	RectangleShape m_Shape;
	Color m_Color;
	float yRightVelocity = 30;

public:

	void moveDown(RenderWindow const& window);
	void moveUp(RenderWindow const& window);
	RectangleShape getShape();
	RightPlayer(Vector2f const& size, Vector2f const& start_pos, Color const& p_color);

	float getPositionX();
	void setPositionX(float x_PosRight);

	float getPositionY();
	void setPositionY(float y_PosRight);
};

