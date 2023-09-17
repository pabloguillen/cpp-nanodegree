# CPPND: Capstone FlappyFish

This is a repo for the Capstone project in the Udacity C++ Nanodegree Program. The code for this repo is based on the provided starter repo for a SnakeGame which was adjusted and extended to ‚FlappyFish‘ - a simple Jump ‚n’ Run game inspired by the classic ‚FlappyBird‘.

The goal of the game is to navigate via the space key through randomly spawned rocks (here obstacles) with increasing speed. By default, the fish is moving constantly downwards, whereas pressing the space key will change it's direction to shortly move upwards. Additionally, the fish needs to swim in the range of the water - not on the ground and not above the sea level.
When the fish eventually hits an obstacle, the game will be stopped and an overlay will be displayed. The score of the game indicates the seconds that have passed from launching the game to hitting an obstacle or going out of range.

The repo containts in total 6 classes plus a main function (13 files). The classes Fish and Obstacle inherit basic properties as well as the update function from a base class, called Asset. The game class contains the basic assets (fish and obstacles) of the game and the update loop function (which calls the update function from the asset classes). The Controller class represent the input handler and process key input to update assets. The render class updates the window with the basic render function. In main, a controller object, renderer object and game objects are constructed before calling the 'Run' function on the game object.

This project comes with a few requirements or so-called rubric points which reflect the content learned throughout the Nanodegree program. These rubric points were adressed in various sections of the code:

____

* Criteria:
The project demonstrates an understanding of C++ functions and control structures.

  * A variety of control structures are used in the project.
  * The project code is clearly organized into functions.

No specific line can be stated. However, the project is organized into classes and functions and uses several control structures.


* Criteria:
The project reads data from a file and process the data, or the program writes data to a file.

  * The project reads data from an external file or writes data to a file as part of the necessary operation of the program.

The images of the background, the obstacles, the fish and the Score Overlay are loaded from local directory and read out in the following files & lines:
  - Fish image: fish.h, line 28
  - Obstacle images: obstacle.h, line 37
  - Background image: renderer.cpp, line 38
  - Score Overlay image: renderer.cpp, line 38


* Criteria:
The project accepts user input and processes the input.

  * The project accepts input from a user as part of the necessary operation of the program.

The project processes key events in the controller class and sets the direction of the fish and the running state (line 21 to 39).


* Criteria:
The project uses Object Oriented Programming techniques.

  * The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.

No specific line can be stated. However, the project is organized into classes that hold data and methods to perform tasks.


* Criteria:
Classes use appropriate access specifiers for class members.

  * All class data members are explicitly specified as public, protected, or private.

This is applicable for all defined classes.


* Criteria: 
Class constructors utilize member initialization lists.

  * All class members that are set to argument values are initialized through member initialization lists.


The classes Game (game.cpp, line 8) and Renderer (renderer.cpp line 10) are initialized through member initialization lists.


* Criteria:
Classes abstract implementation details from their interfaces.

  * All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.

This applies for all member functions.


* Criteria:
Classes encapsulate behavior.

  * Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.

This applies for all member data. One specific example is in file fish.h in line 59, where the 'alive' state is hidden for from the user and needs to be called via a respective getter or setter function.


* Criteria:
Classes follow an appropriate inheritance hierarchy.

  * Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.

The classes Fish and Obstacle inherit from the class Asset and the function Asset::Update() is overwritten by the derived classes Fish and Obstacle.


* Criteria:
Derived class functions override virtual base class functions.

  * One member function in an inherited class overrides a virtual base class member function.

The classes Fish and Obstacle overwrite the function Asset::Update() from the Asset class (virtual base class).


* Criteria:
The project makes use of references in function declarations.

  * At least two variables are defined as references, or two functions use pass-by-reference in the project code.

In various functions of the project code, paraameter are passed by reference (l-value and r-value). For example:
  - In game.h, line 19: R-value reference
  - In render.h, line 21: L-value reference
  - In controller.h (Controller::Handleinput), line 5: L-value reference


* Criteria:
The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.

  * The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.

In file game.cpp (line 154), a lock_guard object is declared and initialzed to ensure automatic locking & unlocking of mutex while destruction.


* Criteria:
The project uses smart pointers instead of raw pointers.

  * The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.

The game class contains contains a unique pointer pointing to a fish object as member variable (line 30) and in main.cpp a unique pointer to a renderer object is constrcted (line 18).


* Criteria:
The project uses multithreading.

  * The project uses multiple threads in the execution.

The project uses multithireading by creating an asynchronous task to update the score of the game (game.cpp, line 28).


* Criteria:
A mutex or lock is used in the project.

  * A mutex or lock (e.g. std::lock_guard or std::unique_lock) is used to protect data that is shared across multiple threads in the project code.

The class Game contains a mutex as member variable which is locked/unlocked (Game::Run(), line 35 & 47) and locked via a lock_guard object (Game::UpdateScore(), line 154) in game.cpp 

____


## Dependencies for Running Locally

* cmake >= 3.7
    * All OSes: click here for installation instructions
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
    * Linux: make is installed by default on most Linux distros
    * Mac: install Xcode command line tools to get make
    * Windows: Click here for installation instructions
* SDL2 >= 2.0
    * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
* Note that for Linux, an apt or apt-get installation is preferred to building from source.
* SDL2_image >= 2.0.5
    * All installation instructions can be found [here] (https://www.libsdl.org/projects/SDL_image/)
* Note that for Linux, an apt or apt-get installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions 

1. Clone this repo.
2. Make a build directory in the top level directory: mkdir build && cd build
3. Compile: cmake .. && make
4. Run it: ./FlappyFish