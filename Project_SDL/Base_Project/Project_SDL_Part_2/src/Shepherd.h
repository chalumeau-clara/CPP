#ifndef SHEPHERD_H
#define SHEPHERD_H

#include "Playable_character.h"

class Shepherd : public Playable_character {
public:



    // Constructeur
    Shepherd(SDL_Surface* window_surface_ptr,SDL_Event window_event):
    Playable_character("../media/shepherd.png", window_surface_ptr, window_event){};

    virtual ~Shepherd() = default;
    // Fonction pour déplacement en fonction des entrées
    void move();
};

#endif