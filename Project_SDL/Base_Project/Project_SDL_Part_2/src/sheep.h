//
// Created by clara on 15/12/22.
//

#ifndef CPP_SHEEP_H
#define CPP_SHEEP_H


class sheep : public animal
{
public:
    // Constructor basic
    sheep(const std::string &file_path, SDL_Surface *window_surface_ptr)
            : animal(file_path, window_surface_ptr){};

    // Destructor
    ~sheep()= default;
    void move() override;

protected:
    bool sex; // if = 0 then male else female
    uint64 offspring_time;
};


#endif //CPP_SHEEP_H
