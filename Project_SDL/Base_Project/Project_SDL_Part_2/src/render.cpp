//
// Created by clara on 25/12/22.
//

#include <stdexcept>
#include "render.h"

SDL_Surface *render::load_surface_for(const std::string &path,
                              SDL_Surface *window_surface_ptr)
{
    // Helper function to load a png for a specific surface
    // See SDL_ConvertSurface
    auto loaded_surface = IMG_Load(path.c_str());
    if (!loaded_surface)
        throw std::runtime_error(
                "load_surface_for(): Unable to load image " + path +
                "! SDL_image Error: " + std::string(IMG_GetError()));

    auto convert = SDL_ConvertSurface(loaded_surface, window_surface_ptr->format,0);
    SDL_FreeSurface(loaded_surface);
    return convert;
    //return loaded_surface;
}

render::render(const std::string &file_path, SDL_Surface *window_surface_ptr)
{
    window_surface_ptr_ = window_surface_ptr;
    image_ptr_ = load_surface_for(file_path, window_surface_ptr_);
}

void render::draw(int x_pos, int y_pos)
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