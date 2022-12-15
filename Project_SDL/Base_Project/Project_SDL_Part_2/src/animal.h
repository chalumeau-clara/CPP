//
// Created by clara on 15/12/22.
//

#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H


class animal {

    public:
        animal();
        virtual ~animal();

        void draw(); // todo: Draw the animal on the screen <-> window_surface_ptr.

        uint64_t random_move(uint64_t move);
};


#endif //CPP_ANIMAL_H
