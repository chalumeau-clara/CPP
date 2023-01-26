#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"
#include "Sheep.h"

const int eat_distance = 1;
const int fear_distance = 10;

class Wolf : public Animal {
    public:
        // Constructeur

        Wolf(SDL_Surface* window_surface_ptr):
            Animal(wolf_texture_path, window_surface_ptr){
                set_property("wolf");
                set_property("alive");

                setVelocityX(2);
                setVelocityY(2);
            };

        virtual ~Wolf(){};

        // Fonction pour déplacement aléatoire
        virtual void move() override;
        virtual void interact(Interacting_object &other_object) override;

    private:
        Sheep* nearest_sheep_ = nullptr;

    };


#endif // WOLF_H
