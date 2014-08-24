#pragma once

#include "Sprite.h"
#include <math.h>

class Entity
{
public:
	Entity(string imageName, int position_X, int position_Y);
	~Entity(void);

	double getX();
	double getY();

	int getWidth();
	int getHeight();

	void setPosition(int newX, int newY);

	void setVelocity_X(double);
	void setVelocity_Y(double);

	void draw();

	void update();

	Entity* shoot(int toX, int toY);

	bool disposable();

	void rotate(int toX, int toY);

private:
	double x, y;
	double velocityX, velocityY;

	float angle;
	
	Sprite image;
};

