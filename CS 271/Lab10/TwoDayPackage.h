#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include <string>
#include "Package.h"

using namespace std;

class TwoDayPackage: public Package{

    private:
        double flatFee;
        
    public:
        TwoDayPackage (string sname, string saddress, string scity, string sstate, string szip, string rname, string raddress, string rcity, string rstate, string rzip, double w, double c, double f);
        
        double getFlateFee() const;
        
        void setFlatFee(double f);
        
        double calculateCost();
}; 
#endif
