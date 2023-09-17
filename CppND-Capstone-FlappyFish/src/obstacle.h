#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "asset.h"
#include "SDL_image.h"
#include "SDL.h"
#include "fish.h"
#include <iostream>
#include <random>
#include <memory>


class Obstacle : public Asset {

    public:

    //Constructor
    Obstacle(std::size_t screen_width, std::size_t screen_height)
      {

    //set basic properties
    _screen_width = screen_width;
    _screen_height = screen_height;
    position_x = _screen_width;

    //get random y position of obstacle 
    std::random_device obstacle_position;
    std::mt19937 gen(obstacle_position()); // seed the generator
    std::uniform_int_distribution<> distribution(80, 420); // define the range
    position_y  = distribution(gen);
    

    //get random obstacle image in local directory
    std::random_device obstacle_type;    
    std::mt19937 generator(obstacle_type()); // seed the generator
    std::uniform_int_distribution<> distr(1, 7); // define the range
     _imagesrc =  "../src/Assets/Obstacle" + std::to_string(distr(generator)) + ".png";

    //set SDL surface object
    sdl_image = IMG_Load(_imagesrc.c_str());
    if (sdl_image == NULL) {
    std::cerr << "Fish Surface could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
      }
    }

    //main update function, inherited from Base class
    void Update();

    //static member representing speed, intialized in game class
    static float speed;

    //check whether crashed has occured
    bool CheckCrash (std::unique_ptr<Fish> &fish);
};

#endif