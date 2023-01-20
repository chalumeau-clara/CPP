#ifndef SHEPHERD_H
#define SHEPHERD_H

#include "Playable_character.h"

class Shepherd : public Playable_character {
public:

    // Constructeur
    Shepherd(SDL_Surface* window_surface_ptr,SDL_Event window_event):
    Playable_character(shepherd_texture_path, window_surface_ptr, window_event){
        window_events = window_event;
    };

    virtual ~Shepherd() = default;
    // Fonction pour déplacement en fonction des entrées
    virtual void interact(Interacting_object &other_object) override;

    virtual void move() override;

private:
    SDL_Event window_events;
};

#endif