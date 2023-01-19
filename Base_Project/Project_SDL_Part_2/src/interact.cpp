//
// Created by clara on 15/12/22.
//

#include <random>
#include "interact.h"


Interact::Interact(const std::string &file_path, SDL_Surface *window_surface_ptr) {
    render_ = Render(file_path, window_surface_ptr);

    // Set random position of the animal
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, frame_width - 1);
    x_pos = dis(gen);
    std::uniform_int_distribution<> dis2(0, frame_height - 1);
    y_pos = dis2(gen);

    //Random move
    x_direction = RIGHT; // TODO
    y_direction = UP; // TODO and others attributes
}
