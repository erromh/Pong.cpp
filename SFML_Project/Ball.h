#pragma once
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
#include "RightPlayer.h"
using namespace sf;

class Ball
{
	friend class LeftPlayer;
	friend class RightPlayer;
	friend class App;

private:
	RectangleShape m_ballShape;
	Vector2f m_position;

	float m_xVelocity = 8;
	float m_yVelocity = 8;

public:
	Ball(Vector2f, Vector2f, Color);

	RectangleShape getShape();

	void ballMoving(LeftPlayer const& leftplayer);

	void Collision(Ball const& ball, LeftPlayer const& leftplayer, RightPlayer const& rightplayer);

	float getBallPositionX();
	void setBallPositionX(float ball_x);

	float getBallPositionY();
	void setBallPositionY(float ball_y);

	float getBallVelocityX();
	void setBallVelocityX(float xVelocity);

	float getBallVelocityY();
	void setBallVelocityY(float yVelocity);

	void printBallLeft(Ball const& ball);
};

