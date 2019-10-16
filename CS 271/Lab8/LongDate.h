#ifndef LONGDATE_H
#define LONGDATE_H

#include <string>
#include "Date.h"

using namespace std;

class LongDate : public Date{
  
    private:
        string dayOfTheWeek;
        
    public:
        LongDate(int m, int d, int y);
        string getDayOfTheWeek();
        void setDayOfTheWeek (string s);
        void helpIncrement();
        void setDate(int, int, int);
        void findNameDay();
        int zFindYear();
        int zFindMonth();
};

#endif
