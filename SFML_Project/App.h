#pragma once
class App
{
	friend class Leftplayer;
	friend class RightPlayer;
	friend class Ball;

public:
	void show();
	//bool checkPlayerCollision(Ball& ball, LeftPlayer& leftplayer, RightPlayer& rightPlayer);
};

