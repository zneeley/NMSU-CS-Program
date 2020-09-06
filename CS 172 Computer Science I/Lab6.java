// Program name: Lab6.java
// Lab number: 6
// CS 172 – section M01
// written by Zachary Neeley
// date written 10/24/17
// This program will work with methods. Creating an array of random numbers,
// pass information into methods in a MyMethods.java file and if needed get information
// from the methods and print.
// Input: User input for a couple of methods.
// Output: Will print out an radom array, and outputs from methods that return data.

import java.util.*;

public class Lab6 {


   public static void main(String[] args) {
      // init
      int number[] = new int[50];
      int key = 0;
      Random rand = new Random();
      Scanner scan = new Scanner(System.in);
      
      // 
      // Method 1
      //
      // Use the number array generate random numbers and store them in
      // the number array.
      for (int k = 0; k < number.length; k++) {
         // Calc random number and assign to number[k]
         number[k] = rand.nextInt(100) + 1;
      }
      // Pass number and 10 to the printIntArray
      MyMethods.printIntArray( number, 10 );
      
      //
      // Method 2
      //
      // Get user input for a number they would like to search for then
      // pass the number array and key to the method linearSearch 
      // if true tell the user.
      System.out.println("Please input a number to search for:");
      key = scan.nextInt();
      // If linearSearch return true tell the user it wasd found if false
      // tell the user it didn't.
      if (MyMethods.linearSearch(number, key) == true) {
         System.out.println("The number " + key + " was found.");
      } else {
         System.out.println("The number " + key + " wasn't found.");
      }
      
      //
      // Method 3
      //
      // Ask for user input then pass the key and array number to linearSearch2 
      // and print it to the user.
      System.out.println("Please input a number to search for:");
      key = scan.nextInt();
      // If linearSearch2 is greater then -1 then tell the user where the key is 
      if (MyMethods.linearSearch2(number, key) > -1) {
         System.out.println("The number " + key + " was found in the index of: " + MyMethods.linearSearch2(number, key));
      } else {
         System.out.println("The number " + key + " was not found in the array");
      }
      scan.nextLine();
      
      //
      // Method 4
      //
      // Call the method powersOfTwo then print it to console
      System.out.println("The first 10 powers of 2 are: ");
      MyMethods.powersOfTwo();
      System.out.println();
      
      //
      // Method 5
      //
      // Ask the user for a char then pass it to isAlpha
      System.out.println("Please input a character");
      // init
      char CheckingChar;
      CheckingChar = scan.next().charAt(0);
      // If the char is in the alphapet then tell the user
      if(MyMethods.isAlpha(CheckingChar) == true) {
         System.out.println("The character " + CheckingChar + " is in the alphabet.");
      }
      scan.nextLine();
      
      //
      // Method 6
      // 
      // Ask user for a string then pass it to reverse then print it to console
      System.out.println("Please type in a string and press enter when finished" );
      // init 
      String finialInput = "";
      String userInput = scan.nextLine();
      
      // Get the string from userInput and print to console
      finialInput = MyMethods.reverse(userInput);
      
      System.out.println("The reverse of " + userInput + " is : " + finialInput);
   }
   
}
