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

