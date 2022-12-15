//
// Created by clara on 15/12/22.
//

#include "rendered_object.h"
void rendered_object::draw()
{
    SDL_Rect rectdest;
    rectdest.x = 0;
    rectdest.y = 0;
    rectdest.w = image_ptr_->w;
    rectdest.h = image_ptr_->h;

    SDL_Rect rect;
    rect.x = x_pos;
    rect.y = y_pos;
    rect.w = image_ptr_->w;
    rect.h = image_ptr_->h;
    if (SDL_BlitSurface(image_ptr_, NULL, window_surface_ptr_, &rect))
        throw std::runtime_error("Could not apply texture.");
}
