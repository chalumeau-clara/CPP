#include "Shepherd_dog.h"

//Shepherd_dog(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y, int velocity_x, int velocity_y);
// virtual ~Shepherd_dog();

void Shepherd_dog::interact(Interacting_object &other_object){
    if (other_object.find_property("shepherd")){
    }
}

void Shepherd_dog::move() {
    // check if shepherd is not null
    if (shepherd_ != nullptr)
    {

        int center_x = shepherd_->get_position()->x;
        int center_y = shepherd_->get_position()->y;

        angle += speed;

        int new_x = center_x + radius * cos(angle);
        int new_y = center_y + radius * sin(angle);
        
        // mettre à jour les coordonnées x et y du Shepherd_dog
        this->get_position()->x = new_x;
        this->get_position()->y = new_y;
    }
}
