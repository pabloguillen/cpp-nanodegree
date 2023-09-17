#include <string>

#include "format.h"

using std::string;

// DONE: Complete this helper function--------
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
  string time = "00:00:00";
  long t = 0;
  if (seconds > 0) {
    // calculate hours
    t = seconds / 3600;
    time = TimeToString(t) + ":";
    // calculate minutes
    t = (seconds / 60) % 60;
    time += TimeToString(t) + ":";
    // calculate seconds
    t = seconds % 60;
    time += TimeToString(t);
  }

  return time;
}

std::string Format::TimeToString(long time) {
  if (time < 10)
    return "0" + std::to_string(time);
  else
    return std::to_string(time);
}