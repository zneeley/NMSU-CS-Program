# pa9b.py
# CS 153
# Written by Zach Neeley
# Date written 11/4/20
# Date/time last modified 11/4/20 6:15 pm
# Purpose: To learn and practice with reading and writing files
# Input: File names need.
# Output: Console output showing the line by line differences in the files
import os

def main():
    
    # Get the file names from the user
    file1 = input('Enter the name for the 1st file: ') 
    file2 = input('Enter the name for the 2nd file: ') 
    
    # Check if the files exist
    if (os.path.exists(file1)):
        if (os.path.exists(file2)):
            
            # Open the needed files
            f1 = open(file1, 'r')
            f2 = open(file2, 'r')
            
            # Read the lines in from the files and store into lists
            LinesF1 = []
            LinesF2 = []
            
            
            # Store the lines from file 1
            for line in f1:
                LinesF1.append(line)
            
            # Store the lines from file 2
            for line in f2:
                LinesF2.append(line) 
            
            # Loop through the longest list
            for i in range(max(len(LinesF1), len(LinesF2))):
               print("File 1: ",LinesF1[i].strip())
               print("File 2: ",LinesF2[i].strip())
               print("Diff:    ",end='')
               
               
                # Loop through the longest list again
               j = 0
               while j<len(LinesF1[i]) and j<len(LinesF2[i]):
                   
                   # Print the needed x's or spaces
                   if LinesF1[i][j]==LinesF2[i][j]:
                       print(' ',end='')

                   else:
                       print('x',end='')
                       
                   # Increment j
                   j = j + 1
                   
                   
               # Print x's for the remaining characters
               while j<len(LinesF1[i]):
                   print('x',end='')
                   j = j + 1
                   
               # Print x's for the remaining characters
               while j<len(LinesF2[i]):
                   print('x',end='')
                   j = j + 1
                   
               #Increment i by 1
               i = i + 1
               
               print()
               
            # Print any more x's needed for any extra lines
            while i<len(LinesF1):
               print("File 1: ",LinesF1[i].strip())
               print("File 2: ")
               print("Diff:    ",end='')
               
               # Print the x's
               for letter in LinesF1[i]:
                   print('x',end='')
               
               i = i + 1
            
           # Print any more x's needed for any extra lines
            while i<len(LinesF2):
               print("File 1: ")
               print("File 2: ",LinesF2[i].strip())
               print("Diff:    ",end='')
               
               # Print the x's
               for letter in LinesF2[i]:
                   print('x',end='')
                   
               i = i + 1
            
            # Close the needed files
            f1.close()
            f2.close()
                
            
        else:
            print('Error: The 2nd file does not exist.')
    else:
        print('Error: The 1st file does not exist.')

if __name__ == '__main__':
    main ()