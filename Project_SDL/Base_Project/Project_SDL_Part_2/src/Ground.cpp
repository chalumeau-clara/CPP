#include "Ground.h"



Ground::Ground(SDL_Surface *window_surface_ptr) {
    window_surface_ptr_ = window_surface_ptr;
}

void Ground::update()
{
    // refresh the screen": Move animals and draw them
    for (auto &animal_ptr : character)
        animal_ptr->move();

    // Clear the screen
    SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0xFF, 0xFF, 0xFF));
    // Draw all animals
    //for (auto &animal_ptr : character)
        //animal_ptr->render_.draw(animal_ptr->get_x_pos(), animal_ptr->get_y_pos());
}
void Ground::set_nb_sheep(uint64_t nb) {
    nb_sheep = nb;
}

void Ground::set_nb_wolf(uint64_t nb){
    nb_wolf = nb;
}
void Ground::set_nb_shephered_dog(uint64_t nb){
    nb_shepherd_dog = nb;
}
// std::vector<std::shared_ptr<Animal>>& Ground::getAnimals() {
//     return animals_;
// }

// void Ground::addAnimals(std::shared_ptr<Animal> animal) {
//     animals_.push_back(animal);
// }

// void Ground::removeAnimals(std::shared_ptr<Animal> animal) {
//     for (auto it = animals_.begin(); it != animals_.end();) {
//         if (it->get() == animal.get()) {
//             it = animals_.erase(it);
//         } else {
//             ++it;
//         }
//     }
// }


