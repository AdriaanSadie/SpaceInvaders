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

### Base requirements:

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
    
### Additional requirements:

*Loops, Functions, I/O*

5. The project demonstrates an understanding of C++ functions and control structures.
	* A variety of control structures are used in the project.
    	* While loops and switch-case statements are used e.g. in **game.cpp** on lines 24 and 26.
        * Lambdas with predicate expressions are used e.g. in **level.cpp** on lines 26 and 41 among others.
	* The project code is clearly organized into functions.
    	* Functions clearly separates functionality and tasks e.g. in **renderer.cpp**, the methods RenderMenu() on line 100 prints the menu image to the game window, and UpdateWindowTitle(int) updates the title of the game window along with the current frame rate.

6. The project reads data from a file and process the data.
	* The project reads data from an external file as part of the necessary operation of the program.
    	* The method Game::LoadConfig(int,int&,int&,std::string&,int&) on line 107 in **game.cpp** opens the config.txt file, parses the text and sets certains member variables accordingly. The level-specific information is stored in the file, e.g. the amount of enemies for the corresponding difficulty.
        
7. The project accepts user input and processes the input.
	* The project accepts input from a user as part of the necessary operation of the program.
    	* The Controller class handles all necessary keyboard input from the user in **controller.cpp**. It uses the SDL_PollEvent(&event) method to 'listen' for keys being pressed by the user.
        
*Object Oriented Programming*

8. The project uses Object Oriented Programming techniques.
	* The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
    	* There are seven distinct classes which each own their respective data and class methods. These are: **game.cpp**, **renderer.cpp**, **controller.cpp**, **player.cpp** (which also contains the Projectile class) and finally **level.cpp** (which also contains the Enemy class). 

9. Classes use appropriate access specifiers for class members.
	* All class data members are explicitly specified as public, protected, or private.
    	* The appropriate private and public members and functions of class are specified, e.g. **level.h** on lines 33 and 56.

10. Class constructors utilize member initialization lists.
	* All class members that are set to argument values are initialized through member initialisation lists.
    	* Member initialisation lists are frequently used, e.g. in **game.cpp** on line 10, in **renderer.cpp** on line 5, etc.

*Memory Management*

11. The project makes use of references in function declarations.
	* At least two variables are defined as references, or two functions use pass-by-reference in the project code.
    	* Two examples of pass-by-reference can be seen in **level.cpp** for the functions Level::Update(Player &player, bool &game_running) - line 21, and Level::EnemyShootLoop(bool &running) - line 88.

*Concurrency*

12. The project uses multithreading.
	* The project uses multiple threads in the execution.
    	* A secondary thread is created to shoot lasers from the enemies. The goal was to make the intervals of shots less frequent. The thread is started in **game.cpp** on line 45.


## Conclusion

As described in the above section, eight of the rubric criteria was met, excluding the base requirements of the compilation and README file.
        
## Recommendations

The following can be improved:

1. The player has the ability to shoot continuously, which makes the game ridiculously easy, even on the hard difficulty. Another thread should be started up which limits the amount of shots that can be fired by means of a boolean.
2. A high score with a name is also stored in the config.txt file but is not currently used in the game. The high score information should be displayed on the main menu and the final screen of the game, where the user also gets the chance to enter a name to be stored along with the score.
3. The player currently decides the difficulty with each iteration of the game. For a better experience, the game should increase difficulty with each iteration and maybe even feature a boss fight later on.
4. Currently, one hit kills the player as well as any enemy. Hit points should be assigned to both, which can be altered based on the difficulty.
5. The user can press ESC any time to exit the game, except during the delay at the final (game-over/victory) screen. This bug should be fixed so that the user is able to exit at any time.
