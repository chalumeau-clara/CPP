#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"

// Sheep default time before reproduction.
constexpr unsigned sheep_reproduction_delay = 2500;



class Sheep : public Animal {
public:
    // Constructeur

    Sheep(SDL_Surface* window_surface_ptr, unsigned seed):
    Animal(sheep_texture_path, window_surface_ptr, sheep_width, sheep_height ){
        speed_timeout_ = 0;
        time_before_reproduction_ = SDL_GetTicks() + sheep_reproduction_delay;

        // Add properties.
        set_property("sheep");
        set_property("alive");
        set_property("prey");
        // Randomly select sheep sex and movement direction.
        srand(time(0) + seed);
        if ((rand() % 2) == 0)
            set_property("male");
        else
            set_property("female");

        // In this case the possible velocities for x/y are: -sheep_velocity, 0, +sheep_velocity.
        int step_x = 0;
        int step_y = 0;
        while (step_x == 0 && step_y == 0) {
            step_x = (-1 + rand() % 3) * sheep_velocity;
            step_y = (-1 + rand() % 3) * sheep_velocity;
        }

        // Set initial position (random).
        get_position()->x = clamp(frame_boundary + (rand() % frame_width), frame_width);
        get_position()->y = clamp(frame_boundary + (rand() % frame_height), frame_height);

        // Set movement.
        step(step_x, step_y);

    };
    virtual void interact(Interacting_object *other_object) override; // todo: implement

    virtual ~Sheep(){};

    bool has_different_sex(Interacting_object *other_object) {
        if (other_object->has_property("female"))
            return this->has_property("male");
        return this->has_property("female");
    };

    bool is_reproduction_time() {
        return SDL_GetTicks() > time_before_reproduction_;
            }


    // Fonction pour déplacement aléatoire
    void move();

private:
    Uint32 time_before_reproduction_;
    Uint32 speed_timeout_;
};

#endif

