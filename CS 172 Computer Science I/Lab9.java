// Program name: Lab9.java
// Lab number: 9
// CS 172 – section M01
// written by Zachary Neeley
// date written 11/14/17
// This program will work with recursion to achieve certain goals
// Input: Take user ints and chars to work with the methods
// Output: This program will output information from the methods to the console

import java.util.Scanner;

public class Lab9 {

   public static void main(String[] args) {
      // int
      int pow = 0;
      int n = 0;
      char c;
      String str;
      Scanner scan = new Scanner(System.in);
      
      for (int i = 0; i <= 2; i++) {
         
         // Problem 1 printLettersForward
         // Prompt user and assign to str then take the char at index 0 assign to c
         System.out.println("Please input a char: ");
         str = scan.next();
         c = str.charAt(0);
         // Pass c to printLettersForward method and print an extra line
         printLettersForward(c);
         System.out.println();
      
         // Problem 2 triangle
         // Prompt user for number of rows wanted and pass n to triangle method
         System.out.println("Please input the number of rows you want in the triangle: ");
         n = scan.nextInt();
         triangle(n);
         
         //Problem 3 powerOfTen
         // Prompt user for exponent for 10 ex: 10^# and pass pow to powerOfTen
         System.out.println("Please input the exponent for the power of 10: ");
         pow = scan.nextInt();
         
         System.out.println(powerOfTen(pow));
      }// End for loop
      
   } // End main
   
   // Problem 1 printLettersForward
   public static void printLettersForward(char c) {
      // Error Case also Base case
      // Will check to see if it is in the alphabet no matter if its upper or lower case
      if(c < 'A' || (c > 'Z' && c < 'a') || c > 'z') {
         return;
      }
      
      // Recursive Step
      // Will subtract 1 from the char ie b to a once finished print c
      printLettersForward((char) (c-1));
      System.out.print(c);
   } //End printLettersForward
   
   // Problem 2 triangle
   public static void triangle(int n) {
      // Error Case
      // Keeps the program from going to 0
      if (n < 1) {
         return;
      }
      // Base Case
      // Last time print 1 star and return
      if ( n == 1) {
         System.out.println("*");
         return;
      }
      // Recursive Step
      // Will subtract 1 from n and use a loop to add the needed stars
      triangle(n-1);
      for (int i = 1; i <= n; i++) {
         System.out.print("*");
         
      }
      System.out.println();
   } // End Triangle
   
   //Problem 3 powerOfTen
   public static double powerOfTen(int a) {
      // Error Case
      // Cant do exponent of 0
      if (a == 0) {
         return 1;
      }
      
      // Recursive Step
      if (a < 0 ) {
         // For negative Step
         // Add 1 to a and divide by 10
         return powerOfTen(a + 1) / 10;
      } else {
         // For positive step
         // Multiply 10 by a - 1
         return 10 * powerOfTen(a - 1);
      }
   } // End powerOfTen
}// End class
