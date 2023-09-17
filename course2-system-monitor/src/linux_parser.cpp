#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cassert>
#include <iostream>
#include <stdexcept>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

//Linux /proc/[pid]/stat information
  //process id
  std::string pid;
  
  //file name of executable (in () )
  std::string com;
  
  //state
  std::string state;
  
  //ppid - The PID of the parent of this process.
  std::string ppid;
  
  //pgrp - The process group ID of the process.
  std::string pgrp;
  
  //session - The session ID of the process.
  std::string session;
  
  //The controlling terminal of the process. 
  std::string tty_nr;
  
  //The ID of the foreground process group of the controlling terminal of the process.
  std::string tpgid;
  
  //The kernel flags word of the process.
  std::string flags;
  
  //The number of minor faults the process has made which have not required loading a memory   page from disk.
  std::string minflt;
  
  
  //The number of minor faults that the process's waited-for children have made.
  std::string cminflt;
  
  //The number of major faults the process has made  which have required loading a memory 	   page from disk.
  std::string majflt;
  
  //The number of major faults that the process's waited-for children have made.
  std::string cmajflt;
  
  // Amount of time that this process has been scheduled in user mode, measured in clock       ticks
  std::string utime_;
  
  //Amount of time that this process has been scheduled in kernel mode, measured in clock ticks
  std::string stime_;
  
  //Amount of time that this process's waited-for children have been scheduled in user mode,   measured in clock ticks
  std::string cutime_;
  
  //Amount of time that this process's waited-for children have been scheduled in kernel      	mode,measured in clock ticks
  std::string cstime_;
  
  //For processes running a real-time scheduling policy (policy below; see   sched_setscheduler(2)), this is the negated scheduling priority, minus one; that is, a 	number in the range -2 to -100, corresponding to real-time priorities 1 to 99.
  std::string priority;
  
  //The nice value (see setpriority(2)), a value in the range 19 (low priority) to -20 (high priority).
  std::string nce;
  
  // Number of threads in this process (since Linux 2.6).
  std::string num_threads;
  
  //The time in jiffies before the next SIGALRM is sent to the process due to an interval timer. 
  std::string itrealvalue;
  
  //The time the process started after system boot. In kernels before Linux 2.6, this value was expressed in jiffies.
  std::string starttime;
  
  //leftover numbers
  std::string leftover;
  


// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  
  //test
  //std::cout << "LinuxParser::OperatingSystem built";
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  //std::cout << "LinuxParser::OperatingSystem built";
  string os, kernel, version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  stream.close();
  return kernel;
}


// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}



//Done Read and return the system memory utilization--------
float LinuxParser::MemoryUtilization() { 
  //std::cout<<"LinuxParser::MemoryUtilization start\n";
  string line;
  string key;
  string value;
  string kb;
  float totalusedmemory = 0.0;
  float memTotal = 0.0;
  float memFree = 0.0;
  std::ifstream filestream(kProcDirectory+kMeminfoFilename);
  if (filestream.is_open()) {
  //std::cout<<"LinuxParser::MemoryUtilization before while loop\n";
    while (std::getline(filestream, line)) {
      std::remove(line.begin(), line.end(), ' ');
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value){
        if (key == "MemTotal") {
          memTotal = std::stof(value);
          //std::cout<<memTotal<<"\n";
        }
        else if (key == "MemFree"){
          memFree = std::stof(value);
          //std::cout<<memFree<<"\n";
          break;
        } 
      }
    } 
    totalusedmemory = ((memTotal-memFree)/memTotal);
    //std::cout<<"LinuxParser::MemoryUtilization end\n";
  }
  filestream.close();
  return totalusedmemory;
}





// DONE Read and return the system uptime------
long LinuxParser::UpTime() { 
  std::string line;
  std::string uptime;
  std::ifstream ftream(kProcDirectory+kUptimeFilename);
  if (ftream.is_open()) {
      while (std::getline(ftream, line)){
      std::istringstream linestream(line);
      while(linestream >> uptime){ 
        try {
          return std::stol(uptime);
        } catch (const std::invalid_argument& arg) {
          return 0;
        }
    	
      }
    }
  }
  return 0; 
}








