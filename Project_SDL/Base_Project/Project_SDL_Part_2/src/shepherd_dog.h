//
// Created by clara on 15/12/22.
//

#ifndef CPP_SHEPHERED_DOG_H
#define CPP_SHEPHERED_DOG_H


class shephered_dog : public animal{

    public:
        shephered_dog(const std::string &file_path, SDL_Surface *window_surface_ptr)
                : animal(file_path, window_surface_ptr){};

        ~shephered_dog()= default;
        void move() override;

};


#endif //CPP_SHEPHERED_DOG_H
