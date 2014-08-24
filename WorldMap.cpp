#include "WorldMap.h"


WorldMap::WorldMap(void)
{
	tangledWorlds = al_load_bitmap("res/World_01.png");
	untangledWorlds = al_load_bitmap("res/World_04.png");

	connectedWorlds_1_2 = al_load_bitmap("res/World_02.png");
	connectedWorlds_1_3 = al_load_bitmap("res/World_03.png");

}

void WorldMap::draw()
{
	al_draw_bitmap(tangledWorlds,0,0,0);
}

void WorldMap::draw(int connectedWorld)
{
	if(connectedWorld == 2)
		al_draw_bitmap(connectedWorlds_1_2,0,0,0);
	else if(connectedWorld == 3)
		al_draw_bitmap(connectedWorlds_1_3,0,0,0);
	else
		al_draw_bitmap(untangledWorlds, 0,0,0);
}

WorldMap::~WorldMap(void)
{
	al_destroy_bitmap(tangledWorlds);
	al_destroy_bitmap(untangledWorlds);
	al_destroy_bitmap(connectedWorlds_1_2);
	al_destroy_bitmap(connectedWorlds_1_3);
}
