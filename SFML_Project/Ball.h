#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Players.h"
using namespace sf;

class Ball
{
	friend class Players;
	friend class App;

private:
	CircleShape m_ballShape;
	Vector2f m_position;

	float m_xVelocity = 8;
	float m_yVelocity = 8;

public:
	Ball(Vector2f, Color);
	~Ball();

	CircleShape getShape();

	void ballMoving(Ball const& ball, RenderWindow const & window);

	void Collision(Ball const& ball, Players const& players, Players const& rightplayer);

	float getBallPositionX();
	void setBallPositionX(float const&);

	float getBallPositionY();
	void setBallPositionY(float const&);

	float getBallVelocityX();
	void setBallVelocityX(float xVelocity);

	float getBallVelocityY();
	void setBallVelocityY(float yVelocity);

	bool gameOver();
};

