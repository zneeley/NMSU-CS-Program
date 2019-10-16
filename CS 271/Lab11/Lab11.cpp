// CS 271
// Program Name: Lab11
// Author:       Zachary Neeley
// Date:         11/27/2018
// Purpose:      Will take input from a file store the information in a 2d array and print the
//               values in the array to a txt file. The array will treat the 0 row and col as

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// setSpacing: method will set the correct spacing needed for the program. Figured out the 
//             needed spacing by counting the characters on the lab handout

string setSpacing(double d) {
    
    //init 
    string spacing;
    
    // If the number is less than 10 return a string with 8 spaces 
    if (d < 10) {
        spacing = "        ";
        return spacing;
        
    } // end if
    
    // If the number is greater than or equal to 10 and less then 100 return a string with 7 spaces 
    if (d >= 10 && d < 100) {
        spacing = "       ";
        return spacing;
        
    } // end if
    
    // If the number is greater than or equal to 100 and less then 1000 return a string with 6 spaces 
    if (d >= 100 && d < 1000) {
        spacing = "      ";
        return spacing;
        
    } // end if
    
    // If the number is greater than or equal to 1000 and less then 10000 return a string with 5 spaces 
    if (d >= 1000 && d < 10000) {
        spacing = "     ";
        return spacing;
        
    } // end if
    
    // If the number is greater than 10000 return a string with 4 spaces 
    if (d > 10000) {
        spacing = "    ";
        return spacing;
        
    } // end if
} // end setSpacing

// main method: will take input from a file store the information in a 2d array and print the
//              values in the array to a txt file. The array will treat the 0 row and col as dummy data.
int main() {
    
    // init
    double sales[6][5];
    double inputAmount;
    double grandTotal = 0.0;
    double totalTemp;
    int inputPerson;
    int inputItem;
    int dataRow = 5;
    int dataCol = 4;
    
    // Create the output file for the program
    ofstream outf("SalesReport.txt");
    
    // Point which file to use with the program
    ifstream inf("Sales.dat");
    
    // Set all the indexes in the array to 0.0.
    for (int row = 1; row <= dataRow; row++){
        for (int col = 1; col <= dataCol; col++){
            sales[row][col] = 0.0;
        } // end col
    } // end row
    
    // If the file could not be opened print an error to console and exit the program
    if (!inf) {
        cerr << "The Sales.dat file could not be opened" << endl;
        return 1;
        
    } // end if
    
    // While the program is still reading data in the file
    while (inf) {
        
        // Take the person, item and amount storing them in the repected variables
        inf >> inputPerson;
        inf >> inputItem;
        inf >> inputAmount;
        
        // If the program did read something 
        if (inf) {
            
            // Assign the values in the correct position in the array
            sales[inputPerson][inputItem] = sales[inputPerson][inputItem] + inputAmount;
            
        } // end if
    } // end while
    
    // Output the needed header to the file
    outf << "                 Product #1  Product #2  Product #3  Product #4  Totals" << endl;
    
    // Loop through the arrays 
    for (int row = 1; row <= dataRow; row++){
        // Output the Salesperson number 
        outf << "Salesperson #" << row << " ";
    
        for (int col = 1; col <= dataCol; col++){
            // Ouput value sold in the correct order for the Salesperson. Calling setSpacing for the needed spacing
            outf << setprecision(2) << fixed << right << setSpacing(sales[row][col]) << sales[row][col];
            
        } // end col
        
        // Calc the total for that row and output to the file
        totalTemp = sales[row][1] + sales[row][2] + sales[row][3] + sales[row][4];
        outf << setprecision(2) << fixed << left << "  " << totalTemp << endl;
        
    } // end row
    
    // Add the Totals line to the output
    outf << "        Totals ";
    
    // Loop through each col in the array adding up the values for the col and calc the grand total
    for (int i = 1; i <= dataCol; i++) {
        totalTemp = sales[1][i] + sales[2][i] + sales[3][i] + sales[4][i] + sales[5][i];
        grandTotal = grandTotal + totalTemp;
        
        // Output the final values
        outf << setprecision(2) << fixed << right << setSpacing(totalTemp) << totalTemp;
        
    } // end for
    
    // Ouput the grand total in the correct position.
    outf << setprecision(2) << fixed << left << "  " << grandTotal << endl;
            
} // end main
