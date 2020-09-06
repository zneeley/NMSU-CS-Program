/*CS 172
* Loops
* Lab 3
* Written by: Zachary Neeley
* 9/24/17
*
* INPUT:
* OUTPUT:
*/

import java.util.Scanner;

public class Lab3 {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // init all needed variables
        int problem1 = 0;
        int largest = 0; 
        int val, inputNum = 1, counter = 0;
        int numA = 0, numE = 0, numI = 0, numO = 0, numU = 0;
        String userInput;
        //
        // Problem 1 - a for loop that will print the odd numbers from 1 to 99
        //
        System.out.println( "\nThis is the output from problem 1 Part A - for loop\n");
        // Loop to get all odd numbers
        for (int num = 1;num < 100; num = num + 2 ){
            // Print the numbers
            System.out.println("num = " + num);
        } 
        //
        // Part B using a while loop
        //
        System.out.println( "\nThis is the output from problem 1 Part B - while loop\n");
        // Loop to get all odd numbers
        while (problem1 <= 100) {
            int odd = problem1 % 2;
            if (odd != 0) {
                // Print the numbers
                System.out.println(problem1);
            }
            problem1 ++;
        }
        
        
        //
        // Problem 2 - Users input 10 numbers and print the largest
        //
        System.out.println( "\nThis is the output from problem 2 part A - for loop\n");
        
        // Loop through 10 times to get all the users values
        for (int i = 1; i <= 10; i ++) {
            
            // Prompt a user
             System.out.println("Please input a number: ");
             val = scan.nextInt();
             
             // Check to see if the number is greater then the last or move on
             if (i == 1) {
                 largest = val;
             } else {
                 if (val > largest) {
                     largest = val;
                 }
             }
        }
        // Print the largest number
        System.out.println("The largest number is: " + largest);
        scan.nextLine( );
        
        //
        //Part B using a while loop
        //
        System.out.println( "\nThis is the output from problem 2 Part B - while loop\n");
        
        // Loop through 10 times to get all the users values
        while (inputNum <= 10) {
            
            // Prompt a user
            System.out.println("Please input a number: ");
             val = scan.nextInt();
            
            // Check to see if the number is greater then the last or move on 
            if (inputNum == 1) {
                largest = val;
            } else {
                if (val > largest) {
                    largest = val;
                }
            }
            inputNum ++;
        }
        // Print the largest number
        System.out.println("The largest number is: " + largest);
        scan.nextLine( );
        
        //
        // Problem 3 - 
        //
        System.out.println( "\nThis is the output from problem 3 - for loop\n");
        
        // Promp a user for a string
        System.out.println("Please input a string: ");
        userInput = scan.nextLine();
        
        // Get the string length and convert it all to lower case
        val = userInput.length();
        String userLower = userInput.toLowerCase();
        
        // Loop through the string to see if each index of the string matches a vowel
        for (int i = 0; i < val; i++) {
            if (userLower.charAt(i) == 'a') {
                numA = numA + 1;
            }
            if (userLower.charAt(i) == 'e') {
                numE = numE + 1;
            }
            if (userLower.charAt(i) == 'i') {
                numI = numI + 1;
            }
            if (userLower.charAt(i) == 'o') {
                numO = numO + 1;
            }
            if (userLower.charAt(i) == 'u') {
                numU = numU + 1;
            }
        }
        // Print out the finial values
        System.out.println("The number of vouels in the string are as follows \n Number of A's: " + numA + "\n Number of E's: " + numE + "\n Number of I's: " + numI +
                           "\n Number of O's: " + numO + "\n Number of U's: " + numU);
        //
        // Part B 
        //
        System.out.println( "\nThis is the output from problem 3 part B - while loop\n");
        
        // Promp a user for a string
        System.out.println("Please input a string: ");
        userInput = scan.nextLine();
        
        // Set each value to 0 
        numA = 0;
        numE = 0;
        numI = 0;
        numO = 0; 
        numU = 0;
        
        // Get the string length and convert it all to lower case
        val = userInput.length();
        userLower = userInput.toLowerCase();
        
        // Loop through the string to see if each index of the string matches a vowel
        while (counter < val) {
            if (userLower.charAt(counter) == 'a') {
                numA = numA + 1;
            }
            if (userLower.charAt(counter) == 'e') {
                numE = numE + 1;
            }
            if (userLower.charAt(counter) == 'i') {
                numI = numI + 1;
            }
            if (userLower.charAt(counter) == 'o') {
                numO = numO + 1;
            }
            if (userLower.charAt(counter) == 'u') {
                numU = numU + 1;
            }
            counter ++;
        }
        // Print out the finial values
        System.out.println("The number of vouels in the string are as follows. \n Number of A's: " + numA + "\n Number of E's: " + numE + "\n Number of I's: " + numI +
                           "\n Number of O's: " + numO + "\n Number of U's: " + numU);
    }
    
}
