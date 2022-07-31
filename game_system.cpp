#include "game_system.h"

int GameSystem::init(){

    done = false;
    FPS = 60;

    if(!al_init()){
        al_show_native_message_box(display, gameTitle, "Blad", "Nie udalo sie zainicjowac allegro5! \n Prosze uruchomic ponownie gre", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    display = al_create_display(gameWidth, gameHeight);
    al_set_window_title(display, gameTitle);

    if(!display)
	{
		al_show_native_message_box(display, gameTitle, "Blad", "Nie udalo sie zainicjowac ekranu gry! \n Prosze uruchomic ponownie gre", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

    al_init_image_addon();
    al_init_primitives_addon();
    
    al_init_font_addon();
    al_init_ttf_addon();

    al_install_audio();
    al_init_acodec_addon();

    al_install_mouse();
    al_install_keyboard();

    eventQueque = al_create_event_queue();
    al_register_event_source(eventQueque, al_get_display_event_source(display));
    al_register_event_source(eventQueque, al_get_mouse_event_source());
    al_register_event_source(eventQueque, al_get_keyboard_event_source());

    timer = al_create_timer(1.0 / FPS);
    al_register_event_source(eventQueque, al_get_timer_event_source(timer));
    al_start_timer(timer);

    return 0;
}

void GameSystem::destroy(){

    al_destroy_display(display);
    al_destroy_event_queue(eventQueque);
    al_destroy_timer(timer);

}