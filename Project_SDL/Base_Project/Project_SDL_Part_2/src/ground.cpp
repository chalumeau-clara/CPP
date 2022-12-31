//
// Created by clara on 15/12/22.
//
#include "ground.h"

ground::ground(SDL_Surface *window_surface_ptr) {
    window_surface_ptr_ = window_surface_ptr;
}

void ground::add_character(std::unique_ptr<interact> character_ptr)
{
    character.push_back(std::move(character_ptr));
}

void ground::update()
{
    // refresh the screen": Move animals and draw them
    for (auto &animal_ptr : character)
        animal_ptr->move();

    // Clear the screen
    SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0xFF, 0xFF, 0xFF));
    // Draw all animals
    for (auto &animal_ptr : character)
        animal_ptr->render_.draw(animal_ptr->get_x_pos(), animal_ptr->get_y_pos());
}
void ground::set_nb_sheep(uint64_t nb) {
    nb_sheep = nb;
}

void ground::set_nb_wolf(uint64_t nb){
    nb_wolf = nb;
}
void ground::set_nb_shephered_dog(uint64_t nb){
    nb_shepherd_dog = nb;
}
void ground::add_random(){
    std::random_device rd3;
    std::mt19937 gen3(rd3());

    // Delete random number of animals
    std::uniform_int_distribution<> dis4(0, nb_sheep);
    std::uniform_int_distribution<> dis5(0, nb_wolf);
    auto deletesheep = dis4(gen3);
    auto deletewolf = dis5(gen3);
    for (unsigned int i = 0; i < deletesheep; ++i)
        character.pop_front();
    for (unsigned int i = 0; i < deletewolf; ++i)
        animals_.pop_back();
    nb_sheep -= deletesheep;
    nb_wolf -= deletewolf;

    // Add random nb of animals
    std::uniform_int_distribution<> dis3(0, 2);
    auto nextsheep = dis3(gen3);
    auto nextwolf = dis3(gen3);
    nb_sheep += nextsheep;
    nb_wolf += nextwolf;
    for (unsigned int i = 0; i < nextsheep; ++i)
        animals_.push_front(std::make_unique<sheep>("media/sheep.png", window_surface_ptr_));
    for (unsigned int i = 0; i < nextwolf; ++i)
        add_animal(std::make_unique<wolf>("media/wolf.png", window_surface_ptr_));
}
