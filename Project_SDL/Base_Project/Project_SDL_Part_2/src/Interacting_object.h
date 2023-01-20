#ifndef INTERACTING_OBJECT_H
#define INTERACTING_OBJECT_H

#include <set>
#include <string>
#include <algorithm>

// Minimal distance of animals to the border
// of the screen
constexpr unsigned frame_boundary = 100;

class Interacting_object {
    public:
        Interacting_object(){properties_.insert("alive");};

        ~Interacting_object(){};

        // Accesseur pour les propriétés
        std::set<std::string> getProperties();
        
        // Mutateurs pour les propriétés
        void set_property(const std::string &property) {properties_.insert(property);};
        void remove_property(const std::string &property) {properties_.erase(property);};

        // void setProperties(std::set<std::string> properties);
        // void setProperties(const std::set<std::string>& properties);
        // void addProperty(std::string property);
        // void removeProperty(std::string property);


        // Fonction virtuelle pour les interactions
        virtual void interact() = 0;

    private:
        std::set<std::string> properties_;
};

#endif // INTERACTING_OBJECT_H