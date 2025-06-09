#pragma once
#include "Time.h"
#include <vector>

class Bus {
    Time_ startTime;
    Time_ endTime;
    int routeDuration;
    int restTime;      

    std::vector<std::pair<Time_, Time_>> schedule;

public:
    Bus(Time_ start, Time_ end, int routeMin, int restMin);
    void generateSchedule();
    void printSchedule() const;
};