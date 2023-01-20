#include "Sheep.h"
#include "Application.h"

// Sheep::Sheep(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y, int velocity_x, int velocity_y)
//     : Animal(std::move(texture), x, y, velocity_x, velocity_y) {}

// Sheep::~Sheep() {}


void Sheep::move()
{
    switch (x_move) {
        case 0:
            x_pos--;
            break;
        case 2:
            x_pos++;
            break;
    }
    switch (y_move) {
        case 0:
            y_pos--;
            break;
        case 2:
            y_pos++;
            break;
    }

    // Make sure the sheep stays in the frame
    if (x_pos + image_ptr_->w > frame_width - frame_boundary) {
        x_pos = frame_width - image_ptr_->w - frame_boundary;
        x_move = 0;
    }

    if (x_pos < frame_boundary){
        x_pos = frame_boundary;
        x_move = 2;
    }

    if (y_pos + image_ptr_->h > frame_height - frame_boundary) {
        y_pos = frame_height - image_ptr_->h - frame_boundary;
        y_move = 0;
    }

    if (y_pos < frame_boundary){
        y_pos = frame_boundary;
        y_move = 2;
    }

}
