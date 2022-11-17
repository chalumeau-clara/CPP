// SDL_Test.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>

void init()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("init():" + std::string(SDL_GetError()));

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        throw std::runtime_error("init(): SDL_image could not initialize! "
                                 "SDL_image Error: "
                                 + std::string(IMG_GetError()));
}

namespace
{
    // Defining a namespace without a name -> Anonymous workspace
    // Its purpose is to indicate to the compiler that everything
    // inside of it is UNIQUELY used within this source file.

    SDL_Surface *load_surface_for(const std::string &path,
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
} // namespace

animal::~animal() {
    SDL_FreeSurface(image_ptr_);
}

uint64_t animal::random_move(uint64_t move) {
    std::random_device rd3;
    std::mt19937 gen3(rd3());
    std::uniform_int_distribution<> dis3(0, 2);
    auto next = dis3(gen3);
    while (next == move)
        next = dis3(gen3);
    return next;
}

animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr)
{
    window_surface_ptr_ = window_surface_ptr;
    image_ptr_ = load_surface_for(file_path, window_surface_ptr_);

    // Set random position of the animal
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, frame_width - 1);
    x_pos = dis(gen);
    std::uniform_int_distribution<> dis2(0, frame_height - 1);
    y_pos = dis2(gen);

    //Random move
    x_move = random_move(x_move);
    y_move = random_move(x_move);

}

// animal::~animal(){};

void animal::draw()
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

//sheep::sheep(const std::string &file_path, SDL_Surface *window_surface_ptr)
//    : animal(file_path, window_surface_ptr){};

// sheep::~sheep(){};

void sheep::move()
{
  switch (x_move) {
  case 0:
    x_pos--;
    break;
  case 2:
    x_pos++;
    break;
  }
    switch (y_move) {
        case 0:
            y_pos--;
            break;
        case 2:
            y_pos++;
            break;
    }

  // Make sure the sheep stays in the frame
  if (x_pos + image_ptr_->w > frame_width - frame_boundary) {
      x_pos = frame_width - image_ptr_->w - frame_boundary;
      x_move = 0;
  }

  if (x_pos < frame_boundary){
      x_pos = frame_boundary;
      x_move = 2;
  }

  if (y_pos + image_ptr_->h > frame_height - frame_boundary) {
      y_pos = frame_height - image_ptr_->h - frame_boundary;
      y_move = 0;
  }

  if (y_pos < frame_boundary){
      y_pos = frame_boundary;
      y_move = 2;
  }

}

//wolf::wolf(const std::string &file_path, SDL_Surface *window_surface_ptr)
//    : animal(file_path, window_surface_ptr){};

//wolf::~wolf(){};

void wolf::move()
{
    switch (x_move) {
        case 0:
            x_pos--;
            break;
        case 2:
            x_pos++;
            break;
    }
    switch (y_move) {
        case 0:
            y_pos--;
            break;
        case 2:
            y_pos++;
            break;
    }

    // Make sure the sheep stays in the frame
    if (x_pos + image_ptr_->w > frame_width - frame_boundary) {
        x_pos = frame_width - image_ptr_->w - frame_boundary;
        x_move = 0;
    }

    if (x_pos < frame_boundary){
        x_pos = frame_boundary;
        x_move = 2;
    }

    if (y_pos + image_ptr_->h > frame_height - frame_boundary) {
        y_pos = frame_height - image_ptr_->h - frame_boundary;
        y_move = 0;
    }

    if (y_pos < frame_boundary){
        y_pos = frame_boundary;
        y_move = 2;
    }
}

ground::ground(SDL_Surface *window_surface_ptr) {
    window_surface_ptr_ = window_surface_ptr;
}

void ground::add_animal(std::unique_ptr<animal> animal_ptr)
{
    animals_.push_back(std::move(animal_ptr));
}

void ground::update()
{
    // refresh the screen": Move animals and draw them
    for (auto &animal_ptr : animals_)
        animal_ptr->move();

    // Clear the screen
    SDL_FillRect(window_surface_ptr_, nullptr ,SDL_MapRGB(window_surface_ptr_->format, 0xFF, 0xFF, 0xFF));
    // Draw all animals
    for (auto &animal_ptr : animals_)
        animal_ptr->draw();
}
void ground::set_nb_sheep(uint64_t nb) {
    nb_sheep = nb;
}

void ground::set_nb_wolf(uint64_t nb){
    nb_wolf = nb;
}

void ground::add_random(){
    std::random_device rd3;
    std::mt19937 gen3(rd3());

    // Delete random number of animals
    std::uniform_int_distribution<> dis4(0, nb_sheep);
    std::uniform_int_distribution<> dis5(0, nb_wolf);
    auto deletesheep = dis4(gen3);
    auto deletewolf = dis5(gen3);
    for (unsigned int i = 0; i < deletesheep; ++i)
        animals_.pop_front();
    for (unsigned int i = 0; i < deletewolf; ++i)
        animals_.pop_back();
    nb_sheep -= deletesheep;
    nb_wolf -= deletewolf;

    // Add random nb of animals
    std::uniform_int_distribution<> dis3(0, 2);
    auto nextsheep = dis3(gen3);
    auto nextwolf = dis3(gen3);
    nb_sheep += nextsheep;
    nb_wolf += nextwolf;
    for (unsigned int i = 0; i < nextsheep; ++i)
        animals_.push_front(std::make_unique<sheep>("media/sheep.png", window_surface_ptr_));
    for (unsigned int i = 0; i < nextwolf; ++i)
        add_animal(std::make_unique<wolf>("media/wolf.png", window_surface_ptr_));
}

application::application(unsigned int n_sheep, unsigned int n_wolf) {
    // Create the window
    window_ptr_ = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, frame_width,
                                   frame_height, SDL_WINDOW_SHOWN);
    if (!window_ptr_)
        throw std::runtime_error("application(): Window could not be created! "
                                 "SDL_Error: "
                                 + std::string(SDL_GetError()));

    // Get window surface
    window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);
    if (!window_surface_ptr_)
        throw std::runtime_error(std::string(SDL_GetError()));

    /*SDL_Renderer *renderer = SDL_CreateRenderer(window_ptr_, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 192, 203, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);*/
    ground_ = ground(window_surface_ptr_);
    ground_.set_nb_sheep(n_sheep);
    ground_.set_nb_wolf(n_wolf);
    // Create the animals
    for (unsigned int i = 0; i < n_sheep; ++i)
      ground_.add_animal(
          std::make_unique<sheep>("media/sheep.png", window_surface_ptr_));
    for (unsigned int i = 0; i < n_wolf; ++i)
      ground_.add_animal(
          std::make_unique<wolf>("media/wolf.png", window_surface_ptr_));
}

application::~application()
{
    SDL_FreeSurface(window_surface_ptr_);
    // Destroy window
    SDL_DestroyWindow(window_ptr_);
    window_ptr_ = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int application::loop(unsigned period)
{
    // Main loop
    bool quit = false;
    auto start = SDL_GetTicks();
    auto random = 1;
    SDL_Event e;
    while (!quit&& (SDL_GetTicks() - start < period * 1000))
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        SDL_Delay(frame_rate);
        if ((random++) % 40 == 0)
            ground_.add_random();
        // Update the ground
        ground_.update();

        // Update the surface
        SDL_UpdateWindowSurface(window_ptr_);
    }

    // Destroy window
    SDL_DestroyWindow(window_ptr_);
    window_ptr_ = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    return 0;
}
