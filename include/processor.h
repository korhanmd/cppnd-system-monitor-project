#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();

 private:
  float prev_amounts[10] {0,0,0,0,0,0,0,0,0,0};
};

#endif