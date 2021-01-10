# computingChange.py
# CS 153
# Written by Zach Neeley
# Date written 9/9/20
# Date/time last modified 9/9/20 5:00 pm
# Purpose: This program calculates the number of bills needed to give change.
# Input: amount of change to give in dollars
# Output: number of bills (twenties, tens, fives, and ones) 

amount_to_change = int(input())

# Take a copy of the original input
originalCharge = amount_to_change

# Calc number of $20's
num_twenties = amount_to_change // 20
amount_to_change = amount_to_change % 20

# Calc number of $10's
num_tens = amount_to_change // 10
amount_to_change = amount_to_change % 10

# Calc number of $5's and $1's
num_fives = amount_to_change // 5
num_ones = amount_to_change % 5


print('Change for $', originalCharge)
print(num_twenties, 'twenties dollar bill(s) and', num_tens, 'tens dollar bill(s)', num_fives, 'five dollar bill(s) and', num_ones, 'one dollar bill(s)')
