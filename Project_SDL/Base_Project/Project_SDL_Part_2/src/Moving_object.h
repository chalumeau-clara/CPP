#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "Rendered_object.h"

class Moving_object : public Rendered_object {
    public:

        Moving_object(const std::string &file_path,
                      SDL_Surface* window_surface_ptr, uint64_t x_position, uint64_t y_position):
                      Rendered_object(file_path, window_surface_ptr){
            x_pos = x_position;
            y_pos = y_position;
        };

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
        void step() {
        };

        int get_x_pos();
        int get_y_pos();


private:
        int velocity_x_, velocity_y_;
protected:
    uint64_t x_pos = 0;
    uint64_t y_pos = 0;
    uint64_t x_move = 0;     // 0 left; 1 straight; 2 right
    uint64_t y_move = 0;     // 0 down; 1 straight; 2 upp
};

#endif // MOVING_OBJECT_H