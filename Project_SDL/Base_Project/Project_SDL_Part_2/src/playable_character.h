//
// Created by clara on 15/12/22.
//

#ifndef CPP_PLAYABLE_CHARACTER_H
#define CPP_PLAYABLE_CHARACTER_H
#include "interact.h"

class playable_character : public interact {

public:
    playable_character();
    virtual ~playable_character();
    virtual void move() = 0;

};


#endif //CPP_PLAYABLE_CHARACTER_H
