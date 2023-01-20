#ifndef PLAYABLE_CHARACTER_H
#define PLAYABLE_CHARACTER_H

#include "Moving_object.h"

class Playable_character : public Moving_object {
public:
    Playable_character(const std::string &file_path, SDL_Surface* window_surface_ptr, SDL_Event window_event, uint64_t x_position, uint64_t y_position) :
            Moving_object(file_path, window_surface_ptr,  x_position, y_position) {
        window_event_ = window_event;

    }

    // Fonction virtuelle pour déplacement
    virtual void move() = 0;

private:
    // The keyboad event
    SDL_Event window_event_;
protected:
    const uint64_t walk = 6;
};

#endif // PLAYABLE_CHARACTER_H