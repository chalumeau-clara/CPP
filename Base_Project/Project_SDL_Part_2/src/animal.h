//
// Created by clara on 15/12/22.
//

#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H

#include "interact.h"
#define CLOSE_WOLF 100
#define OFFSPRING_MIN_TIME 200
#define TIME_TO_DIE 10
#define MIN_DIST_TO_WOLF 400

class Animal: {
    public:
        Animal();
        virtual ~Animal();

        virtual void move() = 0;

        uint64_t random_move(uint64_t move);
private:
    bool speed_boost = false; // If false no speed boost else speed boost
    bool offspring = false; // If false no offspring
};


#endif //CPP_ANIMAL_H
