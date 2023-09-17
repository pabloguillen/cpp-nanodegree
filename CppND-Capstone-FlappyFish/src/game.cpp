#include "game.h"
#include <iostream>
#include <thread>
#include <time.h>
#include <chrono>
#include <thread>
#include <future>

//Constructor
Game::Game(std::size_t kScreenWidth, std::size_t kScreenHeight)
     : _fish(std::make_unique<Fish>(kScreenWidth, kScreenHeight)),
       _screen_width (kScreenWidth),
       _screen_height (kScreenHeight) {}

//set initial obstacle speed
float Obstacle::speed = 0.1f;


//Basic run function
void Game::Run(Controller &&controller, std::unique_ptr<Renderer> &&renderer, //Controller &&controller, Renderer &&renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  //creates task for updating the score asynchronously
  auto ftr = std::async(std::launch::async, &Game::UpdateScore,&(*this));

  //Main game loop - Input, Update, Render.
  while (running) {

    frame_start = SDL_GetTicks();

    //lock mutex and block access to _fish
    mtx.lock();
    
    
    //terminate game after crash or out-of-range. Pause for 2 seconds to display overlay.
    if (!_fish->IsAlive()) {
    running = false;
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    mtx.unlock();
    break;
  }

    //Input handler
    controller.HandleInput(running, _fish);

    //update fish and obstacles
    Update();

    //fender
    renderer->Render(_fish, _obstacles);

    //unlock mutex and unblock access to _fish
    mtx.unlock();

    frame_end = SDL_GetTicks();

    //keeps track of how long each loop through the input/update/render cycle takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    //update the window title after every second
    if (frame_end - title_timestamp >= 1000) {
      renderer->UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

//check whether Obstacles can be launched based on x position of launched obstacles
bool Game::ObstacleLaunch (){

  //check if vector size is bigger than 0
  if (_obstacles.size() != 0){
  
  //check x position of each obstacle in vector
  for (auto &o : _obstacles){
    if (o.position_x >= (_screen_width/3)*2){
      //if x position is bigger than 2/3 of screen width, no object shall be launched
      return false;
    }
   }
  }

  //if no obstacle has x position bigger than 2/3 of screen width, object shall be launched
  return true;
}

//Basic game update function
void Game::Update() {


    //check if fish is alive
    if (!_fish->IsAlive()) {
      //if not, stop update and return
      return;
  }
  
  //update of fish
  _fish->Update();
 

   //check if obstacle vector is bigger than zero
   if (_obstacles.size() != 0){

      //loop over obstacles vector
      for (auto &o : _obstacles){

        //check if obstacle position is smaller than zero/out of screen
        if (o.position_x < 0){

          //if so, erase object 
          _obstacles.erase(_obstacles.begin());

        //check if Obstacle crashed with fish
        } else if (o.CheckCrash(_fish)){

          //if so, set fish state to false
            _fish->SetState (false);
        } else {

          //if no crash, update obstacle
        o.Update();
        }
      }
    }      

    if (this->ObstacleLaunch()){
      
      //creation of obstacle
      Obstacle obstac (_screen_width, _screen_height);

       //place obstacle in vector, using push_back to exploit move semantics
      _obstacles.push_back(obstac);
      }
  }

//Getter: Returns game score, called in main
int Game::GetScore() const { return score; }

//update game score asynchronously every second
void Game::UpdateScore (){
    double timecount = 0;

    //get current number of clock ticks
    clock_t curr_time = clock();

    //set current time of clock ticks to last time
    clock_t last_time = curr_time;
    while (true){

      //lock mutex to block access to _fish via lock guard object 
      std::lock_guard<std::mutex> lock(mtx);
      
      if (!_fish->IsAlive()){
        //if fish is not alive, break loop and not update score
        break;
      }

      //get current number of clock ticks
      clock_t curr_time = clock();

      //get difference from last time and current time in clock ticks
      timecount += (double) (curr_time - last_time);

      //update current time as last time
      last_time = curr_time;

      //Check if timecount is bigger than system clocks per second to block until one second is passed
      if (timecount > (double) CLOCKS_PER_SEC){

        //reset timecount
        timecount -= CLOCKS_PER_SEC;

        //update the score as one second is passed
        score ++;
      }
    }
  }