#ifndef SHEPHERD_H
#define SHEPHERD_H

#include "Playable_character.h"

class Shepherd : public Playable_character {
public:

    // Constructeur
    Shepherd(SDL_Surface* window_surface_ptr,SDL_Event window_event, uint64_t x_position, uint64_t y_position):
    Playable_character("../media/shepherd.png", window_surface_ptr, window_event,x_position, y_position){
        window_events = window_event;
    };

    // Shepherd(SDL_Surface* window_surface_ptr,SDL_Event window_event):
    // Playable_character(sheep_texture_path, window_surface_ptr, shepherd_width, shepherd_height, window_event){
    //     set_property("shepherd");
    //     set_property("alive");

    //     get_position()->x = frame_width / 2 - shepherd_width / 2;
    //     get_position()->y = frame_height / 2 - shepherd_height / 2;
    // };

    virtual ~Shepherd() = default;
    // Fonction pour déplacement en fonction des entrées
    void move();
private:
    SDL_Event window_events;
};

#endif