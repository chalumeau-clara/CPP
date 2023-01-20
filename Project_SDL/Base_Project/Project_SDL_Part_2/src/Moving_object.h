#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "Rendered_object.h"

class Moving_object : public Rendered_object {
    public:

        Moving_object(const std::string &file_path, SDL_Surface* window_surface_ptr):
            Rendered_object(file_path, window_surface_ptr){
        };

        virtual ~Moving_object(){};

        // Accesseurs pour la vélocité
        int getVelocityX() const { return velocity_x_; };
        int getVelocityY() const { return velocity_y_; };

        // Mutateurs pour la vélocité
        void setVelocityX(int velocityX) { velocity_x_ = velocityX; };
        void setVelocityY(int velocityY) { velocity_y_ = velocityY; };

        // Fonction virtuelle pour déplacement
        virtual void move() = 0;

        // Fonction pour un pas de déplacement
        void step() {
        };


private:
        int velocity_x_, velocity_y_;
protected:
    int x_move = 0;     // 0 left; 1 straight; 2 right
    int y_move = 0;     // 0 down; 1 straight; 2 upp
};

#endif // MOVING_OBJECT_H