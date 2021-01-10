# pa8.py
# CS 153
# Written by Zach Neeley
# Date written 10/29/20
# Date/time last modified 10/29/20 5:04 pm
# Purpose: To learn and practice with list comparisons 
# Input: File names
# Output: A file written with the information needed
import re

def remove_non_alpha(s):
    # Define a regex so you can remove all non letters from the string
    regex = re.compile('[^a-zA-Z]')
    newS = regex.sub('', s)
    
    return newS

def main():
    fileName = input('Enter the input file Ex) file1.txt: ')
    inputFile = open(fileName,"r")
    fileName2 = input('Enter the ouput file Ex) outputfile1.txt: ')
    outputFile = open(fileName2, "w+")
    
    # Loop through the file line by line
    for line in inputFile:
        
        # Remove the newLine character from the string
        tempLine = line[:-1]
        
        # Split the string at the spaces 
        words = tempLine.split()
        
        # Convert to lower case letters
        list3A = []
        for i in words:
            list3A.append(i.lower())
        
        # Call the remove_non_alpha if needed
        list3B = []
        for i in list3A:
            if remove_non_alpha(i):
                 list3B.append(remove_non_alpha(i))
        
        # Put the length of each element in 3B into 3C
        list3C = []
        for i in list3B:
            list3C.append(len(i))
        
        # Find the average length
        avg = sum(list3C)/len(list3C)
        
        # Write the needed information to the output file
        outputFile.write("Original Line: {:s}\n".format(tempLine))
        outputFile.write("Words: {:s}\n".format(" ".join(list3A)))
        outputFile.write("Only Letters: {:s}\n".format(" ".join(list3B)))
        outputFile.write("Average Word Length: {:.2f}\n".format(avg))        
        outputFile.write("\n")
      
    # Close the files    
    inputFile.close()
    outputFile.close()
        
        

if __name__ == '__main__':
    main ()
    