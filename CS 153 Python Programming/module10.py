# module10.py
# CS 153
# Written by Zach Neeley
# Date written 11/19/20
# Date/time last modified 3:30 pm 11/19/20
# Purpose: This is a file used with the pa10.py program. This program has functions to modify strings.
# Input: Strings and word lists
# Output: A returned string with the needed changes by the called function
import string
import re

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

def remove_non_alpha(s):
    # Define a regex so you can remove all non letters from the string
    regex = re.compile('[^a-zA-Z0-9]')
    newS = regex.sub('', s)
    
    return newS

def letter_frequency(s):
    # convert the string to lowercase
    newStr = s.lower()
    
    # Array to store how many times a letter appears
    letterFreq = [0]*26
    
    # Look through the string and add 1 to the needed index
    for i in newStr:
        # Make sure the letter is lower case and its a letter 
        if ('a' <= i <= 'z'):
            # Get the letter index 
            index = ord(i) - ord('a')
            
            letterFreq[index] += 1
            
    return letterFreq

def main():
    
    # Test remove punctuation
    str1 = "!!!!!!!!Removeing all punctuation from a string!!!!!!!!"
    print(str1)
    print(remove_punc(str1))
    print("\n")
    
    # Test word count
    str2 = "This string has five words"
    print(str2)
    print(word_count(str2))
    print("\n")
    
    # Test add unique
    str3 = "Old String New String Goes Here"
    words = []
    add_unique(str3, words)
    print ('The unique words in the string: ', words)
    print("\n")
    
    # Test remove non alpha
    str4 = "Thi7s Strin6g has5 othe4r stuf3f i2n i1t"
    print(str4)
    print(remove_non_alpha(str4))
    print("\n")
    
    # Test letter frequency
    str5 = "abcdefghijklmnopqurstuvwxyz"
    print("String letter frequency")
    print(letter_frequency(str5))

if __name__ == '__main__':
    main ()