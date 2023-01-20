#ifndef SHEPHERD_DOG_H
#define SHEPHERD_DOG_H

#include "Animal.h"

class Shepherd_dog : public Animal {
public:

    Shepherd_dog(SDL_Surface* window_surface_ptr, uint64_t x_position, uint64_t y_position):
    Animal(shepherd_dog_texture_path, window_surface_ptr,x_position, y_position){};
    virtual ~Shepherd_dog(){};

    // Shepherd_dog(SDL_Surface* window_surface_ptr):Animal("../../media/shepherd_dog.png", window_surface_ptr){};
    // virtual ~Shepherd_dog();


    // Fonction pour déplacement en suivant le berger
    void move();
};

#endif
