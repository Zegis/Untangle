#include "Game.h"


Game::Game(void)
{
	if(InitializeAllegro())
		std::cout << "Allegro initialized!";

	display = al_create_display(800,600);
	evQueue = al_create_event_queue();
	eventTimer = al_create_timer(1.0 / 05);

	al_register_event_source(evQueue, al_get_keyboard_event_source());
	al_register_event_source(evQueue, al_get_timer_event_source(eventTimer));
}

bool Game::InitializeAllegro(void)
{
	al_init();
	al_install_keyboard();


	return true;
}

Game::~Game(void)
{
	al_destroy_display(display);
	al_destroy_event_queue(evQueue);
}



void Game::Run()
{
	ALLEGRO_EVENT currentEvent;

	while(true)
	{
		al_wait_for_event(evQueue, &currentEvent);

		if(currentEvent.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if(currentEvent.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				break;
			}
		}
	}
}