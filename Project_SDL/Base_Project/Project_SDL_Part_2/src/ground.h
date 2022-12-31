//
// Created by clara on 15/12/22.
//

#ifndef CPP_GROUND_H
#define CPP_GROUND_H
#include "interact.h"
#include <vector>
#include <SDL_surface.h>
#include <memory>

class ground {
public:

    ground(SDL_Surface *window_surface_ptr);

    ~ground()= default; // todo: Dtor, again for clean up (if necessary)
    void add_character(std::unique_ptr<interact> character_ptr);
    void update(); // todo: "refresh the screen": Move animals and draw them
    void set_nb_sheep(uint64_t nb);
    void set_nb_wolf(uint64_t nb);
    void set_nb_shephered_dog(uint64_t nb);
    void add_random();
    // Possibly other methods, depends on your implementation
protected:
    // Attention, NON-OWNING ptr, again to the screen
    SDL_Surface *window_surface_ptr_;

    // Vector of all the character present on the screen
    std::vector<std::shared_ptr<interact>> character;
    uint64_t nb_sheep = 0;
    uint64_t nb_wolf = 0;
    uint64_t nb_shepherd_dog = 4;
    uint64_t score = 0;



};


#endif //CPP_GROUND_H
