#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

#define gameTitle "LOGO QUIZ"
#define gameWidth 640
#define gameHeight 900

#pragma once

class GameSystem{
public:
    ALLEGRO_DISPLAY *display;

    ALLEGRO_EVENT_QUEUE *eventQueque;
    ALLEGRO_EVENT event;

    ALLEGRO_TIMER *timer;

    bool done;
    bool redraw;

    float FPS;

    int init();
    void destroy();
};