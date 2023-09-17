#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, std::unique_ptr<Fish> &fish) {
  SDL_Event e;

  //blocks for 30 frames to smoothly move fish upwards with constant speed
  if (fish->direction == Fish::Direction::kUp && this->count <= 30){
        count ++;
        return;
  }

  //reset of count
  count = 0;

  //Switch of direction toggle to down
  fish->direction = Fish::Direction::kDown;

  //invoked when event is 
  while (SDL_PollEvent(&e)) {
    
    //check whether quit was clicked
    if (e.type == SDL_QUIT) {
      running = false;
      
      //check whether key was pressed
    } else if (e.type == SDL_KEYDOWN) {

      //check whether pressed key was space
      if (e.key.keysym.scancode == SDL_SCANCODE_SPACE){ 

        //switch of direction toggle to up
        fish->direction = Fish::Direction::kUp;
        return;
      } 
    }
 }
}

