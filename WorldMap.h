#pragma once

#include "Sprite.h"

class WorldMap
{
public:
	WorldMap(void);
	~WorldMap(void);

	void draw();
	void draw(int connectedWorld);

private:
	
	ALLEGRO_BITMAP* tangledWorlds;
	ALLEGRO_BITMAP* untangledWorlds;
	ALLEGRO_BITMAP* connectedWorlds_1_2;
	ALLEGRO_BITMAP* connectedWorlds_1_3;
};

