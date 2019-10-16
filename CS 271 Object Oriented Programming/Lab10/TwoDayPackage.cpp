// CS 271
// Program Name: TwoDayPackage.cpp
// Author:       Zachary Neeley
// Date:         11/14/2018
// Purpose:      This program will implement the package class to create a object for a shipping package. This will only add a flatFee to the package class.
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"

using namespace std;

// Constructor will pass the needed parameters to the package constuctor and will call setFlatFee
TwoDayPackage::TwoDayPackage(string sname, string saddress, string scity, string sstate, string szip, string rname, string raddress, string rcity, string rstate, string rzip, double w, double c, double f): Package(sname, saddress, scity, sstate, szip, rname, raddress, rcity, rstate, rzip, w, c){
    
    setFlatFee(f);
    
} // end constructor

// Will check to see if flatFee is > 0 is not then will set the fee to 0
void TwoDayPackage::setFlatFee(double f){
    if (f >= 0) {
        flatFee = f;
    } else {
        flatFee = 0;
    } // end if else
    
} // end setFlatFee


// Accessor getFlateFee
double TwoDayPackage::getFlateFee() const{
    return flatFee;
    
} // end getFlateFee

// Method calculateCost will calc the cost of shipping
double TwoDayPackage::calculateCost() {
    return (getWeight() * getCostPerOunce() + flatFee);
    
} // end calculateCost
