# functions.py
# CS 153
# Written by Zach Neeley
# Date written 10/8/20
# Date/time last modified: 10/8/20 5:08 pm
# Purpose: This program will give me practice with python functions
# Input: The input will be a string from the user for testing function 1
# Output: Output from 3 functions stated in the assignment
import random

def print5(str):
    
    # init
    count = 0
    
    # Loop through the input string
    for i in str:
        
        # Check to see if the loop has printed 4 characters
        if (count < 4):
            
            # Print the character and add 1 to count
            print (i, end='')
            count = count + 1
        
        # Check to see if the count is at 4 then print the 5th character and reset count
        elif (count == 4):
            print (i, "")
            count = 0


def triangleType(side1,side2,side3):
    
    # check to see if it is an Equilateral triangle
    if (side1 == side2 and side2 == side3 and side3 == side1):
        return "Equilateral"
    
    # check to see if it is an Isosceles triangle
    elif (side1 == side2 or side2 == side3 or side3 == side1):
        return "Isosceles"
    
    # Can only be a Scalene at this point
    else:
        return "Scalene"


def printOddNumbers(max):
    
    # init
    i = 1
    j = 1
    
    # Loop till max is reached
    while (i <= max):
        
        # Print i and add a tab after it
        print(i, end='\t')
        
        # Check to see if j%10 == 0 and print a new line
        if (j % 10 == 0):
            print()
        
        # Increment the neede variables
        i = i + 2
        j = j + 1
        
    print()
        

print ("Testing Function #1")

# Get input from the user
inputStr = input('Enter a string: ')

# Call print5 and pass inputStr
print5(inputStr)


print ("\n\nTesting Function #2")

# Test the triangleType function 
print (triangleType(5,5,5))
print (triangleType(5,5,3))
print (triangleType(5,4,3))

print ("\nTesting Function #3")

# Test the printOddNumbers function with random numbers from 1 - 100
printOddNumbers(random.randint(1, 100))
printOddNumbers(random.randint(1, 100))
printOddNumbers(random.randint(1, 100))
