/*CS 172
* ManyStrings
* Lab 2
* Written by: Zachary Neeley
* 9/17/17
*
* INPUT:
* OUTPUT:
*/

import java.util.Scanner;

public class ManyStrings {

    
    public static void main(String[] args) {
        String input;
        String temp;
        Scanner scan = new Scanner(System.in);
        int index;
        
        // Get user input 
        System.out.println("Please enter a string: ");
        input = scan.nextLine();
        
        //Print length of string
        System.out.println("\nThe length of the string is: " + input.length());
        
        //Print 1st word
        index = input.indexOf(' ');
        if (index >= 0) {
            System.out.println("The first word is: " + input.substring(0, input.indexOf(' ')));
        } else {
            System.out.println("The first word is: " + input);
        }
        
        //Print string in uppercase
        System.out.println("The uppercase version is: " + input.toUpperCase() + "\n");
        
        //Prompt for a new string
        System.out.println("Please enter a new string: ");
        input = scan.nextLine();
        
        //Print string in lowercase
        System.out.println("The lowercase version is: " + input.toLowerCase());
        
        //Replace all 'n' with 'r' and print
        System.out.println("The string with all 'n' characters replaced with 'r': " + input.replaceAll("n", "r"));
        
        //Print the 1st index of 'a' or say there are no a's
        index = input.indexOf('a');
        if(index >= 0 ) {
            System.out.println("The first letter 'a' is at index: " + input.indexOf('a'));
        } else {
            System.out.println("There are no a's in the String.");
        }
        
        //Print the last letter
        System.out.println("The last letter of the string is: " + input.substring(input.length() - 1));
        
        //Check to see if ther 1st letter and last letter are the same
        temp = input.toLowerCase();
        if (temp.charAt(0) == temp.charAt(temp.length() - 1)) {
            System.out.println("The first and last are the same");
        } else {
            System.out.println("The first and last are different.");
        }
        
        //Check to see if there are 8 characters in the string and print if so or just print the string
        if (input.length() > 8 ) {
            System.out.println("The first 8 characters are: " + input.substring(0, 8));
        } else {
            System.out.println("The string is: " + input);
        }
        
    }
    
}
