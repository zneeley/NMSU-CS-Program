# stringPractice.py
# CS 153
# Written by Zach Neeley
# Date written 9/14/20
# Date/time last modified 9/14/20 5:13 pm
# Purpose: This program will be used to teach strings and how to use them.
# Input: A string to be used for manipulation.
# Output: Formatted strings that are specified by the assigment. 


# Get input from the user
inputStr = str(input('Input A String: '));


# Print the string and its length.
print ("Inputted String: " + inputStr);
print ("String Length: " + str(len(inputStr)));

# Print the first and last characters of the string
print ("Last Character in the string: " + inputStr[0]);
print ("Last Character in the string: " + inputStr[-1]);
