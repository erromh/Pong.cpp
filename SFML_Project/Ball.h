#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball
{
private:
	CircleShape m_CircleShape;
	Vector2f m_position;

	float m_xVelocity = 4;
	float m_yVelocity = 4;

public:
	Ball(Vector2f, Color);
	CircleShape getShape();
	void ballPosirion();
};

