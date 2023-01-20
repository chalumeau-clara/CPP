#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"

class Wolf : public Animal {
    public:
        // Constructeur

        Wolf(SDL_Surface* window_surface_ptr, uint64_t x_position, uint64_t y_position):
                Animal(wolf_texture_path, window_surface_ptr ,x_position, y_position){};

        virtual ~Wolf(){};

        // Fonction pour déplacement aléatoire
        void move();

    private:

    };


#endif // WOLF_H
