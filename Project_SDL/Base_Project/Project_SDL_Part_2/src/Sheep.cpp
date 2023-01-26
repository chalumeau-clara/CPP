#include "Sheep.h"
#include "Application.h"

// Sheep::Sheep(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y, int velocity_x, int velocity_y)
//     : Animal(std::move(texture), x, y, velocity_x, velocity_y) {}

// Sheep::~Sheep() {}

void Sheep::interact(Interacting_object &other_object){
    
    if (other_object.find_property("wolf") && !other_object.find_property("dead")){

        if (nearest_wolf_ == nullptr)
        {
            nearest_wolf_ = &other_object;
        }
        else
        {
            // check if the sheep is closer than the current nearest sheep with formula distance = √((x2 - x1)² + (y2 - y1)²)
            int new_distance = sqrt(pow(other_object.get_position()->x - this->get_position()->x, 2) + pow(other_object.get_position()->y - this->get_position()->y, 2));
            int current_distance = sqrt(pow(nearest_wolf_->get_position()->x - this->get_position()->x, 2) + pow(nearest_wolf_->get_position()->y - this->get_position()->y, 2));

            if (current_distance > new_distance)
            {
                // update nearest wolf
                nearest_wolf_ = &other_object;
            }

        }
    }
}

void Sheep::move()
{
    // if nearest wolf is not null, move away from it
    if (nearest_wolf_ != nullptr )
    {
        if (get_position()->x < nearest_wolf_->get_position()->x)
        {
            get_position()->x-= getVelocityX();
        }
        else if (get_position()->x > nearest_wolf_->get_position()->x)
        {
            get_position()->x+= getVelocityX();
        }
        if (get_position()->y < nearest_wolf_->get_position()->y)
        {
            get_position()->y-= getVelocityY();
        }
        else if (get_position()->y > nearest_wolf_->get_position()->y)
        {
            get_position()->y+= getVelocityY();
        }

        // Make sure the sheep stays in the frame and bounce back if it hits the boundary
        
        if (get_position()->x + image_ptr_->w > frame_width - frame_boundary) {
            get_position()->x = frame_width - image_ptr_->w - frame_boundary;
        }

        if (get_position()->x < frame_boundary){
            get_position()->x = frame_boundary;
        }

        if (get_position()->y + image_ptr_->h > frame_height - frame_boundary) {
            get_position()->y = frame_height - image_ptr_->h - frame_boundary;
        }

        if (get_position()->y < frame_boundary){
            get_position()->y = frame_boundary;
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
