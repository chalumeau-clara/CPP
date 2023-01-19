#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "Rendered_object.h"

class Moving_object : public Rendered_object {
    public:

        // Moving_object(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y, int velocity_x, int velocity_y);
        // Moving_object(std::unique_ptr<SDL_Surface> texture, int x, int y, int velocity_x, int velocity_y);
        // virtual ~Moving_object() = default;

        Moving_object(const std::string &file_path,
                      SDL_Surface* window_surface_ptr):
                      Rendered_object(file_path, window_surface_ptr){};
        virtual ~Moving_object(){};

        // Accesseurs pour la vélocité
        //int getVelocityX() const;
        //int getVelocityY() const;

        // Mutateurs pour la vélocité
        void setVelocityX(int velocityX);
        void setVelocityY(int velocityY);

        // Fonction virtuelle pour déplacement
        virtual void move() = 0;

        // Fonction pour un pas de déplacement
        void step();

    private:
        int velocity_x, velocity_y;
};

#endif // MOVING_OBJECT_H