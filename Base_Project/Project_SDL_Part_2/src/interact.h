//
// Created by clara on 15/12/22.
//

#ifndef CPP_INTERACT_H
#define CPP_INTERACT_H
#include <SDL_surface.h>

#include <cstdint>
#include <string>
#include "render.h"
#include "application.h"

#define DIST_SHEPHERDS_DOG 30


enum GENDER {
    MALE,
    FEMALE
};
enum DIRECTION {
    RIGHT,
    LEFT,
    UP,
    DOWN,
    STRAIGHT
};

class Interact {
public:
    Interact(const std::string &file_path, SDL_Surface *window_surface_ptr);
    virtual ~Interact() = default;
    Render render_ = Render();
    virtual void move() = 0;
    int get_x_pos();
    int get_y_pos();
private:
    uint64_t x_pos;
    uint64_t y_pos;
    DIRECTION x_direction;
    DIRECTION y_direction;
    uint64_t speed;
    bool alive; // If true alive else die
    GENDER sex;
    bool prey; // If true prey else hunter
};


#endif //CPP_INTERACT_H
