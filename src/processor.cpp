#include "processor.h"
#include "linux_parser.h"

// Return the aggregate CPU utilization
float Processor::Utilization() {
    float total = (float)LinuxParser::Jiffies();
    float idle = (float)LinuxParser::IdleJiffies();

    float total_d = total - prev_total;
    float idle_d = idle - prev_idle;

    prev_total = total;
    prev_idle = idle;

    return (total_d - idle_d)/total_d;
}