Changes:

Installed SDL_image library using:
>> sudo apt-get install libsdl2-dev libsdl2-image-dev

Changed following lines in CMakeLists.txt:

include_directories(${SDL2_INCLUDE_DIRS} src)
target_link_libraries(SpaceInvaders ${SDL2_LIBRARIES})

to

include_directories(${SDL2_INCLUDE_DIRS} src ${SDL2IMAGE_INCLUDE_DIRS})
target_link_libraries(SpaceInvaders ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

in order to include and link the SDL_image library. I'm using the library to import PNG images with a transparent background, since
BMP images do no include an alpha channel with transparent data.