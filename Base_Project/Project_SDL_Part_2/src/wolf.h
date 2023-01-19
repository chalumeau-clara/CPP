//
// Created by clara on 15/12/22.
//

#ifndef CPP_WOLF_H
#define CPP_WOLF_H

#include "animal.h"

class wolf : public animal
{
public:
    wolf(const std::string &file_path, SDL_Surface *window_surface_ptr);

    ~wolf()= default;
    void find_nearest_sheep();
    void move() override;

};


#endif //CPP_WOLF_H
