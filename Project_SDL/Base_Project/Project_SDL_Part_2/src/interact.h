//
// Created by clara on 15/12/22.
//

#ifndef CPP_INTERACT_H
#define CPP_INTERACT_H

#include <cstdint>
#include "animal.h"

enum DIRECTION {
    RIGHT,
    LEFT,
    UP,
    DOWN,
    STRAIGHT
};

struct informations {
    uint64_t x_pos;
    uint64_t y_pos;
    DIRECTION x_direction;
    DIRECTION y_direction;
    uint64_t speed;
    bool alive; // If true alive else die
    GENDER sex;
    bool prey; // If true prey else hunter
    animal animal; // Which sort of animal
};

class interact {
public:
    interact();
    ~interact() = default;
    std::list<std::shared_ptr<animal>> character;
    void set_nb_sheep(uint64_t nb);
    void set_nb_wolf(uint64_t nb);
    void set_nb_shefered_dof(uint64_t nb);
private:
    uint64_t nb_sheep;
    uint64_t nb_wolf;
};


#endif //CPP_INTERACT_H
