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
    }
} // namespace

animal::animal(const std::string &file_path, SDL_Surface *window_surface_ptr)
    : window_surface_ptr_(window_surface_ptr)
{
    image_ptr_ = load_surface_for(file_path, window_surface_ptr);

    // Set random position of the animal
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, frame_width - 1);
    x_pos = dis(gen);
    std::uniform_int_distribution<> dis2(0, frame_height - 1);
    y_pos = dis2(gen);
}

animal::~animal(){};

void animal::draw()
{
    SDL_Rect rect;
    rect.x = x_pos;
    rect.y = y_pos;
    rect.w = image_ptr_->w;
    rect.h = image_ptr_->h;
    SDL_BlitSurface(image_ptr_, nullptr, window_surface_ptr_, &rect);
}

sheep::sheep(const std::string &file_path, SDL_Surface *window_surface_ptr)
    : animal(file_path, window_surface_ptr){};

sheep::~sheep(){};

void sheep::move()
{
    // todo: Implement the move function for the sheep
}

wolf::wolf(const std::string &file_path, SDL_Surface *window_surface_ptr)
    : animal(file_path, window_surface_ptr){};

wolf::~wolf(){};

void wolf::move()
{
    // todo: Implement the move function for the wolf
}

ground::ground(SDL_Surface *window_surface_ptr)
    : window_surface_ptr_(window_surface_ptr)
{}

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
    SDL_FillRect(window_surface_ptr_, nullptr,
                 SDL_MapRGB(window_surface_ptr_->format, 0xFF, 0xFF, 0xFF));

    // Draw all animals
    for (auto &animal_ptr : animals_)
        animal_ptr->draw();
}

application::application(unsigned int n_sheep, unsigned int n_wolf)
{
    // Create the window
    window_ptr_ = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, frame_width,
                                   frame_height, SDL_WINDOW_SHOWN);
    if (window_ptr_ == nullptr)
        throw std::runtime_error("application(): Window could not be created! "
                                 "SDL_Error: "
                                 + std::string(SDL_GetError()));

    // Get window surface
    window_surface_ptr_ = SDL_GetWindowSurface(window_ptr_);

    // Create the ground
    ground ground(window_surface_ptr_);

    // Create the animals
    for (unsigned int i = 0; i < n_sheep; ++i)
        ground.add_animal(
            std::make_unique<sheep>("media/sheep.png", window_surface_ptr_));
    for (unsigned int i = 0; i < n_wolf; ++i)
        ground.add_animal(
            std::make_unique<wolf>("media/wolf.png", window_surface_ptr_));

    // Main loop
    bool quit = false;
    SDL_Event e;
    while (!quit)
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

        // Update the ground
        ground.update();

        // Update the surface
        SDL_UpdateWindowSurface(window_ptr_);
    }

    // Destroy window
    SDL_DestroyWindow(window_ptr_);
    window_ptr_ = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

application::~application()
{
    // Destroy window
    SDL_DestroyWindow(window_ptr_);
    window_ptr_ = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int application::loop(unsigned period)
{
    // Execute the main loop during "period" seconds
    const auto start = std::chrono::system_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(
               std::chrono::system_clock::now() - start)
               .count()
           < period)
    {
        // Update the ground
        ground_.update();

        // Update the surface
        SDL_UpdateWindowSurface(window_ptr_);
    }
    return 0;
}
