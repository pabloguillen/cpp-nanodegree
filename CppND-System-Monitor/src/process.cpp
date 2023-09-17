#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;


//Constructor
Process::Process (int pid) : pid_(pid), user_(LinuxParser::User(pid)),cpu_(Process::CpuUtilization()) {}


// DONE Return this process's ID
int Process::Pid() { 
  return this->Process::pid_;
}

// DONE Return this process's CPU utilization---------------
float Process::CpuUtilization() { 
  //std::cout<<"Process::CPUUtilization\n";
  std::vector<string> codes = LinuxParser::CpuUtilization(this->Process::pid_);
  float cpuutil = LinuxParser::CalcTotalTime(codes);
  return cpuutil;
}

// DONE Return the command that generated this process
string Process::Command() { 
  return LinuxParser::Command(this->Process::pid_); 
}

// DONE Return this process's memory utilization
string Process::Ram() { 
  return LinuxParser::Ram(this->Process::pid_); 
}

// DONE Return the user (name) that generated this process
string Process::User() { 
  return this->Process::user_; 
}

// DONE Return the age of this process (in seconds)
long int Process::UpTime() { 
  long int uptime = LinuxParser::UpTime()-LinuxParser::UpTime(this->Process::pid_);
  return uptime;
}




// DONE Overload the "less than" comparison operator for Process objects
//bool Process::operator<(Process const& a) const { return cpu_ < a.cpu_;}
