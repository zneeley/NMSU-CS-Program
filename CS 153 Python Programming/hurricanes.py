# hurricanes.py
# CS 153
# Written by Zach Neeley
# Date written 12/3/20
# Date/time last modified 12/3/20 3:00pm
# Purpose: Plot hurricanes from data given from a file.
# Input: File that contains the needed earthquake data.
# Output: A plot of the hurricane data
import matplotlib.pyplot as plt
import csv

def main():
    # Get the file name
    inputFile = input('Enter the name of the file: ')
    
    # X Axis years
    xAxis = [i for i in range(1900, 2000, 10)] 
    xAxisLabels = [str(i) for i in xAxis]
    
    # List to store years
    years = []
    
    # Open the file 
    with open(inputFile, 'r') as file:
        inputCSV = csv.reader(file)
        
        # Loop through the csv file and get the years
        for line in inputCSV:
            years.append(int(line[1]))
    
    # Store the height of the bars
    height = []
    
    # Calculate the height of the bars for the graphs
    j = 0
    for i in range(1900, 2000, 10):
        x = 0
        
        # Add the heights together
        while (j < len(years) and (years[j] < i + 10)):
            x += 1
            j += 1
        height.append(x)
    
    # Create the plot
    plt.bar(xAxis, height, tick_label = xAxis, width = 9, color = 'blue')
    
    # Label the plot
    plt.title("Hurricanes in 1900's by Decades")
    plt.xlabel("Decades")
    plt.ylabel("Number of Hurricanes")
    
    # Set anything else needed for the plot
    plt.xticks(xAxis, xAxisLabels)
    plt.show()

if __name__ == '__main__':
    main ()