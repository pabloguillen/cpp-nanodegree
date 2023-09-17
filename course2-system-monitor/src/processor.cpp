#include "processor.h"
#include "linux_parser.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using std::string;

Processor::Processor() {
  prevTotalCpuTime =0.0; 
  prevIdleCpuTime =0.0;
}

//DONE Return the aggregate CPU utilization-------
float Processor::Utilization() { 
  //std::cout<<this->prevTotalCpuTime<<" & "<<this->prevIdleCpuTime<<"\n";
  
  string key, user, nice_, system_, idle, iowait, irq, softirq, steal, guest, guestnice;
  string line;
  std::ifstream filestream(LinuxParser::kProcDirectory+LinuxParser::kStatFilename);
  //std::cout<<"before read in\n";
  if (filestream.is_open()){
    while (std::getline(filestream, line)){
    std::istringstream sstream(line);
    //std::cout<<"line: "<<line<<"\n";
    
    while (sstream >> key >> user >> nice_ >> system_ >> idle >> iowait >> irq >> softirq >>         steal >> guest >> guestnice){
     // std::cout<<guestnice<<"\n";
      if (key == "cpu"){
     float usertime, nice_time, systemtime, idletime, iowaittime, irqtime, softirqtime,           stealtime, guesttime, guestnicetime;

    //std::cout<<"Error User";
    //try {
    usertime = std::stof(user);
    //} catch (const std::invalid_argument& arg){
      //      std::cout<<"Error User";
    //} 
      
    //try { 
    //std::cout<<"Error Nice";
    nice_time = std::stof(nice_);
    //catch (const std::invalid_argument& arg){
    //        std::cout<<"Error Nice";
    //}  
      
    //try { 
    //std::cout<<"Error System";
    systemtime = std::stof(system_);
    //} catch (const std::invalid_argument& arg){
      //      std::cout<<"Error system";
    //} 
      
    //try {
    //std::cout<<"Error Idle";
    idletime = std::stof(idle);
    //} catch (const std::invalid_argument& arg){
    //        std::cout<<"Error idle";
    //} 
    
    //try {
    //std::cout<<"Error iowait";
    iowaittime = std::stof(iowait);
    //} catch (const std::invalid_argument& arg){
    //        std::cout<<"Error iowait";
    //}  
      
    //try {
    //std::cout<<"Error irq";
    irqtime = std::stof(irq);
    //} catch (const std::invalid_argument& arg){
    //        std::cout<<"Error irq";
    //} 
      
    //try { 
    //std::cout<<"Error softirq";
    softirqtime = std::stof(softirq);
     //} catch (const std::invalid_argument& arg){
      //      std::cout<<"Error softirq";
    //} 
      
    //try { 
    //std::cout<<"Error steal";
    stealtime = std::stof(steal);
    //} catch (const std::invalid_argument& arg){
    //        std::cout<<"Error steal";
    //}  
    
    //try {
    //std::cout<<"Error guesttime";
    guesttime = std::stof(guest);
    //} catch (const std::invalid_argument& arg){
    //        std::cout<<"Error guesttime";
    //} 
      
    //try { 
    //std::cout<<"Error guestnice";
    guestnicetime = std::stof(guestnice);
    //} catch (const std::invalid_argument& arg){
    //        std::cout<<"Error guestnice";
    //} 
      
    float totalcputime;
    totalcputime = usertime + nice_time + systemtime + idletime + iowaittime + irqtime + softirqtime + stealtime + guesttime + guestnicetime;
       
    float idleCpuTime;
    idleCpuTime = idletime + iowaittime;
    
    
    float diffIdle, diffTotal, diffUsage;
    diffIdle  = idleCpuTime - Processor::GetprevIdleCpuTime();
    diffTotal = totalcputime - Processor::GetprevTotalCpuTime();
        
    diffUsage = (diffTotal - diffIdle) / diffTotal;
    
    //std::cout<<"before reset\n";
    Processor::SetprevTotalCpuTime(totalcputime);
    Processor::SetprevIdleCpuTime(idleCpuTime);
    
    
    //std::cout<<"before return\n";
    return diffUsage;
       }
      }
     }
  }
  return 0.0;
}


  float Processor::GetprevIdleCpuTime() {return Processor::prevIdleCpuTime;}
  float Processor::GetprevTotalCpuTime(){return Processor::prevTotalCpuTime;}
  
  void Processor::SetprevTotalCpuTime(float i){ 
      this->prevTotalCpuTime = i;
  }
    
    
  void Processor::SetprevIdleCpuTime(float j){
     this->prevIdleCpuTime = j;
  }