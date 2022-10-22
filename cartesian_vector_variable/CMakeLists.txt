cmake_minimum_required(VERSION 3.0)

# set the C++ standard
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(cartesian_vector_variable)

# add the lib
add_executable(main vector.cpp main.cc)
