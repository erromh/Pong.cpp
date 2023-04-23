#include <iostream>
#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
#include "RightPlayer.h"

using namespace sf;
using namespace std;

//https://austinmorlan.com/posts/pong_clone/

int main()
{
	const int WINDOW_HEIGHT = 600;
	const int WINDOW_WIDTH = 1000;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), " ", Style::None);
	window.setFramerateLimit(60);

	Texture textureBackGround;
	textureBackGround.loadFromFile("D:/c++++/SFML_Project/Background.png");

	Sprite spriteBackgrund;

	spriteBackgrund.setTexture(textureBackGround);
	spriteBackgrund.setPosition(0, 0);

	Vector2f leftPosition(0, 225);
	Vector2f rightPosition(950, 225);

	LeftPlayer leftpl(leftPosition, Color::Red);
	RightPlayer rightPlayer(rightPosition, Color::Blue);


	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::KeyPressed)
			{

				if (event.key.code == Keyboard::S)
				{
					leftpl.moveDown();
				}

				if (event.key.code == Keyboard::W)
				{
					leftpl.moveUp();
					cout << "Y left = " << leftPosition.y << endl << endl;
				}

				if (event.key.code == Keyboard::Up)
				{
					rightPlayer.moveUp();
					cout << "Y right = " << rightPosition.y << endl << endl;
				}

				if (event.key.code == Keyboard::Down)
				{
					rightPlayer.moveDown();
					cout << "Y right = " << rightPosition.y << endl << endl;
				}
			}
		}

		window.clear();
		window.draw(spriteBackgrund);
		window.draw(leftpl.getShape());
		window.draw(rightPlayer.getShape());
		window.display();
		
	}
	return 0;
}	






