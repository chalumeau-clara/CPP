//
// Created by clara on 15/12/22.
//

#ifndef CPP_SHEEP_H
#define CPP_SHEEP_H

#include "animal.h"

class sheep : public Animal
{
public:
    // Constructor basic
    sheep(const std::string &file_path, SDL_Surface *window_surface_ptr);


    // Destructor
    ~sheep()= default;
    void move() override;

protected:
};


#endif //CPP_SHEEP_H
