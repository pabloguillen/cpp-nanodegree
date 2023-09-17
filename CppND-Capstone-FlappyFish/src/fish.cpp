//#include "Asset.h"
#include "fish.h"
//#include "SDL_image.h"
//#include "SDL.h"
#include <iostream>



    void Fish::Update() {

        //check if fish hits the floor or is above the screen
        if (this->position_y <= 0 ||  this->position_y >= 500){
          //if true then set the isAlive state of fish to false
          this->SetState(false);
          return;
        } else {

            //update y position of fish based on direction state
            switch (this->direction) {
              case Direction::kUp:
              //move fish updwards
              this->position_y -= 1;
              break;

              case Direction::kDown:
              //move fish dowwards
              this->position_y += 1;
              break;
            }
       }
    }