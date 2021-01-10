# evenOdd.py
# CS 153
# Written by Zach Neeley
# Date written 9/24/20
# Date/time last modified 9/24/20 11:09 am
# Purpose: This program is to help understand how to use a for loop and if statements in pytho
# Input: 10 numbers
# Output: The number of even numbers and the amount of odd numbers. Also the two lists of the nmumbers sorted. 

''' create an empty list named even_numbers '''
even_numbers = [];

''' create an empty list named odd_numbers '''
odd_numbers = [];

for x in range(10):
    ''' input an integer (use a prompt) and store it in a variable called number '''
    number = int(input('Please enter a number: '));
    
    ''' Note: You must use two distinct if statements. '''
    ''' if the number is even, append it to the even_numbers list '''
    if (number % 2) == 0:
        even_numbers.append(number);
    
    ''' if the number is odd, append it to the odd_numbers list '''
    if (number % 2) != 0:
        odd_numbers.append(number);
    
# the loop is over, move all the way back to the left edge
''' print a message that says how many even numbers there were '''
print ("The amount of even numbers: ", len(even_numbers));

''' print the even_numbers list '''
print (even_numbers);

''' print a message that says how many odd numbers there were '''
print ("The amount of odd numbers: ", len(odd_numbers));

''' print the odd_numbers list '''
print (odd_numbers);
