#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"

class Wolf : public Animal {
    public:
        // Constructeur

        Wolf(SDL_Surface* window_surface_ptr, uint64_t x_position, uint64_t y_position):
                Animal("../media/wolf.png", window_surface_ptr ,x_position, y_position){};

    //     Wolf(SDL_Surface* window_surface_ptr, unsigned seed):
    //     Animal(wolf_texture_path, window_surface_ptr, wolf_width, wolf_height){
    //         // Add properties.
    //         set_property("wolf");
    //         set_property("hunter");
    //         set_property("alive");
    //         setVelocityX(wolf_velocity);
    //         setVelocityY(wolf_velocity);
    //         // Nearest sheep position and dog have not been found yet so wolf should stay still.
    //         nearest_prey_position = get_position();
    //         nearest_shepherd_dog_position = get_position();
    //         // Set timer for when wolf should die if starving.
    //         death_time = SDL_GetTicks() + death_delay;

    //         wolf_delay_before_kill = SDL_GetTicks() + wolf_delay_before_kill;

    //         // Set initial position (random).
    //         get_position()->x = clamp(frame_boundary + (rand() % frame_width), frame_width);
    //         get_position()->y = clamp(frame_boundary + (rand() % frame_height), frame_height);
    // };

        virtual ~Wolf(){};

        // Fonction pour déplacement aléatoire
        void move();

    private:
        SDL_Rect *nearest_prey_position;
        SDL_Rect *nearest_shepherd_dog_position;
        Uint32 death_time;
        Uint32 wolf_delay_before_kill = 1000;
    };


#endif // WOLF_H
