#include "Shepherd.h"

void Shepherd::move() {
    while(SDL_PollEvent(&window_events)) {
        switch(window_events.type) {
            // Key press detected
            case SDL_KEYDOWN:
                switch(window_events.key.keysym.sym){
                    case SDLK_z:
                    case SDLK_UP:
                        y_pos -= walk;
                        break;
                    case SDLK_s:
                    case SDLK_DOWN:
                        y_pos += walk;
                        break;
                    case SDLK_q:
                    case SDLK_LEFT:
                        x_pos -= walk;
                        break;
                    case SDLK_d:
                    case SDLK_RIGHT:
                        x_pos += walk;
                        break;
                    default:
                        break;
                }
        }
    }
}


