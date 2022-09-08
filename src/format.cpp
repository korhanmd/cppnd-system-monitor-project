#include <string>

#include "format.h"

using std::string;

// Convert seconds to HH:MM:SS format
string Format::ElapsedTime(long seconds) {
    int hours, minutes;

    hours = seconds/3600;
    seconds %= 3600;
    minutes = seconds/60;
    seconds %= 60;

    string minutes_str = std::to_string(minutes);
    string seconds_str = std::to_string(seconds);

    return std::to_string(hours) + ":" + string(2 - minutes_str.length(), '0') + minutes_str + ":" + string(2 - seconds_str.length(), '0') + seconds_str;
}