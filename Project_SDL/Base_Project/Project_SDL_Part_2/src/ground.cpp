//
// Created by clara on 15/12/22.
//

#include "ground.h"
ground::ground(SDL_Surface *window_surface_ptr) {
    window_surface_ptr_ = window_surface_ptr;
}
void ground::add_animal(std::unique_ptr<animal> animal_ptr)
{
    animals_.push_back(std::move(animal_ptr));
}
void ground::update()
{
    // refresh the screen": Move animals and draw them
    for (auto &animal_ptr : animals_)
        animal_ptr->move();

    // Clear the screen
    SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0xFF, 0xFF, 0xFF));
    // Draw all animals
    for (auto &animal_ptr : animals_)
        animal_ptr->draw();
}
