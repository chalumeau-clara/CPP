//
// Created by clara on 15/12/22.
//

#ifndef CPP_WOLF_H
#define CPP_WOLF_H


class wolf : public animal
{
public:
    wolf(const std::string &file_path, SDL_Surface *window_surface_ptr)
            : animal(file_path, window_surface_ptr){};

    ~wolf()= default;
    void move() override;

};


#endif //CPP_WOLF_H
