#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "LongDate.h"
#include "Date.h"

using namespace std;

int main () {
    int tempMonth, tempDay, tempYear;
    const int MINYEAR = 1980;
    const int MAXYEAR = 2100;
    const int MAXMONTH = 12;
    const int MAXDAY = 31;
    
    srand(time(NULL));
    
    // Create a random date for to test with
    tempMonth = rand() % MAXMONTH + 1;
    tempDay = rand() % MAXDAY + 1;
    tempYear = rand() % (MAXYEAR - MINYEAR + 1) + MINYEAR;
    
    // Create a LongDate Objects
    LongDate testDate = LongDate(tempMonth, tempDay, tempYear);
    
    cout << testDate.getDayOfTheWeek() << " ";
    cout << testDate << endl << endl;
    
    cout << "Test helpIncrement" << endl;
    
    for (int i = 1; i <= 5; i++ ) {
        testDate.helpIncrement();
        cout << testDate.getDayOfTheWeek() << " ";
        cout << testDate << endl;
    }
}
