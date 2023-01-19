# CMakeList.txt: CMake-Projektdatei der obersten Ebene. Führen Sie hier die globale Konfiguration aus,
# und schließen Sie Unterprojekte ein.
#
cmake_minimum_required (VERSION 3.8)

project ("SDL_Test")

set (CMAKE_CXX_STANDARD 17)

# Schließen Sie Unterprojekte ein.
add_subdirectory ("SDL_Test")
