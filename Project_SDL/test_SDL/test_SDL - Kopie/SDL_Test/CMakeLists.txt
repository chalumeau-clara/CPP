IF(WIN32)
  message(STATUS "Building for windows")

  add_compile_definitions(WINDOWSOS)

  set(SDL2_INCLUDE_DIRS "SDL2/include")
  set(SDL2IMAGE_INCLUDE_DIRS "SDL2_image/include")

  # Support both 32 and 64 bit builds
  if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    message(STATUS "Building for x64")
    set(SDL2_LINK_DIRS "SDL2/lib/x64")
    set(SDL2IMAGE_LINK_DIRS "SDL2_image/lib/x64")
  else ()
    message(STATUS "Building for x86")
    set(SDL2_LINK_DIRS "SDL2/lib/x86")
    set(SDL2IMAGE_LINK_DIRS "SDL2_image/lib/x86")
  endif ()

  include_directories(${SDL2_INCLUDE_DIRS})
  include_directories(${SDL2IMAGE_INCLUDE_DIRS})
  link_directories(${SDL2_LINK_DIRS}, ${SDL2IMAGE_LINK_DIRS})


  message(STATUS ${SDL2_LINK_DIRS})
  message(STATUS ${SDL2IMAGE_LINK_DIRS})
  add_executable(SDLTest Main.cpp)
  target_link_libraries(SDLTest PUBLIC SDL2 SDL2main SDL2_image)
ELSE()
  message(STATUS "Building for Linux or Mac")

  find_package(SDL2 REQUIRED)
  find_package(SDL2_image REQUIRED)
  include_directories(${SDL2_INCLUDE_DIRS})

  add_executable(SDLTest Main.cpp)
  target_link_libraries(SDLTest ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
ENDIF()
