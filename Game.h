#pragma once

#include <iostream>

#include <allegro5\allegro5.h>

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

