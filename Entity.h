#pragma once

#include "Sprite.h";

class Entity
{
public:
	Entity(string imageName, int position_X, int position_Y);
	~Entity(void);

	int getX();
	int getY();

	void setVelocity_X(int);
	void setVelocity_Y(int);

	void draw();

	void update();

private:
	int x, y;
	int velocityX, velocityY;

	Sprite image;
};

