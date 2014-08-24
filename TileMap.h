#pragma once

#include<list>
#include"Entity.h"

using std::list;

class TileMap
{
public:
	TileMap(void);
	~TileMap(void);

	list<Entity*>::iterator getFirstObject();
	list<Entity*>::iterator getLastObject();

	void LoadMap(string mapName);

	void draw();

	ALLEGRO_BITMAP* getTile(int x, int y);

private:
	list<Entity*> objectsOnMap;

	ALLEGRO_BITMAP* water;
	ALLEGRO_BITMAP* grass;

	ALLEGRO_BITMAP* tiles[16][12];

	void loadTiles(string mapName);
	void loadObjects(string mapName);

	static bool RemoveAll(Entity* value);
};

