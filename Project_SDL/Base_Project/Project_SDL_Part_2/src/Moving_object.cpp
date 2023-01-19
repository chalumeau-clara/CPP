#include "Moving_object.h"

// Moving_object::Moving_object(std::unique_ptr<SDL_Surface> texture, int x, int y, int velocity_x, int velocity_y)
//     : Rendered_object(std::move(texture), x, y), velocity_x_(velocity_x), velocity_y_(velocity_y) {}

// Moving_object::Moving_object(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y) : texture_(std::move(texture)), x_(x), y_(y) {
//     velocity_x_ = 0;
//     velocity_y_ = 0;
// }

// Moving_object::~Moving_object() {}
/*
Moving_object::Moving_object(SDL_Surface *texture, int velocity_x, int velocity_y) :
    Rendered_object(texture), velocity_x_(velocity_x), velocity_y_(velocity_y) {
}

int Moving_object::getVelocityX() const {
    return velocity_x_;
}

int Moving_object::getVelocityY() const {
    return velocity_y_;
}

void Moving_object::setVelocityX(int velocityX) {
    velocity_x_ = velocityX;
}

void Moving_object::setVelocityY(int velocityY) {
    velocity_y_ = velocityY;
}

void Moving_object::step() {
    setX(getX() + velocity_x_);
    setY(getY() + velocity_y_);
}*/


