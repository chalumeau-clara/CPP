#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "Rendered_object.h"

// Sheep temporary speed boost value (in absolute value).
constexpr unsigned velocity_boost = 3;
constexpr Uint32 speed_boost_time = 100;

// Character's default velocity.
constexpr unsigned sheep_velocity = 1;
constexpr unsigned wolf_velocity = 1;
constexpr unsigned player_velocity = 1;
constexpr unsigned shepherd_dog_velocity = 1;

class Moving_object : public Rendered_object {
    public:

        // Moving_object(std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> texture, int x, int y, int velocity_x, int velocity_y);
        // Moving_object(std::unique_ptr<SDL_Surface> texture, int x, int y, int velocity_x, int velocity_y);
        // virtual ~Moving_object() = default;

        Moving_object(const std::string &file_path,
                      SDL_Surface* window_surface_ptr, uint64_t x_position, uint64_t y_position):
                      Rendered_object(file_path, window_surface_ptr){
            x_pos = x_position;
            y_pos = y_position;
        };

        // Moving_object(const std::string &file_path,
        //                       SDL_Surface* window_surface_ptr, int x_object, int y_object):
        //                       Rendered_object(file_path, window_surface_ptr, x_object, y_object){};

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
        void step(int increment_x, int increment_y) {
            velocity_x_ += increment_x;
            velocity_y_ += increment_y;
            get_position()->x = clamp(get_position()->x + velocity_x_, frame_width);
            get_position()->y = clamp(get_position()->y + velocity_y_, frame_height);
        };

        int get_x_pos();
        int get_y_pos();

        // Helper function to calculate distance between two objects.
        double distance(SDL_Rect* first_object_pos, SDL_Rect* second_object_pos);

        // Helper function to clamp position of object.
        int clamp(int position, int max_position);

private:
        int velocity_x_, velocity_y_;
protected:
    uint64_t x_pos = 0;
    uint64_t y_pos = 0;
    uint64_t x_move = 0;     // 0 left; 1 straight; 2 right
    uint64_t y_move = 0;     // 0 down; 1 straight; 2 upp
};

#endif // MOVING_OBJECT_H