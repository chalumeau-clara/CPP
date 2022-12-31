//
// Created by clara on 15/12/22.
//

#ifndef CPP_SHEPHERD_H
#define CPP_SHEPHERD_H

#include "playable_character.h"

class shepherd : public playable_character {

    public:
        shepherd(const std::string &file_path, SDL_Surface *window_surface_ptr);

        ~shepherd()= default;
        void move() override;

};


#endif //CPP_SHEPHERD_H
