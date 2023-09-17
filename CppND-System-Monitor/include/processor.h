#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  Processor();
  float Utilization();  // TODO: See src/processor.cpp
  
  float GetprevIdleCpuTime();
  float GetprevTotalCpuTime();
  
  void SetprevTotalCpuTime(float i);
  void SetprevIdleCpuTime(float j);

 private:
 float prevTotalCpuTime {};
 float prevIdleCpuTime {};
};

#endif