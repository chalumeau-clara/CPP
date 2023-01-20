#include "Sheep.h"
#include "Application.h"

// Sheep::Sheep(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y, int velocity_x, int velocity_y)
//     : Animal(std::move(texture), x, y, velocity_x, velocity_y) {}

// Sheep::~Sheep() {}

void Sheep::interact(Interacting_object &other_object){
    
    if (other_object.find_property("sheep")){
    }
}

void Sheep::move()
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
