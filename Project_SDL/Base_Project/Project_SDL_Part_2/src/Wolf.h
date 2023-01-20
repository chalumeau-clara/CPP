#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"

const int eat_distance = 10;
const int fear_distance = 10;

class Wolf : public Animal {
    public:
        // Constructeur

        Wolf(SDL_Surface* window_surface_ptr):
                Animal(wolf_texture_path, window_surface_ptr){};

        virtual ~Wolf(){};

        // Fonction pour déplacement aléatoire
        virtual void move() override;
        virtual void interact(Interacting_object &other_object) override;

    private:
        SDL_Rect* nearest_sheep_position_;

    };


#endif // WOLF_H
