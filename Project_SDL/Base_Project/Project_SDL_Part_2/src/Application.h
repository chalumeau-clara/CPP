#ifndef APPLICATION_H
#define APPLICATION_H

#include "Ground.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <vector>
#include <random>
#include <list>

// Defintions
constexpr double frame_rate = 30.0; // refresh rate
constexpr double frame_time = 1. / frame_rate;

constexpr unsigned distance_shepeherd_dog = 50;
// Minimal distance of animals to the border
// of the screen
// Helper function to initialize SDL
void init();

class Application {
protected:
    // The following are OWNING ptrs
    SDL_Window *window_ptr_;
    SDL_Surface *window_surface_ptr_ = nullptr;
    SDL_Event window_event_;

    // Other attributes here, for example an instance of ground
    Ground ground_ = Ground(window_surface_ptr_);

public:
    Application(unsigned int n_sheep, unsigned int n_wolf); // Ctor
    ~Application(); // dtor

    int loop(unsigned period);
};

#endif // APPLICATION_H


