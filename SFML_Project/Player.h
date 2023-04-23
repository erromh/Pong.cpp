#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
	Vector2f m_Leftposition;
	RectangleShape m_Shape;
	Color m_Color;

public:
	
	void virtual moveUp() = 0;
	void virtual moveDown() = 0;

	virtual RectangleShape getShape() = 0;
};


