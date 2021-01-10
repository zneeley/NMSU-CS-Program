# earthquakes.py
# CS 153
# Written by Zach Neeley
# Date written 12/3/20
# Date/time last modified 1:30 pm 12/3/20
# Purpose: Plot earthquakes from data given from a file.
# Input: File that contains the needed earthquake data
# Output: A plot of the earthquake data 
import matplotlib.pyplot as plt

def main():
    
    # Get the file name and open it
    inputFile = input('Enter the name of the file: ')
    file = open(inputFile, 'r')
    
    # Lists to store the years and earthquakes
    eqs = []
    yrs = []
    
    # Read all the lines into the file
    lines = file.readlines()
    
    # Loop through the lines and get the years and earthquakes
    for  line in lines:
        # Split on the space and store the yrs and eqs
        year, earthquakes = line.split(" ")
        yrs.append(int(year))
        eqs.append(int(earthquakes))
        
    # Find the highest year and highest earthquake
    eqsHigh = max(eqs)
    yearHigh = yrs[eqs.index(eqsHigh)]
    
    # Get the years for the x axis
    axisYearsLabel = ["1900", "1920", "1940", "1960", "1980", "2000"]
    axisYearsNumber = [1900, 1920, 1940, 1960, 1980, 2000]
    
    # Plot the information
    plt.plot(yrs, eqs, c='green')
    
    # Set the title and labels
    plt.ylabel("Number of Earthquakes\n(Magnitude > 7)")
    plt.xlabel("Years")
    plt.title("Strong Earthquakes During the 1900's")
    
    # Set any other needed settings for the graph
    plt.grid()
    plt.xticks(axisYearsNumber, axisYearsLabel)
    plotMsg = "Highest of" + str(eqsHigh) + "in" + str(yearHigh)
    plt.annotate(plotMsg, xy = (yearHigh, eqsHigh))
    plt.show()
    
    # Close the file
    file.close()

if __name__ == '__main__':
    main ()