//
// Created by clara on 25/12/22.
//

#ifndef PROJECT_SDL2_RENDER_H
#define PROJECT_SDL2_RENDER_H

#include "application.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_surface.h>
#include <string>


class render{
public:
        render();
        ~render() = default;
        static SDL_Surface *load_surface_for(const std::string &path,
                                  SDL_Surface *window_surface_ptr);

};

#endif //PROJECT_SDL2_RENDER_H
