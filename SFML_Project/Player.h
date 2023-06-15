#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{

private:

	Vector2f m_Leftposition;
	RectangleShape m_Shape;
	Color m_Color;

public:
	
	void virtual moveUp(RenderWindow const& window) = 0;
	void virtual moveDown(RenderWindow const& window) = 0;

	virtual RectangleShape getShape() = 0;
};


