#ifndef ALLEGRO_H
#define ALLEGRO_H

#include <allegro5/allegro.h>

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class Allegro
{
public:
    static void initialize(const int width, const int height);
    static void shutdown(void);

    static const int FPS;

    static ALLEGRO_DISPLAY* display;
    static ALLEGRO_TIMER* timer;
    static ALLEGRO_EVENT_QUEUE* event_queue;

private:
    static void construct(const int width, const int height);
    static void destruct(void);
};

#endif // ALLEGRO_H
