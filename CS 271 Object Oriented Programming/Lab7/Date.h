#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>

class Date {
    
    private:
        unsigned int month;
        unsigned int day;
        unsigned int year;
    
    public:
        Date();
        Date(int m, int d, int y);
        void setMonth(int m);
        void setDay(int d);
        void setYear(int y);
        int getMonth();
        int getDay();
        int getYear();
        void print();
    
};

#endif
