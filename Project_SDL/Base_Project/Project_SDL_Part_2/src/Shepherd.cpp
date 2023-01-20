#include "Shepherd.h"

void Shepherd::interact(Interacting_object &other_object){
    if (other_object.find_property("sheep")){
    }
}


void Shepherd::move() {
    while(SDL_PollEvent(&window_events)) {
        switch(window_events.type) {
            // Key press detected
            case SDL_KEYDOWN:
                switch(window_events.key.keysym.sym){
                    case SDLK_z:
                    case SDLK_UP:
                        get_position()->y -= walk;
                        break;
                    case SDLK_s:
                    case SDLK_DOWN:
                        get_position()->y += walk;
                        break;
                    case SDLK_q:
                    case SDLK_LEFT:
                        get_position()->x -= walk;
                        break;
                    case SDLK_d:
                    case SDLK_RIGHT:
                        get_position()->x += walk;
                        break;
                    default:
                        break;
                }
        }
    }
}


