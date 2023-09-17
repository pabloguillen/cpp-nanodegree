#ifndef GAME_H
#define GAME_H

#include <random>
#include "controller.h"
#include "renderer.h"
#include "fish.h"
#include "obstacle.h"
#include <vector>
#include <mutex>
#include <memory>

class Game {
 public:

  //Constructor
  Game(std::size_t kScreenWidth, std::size_t kScreenHeight);

  //Basic Run function
  void Run(Controller &&controller, std::unique_ptr<Renderer> &&renderer, std::size_t target_frame_duration);

  //Return score of game
  int GetScore() const;

  //Mutex to lock/unlock asynchronous access to member variable _fish 
  std::mutex mtx;

 private:

  //basic member variables/game assets
  std::unique_ptr<Fish> _fish;
  std::vector<Obstacle> _obstacles {};

  //Screen size
  std::size_t _screen_width;
  std::size_t _screen_height;


  //Score of Game starting from zero
  int score{0};

  //main update function
  void Update();

  //Check if obstacles can be launched
  bool ObstacleLaunch ();

  //updates the score
  void UpdateScore ();

};

#endif