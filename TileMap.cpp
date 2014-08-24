#include "TileMap.h"
#include <fstream>

using std::fstream;
using std::getline;


TileMap::TileMap(void)
{
	water = al_load_bitmap("res/water.png");
	grass = al_load_bitmap("res/grass.png");
	fire = al_load_bitmap("res/fire.png");
}


TileMap::~TileMap(void)
{
	al_destroy_bitmap(water);
	al_destroy_bitmap(grass);
	al_destroy_bitmap(fire);

	objectsOnMap.remove_if(RemoveAll);
}

bool TileMap::RemoveAll(Entity* value)
{
	delete value;
	return true;
}

void TileMap::LoadMap(string mapName)
{
	loadTiles(mapName);
	loadObjects(mapName);
}

void TileMap::loadTiles(string mapName)
{
	fstream mapFile(mapName);

	char tile[3];
	tile[2] = '\0';
	

		for(int j=0;j<12;++j)
		{
			for(int i=0;i<16;++i)
			{
				mapFile.read(tile,2);
				if(tile[0] == '\n')
				{
					mapFile.seekg((int)mapFile.tellg()-1);
					mapFile.read(tile,2);
				}

				if(std::strcmp(tile,".1") == 0)
					tiles[i][j] = water;
				else if(strcmp(tile,".2") == 0)
					tiles[i][j] = fire;
				else if(std::strcmp(tile,".3")==0)
					tiles[i][j] = grass;
			}
		}

	mapFile.close();
}

void TileMap::loadObjects(string mapName)
{
	fstream mapFile(mapName);

	string line;
	size_t firstComma, lastComma;
	int x, y;

	do
	{
		getline(mapFile,line);
	}
	while(line.compare("==") != 0);

	while(getline(mapFile,line))
	{
		firstComma = line.find(',');
		lastComma = line.find(',',firstComma+1);
			
		x = std::atoi(line.substr(firstComma+1,lastComma).c_str());
		y = std::atoi(line.substr(lastComma+1).c_str());

		if(line[0] == 'k')
		{
			
			if(line[1] == '2')
			{
				objectsOnMap.push_back(new Entity("res/Key_2.png",x*50, y*50,2));
			}
			else if(line[1] == '3')
			{
				objectsOnMap.push_back(new Entity("res/Key_3.png",x*50, y*50,3));
			}
		}
		else if(line[0] == '@')
		{
			objectsOnMap.push_back(new Entity("res/enemy.png",x*50,y*50));
		}
	}

	mapFile.close();
}

void TileMap::draw()
{
	for(int i=0; i<16; ++i)
		for(int j=0; j<12; ++j)
			al_draw_bitmap(tiles[i][j], i * 50, j * 50, 0);

	list<Entity*>::iterator it = objectsOnMap.begin();
	while(it != objectsOnMap.end())
	{
		if( !(*it)->isDisposable())
		{
			(*it)->draw();
			it++;
		}
		else
		{
			delete (*it);
			objectsOnMap.erase(it++);
		}
	}
}

Entity* TileMap::checkCollisions(Entity* objectToCheck)
{
	int x0 = objectToCheck->getX();
	int y0 = objectToCheck->getY();
	int x1 = 0;
	int y1 = 0;

	int width, height;

	list<Entity*>::iterator it = objectsOnMap.begin();
	while(it != objectsOnMap.end())
	{

		x1 = (*it)->getX();
		y1 = (*it)->getY();
		width = (*it)->getWidth();
		height  = (*it)->getHeight();

		if( x0 < x1 + (*it)->getWidth() &&
			x1 < x0 + objectToCheck->getWidth() &&
			y0 < y1 + (*it)->getHeight() &&
			y1 < y0 + objectToCheck->getHeight() &&
			!(*it)->isPickUp())
				return (*it);

		it++;
	}

	return NULL;
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