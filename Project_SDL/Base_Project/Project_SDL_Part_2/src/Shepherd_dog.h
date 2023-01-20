#ifndef SHEPHERD_DOG_H
#define SHEPHERD_DOG_H

#include "Animal.h"

class Shepherd_dog : public Animal {
public:

    Shepherd_dog(SDL_Surface* window_surface_ptr):
    Animal(shepherd_dog_texture_path, window_surface_ptr){};
    virtual ~Shepherd_dog(){};



    // Fonction pour déplacement en suivant le berger
    virtual void move() override;
    virtual void interact(Interacting_object &other_object) override;
};

#endif
