#include "Ground.h"
#include "Sheep.h"

Ground::Ground(SDL_Surface *window_surface_ptr) {
    window_surface_ptr_ = window_surface_ptr;
    background = IMG_Load("../media/background.png");
}

// remove the animal from the ground
void Ground::removeAnimal(std::shared_ptr<Moving_object> animal) {
    // remove the animal from the list
    characters.erase(std::remove(characters.begin(), characters.end(), animal), characters.end());
}

void Ground::update()
{
    SDL_Rect background_rect = {0, 0, window_surface_ptr_->w, window_surface_ptr_->h};
    SDL_BlitScaled(background, NULL, window_surface_ptr_, &background_rect);

    // refresh all animals
    for (auto &moving_obj : characters)
    {
        // check if the moving object got "dead" and remove it from the ground_
        if (!moving_obj->find_property("dead"))
        {
            moving_obj->move();

            // draw the animal
            moving_obj->draw(moving_obj->get_position()->x, moving_obj->get_position()->y);

            // interact this animal with all other animals
            for (auto &other_moving_obj : characters)
            {
                if (moving_obj != other_moving_obj)
                {
                    moving_obj->interact(*other_moving_obj);
                }
            }
            // // check if it is a sheep and dynamically cast it to a sheep
            // if (moving_obj->find_property("sheep"))
            // {
            //     // remove a sheep from the ground
            //     nb_sheep--;
            //     // add a point to the score
            //     score++;
            //     // dynamic cast to a sheep
            //     // std::shared_ptr<Sheep> sheep = std::dynamic_pointer_cast<Sheep>(moving_obj);
            //     // removeAnimal(sheep);
            // }
            
        }

        
        
    }
    // SDL_FreeSurface(background);
    // Clear the screen
    // SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0xFF, 0xFF, 0xFF));

    // Draw all animals
    // for (auto &moving_obj : characters){
    //     // check if the moving object got "dead" and remove it from the list
    //     if (!moving_obj->find_property("dead")){
    //     }
    //     else
    //         moving_obj->draw(moving_obj->get_position()->x, moving_obj->get_position()->y);
    // }
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


