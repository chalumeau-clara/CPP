#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"
// #include "Wolf.h"
// class Wolf;

const int fear_distance = 200;


class Sheep : public Animal {
public:
    // Constructeur

    Sheep(SDL_Surface* window_surface_ptr):
    Animal(sheep_texture_path, window_surface_ptr){
        set_property("sheep");

        // Set the sheep's velocity
        setVelocityX(1);
        setVelocityY(1);

    };
    virtual void interact(Interacting_object &other_object) override;

    virtual ~Sheep(){};

    // Fonction pour déplacement aléatoire
    void move();

private:
    Interacting_object* nearest_wolf_ = nullptr;
    
};

#endif

