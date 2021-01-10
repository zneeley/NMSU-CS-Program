# salary.py
# CS 153
# Written by Zach Neeley
# Date written 9/2/20
# Date/time last modified 9/2/20 7:49 pm
# Purpose: This program does salary calculations.
# Input: The person's hourly wage.
# Output: The person's annual salary and monthly salary

hourly_wage = float(input ( "Enter hourly wage: " ))

print('Annual salary is: ')
print(hourly_wage * 40 * 50)
print()

print('Monthly salary is: ')
print(((hourly_wage * 40 * 50) / 12))
print()