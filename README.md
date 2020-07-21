# CPPND: Capstone C++ Project Space Invaders

## Project Description

Option 1 (video game) was chosen for a project. A simple version of Space Invaders was written, using the starter code of the Snake project as base. The game starts by showing the user a menu, where the difficulty is chosen. After this the game starts, where enemies (which are able to shoot) start to move from the top of the screen slowly to the bottom. The objective of the player is to shoot the enemies before they reach the player, or the bottom of the screen. When a player wins, the high score is updated and stored. When the player loses, a Game Over screen is shown (depending on the current score, the high score is updated) and an option is given to start over.

## Additional libraries required:

Make sure the SDL and SDL_image libraries are installed:
>> sudo apt-get install libsdl2-dev libsdl2-image-dev

The SDL_image library is used to import PNG images with a transparent background, since the base SDL library can only import BMP images, which do not include an alpha channel with transparent data.

## To build and run:

1. Create a build directory and change current directory to build:
	* >> mkdir build && cd build
2. Run Cmake and Make from build:
	* >> cmake .. && make
3. Run game:
	* >> ./SpaceInvaders


## Specifications met as stated on Project Rubric:

Base requirements:

1. A README with instructions is included with the project
	* The README is included with the project and has instructions for building/running the project.
    * Additional libraries needed to run the project are indicated with cross-platform installation instructions.
    * README submitted as markdown
    
2. The README indicates which project is chosen.
	* The README describes the project.
    * The README also indicates the file and class structure, along with the expected behavior or output of the program.

3. The README includes information about each rubric point addressed.
	* The README indicates which rubric points are addressed.
    * The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.
    
4. The submission compiles and runs.
	* The project code compiles and runs without errors.
    * CMake and Make is used as building tools.
    
Additional requirements:


    







git config --global user.name "AdriaanSadie" && git config --global user.email "sadieadriaan@gmail.com"


