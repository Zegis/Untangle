#include "TileMap.h"
#include <fstream>

using std::fstream;


TileMap::TileMap(void)
{
	water = al_load_bitmap("res/water.png");
}


TileMap::~TileMap(void)
{
	al_destroy_bitmap(water);
}

void TileMap::LoadMap(string mapName)
{
	loadTiles(mapName);
	loadObjects(mapName);
}

void TileMap::loadTiles(string mapName)
{
	fstream mapFile(mapName);

	char tile[2] = "";
	

		for(int i=0;i<16;++i)
		{
			for(int j=0;j<12;++j)
			{
				mapFile.read(tile,2);
				if(strcmp(tile,".1"))
					tiles[i][j] = water;
			}
		}

	mapFile.close();
}

void TileMap::loadObjects(string mapName)
{

}

void TileMap::draw()
{
	for(int i=0; i<16; ++i)
		for(int j=0; j<12; ++j)
			al_draw_bitmap(tiles[i][j], i * 50, j * 50, 0);
}

ALLEGRO_BITMAP* TileMap::getTile(int x, int y)
{
	return tiles[x][y];
}

list<Entity*>::iterator TileMap::getFirstObject()
{
	return objectsOnMap.begin();
}

list<Entity*>::iterator TileMap::getLastObject()
{
	return objectsOnMap.end();
}