#include "Shepherd_dog.h"

//Shepherd_dog(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y, int velocity_x, int velocity_y);
// virtual ~Shepherd_dog();

void Shepherd_dog::interact(Interacting_object &other_object){
    if (other_object.find_property("sheep")){
    }
}

void Shepherd_dog::move() {
    // Déplacement en suivant le berger
    // ...
}
