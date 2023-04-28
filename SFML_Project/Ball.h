#pragma once
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
using namespace sf;

class Ball
{
private:
	CircleShape m_CircleShape;
	Vector2f m_position;

	float m_xVelocity = 8;
	float m_yVelocity = 8;

public:
	Ball(Vector2f, Color);
	CircleShape getShape();
	void ballPosition();

	friend class LeftPlayer;

	void checkLeftPlayerPosition();
};

