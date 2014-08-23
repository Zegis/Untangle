#include "Entity.h"


Entity::Entity(string imageName, int position_X, int position_Y): image(imageName)
{
	x = position_X;
	y = position_Y;

	velocityX = velocityY = 0;
}

int Entity::getX()
{
	return x;
}

int Entity::getY()
{
	return y;
}

void Entity::setVelocity_X(int newVelocity)
{
	velocityX = newVelocity;
}

void Entity::setVelocity_Y(int newVelocity)
{
	velocityY = newVelocity;
}

void Entity::draw()
{
	al_draw_bitmap(image.getImage(), x, y, 0);
}

void Entity::update()
{
	x += velocityX;
	y += velocityY;
}

Entity::~Entity(void)
{
}
