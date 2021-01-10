# computingChange.py
# CS 153
# Written by Zach Neeley
# Date written 9/9/20
# Date/time last modified 9/9/20 5:30 pm
# Purpose: This program calculates the number of bills needed to give change.
# Input: Two floats of the radius of two circles
# Output: The area of the difference between the two circles. Or the ring as said by the problem

import math

# Prompt for needed innerCircle radius
print('What is the radius of the inner circle: ')
innerCircle = float(input())

# Prompt for needed outterCircle radius
print('What is the radius of the outter circle: ')
outterCircle = float(input())

# Print the output and calculate the needed math
print('The area of the ring is: ', ((math.pi * math.pow(outterCircle, 2))) - ((math.pi * math.pow(innerCircle, 2))))