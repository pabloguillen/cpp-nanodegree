#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"
#include <iostream>

using std::set;
using std::size_t;
using std::string;
using std::vector;
/*You need to complete the mentioned TODOs in order to satisfy the rubric criteria "The student will be able to extract and display basic data about the system."

You need to properly format the uptime. Refer to the comments mentioned in format. cpp for formatting the uptime.*/


//Constructor



System::System () {
    //std::cout<<"System Constructor\n";
  	const vector<int>& pids = LinuxParser::Pids();
    for (const int& p : pids){
      		Process pro = Process(p);
      		if (pro.Command() != "" && pro.Ram() != "" ){
         processes_.emplace_back(pro); 
      }
    }
     sort(processes_.begin(),processes_.end(), []( Process& a, Process& b) {
    return (a.CpuUtilization() < b.CpuUtilization());});
 }


// DONE Return the system's CPU----------------------
Processor System::Cpu() { 
  Processor processor;
  //std::cout<<"System::CPU\n";
  return processor; 
}


// DONE Return a container composed of the system's processes---------
vector<Process>& System::Processes() { 
  return System::processes_; 
}

// DONE Return the system's kernel identifier (string)----------
std::string System::Kernel() { return LinuxParser::Kernel(); }

// DONE Return the system's memory utilization----------
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// DONE Return the operating system name--------
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// DONE Return the number of processes actively running on the system---------
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// DONE Return the total number of processes on the system-------
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// DONE Return the number of seconds since the system started running-------
long int System::UpTime() { return LinuxParser::UpTime(); }
