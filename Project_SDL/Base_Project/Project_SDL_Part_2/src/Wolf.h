#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"

class Wolf : public Animal {
    public:
        // Constructeur

        Wolf(SDL_Surface* window_surface_ptr):
                Animal("../media/wolf.png", window_surface_ptr){};

        virtual ~Wolf(){};

        // Fonction pour déplacement aléatoire
        void move();
    };


#endif // WOLF_H
