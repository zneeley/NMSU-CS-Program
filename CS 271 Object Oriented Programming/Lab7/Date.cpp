#include "Date.h"
#include <iostream>
#include <iomanip>
#define DEFAULTDAY 1
#define DEFAULTMONTH 1
#define DEFAULTYEAR 1980

using namespace std;

Date::Date() {
    day = DEFAULTDAY;
    month = DEFAULTMONTH;
    year = DEFAULTYEAR;
}

Date::Date(int m, int d, int y) {
    setMonth(m);
    setDay(d);
    setYear(y);
}

void Date::setMonth(int m) {
    const int minMonth = 1;
    const int maxMonth = 12;
    
    if ( m >= minMonth && m <= maxMonth)
        month = m;
}

void Date::setDay(int d) {
    const int monthDays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    const int minDays = 0;
    
    if (d >= minDays && d <= monthDays[getMonth()])
        day = d;
}

void Date::setYear(int y) {
    const int minYear = 1980;
    const int maxYear = 2100;
    
    if (y >= minYear && y <= maxYear)
        year = y;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

int Date::getYear() {
    return year;
}

void Date::print() {
    cout << setw(2) << setfill('0') << getMonth() << "/" << setw(2) << setfill('0') << getDay() << "/" << setw(4) << setfill('0') << getYear() << endl;
}
