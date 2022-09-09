#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();

 private:
  float prev_total {0.0};
  float prev_idle {0.0};
};

#endif