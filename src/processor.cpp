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
    float prev_idle = prev_amounts[3] + prev_amounts[4];

    // NonIdle = user + nice + system + irq + softirq + steal
    float non_idle = amounts[0] + amounts[1] + amounts[2] + amounts[5] + amounts[6] + amounts[7];
    float prev_non_idle = prev_amounts[0] + prev_amounts[1] + prev_amounts[2] +
                            prev_amounts[5] + prev_amounts[6] + prev_amounts[7];

    // Total = Idle + NonIdle
    float total = idle + non_idle;
    float prev_total = prev_idle + prev_non_idle;

    // Differentiate: actual value minus the previous one
    float total_d = total - prev_total;
    float idle_d = idle - prev_idle;

    // Update previous amounts
    for (int i = 0; i < 10; i++) {
        prev_amounts[i] = amounts[i];
    }

    return (total_d - idle_d)/total_d;
}