#include "Entity.h"


Entity::Entity(string imageName, int position_X, int position_Y): image(imageName)
{
	x = position_X;
	y = position_Y;

	velocityX = velocityY = 0;

	angle = 0;
}

double Entity::getX()
{
	return x;
}

double Entity::getY()
{
	return y;
}

int Entity::getHeight()
{
	return image.getHeight();
}

int Entity::getWidth()
{
	return image.getWidth();
}

void Entity::setPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Entity::setVelocity_X(double newVelocity)
{
	velocityX = newVelocity;
}

void Entity::setVelocity_Y(double newVelocity)
{
	velocityY = newVelocity;
}

void Entity::draw()
{
	al_draw_rotated_bitmap(image.getImage(), image.getWidth()/2, image.getHeight()/2,  x, y, angle ,0);
}

void Entity::update()
{
	x += velocityX;
	y += velocityY;
}

bool Entity::disposable()
{
	if(x < 0 || x > 800 || y < 0 || y > 600)
		return true;
	else
		return false;
}

Entity* Entity::shoot(int toX, int toY)
{
	Entity* bullet = new Entity("res/bullet.png", x, y);

	double deltaX = toX - x;
	double deltaY = toY -y;

	double angle = atan2(deltaY, deltaX);

	bullet->setVelocity_X(cos(angle)*15);
	bullet->setVelocity_Y(sin(angle)*15);

	return bullet;
}

void Entity::rotate(int toX, int toY)
{
	double deltaX = toX - x;
	double deltaY = toY -y;

	 angle = atan2(deltaY, deltaX);
}

Entity::~Entity(void)
{
}
