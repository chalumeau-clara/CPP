cmake_minimum_required(VERSION 3.0)

# set the project name
project(MyFirstProg)

# add the lib
#add_library(mysource SHARED sources.cpp)

# add the executable
add_executable(main main.cpp is_prime.cpp)

# do not forget to link
#target_link_libraries(main mysource)

#target_link_libraries(main mysource_2)