#ifndef INTERACTING_OBJECT_H
#define INTERACTING_OBJECT_H

#include <set>
#include <string>
#include <algorithm>
#include <SDL2/SDL.h>
#include <cmath>

// Minimal distance of animals to the border
// of the screen
constexpr int frame_boundary = 100;
constexpr int frame_width = 1400; // Width of window in pixel
constexpr int frame_height = 900; // Height of window in pixel

class Interacting_object {
    public:
        Interacting_object(){
            properties_.insert("alive");
            // random position in the screen
            position_ = new SDL_Rect{rand() % (frame_width - 2 * frame_boundary) + frame_boundary, rand() % (frame_height - 2 * frame_boundary) + frame_boundary, 0, 0};
            };

        ~Interacting_object(){
            delete position_;
        };

        // Accesseur pour les propriétés
        bool find_property(std::string property){return properties_.find(property) != properties_.end();};
        
        // Mutateurs pour les propriétés
        void set_property(const std::string &property) {properties_.insert(property);};
        void remove_property(const std::string &property) {properties_.erase(property);};



        // void setProperties(std::set<std::string> properties);
        // void setProperties(const std::set<std::string>& properties);
        // void addProperty(std::string property);
        // void removeProperty(std::string property);


        // Fonction virtuelle pour les interactions
        virtual void interact(Interacting_object &other_object) = 0;

        SDL_Rect* get_position() {
            return position_;
        };

        void set_position(int x, int y) {
            position_->x = x;
            position_->y = y;
        };

    private:
        std::set<std::string> properties_;
        SDL_Rect *position_; // Position of the object
};

#endif // INTERACTING_OBJECT_H