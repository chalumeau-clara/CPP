#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
public:
    // Constructeur

    Sheep(SDL_Surface* window_surface_ptr, uint64_t x_position, uint64_t y_position):
    Animal(sheep_texture_path, window_surface_ptr, x_position, y_position){

    };
    virtual void interact(){}; // todo: implement

    virtual ~Sheep(){};

    // Fonction pour déplacement aléatoire
    void move();
};

#endif

