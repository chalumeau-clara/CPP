#ifndef GROUND_H
#define GROUND_H

#include "Moving_object.h"
#include <vector>
#include <memory>
#include <iostream>

class Ground {
public:
    // Constructeur
    Ground(SDL_Surface* window_surface_ptr);
    ~Ground() = default;

    void update(); // todo: "refresh the screen": Move animals and draw them
    void set_nb_sheep(uint64_t nb);
    void set_nb_wolf(uint64_t nb);
    void set_nb_shephered_dog(uint64_t nb);
    uint64_t get_nb_shephered_dog();
    // std::vector<std::shared_ptr<Animal>>& getAnimals();
    void add_character(std::shared_ptr<Moving_object>);
    // void removeAnimals(std::shared_ptr<Animal>);

protected:
    // Attention, NON-OWNING ptr, again to the screen
    SDL_Surface *window_surface_ptr_;
    // Vector of all the character present on the screen
    std::vector<std::shared_ptr<Moving_object>> characters;
    uint64_t nb_sheep = 0;
    uint64_t nb_wolf = 0;
    uint64_t nb_shepherd_dog = 4;
    uint64_t score = 0;

};

#endif // GROUND_H