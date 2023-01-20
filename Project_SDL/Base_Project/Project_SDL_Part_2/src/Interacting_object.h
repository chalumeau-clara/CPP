#ifndef INTERACTING_OBJECT_H
#define INTERACTING_OBJECT_H

#include <set>
#include <string>
#include <algorithm>

// constexpr double frame_rate = 60.0; // refresh rate
// constexpr double frame_time = 1. / frame_rate;
// constexpr unsigned frame_width = 1400; // Width of window in pixel
// constexpr unsigned frame_height = 900; // Height of window in pixel
constexpr unsigned sheep_width = 50; // Width of sheep in pixel
constexpr unsigned sheep_height = 50; // Height of sheep in pixel
constexpr unsigned wolf_width = 50; // Width of wolf in pixel
constexpr unsigned wolf_height = 25; // Height of wolf in pixel
constexpr unsigned shepherd_dog_width = 50; // Width of shepherd dog in pixel
constexpr unsigned shepherd_dog_height = 25; // Height of shepherd dog in pixel
constexpr unsigned shepherd_width = 50; // Width of shepherd in pixel
constexpr unsigned shepherd_height = 25; // Height of shepherd in pixel

// Minimal distance of animals to the border
// of the screen
constexpr unsigned frame_boundary = 100;

// Distance for which sheep should run away from wolf.
constexpr unsigned sheep_danger_distance = 10;

// Minimum distance between shepherd and dog.
constexpr unsigned shepherd_min_distance = 5;

class Interacting_object {
    public:
        Interacting_object(){properties_.insert("alive");};

        ~Interacting_object(){};

        // Accesseur pour les propriétés
        std::set<std::string> getProperties();
        
        // Mutateurs pour les propriétés
        void set_property(const std::string &property) {properties_.insert(property);};
        void remove_property(const std::string &property) {properties_.erase(property);};

        void mark_dead() {
            properties_.erase("alive");
            properties_.insert("dead");
        };
        bool is_alive() {
            return std::find(properties_.begin(), properties_.end(), "alive") != properties_.end();
        };
        bool has_property(std::string property) {
            return std::find(properties_.begin(), properties_.end(), property) != properties_.end();
        }
        
        // SDL_Rect* get_position() {
        //     return position_;
        // };
        // void setProperties(std::set<std::string> properties);
        // void setProperties(const std::set<std::string>& properties);
        // void addProperty(std::string property);
        // void removeProperty(std::string property);


        // Fonction virtuelle pour les interactions
        //virtual void interact(Interacting_object& other) = 0;
        // virtual std::set<std::string> interact() = 0;
        virtual void interact(Interacting_object *other_object) = 0;

    private:
        std::set<std::string> properties_;
        // SDL_Rect* position_;
};

#endif // INTERACTING_OBJECT_H