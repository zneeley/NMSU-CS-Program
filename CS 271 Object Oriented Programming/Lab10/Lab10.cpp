// CS 271
// Program Name: Lab10.cpp
// Author:       Zachary Neeley
// Date:         11/14/2018
// Purpose:      This program test the TwoDayPackage and Package classes.

#include <string>
#include "TwoDayPackage.h"
#include "Package.h"
#include <iostream>

using namespace std;

int main() {
    // Create 2 package objects and 2 TwoDayPackage objects
    Package p1("Zach", "123 Candy Lane", "Las Cruces", "New Mexico", "88011", "Gabby", "123 Dog Drive", "Las Cruces", "New Mexico", "88001", 50, 4);
    
    Package p2("Ethan", "123 CS Ave.", "Las Cruces", "New Mexico", "88012", "Kaylynn", "123 Cat Drive", "Las Cruces", "New Mexico", "88004", 2, 10);
    
    TwoDayPackage twoDay1("Chris", "123 House Ave.", "Las Cruces", "New Mexico", "88031", "Raquel", "123 Candy Lane", "Las Cruces", "New Mexico", "88008", 2, 10, 13);
    
    TwoDayPackage twoDay2("Ethan", "123 Yes Ave.", "Las Cruces", "New Mexico", "88031", "Zach", "123 Hour Lane", "Las Cruces", "New Mexico", "88008", 55, 1, 99);
             
    // Print out p1 
    cout << "------ 1st Package Sender ------" << endl << "Name: " << p1.getSenderName() << endl << "Address: " << p1.getSenderAddress() << endl << "City: " << p1.getSenderCity() << endl << "State: " << p1.getSenderState() << endl << "Zip: " << p1.getSenderZip() << endl << "---- 1st Package  Recipient ----" << endl << "Name: " << p1.getRecipientName() << endl << "Address: " << p1.getRecipientAddress() << endl << "City: " << p1.getRecipientCity() << endl << "State: " << p1.getRecipientState() << endl << "Zip: " << p1.getRecipientZip() << endl << "-------- Shipping  Cost --------" << endl << "$" << p1.calculateCost() << endl << endl << endl;
        
    // Change the weight of the p2 package and the cost of shipping.
    p2.setWeight(66);
    p2.setCostPerOunce(99);
    
    // Print out p2
    cout << "------ 2nd Package Sender ------" << endl << "Name: " << p2.getSenderName() << endl << "Address: " << p2.getSenderAddress() << endl << "City: " << p2.getSenderCity() << endl << "State: " << p2.getSenderState() << endl << "Zip: " << p2.getSenderZip() << endl << "---- 2nd Package  Recipient ----" << endl << "Name: " << p2.getRecipientName() << endl << "Address: " << p2.getRecipientAddress() << endl << "City: " << p2.getRecipientCity() << endl << "State: " << p2.getRecipientState() << endl << "Zip: " << p2.getRecipientZip() << endl << "-------- Shipping  Cost --------" << endl << "$" << p2.calculateCost() << endl << endl << endl;
    
    // Print out twoDay1
    cout << "------ TwoDay1 Package Sender ------" << endl << "Name: " << twoDay1.getSenderName() << endl << "Address: " << twoDay1.getSenderAddress() << endl << "City: " << twoDay1.getSenderCity() << endl << "State: " << twoDay1.getSenderState() << endl << "Zip: " << twoDay1.getSenderZip() << endl << "---- TwoDay1 Package  Recipient ----" << endl << "Name: " << twoDay1.getRecipientName() << endl << "Address: " << twoDay1.getRecipientAddress() << endl << "City: " << twoDay1.getRecipientCity() << endl << "State: " << twoDay1.getRecipientState() << endl << "Zip: " << twoDay1.getRecipientZip() << endl << "-------- Shipping  Cost --------" << endl << "$" << twoDay1.calculateCost() << endl << endl << endl;
    
    // Change the weight, cost per ounce and flat fee to -1 which should force them to be 0
    twoDay2.setWeight(-1);
    twoDay2.setCostPerOunce(-1);
    twoDay2.setFlatFee(-1);
    
    // Print out twoDay2
    cout << "------ TwoDay2 Package Sender ------" << endl << "Name: " << twoDay2.getSenderName() << endl << "Address: " << twoDay2.getSenderAddress() << endl << "City: " << twoDay2.getSenderCity() << endl << "State: " << twoDay2.getSenderState() << endl << "Zip: " << twoDay2.getSenderZip() << endl << "---- TwoDay2 Package  Recipient ----" << endl << "Name: " << twoDay2.getRecipientName() << endl << "Address: " << twoDay2.getRecipientAddress() << endl << "City: " << twoDay2.getRecipientCity() << endl << "State: " << twoDay2.getRecipientState() << endl << "Zip: " << twoDay2.getRecipientZip() << endl << "-------- Shipping  Cost --------" << endl << "$" << twoDay2.calculateCost() << endl;
    
} // end main
