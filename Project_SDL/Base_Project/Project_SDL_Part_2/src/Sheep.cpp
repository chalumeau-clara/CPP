#include "Sheep.h"
#include "Application.h"

// Sheep::Sheep(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y, int velocity_x, int velocity_y)
//     : Animal(std::move(texture), x, y, velocity_x, velocity_y) {}

// Sheep::~Sheep() {}

void Sheep::interact(Interacting_object &other_object){
    
    if (other_object.find_property("wolf") && !other_object.find_property("dead")){

        if (nearest_wolf_position_ == nullptr)
        {
            nearest_wolf_position_ = other_object.get_position();
        }
        else
        {
            // calculate the distance between the sheep and the wolf, absolute value
            int distance_x = std::abs(get_position()->x - nearest_wolf_position_->x);
            int distance_y = std::abs(get_position()->y - nearest_wolf_position_->y);

            int new_distance_x = std::abs(get_position()->x - other_object.get_position()->x);
            int new_distance_y = std::abs(get_position()->y - other_object.get_position()->y);

            // compare the distance between the two wolves and update if the new wolf is closer
            if (new_distance_x < distance_x && new_distance_y < distance_y)
            {
                nearest_wolf_position_ = other_object.get_position();
            }
        }
    }
}

void Sheep::move()
{
    // if nearest wolf is not null, move away from it
    if (nearest_wolf_position_ != nullptr)
    {
        if (get_position()->x < nearest_wolf_position_->x)
        {
            get_position()->x-= getVelocityX();
        }
        else if (get_position()->x > nearest_wolf_position_->x)
        {
            get_position()->x+= getVelocityX();
        }
        if (get_position()->y < nearest_wolf_position_->y)
        {
            get_position()->y-= getVelocityY();
        }
        else if (get_position()->y > nearest_wolf_position_->y)
        {
            get_position()->y+= getVelocityY();
        }
    }
    else
    {
        // natural movement of the sheep
        int x_move = rand() % 3;
        int y_move = rand() % 3;

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

        // Make sure the sheep stays in the frame
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


    // switch (x_move) {
    //     case 0:
    //         get_position()->x--;
    //         break;
    //     case 2:
    //         get_position()->x++;
    //         break;
    // }
    // switch (y_move) {
    //     case 0:
    //         get_position()->y--;
    //         break;
    //     case 2:
    //         get_position()->y++;
    //         break;
    // }

    // // Make sure the sheep stays in the frame
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
