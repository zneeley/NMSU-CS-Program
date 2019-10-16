#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>

using namespace std;

class Package {

    private:
        string senderName;
        string senderAddress;
        string senderCity;
        string senderState;
        string senderZip;
        string recipientName;
        string recipientAddress;
        string recipientCity;
        string recipientState;
        string recipientZip;
        double weight;
        double costPerOunce;
        
    public:
        Package (string sname, string saddress, string scity, string sstate, string szip, string rname, string raddress, string rcity, string rstate, string rzip, double w, double c);
        
        string getSenderName() const;
        string getSenderAddress() const;
        string getSenderCity() const;
        string getSenderState() const;
        string getSenderZip() const;
        string getRecipientName() const;
        string getRecipientAddress() const;
        string getRecipientCity() const;
        string getRecipientState() const;
        string getRecipientZip() const;
        double getWeight() const;
        double getCostPerOunce() const;
        
        void setSenderName(string sname);
        void setSenderAddress(string saddress);
        void setSenderCity(string scity);
        void setSenderState(string sstate);
        void setSenderZip(string szip);
        void setRecipientName(string rname);
        void setRecipientAddress(string raddress);
        void setRecipientCity(string rcity);
        void setRecipientState(string rstate);
        void setRecipientZip(string rzip);
        void setWeight(double w);
        void setCostPerOunce(double c);
        
        double calculateCost();
}; 
#endif
