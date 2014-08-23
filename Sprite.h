#pragma once

#include <allegro5\allegro5.h>
#include <string>

using std::string;

class Sprite
{
public:
	Sprite(string imageName);
	~Sprite(void);

	ALLEGRO_BITMAP* getImage();

	int getWidth();
	int getHeight();

	void setImage(string name);

private:

	ALLEGRO_BITMAP * image;
};

