cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
# set the project name
project(selection_sort)

# add the lib
#add_library(mysource SHARED sources.cpp)

# add another
#add_library(mysource_2 SHARED sources_2.cpp)

# add the executable
add_executable(main my_sort.hpp main.cc)

# Compilation optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

# do not forget to link
#target_link_libraries(main mysource)

#target_link_libraries(main mysource_2)