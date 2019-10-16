// Date.cpp
// Date class member- and friend-function definitions.
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

// initialize static member; one classwide copy
const int Date::days[] = 
   { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Date constructor
Date::Date( int m, int d, int y ) 
{ 
   setDate( m, d, y ); 
} // end Date constructor

// mutators

void Date::setDay( int dd ) {

    if (month == 2 && leapYear(year) )
       if (dd >= 1 && dd <= 29)
          day = dd;
       else
          day = 1; 
   else 
        if ( dd >= 1 && dd <= days[month] )
           day = dd;
        else
           day = 1;
}

void Date::setMonth( int mm ) {

   if (mm >= 1 && mm <= 12)
      month = mm;
   else 
      month = 1;
}

void Date::setYear( int yy ) {

    if (yy >= 1900 && yy <= 2100)
       year = yy;
    else
       year = 1900;
}

// set month, day and year
void Date::setDate( int mm, int dd, int yy )
{

   setYear( yy );
   setMonth( mm );
   setDay( dd );
   
} // end function setDate

// accessors
int Date::getDay( ) {
   return day;
}
int Date::getMonth( ) {
   return month;
}
int Date::getYear( ) {
   return year;
}
// overloaded prefix increment operator 
Date &   Date::operator++()
{
   helpIncrement(); // increment date
   
   return *this; 
   
   // in C++, "this" is a pointer to the calling object
   // *this dereferences the  pointer

} // end function operator++


// overloaded postfix increment operator; note that the  
// dummy integer parameter does not have a parameter name

Date   Date::operator++( int )
{
   Date temp = *this; // hold current state of object
   
   // temp has a day, a month, and year
   // *this has a day, a month, and a year
   // the assignment operator does "memberwise" assignment
   // temp.day = *this.day
   // temp.month = *this.month
   // temp.year = *this.year
   
     
   helpIncrement(); 

   // return unincremented, saved, temporary object
   
   return temp; // value return; not a reference return
   
} // end function operator++

// add specified number of days to date

// Date d1(10, 12, 2016);
// d1 += 2;

// add two days to the date in d1
// the left operand is the calling object
// the right operand is the parameter

// cout << ( d1 += 2 );

const Date &   Date::operator+=( int additionalDays )

{
   for ( int i = 0; i < additionalDays; i++ )
      helpIncrement();

   return *this; // enables cascading
   
} // end function operator+=

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear( int testYear )
{
   if ( testYear % 400 == 0 || 
      ( testYear % 100 != 0 && testYear % 4 == 0 ) )
      return true; // a leap year
   else
      return false; // not a leap year
} // end function leapYear

// determine whether the day is the last day of the month
bool Date::endOfMonth( int testDay ) const
{
   if ( month == 2 && leapYear( year ) )
      return testDay == 29; // last day of Feb. in leap year
   else
      return testDay == days[ month ];
} // end function endOfMonth

// function to help increment the date
void Date::helpIncrement()
{
   // day is not end of month
   if ( !endOfMonth( day ) )
      day++; 
   else 
      if ( month < 12 ) 
      {
         month++; 
         day = 1; 
      } 
      else // last day of year
      {
         year++; // increment year
         month = 1; // first month of new year
         day = 1; // first day of new month
      } // end else
} // end function helpIncrement

// overloaded output operator
ostream &operator<<( ostream &output, const Date &d )
{
   static string monthName[ 13 ] = { "", "January", "February",
      "March", "April", "May", "June", "July", "August",
      "September", "October", "November", "December" };
   output << monthName[ d.month ] << ' ' << d.day << ", " << d.year;
   return output; // enables cascading
} // end function operator<<
