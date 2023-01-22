#include "Ground.h"

Ground::Ground(SDL_Surface *window_surface_ptr) {
    window_surface_ptr_ = window_surface_ptr;
    background = IMG_Load("../media/background.png");
}

void Ground::update()
{
    // refresh the screen": Move animals and draw them
    for (auto &moving_obj : characters)
    {
        moving_obj->move();
        // interact with other animals
        for (auto &moving_obj2 : characters){
            if (moving_obj != moving_obj2){
                moving_obj->interact(*moving_obj2);
            }
        }
    }

    SDL_Rect background_rect = {0, 0, window_surface_ptr_->w, window_surface_ptr_->h};
    SDL_BlitScaled(background, NULL, window_surface_ptr_, &background_rect);
    // SDL_FreeSurface(background);
    // Clear the screen
    // SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0xFF, 0xFF, 0xFF));

    // Draw all animals
    for (auto &moving_obj : characters){
        // check if the moving object got "dead" and remove it from the list
        if (moving_obj->find_property("dead")){
        }
        else
            moving_obj->draw(moving_obj->get_position()->x, moving_obj->get_position()->y);
    }
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

void Ground::add_character(std::shared_ptr<Moving_object> character)
{
    characters.push_back(std::move(character));
}
uint64_t Ground::get_nb_shephered_dog()
{
    return nb_shepherd_dog;
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


