/*CS 172
* Lots Of Stars
* Lab 4
* Written by: Zachary Neeley
* 10/3/17
* The purpose of this program is to use nested loops with a user input to print out a
* pattern as shown in the lab 4 assignment.
* INPUT: User will input a number that will show how manmy lines do they want in each
* pattern.
* OUTPUT: Print a patter of star characters with the amount of lines the user input
*/

// Import the scanner class
import java.util.Scanner;

public class LotsOfStars {

    public static void main(String[] args) {
        int numLines = 0; // Init the number of lines at 0
        String star = ""; // Create a empty string to store the * characters later
        Scanner scan = new Scanner(System.in); // Create a new scanner
        
        // Problem 1
        // Prompt the user for the number of lines that want
        System.out.println("Please input the number of lines you want to have: ");
        numLines = scan.nextInt();
        
        // Problem 2
        // Loop the number of times from the users input 
        for (int i = 0; i <= numLines; i++) {
            // See how many stars there should be per line
            for (int numStars = 1; numStars <= i; numStars++){
                star = star + "*"; // Add the * to the string
            }
            star = star + "\n"; // New line after the stars loop finishes 
        }
        System.out.println(star); // Print the stars
        
        // Problem 3
        // Loop the number of times from the users input
        for (int i = 0; i < numLines; i++){
            // Print the number of * per line and subtrace one * per line
            for (int x = numLines; x > i; x--){    
                System.out.print("*");
            }
            System.out.println("");
        }
        
        System.out.println();
        
        // Problem 4
        // Loop the number of times from the users input
        for (int i = 0; i < numLines; i++){
            for (int x = 0; x < numLines; x++) {
                System.out.print((x >= i) ? "*" : " "); // Check to see if the condition passes and if so print a * or a space
            }
            System.out.println(); // Print a newline 
        }
        System.out.println();
        
        // Problem 5
        // Loop the number of times from the users input
        for (int i = 0; i < numLines; i++){
            // Print the number of spaces needed per line
            for (int j = numLines - 1; j > i; j--){
                System.out.print(" ");
            }
            // Print the number of * needed per line
            for (int k = 1; k <= i + 1; k++){
                System.out.print("*");
            }
            System.out.print("\n");
        }
        
    }
    
}
