#include <stdio.h>
#include <stdexcept>

// ATTENTION
// This file is only to check if
// SDL is correctly installed and linked against
// If everything works, an application is launched showing
// an image.
// However the application is "buggy" as it leaks memory
// and violates some other rules

#ifdef WINDOWSOS
  #include <SDL.h>
  #include <SDL_image.h>
#else
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
#endif


int main(int argc, char* argv[])
{
  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    throw std::runtime_error(std::string(SDL_GetError()));

  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("SDL_image could not initialize! "
                             "SDL_image Error: " + std::string(IMG_GetError()));


  auto window_ptr = SDL_CreateWindow("SDL2 Window",
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     194, 259,
                                     0);

  if (!window_ptr)
    throw std::runtime_error(std::string(SDL_GetError()));

  auto window_surface_ptr = SDL_GetWindowSurface(window_ptr);

  if (!window_surface_ptr)
    throw std::runtime_error(std::string(SDL_GetError()));

  auto surf = IMG_Load("img.png");
  if (!surf)
    throw std::runtime_error("Could not load image");
  auto rect = SDL_Rect{0,0,194,259};
  if (SDL_BlitSurface(surf, NULL, window_surface_ptr, &rect))
      throw std::runtime_error("Could not apply texture.");


  SDL_UpdateWindowSurface(window_ptr);

  auto start = SDL_GetTicks();

  SDL_Event e;
  bool quit = false;
  while (!quit && (SDL_GetTicks() - start < 10000)) {
      while (SDL_PollEvent(&e)) {
          if (e.type == SDL_QUIT) {
              quit = true;
              break;
          }
      }
  }

  return 0;
}