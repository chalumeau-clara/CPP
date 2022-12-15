//
// Created by clara on 15/12/22.
//

#ifndef CPP_APPLICATION_H
#define CPP_APPLICATION_H
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
constexpr unsigned frame_width = 1400; // Width of window in pixel
constexpr unsigned frame_height = 900; // Height of window in pixel
// Minimal distance of animals to the border
// of the screen
constexpr unsigned frame_boundary = 100;

// Helper function to initialize SDL
void init();

class application {

protected:
    // The following are OWNING ptrs
    SDL_Window *window_ptr_;
    SDL_Surface *window_surface_ptr_;
    SDL_Event window_event_;

    // Other attributes here, for example an instance of ground
    ground ground_ = ground(window_surface_ptr_);

public:
    application(unsigned int n_sheep, unsigned int n_wolf); // Ctor
    ~application(); // dtor

    int loop(unsigned period); // main loop of the application.
    // this ensures that the screen is updated
    // at the correct rate.
    // See SDL_GetTicks() and SDL_Delay() to enforce
    // a duration the application should terminate
    // after 'period' seconds
};


#endif //CPP_APPLICATION_H
