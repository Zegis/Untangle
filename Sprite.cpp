#include "Sprite.h"

#include <iostream>

Sprite::Sprite(string imageName)
{
	image = al_load_bitmap(imageName.c_str());
}

void Sprite::setImage(string imageName)
{
	if(image != NULL)
		al_destroy_bitmap(image);

	image = al_load_bitmap(imageName.c_str());
}

ALLEGRO_BITMAP* Sprite::getImage()
{
	return image;
}

int Sprite::getHeight()
{
	return al_get_bitmap_height(image);
}

int Sprite::getWidth()
{
	return al_get_bitmap_width(image);
}

Sprite::~Sprite(void)
{
	al_destroy_bitmap(image);
}
