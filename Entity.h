#pragma once

#include "Sprite.h"
#include <math.h>

class Entity
{
public:
	Entity(string imageName, int position_X, int position_Y);
	Entity(string imageName, int position_X, int position_Y, int pickupId);
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

	void setDisposable();
	bool isDisposable();

	void rotate(int toX, int toY);

	bool isPickUp();
	int getPickUp_ID();

	void hit();

	void setMaxHp(int maxHP);

	bool isPlayer();
	void setPlayer();

private:

	bool disposable;

	bool player;

	int hp;

	int pickUp;
	double x, y;
	double velocityX, velocityY;

	float angle;
	
	Sprite image;
};

