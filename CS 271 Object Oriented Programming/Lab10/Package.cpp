// CS 271
// Program Name: Package.cpp
// Author:       Zachary Neeley
// Date:         11/14/2018
// Purpose:      This program will make sure the basic c++ class structure is learned properly  by creating a package object for shipping.
#include <string>
#include "Package.h"

using namespace std;

// Constructor will set all the needed values using a mutator for each
Package::Package(string sname, string saddress, string scity, string sstate, string szip, string rname, string raddress, string rcity, string rstate, string rzip, double w, double c) {

    setSenderName(sname);
    setSenderAddress(saddress);
    setSenderCity(scity);
    setSenderState(sstate);
    setSenderZip(szip);
    setRecipientName(rname);
    setRecipientAddress(raddress);
    setRecipientCity(rcity);
    setRecipientState(rstate);
    setRecipientZip(rzip);
    setWeight(w);
    setCostPerOunce(c);

    
} // end Constructor

// Accessor getSenderName
string Package::getSenderName() const{
    return senderName;
    
} // end getSenderName

// Accessor getSenderAddress
string Package::getSenderAddress() const{
    return senderAddress;
    
} // end getSenderAddress

// Accessor getSenderCity
string Package::getSenderCity() const{
    return senderCity;
    
} // end getSenderCity

// Accessor getSenderState
string Package::getSenderState() const{
    return senderState;
    
} // end getSenderState

// Accessor getSenderZip
string Package::getSenderZip() const{
    return senderZip;
    
} // end getSenderZip

// Accessor getRecipientName
string Package::getRecipientName() const{
    return recipientName;
    
} // end getRecipientName

// Accessor getRecipientAddress
string Package::getRecipientAddress() const{
    return recipientAddress;
    
} // end getRecipientAddress

// Accessor getRecipientCity
string Package::getRecipientCity() const{
    return recipientCity;
    
} // end getRecipientCity

// Accessor getRecipientState
string Package::getRecipientState() const{
    return recipientState;
    
} // end getRecipientState

// Accessor getRecipientZip
string Package::getRecipientZip() const{
    return recipientZip;
    
} // end getRecipientZip

// Accessor getWeight
double Package::getWeight() const{
    return weight;
    
} // end getWeight

// Accessor getCostPerOunce
double Package::getCostPerOunce() const{
    return costPerOunce;
    
} // end getCostPerOunce

// Mutator setSenderName
void Package::setSenderName(string sname) {
    senderName = sname;
    
} // end setSenderName

// Mutator setSenderAddress
void Package::setSenderAddress(string saddress) {
    senderAddress = saddress;
    
} // end setSenderAddress

// Mutator setSenderCity
void Package::setSenderCity(string scity) {
    senderCity = scity;
    
} // end setSenderCity

// Mutator setSenderState
void Package::setSenderState(string sstate) {
    senderState = sstate;
    
} // end setSenderState

// Mutator setSenderZip
void Package::setSenderZip(string szip) { 
    senderZip = szip;
    
} // end setSenderZip

// Mutator setRecipientName
void Package::setRecipientName(string rname) {
    recipientName = rname;
    
} // end setRecipientName

// Mutator setRecipientAddress
void Package::setRecipientAddress(string raddress) {
    recipientAddress = raddress;
    
} // end setRecipientAddress

// Mutator setRecipientCity
void Package::setRecipientCity(string rcity) {
    recipientCity = rcity;
    
} // end setRecipientCity

// Mutator setRecipientState
void Package::setRecipientState(string rstate) {
    recipientState = rstate;
    
} // end setRecipientState

// Mutator setRecipientZip
void Package::setRecipientZip(string rzip) {
    recipientZip = rzip;
    
} // end setRecipientZip

// Mutator setWeight will check to see if weight is > 0
void Package::setWeight(double w) {
    if (w >= 0) {
        weight = w;
    } else {
        weight = 0;
        
    } // end if else
    
} // end setWeight

// Mutator setCostPerOunce will check to see if costPerOunce is > 0
void Package::setCostPerOunce(double c) {
    if ( c >= 0) {
        costPerOunce = c;
    } else {
        costPerOunce = 0;
        
    } // end if else
    
} // end setCostPerOunce

// Method calculateCost will calc the shipping cost
double Package::calculateCost() {
    return (weight * costPerOunce);
    
} // end calculateCost
