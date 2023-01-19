//
// Created by clara on 15/12/22.
//

#include "sheep.h"

void sheep::move()
{
    // define the distance between the wolf and the sheep
    int wolf_distance_x = wolf_x - x;
    int wolf_distance_y = wolf_y - y;
    int wolf_distance = sqrt(pow(wolf_distance_x, 2) + pow(wolf_distance_y, 2));

    // random move around the map except when getting too close to a wolf
    if (wolf_distance > 10)
    {
        // move randomly
        random_move(10);
    }
    else
    {
        // move away from the wolf
        if (wolf_distance > 0)
        {
            // move away from the wolf
            if (wolf_distance_x > 0)
            {
                // move left
                x -= 10;
            }
            else
            {
                // move right
                x += 10;
            }
            if (wolf_distance_y > 0)
            {
                // move up
                y -= 10;
            }
            else
            {
                // move down
                y += 10;
            }
        }
    }
    
}