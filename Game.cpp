#include "Game.h"


Game::Game(void)
{
	if(InitializeAllegro())
		std::cout << "Allegro initialized! \n";

	display = al_create_display(800,600);
	evQueue = al_create_event_queue();
	eventTimer = al_create_timer(1.0 / 05);

	al_register_event_source(evQueue, al_get_keyboard_event_source());
	al_register_event_source(evQueue, al_get_mouse_event_source());
	al_register_event_source(evQueue, al_get_timer_event_source(eventTimer));
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
}



void Game::Run()
{
	ALLEGRO_EVENT currentEvent;

	Entity player("res/Player.png", 50, 50);

	al_set_target_bitmap(al_get_backbuffer(display));

	player.draw();
	al_flip_display();

	al_start_timer(eventTimer);

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
				player.setVelocity_X(-5);
			}
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			{
				player.setVelocity_X(5);
			}
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_UP)
			{
				player.setVelocity_Y(-5);
			}
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_DOWN)
			{
				player.setVelocity_Y(5);
			}
		}
		else if(currentEvent.type == ALLEGRO_EVENT_KEY_UP)
		{
			if(currentEvent.keyboard.keycode == ALLEGRO_KEY_LEFT || currentEvent.keyboard.keycode == ALLEGRO_KEY_RIGHT)
				player.setVelocity_X(0);
			else if(currentEvent.keyboard.keycode == ALLEGRO_KEY_UP || currentEvent.keyboard.keycode == ALLEGRO_KEY_DOWN)
				player.setVelocity_Y(0);
		}
		else if(currentEvent.type == ALLEGRO_EVENT_TIMER)
		{
			al_clear_to_color(al_map_rgb(0,0,0));
			player.update();
			player.draw();
			al_flip_display();
		}
	}
}