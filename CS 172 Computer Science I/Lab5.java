// Program name: Lab5.java
// Lab number: 5
// CS 172 – section M01
// written by Zachary Neeley
// date written 10/15/17
// This program will work with arrays from reading in from user and working with it.
// Input: This program will need char from the user only for the 1st problem.
// Output: This program will output a string for problem and problem will give you a
// float value, ints, aand strings.

import java.util.*;

public class Lab5 {

    public static void main(String[] args) {
       //init
        String names [] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
                           "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
        String tempChar;
        String searchString;
        char searchChar;
        String searchResult = "";
        int charPass = 0;
        int count = 0;
        Scanner scan = new Scanner(System.in);
        
        /*
         Problem 1
        */
        
        // Prompt user for a letter to search then covert to lower case
        System.out.println("****Problem 1****\n" + "\n" + "Please input a letter you would like to search by, then press enter.");
        
        tempChar = scan.nextLine();
        searchString = tempChar.toLowerCase();
        
        // Will check to see if the character is a true character and will repromt it not
        while (charPass < 1) {
            if (Character.isLetter(searchString.charAt(0)) && searchString.length() == 1) {
               charPass++;
            } else {
               searchString = "";
               System.out.println("Please enter a letter for example a.");
               tempChar = scan.nextLine();
               searchString = tempChar.toLowerCase();
            }
        }
        
        // Choose a index in name then check character by character for the users char
        searchChar = searchString.charAt(0);
        for (int i = 0; i < names.length; i++) {
           String nameVal = names[i];
           for (int x = 0; x < nameVal.length(); x++) {
              if (nameVal.charAt(x) == searchChar) {
                 searchResult = searchResult + names[i] + " ";
                 count++;
              } 
           } 
        }
        
        // Print the search results or if there was not a match print the no element message
        if (count > 0 ) {
           System.out.println(searchResult);
        } else {
           System.out.println("No elements contain that letter.");
        }
        
        /*
         Problem 2
        */
        
        System.out.println("\n*****Problem 2****\n");
        // init
        int values[][] = new int[10][10];
        int num = 0;
        float avg = 0;
        int min = 0;
        int max = 0;
        Random rand = new Random();
        
       // Check assign a 2d array with random numbers then print into a 10 by 10 grid
       for (int[] value : values) {
          for (int k = 0; k < value.length; k++) {
             value[k] = rand.nextInt(1000) + 1;
             System.out.print(value[k] + " ");
             num = num + value[k];
          }
          System.out.println(); 
       }
        
       // Calc the avgerage and print
        avg = (float)num / 100;
        System.out.println("\nThe average of the numbers is: " + avg);
        min = values[0][0];
        
       // Determine the min value and print
       for (int[] value : values) {
          for (int i = 0; i < value.length; i++) {
             if (value[i] < min) {
                min = value[i];
             }
          }
       }
        System.out.println("The minimum value in the array is: " + min);
        
        // Determine the max value and print
        max = values[0][0];
        
        for (int i = 1; i < values.length; i++) {
           if (values[i][i] > max) {
              max = values[i][i];
           }
           
        }
        System.out.println("The maximun value in the array is: " + max);
   
    }
    
}
