#include "Time.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdexcept>

using namespace std;

Time_::Time_() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    hour = ltm.tm_hour;
    minutes = ltm.tm_min;
    seconds = ltm.tm_sec;
    format = true;
}

Time_::Time_(int h, int m, int s, bool f) : hour(h), minutes(m), seconds(s), format(f) {
    if (!valid()) throw invalid_argument("Invalid time");
}

Time_::Time_(const Time_& obj) = default;
Time_& Time_::operator=(const Time_& obj) = default;
Time_::~Time_() = default;

void Time_::setHour(int h) { hour = h; }
int Time_::getHour() const { return hour; }

void Time_::setMinutes(int m) { minutes = m; }
int Time_::getMinutes() const { return minutes; }

void Time_::setSeconds(int s) { seconds = s; }
int Time_::getSeconds() const { return seconds; }

void Time_::setFormat(bool f) { format = f; }
bool Time_::getFormat() const { return format; }

bool Time_::valid() const {
    if (format) return (hour >= 0 && hour < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
    else return (hour >= 1 && hour <= 12 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
}

void Time_::tickTime() {
    *this += 1;
}

void Time_::untickTime() {
    *this -= 1;
}

void Time_::showTime() const {
    if (!valid()) {
        cout << "Invalid time\n";
        return;
    }
    if (format) {
        cout << setfill('0') << setw(2) << hour << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds << " (24h)" << endl;
    }
    else {
        int h = hour % 12;
        if (h == 0) h = 12;
        cout << setfill('0') << setw(2) << h << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds << (hour >= 12 ? " PM" : " AM") << endl;
    }
}

bool Time_::operator==(const Time_& obj) const& {
    return hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds;
}

bool Time_::operator!=(const Time_& obj) const& {
    return !(*this == obj);
}

bool Time_::operator<(const Time_& obj) const& {
    if (hour != obj.hour) return hour < obj.hour;
    if (minutes != obj.minutes) return minutes < obj.minutes;
    return seconds < obj.seconds;
}

bool Time_::operator>(const Time_& obj) const& {
    return obj < *this;
}

bool Time_::operator<=(const Time_& obj) const& {
    return !(*this > obj);
}

bool Time_::operator>=(const Time_& obj) const& {
    return !(*this < obj);
}

int toSeconds(const Time_& t) {
    return t.hour * 3600 + t.minutes * 60 + t.seconds;
}

void fromSeconds(Time_& t, int total) {
    total = (total + 86400) % 86400; 
    t.hour = total / 3600;
    t.minutes = (total % 3600) / 60;
    t.seconds = total % 60;
}

Time_& Time_::operator+=(int s) {
    int total = toSeconds(*this) + s;
    fromSeconds(*this, total);
    return *this;
}

Time_& Time_::operator-=(int s) {
    return *this += -s;
}

Time_& Time_::operator+=(float m) {
    return *this += static_cast<int>(m * 60);
}

Time_& Time_::operator-=(float m) {
    return *this += static_cast<int>(-m * 60);
}

Time_& Time_::operator+=(long h) {
    return *this += static_cast<int>(h * 3600);
}

Time_& Time_::operator-=(long h) {
    return *this += static_cast<int>(-h * 3600);
}

Time_ Time_::operator+(int s) const& {
    Time_ result = *this;
    result += s;
    return result;
}

Time_ Time_::operator-(int s) const& {
    Time_ result = *this;
    result -= s;
    return result;
}

Time_ Time_::operator+(float m) const& {
    Time_ result = *this;
    result += m;
    return result;
}

Time_ Time_::operator-(float m) const& {
    Time_ result = *this;
    result -= m;
    return result;
}

Time_ Time_::operator+(long h) const& {
    Time_ result = *this;
    result += h;
    return result;
}

Time_ Time_::operator-(long h) const& {
    Time_ result = *this;
    result -= h;
    return result;
}
