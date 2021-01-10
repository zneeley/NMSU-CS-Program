# words.py
# CS 153
# Written by Zach Neeley
# Date written 9/24/20
# Date/time last modified 9/24/20 10:53 am
# Purpose: This program is to help understand how to use a for loop and if statements in python
# Input: 10 words
# Output: The number of words longer than 5 charcters long and the amount of words less than 5
#         characters long. Also the two lists of the words sorted. 

''' create an empty list named short_words '''
short_words = [];

''' create an empty list named long_words '''
long_words = [];

for x in range(10):
    ''' input a string (use a prompt) and store it in a variable called word '''
    word = str(input('Please enter a word: '));
    
    ''' Note: You must use an if-else statement. '''
    ''' if the word is 5 letters or less, append it to short_words, otherwise append it to long_words '''
    if len(word) <= 5:
        short_words.append(word);
    else:
        long_words.append(word);
        
# the loop is over, move all the way back to the left edge
''' print a message that says how many short words there were '''
print ("The amount of short words: ", len(short_words));
''' print the short_words list '''
print (short_words);
''' print a message that says how many long words there were '''
print ("The amount of long words: ", len(long_words));
''' print the long_words list '''
print (long_words);