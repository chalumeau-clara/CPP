cmake_minimum_required(VERSION 3.0)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(MyFirstProg)

# add the lib
add_library(vector1 SHARED vector.cc)

# add another
#add_library(mysource_2 SHARED sources_2.cpp)

# add the executable
add_executable(main main.cc)

# do not forget to link
target_link_libraries(main vector1)

#target_link_libraries(main mysource_2)