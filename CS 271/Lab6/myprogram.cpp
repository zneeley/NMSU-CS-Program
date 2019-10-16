// CS 271
// Program Name: myprogram
// Author:       Zachary Neeley
// Date:         10/11/2018
// Purpose:      This program uses 2 different methods to give an example to C++.
//               The method hasDuplicates will check to see if the array has any
//               dublicate values in it. The method longestWord will take a cstring
//               and count all the longest words, returning the longest length.

#include <cstring>
#include <iostream>

using namespace std;

// hasDuplicates will check to see if the array has any dublicate values in it.
int hasDuplicates (int array[], int size) {
    
    // Loop through the array getting the number to compare to.
    for (int i = 0; i < size; i++) {
        
        // Loop through the array to check if the other indexs match i
        for (int x = 0; x < size; x++) {
            
            // If x does't equal i so that we ignore the same index
            if (x != i) {
                
                // If x equals i return 1
                if (array[i] == array[x]) {
                    return 1;
                } // end if
            } // end if
        } // end for x
    } // end for i
    
    // If nothing matches return 0
    return 0;
    
} // end hasDuplicates

// longestWord will take a cstring and count all the longest words, returning the longest length.
int longestWord (char *cPtr) {
    
    // init
    int length = 0, longestLength = 0;
    
    // Loop through the array untill the pointer is at the end
    for (int index = 0; index < strlen(cPtr); index++) {
        
        // If the index is not a space increment length
        if (cPtr[index] != ' ') {           
            length++;
        } else {
            
            // If it is a space then set length to 0
            length = 0;
        } // end if
        
        // If the length is longer then longestLength then set longestLength to length
        if (length > longestLength) 
            longestLength = length;
        
    }// end for index
    
    return longestLength;
    
} // end longestWord

int main () {
    
    // Create the arrays for the numbers and the sentence
    int array[10];
    char sentence[100];
    
    // Ask for 10 numbers
    cout << "Input 10 numbers: " << endl;
    
    // Store the numbers into the array
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    } // end for
    
    
    // See if the array contains duplicates
    if (hasDuplicates(array, 10) == 1)
        cout << "Has Duplicates" << endl;
    
    // See if the array does not contains duplicates
    if (hasDuplicates(array, 10) == 0)
        cout << "Does not have duplicates" << endl << endl;
    
    // Clear the input buffer
    cin.get();
    
    // Ask for a sentence
    cout << "Enter a sentence: " << endl;
    
    // Store the sentence into the sentence array
    cin.getline(sentence, 100);
    
    // Tell how long the longestLength is
    cout << "The longest word length is: " << longestWord(sentence) << endl;
    
} // end main
