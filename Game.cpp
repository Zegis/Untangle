#include "Game.h"


Game::Game(void)
{
	if(InitializeAllegro())
	{
		std::cout << "Allegro initialized! \n";

		connectedWorlds = 3;

		player = new Entity("res/player.png", 50, 50);
		map = new TileMap();

		worlds = new WorldMap();

		display = al_create_display(800,600);
		evQueue = al_create_event_queue();
		eventTimer = al_create_timer(1.0 / 60);

		curs = al_create_mouse_cursor(al_load_bitmap("res/cursor.bmp"),0,0);
		al_set_mouse_cursor(display,curs);

		al_register_event_source(evQueue, al_get_keyboard_event_source());
		al_register_event_source(evQueue, al_get_mouse_event_source());
		al_register_event_source(evQueue, al_get_timer_event_source(eventTimer));
		al_register_event_source(evQueue, al_get_display_event_source(display));

		al_set_window_title(display,"Untangle!");
	}
	else
		std::cout << " Error initializing allegro";
}

bool Game::InitializeAllegro(void)
{
	al_init();
	al_install_keyboard();
	al_install_mouse();

	al_init_image_addon();

	return true;
}

Game::~Game(void)
{
	std::cout << "Uninitializing allegro! \n";

	al_destroy_display(display);
	al_destroy_event_queue(evQueue);

	al_destroy_timer(eventTimer);

	al_destroy_mouse_cursor(curs);

	if(!bullets.empty())
	{
		list<Entity*>::iterator it = bullets.begin();
		while(it != bullets.end())
		{
			delete (*it);
			bullets.erase(it++);
		}
	}

	delete player;
	delete map;
	delete worlds;

	std::cin.get();

}



void Game::Run()
{
	al_set_target_bitmap(al_get_backbuffer(display));


	std::cout << "I'm loading map01.txt\n";

	map->LoadMap("maps/map01.txt");

	std::cout << "End of loading\n";

	GameBriefing();

	GameLoop();
}

void Game::GameBriefing()
{
	worlds->draw(connectedWorlds);

	al_flip_display();

	ALLEGRO_EVENT ev;

	do
		al_wait_for_event(evQueue, &ev);
	while(ev.type != ALLEGRO_EVENT_KEY_CHAR && ev.type != ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
}

void Game::GameLoop()
{
	ALLEGRO_EVENT currentEvent;
	al_start_timer(eventTimer);

	al_hold_bitmap_drawing(true);
	player->draw();
	map->draw();
	al_hold_bitmap_drawing(false);
	al_flip_display();

	while(true)
	{
		al_wait_for_event(evQueue, &currentEvent);

		if(currentEvent.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if(currentEvent.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				break;
			}
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_LEFT)
			{
				player->setVelocity_X(-10);
			}
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			{
				player->setVelocity_X(10);
			}
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_UP)
			{
				player->setVelocity_Y(-10);
			}
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_DOWN)
			{
				player->setVelocity_Y(10);
			}
		}
		else if(currentEvent.type == ALLEGRO_EVENT_KEY_UP)
		{
			if(currentEvent.keyboard.keycode == ALLEGRO_KEY_LEFT || currentEvent.keyboard.keycode == ALLEGRO_KEY_RIGHT)
				player->setVelocity_X(0);
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_UP || currentEvent.keyboard.keycode == ALLEGRO_KEY_DOWN)
				player->setVelocity_Y(0);
		}
		else if(currentEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && currentEvent.mouse.button == 1)
		{
			std::cout << "Shooting from: " << player->getX() << ", " << player->getY() << "\n";
			std::cout << "Shooting to: " << currentEvent.mouse.x << ", " << currentEvent.mouse.y << "\n";

			bullets.push_back(player->shoot(currentEvent.mouse.x, currentEvent.mouse.y));
		}
		else if(currentEvent.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			player->rotate(currentEvent.mouse.x, currentEvent.mouse.y);
		}
		else if(currentEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
		else if(al_is_event_queue_empty(evQueue))
		{

			al_hold_bitmap_drawing(true);
			map->draw();
			player->update();
			player->draw();

			list<Entity*>::iterator it = bullets.begin();
			while( it != bullets.end())
			{
				(*it)->update();

				if (map->checkCollisions((*it)) != NULL)
				{
					(*it)->setDisposable();					
				}

				if( (*it)->isDisposable())
				{
					delete (*it);
					bullets.erase(it++);
				}
				else
				{
					(*it)->draw();
					++it;
				}
			}

			al_hold_bitmap_drawing(false);
			al_flip_display();
		}
	}
}