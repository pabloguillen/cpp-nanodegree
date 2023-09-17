#ifndef FISH_H
#define FISH_H

#include "asset.h"
#include "SDL_image.h"
#include "SDL.h"
#include <iostream>


class Fish : public Asset {

    public:

    //enum for direction of fish
    enum class Direction {kUp, kDown};

    //constructor
    Fish(std::size_t screen_width, std::size_t screen_height){

    //Initialization of basic properties/member variables, inherited from Base class
    _screen_width = screen_width;
    _screen_height =screen_height;
    position_x = screen_width / 2;
    position_y = screen_height / 2;

    //local source of fish image
    _imagesrc = "../src/Assets/Fish.png";
    
    
    //creation of SDL surface object, called in Renderer::Render()
    sdl_image = IMG_Load(_imagesrc.c_str());
    if (sdl_image == NULL) {
    std::cerr << "Fish Surface could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
      }
    }

    //Default destructor
    ~Fish () {};

    //main update function, inherited from Base class
    void Update();

    //default speed of movement 
    float speed {0.1f};

    //Getter: Check if Fish is still alive (no obstacle crash or out of range)
    bool IsAlive() {return alive;}

    //Setter: Toggle to set alive state (in case obstacle carsh or out of range)
    void SetState (bool state) {alive = state;}

    //Default direction of fish 
    Fish::Direction direction {Direction::kDown};

    private:

    //Alive state
    bool alive {true};
};

#endif