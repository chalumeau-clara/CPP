#include "Wolf.h"
#include "Application.h"

void Wolf::interact(Interacting_object &other_object){
    if (other_object.find_property("sheep") && !other_object.find_property("dead")){

        // cast other object to sheep
        Sheep& sheep = dynamic_cast<Sheep&>(other_object);

        if (nearest_sheep_ == nullptr)
        {
            nearest_sheep_ = &sheep;
        }
        else
        {
            // check if the sheep is closer than the current nearest sheep with formula distance = √((x2 - x1)² + (y2 - y1)²)
            int new_distance = sqrt(pow(other_object.get_position()->x - this->get_position()->x, 2) + pow(other_object.get_position()->y - this->get_position()->y, 2));
            int current_distance = sqrt(pow(nearest_sheep_->get_position()->x - this->get_position()->x, 2) + pow(nearest_sheep_->get_position()->y - this->get_position()->y, 2));

            if (current_distance <= new_distance)
            {
                // check if current sheep is eatable
                if (current_distance <= eat_distance)
                {
                    nearest_sheep_->set_property("dead");
                    nearest_sheep_ = nullptr;
                }
            }
            else
            {
                // update nearest sheep
                nearest_sheep_ = &sheep;
            }

        }
    }
}

void Wolf::move()
{
    // if nearest sheep is not null, move towards it
    if (nearest_sheep_!= nullptr)
    {
        if (get_position()->x < nearest_sheep_->get_position()->x)
        {
            get_position()->x+= getVelocityX();
        }
        else if (get_position()->x > nearest_sheep_->get_position()->x)
        {
            get_position()->x-= getVelocityX();
        }
        if (get_position()->y < nearest_sheep_->get_position()->y)
        {
            get_position()->y+= getVelocityY();
        }
        else if (get_position()->y > nearest_sheep_->get_position()->y)
        {
            get_position()->y-= getVelocityY();
        }
    }
    else
    {
        // if nearest sheep is null, move randomly
        int x_move = rand() % 3;
        int y_move = rand() % 3;

        switch (x_move) {
            case 0:
                get_position()->x-= getVelocityX();
                break;
            case 2:
                get_position()->x+= getVelocityX();
                break;
        }
        switch (y_move) {
            case 0:
                get_position()->y-= getVelocityY();
                break;
            case 2:
                get_position()->y+= getVelocityY();
                break;
        }

        // Make sure the wolf stays in the frame
        if (get_position()->x + image_ptr_->w > frame_width - frame_boundary) {
            get_position()->x = frame_width - image_ptr_->w - frame_boundary;
            x_move = 0;
        }

        if (get_position()->x < frame_boundary){
            get_position()->x = frame_boundary;
            x_move = 2;
        }

        if (get_position()->y + image_ptr_->h > frame_height - frame_boundary) {
            get_position()->y = frame_height - image_ptr_->h - frame_boundary;
            y_move = 0;
        }

        if (get_position()->y < frame_boundary){
            get_position()->y = frame_boundary;
            y_move = 2;
        }

    }


    //         switch (x_move) {
    //         case 0:
    //             get_position()->x--;
    //             break;
    //         case 2:
    //             get_position()->x++;
    //             break;
    //     }
    //     switch (y_move) {
    //         case 0:
    //             get_position()->y--;
    //             break;
    //         case 2:
    //             get_position()->y++;
    //             break;
    //     }

    // // Make sure the wolf stays in the frame
    // if (get_position()->x + image_ptr_->w > frame_width - frame_boundary) {
    //     get_position()->x = frame_width - image_ptr_->w - frame_boundary;
    //     x_move = 0;
    // }

    // if (get_position()->x < frame_boundary){
    //     get_position()->x = frame_boundary;
    //     x_move = 2;
    // }

    // if (get_position()->y + image_ptr_->h > frame_height - frame_boundary) {
    //     get_position()->y = frame_height - image_ptr_->h - frame_boundary;
    //     y_move = 0;
    // }

    // if (get_position()->y < frame_boundary){
    //     get_position()->y = frame_boundary;
    //     y_move = 2;
    // }
}










            // int distance_x = std::abs(get_position()->x - nearest_sheep_position_->x);
            // int distance_y = std::abs(get_position()->y - nearest_sheep_position_->y);

            // int new_distance_x = std::abs(get_position()->x - other_object.get_position()->x);
            // int new_distance_y = std::abs(get_position()->y - other_object.get_position()->y);

            // if (new_distance_x < distance_x && new_distance_y < distance_y)
            // {
            //     nearest_sheep_position_ = other_object.get_position();
            // }

            // if (distance_x < eat_distance && distance_y < eat_distance)
            // {
            //     other_object.set_property("dead");
            //     nearest_sheep_position_ = nullptr;
            // }