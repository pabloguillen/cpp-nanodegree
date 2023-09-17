#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "fish.h"
#include "obstacle.h"
#include <mutex>

class Renderer {
 public:

  //Constructor
  Renderer(const std::size_t screen_width, const std::size_t screen_height);

  //Destructor
  ~Renderer();

  //Basic render function
  void Render(std::unique_ptr<Fish> &fish, std::vector<Obstacle> &obstacles);

  //update window title
  void UpdateWindowTitle(int &score, int fps);

 private:

  //Basic SDL properties 
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Texture * sdl_texture;
  SDL_Surface *sdl_image;

  //Screen properties
  const std::size_t screen_width;
  const std::size_t screen_height;

  //display score overlay after crash
  void DisplayScoreOverlay ();
};

#endif