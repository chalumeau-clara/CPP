//
// Created by clara on 15/12/22.
//

#ifndef CPP_MOVING_OBJECT_H
#define CPP_MOVING_OBJECT_H


class moving_object {
    protected:

        // Constructor
        moving_object();

        // Destructor
        virtual ~moving_object();

        // Velocity attributes
        uint64 velocity_x = 0;
        uint64 velocity_y = 0;

        // Move function
        virtual void move() = 0;
        void step();
};


#endif //CPP_MOVING_OBJECT_H
