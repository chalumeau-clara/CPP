#ifndef PLAYABLE_CHARACTER_H
#define PLAYABLE_CHARACTER_H

#include "Moving_object.h"

class Playable_character : public Moving_object {
public:
    Playable_character(const std::string &file_path, SDL_Surface* window_surface_ptr, SDL_Event window_event) :
            Moving_object(file_path, window_surface_ptr) {
        window_event_ = window_event;
    }

    // Fonction virtuelle pour déplacement
    virtual void move() override = 0;
private:
    // The keyboad event
    SDL_Event window_event_;
protected:
    const uint64_t walk = 6;
};

#endif // PLAYABLE_CHARACTER_H