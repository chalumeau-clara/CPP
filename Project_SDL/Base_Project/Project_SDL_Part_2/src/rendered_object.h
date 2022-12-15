//
// Created by clara on 15/12/22.
//

#ifndef CPP_RENDERED_OBJECT_H
#define CPP_RENDERED_OBJECT_H


class rendered_object {
protected:
    rendered_object();

    SDL_Surface *window_surface_ptr_; // ptr to the surface on which we want the
    SDL_Surface *image_ptr_; // The texture of the loaded image

    uint64_t x_pos = 0;  // x position
    uint64_t y_pos = 0;  // y position

public:
    void draw(); // Draw the character
};


#endif //CPP_RENDERED_OBJECT_H
