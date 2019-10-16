#include "Date.h"
#include "Time.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    Time arrayTime[5];
    Date arrayDate[5];
    const int MAXHOUR = 23;
    const int MAXMINUTE = 59;
    const int MAXSECOND = 59;
    const int ARRAYSIZE = 5;
    const int MINYEAR = 1980;
    const int MAXYEAR = 2100;
    const int MAXMONTH = 12;
    const int MAXDAY = 31;
    int tempHour, tempMinute, tempSecond;
    int tempMonth, tempDay, tempYear;
    
    srand(time(NULL));
    
    //
    // Test Time.cpp
    //
    
    for (int i = 1; i <= ARRAYSIZE; i++) {
        tempHour = rand() % MAXHOUR + 1;
        tempMinute = rand() % MAXMINUTE + 1;
        tempSecond = rand() % MAXSECOND + 1;
        
        arrayTime[i] = Time(tempHour, tempMinute, tempSecond);
    }
    
    cout << "Military Time" << endl;
    
    for (int i = 1; i <= ARRAYSIZE; i++) {
        arrayTime[i].print();
    }
    
    cout << endl << "Standard Time" << endl;
    
    for (int i = 1; i <= ARRAYSIZE; i++) {
        arrayTime[i].print12();
    }
    
    //
    // Test Date.cpp
    //
    
    for (int i = 1; i <= ARRAYSIZE; i++) {
        tempMonth = rand() % MAXMONTH + 1;
        tempDay = rand() % MAXDAY + 1;
        tempYear = rand() % (MAXYEAR - MINYEAR + 1) + MINYEAR;
        
        arrayDate[i] = Date(tempMonth, tempDay, tempYear);
    }
    
    cout << endl << "Dates" << endl;
    for (int i = 1; i <= ARRAYSIZE; i++) {
        arrayDate[i].print();
    }
}
