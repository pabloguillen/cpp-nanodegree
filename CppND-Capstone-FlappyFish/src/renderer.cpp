#include "renderer.h"
#include <iostream>
#include <string>
#include <vector>


 //Constructor
 Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)   
    : screen_width(screen_width),
      screen_height(screen_height){

  // Initialize SDL properties
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  //Create surface
  sdl_image = IMG_Load("../src/Assets/background.jpg");
  if (sdl_image == NULL) {
    std::cerr << "Surface could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  //Create texture
  sdl_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_image);
  if (sdl_texture == NULL) {
    std::cerr << "Texture could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

}

//Destructor
Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
  IMG_Quit();
}

//Basic render function
void Renderer::Render(std::unique_ptr<Fish> &fish, std::vector<Obstacle> &obstacles){

  SDL_RenderClear(sdl_renderer);
  SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);


  //Render fish
  //Create texture 
   SDL_Surface* fish_image = fish->getSDLImage();
   SDL_Texture *sdl_texture_fish = SDL_CreateTextureFromSurface(sdl_renderer, fish_image);
   if (sdl_texture_fish == NULL) {
    std::cerr << "Texture of Fish could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
   }

  SDL_Rect dstrect = {fish->position_x, fish->position_y, 91, 56 };
  SDL_RenderCopy(sdl_renderer, sdl_texture_fish, NULL, &dstrect);

  //Render Obstacles
  //Create texture 
  for (auto o : obstacles){
   SDL_Surface* obstacle_image = o.getSDLImage();
   SDL_Texture *sdl_texture_obstacle = SDL_CreateTextureFromSurface(sdl_renderer, obstacle_image);
   if (sdl_texture_obstacle == NULL) {
    std::cerr << "Texture of Obstacle could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
    SDL_Rect dstrect_ = {o.position_x, o.position_y, 50, 50 };
    SDL_RenderCopy(sdl_renderer, sdl_texture_obstacle, NULL, &dstrect_);
    }

    //check if fish is alive and if not, display overlay
    if (!fish->IsAlive()){
      DisplayScoreOverlay ();
    }
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

//update the window title
void Renderer::UpdateWindowTitle(int &score, int fps) {

  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

//display of score overlay
void Renderer::DisplayScoreOverlay (){
    SDL_Surface* score_image = IMG_Load("../src/Assets/Score_Overlay.png");
    SDL_Texture *sdl_texture_score = SDL_CreateTextureFromSurface(sdl_renderer, score_image);
    if (sdl_texture_score == NULL) {
    std::cerr << "Texture of Score could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
    SDL_Rect dstrect_score = {75, 175, 500, 250 };
    SDL_RenderCopy(sdl_renderer, sdl_texture_score, NULL, &dstrect_score);
}
