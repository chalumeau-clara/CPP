#ifndef SHEPHERD_DOG_H
#define SHEPHERD_DOG_H

#include "Animal.h"
#include "Shepherd.h"
#include <memory>

class Shepherd_dog : public Animal {
public:

    Shepherd_dog(SDL_Surface* window_surface_ptr, std::shared_ptr<Shepherd> shepherd):
    Animal(shepherd_dog_texture_path, window_surface_ptr){
        set_property("shepherd_dog");
        shepherd_ = shepherd;
        set_position(shepherd_->get_position()->x + 5, shepherd_->get_position()->y + 5);

        setVelocityX(2);
        setVelocityY(2);

    };
    virtual ~Shepherd_dog(){};



    // Fonction pour déplacement en suivant le berger
    virtual void move() override;
    virtual void interact(Interacting_object &other_object) override;

private:
    std::shared_ptr<Shepherd> shepherd_ = nullptr;
    int radius = 100;
    double angle = 0;
    double speed = 0.1;
};

#endif
