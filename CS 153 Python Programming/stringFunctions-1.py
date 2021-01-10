import string

# stringFunctions.py
# CS 153
# Written by Zach Neeley
# Date written 10/22/20
# Date/time last modified 6:03 pm 10/22/20
# Purpose: This program is designed to help me with some of the more advanced string manipulations
# Input: Strings from the console
# Output:  The information specified from the program. Usually from the string manipulation 

# NOTE I did use some more advanced python here that I have used in the past
# for some scripts at work and some personal use.

def remove_punc(s):  
    # Using the import string and use translate to remove any punctuation
    # to do this call maketrans and pass it string.punctuation which contains
    # any puncuation a string can have. 
    
    # This is alot more complex than what this problem is asking for but I had
    # to use this for a script at work. 
    return s.translate(str.maketrans('', '', string.punctuation))
    
def word_count(s):  
    # Split the string at the spaces and take the length of it to count the words
    return len(s.split())

def add_unique(s, word_list):
    
    # Split the new string at the spaces
    newS = s.split()
    
    # Loop through the string and add the new words if it is not in the string
    for i in newS:
        if i not in word_list:
            word_list.append(i.lower())
    
    return

def main():
    
    # Test remove_punc
    inputStr = input('Type a string with punctuation: ')
    print ('String without punctuation: ', remove_punc(inputStr))  
    inputStr = input('Type a string with punctuation: ')
    print ('String without punctuation: ', remove_punc(inputStr))  
    
    # Test word_count
    inputStr = input('Type a string: ')
    print ('The number of words in that string: ', word_count(inputStr))
    inputStr = input('Type a string: ')
    print ('The number of words in that string: ', word_count(inputStr))
    
    # Test add_unique
    inputStr = input('Type some words. Put one space between words: ')
    words = []
    add_unique(inputStr, words)
    print ('The unique words in the string: ', words)
    inputStr = input('Type some words. Put one space between words: ')
    words = []
    add_unique(inputStr, words)
    print ('The unique words in the string: ', words)


if __name__ == '__main__':
    main ()
    