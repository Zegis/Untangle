#pragma once

#include <iostream>

#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "Entity.h"
#include "TileMap.h"
#include "WorldMap.h"

#include <math.h>
#include <list>

using std::list;

class Game
{
public:
	Game(void);
	
	void Run(void);

	~Game(void);

private:

	void GameBriefing();
	void GameLoop();

	void GameWin();
	void GameLost();

	void DisconnectWorlds(int worldToDisconnect);

	int connectedWorlds;

	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* evQueue;
	ALLEGRO_TIMER* eventTimer;

	ALLEGRO_FONT* font;

	int Worldcounter;

	ALLEGRO_MOUSE_CURSOR* curs;

	list<Entity*> bullets;

	Entity*	player;

	TileMap* map;

	WorldMap* worlds;

	bool InitializeAllegro();
};

