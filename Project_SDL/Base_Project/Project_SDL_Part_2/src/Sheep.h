#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
public:
    // Constructeur

    Sheep(SDL_Surface* window_surface_ptr):
    Animal("../../media/sheep.png", window_surface_ptr){};

    virtual ~Sheep(){};


    // Fonction pour déplacement aléatoire
    void move();
};

#endif

