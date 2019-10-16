// CS 271
// Program Name: lab1
// Author:       Zachary Neeley
// Date:         8/22/2018
// Purpose:      This program will take input from a data file to calculate average
//               and the Letter Grade of that average. Once this is done the program
//               will print to console.

#include <stdio.h>
#include <math.h>

int main (void) {
    // init
    float exam1, exam2, exam3, exam4, average;
    char grade;

//Get input from the dat file and store the first set of scores in exam 1, 2, 3 ,4     
//     printf("Input exam 1: \n");
    scanf("%f", &exam1);
    
//     printf("Input exam 2: \n");
    scanf("%f", &exam2);
    
//     printf("Input exam 3: \n");
    scanf("%f", &exam3);
        
//     printf("Input exam 4: \n");
    scanf("%f", &exam4);
    
    // Create the sentinal loop looking to see if the input was -1 0 0 0
    while (exam1 != -1 && exam2 >= 0 && exam3 >= 0 && exam4 >= 0) {
        
        // Calc average from the exam grades
        average = (exam1 + exam2 + exam3 + exam4) / 4;
        
        // Calc Letter Grades
        // If the grade is between 0 <= average < 60 grade is F
        if (average >=0 && average < 60) {
            grade = 'F';
        
        // If the grade is between 60 <= average < 70 grade is D
        }else if (average >=60 && average < 70) {
            grade = 'D';
           
        // If the grade is between 70 <= average < 80 grade is C   
        } else if (average >=70 && average < 80) {
            grade = 'C';
        
        // If the grade is between 80 <= average < 90 grade is B
        } else if (average >=80 && average < 90) {
            grade = 'B';
        
        // If the grade is between 90 <= average < 100 grade is A
        } else {
            grade = 'A';
            
        } // End if statement
        
        // Print outputs so that the exam scores are given 
        // Average of the scores and the Letter Grade
        printf("Exam Scores: %3.0f %3.0f %3.0f %3.0f\n", exam1, exam2, exam3, exam4);
        printf("Average: %10.2f \n", average);
        printf("Letter Grade: %c\n\n", grade);
            
//         printf("Input exam 1: \n");
        scanf("%f", &exam1);
    
//         printf("Input exam 2: \n");
        scanf("%f", &exam2);
    
//         printf("Input exam 3: \n");
        scanf("%f", &exam3);
        
//         printf("Input exam 4: \n");
        scanf("%f", &exam4);
                
    }// end while
    
    
} // end main function
