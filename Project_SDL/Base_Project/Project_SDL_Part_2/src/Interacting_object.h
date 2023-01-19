#ifndef INTERACTING_OBJECT_H
#define INTERACTING_OBJECT_H

#include <set>
#include <string>

class Interacting_object {
    public:
        Interacting_object() = default;
        ~Interacting_object() = default;

        // Accesseur pour les propriétés
        std::set<std::string> getProperties();
        
        // Mutateurs pour les propriétés
        void set_property(const std::string &property);
        void remove_property(const std::string &property);
        // void setProperties(std::set<std::string> properties);
        // void setProperties(const std::set<std::string>& properties);
        // void addProperty(std::string property);
        // void removeProperty(std::string property);


        // Fonction virtuelle pour les interactions
        //virtual void interact(Interacting_object& other) = 0;
        // virtual std::set<std::string> interact() = 0;
        virtual void interact() = 0;

    private:
        std::set<std::string> properties_;
};

#endif // INTERACTING_OBJECT_H