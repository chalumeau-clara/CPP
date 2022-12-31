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
        render() = default;
        render(const std::string &file_path, SDL_Surface *window_surface_ptr);
        ~render() = default;
        static SDL_Surface *load_surface_for(const std::string &path,
                                  SDL_Surface *window_surface_ptr);
        void draw(int x_pos, int y_pos);

protected:
        SDL_Surface *window_surface_ptr_; // ptr to the surface on which we want the
        // animal to be drawn, also non-owning
        SDL_Surface *image_ptr_; // The texture of the sheep (the loaded image), use
        // load_surface_for


        // Note that this function is not virtual, it does not depend
        // on the static type of the instance
};

#endif //PROJECT_SDL2_RENDER_H
