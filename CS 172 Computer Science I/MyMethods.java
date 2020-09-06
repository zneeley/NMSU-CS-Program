// Program name: MyMethods.java
// Lab number: 6
// CS 172 – section M01
// written by Zachary Neeley
// date written 10/15/17
// This program will work with mythods getting information from the Lab6.java program and
// doing calculations with them.
// Input: This program will need char from the user only for the 1st problem.
// Output: This program will output a string for problem and problem will give you a

import java.util.Scanner;
import java.util.Arrays;

public class MyMethods {

   // 
   // Method 1
   //
   // Read in an array from the Lab6 program and a number for the amount of lines
   // then print out the number of colums needed.
   public static void printIntArray (int [ ] array, int num) {
         // init
         int count = 0;
         // Loop through the array and add a space in between each index and if
         // count is equal to num then start a new line.  
         for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
            count++;
            if (count == num) {
            System.out.println();
            count = 0;
         }
      }
   }
   
   //
   // Method 2
   //
   // Will get the same array as before and a number to look for. Once it gets it will
   // copy and create a new array and short it then use binarySearch to find the key and
   // return back the 1st occurance. 
   public static boolean linearSearch (int [ ] array , int key) {
      // Create the new array and put in the data from the old one.
      int []newArray = new int[50];
      for (int i = 0; i < array.length; i++) {
         newArray[i] = array[i];
      }
      // Sort the new array
      Arrays.sort(newArray);
      // Search for the key and if found return true or false
      boolean found = Arrays.binarySearch(newArray, key) > -1;
      if (found == true) {
         return true;
      } else {
         return false;
      }
   }
   
   //
   // Method 3
   //
   // Do the same as the method before but give the index of the found key.
   public static int linearSearch2 (int [ ] array , int key) {
      // Loop through the array then if index i matches key then return i. 
      for (int i = 0; i < array.length; i++) {
         if (array[i] == key) {
            return i;
         }
      }
      return -1;
   }
   
   //
   // Method 4
   //
   // When called this method doesn't need anything passed to it when called
   // will start at 2^2 then go to 2^10 then print the data to console.
   public static void powersOfTwo () {
      // init
      int powers;
      String powersOf = "";
      // Loop untill i == 10 then print the powersOf results
      for (int i = 2; i <= 10; i++) {
         powers = (int)Math.pow(2, i);
         powersOf = powersOf + " " + Integer.toString(powers);
      }
      System.out.println(powersOf);
   }
   
   // 
   // Method 5
   // 
   // When called this method will get a char and with this will check to see if it is in the
   // alphabet upper or lower case and will return true or false. 
   public static boolean isAlpha (char isChar) {
      // Check the char on each case and return true if found. 
      switch (isChar) {
         case 'a':   case 'b':   case 'c':   case 'd':   case 'e':   case 'f':   case 'g':   case 'h':
         case 'i':   case 'j':   case 'k':   case 'l':   case 'm':   case 'n':   case 'o':   case 'p': 
         case 'q':   case 'r':   case 's':   case 't':   case 'u':   case 'v':   case 'w':   case 'x':
         case 'y':   case 'z':   case 'A':   case 'B':   case 'C':   case 'D':   case 'E':   case 'F':
         case 'G':   case 'H':   case 'I':   case 'J':   case 'K':   case 'L':   case 'M':   case 'N': 
         case 'O':   case 'P':   case 'Q':   case 'R':   case 'S':   case 'T':   case 'U':   case 'V':
         case 'W':   case 'X':   case 'Y':   case 'Z':
            return true;
      }
      return false;
   }
   
   //
   // Method 6 
   //
   // When called this method will get a string from Lab6 program then
   // store a reverse version of the string and return ans.
   public static String reverse (String reverse) {
      // init 
      String ans = "";
      // Take the string reverse loop through earch index then add that index to ans.
      for(int i = reverse.length() - 1; i >= 0; i--) {
         ans = ans + (reverse.charAt(i));
      }
      return ans;
   }
}
