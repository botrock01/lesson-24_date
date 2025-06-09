#include "Bus.h"
#include <iostream>

using namespace std;

Bus::Bus(Time_ start, Time_ end, int routeMin, int restMin)
    : startTime(start), endTime(end), routeDuration(routeMin), restTime(restMin) {
}

void Bus::generateSchedule() {
    schedule.clear();
    Time_ departA = startTime;
    Time_ departB;

    while (true) {
        departB = departA + (float)routeDuration;

        if (departA > endTime || departB > endTime)
            break;

        schedule.emplace_back(departA, departB);

        departA = departB + (float)restTime + (float)routeDuration + (float)restTime;
    }
}

void Bus::printSchedule() const {
    cout << "Rozklad:\n";
    for (const auto& pair : schedule) {
        cout << pair.first << "  " << pair.second << endl;
    }
}