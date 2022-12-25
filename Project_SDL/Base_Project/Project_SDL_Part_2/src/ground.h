//
// Created by clara on 15/12/22.
//

#ifndef CPP_GROUND_H
#define CPP_GROUND_H
#include <vector.h>

class ground {

    protected:
        // Attention, NON-OWNING ptr, again to the screen
        SDL_Surface *window_surface_ptr_;

        // Some attribute to store all the wolves and sheep
        // here
        std::vector<std::shared_ptr<animal>> animals_;
        std::vector<std::shared_ptr<character>> character:
        uint64_t nb_sheep = 0;
        uint64_t nb_wolf = 0;

    public:

        ground(SDL_Surface *window_surface_ptr);

        ~ground()= default; // todo: Dtor, again for clean up (if necessary)
        void add_animal(std::unique_ptr<animal> animal_ptr);
        void set_nb_sheep(uint64_t nb);
        void set_nb_wolf(uint64_t nb);
        void add_random();
        // Possibly other methods, depends on your implementation
};


#endif //CPP_GROUND_H
