#include <string>
#include <iostream>
#include "LongDate.h"
#include "Date.h"

using namespace std;

const string daysNames[7] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

LongDate::LongDate(int m, int d, int y) : Date(m, d, y){
    findNameDay();
}

string LongDate::getDayOfTheWeek() {
    return dayOfTheWeek;
}

void LongDate::setDayOfTheWeek(string s){
    dayOfTheWeek = s;
}

void LongDate::helpIncrement() {
   
   if ( !endOfMonth( getDay() ) ) {
      setDay(getDay() + 1); 
      
   } else {
      if ( getMonth() < 12 ) {
         setMonth(getMonth() + 1); 
         setDay(1); 
         
      } else {
         setYear(getYear() + 1); // increment year
         setMonth(1); // first month of new year
         setDay(1); // first day of new month
      } // end else
   }
   setDate(getMonth(), getDay(), getYear());
} 

void LongDate::setDate(int m, int d, int y) {
    setDay(d);
    setMonth(m);
    setYear(y);
    findNameDay();
}

void LongDate::findNameDay() {
    
    const int Zmonth = zFindMonth();
    const int Zyear = zFindYear(); 
    int ZgetDay = (getDay() + (13 * (Zmonth + 1)) / 5 + (Zyear % 100) + (Zyear % 100) / 4 + 5 - (Zyear / 100)) % 7;

    setDayOfTheWeek(daysNames[ZgetDay]);
}

int LongDate::zFindMonth() {
    
    if (getMonth() == 1) 
        return 13;
    
    if (getMonth() == 2) 
        return 14;
        
    return getMonth();
}

int LongDate::zFindYear() {
    
    if (zFindMonth() == 13 || zFindMonth() == 14) 
        return getYear() - 1;

    return getYear();
}
