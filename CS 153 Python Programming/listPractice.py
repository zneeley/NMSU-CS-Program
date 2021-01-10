# listPractice.py
# CS 153
# Written by Zach Neeley
# Date written 9/14/20
# Date/time last modified 9/14/20 5:32 pm
# Purpose: This program will be used to teach lists and how to use them.
# Input: None.
# Output: Print statements that are specified by the assigment. 
import random

# Create an empty list
myList = []; 


# Input 5 random floats into the list
for i in range(5):
    x = float(random.randrange(1,100));
    myList.append(x);
    
# Pring the needed values
print ("Starting list: " + str(myList));
print ("Sum of the elemnts in the list: " + str(sum(myList)));
print ("Min value in list: " + str(min(myList)));
print ("Max value in list: " + str(max(myList)));
print ("Average of numbers in list: " + str(sum(myList) / len(myList)));

# Remove last element from the list
myList.pop(len(myList) - 1)

# Print the list
print ("Modified list: " + str(myList));