# loops.py
# CS 153
# Written by Zach Neeley
# Date written 10/1/20
# Date/time last modified: 10/1/20 4:12 pm
# Purpose: This program will give me practice with python loops
# Input: The input will be a number for problem 2, string for problem 3 and strings for problem 4
# Output: Output from the loops for the needed problems 



# Problem 1 -  output the lowercase letters
print ("Problem 1 -  output the lowercase letters")

# Loop through a - z number in ascii 
for i in range(97, 123):
    
    # Convert i to a letter and print
    print (chr(i))   

print ()
print ()

# Problem 2 - triangle of asterisks
print ("Problem 2 - triangle of asterisks")
size = int(input('Enter the amount of row in the triangle: '))

# Check to see if the input is 1>= and <=50
if size > 50 or size < 1:
    print('Invalid Input')
else: 
    
    # Print the needed triangle
    for i in range(size,0,-1):
        for j in range(size-i):
            print(' ',end='')
        for j in range(i):
            print('*',end='')
        print()
        
print ()
print ()

# Problem 3 - Counting vowels
print ("Problem 3 - Counting vowels")
string = input('Enter a string: ').lower()

# List of vowels to compare to
vowels = ['a','e','i','o','u']
for i in vowels:
    counts = 0
    for j in string:
        # if the current letter is a vowel add to count 
        if i == j:
            counts += 1
    print("# of " + i + "'s:   " , counts)

print ()
print ()

# Problem 4 - inputting words and sorting them
print ("Problem 4 - inputting words and sorting them")

# Empty list for the words
usrWords = []
while True:
    inputWord = input('Enter a word or type quit to exit the program: ')
    
    # Check to see if the user typed quit 
    if inputWord.lower() == 'quit':
        break
    
    # Make sure they did not enter more than 1 word
    if len(inputWord.split()) != 1:
        print('Please enter only one word at a time.')
    
    # Add the new word to the list
    usrWords.append(inputWord) 
    
# Sort the list once all the words are added
usrWords.sort()

# Print the new list with all the words
print('The new sorted list is: ')
for i in range(len(usrWords)):
    print (usrWords[i])