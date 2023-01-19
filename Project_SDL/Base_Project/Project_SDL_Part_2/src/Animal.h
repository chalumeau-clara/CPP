#ifndef ANIMAL_H
#define ANIMAL_H

#include "Moving_object.h"

class Animal : public Moving_object {
public:
    Animal(const std::string &file_path, SDL_Surface* window_surface_ptr): Moving_object(file_path, window_surface_ptr){};
    virtual ~Animal(){};

    // Fonction virtuelle pour déplacement
    virtual void move() = 0;
};

#endif // ANIMAL_H