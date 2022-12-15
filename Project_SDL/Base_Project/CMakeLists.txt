cmake_minimum_required (VERSION 3.0)

project ("Project_SDL1")

# Pour MacOS
find_package(SDL2 REQUIRED) # build dans variable SDL2_INCLUDE_DIRS et SDL2_LIBRARIES -> (ne fait pas de target)
find_package(SDL2_image REQUIRED) # configure SDL2_image en target correctement -> 

set (CMAKE_CXX_STANDARD 17)

# Schließen Sie Unterprojekte ein.

add_executable(SDL_project
Project_SDL_Part1_base/main.cpp
Project_SDL_Part1_base/Project_SDL1.cpp
)

# add memory leak detection
target_compile_options(SDL_project PRIVATE -Wall -Wextra -pedantic -Werror -fsanitize=address -fno-omit-frame-pointer)

# Pour MacOS
target_include_directories(SDL_project PRIVATE ${SDL2_INCLUDE_DIRS} SDL2_image) # ajoute les include de SDL2 -> necessaire car SDL2 n'est pas un target
target_link_libraries(SDL_project PRIVATE ${SDL2_LIBRARIES} SDL2_image) # ajoute les librairies de SDL2 -> pour link les librairies SDL2 avec SDL2_image