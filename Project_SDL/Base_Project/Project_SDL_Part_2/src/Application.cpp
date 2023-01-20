#include "Application.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Shepherd_dog.h"
#include "Shepherd.h"


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

uint64_t my_random_width()
{
    // Set random position of the animal
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, frame_width - 1);
    return dis(gen);
}
uint64_t my_random_heigth()
{
    // Set random position of the animal
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, frame_height - 1);
    return dis(gen);
}

Application::Application(unsigned int n_sheep, unsigned int n_wolf) {
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

    // SDL_Renderer *renderer = SDL_CreateRenderer(window_ptr_, -1, 0);
    // SDL_SetRenderDrawColor(renderer, 255, 192, 203, 255);
    // SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
    // SDL_Delay(2000);
    ground_ = Ground(window_surface_ptr_);
    ground_.set_nb_sheep(n_sheep);
    ground_.set_nb_wolf(n_wolf);
    // Create the animals
    for (unsigned int i = 0; i < n_sheep; ++i)
        ground_.add_character(
                std::make_unique<Sheep>(window_surface_ptr_, my_random_width(), my_random_heigth()));
    for (unsigned int i = 0; i < n_wolf; ++i)
        ground_.add_character(
                std::make_unique<Wolf>(window_surface_ptr_, my_random_width(), my_random_heigth()));

    ground_.add_character(std::make_unique<Shepherd>(window_surface_ptr_, window_event_, frame_width / 2 - 170, frame_height / 2 - 170));

    ground_.add_character(
            std::make_unique<Shepherd_dog>(window_surface_ptr_, frame_width / 2 - 170 - distance_shepeherd_dog - 340 , frame_height / 2 - 170 - distance_shepeherd_dog - 340));
    ground_.add_character(
            std::make_unique<Shepherd_dog>(window_surface_ptr_, frame_width / 2 - 170 + distance_shepeherd_dog + 340, frame_height / 2 - 170 + distance_shepeherd_dog + 340));
    ground_.add_character(
            std::make_unique<Shepherd_dog>(window_surface_ptr_, frame_width / 2 - 170- distance_shepeherd_dog - 340 , frame_height / 2 - 170 + distance_shepeherd_dog + 340 ));
    ground_.add_character(
            std::make_unique<Shepherd_dog>(window_surface_ptr_, frame_width / 2 - 170+ distance_shepeherd_dog + 340, frame_height / 2 - 170 - distance_shepeherd_dog - 340 ));


}

Application::~Application()
{
    SDL_FreeSurface(window_surface_ptr_);
    // Destroy window
    SDL_DestroyWindow(window_ptr_);
    window_ptr_ = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


int Application::loop(unsigned period)
{
    // Main loop
    bool quit = false;
    auto start = SDL_GetTicks();
    // auto random = 1;
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
        //if ((random++) % 40 == 0)
          //  ground_.add_random();
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
