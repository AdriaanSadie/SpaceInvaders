# CPPND: Capstone C++ Project Space Invaders

## Project Description

Option 1 (video game) was chosen for a project. A simple version of Space Invaders was written, using the starter code of the Snake project as base. The game starts by showing the user a menu, where the difficulty is chosen. After this the game starts, where enemies (which are able to shoot) start to move from the top of the screen slowly to the bottom. The objective of the player is to shoot the enemies before they shoot the player. When a player wins (all enemies shot down), the player wins. When the player loses, a Game Over screen is shown. The game then resets automatically after a slight delay. At any point ESC can be pressed to exit the game.

The file and class structure is set up as follows:

1. main.cpp -> Contains constants regarding game window and creates the Game, Controller and Render objects. The Game::Run() method is then called which starts the game state machine
2. renderer.cpp -> Renderer class. Methods to render the game window, the player, the enemies and all projectiles. Also renders the menu and game-over screens.
3. controller.cpp -> Controller class. Handles all input from the user. Has two methods: input while in the menu, and input while in-game.
4. game.cpp -> Game class. Has the main Run() method which contains a state machine that handles all stages of the game: Main menu -> Initialise -> Game loop -> Game-over screen. Owns the Player and Level objects.
5. player.cpp -> Player and Projectile classes. Contains the Player class which represents the player with all the necessary member variables and functions. Also contains the Projectile class which is responsible for all the bullets and lasers in the game.
6. level.cpp -> Level and Enemy classes. Contains the Level class which owns the enemy vector as well as the lasers vector and is responsible for all the enemy and lasers creation and movement. The Enemy class is similar to the player class and holds all the necessary member variables and functions for the aliens.

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

*Loops, Functions, I/O
    







git config --global user.name "AdriaanSadie" && git config --global user.email "sadieadriaan@gmail.com"