// DONE Read and return the number of jiffies for the system-------
long LinuxParser::Jiffies() { 
  string cpu, user, nice_, system_, idle, iowait, irq, softirq, steal, guest, guestnice;
  std::ifstream flstream(kProcDirectory+kStatFilename);
  if (flstream.is_open()){
    string line;
    std::getline(flstream, line);
    std::istringstream linestream(line);
    while (linestream >> cpu >> user >> nice_ >> system_ >> idle >> iowait >> irq >> softirq >> steal >> guest>>guestnice){
      try {
       return std::stol(user) + std::stol(nice_)+std::stol(system_)+std::stol(idle)+std::stol(iowait)+std::stol(irq)+std::stol(softirq)+std::stol(steal)+std::stol(guest);
      } catch (const std::invalid_argument& arg){
       return 0; 
      }  
    }
  }
  return 0; 
}


// DONE Read and return the number of active jiffies for a PID--------
long LinuxParser::ActiveJiffies(int pid_) { 
  pid = std::to_string(pid_);
  std::string line;
  std::ifstream flstream(kProcDirectory+pid+kStatFilename);
  std::string terminal {""};
  if (flstream.is_open()) {
    while (std::getline(flstream, line)) {
          terminal += line;
    } 
    std::istringstream linestream(terminal);
      while(linestream >> pid >> com >> state >> ppid >> pgrp >> session >> tty_nr >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt >>utime_ >> stime_ >> cutime_ >> cstime_)       {    
        try {
       return std::stol(utime_)+std::stol(stime_);
       } catch (const std::invalid_argument& arg){
       return 0; 
      }  
     }             
    }
   return 0;
}



  
// DONE Read and return the number of active jiffies for the system-----
long LinuxParser::ActiveJiffies() { 
  string cpu, user, nice_, system_, idle, iowait, irq, softirq, steal, guest;
  std::ifstream ifstream(kProcDirectory+kStatFilename);
  if (ifstream.is_open()){
    string line;
    std::getline(ifstream, line);
    std::istringstream linestream(line);
    while (linestream >> cpu >> user >> nice_ >> system_ >> idle >> iowait >> irq >> softirq >> steal >> guest){
    try {
    return std::stol(user) + std::stol(nice_)+std::stol(system_);
    } catch (const std::invalid_argument& arg){
       return 0; 
      }  
    }
  }
  return 0; 
}
  

// DONE Read and return the number of idle jiffies for the system------
long LinuxParser::IdleJiffies() { 
  string cpu, user, nice_, system_, idle, iowait, irq, softirq, steal, guest;
  std::ifstream ifistream(kProcDirectory+kStatFilename);
  if (ifistream.is_open()){
    string line;
    std::getline(ifistream, line);
    std::istringstream linestream(line);
    while (linestream >> cpu >> user >> nice_ >> system_ >> idle >> iowait >> irq >> softirq >> steal >> guest){
    try {
    return std::stol(idle);
     } catch (const std::invalid_argument& arg){
       return 0; 
      }  
    }
  }
  return 0; 
}



//test!!!!

// DONE Read and return CPU utilization----------
vector<string> LinuxParser::CpuUtilization(const int pid_) { 
  vector<string> codes {};
  pid = std::to_string(pid_);
  std::string line;
  std::ifstream ifilestream(kProcDirectory+pid+kStatFilename);
  std::string terminal {""};
  if (ifilestream.is_open()) {
    while (std::getline(ifilestream, line)) {
        terminal += line;
    }
      std::istringstream linestream(terminal);
      while(linestream >> pid >> com >> state >> ppid >> pgrp >> session >> tty_nr >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt >>utime_ >> stime_ >> cutime_ >> cstime_ >> priority >> nce >> num_threads >> itrealvalue >> starttime){      
    try { 
    float utime = std::stof(utime_)/sysconf(_SC_CLK_TCK);
	codes.emplace_back(std::to_string(utime)); //1
    float stime = std::stof(stime_)/sysconf(_SC_CLK_TCK);
    codes.emplace_back(std::to_string(stime)); //1
    float cutime = std::stof(cutime_)/sysconf(_SC_CLK_TCK);
    codes.emplace_back(std::to_string(cutime)); //9
    float cstime = std::stof(cstime_)/sysconf(_SC_CLK_TCK);
    codes.emplace_back(std::to_string(cstime)); //8
    float starttime_ = std::stof(starttime)/sysconf(_SC_CLK_TCK);
    codes.emplace_back(std::to_string(starttime_)); //45052
    return codes;
    } catch (const std::invalid_argument& arg){
       return codes; 
       }    
      }
    }   
  	return codes;
  } 
  
   //test
   //helper function
 float LinuxParser::CalcTotalTime(vector<string> codes){
   
    float utime_ {std::stof(codes[0])};
    float stime_ {std::stof(codes[1])};
    float cutime_ {std::stof(codes[2])}; 
    float cstime_ {std::stof(codes[3])};
    float starttime_ {std::stof(codes[4])};
    float cpu_usage;
   
   	//Long is fine?
    auto uptime_ = LinuxParser::UpTime();
   
   float total_time = utime_ + stime_;
   total_time = total_time + cutime_ + cstime_;
   float hertz = sysconf(_SC_CLK_TCK);
   float seconds = uptime_ - (starttime_ / hertz);
   return cpu_usage = 100 * ((total_time/hertz)/seconds);
 }
         


