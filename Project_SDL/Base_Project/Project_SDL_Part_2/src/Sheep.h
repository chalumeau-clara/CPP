#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
public:
    // Constructeur

    Sheep(SDL_Surface* window_surface_ptr):
    Animal(sheep_texture_path, window_surface_ptr){

    };
    virtual void interact(Interacting_object &other_object) override;

    virtual ~Sheep(){};

    // Fonction pour déplacement aléatoire
    void move();
};

#endif

