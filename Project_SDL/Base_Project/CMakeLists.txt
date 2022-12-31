cmake_minimum_required (VERSION 3.0)

project ("Project_SDL2")

# Pour MacOS
find_package(SDL2 REQUIRED) # build dans variable SDL2_INCLUDE_DIRS et SDL2_LIBRARIES -> (ne fait pas de target)
find_package(SDL2_image REQUIRED) # configure SDL2_image en target correctement -> 

set (CMAKE_CXX_STANDARD 17)

# Schließen Sie Unterprojekte ein.

add_executable(SDL_project
        Project_SDL_Part_2/src/main.cpp
        Project_SDL_Part_2/src/render.cpp
        Project_SDL_Part_2/src/render.h
        Project_SDL_Part_2/src/animal.cpp
        Project_SDL_Part_2/src/application.cpp
        Project_SDL_Part_2/src/interact.cpp
        Project_SDL_Part_2/src/playable_character.cpp
        Project_SDL_Part_2/src/sheep.cpp
        Project_SDL_Part_2/src/shepherd.cpp
        Project_SDL_Part_2/src/shepherd_dog.cpp
        Project_SDL_Part_2/src/wolf.cpp Project_SDL_Part_2/src/ground.h Project_SDL_Part_2/src/ground.cpp)


# add memory leak detection
target_compile_options(SDL_project PRIVATE -Wall -Wextra -pedantic -Werror -fsanitize=address -fno-omit-frame-pointer)

# Pour MacOS
target_include_directories(SDL_project PRIVATE ${SDL2_INCLUDE_DIRS} SDL2_image) # ajoute les include de SDL2 -> necessaire car SDL2 n'est pas un target
target_link_libraries(SDL_project PRIVATE ${SDL2_LIBRARIES} SDL2_image) # ajoute les librairies de SDL2 -> pour link les librairies SDL2 avec SDL2_image