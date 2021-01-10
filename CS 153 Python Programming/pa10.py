# pa10.py
# CS 153
# Written by Zach Neeley
# Date written 11/19/20
# Date/time last modified 6:20 pm 11/19/20
# Purpose: This program is designed for me to have practice with coding my own 
#           module and using the module for tasks with a file.
# Input: Filename
# Output: Information stated from the assignement like number of words, letter 
#           frequence, etc. 

import module10

def main():
    # Get file name and open it
    inputFile = input('Enter a file name: ')
    file = open(inputFile, "r")
    
    # init
    totalWords = 0
    uniqueWords = []
    sortedWords = []
    letterFreq = [0]*26
    letters = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n",
               "o","p","q","r","s","t","u","v","w","x","y","z"]

    # Loop through the file
    for line in file:
        # Get the total words in the file
        totalWords = totalWords + module10.word_count(line)
        
        # List of unique words
        module10.add_unique(line,uniqueWords)

        # Get frequency of letters
        returnedList = module10.letter_frequency(line)
        
        # Add the 2 lists together 
        for i in range(len(returnedList)):
            letterFreq[i] = letterFreq[i] + returnedList[i]
        
        
    # Close the file        
    file.close()

    # Sort the unique words
    for i in uniqueWords:
        tempStr = module10.remove_non_alpha(i)
        sortedWords.append(tempStr)
    sortedWords.sort()
    
    # Print the unique works
    print("There are " + str(totalWords) + "words in the file.\n")
    print("There are " + str(len(uniqueWords)) + " unique words in the file: ")
    count = 1
    
    # Print the words in the needed format
    for i in sortedWords:
        
        strCounter = str(count) + "."
        
        print("{0:>3} {1}".format(strCounter, i))
        count += 1
        
    # Print the letter frequency
    print("\n\nLetter Frequency")
    print("------ ---------")

    for i in range(len(letters)):
        print("   " + str(letters[i]) + "\t\t", end="")
        print(letterFreq[i])
    
if __name__ == '__main__':
    main ()