// DONE Read and return the total number of processes------
int LinuxParser::TotalProcesses() {
  string line;
  string key;
  string value;
  std::ifstream iffilestream(kProcDirectory+kStatFilename);
  if (iffilestream.is_open()) {
    while (std::getline(iffilestream, line)) {
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "processes") {
          try {
            return std::stoi(value);
          } catch (const std::invalid_argument& arg){
            std::cout<<"Error LinuxParser::TotalProcesses";
            return 0; 
          }  
        }
      }
    }
  }
  //std::cout<<"Error LinuxParser::TotalProcesses";
  return 0;
}
  




// DONE Read and return the number of running processes-------
int LinuxParser::RunningProcesses() {
  string line;
  string key1;
  string value;
  std::ifstream sfilestream(kProcDirectory+kStatFilename);
  if (sfilestream.is_open()) {
    while (std::getline(sfilestream, line)) {     
      std::istringstream linestream(line);
      linestream >> key1 >> value;
        if (key1 == "procs_running") {
          try {
            return std::stoi(value);
          } catch (const std::invalid_argument& arg){
            std::cout<<"Error LinuxParser::RunningProcesses";
            return 10; 
          }     
        }
     }
  }
  //std::cout<<"Error LinuxParser::RunningProcesses";
  return 10;
}






// DONE Read and return the command associated with a process------

string LinuxParser::Command(int pid) {
  string commandline;
  std::ifstream isfilestream(LinuxParser::kProcDirectory+std::to_string(pid)+LinuxParser::kCmdlineFilename);
  if (isfilestream.is_open()) {
    std::getline(isfilestream, commandline);
    return commandline;
     }
  //std::cout<<"Error LinuxParser::Command";
  return "";
}



// DONE Read and return the memory used by a process
string LinuxParser::Ram(int pid) { 
  string line;
  string key;
  string value = "";
  string kb;
  std::ifstream isffilestream(kProcDirectory+std::to_string(pid)+kStatusFilename);
  if (isffilestream.is_open()) {
    while (std::getline(isffilestream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "VmSize") {
          return value;
        }
      }
    }
  }
  //std::cout<<"Error LinuxParser::RAM";
  return value;
}




 


// DONE Read and return the user ID associated with a process
string LinuxParser::Uid(int pid) {
  string line;
  string key;
  string value;
  std::ifstream fs (kProcDirectory+std::to_string(pid)+kStatusFilename);
  if (fs.is_open()) {
    while (std::getline(fs, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "Uid") {
          return value;
        }
      }
    }
  }
  //std::cout<<"Error LinuxParser::Uid";
  return "";
}






// DONE Read and return the user associated with a process
string LinuxParser::User(int pid) { 
  string line;
  string user;
  string variable;
  string uid;
  std::ifstream fst(kPasswordPath);
  if (fst.is_open()) {
    while (std::getline(fst, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while (linestream >> user >> variable >> uid) {
        if (uid == LinuxParser::Uid(pid)) {
          return user;
        }
      }
    }
  }
  return "";
}
 


  
  
//__________________________Need to be corrected

//umwandeln in Uhrzeit

// DONE Read and return the uptime of a process
long LinuxParser::UpTime(int pid_) { 
  pid = std::to_string(pid_);
  long result;
  string key;
  std::ifstream filestream(kProcDirectory+pid+kStatFilename);
  if (filestream.is_open()) {
          std::string line;
    while (std::getline(filestream, line)) {
        std::istringstream linestream(line);
        for (int i = 1; i <= 22; i++){
          linestream >> key;
          if (i == 22){
            try {
            result = std::stol(key)/sysconf(_SC_CLK_TCK);
          } catch (const std::invalid_argument& arg) {
            result = 0;
           }
          }
        }
      } 
    }
    //std::cout<<"Error LinuxParser::UpTime";
  	return result;
  } 



