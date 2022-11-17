// SDL_Test.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

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

class animal
{
protected:
  SDL_Surface *window_surface_ptr_; // ptr to the surface on which we want the
                                    // animal to be drawn, also non-owning
  SDL_Surface *image_ptr_; // The texture of the sheep (the loaded image), use
                           // load_surface_for
  uint64_t x_pos = 0;      // x position of the Animal
  uint64_t y_pos = 0;      // y position of the Animal
  uint64_t x_move = 3;     // 0 left; 1 straight; 2 right
  uint64_t y_move = 3;     // 0 down; 1 straight; 2 upp

public:
    animal(const std::string &file_path, SDL_Surface *window_surface_ptr);
    // todo: The constructor has to load the sdl_surface that corresponds to the
    // texture
    virtual ~animal(); // todo: Use the destructor to release memory and "clean up
                 // behind you"

    void
    draw(); // todo: Draw the animal on the screen <-> window_surface_ptr.
              // Note that this function is not virtual, it does not depend
              // on the static type of the instance

    virtual void move() = 0; // todo: Animals move around, but in a different
                               // fashion depending on which type of animal
   uint64_t random_move(uint64_t move);
};

class sheep : public animal
{
public:
    // Constructor basic
    sheep(const std::string &file_path, SDL_Surface *window_surface_ptr)
        : animal(file_path, window_surface_ptr){};

    // Destructor
    ~sheep()= default;
    void move() override;
};

class wolf : public animal
{
public:
    wolf(const std::string &file_path, SDL_Surface *window_surface_ptr)
        : animal(file_path, window_surface_ptr){};

    ~wolf()= default;
    void move() override;

};

// The "ground" on which all the animals live (like the std::vector
// in the zoo example).
class ground
{
protected:
  // Attention, NON-OWNING ptr, again to the screen
  SDL_Surface *window_surface_ptr_;

  // Some attribute to store all the wolves and sheep
  // here
  std::list<std::shared_ptr<animal>> animals_;
  uint64_t nb_sheep = 0;
  uint64_t nb_wolf = 0;

public:

    ground(SDL_Surface *window_surface_ptr);

    ~ground()= default; // todo: Dtor, again for clean up (if necessary)
    void add_animal(std::unique_ptr<animal> animal_ptr);
    void update(); // todo: "refresh the screen": Move animals and draw them
    void set_nb_sheep(uint64_t nb);
    void set_nb_wolf(uint64_t nb);
    void add_random();
    // Possibly other methods, depends on your implementation
};

// The application class, which is in charge of generating the window
class application
{
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
