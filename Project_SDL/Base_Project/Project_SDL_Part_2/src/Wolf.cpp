#include "Wolf.h"
#include "Application.h"

void Wolf::interact(Interacting_object &other_object){
    if (other_object.find_property("sheep")){

        if (nearest_sheep_position_ == nullptr)
        {
            nearest_sheep_position_ = other_object.get_position();
        }
        else
        {
            // calculate the distance between the wolf and the sheep, absolute value
            int distance = std::abs(get_position()->x - nearest_sheep_position_->x) + std::abs(get_position()->y - nearest_sheep_position_->y);
            int new_distance = std::abs(get_position()->x - other_object.get_position()->x) + std::abs(get_position()->y - other_object.get_position()->y);
            if (distance < eat_distance)
            {
                // eat the sheep
                other_object.set_property("dead");
                nearest_sheep_position_ = nullptr;
            }
            if (new_distance < distance)
            {
                nearest_sheep_position_ = other_object.get_position();
            }
        }
    }
}

void Wolf::move()
{
    // if nearest sheep is not null, move towards it
    if (nearest_sheep_position_ != nullptr)
    {
        if (nearest_sheep_position_->x > get_position()->x)
        {
            x_move = 2;
        }
        else if (nearest_sheep_position_->x < get_position()->x)
        {
            x_move = 0;
        }
        else
        {
            x_move = 1;
        }

        if (nearest_sheep_position_->y > get_position()->y)
        {
            y_move = 2;
        }
        else if (nearest_sheep_position_->y < get_position()->y)
        {
            y_move = 0;
        }
        else
        {
            y_move = 1;
        }
    }
    else
    {
        switch (x_move) {
        case 0:
            get_position()->x--;
            break;
        case 2:
            get_position()->x++;
            break;
    }
    switch (y_move) {
        case 0:
            get_position()->y--;
            break;
        case 2:
            get_position()->y++;
            break;
    }
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