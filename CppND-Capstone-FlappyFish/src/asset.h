#ifndef ASSET_H
#define ASSET_H

#include <string>
#include "SDL_image.h"



class Asset {

    public:

    //Main update function for assets
    virtual void Update() {};

    //return SDL surface in Render class for rendering image
    SDL_Surface* getSDLImage(){return sdl_image;};

    //x position on screen for assets
    int position_x;

    //y position on screen for assets;
    int position_y;

    //local source of asset images
    std::string _imagesrc;

    //SDL surface for rendering image
    SDL_Surface* sdl_image;

    //Default screen width for asset
    int _screen_width;

    //Default scree height for asset
    int _screen_height;
};

#endif