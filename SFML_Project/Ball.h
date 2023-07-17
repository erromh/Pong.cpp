#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Players.h"
using namespace sf;

class Ball
{
	friend class Players;
	friend class App;

private:

	CircleShape m_ballShape;
	Vector2f m_position;

	Text count;

	int countLeft = 0;
	int countRight = 0;

	float m_DirectionX = 100.0f;
	float m_DirectionY = 100.0f;

	float m_velocity = 25000.f;

	float dx1 = rand() % 10;
	float dy1 = rand() % 10;

public:
	Ball(Color color);
	~Ball();

	CircleShape getShape();

	void ballMoving(Ball const& ball);

	void Collision(Ball const& ball, Players const& players, Players const& rightplayer, RenderWindow const& window);

	void counter(Ball const& ball, RenderWindow const& window);

	Text getCounter();

	float getBallPositionX();
	void setBallPositionX(float const&);

	float getBallPositionY();
	void setBallPositionY(float const&);

	float getX();
	void setX(float const& x);

	float getY();
	void setY(float const&);
};

