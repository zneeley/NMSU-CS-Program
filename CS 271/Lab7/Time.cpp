#include "Time.h"
#include <iostream>
#include <iomanip>
#define DEFAULT 0

using namespace std;

Time::Time() {
    hour = DEFAULT;
    minute = DEFAULT;
    second = DEFAULT;
}

Time::Time(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void Time::setHour(int h) {
    const int maxHour = 23;
    const int minHour = 0;
    
    if (h >= minHour && h <= maxHour) 
        hour = h;
}

void Time::setMinute(int m) {
    const int maxMin = 59;
    const int minMin = 0;
    
    if (m >= minMin && m <= maxMin) 
        minute = m;
}

void Time::setSecond(int s) {
    const int maxSec = 59;
    const int minSec = 0;
    
    if (s >= minSec && s <= maxSec) 
        second = s;
}

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

int Time::getSecond() {
    return second;
}

void Time::print() {
    cout << setw(2) << setfill('0') << getHour() << ":" << setw(2) << setfill('0') << getMinute() << ":" << setw(2) << setfill('0') << getSecond() << endl;
}

void Time::print12() {
    const int timePM = 12;
    
    if (getHour() <= timePM) {
       cout << setw(2) << setfill('0') << getHour() << ":" << setw(2) << setfill('0') << getMinute() << ":" << setw(2) << setfill('0') << getSecond() << " AM" << endl; 
    } else {
        cout << setw(2) << setfill('0') << getHour() - timePM << ":" << setw(2) << setfill('0') << getMinute() << ":" << setw(2) << setfill('0') << getSecond() << " PM" << endl; 
    }
}
