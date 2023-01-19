PLEASE try this home!

SDL: SDL is a "simple" media layer written in C++.
It is used for indie games for instances.

This is an example project whose only purpose is to check
your installation.

The build must succeed and launching the application should give you a
window showing an image for 10sec

Linux

Install the packages via
sudo apt install libsdl2-2.0-0 libsdl2-dev libsdl2-image-2.0-0  libsdl2-image-dev

Now the tricky part, there is no "default" cmake package for sdl2_image
so create the folder
sudo mkdir /usr/lib/x86_64-linux-gnu/cmake/sdl2_image
create the file
sudo nano /usr/lib/x86_64-linux-gnu/cmake/sdl2_image/sdl2_image-config.cmake
and paste

set(prefix "/usr")
set(exec_prefix "${prefix}")
set(libdir "${prefix}/lib/x86_64-linux-gnu")
set(SDL2_IMAGE_PREFIX "/usr")
set(SDL2_IMAGE_EXEC_PREFIX "/usr")
set(SDL2_IMAGE_INCLUDE_DIRS "${prefix}/include/SDL2_image")
set(SDL2_IMAGE_LIBRARIES "-lSDL2_image")
link_directories("${prefix}/lib/x86_64-linux-gnu")

and you should be good to go.

MacOS
Install packages via brew
brew install sdl2

make the same cmake packages magic detailed in the linux part (I guess?)

I think you should be good to go as well, but I can't test this.

Linux and MacOS:
you need to start the application from the folder test_SDL
(where img.png is located)
If you use clion: Either define the working directory or
use the console.
cd to test_SDL and type
./cmake-build-debug/SDL_Test/SDLTest
to launch

Windows
Windows needs to be able to find the shared library, we
therefore need to add it to the path.
However there are two version x64 and x86.

Step 1)
Configure the cmake project.
In the messages you should see either
-- Building for x86
or
-- Building for x64

Step 2)
Go to environement variables -> Click on path -> edit -> new
Select [path to this folder]/SDL_Test/SDL2/lib/[x64|x86]
Do the same for SDL2_image

You should be able to build and launch.
If the built-in launcher of VS gives you an error,
try launching it from the powershell.




