#ifndef RENDERED_OBJECT_H
#define RENDERED_OBJECT_H

#include "Interacting_object.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2/SDL.h>

// Path to textures
const std::string sheep_texture_path = "../media/sheep.png";
const std::string wolf_texture_path = "../media/wolf.png";
const std::string shepherd_dog_texture_path = "../media/shepherd_dog.png";
const std::string shepherd_texture_path = "../media/shepherd.png";

class Rendered_object : public Interacting_object {
public:
    Rendered_object(const std::string &file_path, SDL_Surface *window_surface_ptr);
    // Rendered_object(const std::string &file_path, SDL_Surface *window_surface_ptr, int x_object, int y_object);
    ~Rendered_object(){
        SDL_FreeSurface(image_ptr_);
    };
    static SDL_Surface *load_surface_for(const std::string &path,
                                         SDL_Surface *window_surface_ptr);
    void draw(int x_pos, int y_pos);


protected:
    SDL_Surface *window_surface_ptr_; // ptr to the surface on which we want the
    // animal to be drawn, also non-owning
    SDL_Surface *image_ptr_; // The texture of the sheep (the loaded image), use
    // load_surface_for
    

};

#endif // RENDERED_OBJECT_H