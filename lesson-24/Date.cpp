#include "Date.h"

Date::Date()
{
    auto sec = time(0);
    tm* obj = new tm;
    localtime_s(obj, &sec);
    day = obj->tm_mday;
    month = obj->tm_mon + 1;
    year = obj->tm_year + 1900;
    delete obj;
}

Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

bool Date::isLeapYear() const
{
    return year % 4==0&&year%100!=0||year%100==0&&year%400==0;
}

int Date::monthDays() const
{
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 2:
        return isLeapYear() ? 29 : 28;
    case 4: case 6: case 9: case 11:
        return 30;
    }
    return 0;
}

void Date::nextDate()
{
    if (day == 31 && month == 12) {
        day = 1;
        month = 1;
        year++;
    }
    else if (day == monthDays()) {
        month++;
        day = 1;
    }
    else {
        day++;
    }
}

void Date::prevDate()
{
    if (day == 1 && month == 1) {
        day = 31;
        month = 12;
        year--;
    }
    else if (day == 1) {
        month--;
        day = monthDays();
    }
    else {
        day--;
    }
}

void Date::setYear(int year)
{
    this->year = year;
}

int Date::getYear() const
{
    return year;
}

void Date::setMonth(int month)
{
    if(month>=1&&month<=12) this->month=month;
}

int Date::getMonth() const
{
    return month;
}

void Date::setDay(int day)
{
    if (day >= 1 && day <= monthDays()) this->day = day;
}

int Date::getDay() const
{
    return day;
}

void Date::showDate() const
{
    cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
}

bool Date::valid() const
{
    return month>=1&&month<=12 &&day>=1&&day<=monthDays();
}

bool Date::operator==(const Date& obj) const&
{
    return (this->day==obj.day&&this->month==obj.month&&this->year==obj.year);
}

bool Date::operator!=(const Date& obj) const&
{
    return !(*this == obj);
}

bool Date::operator>(const Date& obj) const&
{
    if (this->year > obj.year) {
        return true;
    }
    else if (this->year == obj.year && this->month > obj.month) {
        return true;
    }
    else if (this->year == obj.year && this->month == obj.month && this->day > obj.day) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::operator<(const Date& obj) const&
{
    return !(*this>obj)&&*this!=obj;
}

bool Date::operator>=(const Date& obj) const&
{
    return (*this > obj || *this == obj);
}

bool Date::operator<=(const Date& obj) const&
{
    return (*this < obj || *this == obj);
}

Date& Date::operator+=(int days)
{
    for (int i = 0; i < days; i++) {
        this->nextDate();
    }
    return *this;
}

Date& Date::operator-=(int days)
{
    for (int i = 0; i < days; i++) {
        this->prevDate();
    }
    return *this;
}

Date& Date::operator+=(float months)
{
    this->month += months;
    if (this->month > 12) {
        this->year += (this->month-1) / 12;
        this->month = this->month % 12;
    }
    return *this;
}

Date& Date::operator-=(float months)
{
    this->month - +months;
    if (this->month < 0) {
        this->year -= (12 - this->month) / 12;
        this->month = (12 + this->month) % 12;
    }
    return *this;
}

Date& Date::operator+=(long years)
{
    this->year += years;
    return *this;
}

Date& Date::operator-=(long years)
{
    this->year -= years;
    return *this;
}

Date& Date::operator--()
{
    this->prevDate();
    return *this;
}

Date Date::operator--(int)
{
    Date tmp = *this;
    this->prevDate();
    return tmp;
}

Date& Date::operator++()
{
    this->nextDate();
    return *this;
}

Date Date::operator++(int)
{
    Date tmp = *this;
    this->nextDate();
    return tmp;
}

Date operator+(int days, const Date& a)
{
    return a+days;
}

Date operator-(int days, const Date& a)
{
    return a-days;
}

Date operator+(float months, const Date& a)
{
    return a+months;
}

Date operator-(float months, const Date& a)
{
    return a-months;
}

Date operator+(long years, const Date& a)
{
    return a+years;
}

Date operator-(long years, const Date& a)
{
    return a-years;
}

ostream& operator<<(ostream& os, const Date& t)
{
    os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year;
    return os;
}

istream& operator>>(istream& is, Date& t)
{
    do {
        cout << "DD MM YYYY: ";
        is >> t.day >> t.month >> t.year;
        
    } while (!t.valid());
    return is;

}

Date Date::operator+(int days) const&
{
    Date tmp = *this;
    tmp += days;
    return tmp;
}

Date Date::operator-(int days) const&
{
    Date tmp = *this;
    tmp -= days;
    return tmp;
}

Date Date::operator+(float months) const&
{
    Date tmp = *this;
    tmp += months;
    return tmp;
}

Date Date::operator-(float months) const&
{
    Date tmp = *this;
    tmp += months;
    return tmp;
}

Date Date::operator+(long years) const&
{
    Date tmp = *this;
    tmp += years;
    return tmp;
}

Date Date::operator-(long years) const&
{
    Date tmp = *this;
    tmp += years;
    return tmp;
}