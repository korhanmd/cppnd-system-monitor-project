#include "processor.h"
#include "linux_parser.h"

// Return the aggregate CPU utilization
float Processor::Utilization() {
    std::vector<std::string> values = LinuxParser::CpuUtilization();
    float amounts[values.size()];

    for (long unsigned int i = 0; i < values.size(); i++) {
        amounts[i] = std::stof(values[i]);
    }

    // Idle = idle + iowait
    float idle = amounts[3] + amounts[4];

    // NonIdle = user + nice + system + irq + softirq + steal
    float non_idle = amounts[0] + amounts[1] + amounts[2] + amounts[5] + amounts[6] + amounts[7];

    // Total = Idle + NonIdle
    float total = idle + non_idle;

    return (total - idle)/total;
}