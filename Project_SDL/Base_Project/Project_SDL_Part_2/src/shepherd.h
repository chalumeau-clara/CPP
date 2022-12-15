//
// Created by clara on 15/12/22.
//

#ifndef CPP_SHEPHERD_H
#define CPP_SHEPHERD_H


class shepherd : public playable_caracter {

    public:
        shepherd(const std::string &file_path, SDL_Surface *window_surface_ptr)
            : playable_caracter(file_path, window_surface_ptr){};

        ~shepherd()= default;
};


#endif //CPP_SHEPHERD_H
