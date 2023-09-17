//#include "asset.h"
#include "SDL_image.h"
#include "SDL.h"
#include "obstacle.h"
#include <iostream>


    void Obstacle::Update(){

            //update obstacle position
             this->position_x -= speed;

             //update obstacle speed
             speed += 0.001;
    }


    //Checks if crash occured by comparing the position of fish and this obstacle
    bool Obstacle::CheckCrash (std::unique_ptr<Fish> &fish){

        //set fish position (fish size is 81,46)
        int fish_x_start = (int) fish->position_x;
        int fish_x_end = fish_x_start + 81;
        int fish_y_start = (int) fish->position_y+12;
        int fish_y_end = fish_y_start + 46;

        //compare fish and obstacle position (obstacle size is 50, 50)
        if (((fish_x_start <= this->position_x && this->position_x <= fish_x_end) &&  (fish_y_start <= this->position_y && this->position_y <= fish_y_end))||
            ((fish_x_start <= this->position_x && this->position_x <= fish_x_end) &&  (fish_y_start <= (this->position_y + 50) && (this->position_y + 50) <= fish_y_end)) ||
            ((fish_x_start <= (this->position_x + 50) &&  (this->position_x + 50) <= fish_x_end) && (fish_y_start <= this->position_y && this->position_y <= fish_y_end)) ||
            ((fish_x_start <= (this->position_x + 50) && (this->position_x + 50) <= fish_x_end) && (fish_y_start <= (this->position_y + 50) && (this->position_y + 50) <= fish_y_end))){
            //print message if obstacle crashed
            std::cerr<<"Obstacle crash.\n";
            return true;
        } else {
            return false;
        }
    }