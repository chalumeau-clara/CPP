//
// Created by clara on 15/12/22.
//

#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H

enum GENDER {
    MALE,
    FEMALE
};

class animal {

    public:
        animal();
        virtual ~animal();


        uint64_t random_move(uint64_t move);
};


#endif //CPP_ANIMAL_H
