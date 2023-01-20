#ifndef SHEPHERD_DOG_H
#define SHEPHERD_DOG_H

#include "Animal.h"

class Shepherd_dog : public Animal {
public:

    Shepherd_dog(SDL_Surface* window_surface_ptr):Animal("../media/shepherd_dog.png", window_surface_ptr){};
    virtual ~Shepherd_dog();


    // Fonction pour déplacement en suivant le berger
    void move();
};

#endif
