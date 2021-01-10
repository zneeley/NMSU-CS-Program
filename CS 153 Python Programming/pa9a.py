# pa9a.py
# CS 153
# Written by Zach Neeley
# Date written 11/4/20
# Date/time last modified 11/4/20 7:35 pm
# Purpose: To learn and practice with reading and writing files
# Input: File names and strings to search for.
# Output: A file written with the replaced strings
import os

def main():
    file1 = input('Enter the name of the 1st file: ')
    file2 = input('Enter the name of the 2nd file: ')
    
    # Check if the file exists
    if (os.path.exists(file1)):
        
        # Prompt for the needed strings
        old_string = input('Enter the string to search for: ')
        new_string = input('Enter the to replace the other string: ')
        
        # Open the inpute file
        with open(file1, 'r') as inputFile:
            
            # Open the output file
            with open(file2, 'w') as outputFile:
                
                # Loop through the lines in inputFile
                for line in inputFile:
                    
                    # Replace the strings if needed
                    outputFile.write(line.replace(old_string, new_string))
                
        # Close the files
        inputFile.close()
        outputFile.close()
    
    else:
        print('Error: The file does not exist.')

if __name__ == '__main__':
    main ()