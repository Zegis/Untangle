#pragma once

#include <iostream>

#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include "Entity.h"

class Game
{
public:
	Game(void);
	
	void Run(void);

	~Game(void);

private:

	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* evQueue;
	ALLEGRO_TIMER* eventTimer;

	bool InitializeAllegro();
};

